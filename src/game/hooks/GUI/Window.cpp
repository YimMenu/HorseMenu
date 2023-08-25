#include "core/hooking/DetourHook.hpp"
#include "core/renderer/Renderer.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/frontend/GUI.hpp"

namespace YimMenu
{
	LRESULT Window::WndProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
	{
		if (g_Running)
			Renderer::WndProc(hwnd, umsg, wparam, lparam);

		if (umsg == WM_KEYUP && wparam == VK_DELETE) // fallback to unload
			g_Running = false;

		return CallWindowProcW(Window::OriginalWndProc, hwnd, umsg, wparam, lparam);
	}
	BOOL Window::SetCursorPos(int x, int y)
	{
		if (GUI::IsOpen())
		{
			return true;
		}
		
		return BaseHook::Get<Window::SetCursorPos, DetourHook<decltype(&SetCursorPos)>>()->Original()(x, y);
	}
}