#include "Pointers.hpp"

#include "core/memory/BytePatch.hpp"
#include "core/memory/ModuleMgr.hpp"
#include "core/memory/PatternScanner.hpp"
#include "util/Joaat.hpp"
#include "core/renderer/Renderer.hpp"

namespace YimMenu
{
	bool Pointers::Init()
	{
		const auto rdr2 = ModuleMgr.Get("RDR2.exe"_J);
		if (!rdr2)
		{
			LOG(FATAL) << "Could not find RDR2.exe, is this RDR2?";

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

	    constexpr auto gfxInformation = Pattern<"48 8D 0D ? ? ? ? 48 8B F8 E8 ? ? ? ? 45 33 ED 45 84 FF">("GFXInformation");
	    scanner.Add(gfxInformation, [this](PointerCalculator ptr) {
	    	auto gfx = ptr.Add(3).Rip().As<uint64_t*>();

			if (*reinterpret_cast<uint8_t*>((uint64_t)gfx + 0x10C))
			{
				LOG(WARNING) << "Turn HDR off!";
			}
	
			if (*reinterpret_cast<uint8_t*>((uint64_t)gfx + 0xC))
			{
				LOG(INFO) << "Ew motion blur. Seriously?";
			}

			if (*reinterpret_cast<DWORD*>((uint64_t)gfx + 0x150))
			{
				ScreenResX = *reinterpret_cast<DWORD*>((uint64_t)gfx + 0x13C); 
				ScreenResY =  *reinterpret_cast<DWORD*>((uint64_t)gfx + 0x140);
				LOG(INFO) << "Screen Resolution: " << ScreenResX << "x" << ScreenResY;
			}

	    });
		
		constexpr auto wndProc = Pattern<"48 89 5C 24 ? 4C 89 4C 24 ? 48 89 4C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 60">("WndProc");
		scanner.Add(wndProc, [this](PointerCalculator ptr) {
			WndProc = ptr.As<PVOID>();
		});

		constexpr auto getNativeHandlerPtrn = Pattern<"E8 ? ? ? ? 42 8B 9C FE">("GetNativeHandler");
		scanner.Add(getNativeHandlerPtrn, [this](PointerCalculator ptr) {
			GetNativeHandler = ptr.Add(1).Rip().As<Functions::GetNativeHandler>();
		});

		constexpr auto fixVectorsPtrn = Pattern<"8B 41 18 4C 8B C1 85">("FixVectors");
		scanner.Add(fixVectorsPtrn, [this](PointerCalculator ptr) {
			FixVectors = ptr.As<Functions::FixVectors>();
		});

		constexpr auto scriptThreadsPtrn = Pattern<"48 8D 0D ? ? ? ? E8 ? ? ? ? EB 0B 8B 0D">("ScriptThreads&RunScriptThreads");
		scanner.Add(scriptThreadsPtrn, [this](PointerCalculator ptr) {
			ScriptThreads    = ptr.Add(3).Rip().As<rage::atArray<rage::scrThread*>*>();
			RunScriptThreads = ptr.Add(8).Rip().As<PVOID>();
		});

		constexpr auto currentScriptThreadPtrn = Pattern<"48 89 2D ? ? ? ? 48 89 2D ? ? ? ? 48 8B 04 F9">("CurrentScriptThread");
		scanner.Add(currentScriptThreadPtrn, [this](PointerCalculator ptr) {
			CurrentScriptThread = ptr.Add(3).Rip().As<rage::scrThread**>();
		});

		constexpr auto hwnd = Pattern<"4C 8B 05 ? ? ? ? 4C 8D 0D ? ? ? ? 48 89 54 24">("Hwnd");
		scanner.Add(hwnd, [this](PointerCalculator ptr) {
			Hwnd = *ptr.Add(3).Rip().As<HWND*>();
			LOG(INFO) << "HWND: " << Hwnd;
		});

		if (!scanner.Scan())
		{
			LOG(FATAL) << "Some patterns could not be found, unloading.";

			return false;
		}

		if (const auto& RendererInfo = GetRendererInfo(); RendererInfo)
		{
			if (RendererInfo->is_rendering_type(eRenderingType::DX12))
			{
				IsVulkan = false;
			}
			else if (RendererInfo->is_rendering_type(eRenderingType::Vulkan))
			{
				IsVulkan = true;
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

		return true;
	}
}