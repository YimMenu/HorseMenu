#include "common.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "core/hooking/Hooking.hpp"
#include "core/memory/ModuleMgr.hpp"
#include "core/renderer/Renderer.hpp"
#include "game/frontend/GUI.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/features/Features.hpp"

namespace YimMenu
{
	DWORD Main(void*)
	{
		const auto documents = std::filesystem::path(std::getenv("USERPROFILE")) / "Documents";
		FileMgr::Init(documents / "HellBase");

		// TODO: change console name
		LogHelper::Init("henlo", FileMgr::GetProjectFile("./cout.log"));

		if (!ModuleMgr.LoadModules())
			goto unload;
		if (!Pointers.Init())
			goto unload;
		if (!Renderer::Init())
			goto unload;

		ScriptMgr::Init();
		LOG(INFO) << "ScriptMgr Initialized";

		FiberPool::Init(5);
		LOG(INFO) << "FiberPool Initialized";

		GUI::Init();
		Hooking::Init();

		ScriptMgr::AddScript(std::make_unique<Script>(&FeatureLoop));

		while (g_Running)
		{
			std::this_thread::sleep_for(100ms);
		}

		LOG(INFO) << "Unloading";

		ScriptMgr::Destroy();
		LOG(INFO) << "ScriptMgr Uninitialized";

		FiberPool::Destroy();
		LOG(INFO) << "FiberPool Uninitialized";

	unload:
		Hooking::Destroy();
		Renderer::Destroy();

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