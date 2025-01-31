#include "Debug.hpp"

#include "Debug/Globals.hpp"
#include "Debug/Locals.hpp"
#include "Debug/Scripts.hpp"
#include "core/commands/BoolCommand.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/NativeHooks.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Object.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	BoolCommand _LogScriptLaunches("logscriptlaunches", "Log Script Launches", "Log script launches");
}

namespace YimMenu::Submenus
{
	Debug::Debug() :
	    Submenu::Submenu("Debug")
	{
		AddCategory(BuildGlobalsMenu());
		AddCategory(BuildLocalsMenu());
		AddCategory(BuildScriptsMenu());

		auto debug = std::make_shared<Category>("Logging/Misc");

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

		debug->AddItem(std::make_shared<BoolCommandItem>("betterentitycheck"_J));
		debug->AddItem(std::make_shared<CommandItem>("chathelper"_J));
		debug->AddItem(std::make_shared<CommandItem>("clearchat"_J));
		debug->AddItem(std::make_shared<ImGuiItem>([] {
			if (ImGui::Button("Bail to Loading Screen"))
			{
				FiberPool::Push([] {
					SCRIPTS::BAIL_TO_LANDING_PAGE(0);
				});
			}

			static char object_model[255]{};
			ImGui::InputText("Object Model", object_model, sizeof(object_model));
			if (ImGui::Button("Create"))
			{
				FiberPool::Push([] {
					Object::Create(Joaat(object_model), Self::GetPed().GetPosition());
				});
			}
			static char music_event[255]{};
			ImGui::InputText("Music", music_event, sizeof(music_event));
			if (ImGui::Button("Play"))
			{
				FiberPool::Push([] {
					AUDIO::PREPARE_MUSIC_EVENT(music_event);
					AUDIO::TRIGGER_MUSIC_EVENT(music_event);
				});
			}
			ImGui::SameLine();
			if (ImGui::Button("Stop"))
			{
				FiberPool::Push([] {
					AUDIO::TRIGGER_MUSIC_EVENT("MC_MUSIC_STOP");
				});
			}
			static int mflag = 0;
			ImGui::InputInt("MotivationState", &mflag);
			if (ImGui::Button("Override"))
			{
				FiberPool::Push([] {
					Self::GetPed().SetMotivation(static_cast<MotivationState>(mflag), 99999.0f);
					PED::_SET_PED_MOTIVATION_STATE_OVERRIDE(Self::GetPed().GetHandle(), mflag, true);
				});
			}
			ImGui::SameLine();
			if (ImGui::Button("Stop"))
			{
				FiberPool::Push([] {
					Self::GetPed().SetMotivation(static_cast<MotivationState>(mflag), 0.0f);
					PED::_SET_PED_MOTIVATION_STATE_OVERRIDE(Self::GetPed().GetHandle(), mflag, false);
				});
			}
		}));
		AddCategory(std::move(debug));
	}
}