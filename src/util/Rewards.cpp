#include "Rewards.hpp"
#include "game/pointers/Pointers.hpp"
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

	void GiveRequestedRewards(std::vector<eRewardType> rewards)
	{
		for (auto& reward : rewards)
		{
			switch (reward)
			{
			//case eRewardType::GOLD_REWARDS:
			//	for (const auto& goldreward : GoldRewards)
			//	{
			//		SpawnRequestedRewards_Helper(goldreward);
			//	}
			//	break;
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
			}
		}
	};
};
