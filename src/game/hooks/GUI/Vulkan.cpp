#include "core/hooking/DetourHook.hpp"
#include "core/hooking/VMTHook.hpp"
#include "core/renderer/Renderer.hpp"
#include "game/hooks/Hooks.hpp"

namespace YimMenu::Hooks
{
	VkResult VKAPI_CALL Vulkan::QueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
	{
		Renderer::VkOnPresent(queue, pPresentInfo);

		return BaseHook::Get<Vulkan::QueuePresentKHR, DetourHook<decltype(&QueuePresentKHR)>>()->Original()(queue, pPresentInfo);
	}

	VkResult VKAPI_CALL Vulkan::CreateSwapchainKHR(VkDevice device, const VkSwapchainCreateInfoKHR* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSwapchainKHR* pSwapchain)
	{
		if (pCreateInfo)
		{
			Renderer::SetResizing(true);
			Renderer::VkCleanupRenderTarget();
			Renderer::VkSetScreenSize(pCreateInfo->imageExtent);
		}
	
		return BaseHook::Get<Vulkan::CreateSwapchainKHR, DetourHook<decltype(&CreateSwapchainKHR)>>()->Original()(device, pCreateInfo, pAllocator, pSwapchain);
	}

	VkResult VKAPI_CALL Vulkan::AcquireNextImage2KHR(VkDevice device, const VkAcquireNextImageInfoKHR* pAcquireInfo, uint32_t* pImageIndex)
	{
		Renderer::VkSetDevice(device);

	    return BaseHook::Get<Vulkan::AcquireNextImage2KHR, DetourHook<decltype(&AcquireNextImage2KHR)>>()->Original()(device, pAcquireInfo, pImageIndex);
	}

	VkResult VKAPI_CALL Vulkan::AcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) 
	{
	    Renderer::VkSetDevice(device);

		return BaseHook::Get<Vulkan::AcquireNextImageKHR, DetourHook<decltype(&AcquireNextImageKHR)>>()->Original()(device, swapchain, timeout, semaphore, fence, pImageIndex);
	}
}