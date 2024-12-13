#include "core/hooking/DetourHook.hpp"
#include "core/renderer/Renderer.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/frontend/GUI.hpp"

namespace YimMenu::Hooks
{
	LRESULT Window::WndProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
	{
		if (g_Running)
			Renderer::WndProc(hwnd, umsg, wparam, lparam);

		return BaseHook::Get<Window::WndProc, DetourHook<decltype(&WndProc)>>()->Original()(hwnd, umsg, wparam, lparam);
	}
	
	BOOL Window::SetCursorPos(int x, int y)
	{
		if (GUI::IsOpen() && !Renderer::IsResizing())
		{
			return true;
		}
		
		return BaseHook::Get<Window::SetCursorPos, DetourHook<decltype(&SetCursorPos)>>()->Original()(x, y);
	}

	BOOL Window::ShowWindow(HWND hWnd, int nCmdShow)
	{
		LOG(INFO) << hWnd << " " << nCmdShow;
		// prevent game from hiding console window
		if (hWnd == GetConsoleWindow() && nCmdShow == 0)
		{
			return false;
		}

		return BaseHook::Get<Window::ShowWindow, DetourHook<decltype(&ShowWindow)>>()->Original()(hWnd, nCmdShow);
	}
}