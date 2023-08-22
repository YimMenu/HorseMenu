#pragma once
#include <d3d11.h>
#include <windows.h>

namespace YimMenu
{
	namespace Functions
	{

	}

	struct PointerData
	{
		IDXGISwapChain** SwapChain;
		HWND Hwnd;
		WNDPROC WndProc;
		std::int64_t** ScriptGlobals;
		void* NativeRegistrationTable;
	};

	struct Pointers : PointerData
	{
		bool Init();
	};

	inline YimMenu::Pointers Pointers;
}