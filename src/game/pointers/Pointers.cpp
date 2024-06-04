#include "Pointers.hpp"

#include "core/memory/BytePatch.hpp"
#include "core/memory/ModuleMgr.hpp"
#include "core/memory/PatternScanner.hpp"
#include "core/renderer/Renderer.hpp"
#include "util/GraphicsValue.hpp"
#include "util/Joaat.hpp"


namespace YimMenu
{
	void patch_byte(PVOID address, const unsigned char* bytes, int numBytes) //TODO: make service
	{
		DWORD oldProtect;
		VirtualProtect(address, numBytes, PAGE_EXECUTE_READWRITE, &oldProtect);
		memcpy(address, bytes, numBytes);
		VirtualProtect(address, numBytes, oldProtect, &oldProtect);
	}

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

		constexpr auto gfxInformationPtrn = Pattern<"48 8D 0D ? ? ? ? 48 8B F8 E8 ? ? ? ? 45 33 ED 45 84 FF">("GFXInformation");
		scanner.Add(gfxInformationPtrn, [this](PointerCalculator ptr) {
			auto gfx = ptr.Add(3).Rip().As<GraphicsOptions*>();

			if (gfx->m_hdr)
			{
				LOG(WARNING) << "Turn HDR off if your using DX12!";
			}

			if (gfx->m_motion_blur)
			{
				LOG(INFO) << "Ew motion blur. Seriously?";
			}

			//LOG(INFO) << GetGraphicsValue(gfx->m_gfx_lightingQuality); example

			if (gfx->m_unk)
			{
				ScreenResX = gfx->m_screen_resolution_x;
				ScreenResY = gfx->m_screen_resolution_y;
				LOG(INFO) << "Screen Resolution: " << ScreenResX << "x" << ScreenResY;
			}
		});

		constexpr auto wndProcPtrn = Pattern<"48 89 5C 24 ? 4C 89 4C 24 ? 48 89 4C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 60">("WndProc");
		scanner.Add(wndProcPtrn, [this](PointerCalculator ptr) {
			WndProc = ptr.As<PVOID>();
		});

