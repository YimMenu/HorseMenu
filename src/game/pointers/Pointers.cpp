#include "Pointers.hpp"

#include "core/memory/BytePatch.hpp"
#include "core/memory/ModuleMgr.hpp"
#include "core/memory/PatternScanner.hpp"
#include "util/Joaat.hpp"

namespace YimMenu
{
	bool Pointers::Init()
	{
		const auto rdr2 = ModuleMgr.Get("RDR2.exe"_J);
		if (!rdr2)
		{
			LOG(FATAL) << "Could not find " << rdr2->Name() << ", is this RDR2?";

			return false;
		}

		auto scanner = PatternScanner(rdr2);

		constexpr auto swapchainPtrn = Pattern<"48 8B 58 60 48 8B 0D">("IDXGISwapChain1");
		scanner.Add(swapchainPtrn, [this](PointerCalculator ptr) {
			SwapChain = ptr.Add(4).Add(3).Rip().As<IDXGISwapChain1**>();
		});

		constexpr auto commandQueuePtrn = Pattern<"FF 50 10 48 8B 0D ? ? ? ? 48 8B 01">("ID3D12CommandQueue");
		scanner.Add(commandQueuePtrn, [this](PointerCalculator ptr) {
			CommandQueue = ptr.Add(3).Add(3).Rip().As<ID3D12CommandQueue**>();
		});

		constexpr auto getRendererInfoPtrn = Pattern<"E8 ? ? ? ? 38 58 09">("GetRendererInfo");
		scanner.Add(getRendererInfoPtrn, [this](PointerCalculator ptr) {
			GetRendererInfo = ptr.Add(1).Rip().As<Functions::GetRendererInfo>();
		});

		constexpr auto getNativeAddressPtrn = Pattern<"E8 ? ? ? ? 42 8B 9C FE">("GetRendererInfo");
		scanner.Add(getNativeAddressPtrn, [this](PointerCalculator ptr) {
			GetNativeAddress = ptr.Add(1).Rip().As<Functions::GetNativeAddress>();
		});

		if (!scanner.Scan())
		{
			LOG(FATAL) << "Some patterns could not be found, unloading.";

			return false;
		}

		if (!GetRendererInfo)
		{
			LOG(FATAL) << "Failed to get rendering info, unloading.";

			return false;
		}
		else
		{
			RenderingInfo* info{ GetRendererInfo() };
			if (!info->is_rendering_type(eRenderingType::DX12))
			{
				LOG(FATAL) << "Unsupported rendering type, unloading.";

				return false;
			}
		}

		if (auto swapchain = *SwapChain)
		{
			if (auto result = swapchain->GetHwnd(&Hwnd); result < 0)
			{
				LOG(FATAL) << "Failed to grab game window from swapchain [" << result << "], unloading.";

				return false;
			}
			else if (!Hwnd)
			{
				LOG(FATAL) << "Game window is invalid, unloading.";

				return false;
			}
		}

		return true;
	}
}