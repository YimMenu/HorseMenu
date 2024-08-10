#include "Rewards.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/ScriptFunction.hpp"
#include "game/rdr/Scripts.hpp"
#include <event/CEventGroup.hpp>
#include <event/CEventInventoryItemPickedUp.hpp>

namespace YimMenu::Rewards
{
	void GiveReward(const RewardInfo& info)
	{
		CEventInventoryItemPickedUp event;
		Pointers.InventoryEventConstructor(&event, info.reward_hash, info.model_hash, false, false, nullptr);
		(*Pointers.EventGroupNetwork)->AddEvent(&event, false);
	};

	void GiveScriptReward(const RewardInfo& info, bool loottable)
	{
		if (!Scripts::RequestScript("interactive_campfire"_J))
			return;

		if (loottable)
			ScriptFunctions::GiveLootTableAward.StaticCall(info.reward_hash, 0);
		else
			ScriptFunctions::GiveItemDatabaseAward.StaticCall(info.reward_hash, false, 255, 0, false);
	}

	void GiveRequestedRewards(std::vector<eRewardType> rewards)
	{
		if (!Scripts::UsingMPScripts())
			return;

		for (auto& reward : rewards)
		{
			switch (reward)
			{
			case eRewardType::HEIRLOOMS:
				for (const auto& heirloom : Heirlooms)
				{
					GiveReward(heirloom);
				}
				break;
			case eRewardType::COINS:
				for (const auto& coin : Coins)
				{
					GiveReward(coin);
				}
				break;
			case eRewardType::ALCBOTTLES:
				for (const auto& alc : AlcBottles)
				{
					GiveReward(alc);
				}
				break;

			case eRewardType::ARROWHEADS:
				for (const auto& arrowhead : Arrowheads)
				{
					GiveReward(arrowhead);
				}
				break;
			case eRewardType::BRACELETS:
				for (const auto& bracelet : Bracelets)
				{
					GiveReward(bracelet);
				}
				break;
			case eRewardType::EARRINGS:
				for (const auto& earring : Earrings)
				{
					GiveReward(earring);
				}
				break;
			case eRewardType::NECKLACES:
				for (const auto& necklace : Necklaces)
				{
					GiveReward(necklace);
				}
				break;
			case eRewardType::RINGS:
				for (const auto& ring : Rings)
				{
					GiveReward(ring);
				}
				break;
			case eRewardType::TAROTCARDS_CUPS:
				for (const auto& card : TarotCards_Cups)
				{
					GiveReward(card);
				}
				break;
			case eRewardType::TAROTCARDS_PENTACLES:
				for (const auto& card : TarotCards_Pentacles)
				{
					GiveReward(card);
				}
				break;
			case eRewardType::TAROTCARDS_SWORDS:
				for (const auto& card : TarotCards_Swords)
				{
					GiveReward(card);
				}
				break;
			case eRewardType::TAROTCARDS_WANDS:
				for (const auto& card : TarotCards_Wands)
				{
					GiveReward(card);
				}
				break;
			case eRewardType::FOSSILS:
				for (const auto& fossil : Fossils)
				{
					GiveScriptReward(fossil);
				}
				break;
			case eRewardType::EGGS:
				for (const auto& egg : Eggs)
				{
					GiveScriptReward(egg);
				}
				break;
			case eRewardType::TREASURE:
				for (const auto& treasure : TreasureReward)
				{
					GiveScriptReward(treasure);
				}
				break;
			case eRewardType::CAPITALE:
				for (const auto& capitale : CapitaleReward)
				{
					GiveScriptReward(capitale);
				}
				break;
			case eRewardType::XP:
				for (const auto& xp : RegularXP)
				{
					GiveScriptReward(xp, false);
				}
				break;
			case eRewardType::MOONSHINERXP:
				for (const auto& xp : MoonshinerXP)
				{
					GiveScriptReward(xp, false);
				}
				break;
			case eRewardType::TRADERXP:
				for (const auto& xp : TraderXP)
				{
					GiveScriptReward(xp, false);
				}
				break;
			case eRewardType::COLLECTORXP:
				for (const auto& xp : CollectorXP)
				{
					GiveScriptReward(xp, false);
				}
				break;
			case eRewardType::NATURALISTXP:
				for (const auto& xp : NaturalistXP)
				{
					GiveScriptReward(xp, false);
				}
				break;
			case eRewardType::BOUNTYHUNTERXP:
				for (const auto& xp : BountyHunterXP)
				{
					GiveScriptReward(xp, false);
				}
				break;
			case eRewardType::TRADERGOODS:
				for (const auto& good : TraderGoods)
				{
					GiveScriptReward(good, false);
				}
				break;
			}
		}
	};
};
