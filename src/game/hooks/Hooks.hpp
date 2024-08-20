#pragma once
#include "game/rdr/Pools.hpp"

#include <D3D12.h>
#include <dxgi1_4.h>
#include <network/InFrame.hpp> // has to be imported
#include <vulkan/vulkan.h>


namespace rage
{
	class rlMetric;
	class netEventMgr;
	class datBitBuffer;
	class netObject;
	class netSyncTree;
	class rlGamerInfo;
	class netConnectionManager;
	class rlGamerInfo;
	class ServerMsg;
	class ServerMsgData;
	class ServerRPCSerializer;
	class scrProgram;
	class scrThreadContext;
	class rlScSessionMultiplayer;
	class rlScSessionEvent;
	class netPeerAddress;
}

class CNetGamePlayer;
enum class NetEventType;
class CFoundDevice;
class IDirectSoundCapture;
class CScriptedGameEvent;
enum class NetObjType;
class CPlayerHealthData;
class CVehicleProximityMigrationData;
class CPed;
class CNetworkScServerConnection;
class CProjectBaseSyncDataNode;

namespace YimMenu::Hooks
{
	class HttpRequest;

	namespace SwapChain
	{
		constexpr auto VMTPresentIdx       = 8;
		constexpr auto VMTResizeBuffersIdx = 13;
		extern HRESULT Present(IDXGISwapChain1* that, UINT syncInterval, UINT flags);
		extern HRESULT ResizeBuffers(IDXGISwapChain1* that, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags);
	}

	namespace Vulkan
	{
		extern VkResult VKAPI_CALL QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo);
		extern VkResult VKAPI_CALL CreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain);
		extern VkResult VKAPI_CALL AcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex);
		extern VkResult VKAPI_CALL AcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex);
	}

	namespace Window
	{
		extern LRESULT WndProc(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);
		extern BOOL SetCursorPos(int x, int y);
	}

	namespace Script
	{
		extern bool RunScriptThreads(void* threads, int unk);
		extern bool InitNativeTables(rage::scrProgram* program);
		extern int ScriptVM(void* stack, void** globals, bool* globals_enabled, rage::scrProgram* program, rage::scrThreadContext* ctx);
	}

	namespace Anticheat
	{
		extern bool SendMetric(void* manager, rage::rlMetric* metric);
		extern void QueueDependency(__int64 dependency);
		extern bool UnkFunction(__int64 cb);
	}

	namespace Protections
	{
		extern bool ShouldBlockSync(rage::netSyncTree* tree, NetObjType type, rage::netObject* object); // helper function, not a hook

		extern void HandleNetGameEvent(rage::netEventMgr* pEventMgr, CNetGamePlayer* pSourcePlayer, CNetGamePlayer* pTargetPlayer, NetEventType type, int index, int handledBits, std::int16_t unk, rage::datBitBuffer* buffer);
		extern int HandleCloneCreate(void* mgr, CNetGamePlayer* sender, uint16_t objectType, uint16_t objectId, int flags, void* encryptedMem, rage::datBitBuffer* buffer, int a8, int a9, bool isQueued);
		extern int HandleCloneSync(void* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, uint16_t objectType, uint16_t objectId, rage::datBitBuffer* buffer, int a7, int a8, void* a9);
		extern bool PackCloneCreate(void* mgr, rage::netObject* object, CNetGamePlayer* dst, rage::datBitBuffer* buffer);
		extern bool CanApplyData(rage::netSyncTree* tree, rage::netObject* object);
		extern void ResetSyncNodes();
		extern bool HandleScriptedGameEvent(CScriptedGameEvent* event, CNetGamePlayer* src, CNetGamePlayer* dst);
		extern int AddObjectToCreationQueue(void* mgr, NetObjType objectType, CNetGamePlayer* src, CNetGamePlayer* dst);
		extern bool ReceiveNetMessage(void* a1, void* ncm, rage::netConnection::InFrame* frame);
		extern bool HandlePresenceEvent(uint64_t a1, rage::rlGamerInfo* gamerInfo, unsigned int sender, const char** payload, const char* channel);
		extern bool PPostMessage(int localGamerIndex, rage::rlGamerInfo* recipients, int numRecipients, const char* msg, unsigned int ttlSeconds);
		extern bool SerializeServerRPC(rage::ServerRPCSerializer* serializer, void* a2, const char* message, void* def, void* structure, const char* RPCGuid, void* a7);
		extern bool ReceiveServerMessage(void* a1, rage::ServerMsg* message); // doesn't receive all messages
		extern bool ReceiveArrayUpdate(void* array, CNetGamePlayer* sender, rage::datBitBuffer* buffer, int size, int16_t cycle);
		extern void* CreatePoolItem(PoolUtils<Entity>* pool);
		extern int HandleCloneRemove(void* mgr, CNetGamePlayer* sender, CNetGamePlayer* target, uint16_t objectId, int ownershipToken, bool unk);
		extern __int64 PhysicCrash(__int64 a1, unsigned int a2, int* a3); // Don't really know what to call it. Lets go with PhysicCrash
	}

	namespace Voice
	{
		// {DCB7EF33-CD8A-4231-8051-66E3F683180B}
		inline constexpr GUID g_YimDevice = {0xdcb7ef33, 0xcd8a, 0x4231, {0x80, 0x51, 0x66, 0xe3, 0xf6, 0x83, 0x18, 0xb}};

		extern int EnumerateAudioDevices(CFoundDevice* devices, int count, int flags);
		extern HRESULT DirectSoundCaptureCreate(GUID* guid, IDirectSoundCapture** sound, void* unknown);
		extern void SendVoicePacket(void* net_cxn_mgr, rage::netPeerAddress* address, int voice_cxn, void* packet, int size, int flags);
		extern bool WriteVoiceInfoData(rage::datBitBuffer* buffer, __int64 data);
	}

	namespace Misc
	{
		extern void ThrowFatalError(int code, int fileHash, int fileLine);
		extern bool IsAnimSceneInScope(rage::netObject* scene, CNetGamePlayer* player, int* reason);
	}

	namespace Info
	{
		extern uint8_t* NetworkRequest(HttpRequest* Request, uint8_t* a2, uint32_t a3);

		extern void PlayerHasJoined(CNetGamePlayer* player);
		extern void PlayerHasLeft(CNetGamePlayer* player);

		extern void HandleSessionEvent(rage::rlScSessionMultiplayer* mp, CNetworkScServerConnection* cxn, rage::rlScSessionEvent* evt);
	}

	namespace Spoofing
	{
		extern void WriteNodeData(CProjectBaseSyncDataNode* node, rage::netObject* object, rage::datBitBuffer* buffer, void* logger, bool update);
		extern void WritePlayerHealthData(void* iface, CPlayerHealthData* data);
		extern bool SendNetInfoToLobby(rage::rlGamerInfo* local_player, int64_t a2, int64_t a3, DWORD* a4);
		extern void WriteVPMData(void* vehicle, CVehicleProximityMigrationData* data);
		extern int GetDiscriminator();
	}

	namespace Toxic
	{
		extern unsigned int BroadcastNetArray(void* array, CNetGamePlayer* target, rage::datBitBuffer* buffer, std::uint16_t counter, std::uint32_t* elem_start);
	}
}