		constexpr auto isSessionStartedPtrn = Pattern<"40 38 35 ? ? ? ? 74 4D">("IsSessionStarted");
		scanner.Add(isSessionStartedPtrn, [this](PointerCalculator ptr) {
			IsSessionStarted = ptr.Add(3).Rip().As<bool*>();
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

		constexpr auto vmDetectionCallbackPtrn = Pattern<"48 8B 0D ? ? ? ? E8 ? ? ? ? 48 8B 0D ? ? ? ? 8D 7E">("VMDetectionCallback");
		scanner.Add(vmDetectionCallbackPtrn, [this](PointerCalculator ptr) {
			auto loc                = ptr.Add(3).Rip().As<uint8_t*>();
			VmDetectionCallback     = (PVOID*)loc;
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

		constexpr auto getLocalPedPtrn = Pattern<"8A 05 ? ? ? ? 33 D2 84 C0 74 39 48 8B 0D ? ? ? ? 4C 8B 05 ? ? ? ? 48 C1 C9 05 48 C1 C1 20 4C 33 C1 8B C1 83 E0 1F 49 C1 C0 20 FF C0 8A C8 8A 05 ? ? ? ? 49 D3 C0 84 C0 74 06 49 8B D0 48 F7 D2 48 8B 42">("GetLocalPed");
		scanner.Add(getLocalPedPtrn, [this](PointerCalculator ptr) {
			GetLocalPed = ptr.As<Functions::GetLocalPed>();
		});

		constexpr auto handleCloneCreatePtrn = Pattern<"48 8B C4 48 89 58 08 48 89 68 10 48 89 70 20 66 44 89 40 18 57 41 54 41 55 41 56 41 57 48 83">("HandleCloneCreate");
		scanner.Add(handleCloneCreatePtrn, [this](PointerCalculator ptr) {
			HandleCloneCreate = ptr.As<PVOID>();
		});

		constexpr auto handleCloneSyncPtrn = Pattern<"48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 56 41 57 48 83 EC 40 4C 8B F2">("HandleCloneSync");
		scanner.Add(handleCloneSyncPtrn, [this](PointerCalculator ptr) {
			HandleCloneSync = ptr.As<PVOID>();
		});

		constexpr auto canApplyDataPtrn = Pattern<"48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 4C 89 70 20 41 57 48 83 EC 30 4C 8B FA">("CanApplyData");
		scanner.Add(canApplyDataPtrn, [this](PointerCalculator ptr) {
			CanApplyData = ptr.As<PVOID>();
		});

		constexpr auto getSyncTreeForTypePtrn = Pattern<"0F B7 CA 83 F9">("GetSyncTreeForType");
		scanner.Add(getSyncTreeForTypePtrn, [this](PointerCalculator ptr) {
			GetSyncTreeForType = ptr.As<Functions::GetSyncTreeForType>();
		});

		constexpr auto resetSyncNodesPtrn = Pattern<"E8 ? ? ? ? E8 ? ? ? ? B9 0E 00 00 00 E8 ? ? ? ? 48 8B CB E8 ? ? ? ? E8 ? ? ? ? B9 0F 00 00 00 E8 ? ? ? ? E8">("ResetSyncNodes");
		scanner.Add(resetSyncNodesPtrn, [this](PointerCalculator ptr) {
			ResetSyncNodes = ptr.Add(1).Rip().As<PVOID>();
		});

		constexpr auto throwFatalErrorPtrn = Pattern<"48 83 EC 28 45 33 C9 E8 ? ? ? ? CC">("ThrowFatalError");
		scanner.Add(throwFatalErrorPtrn, [this](PointerCalculator ptr) {
			ThrowFatalError = ptr.As<PVOID>();
		});

		constexpr auto networkRequestPtrn = Pattern<"4C 8B DC 49 89 5B 08 49 89 6B 10 49 89 73 18 57 48 81 EC ? ? ? ? 48 8B 01">("NetworkRequest");
		scanner.Add(networkRequestPtrn, [this](PointerCalculator ptr) {
			NetworkRequest = ptr.As<PVOID>();
		});

		constexpr auto handleScriptedGameEventPtrn = Pattern<"40 53 48 81 EC 10 02 00 00 48 8B D9 48 8B">("HandleScriptedGameEvent");
		scanner.Add(handleScriptedGameEventPtrn, [this](PointerCalculator ptr) {
			HandleScriptedGameEvent = ptr.As<PVOID>();
		});

		constexpr auto addObjectToCreationQueuePtrn = Pattern<"48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 55 41 54 41 55 41 56 41 57 48 8D 68 98 48 81 EC 50">("AddObjectToCreationQueue");
		scanner.Add(addObjectToCreationQueuePtrn, [this](PointerCalculator ptr) {
			AddObjectToCreationQueue = ptr.As<PVOID>();
		});

		constexpr auto playerHasJoinedPtrn = Pattern<"E8 ? ? ? ? 8A 4B 19 48 8B 45 38">("PlayerHasJoined");
		scanner.Add(playerHasJoinedPtrn, [this](PointerCalculator ptr) {
			PlayerHasJoined = ptr.Add(1).Rip().As<PVOID>();
		});

		constexpr auto playerHasLeftPtrn = Pattern<"E8 ? ? ? ? 48 8B 0D ? ? ? ? 48 8B 57 08">("PlayerHasLeft");
		scanner.Add(playerHasLeftPtrn, [this](PointerCalculator ptr) {
			PlayerHasLeft = ptr.Add(1).Rip().As<PVOID>();
		});

		constexpr auto networkPlayerMgrPtrn = Pattern<"48 89 5C 24 08 57 48 83 EC 30 48 8B ? ? ? ? 01 8A D9 80 F9 20">("NetworkPlayerMgr");
		scanner.Add(networkPlayerMgrPtrn, [this](PointerCalculator ptr) {
			NetworkPlayerMgr = *ptr.Add(0xD).Rip().As<CNetworkPlayerMgr**>();
		});

		constexpr auto getNetworkPlayerFromPidPtrn = Pattern<"E8 ? ? ? ? B2 01 8B CB 48 8B F8">("GetNetworkPlayerFromPid");
		scanner.Add(getNetworkPlayerFromPidPtrn, [this](PointerCalculator ptr) {
			GetNetPlayerFromPid = ptr.Add(1).Rip().As<Functions::GetNetworkPlayerFromPid>();
		});

		constexpr auto getNetObjectByIdPtrn = Pattern<"E8 ? ? ? ? 48 85 C0 74 20 80 78 47 00">("GetNetObjectById");
		scanner.Add(getNetObjectByIdPtrn, [this](PointerCalculator ptr) {
			GetNetObjectById = ptr.Add(1).Rip().As<Functions::GetNetObjectById>();
		});

		constexpr auto addExplosionBypass = Pattern<"0F 84 ? ? ? ? 44 38 3D ? ? ? ? 75 14">("ExplosionBypass");
		scanner.Add(addExplosionBypass, [this](PointerCalculator ptr) {
			ExplosionBypass = ptr.Add(9).Rip().As<bool*>();
		});

		constexpr auto worldToScreenPtrn = Pattern<"E8 ? ? ? ? 84 C0 74 19 F3 0F 10 44 24">("WorldToScreen");
		scanner.Add(worldToScreenPtrn, [this](PointerCalculator ptr) {
			WorldToScreen = ptr.Add(1).Rip().As<Functions::WorldToScreen>();
		});

		constexpr auto writePlayerHealthDataPtrn = Pattern<"48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 30 48 8B B1 A8">("WritePlayerHealthData");
		scanner.Add(writePlayerHealthDataPtrn, [this](PointerCalculator ptr) {
			WritePlayerHealthData = ptr.As<PVOID>();
		});

		constexpr auto requestControlPtrn = Pattern<"E8 ? ? ? ? 32 C0 48 83 C4 ? 5B C3 B0 ? EB ? 48 8D 0D">("RequestControl");
		scanner.Add(requestControlPtrn, [this](PointerCalculator ptr) {
			RequestControlOfNetObject = ptr.Add(1).Rip().As<Functions::RequestControlOfNetObject>();
		});

		constexpr auto networkObjectMgrPtrn = Pattern<"48 8B 0D ?? ?? ?? ?? E9 ?? ?? ?? ?? 90 E9 ?? ?? ?? ?? EC">("NetworkObjectMgr");
		scanner.Add(networkObjectMgrPtrn, [this](PointerCalculator ptr) {
			NetworkObjectMgr = *ptr.Add(3).Rip().As<void**>();
		});

		constexpr auto handleJoinRequestPtrn = Pattern<"40 53 48 83 EC 20 48 8D 41 08">("HandleJoinRequest");
		scanner.Add(handleJoinRequestPtrn, [this](PointerCalculator ptr) {
			HandleJoinRequest = ptr.As<Functions::HandleJoinRequest>();
		});

		constexpr auto writeJoinResponseDataPtrn = Pattern<"48 8D 4C 24 30 E8 ?? ?? ?? ?? 84 C0 74 04 B0 01 EB 02 32 C0 48 83 C4 20">("WriteJoinResponseData");
		scanner.Add(writeJoinResponseDataPtrn, [this](PointerCalculator ptr) {
			WriteJoinResponseData = ptr.Add(1).Rip().As<Functions::WriteJoinResponseData>();
		});

		constexpr auto sendPacketPtrn = Pattern<"8B 44 24 60 48 8B D6 48 8B CD">("SendPacket");
		scanner.Add(sendPacketPtrn, [this](PointerCalculator ptr) {
			SendPacket = ptr.Add(10).Rip().As<Functions::SendPacket>();
		});

		constexpr auto writePlayerCameraDataNode = Pattern<"40 55 53 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 78 4C 8B A9">("WritePlayerCameraDataNode");
		scanner.Add(writePlayerCameraDataNode, [this](PointerCalculator ptr) {
			WritePlayerCameraDataNode = ptr.As<PVOID>();
		});

		constexpr auto writePlayerAppearanceNode = Pattern<"40 55 53 56 57 41 55 41 56 41 57 48 8B EC 48 83 EC 50 4C 8B B9">("WritePlayerAppearanceDataNode");
		scanner.Add(writePlayerAppearanceNode, [this](PointerCalculator ptr) {
			WritePlayerAppearanceDataNode = ptr.As<PVOID>();
		});

		constexpr auto writePlayerGameStateDataNode = Pattern<"48 8B C4 48 89 58 ? 48 89 68 ? 48 89 70 ? 48 89 78 ? 41 54 41 56 41 57 48 83 EC ? 48 8B A9 ? ? ? ? 48 8B F1">("WritePlayerGameStateDataNode");
		scanner.Add(writePlayerGameStateDataNode, [this](PointerCalculator ptr) {
			WritePlayerGameStateDataNode = ptr.As<PVOID>();
		});

		constexpr auto getGamerOnlineState = Pattern<"E8 ?? ?? ?? ?? 84 C0 75 11 BF EE 03 00 00">("GetGamerOnlineState");
		scanner.Add(getGamerOnlineState, [this](PointerCalculator ptr) {
			GetGamerOnlineState = ptr.As<Functions::GetGamerOnlineState>();
		});

		constexpr auto startGetSessionByGamerHandle = Pattern<"48 89 5C 24 20 8B C8 E8">("StartGetSessionByGamerHandle");
		scanner.Add(startGetSessionByGamerHandle, [this](PointerCalculator ptr) {
			StartGetSessionByGamerHandle = ptr.Add(3).Rip().As<Functions::StartGetSessionByGamerHandle>();
		});

		constexpr auto queuePacketPtrn = Pattern<"48 89 5C 24 08 48 89 6C 24 10 48 89 74 24 18 57 41 54 41 55 41 56 41 57 48 83 EC 30 4C 8B F1 4D">("QueuePacket");
		scanner.Add(queuePacketPtrn, [this](PointerCalculator ptr) {
			QueuePacket = ptr.As<Functions::QueuePacket>();
		});

		constexpr auto recieveNetMessagePtrn = Pattern<"48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 54 41 56 41 57 48 83 EC 20 4C 8B 71 38">("RecieveNetMessage");
		scanner.Add(recieveNetMessagePtrn, [this](PointerCalculator ptr) {
			ReceiveNetMessage = ptr.As<PVOID>();
		});

		constexpr auto handlePresenceEventPtrn = Pattern<"48 8B C4 48 89 58 08 48 89 70 10 48 89 78 18 4C 89 70 20 55 48 8D 68 A9 48 81 EC B0 00 00 00 4C">("HandlePresenceEvent");
		scanner.Add(handlePresenceEventPtrn, [this](PointerCalculator ptr) {
			HandlePresenceEvent = ptr.As<PVOID>();
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

	void Pointers::Restore()
	{
	}
}
