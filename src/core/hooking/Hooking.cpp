#include "Hooking.hpp"

#include "BaseHook.hpp"
#include "DetourHook.hpp"
#include "VMTHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "core/memory/ModuleMgr.hpp"

namespace YimMenu
{
	Hooking::Hooking()
	{
		BaseHook::Add<Hooks::Window::WndProc>(new DetourHook("WndProc", Pointers.WndProc, Hooks::Window::WndProc));
		BaseHook::Add<Hooks::Window::SetCursorPos>(new DetourHook("SetCursorPos", ModuleMgr.Get("user32.dll")->GetExport<void*>("SetCursorPos"), Hooks::Window::SetCursorPos));

		if (Pointers.IsVulkan)
		{
			BaseHook::Add<Hooks::Vulkan::QueuePresentKHR>(new DetourHook("Vulkan::QueuePresentKHR", Pointers.QueuePresentKHR, Hooks::Vulkan::QueuePresentKHR));
			BaseHook::Add<Hooks::Vulkan::CreateSwapchainKHR>(new DetourHook("Vulkan::CreateSwapchainKHR", Pointers.CreateSwapchainKHR, Hooks::Vulkan::CreateSwapchainKHR));
			BaseHook::Add<Hooks::Vulkan::AcquireNextImage2KHR>(new DetourHook("Vulkan::AcquireNextImage2KHR", Pointers.AcquireNextImage2KHR, Hooks::Vulkan::AcquireNextImage2KHR));
			BaseHook::Add<Hooks::Vulkan::AcquireNextImageKHR>(new DetourHook("Vulkan::AcquireNextImageKHR", Pointers.AcquireNextImageKHR, Hooks::Vulkan::AcquireNextImageKHR));
		}
		else if (!Pointers.IsVulkan)
		{
			//RDR2 would typically crash or do nothing when using VMT hooks, something to look into in the future.
			BaseHook::Add<Hooks::SwapChain::Present>(new DetourHook("SwapChain::Present", GetVF(*Pointers.SwapChain, Hooks::SwapChain::VMTPresentIdx), Hooks::SwapChain::Present));
			BaseHook::Add<Hooks::SwapChain::ResizeBuffers>(new DetourHook("SwapChain::ResizeBuffers", GetVF(*Pointers.SwapChain, Hooks::SwapChain::VMTResizeBuffersIdx), Hooks::SwapChain::ResizeBuffers));
		}

		BaseHook::Add<Hooks::Script::RunScriptThreads>(new DetourHook("RunScriptThreads", Pointers.RunScriptThreads, Hooks::Script::RunScriptThreads));
		
		BaseHook::Add<Hooks::Anticheat::SendMetric>(new DetourHook("SendMetric", Pointers.SendMetric, Hooks::Anticheat::SendMetric));
		BaseHook::Add<Hooks::Anticheat::QueueDependency>(new DetourHook("QueueDependency", Pointers.QueueDependency, Hooks::Anticheat::QueueDependency));
		BaseHook::Add<Hooks::Anticheat::UnkFunction>(new DetourHook("UnkFunction", Pointers.UnkFunction, Hooks::Anticheat::UnkFunction));
		
		BaseHook::Add<Hooks::Protections::HandleNetGameEvent>(new DetourHook("HandleNetGameEvent", Pointers.HandleNetGameEvent, Hooks::Protections::HandleNetGameEvent));
		BaseHook::Add<Hooks::Protections::HandleCloneCreate>(new DetourHook("HandleCloneCreate", Pointers.HandleCloneCreate, Hooks::Protections::HandleCloneCreate));
		BaseHook::Add<Hooks::Protections::HandleCloneSync>(new DetourHook("HandleCloneSync", Pointers.HandleCloneSync, Hooks::Protections::HandleCloneSync));
		BaseHook::Add<Hooks::Protections::CanApplyData>(new DetourHook("CanApplyData", Pointers.CanApplyData, Hooks::Protections::CanApplyData));
		BaseHook::Add<Hooks::Protections::ResetSyncNodes>(new DetourHook("ResetSyncNodes", Pointers.ResetSyncNodes, Hooks::Protections::ResetSyncNodes));
		BaseHook::Add<Hooks::Protections::HandleScriptedGameEvent>(new DetourHook("HandleScriptedGameEvent", Pointers.HandleScriptedGameEvent, Hooks::Protections::HandleScriptedGameEvent));
		BaseHook::Add<Hooks::Protections::AddObjectToCreationQueue>(new DetourHook("AddObjectToCreationQueue", Pointers.AddObjectToCreationQueue, Hooks::Protections::AddObjectToCreationQueue));
		
		BaseHook::Add<Hooks::Voice::EnumerateAudioDevices>(new DetourHook("EnumerateAudioDevices", Pointers.EnumerateAudioDevices, Hooks::Voice::EnumerateAudioDevices));
		BaseHook::Add<Hooks::Voice::DirectSoundCaptureCreate>(
		    new DetourHook("DirectSoundCaptureCreate", Pointers.DirectSoundCaptureCreate, Hooks::Voice::DirectSoundCaptureCreate));
		
		BaseHook::Add<Hooks::Misc::ThrowFatalError>(new DetourHook("ThrowFatalError", Pointers.ThrowFatalError, Hooks::Misc::ThrowFatalError));
		
		BaseHook::Add<Hooks::Info::NetworkRequest>(new DetourHook("NetworkReqeust", Pointers.NetworkRequest, Hooks::Info::NetworkRequest));

		BaseHook::Add<Hooks::Info::PlayerHasJoined>(new DetourHook("PlayerHasJoined", Pointers.PlayerHasJoined, Hooks::Info::PlayerHasJoined));
		BaseHook::Add<Hooks::Info::PlayerHasLeft>(new DetourHook("PlayerHasLeft", Pointers.PlayerHasLeft, Hooks::Info::PlayerHasLeft));

		BaseHook::Add<Hooks::Spoofing::WritePlayerHealthData>(new DetourHook("WritePlayerHealthData", Pointers.WritePlayerHealthData, Hooks::Spoofing::WritePlayerHealthData));
	}

	Hooking::~Hooking()
	{
		DestroyImpl();
	}

	bool Hooking::Init()
	{
		return GetInstance().InitImpl();
	}

	void Hooking::Destroy()
	{
		GetInstance().DestroyImpl();
	}

	bool Hooking::InitImpl()
	{
		BaseHook::EnableAll();
		m_MinHook.ApplyQueued();

		return true;
	}

	void Hooking::DestroyImpl()
	{
		BaseHook::DisableAll();
		m_MinHook.ApplyQueued();

		for (auto it : BaseHook::Hooks())
		{
			delete it;
		}
		BaseHook::Hooks().clear();
	}
}