#define IMGUI_DEFINE_MATH_OPERATORS
#include "Renderer.hpp"

#include "core/memory/ModuleMgr.hpp"
#include "core/memory/PatternScanner.hpp"
#include "game/frontend/GUI.hpp"
#include "game/frontend/Menu.hpp"
#include "game/pointers/Pointers.hpp"

#include <backends/imgui_impl_dx12.h>
#include <backends/imgui_impl_win32.h>
#include <imgui.h>


namespace YimMenu
{
	Renderer::Renderer()
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::DestroyImpl()
	{
		ImGui_ImplWin32_Shutdown();

		if (Pointers.IsVulkan)
		{
			VkCleanupRenderTarget();
			vkDestroyDescriptorPool(m_VkDevice, m_VkDescriptorPool, m_VkAllocator);
			vkDeviceWaitIdle(m_VkDevice);
			vkDestroyInstance(m_VkInstance, m_VkAllocator);
			ImGui_ImplVulkan_Shutdown();
		}
		else if (!Pointers.IsVulkan)
		{
			WaitForLastFrame();
			ImGui_ImplDX12_Shutdown();
		}

		ImGui::DestroyContext();
	}

	bool Renderer::InitDX12()
	{
		if (!Pointers.SwapChain)
		{
			LOG(WARNING) << "SwapChain pointer is invalid!";

			return false;
		}

		if (!Pointers.CommandQueue)
		{
			LOG(WARNING) << "CommandQueue pointer is invalid!";

			return false;
		}

		//This is required. In order to stop ComPtr from releasing the original pointer, we create a new ComPtr with the ptr as the intializer. (The '=' operator uses swap which releases the object passed into it)
		if (m_GameSwapChain = ComPtr<IDXGISwapChain1>(*Pointers.SwapChain); !m_GameSwapChain.Get())
		{
			LOG(WARNING) << "Dereferenced SwapChain pointer is invalid!";

			return false;
		}

		if (m_CommandQueue = ComPtr<ID3D12CommandQueue>(*Pointers.CommandQueue); !m_CommandQueue.Get())
		{
			LOG(WARNING) << "Dereferenced CommandQueue pointer is invalid!";

			return false;
		}

		m_GameSwapChain.As(&m_SwapChain); //We need GetCurrentBackBufferIndex from IDXGISwapChain3

		if (const auto result = m_SwapChain->GetDevice(__uuidof(ID3D12Device), reinterpret_cast<void**>(m_Device.GetAddressOf())); result < 0)
		{
			LOG(WARNING) << "Failed to get D3D Device with result: [" << result << "]";

			return false;
		}

		if (const auto result = m_SwapChain->GetDesc(&m_SwapChainDesc); result < 0)
		{
			LOG(WARNING) << "Failed to get SwapChain Description with result: [" << result << "]";

			return false;
		}

		if (const auto result = m_Device->CreateFence(0, D3D12_FENCE_FLAG_NONE, __uuidof(ID3D12Fence), (void**)m_Fence.GetAddressOf()); result < 0)
		{
			LOG(WARNING) << "Failed to create Fence with result: [" << result << "]";

			return false;
		}

		if (const auto result = m_FenceEvent = CreateEventA(nullptr, FALSE, FALSE, nullptr); !result)
		{
			LOG(WARNING) << "Failed to create Fence Event!";

			return false;
		}

		m_FrameContext.resize(m_SwapChainDesc.BufferCount);

		D3D12_DESCRIPTOR_HEAP_DESC DescriptorDesc{D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, m_SwapChainDesc.BufferCount, D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE};
		if (const auto result =
		        m_Device->CreateDescriptorHeap(&DescriptorDesc, __uuidof(ID3D12DescriptorHeap), (void**)m_DescriptorHeap.GetAddressOf());
		    result < 0)
		{
			LOG(WARNING) << "Failed to create Descriptor Heap with result: [" << result << "]";

			return false;
		}

		if (const auto result = m_Device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT,
		        __uuidof(ID3D12CommandAllocator),
		        (void**)m_CommandAllocator.GetAddressOf());
		    result < 0)
		{
			LOG(WARNING) << "Failed to create Command Allocator with result: [" << result << "]";

			return false;
		}

		for (size_t i{}; i < m_SwapChainDesc.BufferCount; ++i)
		{
			m_FrameContext[i].CommandAllocator = m_CommandAllocator.Get();
		}

		if (const auto result = m_Device->CreateCommandList(0,
		        D3D12_COMMAND_LIST_TYPE_DIRECT,
		        m_CommandAllocator.Get(),
		        NULL,
		        __uuidof(ID3D12GraphicsCommandList),
		        (void**)m_CommandList.GetAddressOf());
		    result < 0)
		{
			LOG(WARNING) << "Failed to create Command List with result: [" << result << "]";

			return false;
		}

