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

		constexpr auto swapchainPtrn = Pattern<"48 8B 0D ? ? ? ? 45 8B C7 8B 53 08">("IDXGISwapChain");
		scanner.Add(swapchainPtrn, [this](PointerCalculator ptr) {
			SwapChain = ptr.Add(3).Rip().As<IDXGISwapChain**>();
		});

		// constexpr auto wndProcPtrn = Pattern<"48 8B C4 48 89 58 08 4C 89 48 20 55 56 57 41 54 41 55 41 56 41 57 48 8D 68 A1 48 81 EC F0">("WNDPROC");
		// scanner.Add(wndProcPtrn, [this](PointerCalculator ptr) {
		// 	WndProc = ptr.As<WNDPROC>();
		// });

		if (!scanner.Scan())
		{
			LOG(FATAL) << "Some patterns could not be found, unloading.";

			return false;
		}

		if (Hwnd = FindWindowA(0,"Red Dead Redemption 2"); !Hwnd)
		{
			LOG(FATAL) << "Failed to grab game window, unloading.";

			return false;
		}

		return true;
	}
}