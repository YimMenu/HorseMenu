#include "Self.hpp"

#include "core/commands/BoolCommand.hpp"
#include "core/commands/Commands.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/features/Features.hpp"
#include "util/libraries/Emote.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/Natives.hpp"
#include "util/Ped.hpp"
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

				TASK::TASK_PLAY_ANIM(YimMenu::Self::PlayerPed, dict.c_str(), anim.c_str(), 8.0f, -8.0f, -1, 0, 0, FALSE, FALSE, FALSE, "", 0);
			});
		}

		ImGui::Separator();

		ImGui::Text("Emote Category");
		if (ImGui::BeginCombo("##Emote Category", Emote::emoteCategories[Emote::selectedEmoteCategoryIndex]))
		{
			for (int i = 0; i < Emote::numCategories; i++)
			{
				bool isSelected = (i == Emote::selectedEmoteCategoryIndex);
				if (ImGui::Selectable(Emote::emoteCategories[i], isSelected))
				{
					Emote::selectedEmoteCategoryIndex          = i;
					Emote::selectedEmoteMemberIndex   = 0;
				}
				if (isSelected)
				{
					ImGui::SetItemDefaultFocus();
				}
			}
			ImGui::EndCombo();
		}

		ImGui::Text("Emote");
		if (ImGui::BeginCombo("##Emote",
		        Emote::emoteCategoryMembers[Emote::selectedEmoteCategoryIndex][Emote::selectedEmoteMemberIndex]
		            .name))
		{
			for (int i = 0; i < Emote::maxEmotesPerCategory; i++)
			{
				const auto& emote = Emote::emoteCategoryMembers[Emote::selectedEmoteCategoryIndex][i];
				if (emote.name == nullptr)
					break;
				bool isSelected = (i == Emote::selectedEmoteMemberIndex);
				if (ImGui::Selectable(emote.name, isSelected))
				{
					Emote::selectedEmoteMemberIndex = i;
				}
				if (isSelected)
				{
					ImGui::SetItemDefaultFocus();
				}
			}
			ImGui::EndCombo();
		}

		if (ImGui::Button("Play Emote"))
		{
			if (*Pointers.IsSessionStarted)
			{
				FiberPool::Push([=] {
					int selectedCategoryIndex = Emote::selectedEmoteCategoryIndex;
					int selectedEmoteIndex    = Emote::selectedEmoteMemberIndex;
					const Emote::EmoteItemData& selectedEmote = Emote::emoteCategoryMembers[selectedCategoryIndex][selectedEmoteIndex];

					TASK::TASK_PLAY_EMOTE_WITH_HASH(YimMenu::Self::PlayerPed,
					    static_cast<int>(selectedEmote.type),
					    EMOTE_PM_FULLBODY,
					    static_cast<Hash>(selectedEmote.hash),
					    false,
					    false,
					    false,
					    false,
					    false);
				});
			}
		}

		if (ImGui::Button("Stop Animation"))
		{
			FiberPool::Push([=] {
				TASK::CLEAR_PED_TASKS(YimMenu::Self::PlayerPed, TRUE, FALSE);
			});
		}
	}

	Self::Self() :
	    Submenu::Submenu("Self")
	{
		auto main            = std::make_shared<Category>("Main");
		auto globalsGroup    = std::make_shared<Group>("Globals", GetListBoxDimensions());
		auto movementGroup   = std::make_shared<Group>("Movement", GetListBoxDimensions());
		auto toolsGroup      = std::make_shared<Group>("Tools", GetListBoxDimensions());
		auto pedSpawnerGroup = std::make_shared<Group>("Ped Spawner", GetListBoxDimensions());
		auto columns         = std::make_shared<Column>(2);


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
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("nospread"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("autocock"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("keepclean"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("antilasso"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("antihogtie"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("antimelee"_J));

		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("drunk"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("autotp"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("superjump"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("superdamage"_J));
		globalsGroup->AddItem(std::make_shared<BoolCommandItem>("superpunch"_J));


		toolsGroup->AddItem(std::make_shared<CommandItem>("suicide"_J));
		toolsGroup->AddItem(std::make_shared<CommandItem>("clearcrimes"_J));
		toolsGroup->AddItem(std::make_shared<ImGuiItem>([] {
			if (ImGui::Button("Unfreeze"))
				FiberPool::Push([] {
					ENTITY::FREEZE_ENTITY_POSITION(YimMenu::Self::PlayerPed, false);
				});
		}));

		toolsGroup->AddItem(std::make_shared<BoolCommandItem>("npcignore"_J));
		toolsGroup->AddItem(std::make_shared<BoolCommandItem>("eagleeye"_J));
		toolsGroup->AddItem(std::make_shared<CommandItem>("spawnbountywagon"_J));
		toolsGroup->AddItem(std::make_shared<CommandItem>("spawnhuntingwagon"_J));

		toolsGroup->AddItem(std::make_shared<BoolCommandItem>("overridewhistle"_J));
		toolsGroup->AddItem(std::make_shared<ImGuiItem>([] {
			ImGui::Text("Pitch");
			ImGui::SliderFloat("##Pitch", &SelfStorage::pitch, 0.0f, 1.0f);
			ImGui::Text("Clarity");
			ImGui::SliderFloat("##Clarity", &SelfStorage::clarity, 0.0f, 1.0f);
			ImGui::Text("Shape");
			ImGui::SliderFloat("##Shape", &SelfStorage::shape, 0.0f, 10.0f);
		}));

		movementGroup->AddItem(std::make_shared<BoolCommandItem>("noclip"_J));
		movementGroup->AddItem(std::make_shared<BoolCommandItem>("superjump"_J));
		movementGroup->AddItem(std::make_shared<BoolCommandItem>("superrun"_J));

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
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("keephorseclean"_J));
		horseGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("horseclimbsteepslopes"_J));
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
					PED::_SET_PED_SCALE(YimMenu::Self::Mount, (float)horseScale);
				});
		}));
		horseColumns->AddItem(horseGlobalsGroup);
		horse->AddItem(horseColumns);
		AddCategory(std::move(horse));

		auto vehicle             = std::make_shared<Category>("Vehicle");
		auto vehicleColumns      = std::make_shared<Column>(1);
		auto vehicleGlobalsGroup = std::make_shared<Group>("Globals", GetListBoxDimensions());
		vehicleGlobalsGroup->AddItem(std::make_shared<BoolCommandItem>("vehiclegodmode"_J));
		vehicleGlobalsGroup->AddItem(std::make_shared<CommandItem>("repairvehicle"_J));
		vehicleColumns->AddItem(vehicleGlobalsGroup);
		vehicle->AddItem(vehicleColumns);
		AddCategory(std::move(vehicle));

		auto animations = std::make_shared<Category>("Animations");

		animations->AddItem(std::make_shared<ImGuiItem>([] {
			RenderAnimationsCategory();
		}));

		AddCategory(std::move(animations));

		auto recovery               = std::make_shared<Category>("Recovery");
		auto recoveryColumns        = std::make_shared<Column>(2);
		auto spawnCollectiblesGroup = std::make_shared<Group>("Spawn Collectibles", GetListBoxDimensions());
		auto recoveryOptions        = std::make_shared<Group>("Options", GetListBoxDimensions());

		static auto recoveryCommand = Commands::GetCommand<BoolCommand>("recoveryenabled"_J);

		spawnCollectiblesGroup->AddItem(std::make_shared<ImGuiItem>([=] {
			if (recoveryCommand->GetState())
			{
				static Rewards::eRewardType selected;
				std::map<Rewards::eRewardType, std::string> reward_translations = {{Rewards::eRewardType::GOLD_REWARDS, "Gold Rewards"}, {Rewards::eRewardType::HEIRLOOMS, "Heirlooms"}, {Rewards::eRewardType::COINS, "Coins"}, {Rewards::eRewardType::ALCBOTTLES, "Alcohol Bottles"}, {Rewards::eRewardType::ARROWHEADS, "Arrowheads"}, {Rewards::eRewardType::BRACELETS, "Bracelets"}, {Rewards::eRewardType::EARRINGS, "Earrings"}, {Rewards::eRewardType::NECKLACES, "Necklaces"}, {Rewards::eRewardType::RINGS, "Rings"}, {Rewards::eRewardType::TAROTCARDS_CUPS, "Tarot Cards - Cups"}, {Rewards::eRewardType::TAROTCARDS_PENTACLES, "Tarot Cards - Pentacles"}, {Rewards::eRewardType::TAROTCARDS_SWORDS, "Tarot Cards - Swords"}, {Rewards::eRewardType::TAROTCARDS_WANDS, "Tarot Cards - Wands"}};

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
							Rewards::SpawnRequestedRewards({selected});
						}
					}
					ImGui::EndCombo();
				}

				if (ImGui::Button("Spawn Selected"))
				{
					Rewards::SpawnRequestedRewards({selected});
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
		recoveryOptions->AddItem(std::make_shared<BoolCommandItem>("unlimiteditems"_J));
		recoveryColumns->AddItem(spawnCollectiblesGroup);
		recoveryColumns->AddItem(recoveryOptions);
		recovery->AddItem(recoveryColumns);

		AddCategory(std::move(recovery));
	}
}
