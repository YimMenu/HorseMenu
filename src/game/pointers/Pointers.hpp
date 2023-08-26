#pragma once
#include <windows.h>
#include <dxgi1_4.h>
#include <d3d12.h>
#include "game/rdr/RenderingInfo.hpp"
#include <script/scrNativeHandler.hpp>
#include <rage/atArray.hpp>

namespace rage
{
	class scrThread;
}

namespace YimMenu
{
	namespace Functions
	{
		using GetRendererInfo = RenderingInfo*(*)();
		using GetNativeHandler = rage::scrNativeHandler (*)(rage::scrNativeHash hash);
		using FixVectors       = void (*)(rage::scrNativeCallContext* call_ctx);
	}

	struct PointerData
	{
		Functions::GetRendererInfo GetRendererInfo;
		IDXGISwapChain1** SwapChain;
		ID3D12CommandQueue** CommandQueue;
		HWND Hwnd;
		std::int64_t** ScriptGlobals;
		void* NativeRegistrationTable;
		PVOID WndProc;
		Functions::GetNativeHandler GetNativeHandler;
		Functions::FixVectors FixVectors;
		rage::atArray<rage::scrThread*>* ScriptThreads;
		PVOID RunScriptThreads;
		rage::scrThread** CurrentScriptThread;
	};

	struct Pointers : PointerData
	{
		bool Init();
	};

	inline YimMenu::Pointers Pointers;
}