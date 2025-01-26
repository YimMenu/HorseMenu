#include "Pointers.hpp"

#include "core/backend/PatternCache.hpp"
#include "core/memory/BytePatch.hpp"
#include "core/memory/ModuleMgr.hpp"
#include "core/memory/PatternScanner.hpp"
#include "core/renderer/Renderer.hpp"
#include "game/rdr/invoker/Invoker.hpp"
#include "util/GraphicsValue.hpp"
#include "util/Joaat.hpp"


namespace YimMenu
{
	bool Pointers::Init()
	{
		PatternCache::Init();

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
			GraphicsOptions_ = ptr.Add(3).Rip().As<GraphicsOptions*>();

			if (GraphicsOptions_->m_hdr)
			{
				LOG(WARNING) << "Turn HDR off if you're using DX12!";
			}

			ScreenResX = &GraphicsOptions_->m_screen_resolution_x;
			ScreenResY = &GraphicsOptions_->m_screen_resolution_y;
		});

		constexpr auto keyboardHookPtrn = Pattern<"41 8D 49 0D">("KeyboardHook");
		scanner.Add(keyboardHookPtrn, [this](PointerCalculator ptr) {
			UnhookWindowsHookEx(*ptr.Add(0x14).Rip().As<HHOOK*>()); // remove hook if it already exists
			memset(ptr.Add(4).As<PVOID>(), 0x90, 6); // prevent it from being created if we load early
			memset(ptr.Sub(0x1B).As<PVOID>(), 0x90, 6); // ...and prevent the game from destroying our console window
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

		constexpr auto scriptProgramsPtrn = Pattern<"C1 EF 0E 85 FF 74 21">("ScriptPrograms");
		scanner.Add(scriptProgramsPtrn, [this](PointerCalculator ptr) {
			ScriptPrograms = ptr.Sub(0x16).Add(3).Rip().Add(0xC8).As<rage::scrProgram**>();
		});

		constexpr auto currentScriptThreadPtrn = Pattern<"48 89 2D ? ? ? ? 48 89 2D ? ? ? ? 48 8B 04 F9">("CurrentScriptThread&ScriptVM");
		scanner.Add(currentScriptThreadPtrn, [this](PointerCalculator ptr) {
			CurrentScriptThread = ptr.Add(3).Rip().As<rage::scrThread**>();
			ScriptVM            = ptr.Add(0x28).Rip().As<Functions::ScriptVM>();
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
			Hwnd = ptr.Add(3).Rip().As<HWND*>();
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

		constexpr auto getCloneCreateResponsePtrn = Pattern<"8D 45 F8 1B F6 66 44 3B F0">("GetCloneCreateResponse");
		scanner.Add(getCloneCreateResponsePtrn, [this](PointerCalculator ptr) {
			GetCloneCreateResponse = ptr.Sub(0x5F).As<PVOID>();
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

		constexpr auto isAnimSceneInScopePtrn = Pattern<"74 78 4C 8B 03 48 8B CB">("IsAnimSceneInScope");
		scanner.Add(isAnimSceneInScopePtrn, [this](PointerCalculator ptr) {
			IsAnimSceneInScope = ptr.Sub(0x37).As<PVOID>();
		});

		constexpr auto broadcastNetArrayPtrn = Pattern<"48 89 5C 24 ? 48 89 54 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 83 EC ? 48 8B 81 ? ? ? ? 4C 8B F1">("BroadcastNetArray");
		scanner.Add(broadcastNetArrayPtrn, [this](PointerCalculator ptr) {
			BroadcastNetArray = ptr.As<PVOID>();
			NetArrayPatch     = ptr.Add(0x23B).As<std::uint8_t*>();
		});

		constexpr auto inventoryEventCtorPtrn = Pattern<"C7 41 10 55 2B 70 40">("InventoryEventConstructor");
		scanner.Add(inventoryEventCtorPtrn, [this](PointerCalculator ptr) {
			InventoryEventConstructor = ptr.Sub(0x81).As<Functions::InventoryEventConstructor>();
		});

		constexpr auto eventGroupNetworkPtrn = Pattern<"80 78 47 00 75 52 48 8B 35">("EventGroupNetwork");
		scanner.Add(eventGroupNetworkPtrn, [this](PointerCalculator ptr) {
			EventGroupNetwork = ptr.Add(0x9).Rip().As<CEventGroup**>();
		});

		constexpr auto networkRequestPtrn = Pattern<"4C 8B DC 49 89 5B 08 49 89 6B 10 49 89 73 18 57 48 81 EC ? ? ? ? 48 8B 01">("NetworkRequest");
		scanner.Add(networkRequestPtrn, [this](PointerCalculator ptr) {
			NetworkRequest = ptr.As<PVOID>();
		});

		constexpr auto handleScriptedGameEventPtrn = Pattern<"40 53 48 81 EC 10 02 00 00 48 8B D9 48 8B">("HandleScriptedGameEvent");
		scanner.Add(handleScriptedGameEventPtrn, [this](PointerCalculator ptr) {
			HandleScriptedGameEvent = ptr.As<PVOID>();
		});

		constexpr auto addObjectToCreationQueuePtrn = Pattern<"0F 83 00 01 00 00 4D 8B C8">("AddObjectToCreationQueue");
		scanner.Add(addObjectToCreationQueuePtrn, [this](PointerCalculator ptr) {
			AddObjectToCreationQueue = ptr.Sub(0x2C).As<PVOID>();
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

		constexpr auto getAnimSceneFromHandlePtrn = Pattern<"00 83 F9 04 7C 0F">("GetAnimSceneFromHandle");
		scanner.Add(getAnimSceneFromHandlePtrn, [this](PointerCalculator ptr) {
			GetAnimSceneFromHandle = ptr.Sub(0x13).Rip().As<Functions::GetAnimSceneFromHandle>();
		});

		constexpr auto networkObjectMgrPtrn = Pattern<"74 44 0F B7 56 40">("NetworkObjectMgr");
		scanner.Add(networkObjectMgrPtrn, [this](PointerCalculator ptr) {
			NetworkObjectMgr = ptr.Add(0xC).Rip().As<CNetworkObjectMgr**>();
		});

		constexpr auto sendPacketPtrn = Pattern<"8B 44 24 60 48 8B D6 48 8B CD">("SendPacket");
		scanner.Add(sendPacketPtrn, [this](PointerCalculator ptr) {
			SendPacket = ptr.Add(0xE).Add(1).Rip().As<Functions::SendPacket>();
		});

		constexpr auto queuePacketPtrn = Pattern<"E8 ?? ?? ?? ?? FF C6 49 83 C6 08 3B B7 88 40 00 00">("QueuePacket");
		scanner.Add(queuePacketPtrn, [this](PointerCalculator ptr) {
			QueuePacket = ptr.Add(1).Rip().As<Functions::QueuePacket>();
		});

		constexpr auto receiveNetMessagePtrn = Pattern<"E8 ?? ?? ?? ?? EB 24 48 8D B7 90 02 00 00">("ReceiveNetMessage");
		scanner.Add(receiveNetMessagePtrn, [this](PointerCalculator ptr) {
			ReceiveNetMessage = ptr.Add(1).Rip().As<PVOID>();
		});

		constexpr auto handlePresenceEventPtrn = Pattern<"0F 84 00 03 00 00 85 C9">("HandlePresenceEvent");
		scanner.Add(handlePresenceEventPtrn, [this](PointerCalculator ptr) {
			HandlePresenceEvent = ptr.Sub(0x34).As<PVOID>();
		});

		constexpr auto postMessagePtrn = Pattern<"E8 ?? ?? ?? ?? EB 35 C7 44 24 20 D9 7A 70 E1">("PostPresenceMessage");
		scanner.Add(postMessagePtrn, [this](PointerCalculator ptr) {
			PostPresenceMessage = ptr.Add(1).Rip().As<Functions::PostPresenceMessage>();
		});

		constexpr auto sendNetInfoToLobbyPtrn = Pattern<"E8 ?? ?? ?? ?? 32 DB 84 C0 74 1B 44 8B 84 24 40 01 00 00">("SendNetInfoToLobby");
		scanner.Add(sendNetInfoToLobbyPtrn, [this](PointerCalculator ptr) {
			SendNetInfoToLobby = ptr.Add(1).Rip().As<Functions::SendNetInfoToLobby>();
		});

		constexpr auto pedPoolPtrn = Pattern<"0F 28 F0 48 85 DB 74 56 8A 05 ? ? ? ? 84 C0 75 05">("PedPool");
		scanner.Add(pedPoolPtrn, [this](PointerCalculator ptr) {
			PedPool = ptr.Add(10).Rip().As<PoolEncryption*>();
		});

		constexpr auto objectPoolPtrn = Pattern<"3C 05 75 67">("ObjectPool");
		scanner.Add(objectPoolPtrn, [this](PointerCalculator ptr) {
			ObjectPool = ptr.Add(20).Rip().As<PoolEncryption*>();
		});

		constexpr auto vehiclePoolPtrn = Pattern<"48 83 EC 20 8A 05 ? ? ? ? 45 33 E4">("VehiclePool");
		scanner.Add(vehiclePoolPtrn, [this](PointerCalculator ptr) {
			VehiclePool = ptr.Add(6).Rip().As<PoolEncryption*>();
		});

		constexpr auto pickupPoolPtrn = Pattern<"0F 84 ? ? ? ? 8A 05 ? ? ? ? 48 85">("PickupPool");
		scanner.Add(pickupPoolPtrn, [this](PointerCalculator ptr) {
			PickupPool = ptr.Add(8).Rip().As<PoolEncryption*>();
		});

		constexpr auto scriptHandlePoolPtrn = Pattern<"8A 05 ?? ?? ?? ?? 33 FF 48 89 3D">("ScriptHandlePool");
		scanner.Add(scriptHandlePoolPtrn, [this](PointerCalculator ptr) {
			ScriptHandlePool = ptr.Add(2).Rip().As<PoolEncryption*>();
		});

		constexpr auto fwScriptGuidCreateGuidPtrn = Pattern<"E8 ? ? ? ? B3 01 8B 15">("FwScriptGuidCreateGuid");
		scanner.Add(fwScriptGuidCreateGuidPtrn, [this](PointerCalculator ptr) {
			FwScriptGuidCreateGuid = ptr.Sub(141).As<uint32_t (*)(void*)>();
		});

		constexpr auto receiveServerMessagePtrn = Pattern<"48 89 5C 24 08 57 48 83 EC 20 48 8B 02 48 8B F9 48 8B CA 48 8B DA FF 50 ?? 48 8B C8">("ReceiveServerMessage");
		scanner.Add(receiveServerMessagePtrn, [this](PointerCalculator ptr) {
			ReceiveServerMessage = ptr.As<PVOID>();
		});

		constexpr auto serializeServerRPCPtrn = Pattern<"48 89 5C 24 08 57 48 83 EC 30 48 8B 44 24 70">("SerializeServerRPC");
		scanner.Add(serializeServerRPCPtrn, [this](PointerCalculator ptr) {
			SerializeServerRPC = ptr.As<PVOID>();
		});

		constexpr auto readBBArrayPtrn = Pattern<"48 89 5C 24 08 57 48 83 EC 30 41 8B F8 4C">("ReadBitBufferArray");
		scanner.Add(readBBArrayPtrn, [this](PointerCalculator ptr) {
			ReadBitBufferArray = ptr.As<Functions::ReadBitBufferArray>();
		});

		constexpr auto writeBBArrayPtrn = Pattern<"48 89 5C 24 08 57 48 83 EC 30 F6 41 28">("WriteBitBufferArray");
		scanner.Add(writeBBArrayPtrn, [this](PointerCalculator ptr) {
			WriteBitBufferArray = ptr.As<Functions::WriteBitBufferArray>();
		});

		constexpr auto readBBStringPtrn = Pattern<"48 89 5C 24 08 48 89 6C 24 18 56 57 41 56 48 83 EC 20 45 8B">("ReadBitBufferString");
		scanner.Add(readBBStringPtrn, [this](PointerCalculator ptr) {
			ReadBitBufferString = ptr.As<Functions::ReadBitBufferString>();
		});

		constexpr auto initNativeTablesPtrn = Pattern<"41 B0 01 44 39 51 2C 0F">("InitNativeTables");
		scanner.Add(initNativeTablesPtrn, [this](PointerCalculator ptr) {
			InitNativeTables = ptr.Sub(0x10).As<PVOID>();
		});

		constexpr auto triggerWeaponDamageEventPtrn = Pattern<"89 44 24 58 8B 47 F8 89">("TriggerWeaponDamageEvent");
		scanner.Add(triggerWeaponDamageEventPtrn, [this](PointerCalculator ptr) {
			TriggerWeaponDamageEvent = ptr.Add(0x39).Rip().As<Functions::TriggerWeaponDamageEvent>();
		});

		constexpr auto scSessionPtrn = Pattern<"3B 1D ? ? ? ? 76 60">("ScSession");
		scanner.Add(scSessionPtrn, [this](PointerCalculator ptr) {
			ScSession = ptr.Add(0xB).Rip().As<CNetworkScSession**>();
		});

		constexpr auto receiveArrayUpdatePtrn = Pattern<"48 89 5C 24 10 55 56 57 41 54 41 55 41 56 41 57 48 8B EC 48 83 EC 50 48 8B D9 45">("ReceiveArrayUpdate");
		scanner.Add(receiveArrayUpdatePtrn, [this](PointerCalculator ptr) {
			ReceiveArrayUpdate = ptr.As<PVOID>();
		});

		constexpr auto writeVPMDataPtrn = Pattern<"48 8B C4 48 89 58 10 48 89 68 18 48 89 70 20 48 89 48 08 57 41 54 41 55 41 56 41 57 48 83 EC 30 4C 8B A9">("WriteVehicleProximityMigrationData");
		scanner.Add(writeVPMDataPtrn, [this](PointerCalculator ptr) {
			WriteVPMData = ptr.As<PVOID>();
		});

		constexpr auto triggerGiveControlEventPtrn = Pattern<"48 8B C4 48 89 58 ? 48 89 68 ? 48 89 70 ? 48 89 78 ? 41 54 41 56 41 57 48 83 EC ? 65 4C 8B 0C 25">("TriggerGiveControlEvent");
		scanner.Add(triggerGiveControlEventPtrn, [this](PointerCalculator ptr) {
			TriggerGiveControlEvent = ptr.As<Functions::TriggerGiveControlEvent>();
		});

		constexpr auto createPoolItemPtrn = Pattern<"BA EF 4F 91 02">("CreatePoolItem");
		scanner.Add(createPoolItemPtrn, [this](PointerCalculator ptr) {
			CreatePoolItem = ptr.Sub(0x19).As<PVOID>();
		});

		constexpr auto handleCloneRemovePtrn = Pattern<"48 8B C4 48 89 58 ? 48 89 68 ? 48 89 70 ? 48 89 78 ? 41 54 41 56 41 57 48 81 EC ? ? ? ? 4D 8B E0 4C 8B FA">("HandleCloneRemove");
		scanner.Add(handleCloneRemovePtrn, [this](PointerCalculator ptr) {
			HandleCloneRemove = ptr.As<PVOID>();
		});

		constexpr auto handleSessionEventPtrn = Pattern<"83 F9 16 0F 8F 0B">("HandleSessionEvent");
		scanner.Add(handleSessionEventPtrn, [this](PointerCalculator ptr) {
			HandleSessionEvent = ptr.Sub(0x29).As<PVOID>();
		});

		constexpr auto requestSessionSeamlessPtrn = Pattern<"83 64 24 20 00 41 B8 40 00 00 00">("RequestSessionSeamless");
		scanner.Add(requestSessionSeamlessPtrn, [this](PointerCalculator ptr) {
			RequestSessionSeamless = ptr.Add(0x12).Rip().As<Functions::RequestSessionSeamless>();
		});

		constexpr auto getDiscriminatorPtrn = Pattern<"83 E3 01 C1 E3 0A E8">("GetDiscriminator");
		scanner.Add(getDiscriminatorPtrn, [this](PointerCalculator ptr) {
			GetDiscriminator = ptr.Sub(0x20).As<PVOID>();
		});

		constexpr auto objectIdMapPtrn = Pattern<"83 C0 13 3D 00 20 00 00">("ObjectIdMap");
		scanner.Add(objectIdMapPtrn, [this](PointerCalculator ptr) {
			ObjectIdMap = ptr.Add(0x24).Rip().As<std::uint16_t**>();
		});

		constexpr auto writeNodeDataPtrn = Pattern<"48 8B 89 18 01 00 00 4C 8B 11 49 FF 62 10">("WriteNodeData");
		scanner.Add(writeNodeDataPtrn, [this](PointerCalculator ptr) {
			WriteNodeData = ptr.As<PVOID>();
		});

		constexpr auto totalProgramCountPtrn = Pattern<"44 3B CF 75 E9 41 8B DB">("TotalProgramCount");
		scanner.Add(totalProgramCountPtrn, [this](PointerCalculator ptr) {
			TotalProgramCount = ptr.Add(0xB).Rip().As<int*>() + 1;
		});

		constexpr auto sendVoicePacketPtrn = Pattern<"4C 8D 8C 24 B0 00 00 00 45 8B C4">("SendVoicePacket");
		scanner.Add(sendVoicePacketPtrn, [this](PointerCalculator ptr) {
			SendVoicePacket           = ptr.Add(0x15).As<PVOID>();
			GetPeerAddressByMessageId = ptr.Sub(0x18).Rip().As<Functions::GetPeerAddressByMessageId>();
		});

		constexpr auto writeVoiceInfoDataPtrn = Pattern<"8B 57 04 41 B8 07 00 00 00">("WriteVoiceInfoData");
		scanner.Add(writeVoiceInfoDataPtrn, [this](PointerCalculator ptr) {
			WriteVoiceInfoData = ptr.Sub(0x25).As<PVOID>();
		});

		constexpr auto friendRegistryPtrn = Pattern<"4C 8D 05 ? ? ? ? 48 8B CB E8 ? ? ? ? 84 C0 75 07 B8 4F 3D E1 01">("FriendRegistry");
		scanner.Add(friendRegistryPtrn, [this](PointerCalculator ptr) {
			FriendRegistry = ptr.Add(3).Rip().As<CFriend**>();
		});

		constexpr auto packCloneCreatePtrn = Pattern<"FF 90 90 01 00 00 33 DB">("PackCloneCreate");
		scanner.Add(packCloneCreatePtrn, [this](PointerCalculator ptr) {
			PackCloneCreate = ptr.Sub(0x34).As<PVOID>();
		});

		constexpr auto writeSyncTreePtrn = Pattern<"0F 84 A4 00 00 00 48 8B 07 45 8B C4">("WriteSyncTree");
		scanner.Add(writeSyncTreePtrn, [this](PointerCalculator ptr) {
			WriteSyncTree = ptr.Sub(0x79).As<PVOID>();
		});

		constexpr auto shouldUseNodeCachePtrn = Pattern<"83 FA 20 75 03">("ShouldUseNodeCache");
		scanner.Add(shouldUseNodeCachePtrn, [this](PointerCalculator ptr) {
			ShouldUseNodeCache = ptr.As<PVOID>();
		});

		constexpr auto isNodeInScopePtrn = Pattern<"41 83 F9 02 74 25">("IsNodeInScope");
		scanner.Add(isNodeInScopePtrn, [this](PointerCalculator ptr) {
			IsNodeInScope = ptr.Sub(0x1F).As<PVOID>();
		});

		constexpr auto setTreeErroredPtrn = Pattern<"80 BB 9C 01 00 00 00 74 0B">("SetTreeErrored");
		scanner.Add(setTreeErroredPtrn, [this](PointerCalculator ptr) {
			SetTreeErrored = ptr.Add(0x10).Rip().As<PVOID>();
		});

		constexpr auto setTreeTargetObjectPtrn = Pattern<"48 89 7C CE 08 48 8B 74 24 38">("SetTreeTargetObject");
		scanner.Add(setTreeTargetObjectPtrn, [this](PointerCalculator ptr) {
			SetTreeTargetObject = ptr.Sub(0x5D).As<PVOID>();
		});

		constexpr auto physicsHandleLassoAttachmentPtrn = Pattern<"EB 3B 40 84 ED 74 36">("PhysicsHandleLassoAttachment");
		scanner.Add(physicsHandleLassoAttachmentPtrn, [this](PointerCalculator ptr) {
			PhysicsHandleLassoAttachment = ptr.Sub(4).Rip().As<PVOID>();
		});

		constexpr auto decideConnectionMethodPtrn = Pattern<"81 7D 30 98 3A 00 00 76 06">("DecideConnectionMethod");
		scanner.Add(decideConnectionMethodPtrn, [this](PointerCalculator ptr) {
			DecideConnectionMethod = ptr.Sub(0x90).As<PVOID>();
			DecideConnectionMethodJmp = ptr.Sub(0x6).As<char*>();
			DecideConnectionMethodDefVal = ptr.Add(0x83).As<char*>();
		});

		constexpr auto handlePeerRelayPacketPtrn = Pattern<"48 8B C4 48 89 58 ? 48 89 68 ? 48 89 70 ? 57 48 83 EC ? F6 81 ? ? ? ? ? 41 8B F9">("HandlePeerRelayPacket");
		scanner.Add(handlePeerRelayPacketPtrn, [this](PointerCalculator ptr) {
			HandlePeerRelayPacket = ptr.As<PVOID>();
		});

		constexpr auto unpackPacketPtrn = Pattern<"48 89 5C 24 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 ? ? ? ? 48 81 EC ? ? ? ? 41 8D 41">("UnpackPacket");
		scanner.Add(unpackPacketPtrn, [this](PointerCalculator ptr) {
			UnpackPacket = ptr.As<PVOID>();
		});
		
		constexpr auto updateEndpointAddressPtrn = Pattern<"48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 55 41 56 41 57 48 8B EC 48 81 EC ? ? ? ? 4C 8D B9">("UpdateEndpointAddress");
		scanner.Add(updateEndpointAddressPtrn, [this](PointerCalculator ptr) {
			UpdateEndpointAddress = ptr.As<PVOID>();
		});

		constexpr auto trainConfigsPtrn = Pattern<"41 39 09 74 11">("TrainConfigs");
		scanner.Add(trainConfigsPtrn, [this](PointerCalculator ptr) {
			TrainConfigs = ptr.Sub(0xA).Rip().As<CTrainConfigs*>();
		});

		constexpr auto serializeIceSessionOfferRequestPtrn = Pattern<"80 3F 03 0F 85 9C 01 00 00">("SerializeIceSessionOfferRequest");
		scanner.Add(serializeIceSessionOfferRequestPtrn, [this](PointerCalculator ptr) {
			SerializeIceSessionOfferRequest = ptr.Sub(0x2F).As<PVOID>();
		});

		constexpr auto openIceTunnelPtrn = Pattern<"66 44 39 6D 58 0F 84 1D 01 00 00">("OpenIceTunnel");
		scanner.Add(openIceTunnelPtrn, [this](PointerCalculator ptr) {
			OpenIceTunnel = ptr.Sub(0x5F).As<Functions::OpenIceTunnel>();
		});

		constexpr auto canCreateNetworkObjectPtrn = Pattern<"B8 81 00 20 00 85 FF">("CanCreateNetworkObject");
		scanner.Add(canCreateNetworkObjectPtrn, [this](PointerCalculator ptr) {
			CanCreateNetworkObject = ptr.Sub(0x26).As<PVOID>();
			MaxNetworkPeds = ptr.Add(0x60).As<int*>();
		});

		constexpr auto getTextLabelPtrn = Pattern<"BB 1A 00 00 00 48 8D 0D">("GetTextLabel");
		scanner.Add(getTextLabelPtrn, [this](PointerCalculator ptr) {
			GetTextLabel = ptr.Add(0x12).Rip().As<PVOID>();
		});

		// fixes crash at CNetObjPed::SetPedWeaponComponentData
		constexpr auto weaponComponentPatchPtrn = Pattern<"0F 85 9E 00 00 00 45 39 19">("WeaponComponentPatch");
		scanner.Add(weaponComponentPatchPtrn, [this](PointerCalculator ptr) {
			// TODO: disable on unload
			*ptr.Add(9).As<uint16_t*>() = 0x377C;
			*ptr.Add(0x15).As<uint16_t*>() = 0x2B7D;
		});

		constexpr auto getPoolSizePtrn = Pattern<"BA F7 01 22 5F">("GetPoolSize");
		scanner.Add(getPoolSizePtrn, [this](PointerCalculator ptr) {
			GetPoolSize = ptr.Add(0xC).Rip().As<PVOID>();
		});

		constexpr auto checkConditionIsMalePtrn = Pattern<"C0 E8 03 24 01 EB 26">("CheckConditionIsMale");
		scanner.Add(checkConditionIsMalePtrn, [this](PointerCalculator ptr) {
			CheckConditionIsMale = ptr.Sub(0x5B).As<PVOID>();
		});

		constexpr auto checkConditionIsFemalePtrn = Pattern<"74 27 48 8B 82 00 01 00 00 48 85 C0 74 10">("CheckConditionIsFemale");
		scanner.Add(checkConditionIsFemalePtrn, [this](PointerCalculator ptr) {
			CheckConditionIsFemale = ptr.Sub(0xF).As<PVOID>();
		});

		constexpr auto scriptUiDrawFlagsPtrn = Pattern<"41 8D 51 0E EB 05 BA">("ScriptUIDrawFlags");
		scanner.Add(scriptUiDrawFlagsPtrn, [this](PointerCalculator ptr) {
			ScriptUIDrawFlags = ptr.Add(0x16).Rip().As<int*>();
		});

		constexpr auto registerCompappNativesPtrn = Pattern<"A1 26 01 0C">("RegisterCompappNatives");
		scanner.Add(registerCompappNativesPtrn, [this](PointerCalculator ptr) {
			RegisterCompappNatives = ptr.Sub(0x27).As<int*>();
		});

		if (!scanner.Scan())
		{
			LOG(FATAL) << "Some game patterns could not be found, unloading.";

			return false;
		}
		else
		{
			LOG(INFO) << "Initial pointer scan complete";
		}

		if (GetNativeHandler(0xCCB4635A071FB62DuLL)) // the last native registered
			NativeInvoker::CacheHandlers();

		return true;
	}

	bool Pointers::LateInit() 
	{
		PatternCache::Update(); // update late to store all patterns

		return true;
	}

	void Pointers::Restore()
	{
	}
}
