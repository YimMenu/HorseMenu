#include "common.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/Hooking.hpp"
#include "core/memory/ModuleMgr.hpp"
#include "core/player_database/PlayerDatabase.hpp"
#include "core/renderer/Renderer.hpp"
#include "core/settings/Settings.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/NativeHooks.hpp"
#include "game/bigfeatures/CustomTeleport.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/GUI.hpp"
#include "game/pointers/Pointers.hpp"


namespace YimMenu
{
	DWORD Main(void*)
	{
		const auto documents = std::filesystem::path(std::getenv("appdata")) / "HorseMenu";
		FileMgr::Init(documents);

		LogHelper::Init("HorseMenu", FileMgr::GetProjectFile("./cout.log"));

		g_HotkeySystem.RegisterCommands();
		CustomTeleport::FetchSavedLocations();
		Settings::Initialize(FileMgr::GetProjectFile("./settings.json"));

		auto PlayerDatabaseInstance = std::make_unique<PlayerDatabase>();

		if (!ModuleMgr.LoadModules())
			goto unload;
		if (!Pointers.Init())
			goto unload;
		if (!Renderer::Init())
			goto unload;

		Hooking::Init();

		ScriptMgr::Init();
		LOG(INFO) << "ScriptMgr Initialized";

		FiberPool::Init(5);
		LOG(INFO) << "FiberPool Initialized";

		GUI::Init();

		ScriptMgr::AddScript(std::make_unique<Script>(&FeatureLoop));
		ScriptMgr::AddScript(std::make_unique<Script>(&BlockControlsForUI));
		ScriptMgr::AddScript(std::make_unique<Script>(&ContextMenuTick));

		Notifications::Show("HorseMenu", "Loaded succesfully", NotificationType::Success);

		while (g_Running)
		{
			// Needed incase UI is malfunctioning or for emergencies
			if (GetAsyncKeyState(VK_DELETE) & 0x8000 && !*Pointers.IsSessionStarted)
			{
				g_Running = false;
			}

			std::this_thread::sleep_for(3000ms);
			Settings::Save(); // TODO: move this somewhere else
		}

		LOG(INFO) << "Unloading";

		NativeHooks::Destroy();
		LOG(INFO) << "NativeHooks Uninitialized";

		ScriptMgr::Destroy();
		LOG(INFO) << "ScriptMgr Uninitialized";

		FiberPool::Destroy();
		LOG(INFO) << "FiberPool Uninitialized";

		PlayerDatabaseInstance.reset();

	unload:
		Hooking::Destroy();
		Renderer::Destroy();
		Pointers.Restore();

		LogHelper::Destroy();

		CloseHandle(g_MainThread);
		FreeLibraryAndExitThread(g_DllInstance, EXIT_SUCCESS);

		return EXIT_SUCCESS;
	}
}

BOOL WINAPI DllMain(HINSTANCE dllInstance, DWORD reason, void*)
{
	using namespace YimMenu;

	DisableThreadLibraryCalls(dllInstance);

	if (reason == DLL_PROCESS_ATTACH)
	{
		g_DllInstance = dllInstance;

		g_MainThread = CreateThread(nullptr, 0, Main, nullptr, 0, &g_MainThreadId);
	}
	return true;
}