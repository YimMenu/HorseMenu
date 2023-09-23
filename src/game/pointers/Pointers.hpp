#pragma once
#include <windows.h>
#include <dxgi1_4.h>
#include <d3d12.h>
#include "game/rdr/RenderingInfo.hpp"
#include <script/scrNativeHandler.hpp>
#include <rage/atArray.hpp>
#include <vulkan/vulkan.h>

class CNetGamePlayer;

namespace rage
{
	class scrThread;
	class netEventMgr;
}

namespace YimMenu
{
	namespace Functions
	{
		using GetRendererInfo = RenderingInfo*(*)();
		using GetNativeHandler = rage::scrNativeHandler (*)(rage::scrNativeHash hash);
		using FixVectors       = void (*)(rage::scrNativeCallContext* call_ctx);
		using SendEventAck =     void(*)(rage::netEventMgr* eventMgr, CNetGamePlayer* sourcePlayer, CNetGamePlayer* targetPlayer, int eventIndex, int handledBitset);
	}

	struct PointerData
	{
	    // RDR
		std::int64_t** ScriptGlobals;
		void* NativeRegistrationTable;
		Functions::GetNativeHandler GetNativeHandler;
		Functions::FixVectors FixVectors;
		rage::atArray<rage::scrThread*>* ScriptThreads;
		PVOID RunScriptThreads;
		rage::scrThread** CurrentScriptThread;

		// Security
		PVOID SendMetric;
		bool* RageSecurityInitialized;
		PVOID* VmDetectionCallback;
		PVOID QueueDependency;
		PVOID UnkFunction;

		// Protections
		PVOID HandleNetGameEvent;
		Functions::SendEventAck SendEventAck;

		// Voice
		PVOID EnumerateAudioDevices;
		PVOID DirectSoundCaptureCreate;

		// Vulkan
		PVOID QueuePresentKHR; //Init in renderer
		PVOID CreateSwapchainKHR; //Init in renderer
		PVOID AcquireNextImageKHR; //Init in renderer
		PVOID AcquireNextImage2KHR; //Init in renderer

		VkDevice* VkDevicePtr;

		// DX12
		IDXGISwapChain1** SwapChain;
		ID3D12CommandQueue** CommandQueue;

		// Misc Renderer Related
		HWND Hwnd;
		Functions::GetRendererInfo GetRendererInfo;
		PVOID WndProc;
		BOOL IsVulkan;
	};

	struct Pointers : PointerData
	{
		bool Init();
	};

	inline YimMenu::Pointers Pointers;
}