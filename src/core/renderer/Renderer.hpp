#pragma once
#pragma comment(lib, "dxgi.lib")

#include "util/Joaat.hpp"

#include <backends/imgui_impl_vulkan.h>
#include <backends/imgui_impl_dx12.h>
#include <backends/imgui_impl_win32.h>
#include <comdef.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#include <functional>
#include <map>
#include <vulkan/vulkan.h>
#include <windows.h>
#include <wrl/client.h>


#define REL(o)       \
	o->Release();    \
	if (o)           \
	{                \
		o = nullptr; \
	}


constexpr UINT SRV_HEAP_SIZE = 128;

// https://github.com/YimMenu/YimMenuV2/blob/enhanced/src/core/renderer/Renderer.cpp
struct SrvHeapAllocator
{
	void Init(ID3D12Device* device, ID3D12DescriptorHeap* heap)
	{
		DescriptorSize = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
		HeapStartCpu   = heap->GetCPUDescriptorHandleForHeapStart();
		HeapStartGpu   = heap->GetGPUDescriptorHandleForHeapStart();

		FreeIndices.clear();
		FreeIndices.reserve(64);
		for (int i = 64 - 1; i >= 0; --i)
			FreeIndices.push_back(i);
	}

	void Alloc(D3D12_CPU_DESCRIPTOR_HANDLE* outCpu, D3D12_GPU_DESCRIPTOR_HANDLE* outGpu)
	{
		if (FreeIndices.empty())
		{
			LOG(FATAL) << "SRV heap exhausted!";
			*outCpu = HeapStartCpu;
			*outGpu = HeapStartGpu;
			return;
		}

		int index = FreeIndices.back();
		FreeIndices.pop_back();

		outCpu->ptr = HeapStartCpu.ptr + static_cast<SIZE_T>(index) * DescriptorSize;
		outGpu->ptr = HeapStartGpu.ptr + static_cast<UINT64>(index) * DescriptorSize;
	}

	void Free(D3D12_CPU_DESCRIPTOR_HANDLE cpu, D3D12_GPU_DESCRIPTOR_HANDLE gpu)
	{
		int index = static_cast<int>((cpu.ptr - HeapStartCpu.ptr) / DescriptorSize);
		FreeIndices.push_back(index);
	}

	UINT DescriptorSize                      = 0;
	D3D12_CPU_DESCRIPTOR_HANDLE HeapStartCpu = {};
	D3D12_GPU_DESCRIPTOR_HANDLE HeapStartGpu = {};
	std::vector<int> FreeIndices             = {};
};

namespace Terminus
{
	using namespace Microsoft::WRL;
	using RendererCallBack        = std::function<void()>;
	using WindowProcedureCallback = std::function<void(HWND, UINT, WPARAM, LPARAM)>;

	struct FrameContext
	{
		ID3D12CommandAllocator* CommandAllocator;
		ID3D12Resource* Resource;
		D3D12_CPU_DESCRIPTOR_HANDLE Descriptor;
		UINT64 FenceValue;
	};

	class Renderer final
	{
	private:
		Renderer();

	public:
		~Renderer();

		Renderer(const Renderer&)                = delete;
		Renderer(Renderer&&) noexcept            = delete;
		Renderer& operator=(const Renderer&)     = delete;
		Renderer& operator=(Renderer&&) noexcept = delete;

		static void Destroy()
		{
			GetInstance().DestroyImpl();
		}

		static bool Init()
		{
			return GetInstance().InitImpl();
		}

		/**
		 * @brief Add a callback function to draw using ImGui
		 * 
		 * @param callback Callback function
		 * @param priority Low values will be drawn before higher values.
		 * @return true Successfully added callback.
		 * @return false Duplicate render priority was given.
		 */
		static bool AddRendererCallBack(RendererCallBack&& callback, std::uint32_t priority)
		{
			return GetInstance().AddRendererCallBackImpl(std::move(callback), priority);
		}
		/**
		 * @brief Add a callback function to handle Windows WindowProcedure
		 * 
		 * @param callback Callback function
		 */
		static void AddWindowProcedureCallback(WindowProcedureCallback&& callback)
		{
			GetInstance().AddWindowProcedureCallbackImpl(std::move(callback));
		}

		static void DX12OnPresent()
		{
			GetInstance().DX12OnPresentImpl();
		}

