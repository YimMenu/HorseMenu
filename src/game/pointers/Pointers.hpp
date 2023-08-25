#pragma once
#include <windows.h>
#include <dxgi1_4.h>
#include <d3d12.h>
#include "game/rdr/RenderingInfo.hpp"

namespace YimMenu
{
	namespace Functions
	{
		using GetRendererInfo = RenderingInfo*(*)();
	}

	struct PointerData
	{
		Functions::GetRendererInfo GetRendererInfo;
		IDXGISwapChain1** SwapChain;
		ID3D12CommandQueue** CommandQueue;
		HWND Hwnd;
		std::int64_t** ScriptGlobals;
		void* NativeRegistrationTable;
	};

	struct Pointers : PointerData
	{
		bool Init();
	};

	inline YimMenu::Pointers Pointers;
}