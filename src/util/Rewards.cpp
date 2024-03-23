#include "Rewards.hpp"

namespace YimMenu::Rewards
{
	void SpawnRequestedRewards(std::vector<eRewardType> rewards)
	{
		for (auto& reward : rewards)
		{
			switch (reward)
			{
			case eRewardType::GOLD_REWARDS:
				for (const auto& goldreward : GoldRewards)
				{
					SpawnRequestedRewards_Helper(goldreward.model);
				}
				break;
			case eRewardType::HEIRLOOMS:
				for (const auto& heirloom : Heirlooms)
				{
					SpawnRequestedRewards_Helper(heirloom.model);
				}
				break;
			case eRewardType::COINS:
				for (const auto& coin : Coins)
				{
					SpawnRequestedRewards_Helper(coin.model);
				}
				break;
			case eRewardType::ALCBOTTLES:
				for (const auto& alc : AlcBottles)
				{
					SpawnRequestedRewards_Helper(alc.model);
				}
				break;

			case eRewardType::ARROWHEADS:
				for (const auto& arrowhead : Arrowheads)
				{
					SpawnRequestedRewards_Helper(arrowhead.model);
				}
				break;
			case eRewardType::BRACELETS:
				for (const auto& bracelet : Bracelets)
				{
					SpawnRequestedRewards_Helper(bracelet.model);
				}
				break;
			case eRewardType::EARRINGS:
				for (const auto& earring : Earrings)
				{
					SpawnRequestedRewards_Helper(earring.model);
				}
				break;
			case eRewardType::NECKLACES:
				for (const auto& necklace : Necklaces)
				{
					SpawnRequestedRewards_Helper(necklace.model);
				}
				break;
			case eRewardType::RINGS:
				for (const auto& ring : Rings)
				{
					SpawnRequestedRewards_Helper(ring.model);
				}
				break;
			case eRewardType::TAROTCARDS_CUPS:
				for (const auto& card : TarotCards_Cups)
				{
					SpawnRequestedRewards_Helper(card.model);
				}
				break;
			case eRewardType::TAROTCARDS_PENTACLES:
				for (const auto& card : TarotCards_Pentacles)
				{
					SpawnRequestedRewards_Helper(card.model);
				}
				break;
			case eRewardType::TAROTCARDS_SWORDS:
				for (const auto& card : TarotCards_Swords)
				{
					SpawnRequestedRewards_Helper(card.model);
				}
				break;
			case eRewardType::TAROTCARDS_WANDS:
				for (const auto& card : TarotCards_Wands)
				{
					SpawnRequestedRewards_Helper(card.model);
				}
				break;
			}
		}
	};

	void SpawnRequestedRewards_Helper(std::string model_name)
	{
		FiberPool::Push([=] {
			Hash hash = MISC::GET_HASH_KEY(model_name.c_str());
			if (STREAMING::IS_MODEL_IN_CDIMAGE(hash) && STREAMING::IS_MODEL_VALID(hash))
			{
				if (!STREAMING::HAS_MODEL_LOADED(hash))
				{
					STREAMING::REQUEST_MODEL(hash, false);
					ScriptMgr::Yield();
				}
				Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true, false);
				Object obj = OBJECT::CREATE_OBJECT(hash, coords.x, coords.y, coords.z, true, NETWORK::NETWORK_IS_HOST_OF_THIS_SCRIPT(), 1, 0, 1);
				ScriptMgr::Yield();

				ENTITY::SET_ENTITY_VISIBLE(obj, true);
				ScriptMgr::Yield();

				OBJECT::_MAKE_ITEM_CARRIABLE(obj);

				NETWORK::NETWORK_REGISTER_ENTITY_AS_NETWORKED(obj);
				if (NETWORK::NETWORK_DOES_NETWORK_ID_EXIST(NETWORK::OBJ_TO_NET(obj)))
				{
					OBJECT::PLACE_OBJECT_ON_GROUND_PROPERLY(obj, true);
					ENTITY::SET_ENTITY_SHOULD_FREEZE_WAITING_ON_COLLISION(obj, true);
					NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(NETWORK::OBJ_TO_NET(obj), true);
					NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(obj);
				}
				ScriptMgr::Yield();

				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
				ENTITY::SET_OBJECT_AS_NO_LONGER_NEEDED(&obj);
			}
		});
	};
};
