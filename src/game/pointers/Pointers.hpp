#pragma once
#include "game/rdr/GraphicsOptions.hpp"
#include "game/rdr/RenderingInfo.hpp"

#include <d3d12.h>
#include <dxgi1_4.h>
#include <rage/atArray.hpp>
#include <script/scrNativeHandler.hpp>
#include <vulkan/vulkan.h>
#include <windows.h>

class CNetGamePlayer;
class CVehicle;
class CPed;
class CNetworkPlayerMgr;

namespace rage
{
	class scrThread;
	class netEventMgr;
	class netSyncTree;
	class netObject;
}

namespace YimMenu
{
	namespace Functions
	{
		using GetRendererInfo  = RenderingInfo* (*)();
		using GetNativeHandler = rage::scrNativeHandler (*)(rage::scrNativeHash hash);
		using FixVectors       = void (*)(rage::scrNativeCallContext* call_ctx);
		using SendEventAck = void (*)(rage::netEventMgr* eventMgr, void* event, CNetGamePlayer* sourcePlayer, CNetGamePlayer* targetPlayer, int eventIndex, int handledBitset);
		using HandleToPtr               = void* (*)(int handle);
		using PtrToHandle               = int (*)(void* pointer);
		using GetLocalPed               = CPed* (*)();
		using GetSyncTreeForType        = rage::netSyncTree* (*)(void* netObjMgr, uint16_t type);
		using GetNetworkPlayerFromPid   = CNetGamePlayer* (*)(uint8_t player);
		using WorldToScreen             = bool (*)(float* world_coords, float* out_x, float* out_y);
		using GetNetObjectById        = rage::netObject*(*)(uint16_t id);
		using RequestControlOfNetObject = bool (*)(rage::netObject** netId, bool unk);
	};

	struct PointerData
	{
		// RDR
		bool* IsSessionStarted;
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
		Functions::GetNetworkPlayerFromPid GetNetPlayerFromPid;

		// Voice
		PVOID EnumerateAudioDevices;
		PVOID DirectSoundCaptureCreate;

		// Native Handles
		Functions::HandleToPtr HandleToPtr;
		Functions::PtrToHandle PtrToHandle;
		Functions::WorldToScreen WorldToScreen;
		Functions::GetNetObjectById GetNetObjectById;
		Functions::RequestControlOfNetObject RequestControlOfNetObject;

		// Misc
		PVOID ThrowFatalError;

		// Vulkan
		PVOID QueuePresentKHR;      //Init in renderer
		PVOID CreateSwapchainKHR;   //Init in renderer
		PVOID AcquireNextImageKHR;  //Init in renderer
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

		CNetworkPlayerMgr* NetworkPlayerMgr;
		void* NetworkObjectMgr;

		PVOID WritePlayerHealthData;

		//Patches
		bool* ExplosionBypass;
	};

	struct Pointers : PointerData
	{
		bool Init();
		void Restore();
	};

	inline YimMenu::Pointers Pointers;
}