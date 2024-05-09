#pragma once
#include <D3D12.h>
#include <dxgi1_4.h>
#include <vulkan/vulkan.h>


namespace rage
{
	class rlMetric;
	class netEventMgr;
	class datBitBuffer;
	class netObject;
	class netSyncTree;
	class CJoinRequestContext;
	class CMsgJoinResponse;
	class rlGamerInfo;
	class CPlayerCameraDataNode;
}
class CNetGamePlayer;
enum class NetEventType;
class CFoundDevice;
class IDirectSoundCapture;
class CScriptedGameEvent;
enum class eNetObjType;
class CPlayerHealthData;

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
	}

	namespace Anticheat
	{
		extern bool SendMetric(void* manager, rage::rlMetric* metric);
		extern void QueueDependency(__int64 dependency);
		extern bool UnkFunction(__int64 cb);
	}

	namespace Protections
	{
		extern bool ShouldBlockSync(rage::netSyncTree* tree, eNetObjType type, rage::netObject* object); // helper function, not a hook

		extern void HandleNetGameEvent(rage::netEventMgr* pEventMgr, CNetGamePlayer* pSourcePlayer, CNetGamePlayer* pTargetPlayer, NetEventType type, int index, int handledBits, std::int16_t unk, rage::datBitBuffer* buffer);
		extern int HandleCloneCreate(void* mgr, CNetGamePlayer* sender, uint16_t objectType, uint16_t objectId, int flags, void* encryptedMem, rage::datBitBuffer* buffer, int a8, int a9, bool isQueued);
		extern int HandleCloneSync(void* mgr, CNetGamePlayer* src, CNetGamePlayer* dst, uint16_t objectType, uint16_t objectId, rage::datBitBuffer* buffer, int a7, int a8, void* a9);
		extern bool CanApplyData(rage::netSyncTree* tree, rage::netObject* object);
		extern void ResetSyncNodes();
		extern bool HandleScriptedGameEvent(CScriptedGameEvent* event, CNetGamePlayer* src, CNetGamePlayer* dst);
		extern int AddObjectToCreationQueue(void* mgr, eNetObjType objectType, CNetGamePlayer* src, CNetGamePlayer* dst);
		extern bool HandleJoinRequest(int64_t network, int64_t session, rage::rlGamerInfo* player_info, rage::CJoinRequestContext* ctx);
	}

	namespace Voice
	{
		// {DCB7EF33-CD8A-4231-8051-66E3F683180B}
		inline constexpr GUID g_YimDevice = {0xdcb7ef33, 0xcd8a, 0x4231, {0x80, 0x51, 0x66, 0xe3, 0xf6, 0x83, 0x18, 0xb}};

		extern int EnumerateAudioDevices(CFoundDevice* devices, int count, int flags);
		extern HRESULT DirectSoundCaptureCreate(GUID* guid, IDirectSoundCapture** sound, void* unknown);
	}

	namespace Misc
	{
		extern void ThrowFatalError(int code, int fileHash, int fileLine);
	}

	namespace Info
	{
		extern uint8_t* NetworkRequest(HttpRequest* Request, uint8_t* a2, uint32_t a3);

		extern void PlayerHasJoined(CNetGamePlayer* player);
		extern void PlayerHasLeft(CNetGamePlayer* player);
	}

	namespace Spoofing
	{
		extern void WritePlayerHealthData(void* iface, CPlayerHealthData* data);
		extern void WritePlayerCameraDataNode(rage::netObject* player, rage::CPlayerCameraDataNode* node);
	}
}