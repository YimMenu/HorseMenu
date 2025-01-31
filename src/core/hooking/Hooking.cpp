#include "Hooking.hpp"

#include "BaseHook.hpp"
#include "CallHook.hpp"
#include "DetourHook.hpp"
#include "VMTHook.hpp"
#include "VtableHook.hpp"
#include "core/memory/ModuleMgr.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"

#include "game/backend/Self.hpp"

#include <network/rlGamerInfoBase.hpp>

namespace YimMenu
{
	Hooking::Hooking()
	{
	}

	Hooking::~Hooking()
	{
		DestroyImpl();
	}

	bool Hooking::Init() 
	{ 
		return GetInstance().InitImpl(); 
	}

	bool Hooking::LateInit()
	{
		return GetInstance().LateInitImpl();
	}

	void Hooking::Destroy()
	{
		GetInstance().DestroyImpl();
	}

	bool Hooking::InitImpl() 
	{ 
		BaseHook::Add<Hooks::Window::ShowWindow>(new DetourHook("ShowWindow", ModuleMgr.Get("user32.dll")->GetExport<void*>("ShowWindow"), Hooks::Window::ShowWindow));

		BaseHook::Add<Hooks::Anticheat::SendMetric>(new DetourHook("SendMetric", Pointers.SendMetric, Hooks::Anticheat::SendMetric));
		BaseHook::Add<Hooks::Anticheat::QueueDependency>(new DetourHook("QueueDependency", Pointers.QueueDependency, Hooks::Anticheat::QueueDependency));
		BaseHook::Add<Hooks::Anticheat::UnkFunction>(new DetourHook("UnkFunction", Pointers.UnkFunction, Hooks::Anticheat::UnkFunction));

		BaseHook::Add<Hooks::Misc::GetPoolSize>(new DetourHook("GetPoolSize", Pointers.GetPoolSize, Hooks::Misc::GetPoolSize));

		BaseHook::Add<Hooks::Script::RunScriptThreads>(new DetourHook("RunScriptThreads", Pointers.RunScriptThreads, Hooks::Script::RunScriptThreads));
		BaseHook::Add<Hooks::Script::InitNativeTables>(new DetourHook("InitNativeTables", Pointers.InitNativeTables, Hooks::Script::InitNativeTables));
		BaseHook::Add<Hooks::Script::ScriptVM>(new DetourHook("ScriptVM", Pointers.ScriptVM, Hooks::Script::ScriptVM));
		BaseHook::Add<Hooks::Script::RegisterCompappNatives>(new DetourHook("RegisterCompappNatives", Pointers.RegisterCompappNatives, Hooks::Script::RegisterCompappNatives));

		BaseHook::Add<Hooks::Protections::HandleNetGameEvent>(new DetourHook("HandleNetGameEvent", Pointers.HandleNetGameEvent, Hooks::Protections::HandleNetGameEvent));
		BaseHook::Add<Hooks::Protections::HandleCloneCreate>(new DetourHook("HandleCloneCreate", Pointers.HandleCloneCreate, Hooks::Protections::HandleCloneCreate));
		BaseHook::Add<Hooks::Protections::HandleCloneSync>(new DetourHook("HandleCloneSync", Pointers.HandleCloneSync, Hooks::Protections::HandleCloneSync));
		BaseHook::Add<Hooks::Protections::GetCloneCreateResponse>(new DetourHook("GetCloneCreateResponse", Pointers.GetCloneCreateResponse, Hooks::Protections::GetCloneCreateResponse));
		BaseHook::Add<Hooks::Protections::CanApplyData>(new DetourHook("CanApplyData", Pointers.CanApplyData, Hooks::Protections::CanApplyData));
		BaseHook::Add<Hooks::Protections::ResetSyncNodes>(new DetourHook("ResetSyncNodes", Pointers.ResetSyncNodes, Hooks::Protections::ResetSyncNodes));
		BaseHook::Add<Hooks::Protections::HandleScriptedGameEvent>(new DetourHook("HandleScriptedGameEvent", Pointers.HandleScriptedGameEvent, Hooks::Protections::HandleScriptedGameEvent));
		BaseHook::Add<Hooks::Protections::AddObjectToCreationQueue>(new DetourHook("AddObjectToCreationQueue", Pointers.AddObjectToCreationQueue, Hooks::Protections::AddObjectToCreationQueue));
		BaseHook::Add<Hooks::Protections::ReceiveNetMessage>(new DetourHook("ReceiveNetMessage", Pointers.ReceiveNetMessage, Hooks::Protections::ReceiveNetMessage));
		BaseHook::Add<Hooks::Protections::HandlePresenceEvent>(new DetourHook("HandlePresenceEvent", Pointers.HandlePresenceEvent, Hooks::Protections::HandlePresenceEvent));
		BaseHook::Add<Hooks::Protections::PPostMessage>(new DetourHook("PostMessage", Pointers.PostPresenceMessage, Hooks::Protections::PPostMessage));
		BaseHook::Add<Hooks::Protections::SerializeServerRPC>(new DetourHook("SerializeServerRPC", Pointers.SerializeServerRPC, Hooks::Protections::SerializeServerRPC));
		BaseHook::Add<Hooks::Protections::ReceiveServerMessage>(new DetourHook("ReceiveServerMessage", Pointers.ReceiveServerMessage, Hooks::Protections::ReceiveServerMessage));
		BaseHook::Add<Hooks::Protections::DeserializeServerMessage>(new DetourHook("DeserializeServerMessage", (void*)((__int64)GetModuleHandleA(0) + 0x2609f78), Hooks::Protections::DeserializeServerMessage));
		BaseHook::Add<Hooks::Protections::ReceiveArrayUpdate>(new DetourHook("ReceiveArrayUpdate", Pointers.ReceiveArrayUpdate, Hooks::Protections::ReceiveArrayUpdate));
		BaseHook::Add<Hooks::Protections::CreatePoolItem>(new DetourHook("CreatePoolItem", Pointers.CreatePoolItem, Hooks::Protections::CreatePoolItem));
		BaseHook::Add<Hooks::Protections::HandleCloneRemove>(new DetourHook("HandleCloneRemove", Pointers.HandleCloneRemove, Hooks::Protections::HandleCloneRemove));
		BaseHook::Add<Hooks::Protections::PackCloneCreate>(new DetourHook("PackCloneCreate", Pointers.PackCloneCreate, Hooks::Protections::PackCloneCreate));
		BaseHook::Add<Hooks::Protections::SetTreeErrored>(new DetourHook("SetTreeErrored", Pointers.SetTreeErrored, Hooks::Protections::SetTreeErrored));
		BaseHook::Add<Hooks::Protections::PhysicsHandleLassoAttachment>(new DetourHook("PhysicsHandleLassoAttachment", Pointers.PhysicsHandleLassoAttachment, Hooks::Protections::PhysicsHandleLassoAttachment));
		BaseHook::Add<Hooks::Protections::DecideConnectionMethod>(new DetourHook("DecideConnectionMethod", Pointers.DecideConnectionMethod, Hooks::Protections::DecideConnectionMethod));
		BaseHook::Add<Hooks::Protections::HandlePeerRelayPacket>(new DetourHook("HandlePeerRelayPacket", Pointers.HandlePeerRelayPacket, Hooks::Protections::HandlePeerRelayPacket));
		BaseHook::Add<Hooks::Protections::UnpackPacket>(new DetourHook("UnpackPacket", Pointers.UnpackPacket, Hooks::Protections::UnpackPacket));
		BaseHook::Add<Hooks::Protections::UpdateEndpointAddress>(new DetourHook("UpdateEndpointAddress", Pointers.UpdateEndpointAddress, Hooks::Protections::UpdateEndpointAddress));
		BaseHook::Add<Hooks::Protections::CanCreateNetworkObject>(new DetourHook("CanCreateNetworkObject", Pointers.CanCreateNetworkObject, Hooks::Protections::CanCreateNetworkObject));

		BaseHook::Add<Hooks::Voice::EnumerateAudioDevices>(new DetourHook("EnumerateAudioDevices", Pointers.EnumerateAudioDevices, Hooks::Voice::EnumerateAudioDevices));
		BaseHook::Add<Hooks::Voice::DirectSoundCaptureCreate>(new DetourHook("DirectSoundCaptureCreate", Pointers.DirectSoundCaptureCreate, Hooks::Voice::DirectSoundCaptureCreate));
		BaseHook::Add<Hooks::Voice::SendVoicePacket>(new CallHook("SendVoicePacket", Pointers.SendVoicePacket, Hooks::Voice::SendVoicePacket));
		BaseHook::Add<Hooks::Voice::WriteVoiceInfoData>(new DetourHook("WriteVoiceInfoData", Pointers.WriteVoiceInfoData, Hooks::Voice::WriteVoiceInfoData));

		BaseHook::Add<Hooks::Misc::ThrowFatalError>(new DetourHook("ThrowFatalError", Pointers.ThrowFatalError, Hooks::Misc::ThrowFatalError));
		BaseHook::Add<Hooks::Misc::IsAnimSceneInScope>(new DetourHook("IsAnimSceneInScope", Pointers.IsAnimSceneInScope, Hooks::Misc::IsAnimSceneInScope));
		BaseHook::Add<Hooks::Misc::GetTextLabel>(new DetourHook("GetTextLabel", Pointers.GetTextLabel, Hooks::Misc::GetTextLabel));
		BaseHook::Add<Hooks::Misc::CheckConditionIsMale>(new DetourHook("CheckConditionIsMale", Pointers.CheckConditionIsMale, Hooks::Misc::CheckConditionIsMale));
		BaseHook::Add<Hooks::Misc::CheckConditionIsFemale>(new DetourHook("CheckConditionIsFemale", Pointers.CheckConditionIsFemale, Hooks::Misc::CheckConditionIsFemale));

		BaseHook::Add<Hooks::Info::NetworkRequest>(new DetourHook("NetworkReqeust", Pointers.NetworkRequest, Hooks::Info::NetworkRequest));

		BaseHook::Add<Hooks::Info::PlayerHasJoined>(new DetourHook("PlayerHasJoined", Pointers.PlayerHasJoined, Hooks::Info::PlayerHasJoined));
		BaseHook::Add<Hooks::Info::PlayerHasLeft>(new DetourHook("PlayerHasLeft", Pointers.PlayerHasLeft, Hooks::Info::PlayerHasLeft));

		BaseHook::Add<Hooks::Info::HandleSessionEvent>(new DetourHook("HandleSessionEvent", Pointers.HandleSessionEvent, Hooks::Info::HandleSessionEvent));

		BaseHook::Add<Hooks::Spoofing::SendNetInfoToLobby>(new DetourHook("SendNetInfoToLobby", Pointers.SendNetInfoToLobby, Hooks::Spoofing::SendNetInfoToLobby));
		BaseHook::Add<Hooks::Spoofing::WriteVPMData>(new DetourHook("WriteVehicleProximityMigrationData", Pointers.WriteVPMData, Hooks::Spoofing::WriteVPMData));
		BaseHook::Add<Hooks::Spoofing::GetDiscriminator>(new DetourHook("GetDiscriminator", Pointers.GetDiscriminator, Hooks::Spoofing::GetDiscriminator));
		BaseHook::Add<Hooks::Spoofing::WriteNodeData>(new DetourHook("WriteNodeData", Pointers.WriteNodeData, Hooks::Spoofing::WriteNodeData));

		BaseHook::Add<Hooks::Toxic::BroadcastNetArray>(new DetourHook("BroadcastNetArray", Pointers.BroadcastNetArray, Hooks::Toxic::BroadcastNetArray));
		BaseHook::Add<Hooks::Toxic::WriteSyncTree>(new DetourHook("WriteSyncTree", Pointers.WriteSyncTree, Hooks::Toxic::WriteSyncTree));
		BaseHook::Add<Hooks::Toxic::ShouldUseNodeCache>(new DetourHook("ShouldUseNodeCache", Pointers.ShouldUseNodeCache, Hooks::Toxic::ShouldUseNodeCache));
		BaseHook::Add<Hooks::Toxic::IsNodeInScope>(new DetourHook("IsNodeInScope", Pointers.IsNodeInScope, Hooks::Toxic::IsNodeInScope));
		BaseHook::Add<Hooks::Toxic::SetTreeTargetObject>(new DetourHook("SetTreeTargetObject", Pointers.SetTreeTargetObject, Hooks::Toxic::SetTreeTargetObject));

	
		BaseHook::Add<Hooks::Toxic::SerializeIceSessionOfferRequest>(new DetourHook("SerializeIceSessionOfferRequest", Pointers.SerializeIceSessionOfferRequest, Hooks::Toxic::SerializeIceSessionOfferRequest));

		if (!BaseHook::EnableAll())
		{
			LOG(FATAL) << "Failed to apply initial hooks";
			return false;
		}

		auto code = m_MinHook.ApplyQueued();

		if (code == MH_OK)
		{
			LOG(INFO) << "Initial hooks applied";
			return true;
		}
		else
		{
			LOG(FATAL) << "Failed to apply initial hooks: " << MH_StatusToString(code);
			return false;
		}
	}

	bool Hooking::LateInitImpl()
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
			BaseHook::Add<Hooks::SwapChain::Present>(new DetourHook("SwapChain::Present", GetVF(*Pointers.SwapChain, Hooks::SwapChain::VMTPresentIdx), Hooks::SwapChain::Present));
			BaseHook::Add<Hooks::SwapChain::ResizeBuffers>(new DetourHook("SwapChain::ResizeBuffers", GetVF(*Pointers.SwapChain, Hooks::SwapChain::VMTResizeBuffersIdx), Hooks::SwapChain::ResizeBuffers));
		}

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