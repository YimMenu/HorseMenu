#include "Self.hpp"

#include "core/commands/BoolCommand.hpp"
#include "core/commands/IntCommand.hpp"
#include "core/commands/Commands.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/Natives.hpp"
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

				TASK::TASK_PLAY_ANIM(YimMenu::Self::GetPed().GetHandle(), dict.c_str(), anim.c_str(), 8.0f, -8.0f, -1, 0, 0, false, false, false, "", 0);
			});
		}
		ImGui::SameLine();
		if (ImGui::Button("Stop"))
		{
			FiberPool::Push([=] {
				TASK::CLEAR_PED_TASKS(YimMenu::Self::GetPed().GetHandle(), true, false);
			});
		}
	}

	Self::Self() :
	    Submenu::Submenu("Self")
	{
		auto main            = std::make_shared<Category>("Main");
		auto globalsGroup    = std::make_shared<Group>("Globals");
		auto movementGroup   = std::make_shared<Group>("Movement");
		auto toolsGroup      = std::make_shared<Group>("Tools");
		auto pedSpawnerGroup = std::make_shared<Group>("Ped Spawner");


		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("godmode"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("neverwanted"_J));
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
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("antimelee"_J));

		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("drunk"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("superpunch"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("quickskin"_J));

		toolsGroup->AddItem(std::make_shared<CommandItem>("suicide"_J));
		toolsGroup->AddItem(std::make_shared<CommandItem>("clearcrimes"_J));
		toolsGroup->AddItem(std::make_shared<ImGuiItem>([] {
			if (ImGui::Button("Unfreeze"))
				FiberPool::Push([] {
					YimMenu::Self::GetPed().SetFrozen(false);
					YimMenu::Self::GetPed().SetCollision(true);
				});
		}));

		toolsGroup->AddItem(std::make_shared<BoolCommandItem>("npcignore"_J));
		toolsGroup->AddItem(std::make_shared<CommandItem>("spawnbountywagon"_J));
		toolsGroup->AddItem(std::make_shared<CommandItem>("spawnhuntingwagon"_J));

		movementGroup->AddItem(std::make_shared<BoolCommandItem>("noclip"_J));
		movementGroup->AddItem(std::make_shared<BoolCommandItem>("superjump"_J));

		main->AddItem(globalsGroup);
		main->AddItem(toolsGroup);
		main->AddItem(movementGroup);
		AddCategory(std::move(main));

		auto horse             = std::make_shared<Category>("Horse");
		auto horseGlobalsGroup = std::make_shared<Group>("Globals");
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("horsegodmode"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("horsenoragdoll"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("horsesuperrun"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("keephorsebarsfilled"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("keephorsecoresfilled"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("keephorseagitationlow"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("flaminghooves"_J));
		horseGlobalsGroup->AddItem(std::make_shared<CommandItem>("tpmounttoself"_J));
		static int horseScale = 1;
		horseGlobalsGroup->AddItem(std::make_shared<ImGuiItem>([] {
			ImGui::Text("Horse Scale");
			if (ImGui::InputInt(" ", &horseScale))
				FiberPool::Push([] {
					PED::_SET_PED_SCALE(YimMenu::Self::GetMount().GetHandle(), (float)horseScale);
				});
		}));
		horse->AddItem(horseGlobalsGroup);
		AddCategory(std::move(horse));

		auto vehicle             = std::make_shared<Category>("Vehicle");
		auto vehicleGlobalsGroup = std::make_shared<Group>("Globals");
		auto vehicleFunGroup = std::make_shared<Group>("Fun");

		vehicleGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("vehiclegodmode"_J));
		vehicleGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("superbrake"_J));
		vehicleGlobalsGroup->AddItem(std::make_shared<CommandItem>("repairvehicle"_J));

		vehicleFunGroup->AddItem(std::make_shared<BoolCommandItem>("superdrive"_J));
		vehicleFunGroup->AddItem(std::make_shared<BoolCommandItem>("superdrivedirectional"_J, "Directional"));
		vehicleFunGroup->AddItem(std::make_shared<IntCommandItem>("superdriveforce"_J, "Force"));
		vehicleFunGroup->AddItem(std::make_shared<BoolCommandItem>("superbrake"_J));
		vehicle->AddItem(vehicleGlobalsGroup);
		vehicle->AddItem(vehicleFunGroup);
		AddCategory(std::move(vehicle));

		auto animations = std::make_shared<Category>("Animations");

		animations->AddItem(std::make_shared<ImGuiItem>([] {
			RenderAnimationsCategory();
		}));

		AddCategory(std::move(animations));

		auto recovery               = std::make_shared<Category>("Recovery");
		auto spawnCollectiblesGroup = std::make_shared<Group>("Spawn Collectibles");
		auto recoveryOptions        = std::make_shared<Group>("Options");

		static auto recoveryCommand = Commands::GetCommand<BoolCommand>("recoveryenabled"_J);

		spawnCollectiblesGroup->AddItem(std::make_shared<ImGuiItem>([=] {
			if (recoveryCommand->GetState())
			{
				static Rewards::eRewardType selected{};
				std::map<Rewards::eRewardType, std::string> reward_translations = {{Rewards::eRewardType::HEIRLOOMS, "Heirlooms"}, {Rewards::eRewardType::COINS, "Coins"}, {Rewards::eRewardType::ALCBOTTLES, "Alcohol Bottles"}, {Rewards::eRewardType::ARROWHEADS, "Arrowheads"}, {Rewards::eRewardType::BRACELETS, "Bracelets"}, {Rewards::eRewardType::EARRINGS, "Earrings"}, {Rewards::eRewardType::NECKLACES, "Necklaces"}, {Rewards::eRewardType::RINGS, "Rings"}, {Rewards::eRewardType::TAROTCARDS_CUPS, "Tarot Cards - Cups"}, {Rewards::eRewardType::TAROTCARDS_PENTACLES, "Tarot Cards - Pentacles"}, {Rewards::eRewardType::TAROTCARDS_SWORDS, "Tarot Cards - Swords"}, {Rewards::eRewardType::TAROTCARDS_WANDS, "Tarot Cards - Wands"}};

				if (ImGui::BeginCombo("Rewards", reward_translations[selected].c_str()))
				{
					for (auto& [type, translation] : reward_translations)
					{
						if (ImGui::Selectable(std::string(translation).c_str(), type == selected, ImGuiSelectableFlags_AllowDoubleClick))
						{
							selected = type;
						}
						if (ImGui::IsItemHovered() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
						{
							FiberPool::Push([] {
								Rewards::GiveRequestedRewards({selected});
							});
						}
					}
					ImGui::EndCombo();
				}

				if (ImGui::Button("Add Selected"))
				{
					FiberPool::Push([] {
						Rewards::GiveRequestedRewards({selected});
					});
				}
			}
			else
			{
				ImGui::Text("Recovery Feature Restricted");
				ImGui::Text("The recovery/collectibles feature is risky and you might face a ban for using it. You are responsible for what you do with this feature. None of the developers or the YimMenu organization are responsible for any damages to your account.");
				if (ImGui::Button("Enable Recovery"))
				{
					recoveryCommand->SetState(true);
				}
			}
		}));
		recoveryOptions->AddItem(std::make_shared<BoolCommandItem>("unlimiteditems"_J));
		recovery->AddItem(spawnCollectiblesGroup);
		recovery->AddItem(recoveryOptions);

		AddCategory(std::move(recovery));
	}
}
