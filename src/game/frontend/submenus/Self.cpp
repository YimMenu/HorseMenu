#include "Self.hpp"

#include "core/commands/BoolCommand.hpp"
#include "core/commands/Commands.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "util/Rewards.hpp"

#include <map>


namespace YimMenu::Features
{
	BoolCommand _RecoveryEnabled("recoveryenabled", "Recovery Enabled", "Is the recovery feature enabled");
}

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
		auto main              = std::make_shared<Category>("Main");
		auto globalsGroup      = std::make_shared<Group>("Globals", GetListBoxDimensions());
		auto movementGroup     = std::make_shared<Group>("Movement", GetListBoxDimensions());
		auto toolsGroup        = std::make_shared<Group>("Tools", GetListBoxDimensions());
		auto collectiblesGroup = std::make_shared<Group>("Collectibles", GetListBoxDimensions());
		auto columns           = std::make_shared<Column>(2);


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

		static auto recoveryCommand = Commands::GetCommand<BoolCommand>("recoveryenabled"_J);

		collectiblesGroup->AddItem(std::make_shared<ImGuiItem>([=] {
			if (recoveryCommand->GetState())
			{
				std::map<Rewards::eRewardType, std::string> reward_translations = {{Rewards::eRewardType::GOLD_REWARDS, "Gold Rewards"}, {Rewards::eRewardType::HEIRLOOMS, "Heirlooms"}, {Rewards::eRewardType::COINS, "Coins"}, {Rewards::eRewardType::ALCBOTTLES, "Alcohol Bottles"}, {Rewards::eRewardType::ARROWHEADS, "Arrowheads"}, {Rewards::eRewardType::BRACELETS, "Bracelets"}, {Rewards::eRewardType::EARRINGS, "Earrings"}, {Rewards::eRewardType::NECKLACES, "Necklaces"}, {Rewards::eRewardType::RINGS, "Rings"}, {Rewards::eRewardType::TAROTCARDS_CUPS, "Tarot Cards - Cups"}, {Rewards::eRewardType::TAROTCARDS_PENTACLES, "Tarot Cards - Pentacles"}, {Rewards::eRewardType::TAROTCARDS_SWORDS, "Tarot Cards - Swords"}, {Rewards::eRewardType::TAROTCARDS_WANDS, "Tarot Cards - Wands"}};

				for (auto& [type, translation] : reward_translations)
				{
					if (ImGui::Button(std::string("Spawn all ").append(translation).c_str()))
					{
						Rewards::SpawnRequestedRewards({type});
					}
				}
			}
			else
			{
				ImGui::Text("Recovery Feature Restricted");
				ImGui::Text("The recovery/collectibles feature is risky and you might face a ban for using it. You are responsible for what you do with this feature. None of the developers or YimMenu organization are responsible for any damages to your account.");
				if (ImGui::Button("Enable Recovery"))
				{
					recoveryCommand->SetState(true);
				}
			}
		}));


		movementGroup->AddItem(std::make_shared<BoolCommandItem>("noclip"_J));


		columns->AddItem(globalsGroup);
		columns->AddItem(toolsGroup);
		columns->AddNextColumn();
		columns->AddItem(movementGroup);
		columns->AddItem(collectiblesGroup);
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