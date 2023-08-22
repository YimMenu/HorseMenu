#pragma once
#include <windows.h>
#include <dxgi1_2.h>

namespace YimMenu
{
	namespace Functions
	{

	}

	struct PointerData
	{
		IDXGISwapChain1** SwapChain;
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