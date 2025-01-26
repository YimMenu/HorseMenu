#include "common.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/Hooking.hpp"
#include "core/memory/ModuleMgr.hpp"
#include "game/backend/PlayerDatabase.hpp"
#include "core/renderer/Renderer.hpp"
#include "core/settings/Settings.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/MapEditor/MapEditor.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/NativeHooks.hpp"
#include "game/backend/SavedLocations.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/GUI.hpp"
#include "game/pointers/Pointers.hpp"


namespace YimMenu
{
	static DWORD Main(void*)
	{
		const auto documents = std::filesystem::path(std::getenv("appdata")) / "HorseMenu";
		FileMgr::Init(documents);

		LogHelper::Init("Terminus", FileMgr::GetProjectFile("./cout.log"));

		g_HotkeySystem.RegisterCommands();
		SavedLocations::FetchSavedLocations();
		Settings::Initialize(FileMgr::GetProjectFile("./settings.json"));

		auto PlayerDatabaseInstance = std::make_unique<PlayerDatabase>();

		if (!ModuleMgr.LoadModules())
			goto unload;
		if (!Pointers.Init())
			goto unload;

		Hooking::Init();

		if (!Renderer::Init())
			goto unload;

		if (!Pointers.LateInit())
			LOG(WARNING) << "Failed to find some pointers";
		Hooking::LateInit();

		ScriptMgr::Init();
		LOG(INFO) << "ScriptMgr initialized";

		FiberPool::Init(5);
		LOG(INFO) << "FiberPool initialized";

		GUI::Init();

		ScriptMgr::AddScript(std::make_unique<Script>(&FeatureLoop));
		ScriptMgr::AddScript(std::make_unique<Script>(&BlockControlsForUI));
		ScriptMgr::AddScript(std::make_unique<Script>(&ContextMenuTick));
		ScriptMgr::AddScript(std::make_unique<Script>(&MapEditor::Update));

		Notifications::Show("Terminus", "Loaded succesfully", NotificationType::Success);

#ifndef NDEBUG
		LOG(WARNING) << "Debug Build. Switch to RelWithDebInfo or Release build configurations to have a more stable experience.";
#endif

		while (g_Running)
		{
			Settings::Tick(); // TODO: move this somewhere else
		}

		LOG(INFO) << "Unloading";

		NativeHooks::Destroy();
		LOG(INFO) << "NativeHooks uninitialized";

		ScriptMgr::Destroy();
		LOG(INFO) << "ScriptMgr uninitialized";

		FiberPool::Destroy();
		LOG(INFO) << "FiberPool uninitialized";

		PlayerDatabaseInstance.reset();

	unload:
		Hooking::Destroy();
		LOG(INFO) << "Hooking uninitialized";
		Renderer::Destroy();
		LOG(INFO) << "Renderer uninitialized";

		LOG(INFO) << "Goodbye!";
		LogHelper::Destroy();

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