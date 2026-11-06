#include "Recovery.hpp"

#include "core/commands/BoolCommand.hpp"
#include "core/commands/Commands.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Self.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/ScriptFunction.hpp"
#include "game/rdr/Scripts.hpp"
#include "util/Rewards.hpp"
#include "core/memory/BytePatch.hpp"
#include "game/pointers/Pointers.hpp"
#include "core/frontend/widgets/toggle/imgui_toggle.hpp"


namespace Terminus::Submenus
{

	static std::unique_ptr<BytePatch> infiniteItemsPatch{nullptr};
	static bool infiniteItems;
	static bool loopReward;
	static Rewards::eRewardType selectedReward{Rewards::eRewardType::HEIRLOOMS};
	static std::string selectedHerb{"HERB_LOOT_ALASKAN_GINSENG"};

	static std::map<Rewards::eRewardType, const char*> rewardsMap = {
	    {Rewards::eRewardType::HEIRLOOMS, "Heirlooms"},
	    {Rewards::eRewardType::COINS, "Coins"},
	    {Rewards::eRewardType::ALCBOTTLES, "Alcohol Bottles"},
	    {Rewards::eRewardType::ARROWHEADS, "Arrowheads"},
	    {Rewards::eRewardType::BRACELETS, "Bracelets"},
	    {Rewards::eRewardType::EARRINGS, "Earrings"},
	    {Rewards::eRewardType::NECKLACES, "Necklaces"},
	    {Rewards::eRewardType::RINGS, "Rings"},
	    {Rewards::eRewardType::TAROTCARDS_CUPS, "Tarot Cards - Cups"},
	    {Rewards::eRewardType::TAROTCARDS_PENTACLES, "Tarot Cards - Pentacles"},
	    {Rewards::eRewardType::TAROTCARDS_SWORDS, "Tarot Cards - Swords"},
	    {Rewards::eRewardType::TAROTCARDS_WANDS, "Tarot Cards - Wands"},
	    {Rewards::eRewardType::FOSSILS, "Fossils"},
	    {Rewards::eRewardType::EGGS, "Eggs"},
	    {Rewards::eRewardType::TREASURE, "Treasure Reward"},
	    {Rewards::eRewardType::CAPITALE, "Capitale"},
	    {Rewards::eRewardType::XP, "25K XP"},
	    {Rewards::eRewardType::MOONSHINERXP, "200 Moonshiner XP"},
	    {Rewards::eRewardType::TRADERXP, "200 Trader XP"},
	    {Rewards::eRewardType::COLLECTORXP, "200 Collector XP"},
	    {Rewards::eRewardType::NATURALISTXP, "300 Naturalist XP"},
	    {Rewards::eRewardType::BOUNTYHUNTERXP, "200 Bounty Hunter XP"},
	    {Rewards::eRewardType::TRADERGOODS, "Max Trader Goods"},
	};

	std::map<std::string, const char*> herbsMap = {
	    {"HERB_LOOT_ALASKAN_GINSENG", "Alaskan Ginseng"},
	    {"HERB_LOOT_AMERICAN_GINSENG", "American Ginseng"},
	    {"HERB_LOOT_BAY_BOLETE", "Bay Bolete"},
	    {"HERB_LOOT_BLACK_BERRY", "Black Berry"},
	    {"HERB_LOOT_BLACK_CURRANT", "Black Currant"},
	    {"HERB_LOOT_BURDOCK_ROOT", "Burdock Root"},
	    {"HERB_LOOT_CHANTERELLES", "Chanterelles"},
	    {"HERB_LOOT_COMMON_BULRUSH", "Common Bulrush"},
	    {"HERB_LOOT_CREEPING_THYME", "Creeping Thyme"},
	    {"HERB_LOOT_DESERT_SAGE", "Desert Sage"},
	    {"HERB_LOOT_ENGLISH_MACE", "English Mace"},
	    {"HERB_LOOT_EVERGREEN_HUCKLEBERRY", "Evergreen Huckleberry"},
	    {"HERB_LOOT_GOLDEN_CURRANT", "Golden Currant"},
	    {"HERB_LOOT_HUMMINGBIRD_SAGE", "Hummingbird Sage"},
	    {"HERB_LOOT_INDIAN_TOBACCO", "Indian Tobacco"},
	    {"HERB_LOOT_MILKWEED", "Milkweed"},
	    {"HERB_LOOT_OLEANDER_SAGE", "Oleander Sage"},
	    {"HERB_LOOT_OREGANO", "Oregano"},
	    {"HERB_LOOT_PARASOL_MUSHROOM", "Parasol Mushroom"},
	    {"HERB_LOOT_PRAIRIE_POPPY", "Prairie Poppy"},
	    {"HERB_LOOT_RAMS_HEAD", "Rams Head"},
	    {"HERB_LOOT_RED_RASPBERRY", "Red Raspberry"},
	    {"HERB_LOOT_RED_SAGE", "Red Sage"},
	    {"HERB_LOOT_VANILLA_FLOWER", "Vanilla Flower"},
	    {"HERB_LOOT_VIOLET_SNOWDROP", "Violet Snowdrop"},
	    {"HERB_LOOT_WILD_CARROTS", "Wild Carrots"},
	    {"HERB_LOOT_WILD_FEVERFEW", "Wild Feverfew"},
	    {"HERB_LOOT_WILD_MINT", "Wild Mint"},
	    {"HERB_LOOT_WINTERGREEN_BERRY", "Wintergreen Berry"},
	    {"HERB_LOOT_YARROW", "Yarrow"},
	    {"HERB_LOOT_AGARITA", "Agarita"},
	    {"HERB_LOOT_BITTERWEED", "Bitterweed"},
	    {"HERB_LOOT_BLUE_BONNET", "Blue Bonnet"},
	    {"HERB_LOOT_BLOOD_FLOWER", "Blood Flower"},
	    {"HERB_LOOT_CARDINAL_FLOWER", "Cardinal Flower"},
	    {"HERB_LOOT_CHOCOLATE_DAISY", "Chocolate Daisy"},
	    {"HERB_LOOT_CREEK_PLUM", "Creek Plum"},
	    {"HERB_LOOT_RHUBARB", "Rhubarb"},
	    {"HERB_LOOT_WISTERIA", "Wisteria"},
	    {"HERB_LOOT_HARRIETUM", "Harrietum"},
	};

