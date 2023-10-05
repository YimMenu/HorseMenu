#pragma once
#include <windows.h>
#include <dxgi1_4.h>
#include <d3d12.h>
#include "game/rdr/RenderingInfo.hpp"
#include "game/rdr/GraphicsOptions.hpp"
#include <script/scrNativeHandler.hpp>
#include <rage/atArray.hpp>
#include <vulkan/vulkan.h>


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
	    //RDR
		std::int64_t** ScriptGlobals;
		void* NativeRegistrationTable;
		Functions::GetNativeHandler GetNativeHandler;
		Functions::FixVectors FixVectors;
		rage::atArray<rage::scrThread*>* ScriptThreads;
		PVOID RunScriptThreads;
		rage::scrThread** CurrentScriptThread;

		//Vulkan
		PVOID QueuePresentKHR; //Init in renderer
		PVOID CreateSwapchainKHR; //Init in renderer
		PVOID AcquireNextImageKHR; //Init in renderer
		PVOID AcquireNextImage2KHR; //Init in renderer

		VkDevice* VkDevicePtr;

		//DX12
		IDXGISwapChain1** SwapChain;
		ID3D12CommandQueue** CommandQueue;

		//Misc Renderer Related
		HWND Hwnd;

		Functions::GetRendererInfo GetRendererInfo;
		GraphicsOptions GameGraphicsOptions;

		PVOID WndProc;
		BOOL IsVulkan;

		uint32_t ScreenResX;
		uint32_t ScreenResY;
	};

	struct Pointers : PointerData
	{
		bool Init();
	};

	inline YimMenu::Pointers Pointers;
}