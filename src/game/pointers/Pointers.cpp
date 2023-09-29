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

		constexpr auto sendMetricPtrn = Pattern<"48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 48 8B F1 48 8B FA B1">("SendMetric");
		scanner.Add(sendMetricPtrn, [this](PointerCalculator ptr) {
			SendMetric = ptr.As<PVOID*>();
		});

		constexpr auto vmDetectionCallbackPtrn = Pattern<"48 8B 0D ? ? ? ? 33 F6 E8 ? ? ? ? 48 8B 0D">("VMDetectionCallback");
		scanner.Add(vmDetectionCallbackPtrn, [this](PointerCalculator ptr) {
			auto loc =  ptr.Add(3).Rip().As<uint8_t*>();
			VmDetectionCallback = (PVOID*)loc;
			RageSecurityInitialized = (bool*)(loc - 6);
		});

		constexpr auto queueDependencyPtrn = Pattern<"E8 ? ? ? ? EB 43 8A 43 54">("QueueDependency");
		scanner.Add(queueDependencyPtrn, [this](PointerCalculator ptr) {
			QueueDependency = ptr.Add(1).Rip().As<PVOID>();
		});

		constexpr auto unkFunctionPtrn = Pattern<"40 53 48 83 EC 20 48 8B 59 20 48 8B 43 08 48 8B 4B">("UnkFunction");
		scanner.Add(unkFunctionPtrn, [this](PointerCalculator ptr) {
			UnkFunction = ptr.As<PVOID>();
		});

		constexpr auto scriptGlobalsPtrn = Pattern<"48 8D 15 ? ? ? ? 48 8B 1D ? ? ? ? 8B 3D">("ScriptGlobals");
		scanner.Add(scriptGlobalsPtrn, [this](PointerCalculator ptr) {
			ScriptGlobals = ptr.Add(3).Rip().As<int64_t**>();
		});

		constexpr auto handleNetGameEventPtrn = Pattern<"E8 ? ? ? ? F6 43 28 01 74 05 8B 7B 0C EB 03 8B 7B 14 48 8B CB E8 ? ? ? ? 2B F8 83 FF 28 0F 8D C9 FE FF FF">("HandleNetGameEvent");
		scanner.Add(handleNetGameEventPtrn, [this](PointerCalculator ptr) {
			HandleNetGameEvent = ptr.Add(1).Rip().As<PVOID>();
		});

		constexpr auto sendEventAckPtrn = Pattern<"E8 ? ? ? ? F6 43 32 01 74 4B">("SendEventAck");
		scanner.Add(sendEventAckPtrn, [this](PointerCalculator ptr) {
			SendEventAck = ptr.Add(1).Rip().As<Functions::SendEventAck>();
		});

		constexpr auto enumerateAudioDevicesPtrn = Pattern<"48 89 5C 24 08 48 89 74 24 10 48 89 7C 24 18 55 48 8B EC 48 83 EC 60 33 C0 41">("EnumerateAudioDevices");
		scanner.Add(enumerateAudioDevicesPtrn, [this](PointerCalculator ptr) {
			EnumerateAudioDevices = ptr.As<PVOID>();
		});

		constexpr auto directSoundCaptureCreatePtrn = Pattern<"E8 ? ? ? ? 85 C0 79 08 48 83 23 00 32 C0 EB 7B">("DirectSoundCaptureCreate");
		scanner.Add(directSoundCaptureCreatePtrn, [this](PointerCalculator ptr) {
			DirectSoundCaptureCreate = ptr.Add(1).Rip().As<PVOID>();
		});

		constexpr auto hwnd = Pattern<"4C 8B 05 ? ? ? ? 4C 8D 0D ? ? ? ? 48 89 54 24">("Hwnd");
		scanner.Add(hwnd, [this](PointerCalculator ptr) {
			Hwnd = *ptr.Add(3).Rip().As<HWND*>();
			LOG(INFO) << "HWND: " << Hwnd;
		});

		constexpr auto handleToPtrPtrn = Pattern<"E8 ? ? ? ? 45 8D 47 04">("HandleToPtr");
		scanner.Add(handleToPtrPtrn, [this](PointerCalculator ptr) {
			HandleToPtr = ptr.Add(1).Rip().As<Functions::HandleToPtr>();
		});

		constexpr auto ptrToHandlePtrn = Pattern<"E8 ? ? ? ? F3 0F 10 0D ? ? ? ? 48 8D 4D DF 8B 5B 40">("PtrToHandle");
		scanner.Add(ptrToHandlePtrn, [this](PointerCalculator ptr) {
			PtrToHandle = ptr.Add(1).Rip().As<Functions::PtrToHandle>();
		});

		constexpr auto getUnkPlayerThingPtrn = Pattern<"48 8B 81 10 0C 00 00 8B">("GetUnkPlayerThing");
		scanner.Add(getUnkPlayerThingPtrn, [this](PointerCalculator ptr) {
			GetUnkPlayerThing = ptr.As<Functions::PtrToHandle>();
		});

		constexpr auto getLocalPedPtrn = Pattern<"8A 05 ?? ?? ?? ?? 33 D2 84 C0 74 39 48 8B 0D ?? ?? ?? ?? 4C 8B 05 ?? ?? ?? ?? 48 C1 C9 05 48 C1 C1 20 4C 33 C1 8B C1 83 E0 1F 49 C1 C0 20 FF C0 8A C8 8A 05 ?? ?? ?? ?? 49 D3 C0 84 C0 74 06 49 8B D0 48 F7 D2 48 8B 42">("GetLocalPed");
		scanner.Add(getLocalPedPtrn, [this](PointerCalculator ptr) {
			GetLocalPed = ptr.As<Functions::GetLocalPed>();
		});

		constexpr auto applyVehicleMigrationDataNodePtrn = Pattern<"48 8B C4 48 89 48 08 53 55 56 57 41 54 41 55 41 56 41 57 48 81 EC D8">("ApplyVehicleMigrationDataNode");
		scanner.Add(applyVehicleMigrationDataNodePtrn, [this](PointerCalculator ptr) {
			ApplyVehicleMigrationDataNode = ptr.As<PVOID>();
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