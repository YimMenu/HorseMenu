#include "Self.hpp"

#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Submenus
{
	void RenderAnimationsCategory()
	{
		static std::string anim, dict;
		InputTextWithHint("Dictionary", "Enter Dictionary Name", &dict).Draw();
		InputTextWithHint("Animation", "Enter Animation Name", &anim).Draw();

		if (ImGui::Button("Play Animation"))
		{
			FiberPool::Push([=] {
				for (int i = 0; i < 250; i++)
				{
					if (dict.empty() || anim.empty())
						break;

					if (STREAMING::HAS_ANIM_DICT_LOADED(dict.c_str()))
						break;

					STREAMING::REQUEST_ANIM_DICT(dict.c_str());
					ScriptMgr::Yield();
				}

				TASK::TASK_PLAY_ANIM(YimMenu::Self::PlayerPed, dict.c_str(), anim.c_str(), 8.0f, -8.0f, -1, 0, 0, false, false, false, "", 0);
			});
		}
		ImGui::SameLine();
		if (ImGui::Button("Stop"))
		{
			FiberPool::Push([=] {
				TASK::CLEAR_PED_TASKS(YimMenu::Self::PlayerPed, true, false);
			});
		}
	}

	Self::Self() :
	    Submenu::Submenu("Self")
	{
		auto main          = std::make_shared<Category>("Main");
		auto globalsGroup  = std::make_shared<Group>("Globals", GetListBoxDimensions());
		auto movementGroup = std::make_shared<Group>("Movement", GetListBoxDimensions());
		auto toolsGroup    = std::make_shared<Group>("Tools", GetListBoxDimensions());
		auto columns       = std::make_shared<Column>(2);

		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("godmode"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("invis"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("offtheradar"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("noragdoll"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("antiafk"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("keepbarsfilled"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("keepcoresfilled"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("infiniteammo"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("infiniteclip"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("keepclean"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("antilasso"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("antihogtie"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("voicechatoverride"_J)); // TODO: move this to spoofing or network

		toolsGroup->AddItem(std::make_shared<CommandItem>("suicide"_J));
		toolsGroup->AddItem(std::make_shared<CommandItem>("clearcrimes"_J));
		toolsGroup->AddItem(std::make_shared<ImGuiItem>([] {
			if (ImGui::Button("Unfreeze"))
				FiberPool::Push([] {
					ENTITY::FREEZE_ENTITY_POSITION(YimMenu::Self::PlayerPed, false);
				});
		}));

		movementGroup->AddItem(std::make_shared<BoolCommandItem>("noclip"_J));

		columns->AddItem(globalsGroup);
		columns->AddItem(toolsGroup);
		columns->AddNextColumn();
		columns->AddItem(movementGroup);
		main->AddItem(columns);
		AddCategory(std::move(main));

		auto horse             = std::make_shared<Category>("Horse");
		auto horseColumns      = std::make_shared<Column>(2);
		auto horseGlobalsGroup = std::make_shared<Group>("Globals", GetListBoxDimensions());
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("horsegodmode"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("horsenoragdoll"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("keephorsebarsfilled"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("keephorsecoresfilled"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("keephorseagitationlow"_J));
		horseGlobalsGroup->AddItem(std::make_shared<CommandItem>("tpmounttoself"_J));
		horseColumns->AddItem(horseGlobalsGroup);
		horse->AddItem(horseColumns);
		AddCategory(std::move(horse));

		auto animations = std::make_shared<Category>("Animations");

		animations->AddItem(std::make_shared<ImGuiItem>([] {
			RenderAnimationsCategory();
		}));

		AddCategory(std::move(animations));
	}
}