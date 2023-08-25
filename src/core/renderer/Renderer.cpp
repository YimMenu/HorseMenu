#include "Renderer.hpp"

#include "game/pointers/Pointers.hpp"
#include "game/frontend/GUI.hpp"

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
		ImGui_ImplDX12_Shutdown();
		ImGui::DestroyContext();
	}

	bool Renderer::InitImpl()
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

		m_FrameContext.reserve(m_SwapChainDesc.BufferCount);

		D3D12_DESCRIPTOR_HEAP_DESC DescriptorDesc{ D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV, m_SwapChainDesc.BufferCount, D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE };
		if (const auto result = m_Device->CreateDescriptorHeap(&DescriptorDesc, __uuidof(ID3D12DescriptorHeap), (void**)m_DescriptorHeap.GetAddressOf()); result < 0)
		{
			LOG(WARNING) << "Failed to create Descriptor Heap with result: [" << result << "]";

			return false;
		}

		if (const auto result = m_Device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, __uuidof(ID3D12CommandAllocator), (void**)m_CommandAllocator.GetAddressOf()); result < 0)
		{
			LOG(WARNING) << "Failed to create Command Allocator with result: [" << result << "]";

			return false;
		}

		for (size_t i{}; i != m_SwapChainDesc.BufferCount; ++i)
		{
			m_FrameContext[i].CommandAllocator = m_CommandAllocator.Get();
		}

		if (const auto result = m_Device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, m_CommandAllocator.Get(), NULL, __uuidof(ID3D12GraphicsCommandList), (void**)m_CommandList.GetAddressOf()); result < 0)
		{
			LOG(WARNING) << "Failed to create Command List with result: [" << result << "]";

			return false;
		}

		if (const auto result = m_CommandList->Close(); result < 0)
		{
			LOG(WARNING) << "Failed to finalize the creation of Command List with result: [" << result << "]";

			return false;
		}

		D3D12_DESCRIPTOR_HEAP_DESC DescriptorBackbufferDesc{ D3D12_DESCRIPTOR_HEAP_TYPE_RTV, m_SwapChainDesc.BufferCount, D3D12_DESCRIPTOR_HEAP_FLAG_NONE, 1 };
		if (const auto result = m_Device->CreateDescriptorHeap(&DescriptorBackbufferDesc, __uuidof(ID3D12DescriptorHeap), (void**)m_BackbufferDescriptorHeap.GetAddressOf()); result < 0)
		{
			LOG(WARNING) << "Failed to create Backbuffer Descriptor Heap with result: [" << result << "]";

			return false;
		}
	
		const auto RTVDescriptorSize{ m_Device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV) };
		D3D12_CPU_DESCRIPTOR_HANDLE RTVHandle{ m_BackbufferDescriptorHeap->GetCPUDescriptorHandleForHeapStart() };
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
		ImGui::CreateContext();
		ImGui_ImplWin32_Init(Pointers.Hwnd);
		ImGui_ImplDX12_Init(m_Device.Get(), m_SwapChainDesc.BufferCount, DXGI_FORMAT_R8G8B8A8_UNORM, m_DescriptorHeap.Get(), m_DescriptorHeap->GetCPUDescriptorHandleForHeapStart(), m_DescriptorHeap->GetGPUDescriptorHandleForHeapStart());

		ImGui::StyleColorsDark();

		LOG(INFO) << "Renderer has finished initializing.";
		return true;
	}

	bool Renderer::AddDXCallbackImpl(DXCallback&& callback, std::uint32_t priority)
	{
		return m_DXCallbacks.insert({priority, callback}).second;
	}

	void Renderer::AddWindowProcedureCallbackImpl(WindowProcedureCallback&& callback)
	{
		return m_WindowProcedureCallbacks.push_back(callback);
	}

	void Renderer::OnPresentImpl()
	{
		Renderer::NewFrame();
		for (const auto& callback : m_DXCallbacks | std::views::values)
			callback();
		Renderer::EndFrame();
	}

	LRESULT Renderer::WndProcImpl(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		for (const auto& callback : m_WindowProcedureCallbacks)
			callback(hwnd, msg, wparam, lparam);

		return ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam);
	}

	//This is needed because of how DX12 resizing works. It waits for the last frame to finish then invalidates objects. We would use fence for that.
	//	However, it requires alot of work and logic, making it not worth it. In all of my testing, just simply waiting a bit works.
	void Renderer::WaitForLastFrame()
	{
		std::this_thread::sleep_for(200ms);
	}

	void Renderer::PreResize()
	{
		GetInstance().m_Resizing = true;
		WaitForLastFrame();

        ImGui_ImplDX12_InvalidateDeviceObjects();

		for (size_t i{}; i != GetInstance().m_SwapChainDesc.BufferCount; ++i)
		{
			REL(GetInstance().m_FrameContext[i].Resource);
		}
	}

	void Renderer::PostResize()
	{
		bool WasGUIOpen{ GUI::IsOpen() };
		//SetCursorPos is returning true while open, this is to ensure we sync them. When the GUI is open and we resize buffers, the cursor changes pos and likes to cause a issue.
		if (WasGUIOpen)
		{
			GUI::Toggle();
		}

		//Recreate our pointers and ImGui's
        ImGui_ImplDX12_CreateDeviceObjects();
		const auto RTVDescriptorSize{ GetInstance().m_Device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV) };
		D3D12_CPU_DESCRIPTOR_HANDLE RTVHandle{ GetInstance().m_BackbufferDescriptorHeap->GetCPUDescriptorHandleForHeapStart() };
		for (size_t i{}; i != GetInstance().m_SwapChainDesc.BufferCount; ++i)
		{
			ComPtr<ID3D12Resource> BackBuffer{};
			GetInstance().m_FrameContext[i].Descriptor = RTVHandle;
			GetInstance().m_SwapChain->GetBuffer(i, __uuidof(ID3D12Resource), (void**)BackBuffer.GetAddressOf());
			GetInstance().m_Device->CreateRenderTargetView(BackBuffer.Get(), nullptr, RTVHandle);
			GetInstance().m_FrameContext[i].Resource = BackBuffer.Get();
			RTVHandle.ptr += RTVDescriptorSize;
		}

		//Reopen our GUI if it was open
		if (WasGUIOpen)
		{
			GUI::Toggle();
		}

		GetInstance().m_Resizing = false;
	}

	void Renderer::NewFrame()
	{
		ImGui_ImplDX12_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
	}

	void Renderer::EndFrame()
	{
		ImGui::EndFrame();
		FrameContext& CurrentFrameContext{ GetInstance().m_FrameContext[GetInstance().m_SwapChain->GetCurrentBackBufferIndex()] };
		CurrentFrameContext.CommandAllocator->Reset();

		D3D12_RESOURCE_BARRIER Barrier{ D3D12_RESOURCE_BARRIER_TYPE_TRANSITION, D3D12_RESOURCE_BARRIER_FLAG_NONE, { { CurrentFrameContext.Resource, D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES, D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET } } };
		GetInstance().m_CommandList->Reset(CurrentFrameContext.CommandAllocator, nullptr);
		GetInstance().m_CommandList->ResourceBarrier(1, &Barrier);
		GetInstance().m_CommandList->OMSetRenderTargets(1, &CurrentFrameContext.Descriptor, FALSE, nullptr);
		GetInstance().m_CommandList->SetDescriptorHeaps(1, GetInstance().m_DescriptorHeap.GetAddressOf());

		ImGui::Render();
		ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), GetInstance().m_CommandList.Get());

		Barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
		Barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
		GetInstance().m_CommandList->ResourceBarrier(1, &Barrier);
		GetInstance().m_CommandList->Close();

		ID3D12CommandList* CommandLists[]{ GetInstance().m_CommandList.Get() };
		GetInstance().m_CommandQueue->ExecuteCommandLists(_countof(CommandLists), CommandLists);
	}
}