		static void VkOnPresent(VkQueue queue, const VkPresentInfoKHR* pPresentInfo)
		{
			if (!queue)
			{
				LOG(FATAL) << "Invalid Vulkan Queue!";

				return;
			}

			if (!pPresentInfo)
			{
				LOG(FATAL) << "Invalid Vulkan Present Info!";

				return;
			}

			GetInstance().VkOnPresentImpl(queue, pPresentInfo);
		}

		static LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
		{
			return GetInstance().WndProcImpl(hwnd, msg, wparam, lparam);
		}

		static void WaitForLastFrame();
		static void WaitForNextFrame();

		static void DX12PreResize();
		static void DX12PostResize();

		static void VkCleanupRenderTarget();

		static bool IsResizing()
		{
			return GetInstance().m_Resizing;
		}

		static void SetResizing(const bool& status)
		{
			GetInstance().m_Resizing = status;
		}

		static void Resize(float scale)
		{
			GetInstance().ResizeImpl(scale);
		}

		static void VkSetDevice(VkDevice device)
		{
			if (!device)
			{
				LOG(FATAL) << "Invalid Vulkan Device!";

				return;
			}

			GetInstance().m_VkDevice = device;
		}
		static void VkSetScreenSize(VkExtent2D extent)
		{
			GetInstance().m_VkImageExtent = extent;
		}

		static void SetFontsUpdated()
		{
			GetInstance().m_FontsUpdated = true;
		}

	private:
		void DX12NewFrame();
		void DX12EndFrame();

		void DestroyImpl();
		bool InitImpl();

		bool InitVulkan();
		bool InitDX12();
		void DX12Destroy();

		void ResizeImpl(float scale);

		void VkCreateRenderTarget(VkDevice Device, VkSwapchainKHR Swapchain);

		bool AddRendererCallBackImpl(RendererCallBack&& callback, std::uint32_t priority);
		void AddWindowProcedureCallbackImpl(WindowProcedureCallback&& callback);

		void DX12OnPresentImpl();
		void VkOnPresentImpl(VkQueue queue, const VkPresentInfoKHR* pPresentInfo);

		bool DoesQueueSupportGraphic(VkQueue queue, VkQueue* pGraphicQueue);

		LRESULT WndProcImpl(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

		static Renderer& GetInstance()
		{
			static Renderer i{};

			return i;
		}

	private:
		bool m_Resizing;
		bool m_FontsUpdated;

		//DX12
		std::vector<FrameContext> m_FrameContext;

		DXGI_SWAP_CHAIN_DESC m_SwapChainDesc;
		ComPtr<IDXGISwapChain1> m_GameSwapChain;
		ComPtr<IDXGISwapChain3> m_SwapChain;
		ComPtr<ID3D12Device> m_Device;
		ComPtr<ID3D12CommandQueue> m_CommandQueue;
		ComPtr<ID3D12CommandAllocator> m_CommandAllocator;
		ComPtr<ID3D12GraphicsCommandList> m_CommandList;
		ComPtr<ID3D12DescriptorHeap> m_BackbufferDescriptorHeap;
		ComPtr<ID3D12DescriptorHeap> m_DescriptorHeap;

		ComPtr<ID3D12Fence> m_Fence;
		HANDLE m_FenceEvent;
		UINT64 m_FenceLastSignaledValue;
		HANDLE m_SwapchainWaitableObject;
		UINT64 m_FrameIndex;
		D3D12_CPU_DESCRIPTOR_HANDLE m_MainRenderTargetDescriptor[2]{};
		SrvHeapAllocator m_SrvHeapAllocator;

		//Vulkan
		VkPhysicalDevice m_VkPhysicalDevice;
		VkInstance m_VkInstance;
		VkAllocationCallbacks* m_VkAllocator = nullptr;
		std::vector<VkQueueFamilyProperties> m_VKQueueFamilies;
		uint32_t m_VkQueueFamily = (uint32_t)-1;
		VkDevice m_VkFakeDevice;
		VkDevice m_VkDevice;
		ImGui_ImplVulkanH_Frame m_VkFrames[8]                    = {};
		ImGui_ImplVulkanH_FrameSemaphores m_VkFrameSemaphores[8] = {};
		VkRenderPass m_VkRenderPass;
		VkDescriptorPool m_VkDescriptorPool;
		VkPipelineCache m_VkPipelineCache;
		uint32_t m_VkMinImageCount = 2;
		VkExtent2D m_VkImageExtent;

	private:
		//Other
		std::map<joaat_t, RendererCallBack> m_RendererCallBacks;
		std::vector<WindowProcedureCallback> m_WindowProcedureCallbacks;
		bool m_Initialized;
	};
}

// Make our linker aware of the ImGui WndProcHandler
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
