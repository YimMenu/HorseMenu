#pragma once
#include <windows.h>
#include <dxgi1_4.h>
#include <d3d12.h>
#include "game/rdr/RenderingInfo.hpp"
#include "game/rdr/GraphicsOptions.hpp"
#include <script/scrNativeHandler.hpp>
#include <rage/atArray.hpp>
#include <vulkan/vulkan.h>

class CNetGamePlayer;
class CVehicle;
class CPed;

namespace rage
{
	class scrThread;
	class netEventMgr;
	class netSyncTree;
}

namespace YimMenu
{
	namespace Functions
	{
		using GetRendererInfo         = RenderingInfo*(*)();
		using GetNativeHandler        = rage::scrNativeHandler (*)(rage::scrNativeHash hash);
		using FixVectors              = void (*)(rage::scrNativeCallContext* call_ctx);
		using SendEventAck            = void(*)(rage::netEventMgr* eventMgr, void* event, CNetGamePlayer* sourcePlayer, CNetGamePlayer* targetPlayer, int eventIndex, int handledBitset);
		using HandleToPtr             = void*(*)(int handle);
		using PtrToHandle             = int(*)(void* pointer);
		using GetLocalPed             = CPed*(*)();
		using GetSyncTreeForType      = rage::netSyncTree*(*)(void* netObjMgr, uint16_t type);
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
		Functions::GetLocalPed GetLocalPed;

		// Security
		PVOID SendMetric;
		bool* RageSecurityInitialized;
		PVOID* VmDetectionCallback;
		PVOID QueueDependency;
		PVOID UnkFunction;

		// Protections
		PVOID HandleNetGameEvent;
		Functions::SendEventAck SendEventAck;
		PVOID HandleCloneCreate;
		PVOID HandleCloneSync;
		PVOID CanApplyData;
		Functions::GetSyncTreeForType GetSyncTreeForType;
		PVOID ResetSyncNodes;
		PVOID HandleScriptedGameEvent;
		PVOID AddObjectToCreationQueue;

		// Player Stuff
		PVOID AssignPhysicalIndex;

		// Voice
		PVOID EnumerateAudioDevices;
		PVOID DirectSoundCaptureCreate;

		// Native Handles
		Functions::HandleToPtr HandleToPtr;
		Functions::PtrToHandle PtrToHandle;

		// Misc
		PVOID ThrowFatalError;

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
		GraphicsOptions GameGraphicsOptions;

		PVOID WndProc;
		BOOL IsVulkan;

		uint32_t ScreenResX;
		uint32_t ScreenResY;

		PVOID NetworkRequest;
	};

	struct Pointers : PointerData
	{
		bool Init();
	};

	inline YimMenu::Pointers Pointers;
}