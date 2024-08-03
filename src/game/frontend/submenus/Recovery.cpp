#include "Recovery.hpp"

#include "core/commands/BoolCommand.hpp"
#include "core/commands/Commands.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/NativeHooks.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptFunction.hpp"
#include "game/rdr/Scripts.hpp"
#include "util/Rewards.hpp"

namespace YimMenu::Submenus
{
	namespace NetshoppingHooks
	{
		void _CASHINVENTORY_TRANSACTION_FIRE_AND_FORGET_ITEM(rage::scrNativeCallContext* ctx)
		{
			Hash ActionHash    = ctx->GetArg<Hash>(0);
			int* TransactionID = ctx->GetArg<int*>(1);
			uint64_t* ItemInfo = ctx->GetArg<uint64_t*>(2);
			int ItemInfoCount  = ctx->GetArg<int>(3);
			std::stringstream iss;
			iss << "\nCTFAFI\nAction Hash: " << ActionHash << "\n";
			iss << "ItemInfo[" << ItemInfoCount << "]:\n";
			for (int i = 0; i < ItemInfoCount; i++)
			{
				iss << "\tItemInfo[" << i << "] = " << ItemInfo[i] << ";\n";
			}
			LOG(INFO) << iss.str() << "***************************************";
			ctx->SetReturnValue<BOOL>(NETSHOPPING::_CASHINVENTORY_TRANSACTION_FIRE_AND_FORGET_ITEM(ActionHash, TransactionID, ItemInfo, ItemInfoCount));
		}

		void _0xA3B8D31C13CB4239(rage::scrNativeCallContext* ctx)
		{
			int TransactionID   = ctx->GetArg<int>(0);
			Hash ActionHash     = ctx->GetArg<Hash>(1);
			uint64_t* ItemInfo  = ctx->GetArg<uint64_t*>(2);
			int ItemInfoCount   = ctx->GetArg<int>(3);
			uint64_t* ItemInfo2 = ctx->GetArg<uint64_t*>(4);
			int arg6            = ctx->GetArg<int>(5);
			std::stringstream iss;
			iss << "\nC_0xA3B8D31C13CB4239\nAction Hash: " << ActionHash << "\n";
			iss << "ItemInfo[" << ItemInfoCount << "]:\n";
			for (int i = 0; i < ItemInfoCount; i++)
			{
				iss << "\tItemInfo[" << i << "] = " << ItemInfo[i] << ";\n";
			}
			LOG(INFO) << iss.str() << "***************************************";
			ctx->SetReturnValue<BOOL>(NETSHOPPING::_0xA3B8D31C13CB4239(TransactionID, ActionHash, ItemInfo, ItemInfoCount, ItemInfo2, arg6));
		}

		void _0xD1555FBC96C88444(rage::scrNativeCallContext* ctx)
		{
			joaat_t CurrencyHash = ctx->GetArg<joaat_t>(0);
			joaat_t ItemPathset  = ctx->GetArg<joaat_t>(1);
			int Balance          = ctx->GetArg<int>(2);
			uint64_t* arg4       = ctx->GetArg<uint64_t*>(3);
			int arg5             = ctx->GetArg<int>(4);
			std::stringstream iss;
			iss << "\nC_0xD1555FBC96C88444\n";
			iss << "CurrencyHash: " << CurrencyHash << "\n";
			iss << "ItemPathset: " << ItemPathset << "\n";
			iss << "Balance: " << Balance << "\n";
			iss << "arg4: " << *arg4 << "\n";
			iss << "arg5: " << arg5 << "\n";
			LOG(INFO) << iss.str() << "***************************************";
			ctx->SetReturnValue<BOOL>(NETSHOPPING::_0xD1555FBC96C88444(CurrencyHash, ItemPathset, Balance, (Any)arg4, arg5));
		}

		void AWARDS_GET_RESULT_ITEM(rage::scrNativeCallContext* ctx)
		{
			joaat_t AwardHash = ctx->GetArg<joaat_t>(1);
			LOG(INFO) << "AGRI award hash: " << HEX(AwardHash);
			ctx->SetReturnValue<Any>(SCRIPTS::AWARDS_GET_RESULT_ITEM(ctx->GetArg<Any*>(0), AwardHash, ctx->GetArg<int>(2), ctx->GetArg<Any*>(3)));
		}
	}

