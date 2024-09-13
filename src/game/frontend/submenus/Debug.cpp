#include "Debug.hpp"

#include "Debug/Globals.hpp"
#include "Debug/Scripts.hpp"
#include "core/commands/BoolCommand.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/NativeHooks.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	BoolCommand _LogScriptLaunches("logscriptlaunches", "Log Script Launches", "Log script launches");
}

namespace YimMenu::Submenus
{
	/*void START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS(rage::scrNativeCallContext* ctx)
	{
		if (Features::_LogScriptLaunches.GetState())
		{
			Hash scriptHash = ctx->GetArg<Hash>(0);
			Any* args       = ctx->GetArg<Any*>(1);
			int argCount    = ctx->GetArg<int>(2);
			int stackSize   = ctx->GetArg<int>(3);

			std::stringstream argsStream;
			for (int i = 0; i < argCount; ++i)
			{
				argsStream << *(uint64_t*)args[i];
				if (i < argCount - 1)
				{
					argsStream << ", ";
				}
			}

			LOG(INFO) << "Script Hash: " << scriptHash << " | Args: " << argsStream.str() << " | Arg Count: " << argCount << " | Stack Size: " << stackSize;
		}

		SCRIPTS::START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS(ctx->GetArg<Hash>(0), ctx->GetArg<Any*>(1), ctx->GetArg<int>(2), ctx->GetArg<int>(3));
	}*/

	Debug::Debug() :
	    Submenu::Submenu("Debug")
	{
		auto globals = std::make_shared<Category>("Globals");

		globals->AddItem(std::make_shared<ImGuiItem>([] {
			RenderGlobalsMenu();
		}));

		AddCategory(std::move(globals));

		auto threads = std::make_shared<Category>("Threads");

		threads->AddItem(std::make_shared<ImGuiItem>([] {
			RenderScriptsMenu();
		}));

		AddCategory(std::move(threads));

		auto debug = std::make_shared<Category>("Debug");

		/*debug->AddItem(std::make_shared<ImGuiItem>([] {
			static auto scriptLauncherHook = ([]() {
				NativeHooks::AddHook("net_main_offline"_J, NativeIndex::START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS, START_NEW_SCRIPT_WITH_NAME_HASH_AND_ARGS);
				return true;
			}());
		}));*/

		debug->AddItem(std::make_shared<BoolCommandItem>("logclones"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logoutgoingclones"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logevents"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logtses"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logmetrics"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logpackets"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logforwardpackets"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logterminuspackets"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logunpackedpackets"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logendpointupdates"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logpresenceevents"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logpostmessage"_J));
		debug->AddItem(std::make_shared<BoolCommandItem>("logservermessages"_J));
		//debug->AddItem(std::make_shared<BoolCommandItem>("logscriptlaunches"_J));

		debug->AddItem(std::make_shared<CommandItem>("chathelper"_J));
		debug->AddItem(std::make_shared<CommandItem>("clearchat"_J));
		debug->AddItem(std::make_shared<ImGuiItem>([] {
			if (ImGui::Button("Bail to Loading Screen"))
			{
				FiberPool::Push([] {
					SCRIPTS::BAIL_TO_LANDING_PAGE(0);
				});
			}
		}));
		AddCategory(std::move(debug));
	}
}