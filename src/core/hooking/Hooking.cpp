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
		BaseHook::Add<Window::WndProc>(new DetourHook("WndProc", Pointers.WndProc, Window::WndProc));

		BaseHook::Add<Window::SetCursorPos>(new DetourHook("SetCursorPos", ModuleMgr.Get("user32.dll")->GetExport<void*>("SetCursorPos"), Window::SetCursorPos));

		//RDR2 would typically crash or do nothing when using VMT hooks, something to look into in the future.
		BaseHook::Add<SwapChain::Present>(new DetourHook("SwapChain::Present", GetVF(*Pointers.SwapChain, SwapChain::VMTPresentIdx), SwapChain::Present));
		BaseHook::Add<SwapChain::ResizeBuffers>(new DetourHook("SwapChain::ResizeBuffers", GetVF(*Pointers.SwapChain, SwapChain::VMTResizeBuffersIdx), SwapChain::ResizeBuffers));
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