	Recovery::Recovery() :
	    Submenu::Submenu("Recovery")
	{
		auto recovery               = std::make_shared<Category>("Recovery");
		auto spawnCollectiblesGroup = std::make_shared<Group>("Spawn Collectibles");
		auto spawnHerbsGroup		= std::make_shared<Group>("Spawn Herbs");
		auto recoveryOptions        = std::make_shared<Group>("Options");

		static auto recoveryCommand = Commands::GetCommand<BoolCommand>("recoveryenabled"_J);

		spawnCollectiblesGroup->AddItem(std::make_shared<ImGuiItem>([=] {
			if (recoveryCommand->GetState())
			{
				static Rewards::eRewardType selected{};
				std::map<Rewards::eRewardType, std::string> reward_translations = {
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

				static bool hooked = false;
				if (!hooked && ImGui::Button("Hook Netshopping Natives"))
				{
					NativeHooks::AddHook("ALL_SCRIPTS"_J, NativeIndex::_CASHINVENTORY_TRANSACTION_FIRE_AND_FORGET_ITEM, NetshoppingHooks::_CASHINVENTORY_TRANSACTION_FIRE_AND_FORGET_ITEM);
					NativeHooks::AddHook("ALL_SCRIPTS"_J, NativeIndex::_0xA3B8D31C13CB4239, NetshoppingHooks::_0xA3B8D31C13CB4239);
					//NativeHooks::AddHook("ALL_SCRIPTS"_J, NativeIndex::_0xD1555FBC96C88444, NetshoppingHooks::_0xD1555FBC96C88444);
					NativeHooks::AddHook("ALL_SCRIPTS"_J, NativeIndex::AWARDS_GET_RESULT_ITEM, NetshoppingHooks::AWARDS_GET_RESULT_ITEM);
					hooked = true;
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
		spawnHerbsGroup->AddItem(std::make_shared<ImGuiItem>([=] {
			if (recoveryCommand->GetState())
			{
				static joaat_t selectedHerb;
				std::map<joaat_t, std::string> herb_translations = {{"HERB_LOOT_ALASKAN_GINSENG"_J, "Alaskan Ginseng"},{"HERB_LOOT_AMERICAN_GINSENG"_J, "American Ginseng"},{"HERB_LOOT_BAY_BOLETE"_J, "Bay Bolete"},{"HERB_LOOT_BLACK_BERRY"_J, "Black Berry"},{"HERB_LOOT_BLACK_CURRANT"_J, "Black Currant"},{"HERB_LOOT_BURDOCK_ROOT"_J, "Burdock Root"},{"HERB_LOOT_CHANTERELLES"_J, "Chanterelles"},{"HERB_LOOT_COMMON_BULRUSH"_J, "Common Bulrush"},{"HERB_LOOT_CREEPING_THYME"_J, "Creeping Thyme"},{"HERB_LOOT_DESERT_SAGE"_J, "Desert Sage"},{"HERB_LOOT_ENGLISH_MACE"_J, "English Mace"},{"HERB_LOOT_EVERGREEN_HUCKLEBERRY"_J, "Evergreen Huckleberry"},{"HERB_LOOT_GOLDEN_CURRANT"_J, "Golden Currant"},{"HERB_LOOT_HUMMINGBIRD_SAGE"_J, "Hummingbird Sage"},{"HERB_LOOT_INDIAN_TOBACCO"_J, "Indian Tobacco"},{"HERB_LOOT_MILKWEED"_J, "Milkweed"},{"HERB_LOOT_OLEANDER_SAGE"_J, "Oleander Sage"},{"HERB_LOOT_OREGANO"_J, "Oregano"},{"HERB_LOOT_PARASOL_MUSHROOM"_J, "Parasol Mushroom"},{"HERB_LOOT_PRAIRIE_POPPY"_J, "Prairie Poppy"},{"HERB_LOOT_RAMS_HEAD"_J, "Rams Head"},{"HERB_LOOT_RED_RASPBERRY"_J, "Red Raspberry"},{"HERB_LOOT_RED_SAGE"_J, "Red Sage"},{"HERB_LOOT_VANILLA_FLOWER"_J, "Vanilla Flower"},{"HERB_LOOT_VIOLET_SNOWDROP"_J, "Violet Snowdrop"},{"HERB_LOOT_WILD_CARROTS"_J, "Wild Carrots"},{"HERB_LOOT_WILD_FEVERFEW"_J, "Wild Feverfew"},{"HERB_LOOT_WILD_MINT"_J, "Wild Mint"},{"HERB_LOOT_WINTERGREEN_BERRY"_J, "Wintergreen Berry"},{"HERB_LOOT_YARROW"_J, "Yarrow"},{"HERB_LOOT_AGARITA"_J, "Agarita"},{"HERB_LOOT_BITTERWEED"_J, "Bitterweed"},{"HERB_LOOT_BLUE_BONNET"_J, "Blue Bonnet"},{"HERB_LOOT_BLOOD_FLOWER"_J, "Blood Flower"},{"HERB_LOOT_CARDINAL_FLOWER"_J, "Cardinal Flower"},{"HERB_LOOT_CHOCOLATE_DAISY"_J, "Chocolate Daisy"},{"HERB_LOOT_CREEK_PLUM"_J, "Creek Plum"},{"HERB_LOOT_RHUBARB"_J, "Rhubarb"},{"HERB_LOOT_WISTERIA"_J, "Wisteria"},{"HERB_LOOT_HARRIETUM"_J, "Harrietum"},};
				if (ImGui::BeginCombo("Herbs", herb_translations[selectedHerb].c_str()))
				{
					for (auto& [herb, translation] : herb_translations)
					{
						if (ImGui::Selectable(std::string(translation).c_str(), herb == selectedHerb))
						{
							selectedHerb = herb;
						}
					}
					ImGui::EndCombo();
				}

				static int amount = 1;
				ImGui::SliderInt("Amount", &amount, 1, 10);

				if (ImGui::Button("Give Selected"))
				{
					FiberPool::Push([] {
						if (!Scripts::RequestScript("interactive_campfire"_J))
							return;

						for (int i = 0; i < amount; i++)
							ScriptFunctions::GiveLootTableAward.StaticCall(selectedHerb, 0);
					});
				}
			}
		}));
		recoveryOptions->AddItem(std::make_shared<BoolCommandItem>("unlimiteditems"_J));
		recoveryOptions->AddItem(std::make_shared<BoolCommandItem>("fastmoonshine"_J));
		recovery->AddItem(spawnCollectiblesGroup);
		recovery->AddItem(spawnHerbsGroup);
		recovery->AddItem(recoveryOptions);

		AddCategory(std::move(recovery));
	}
}