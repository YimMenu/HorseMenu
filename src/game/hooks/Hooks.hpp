#pragma once
#include <dxgi1_4.h>
#include <D3D12.h>
#include <vulkan/vulkan.h>

namespace rage
{
	class rlMetric;
	class netEventMgr;
	class datBitBuffer;
}
class CNetGamePlayer;
enum class NetEventType;

namespace YimMenu::Hooks
{
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
		extern void HandleNetGameEvent(rage::netEventMgr* pEventMgr, CNetGamePlayer* pSourcePlayer, CNetGamePlayer* pTargetPlayer, NetEventType type, int index, int handledBits, std::int16_t unk, rage::datBitBuffer* buffer);
	}
}