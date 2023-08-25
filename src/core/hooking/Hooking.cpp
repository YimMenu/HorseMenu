#include "Hooking.hpp"

#include "BaseHook.hpp"
#include "DetourHook.hpp"
#include "VMTHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "../memory/ModuleMgr.hpp"

namespace YimMenu
{
	Hooking::Hooking()
	{
		Window::OriginalWndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtrW(Pointers.Hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(Window::WndProc)));
	
		BaseHook::Add<Window::SetCursorPos>(new DetourHook("SetCursorPos", ModuleMgr.Get("user32.dll")->GetExport<void*>("SetCursorPos"), Window::SetCursorPos));

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
		SetWindowLongPtrW(Pointers.Hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(Window::OriginalWndProc));
		BaseHook::DisableAll();
		m_MinHook.ApplyQueued();

		for (auto it : BaseHook::Hooks())
		{
			delete it;
		}
		BaseHook::Hooks().clear();
	}
}