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
	class CJoinRequestContext
	{
	public:
		char pad_0000[40];                 //0x0000
		void* m_join_request_data;         //0x0028
		uint32_t m_join_request_size;      //0x0030
		uint8_t m_join_response_data[512]; //0x0034
		uint32_t m_join_response_size;     //0x0234
		char pad_0238[12];                 //0x0238
	};                                     //Size: 0x0244
	class CMsgJoinResponse
	{
	public:
		uint32_t m_status_code;      //0x0000
		uint32_t m_visibility_flags; //0x0004
		bool m_can_wait_for_slot;    //0x0008
		char pad_0009[3];            //0x0009
		bool m_is_activity_session;  //0x000C
		char pad_000D[7];            //0x000D
		uint32_t m_network_time;     //0x0014
		char pad_0018[72];           //0x0018
	};                               //Size: 0x0060
	class CPlayerCameraDataNode
	{
	public:
		float m_camera_x;            // 0x100
		float m_camera_z;            // 0x104
		bool m_is_long_range_target; // 0x3F
	};
	class rlGamerInfo;
	class netConnectionManager;
	class netPeerAddress;
	class rlGamerHandle;
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
		using GetNetObjectById          = rage::netObject* (*)(uint16_t id);
		using RequestControlOfNetObject = bool (*)(rage::netObject** netId, bool unk);
		using HandleJoinRequest = bool (*)(int64_t network, int64_t session, rage::rlGamerInfo* player_info, rage::CJoinRequestContext* ctx);
		using WriteJoinResponseData = bool (*)(rage::CMsgJoinResponse* response, void* data, int size, uint32_t* size_used);
		using SendPacket = bool (*)(rage::netConnectionManager* mgr, rage::netPeerAddress* adde, int connection_id, void* data, int size, int flags);
		using QueuePacket = bool (*)(rage::netConnectionManager* mgr, int msg_id, void* data, int size, int flags, void* unk);
		using GetGamerOnlineState = bool (*)(int profile_index, rage::rlGamerHandle* handles, uint32_t count, int* online_state, int* status);
		using StartGetSessionByGamerHandle = bool (*)(int profile_index, rage::rlGamerHandle* handles, int count, void* result, int unk, bool* success, int* state);
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
		Functions::SendPacket SendPacket;
		Functions::QueuePacket QueuePacket;
		PVOID WritePlayerCameraDataNode;
		PVOID WritePlayerAppearanceDataNode;
		PVOID WritePlayerGameStateDataNode;

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
		Functions::HandleJoinRequest HandleJoinRequest;
		Functions::WriteJoinResponseData WriteJoinResponseData;
		PVOID ReceiveNetMessage;

		// Player Stuff
		PVOID PlayerHasJoined;
		PVOID PlayerHasLeft;
		Functions::GetNetworkPlayerFromPid GetNetPlayerFromPid;
		Functions::GetGamerOnlineState GetGamerOnlineState;
		Functions::StartGetSessionByGamerHandle StartGetSessionByGamerHandle;

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