	Recovery::Recovery() :
	    Submenu::Submenu("Recovery")
	{
		auto recovery               = std::make_shared<Category>("Recovery");
		auto storyMode              = std::make_shared<Category>("Story");
		auto spawnCollectiblesGroup = std::make_shared<Group>("Spawn Collectibles");
		auto spawnHerbsGroup        = std::make_shared<Group>("Spawn Herbs");
		auto recoveryOptions        = std::make_shared<Group>("Options");
		auto storyRecoveryOptions   = std::make_shared<Group>("Story Mode Options");

		static auto recoveryCommand = Commands::GetCommand<BoolCommand>("recoveryenabled"_J);

		spawnCollectiblesGroup->AddItem(std::make_shared<ImGuiItem>([=] {
			if (!recoveryCommand->GetState())
			{
				ImGui::Text("Recovery Feature Restricted");
				ImGui::Text("The recovery/collectibles feature is risky and you might face a ban for using it. You are responsible for what you do with this feature. None of the developers or the YimMenu organization are responsible for any damages to your account.");
				
				if (ImGui::Button("Enable Recovery Features"))
					recoveryCommand->SetState(true);

				return;
			}
			
			if (ImGui::BeginCombo("Rewards", rewardsMap[selectedReward]))
			{
				for (auto& [type, name] : rewardsMap)
				{
					if (ImGui::Selectable(name, type == selectedReward))
						selectedReward = type;
				}
				ImGui::EndCombo();
			}

			ImGui::BeginDisabled(loopReward);
			if (ImGui::Button("Add Selected"))
			{
				FiberPool::Push([] {
					Rewards::GiveRequestedRewards({selectedReward});
				});
			}
			ImGui::EndDisabled();

			ImGui::SameLine();

			static float rewardTimer          = 0.0f;
			static const float rewardInterval = 0.2f;

			ImGui::Checkbox("Loop Selected", &loopReward);

			rewardTimer += ImGui::GetIO().DeltaTime;
			if (loopReward && rewardTimer >= rewardInterval)
			{
				rewardTimer = 0.0f;
				FiberPool::Push([] {
					Rewards::GiveRequestedRewards({selectedReward});
				});
			}
		}));

		spawnHerbsGroup->AddItem(std::make_shared<ImGuiItem>([=] {
			if (!recoveryCommand->GetState())
				return;

			if (ImGui::BeginCombo("Herbs", herbsMap[selectedHerb]))
			{
				for (auto& [herb, name] : herbsMap)
				{
					if (ImGui::Selectable(name, herb == selectedHerb))
						selectedHerb = herb;
				}
				ImGui::EndCombo();
			}

			static int amount = 1;
			ImGui::SliderInt("Amount", &amount, 1, 10);

			if (ImGui::Button("Give Selected"))
			{
				FiberPool::Push([] {
					if (!Scripts::RequestScript("interactive_campfire"_J))
					{
						Notifications::Show("Recovery", "Unavailable at the moment. Please try again later!", NotificationType::Error);
						return;
					}

					for (int i = 0; i < amount; i++)
						ScriptFunctions::GiveLootTableAward.StaticCall(Joaat(selectedHerb), 0);
				});
			}
		}));

		// recoveryOptions->AddItem(std::make_shared<BoolCommandItem>("unlimiteditems"_J)); // TODO
		recoveryOptions->AddItem(std::make_shared<ImGuiItem>([] {
			if (ImGui::Toggle("Infinite Items", &infiniteItems))
			{
				if (!Pointers.InfiniteItems)
				{
					infiniteItems = false;
					return;
				}

				if (infiniteItems)
				{
					if (infiniteItemsPatch)
						infiniteItemsPatch->Apply();
					else
					{
						infiniteItemsPatch = std::make_unique<BytePatch>(Pointers.InfiniteItems, std::to_array<uint8_t>({0x90, 0x90, 0x90}));
						infiniteItemsPatch->Apply();
					}
				}
				else if (infiniteItemsPatch)
					infiniteItemsPatch->Restore();
			}
			if (ImGui::IsItemHovered())
				ImGui::SetTooltip("Items in your satchel become infinite, including treasure maps.\n\n[Note]:This toggle will not be saved because it can break missions.");
		}));

		storyRecoveryOptions->AddItem(std::make_shared<CommandItem>("givestorycash"_J));
		storyRecoveryOptions->AddItem(std::make_shared<CommandItem>("giveallweapons"_J));
		storyRecoveryOptions->AddItem(std::make_shared<CommandItem>("giveallitems"_J));
		storyRecoveryOptions->AddItem(std::make_shared<CommandItem>("maxsphonor"_J));
		storyRecoveryOptions->AddItem(std::make_shared<CommandItem>("minsphonor"_J));
		
		recovery->AddItem(spawnCollectiblesGroup);
		recovery->AddItem(spawnHerbsGroup);
		recovery->AddItem(recoveryOptions);

		storyMode->AddItem(storyRecoveryOptions);

		AddCategory(std::move(recovery));
		AddCategory(std::move(storyMode));
	}
}