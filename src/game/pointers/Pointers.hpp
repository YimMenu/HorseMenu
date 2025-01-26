#pragma once
#include "game/rdr/GraphicsOptions.hpp"
#include "game/rdr/RenderingInfo.hpp"

#include <d3d12.h>
#include <dxgi1_4.h>
#include <rage/atArray.hpp>
#include <rage/vector.hpp>
#include <script/scrNativeHandler.hpp>
#include <vulkan/vulkan.h>
#include <windows.h>

class GraphicsOptions;
class CNetGamePlayer;
class CVehicle;
class CPed;
class CNetworkPlayerMgr;
class CNetworkObjectMgr;
class PoolEncryption;
class CFriend;

namespace rage
{
	class scrThread;
	class netEventMgr;
	class netSyncTree;
	class netObject;
	class rlGamerInfo;
	class netConnectionManager;
	class netPeerAddress;
	class rlGamerHandle;
	class datBitBuffer;
	class fwEntity;
	class scrProgram;
	enum class eThreadState : uint32_t;
	class scrThreadContext;
	class rlScSessionId;
	class rlScSessionMultiplayer;
	class rlGamerInfoBase;
	class rlTaskStatus;
	class rlQueryPresenceAttributesContext;
	class rlScTaskStatus;
}

class CAnimScene;
class CEventInventoryItemPickedUp;
class CEventGroup;
class CNetworkScSession;
class CNetworkScSessionMultiplayerImpl;
class CTrainConfigs;

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
		using SendPacket = bool (*)(rage::netConnectionManager* mgr, rage::netPeerAddress* adde, int connection_id, void* data, int size, int flags);
		using QueuePacket = bool (*)(rage::netConnectionManager* mgr, int msg_id, int connection_id, void* data, int size, int flags, void* unk);
		using PostPresenceMessage = bool (*)(int localGamerIndex, rage::rlGamerInfo* recipients, int numRecipients, const char* msg, unsigned int ttlSeconds);
		using SendNetInfoToLobby     = bool (*)(rage::rlGamerInfo* player, int64_t a2, int64_t a3, DWORD* a4);
		using ReadBitBufferArray     = bool (*)(rage::datBitBuffer* buffer, PVOID read, int bits, int unk);
		using WriteBitBufferArray    = bool (*)(rage::datBitBuffer* buffer, void* val, int bits, int unk);
		using ReadBitBufferString    = bool (*)(rage::datBitBuffer* buffer, char* read, int bits);
		using GetAnimSceneFromHandle = CAnimScene** (*)(CAnimScene** scene, int handle);
		using InventoryEventConstructor = CEventInventoryItemPickedUp* (*)(CEventInventoryItemPickedUp*, std::uint32_t reward_hash, std::uint32_t model_hash, bool a4, bool a5, void* a6);
		using TriggerWeaponDamageEvent = void (*)(rage::netObject* source, rage::netObject* target, rage::netObject* unk, rage::fvector3* position, void* a5, void* a6, bool override_dmg, std::uint32_t* weapon_hash, float damage, float f10, int tire_index, int suspension_index, std::uint64_t flags, void* action_result, bool hit_entity_weapon, bool hit_ammo_attachment, bool silenced, bool a18, bool a19, int a20, int a21, int a22, int a23, int a24, int a25);
		using TriggerGiveControlEvent = void (*)(CNetGamePlayer* player, rage::netObject* object, int type);
		using ScriptVM = rage::eThreadState (*)(void* stack, int64_t** globals, bool* globals_enabled, rage::scrProgram* program, rage::scrThreadContext* ctx);
		using RequestSessionSeamless = void (*)(CNetworkScSession* session, rage::rlScSessionId* req_id, int flags, rage::fvector3* position, int type);
		using GetConnectPlayerData = void (*)(CNetworkScSessionMultiplayerImpl* mp, void* data);
		using SendConnectResponse = void (*)(rage::rlScSessionMultiplayer* sess, int message_id, void* data, int flags);
		using GetPeerAddressByMessageId = rage::netPeerAddress* (*)(rage::netConnectionManager* cxn_mgr, int msg_id);
		using OpenIceTunnel = bool (*)(rage::rlGamerInfoBase* peer_addr, rage::netPeerAddress* direct_addr, rage::netPeerAddress* relay_addr, bool a4, std::uint64_t session_token, std::uint64_t session_id, rage::rlTaskStatus* status);
	};

	struct PointerData
	{
		// RDR
		GraphicsOptions* GraphicsOptions_;
		bool* IsSessionStarted;
		std::int64_t** ScriptGlobals;
		Functions::GetNativeHandler GetNativeHandler;
		Functions::FixVectors FixVectors;
		rage::atArray<rage::scrThread*>* ScriptThreads;
		rage::scrProgram** ScriptPrograms;
		PVOID RunScriptThreads;
		rage::scrThread** CurrentScriptThread;
		Functions::ScriptVM ScriptVM;
		Functions::GetLocalPed GetLocalPed;
		Functions::SendPacket SendPacket;
		Functions::QueuePacket QueuePacket;
		PVOID HandlePresenceEvent;
		Functions::PostPresenceMessage PostPresenceMessage;
		Functions::SendNetInfoToLobby SendNetInfoToLobby;
		Functions::ReadBitBufferArray ReadBitBufferArray;
		Functions::WriteBitBufferArray WriteBitBufferArray;
		Functions::ReadBitBufferString ReadBitBufferString;
		PVOID InitNativeTables;
		Functions::TriggerWeaponDamageEvent TriggerWeaponDamageEvent;
		CNetworkScSession** ScSession;
		PVOID HandleSessionEvent;
		Functions::RequestSessionSeamless RequestSessionSeamless;
		PVOID GetDiscriminator;
		std::uint16_t** ObjectIdMap;
		PVOID WriteNodeData;
		int* TotalProgramCount;
		PVOID SendVoicePacket;
		Functions::GetPeerAddressByMessageId GetPeerAddressByMessageId;
		PVOID WriteVoiceInfoData;
		CFriend** FriendRegistry;
		PVOID WriteSyncTree;
		PVOID ShouldUseNodeCache;
		PVOID IsNodeInScope;
		PVOID SetTreeErrored;
		PVOID SetTreeTargetObject;
		PVOID PhysicsHandleLassoAttachment;
		PVOID DecideConnectionMethod;
		char* DecideConnectionMethodJmp;
		char* DecideConnectionMethodDefVal;
		PVOID HandlePeerRelayPacket;
		PVOID UnpackPacket;
		PVOID UpdateEndpointAddress;
		CTrainConfigs* TrainConfigs;
		Functions::OpenIceTunnel OpenIceTunnel;
		PVOID SerializeIceSessionOfferRequest;
		PVOID CanCreateNetworkObject;
		int* MaxNetworkPeds;
		PVOID GetPoolSize;

		PoolEncryption* PedPool;
		PoolEncryption* ObjectPool;
		PoolEncryption* VehiclePool;
		PoolEncryption* PickupPool;
		PoolEncryption* ScriptHandlePool;
		uint32_t (*FwScriptGuidCreateGuid)(void*);
		CNetworkObjectMgr** NetworkObjectMgr;
		PVOID HandleCloneRemove;

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
		PVOID GetCloneCreateResponse;
		PVOID CanApplyData;
		PVOID PackCloneCreate;
		Functions::GetSyncTreeForType GetSyncTreeForType;
		PVOID ResetSyncNodes;
		PVOID HandleScriptedGameEvent;
		PVOID AddObjectToCreationQueue;
		PVOID ReceiveNetMessage;
		PVOID ReceiveServerMessage;
		PVOID SerializeServerRPC;
		PVOID ReceiveArrayUpdate;
		PVOID CreatePoolItem;


		// Player Stuff
		PVOID PlayerHasJoined;
		PVOID PlayerHasLeft;
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
		Functions::GetAnimSceneFromHandle GetAnimSceneFromHandle;

		// Misc
		PVOID ThrowFatalError;
		PVOID IsAnimSceneInScope;
		PVOID BroadcastNetArray;
		std::uint8_t* NetArrayPatch;
		Functions::InventoryEventConstructor InventoryEventConstructor;
		CEventGroup** EventGroupNetwork;
		Functions::TriggerGiveControlEvent TriggerGiveControlEvent;

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
		HWND* Hwnd;

		Functions::GetRendererInfo GetRendererInfo;
		GraphicsOptions GameGraphicsOptions;

		PVOID WndProc;
		BOOL IsVulkan;

		uint32_t* ScreenResX;
		uint32_t* ScreenResY;

		PVOID NetworkRequest;

		CNetworkPlayerMgr* NetworkPlayerMgr;

		PVOID WritePlayerHealthData;
		PVOID WriteVPMData;
		
		PVOID GetTextLabel;

		PVOID CheckConditionIsMale;
		PVOID CheckConditionIsFemale;
		int* ScriptUIDrawFlags;

		PVOID RegisterCompappNatives;

		//Patches
		bool* ExplosionBypass;
	};

	struct Pointers : PointerData
	{
		bool Init();
		bool LateInit();
		void Restore();
	};

	inline YimMenu::Pointers Pointers;
}
