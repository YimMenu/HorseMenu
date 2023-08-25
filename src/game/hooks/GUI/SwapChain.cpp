#include "core/hooking/VMTHook.hpp"
#include "core/renderer/Renderer.hpp"
#include "game/hooks/Hooks.hpp"
#include "core/hooking/DetourHook.hpp"

namespace YimMenu
{
	HRESULT SwapChain::Present(IDXGISwapChain1* that, UINT syncInterval, UINT flags)
	{
		if (g_Running)
		{
			Renderer::OnPresent();
		}
		return BaseHook::Get<SwapChain::Present, DetourHook<decltype(&Present)>>()->Original()(that, syncInterval, flags);
	}

	HRESULT SwapChain::ResizeBuffers(IDXGISwapChain1* that, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags)
	{
		if (g_Running)
		{
			Renderer::PreResize();
			const auto result = BaseHook::Get<SwapChain::ResizeBuffers, DetourHook<decltype(&ResizeBuffers)>>()->Original()(that, bufferCount, width, height, newFormat, swapChainFlags);
			Renderer::PostResize();
			return result;
		}
		return BaseHook::Get<SwapChain::Present, DetourHook<decltype(&ResizeBuffers)>>()->Original()(that, bufferCount, width, height, newFormat, swapChainFlags);
	}
}