		if (const auto result = m_CommandList->Close(); result < 0)
		{
			LOG(WARNING) << "Failed to finalize the creation of Command List with result: [" << result << "]";

			return false;
		}

		D3D12_DESCRIPTOR_HEAP_DESC DescriptorBackbufferDesc{D3D12_DESCRIPTOR_HEAP_TYPE_RTV, m_SwapChainDesc.BufferCount, D3D12_DESCRIPTOR_HEAP_FLAG_NONE, 1};
		if (const auto result = m_Device->CreateDescriptorHeap(&DescriptorBackbufferDesc,
		        __uuidof(ID3D12DescriptorHeap),
		        (void**)m_BackbufferDescriptorHeap.GetAddressOf());
		    result < 0)
		{
			LOG(WARNING) << "Failed to create Backbuffer Descriptor Heap with result: [" << result << "]";

			return false;
		}

		const auto RTVDescriptorSize{m_Device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV)};
		D3D12_CPU_DESCRIPTOR_HANDLE RTVHandle{m_BackbufferDescriptorHeap->GetCPUDescriptorHandleForHeapStart()};
		for (size_t i{}; i != m_SwapChainDesc.BufferCount; ++i)
		{
			ComPtr<ID3D12Resource> BackBuffer{};
			m_FrameContext[i].Descriptor = RTVHandle;
			m_SwapChain->GetBuffer(i, __uuidof(ID3D12Resource), (void**)BackBuffer.GetAddressOf());
			m_Device->CreateRenderTargetView(BackBuffer.Get(), nullptr, RTVHandle);
			m_FrameContext[i].Resource = BackBuffer.Get();
			RTVHandle.ptr += RTVDescriptorSize;
		}

		// never returns false, useless to check return
		ImGui::CreateContext(&GetInstance().m_FontAtlas);
		ImGui_ImplWin32_Init(*Pointers.Hwnd);
		ImGui_ImplDX12_Init(m_Device.Get(),
		    m_SwapChainDesc.BufferCount,
		    DXGI_FORMAT_R8G8B8A8_UNORM,
		    m_DescriptorHeap.Get(),
		    m_DescriptorHeap->GetCPUDescriptorHandleForHeapStart(),
		    m_DescriptorHeap->GetGPUDescriptorHandleForHeapStart());

		ImGui::StyleColorsDark();

		LOG(INFO) << "DirectX 12 renderer has finished initializing.";
		return true;
	}

	bool Renderer::InitVulkan()
	{
		VkInstanceCreateInfo CreateInfo = {};

		const std::vector<const char*> InstanceExtensions = {"VK_KHR_surface"};

		const std::vector<const char*> ValidationLayers = {"VK_LAYER_KHRONOS_validation"};

		CreateInfo.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		CreateInfo.enabledExtensionCount   = (uint32_t)InstanceExtensions.size();
		CreateInfo.ppEnabledExtensionNames = InstanceExtensions.data();

		//	CreateInfo.enabledLayerCount       = (uint32_t)ValidationLayers.size();
		//	CreateInfo.ppEnabledLayerNames     = ValidationLayers.data();

		// Create Vulkan Instance without debug feature
		if (const VkResult result = vkCreateInstance(&CreateInfo, m_VkAllocator, &m_VkInstance); result != VK_SUCCESS)
		{
			LOG(WARNING) << "vkCreateInstance failed with result: [" << result << "]";
			return false;
		}

		;
		uint32_t GpuCount;
		if (const VkResult result = vkEnumeratePhysicalDevices(m_VkInstance, &GpuCount, NULL); result != VK_SUCCESS)
		{
			LOG(WARNING) << "vkEnumeratePhysicalDevices failed with result: [" << result << "]";
			return false;
		}

		IM_ASSERT(GpuCount > 0);

		ImVector<VkPhysicalDevice> GpuArr;
		GpuArr.resize(GpuCount);

		if (const VkResult result = vkEnumeratePhysicalDevices(m_VkInstance, &GpuCount, GpuArr.Data); result != VK_SUCCESS)
		{
			LOG(WARNING) << "vkEnumeratePhysicalDevices 2 failed with result: [" << result << "]";
			return false;
		}

		VkPhysicalDevice MainGPU = nullptr;
		for (const auto& Gpu : GpuArr)
		{
			VkPhysicalDeviceProperties Properties;
			vkGetPhysicalDeviceProperties(Gpu, &Properties);
			if (Properties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
			{
				LOG(INFO) << "Vulkan - Using GPU: " << Properties.deviceName;

				MainGPU = Gpu;
				break;
			}
		}

		if (!MainGPU)
		{
			LOG(INFO) << "Failed to get main GPU!";
			return false;
		}

		m_VkPhysicalDevice = MainGPU;

		uint32_t Count;
		vkGetPhysicalDeviceQueueFamilyProperties(m_VkPhysicalDevice, &Count, NULL);
		m_VKQueueFamilies.resize(Count);
		vkGetPhysicalDeviceQueueFamilyProperties(m_VkPhysicalDevice, &Count, m_VKQueueFamilies.data());
		for (uint32_t i = 0; i < Count; ++i)
		{
			if (m_VKQueueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
			{
				m_VkQueueFamily = i;
				break;
			}
		}

		IM_ASSERT(m_VkQueueFamily != (uint32_t)-1);

		constexpr const char* DeviceExtension = "VK_KHR_swapchain";
		constexpr const float QueuePriority   = 1.0f;

		VkDeviceQueueCreateInfo DeviceQueueInfo = {};
		DeviceQueueInfo.sType                   = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		DeviceQueueInfo.queueFamilyIndex        = m_VkQueueFamily;
		DeviceQueueInfo.queueCount              = 1;
		DeviceQueueInfo.pQueuePriorities        = &QueuePriority;

		VkDeviceCreateInfo DeviceCreateInfo      = {};
		DeviceCreateInfo.sType                   = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		DeviceCreateInfo.queueCreateInfoCount    = 1;
		DeviceCreateInfo.pQueueCreateInfos       = &DeviceQueueInfo;
		DeviceCreateInfo.enabledExtensionCount   = 1;
		DeviceCreateInfo.ppEnabledExtensionNames = &DeviceExtension;

		if (const VkResult result = vkCreateDevice(m_VkPhysicalDevice, &DeviceCreateInfo, m_VkAllocator, &m_VkFakeDevice); result != VK_SUCCESS)
		{
			LOG(WARNING) << "Fake vkCreateDevice failed with result: [" << result << "]";
			return false;
		}

		Pointers.QueuePresentKHR = reinterpret_cast<void*>(vkGetDeviceProcAddr(m_VkFakeDevice, "vkQueuePresentKHR"));
		Pointers.CreateSwapchainKHR = reinterpret_cast<void*>(vkGetDeviceProcAddr(m_VkFakeDevice, "vkCreateSwapchainKHR"));
		Pointers.AcquireNextImageKHR = reinterpret_cast<void*>(vkGetDeviceProcAddr(m_VkFakeDevice, "vkAcquireNextImageKHR"));
		Pointers.AcquireNextImage2KHR = reinterpret_cast<void*>(vkGetDeviceProcAddr(m_VkFakeDevice, "vkAcquireNextImage2KHR"));

		vkDestroyDevice(m_VkFakeDevice, m_VkAllocator);
		m_VkFakeDevice = NULL;

		ImGui::CreateContext(&GetInstance().m_FontAtlas);
		ImGui_ImplWin32_Init(*Pointers.Hwnd);


		LOG(INFO) << "Vulkan renderer has finished initializing.";

		return true;
	}

	void Renderer::ResizeImpl(float scale)
	{
		DX12PreResize();

		if (scale != 1.0f)
			ImGui::GetStyle().ScaleAllSizes(scale);
		ImGui::GetStyle().MouseCursorScale = 1.0f;
		ImGui::GetIO().FontGlobalScale     = scale;
		DX12PostResize();
	}

	void Renderer::VkCreateRenderTarget(VkDevice device, VkSwapchainKHR swapchain)
	{
		uint32_t uImageCount;
		if (const VkResult result = vkGetSwapchainImagesKHR(device, swapchain, &uImageCount, NULL))
		{
			LOG(WARNING) << "vkGetSwapchainImagesKHR failed with result: [" << result << "]";
			return;
		}

		VkImage BackBuffers[8] = {};
		if (const VkResult result = vkGetSwapchainImagesKHR(device, swapchain, &uImageCount, BackBuffers))
		{
			LOG(WARNING) << "vkGetSwapchainImagesKHR 2 failed with result: [" << result << "]";
			return;
		}

		for (uint32_t i = 0; i < uImageCount; ++i)
		{
			m_VkFrames[i].Backbuffer = BackBuffers[i];

			ImGui_ImplVulkanH_Frame* fd            = &m_VkFrames[i];
			ImGui_ImplVulkanH_FrameSemaphores* fsd = &m_VkFrameSemaphores[i];
			{
				VkCommandPoolCreateInfo info = {};
				info.sType                   = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
				info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
				info.queueFamilyIndex        = m_VkQueueFamily;

				if (const VkResult result = vkCreateCommandPool(device, &info, m_VkAllocator, &fd->CommandPool))
				{
					LOG(WARNING) << "vkCreateCommandPool failed with result: [" << result << "]";
					return;
				}
			}
			{
				VkCommandBufferAllocateInfo info = {};
				info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
				info.commandPool                 = fd->CommandPool;
				info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
				info.commandBufferCount          = 1;

				if (const VkResult result = vkAllocateCommandBuffers(device, &info, &fd->CommandBuffer))
				{
					LOG(WARNING) << "vkAllocateCommandBuffers failed with result: [" << result << "]";
					return;
				}
			}
			{
				VkFenceCreateInfo info = {};
				info.sType             = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
				info.flags             = VK_FENCE_CREATE_SIGNALED_BIT;
				if (const VkResult result = vkCreateFence(device, &info, m_VkAllocator, &fd->Fence))
				{
					LOG(WARNING) << "vkCreateFence failed with result: [" << result << "]";
					return;
				}
			}
			{
				VkSemaphoreCreateInfo info = {};
				info.sType                 = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
				if (const VkResult result = vkCreateSemaphore(device, &info, m_VkAllocator, &fsd->ImageAcquiredSemaphore))
				{
					LOG(WARNING) << "vkCreateSemaphore failed with result: [" << result << "]";
					return;
				}

				if (const VkResult result = vkCreateSemaphore(device, &info, m_VkAllocator, &fsd->RenderCompleteSemaphore))
				{
					LOG(WARNING) << "vkCreateSemaphore 2 failed with result: [" << result << "]";
					return;
				}
			}
		}

		{
			VkAttachmentDescription attachment = {};
			attachment.format                  = VK_FORMAT_B8G8R8A8_UNORM;
			attachment.samples                 = VK_SAMPLE_COUNT_1_BIT;
			attachment.loadOp                  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
			attachment.storeOp                 = VK_ATTACHMENT_STORE_OP_STORE;
			attachment.stencilLoadOp           = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
			attachment.stencilStoreOp          = VK_ATTACHMENT_STORE_OP_DONT_CARE;
			attachment.initialLayout           = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
			attachment.finalLayout             = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

			VkAttachmentReference color_attachment = {};
			color_attachment.attachment            = 0;
			color_attachment.layout                = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

			VkSubpassDescription subpass = {};
			subpass.pipelineBindPoint    = VK_PIPELINE_BIND_POINT_GRAPHICS;
			subpass.colorAttachmentCount = 1;
			subpass.pColorAttachments    = &color_attachment;

			VkRenderPassCreateInfo info = {};
			info.sType                  = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
			info.attachmentCount        = 1;
			info.pAttachments           = &attachment;
			info.subpassCount           = 1;
			info.pSubpasses             = &subpass;

			if (const VkResult result = vkCreateRenderPass(device, &info, m_VkAllocator, &m_VkRenderPass))
			{
				LOG(WARNING) << "vkCreateRenderPass failed with result: [" << result << "]";
				return;
			}
		}
		{
			VkImageViewCreateInfo info = {};
			info.sType                 = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
			info.viewType              = VK_IMAGE_VIEW_TYPE_2D;
			info.format                = VK_FORMAT_B8G8R8A8_UNORM;

			info.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
			info.subresourceRange.baseMipLevel   = 0;
			info.subresourceRange.levelCount     = 1;
			info.subresourceRange.baseArrayLayer = 0;
			info.subresourceRange.layerCount     = 1;

			for (uint32_t i = 0; i < uImageCount; ++i)
			{
				ImGui_ImplVulkanH_Frame* fd = &m_VkFrames[i];
				info.image                  = fd->Backbuffer;

				if (const VkResult result = vkCreateImageView(device, &info, m_VkAllocator, &fd->BackbufferView))
				{
					LOG(WARNING) << "vkCreateImageView failed with result: [" << result << "]";
					return;
				}
			}
		}
		{
			VkImageView attachment[1];
			VkFramebufferCreateInfo info = {};
			info.sType                   = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
			info.renderPass              = m_VkRenderPass;
			info.attachmentCount         = 1;
			info.pAttachments            = attachment;
			info.layers                  = 1;

			for (uint32_t i = 0; i < uImageCount; ++i)
			{
				ImGui_ImplVulkanH_Frame* fd = &m_VkFrames[i];
				attachment[0]               = fd->BackbufferView;

				if (const VkResult result = vkCreateFramebuffer(device, &info, m_VkAllocator, &fd->Framebuffer))
				{
					LOG(WARNING) << "vkCreateFramebuffer failed with result: [" << result << "]";
					return;
				}
			}
		}

		if (!m_VkDescriptorPool) // Create Descriptor Pool.
		{
			constexpr VkDescriptorPoolSize pool_sizes[] = {{VK_DESCRIPTOR_TYPE_SAMPLER, 1000}, {VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1000}, {VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, 1000}, {VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, 1000}, {VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER, 1000}, {VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER, 1000}, {VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1000}, {VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 1000}, {VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, 1000}, {VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, 1000}, {VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, 1000}};

			VkDescriptorPoolCreateInfo pool_info = {};
			pool_info.sType                      = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
			pool_info.flags                      = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
			pool_info.maxSets                    = 1000 * IM_ARRAYSIZE(pool_sizes);
			pool_info.poolSizeCount              = (uint32_t)IM_ARRAYSIZE(pool_sizes);
			pool_info.pPoolSizes                 = pool_sizes;

			if (const VkResult result = vkCreateDescriptorPool(device, &pool_info, m_VkAllocator, &m_VkDescriptorPool))
			{
				LOG(WARNING) << "vkCreateDescriptorPool failed with result: [" << result << "]";
				return;
			}
		}
	}

	void Renderer::VkCleanupRenderTarget()
	{
		for (uint32_t i = 0; i < RTL_NUMBER_OF(GetInstance().m_VkFrames); ++i)
		{
			if (GetInstance().m_VkFrames[i].Fence)
			{
				vkDestroyFence(GetInstance().m_VkDevice, GetInstance().m_VkFrames[i].Fence, GetInstance().m_VkAllocator);
				GetInstance().m_VkFrames[i].Fence = VK_NULL_HANDLE;
			}
			if (GetInstance().m_VkFrames[i].CommandBuffer)
			{
				vkFreeCommandBuffers(GetInstance().m_VkDevice,
				    GetInstance().m_VkFrames[i].CommandPool,
				    1,
				    &GetInstance().m_VkFrames[i].CommandBuffer);
				GetInstance().m_VkFrames[i].CommandBuffer = VK_NULL_HANDLE;
			}
			if (GetInstance().m_VkFrames[i].CommandPool)
			{
				vkDestroyCommandPool(GetInstance().m_VkDevice, GetInstance().m_VkFrames[i].CommandPool, GetInstance().m_VkAllocator);
				GetInstance().m_VkFrames[i].CommandPool = VK_NULL_HANDLE;
			}
			if (GetInstance().m_VkFrames[i].BackbufferView)
			{
				vkDestroyImageView(GetInstance().m_VkDevice, GetInstance().m_VkFrames[i].BackbufferView, GetInstance().m_VkAllocator);
				GetInstance().m_VkFrames[i].BackbufferView = VK_NULL_HANDLE;
			}
			if (GetInstance().m_VkFrames[i].Framebuffer)
			{
				vkDestroyFramebuffer(GetInstance().m_VkDevice, GetInstance().m_VkFrames[i].Framebuffer, GetInstance().m_VkAllocator);
				GetInstance().m_VkFrames[i].Framebuffer = VK_NULL_HANDLE;
			}
		}

		for (uint32_t i = 0; i < RTL_NUMBER_OF(GetInstance().m_VkFrameSemaphores); ++i)
		{
			if (GetInstance().m_VkFrameSemaphores[i].ImageAcquiredSemaphore)
			{
				vkDestroySemaphore(GetInstance().m_VkDevice,
				    GetInstance().m_VkFrameSemaphores[i].ImageAcquiredSemaphore,
				    GetInstance().m_VkAllocator);
				GetInstance().m_VkFrameSemaphores[i].ImageAcquiredSemaphore = VK_NULL_HANDLE;
			}
			if (GetInstance().m_VkFrameSemaphores[i].RenderCompleteSemaphore)
			{
				vkDestroySemaphore(GetInstance().m_VkDevice,
				    GetInstance().m_VkFrameSemaphores[i].RenderCompleteSemaphore,
				    GetInstance().m_VkAllocator);
				GetInstance().m_VkFrameSemaphores[i].RenderCompleteSemaphore = VK_NULL_HANDLE;
			}
		}

		if (IsResizing())
		{
			ImGui_ImplWin32_Shutdown();
			ImGui::DestroyContext();
			ImGui::CreateContext(&GetInstance().m_FontAtlas);
			ImGui_ImplWin32_Init(*Pointers.Hwnd);
			Menu::SetupStyle();

			SetResizing(false);
		}
	}

	bool Renderer::DoesQueueSupportGraphic(VkQueue queue, VkQueue* pGraphicQueue)
	{
		for (uint32_t i = 0; i < m_VKQueueFamilies.size(); ++i)
		{
			const VkQueueFamilyProperties& family = m_VKQueueFamilies[i];
			for (uint32_t j = 0; j < family.queueCount; ++j)
			{
				VkQueue it = VK_NULL_HANDLE;
				vkGetDeviceQueue(m_VkDevice, i, j, &it);

				if (pGraphicQueue && family.queueFlags & VK_QUEUE_GRAPHICS_BIT)
				{
					if (*pGraphicQueue == VK_NULL_HANDLE)
					{
						*pGraphicQueue = it;
					}
				}


				if (queue == it && family.queueFlags & VK_QUEUE_GRAPHICS_BIT)
				{
					return true;
				}
			}
		}

		return false;
	}

	void Renderer::VkOnPresentImpl(VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
	{
		if (!m_VkDevice || !g_Running || IsResizing())
		{
			return;
		}

		if (!ImGui::GetCurrentContext())
		{
			ImGui::CreateContext(&GetInstance().m_FontAtlas);
			ImGui_ImplWin32_Init(*Pointers.Hwnd);
		}

		VkQueue GraphicQueue            = VK_NULL_HANDLE;
		const bool QueueSupportsGraphic = DoesQueueSupportGraphic(queue, &GraphicQueue);

		for (uint32_t i = 0; i < pPresentInfo->swapchainCount; ++i)
		{
			VkSwapchainKHR swapchain = pPresentInfo->pSwapchains[i];
			if (m_VkFrames[0].Framebuffer == VK_NULL_HANDLE)
			{
				VkCreateRenderTarget(m_VkDevice, swapchain);
			}

			ImGui_ImplVulkanH_Frame* fd            = &m_VkFrames[pPresentInfo->pImageIndices[i]];
			ImGui_ImplVulkanH_FrameSemaphores* fsd = &m_VkFrameSemaphores[pPresentInfo->pImageIndices[i]];
			{
				if (const VkResult result = vkWaitForFences(m_VkDevice, 1, &fd->Fence, VK_TRUE, ~0ull); result != VK_SUCCESS)
				{
					LOG(WARNING) << "vkWaitForFences failed with result: [" << result << "]";
					return;
				}

				if (const VkResult result = vkResetFences(m_VkDevice, 1, &fd->Fence); result != VK_SUCCESS)
				{
					LOG(WARNING) << "vkResetFences failed with result: [" << result << "]";
					return;
				}
			}
			{
				if (const VkResult result = vkResetCommandBuffer(fd->CommandBuffer, 0); result != VK_SUCCESS)
				{
					LOG(WARNING) << "vkResetCommandBuffer failed with result: [" << result << "]";
					return;
				}

				VkCommandBufferBeginInfo info = {};
				info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
				info.flags |= VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

				if (const VkResult result = vkBeginCommandBuffer(fd->CommandBuffer, &info); result != VK_SUCCESS)
				{
					LOG(WARNING) << "vkBeginCommandBuffer failed with result: [" << result << "]";
					return;
				}
			}
			{
				VkRenderPassBeginInfo info = {};
				info.sType                 = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
				info.renderPass            = m_VkRenderPass;
				info.framebuffer           = fd->Framebuffer;
				if (m_VkImageExtent.width == 0 || m_VkImageExtent.height == 0)
				{
					info.renderArea.extent.width  = *Pointers.ScreenResX;
					info.renderArea.extent.height = *Pointers.ScreenResY;
				}
				else
				{
					info.renderArea.extent = m_VkImageExtent;
				}

				vkCmdBeginRenderPass(fd->CommandBuffer, &info, VK_SUBPASS_CONTENTS_INLINE);
			}

			if (!ImGui::GetIO().BackendRendererUserData)
			{
				ImGui_ImplVulkan_InitInfo init_info = {};
				init_info.Instance                  = m_VkInstance;
				init_info.PhysicalDevice            = m_VkPhysicalDevice;
				init_info.Device                    = m_VkDevice;
				init_info.QueueFamily               = m_VkQueueFamily;
				init_info.Queue                     = GraphicQueue;
				init_info.PipelineCache             = m_VkPipelineCache;
				init_info.DescriptorPool            = m_VkDescriptorPool;
				init_info.Subpass                   = 0;
				init_info.MinImageCount             = m_VkMinImageCount;
				init_info.ImageCount                = m_VkMinImageCount;
				init_info.MSAASamples               = VK_SAMPLE_COUNT_1_BIT;
				init_info.Allocator                 = m_VkAllocator;

				ImGui_ImplVulkan_Init(&init_info);

				ImGui_ImplVulkan_CreateFontsTexture();
			}

			ImGui_ImplVulkan_NewFrame();
			ImGui_ImplWin32_NewFrame();
			ImGui::NewFrame();

			for (const auto& callback : m_RendererCallBacks | std::views::values)
				callback();

			ImGui::Render();

			ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), fd->CommandBuffer);

			vkCmdEndRenderPass(fd->CommandBuffer);
			vkEndCommandBuffer(fd->CommandBuffer);

			uint32_t waitSemaphoresCount = i == 0 ? pPresentInfo->waitSemaphoreCount : 0;
			if (waitSemaphoresCount == 0 && !QueueSupportsGraphic)
			{
				constexpr VkPipelineStageFlags stages_wait = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT;
				{
					VkSubmitInfo info = {};
					info.sType        = VK_STRUCTURE_TYPE_SUBMIT_INFO;

					info.pWaitDstStageMask = &stages_wait;

					info.signalSemaphoreCount = 1;
					info.pSignalSemaphores    = &fsd->RenderCompleteSemaphore;

					if (const VkResult result = vkQueueSubmit(queue, 1, &info, VK_NULL_HANDLE); result != VK_SUCCESS)
					{
						LOG(WARNING) << "vkQueueSubmit failed with result: [" << result << "]";
						return;
					}
				}
				{
					VkSubmitInfo info       = {};
					info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
					info.commandBufferCount = 1;
					info.pCommandBuffers    = &fd->CommandBuffer;

					info.pWaitDstStageMask  = &stages_wait;
					info.waitSemaphoreCount = 1;
					info.pWaitSemaphores    = &fsd->RenderCompleteSemaphore;

					info.signalSemaphoreCount = 1;
					info.pSignalSemaphores    = &fsd->ImageAcquiredSemaphore;

					if (const VkResult result = vkQueueSubmit(GraphicQueue, 1, &info, fd->Fence); result != VK_SUCCESS)
					{
						LOG(WARNING) << "vkQueueSubmit 2 failed with result: [" << result << "]";
						return;
					}
				}
			}
			else
			{
				std::vector<VkPipelineStageFlags> stages_wait(waitSemaphoresCount, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT);

				VkSubmitInfo info       = {};
				info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
				info.commandBufferCount = 1;
				info.pCommandBuffers    = &fd->CommandBuffer;

				info.pWaitDstStageMask  = stages_wait.data();
				info.waitSemaphoreCount = waitSemaphoresCount;
				info.pWaitSemaphores    = pPresentInfo->pWaitSemaphores;

				info.signalSemaphoreCount = 1;
				info.pSignalSemaphores    = &fsd->ImageAcquiredSemaphore;

				if (const VkResult result = vkQueueSubmit(GraphicQueue, 1, &info, fd->Fence); result != VK_SUCCESS)
				{
					LOG(WARNING) << "vkQueueSubmit 3 failed with result: [" << result << "]";
					return;
				}
			}
		}
	}


	bool Renderer::InitImpl()
	{
		while (!*Pointers.Hwnd || !*Pointers.ScreenResX)
		{
			std::this_thread::sleep_for(1s);
		}

		if (const auto& RendererInfo = Pointers.GetRendererInfo(); RendererInfo)
		{
			if (RendererInfo->is_rendering_type(eRenderingType::DX12))
			{
				Pointers.IsVulkan = false;
			}
			else if (RendererInfo->is_rendering_type(eRenderingType::Vulkan))
			{
				Pointers.IsVulkan = true;
			}
			else
			{
				LOG(INFO) << "Unknown renderer type!";
				return false;
			}
		}
		else
		{
			LOG(INFO) << "Invalid renderer info!";
			return false;
		}

		if (Pointers.IsVulkan)
		{
			LOG(INFO) << "Using Vulkan";
			return InitVulkan();
		}
		else if (!Pointers.IsVulkan)
		{
			LOG(INFO) << "Using DX12, clear shader cache if you're having issues.";
			LOG(INFO) << "Waiting...";
			std::this_thread::sleep_for(5s); //Early injection could result in errors.
			return InitDX12();
		}

		return false;
	}

	bool Renderer::AddRendererCallBackImpl(RendererCallBack&& callback, std::uint32_t priority)
	{
		return m_RendererCallBacks.insert({priority, callback}).second;
	}

	void Renderer::AddWindowProcedureCallbackImpl(WindowProcedureCallback&& callback)
	{
		return m_WindowProcedureCallbacks.push_back(callback);
	}

	void Renderer::DX12OnPresentImpl()
	{
		Renderer::DX12NewFrame();
		for (const auto& callback : m_RendererCallBacks | std::views::values)
			callback();
		Renderer::DX12EndFrame();
	}

	LRESULT Renderer::WndProcImpl(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		for (const auto& callback : m_WindowProcedureCallbacks)
			callback(hwnd, msg, wparam, lparam);

		return ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam);
	}

	void Renderer::WaitForLastFrame()
	{
		FrameContext FrameCtx = GetInstance().m_FrameContext[GetInstance().m_FrameIndex % GetInstance().m_SwapChainDesc.BufferCount];

		UINT64 FenceValue = FrameCtx.FenceValue;

		if (FenceValue == 0)
		{
			return;
		}

		FrameCtx.FenceValue = 0;

		if (GetInstance().m_Fence->GetCompletedValue() >= FenceValue)
		{
			return;
		}

		GetInstance().m_Fence->SetEventOnCompletion(FenceValue, GetInstance().m_FenceEvent);

		WaitForSingleObject(GetInstance().m_FenceEvent, INFINITE);
	}

	void Renderer::WaitForNextFrame()
	{
		UINT NextFrameIndex        = GetInstance().m_FrameIndex + 1;
		GetInstance().m_FrameIndex = NextFrameIndex;

		HANDLE WaitableObjects[] = {GetInstance().m_SwapchainWaitableObject, nullptr};
		DWORD NumWaitableObjets  = 1;

		FrameContext FrameCtx = GetInstance().m_FrameContext[NextFrameIndex % GetInstance().m_SwapChainDesc.BufferCount];
		UINT64 FenceValue = FrameCtx.FenceValue;
		if (FenceValue != 0) // means no fence was signaled
		{
			FrameCtx.FenceValue = 0;
			GetInstance().m_Fence->SetEventOnCompletion(FenceValue, GetInstance().m_FenceEvent);
			WaitableObjects[1] = GetInstance().m_FenceEvent;
			NumWaitableObjets  = 2;
		}

		WaitForMultipleObjects(NumWaitableObjets, WaitableObjects, TRUE, INFINITE);
	}

	void Renderer::DX12PreResize()
	{
		SetResizing(true);

		WaitForLastFrame();

		ImGui_ImplDX12_InvalidateDeviceObjects();

		for (size_t i{}; i != GetInstance().m_SwapChainDesc.BufferCount; ++i)
		{
			REL(GetInstance().m_FrameContext[i].Resource);
		}
	}

	void Renderer::DX12PostResize()
	{
		//Recreate our pointers and ImGui's
		ImGui_ImplDX12_CreateDeviceObjects();
		const auto RTVDescriptorSize{GetInstance().m_Device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV)};
		D3D12_CPU_DESCRIPTOR_HANDLE RTVHandle{GetInstance().m_BackbufferDescriptorHeap->GetCPUDescriptorHandleForHeapStart()};
		for (size_t i{}; i != GetInstance().m_SwapChainDesc.BufferCount; ++i)
		{
			ComPtr<ID3D12Resource> BackBuffer{};
			GetInstance().m_FrameContext[i].Descriptor = RTVHandle;
			GetInstance().m_SwapChain->GetBuffer(i, __uuidof(ID3D12Resource), (void**)BackBuffer.GetAddressOf());
			GetInstance().m_Device->CreateRenderTargetView(BackBuffer.Get(), nullptr, RTVHandle);
			GetInstance().m_FrameContext[i].Resource = BackBuffer.Get();
			RTVHandle.ptr += RTVDescriptorSize;
		}

		SetResizing(false);
	}

	void Renderer::DX12NewFrame()
	{
		ImGui_ImplDX12_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
	}

	void Renderer::DX12EndFrame()
	{
		WaitForNextFrame();

		FrameContext& CurrentFrameContext{GetInstance().m_FrameContext[GetInstance().m_SwapChain->GetCurrentBackBufferIndex()]};
		CurrentFrameContext.CommandAllocator->Reset();

		D3D12_RESOURCE_BARRIER Barrier{D3D12_RESOURCE_BARRIER_TYPE_TRANSITION,
		    D3D12_RESOURCE_BARRIER_FLAG_NONE,
		    {{CurrentFrameContext.Resource, D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES, D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET}}};
		GetInstance().m_CommandList->Reset(CurrentFrameContext.CommandAllocator, nullptr);
		GetInstance().m_CommandList->ResourceBarrier(1, &Barrier);
		GetInstance().m_CommandList->OMSetRenderTargets(1, &CurrentFrameContext.Descriptor, FALSE, nullptr);
		GetInstance().m_CommandList->SetDescriptorHeaps(1, GetInstance().m_DescriptorHeap.GetAddressOf());

		ImGui::Render();
		ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), GetInstance().m_CommandList.Get());

		Barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
		Barrier.Transition.StateAfter  = D3D12_RESOURCE_STATE_PRESENT;
		GetInstance().m_CommandList->ResourceBarrier(1, &Barrier);
		GetInstance().m_CommandList->Close();

		ID3D12CommandList* CommandLists[]{GetInstance().m_CommandList.Get()};
		GetInstance().m_CommandQueue->ExecuteCommandLists(_countof(CommandLists), CommandLists);

		UINT64 FenceValue = GetInstance().m_FenceLastSignaledValue + 1;
		GetInstance().m_CommandQueue->Signal(GetInstance().m_Fence.Get(), FenceValue);
		GetInstance().m_FenceLastSignaledValue = FenceValue;
		CurrentFrameContext.FenceValue         = FenceValue;
	}
}