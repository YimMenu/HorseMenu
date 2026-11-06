#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_STATS_STAT_ID_IS_VALID(uintptr_t statId)
	{
		auto retval = (bool)STATS::STAT_ID_IS_VALID((Any*)statId);
		return retval;
	}

	static bool LUA_NATIVE_STATS_STAT_ID_SET_INT(uintptr_t statId, int value, bool p2)
	{
		auto retval = (bool)STATS::STAT_ID_SET_INT((Any*)statId, value, p2);
		return retval;
	}

	static bool LUA_NATIVE_STATS_STAT_ID_SET_FLOAT(uintptr_t statId, float value, bool p2)
	{
		auto retval = (bool)STATS::STAT_ID_SET_FLOAT((Any*)statId, value, p2);
		return retval;
	}

	static bool LUA_NATIVE_STATS_STAT_ID_SET_BOOL(uintptr_t statId, bool value, bool p2)
	{
		auto retval = (bool)STATS::STAT_ID_SET_BOOL((Any*)statId, value, p2);
		return retval;
	}

	static bool LUA_NATIVE_STATS_STAT_ID_SET_GXT_LABEL(uintptr_t statId, sol::stack_object label, bool p2)
	{
		auto retval = (bool)STATS::STAT_ID_SET_GXT_LABEL((Any*)statId, label.is<const char*>() ? label.as<const char*>() : nullptr, p2);
		return retval;
	}

	static bool LUA_NATIVE_STATS_STAT_ID_SET_DATE(uintptr_t statId, uintptr_t date, bool p2)
	{
		auto retval = (bool)STATS::STAT_ID_SET_DATE((Any*)statId, (Any*)date, p2);
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_STATS_STAT_ID_GET_INT(uintptr_t statId, int p1)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)STATS::STAT_ID_GET_INT((Any*)statId, &p1);
		std::get<1>(return_values) = p1;

		return return_values;
	}

	static std::tuple<bool, float> LUA_NATIVE_STATS_STAT_ID_GET_FLOAT(uintptr_t statId, float value)
	{
		std::tuple<bool, float> return_values;
		std::get<0>(return_values) = (bool)STATS::STAT_ID_GET_FLOAT((Any*)statId, &value);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static std::tuple<bool, bool> LUA_NATIVE_STATS_STAT_ID_GET_BOOL(uintptr_t statId, bool value)
	{
		std::tuple<bool, bool> return_values;
		std::get<0>(return_values) = (bool)STATS::STAT_ID_GET_BOOL((Any*)statId, (BOOL*)&value);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static bool LUA_NATIVE_STATS_STAT_ID_GET_DATE(uintptr_t statId, uintptr_t date)
	{
		auto retval = (bool)STATS::STAT_ID_GET_DATE((Any*)statId, (Any*)date);
		return retval;
	}

	static void LUA_NATIVE_STATS__0x0FEE2561120F3333(uintptr_t statId)
	{
		STATS::_0x0FEE2561120F3333((Any*)statId);
	}

	static void LUA_NATIVE_STATS__STAT_ID_INCREMENT_INT(uintptr_t statId, int value)
	{
		STATS::_STAT_ID_INCREMENT_INT((Any*)statId, value);
	}

	static void LUA_NATIVE_STATS__STAT_ID_INCREMENT_FLOAT(uintptr_t statId, float value)
	{
		STATS::_STAT_ID_INCREMENT_FLOAT((Any*)statId, value);
	}

	static void LUA_NATIVE_STATS__STAT_ID_DECREMENT_INT(uintptr_t statId, int value)
	{
		STATS::_STAT_ID_DECREMENT_INT((Any*)statId, value);
	}

	static void LUA_NATIVE_STATS__0x91A4F58E01ED5E4C(uintptr_t statId, int value)
	{
		STATS::_0x91A4F58E01ED5E4C((Any*)statId, value);
	}

	static void LUA_NATIVE_STATS__0xE141F6B40B1E3683(uintptr_t statId, float value)
	{
		STATS::_0xE141F6B40B1E3683((Any*)statId, value);
	}

	static void LUA_NATIVE_STATS_STAT_ID_SET_TO_POSSE_ID(uintptr_t statId)
	{
		STATS::STAT_ID_SET_TO_POSSE_ID((Any*)statId);
	}

	static int LUA_NATIVE_STATS__STAT_CALCULATE_COOLDOWN(int value)
	{
		auto retval = STATS::_STAT_CALCULATE_COOLDOWN(value);
		return retval;
	}

	static bool LUA_NATIVE_STATS__STAT_PHEROMONE_COOLDOWN_LEGENDARY_ANIMAL(Entity entity, uintptr_t statId)
	{
		auto retval = (bool)STATS::_STAT_PHEROMONE_COOLDOWN_LEGENDARY_ANIMAL(entity, (Any*)statId);
		return retval;
	}

	static void LUA_NATIVE_STATS__STAT_ITEM_FISH_CAUGHT(Ped fish, float weight, Hash category, Hash subcategory)
	{
		STATS::_STAT_ITEM_FISH_CAUGHT(fish, weight, category, subcategory);
	}

	static void LUA_NATIVE_STATS__STAT_CARRIED_SATCHEL_ITEM_FROM_PED(Ped ped)
	{
		STATS::_STAT_CARRIED_SATCHEL_ITEM_FROM_PED(ped);
	}

	static void LUA_NATIVE_STATS__STAT_DONATE_INCREMENT_ITEM(int item, int slot, Any p2, Any p3)
	{
		STATS::_STAT_DONATE_INCREMENT_ITEM(item, slot, p2, p3);
	}

	static void LUA_NATIVE_STATS__0x8312F09C56149A8A(Hash animalType)
	{
		STATS::_0x8312F09C56149A8A(animalType);
	}

	static void LUA_NATIVE_STATS__0x378D3B1B11D9385B(int p0)
	{
		STATS::_0x378D3B1B11D9385B(p0);
	}

	static void LUA_NATIVE_STATS__0xDA26263C07CCE9C2(int p0)
	{
		STATS::_0xDA26263C07CCE9C2(p0);
	}

	static void LUA_NATIVE_STATS__0xD64DBC8B0424135F(Ped ped, Hash animalType)
	{
		STATS::_0xD64DBC8B0424135F(ped, animalType);
	}

	static void LUA_NATIVE_STATS__0xA59590050F80FF2E(Any p0, bool p1, bool p2, bool p3)
	{
		STATS::_0xA59590050F80FF2E(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_STATS__STAT_ADD_ANIMAL_SAMPLE_TARGET(Hash animalType)
	{
		STATS::_STAT_ADD_ANIMAL_SAMPLE_TARGET(animalType);
	}

	static void LUA_NATIVE_STATS__0xF8181B5EF156862C(Ped ped)
	{
		STATS::_0xF8181B5EF156862C(ped);
	}

	static void LUA_NATIVE_STATS_STAT_ADD_BOUNTY_TARGET(Hash unlockHash, Ped ped)
	{
		STATS::STAT_ADD_BOUNTY_TARGET(unlockHash, ped);
	}

	static void LUA_NATIVE_STATS__0x8C889E4CBB4B2356(Any p0, Ped ped)
	{
		STATS::_0x8C889E4CBB4B2356(p0, ped);
	}

	static void LUA_NATIVE_STATS_STAT_BOUNTY_CAPTURED(Entity entity)
	{
		STATS::STAT_BOUNTY_CAPTURED(entity);
	}

	static void LUA_NATIVE_STATS__0xA596890CF55B5095(Ped ped, bool p1)
	{
		STATS::_0xA596890CF55B5095(ped, p1);
	}

	static void LUA_NATIVE_STATS_STAT_BOUNTY_ESCAPED(Ped ped)
	{
		STATS::STAT_BOUNTY_ESCAPED(ped);
	}

	static void LUA_NATIVE_STATS__0xF21A5D66874FCEDD(Any p0, Hash p1, Hash p2)
	{
		STATS::_0xF21A5D66874FCEDD(p0, p1, p2);
	}

	static void LUA_NATIVE_STATS__0x3EB2791A1FBC8A42(Hash statItem, int p1)
	{
		STATS::_0x3EB2791A1FBC8A42(statItem, p1);
	}

	static void LUA_NATIVE_STATS__0xDF95DF488A645CE7()
	{
		STATS::_0xDF95DF488A645CE7();
	}

	static void LUA_NATIVE_STATS_STAT_PHOTOGRAPH_TAKEN(ItemSet itemset)
	{
		STATS::STAT_PHOTOGRAPH_TAKEN(itemset);
	}

	static void LUA_NATIVE_STATS__0xBE66B26B6529E943(Hash unlockHash, Ped ped, Hash animalType)
	{
		STATS::_0xBE66B26B6529E943(unlockHash, ped, animalType);
	}

	static void LUA_NATIVE_STATS__0xF2B5ABDE09958689(Hash unlockHash, Ped ped1, Ped ped2)
	{
		STATS::_0xF2B5ABDE09958689(unlockHash, ped1, ped2);
	}

	static void LUA_NATIVE_STATS_STAT_REGISTER_LEGENDARY_ANIMAL_DEED(Hash deedHash)
	{
		STATS::STAT_REGISTER_LEGENDARY_ANIMAL_DEED(deedHash);
	}

	static std::tuple<bool, int> LUA_NATIVE_STATS__0x302E71C1D9EE75B9(uintptr_t statId, Hash p1, int p2)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)STATS::_0x302E71C1D9EE75B9((Any*)statId, p1, &p2);
		std::get<1>(return_values) = p2;

		return return_values;
	}

	static bool LUA_NATIVE_STATS_STATSTRACKER_IS_INITIALIZED(Hash p0)
	{
		auto retval = (bool)STATS::STATSTRACKER_IS_INITIALIZED(p0);
		return retval;
	}

	static void LUA_NATIVE_STATS__0x6123E2832C34243D(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		STATS::_0x6123E2832C34243D(p0, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_STATS__0xCA41E86545413B5B(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6)
	{
		STATS::_0xCA41E86545413B5B(p0, p1, p2, p3, p4, p5, p6);
	}

	static void LUA_NATIVE_STATS_STATSTRACKER_DEED_STARTED(Hash p0, Any p1)
	{
		STATS::STATSTRACKER_DEED_STARTED(p0, p1);
	}

	static void LUA_NATIVE_STATS__STATSTRACKER_DEED_STATUS(int deedType, Hash deedHash, int missionStatus, uintptr_t data)
	{
		STATS::_STATSTRACKER_DEED_STATUS(deedType, deedHash, missionStatus, (Any*)data);
	}

	static void LUA_NATIVE_STATS__0x99230691875FC218(Any p0, Hash p1, float x, float y, float z)
	{
		STATS::_0x99230691875FC218(p0, p1, x, y, z);
	}

	static void LUA_NATIVE_STATS__0x025E98E317652CDD(int p0)
	{
		STATS::_0x025E98E317652CDD(p0);
	}

	static void LUA_NATIVE_STATS__0xE5A680A5D8B1F687(int p0)
	{
		STATS::_0xE5A680A5D8B1F687(p0);
	}

	static bool LUA_NATIVE_STATS__0x4DAC398297981B87(int p0)
	{
		auto retval = (bool)STATS::_0x4DAC398297981B87(p0);
		return retval;
	}

	static bool LUA_NATIVE_STATS_CHAL_IS_GOAL_ACTIVE(Hash chalHash, Hash goalHash)
	{
		auto retval = (bool)STATS::CHAL_IS_GOAL_ACTIVE(chalHash, goalHash);
		return retval;
	}

	static void LUA_NATIVE_STATS_CHAL_SET_GOAL_DISABLED(Hash chalHash, Hash goalHash, bool disabled)
	{
		STATS::CHAL_SET_GOAL_DISABLED(chalHash, goalHash, disabled);
	}

	static int LUA_NATIVE_STATS_CHAL_GET_NUM_RANKS_COMPLETED(Hash chalHash)
	{
		auto retval = STATS::CHAL_GET_NUM_RANKS_COMPLETED(chalHash);
		return retval;
	}

	static int LUA_NATIVE_STATS_CHAL_GET_MAX_RANKS(Hash chalHash)
	{
		auto retval = STATS::CHAL_GET_MAX_RANKS(chalHash);
		return retval;
	}

	static void LUA_NATIVE_STATS_CHAL_ADD_GOAL_PROGRESS_INT(Hash chalHash, Hash goalHash, int value)
	{
		STATS::CHAL_ADD_GOAL_PROGRESS_INT(chalHash, goalHash, value);
	}

	static void LUA_NATIVE_STATS_CHAL_ADD_GOAL_PROGRESS_FLOAT(Hash chalHash, Hash goalHash, float value)
	{
		STATS::CHAL_ADD_GOAL_PROGRESS_FLOAT(chalHash, goalHash, value);
	}

	static void LUA_NATIVE_STATS_CHAL_SET_GOAL_PROGRESS_INT(Hash chalHash, Hash goalHash, int value)
	{
		STATS::CHAL_SET_GOAL_PROGRESS_INT(chalHash, goalHash, value);
	}

	static void LUA_NATIVE_STATS_CHAL_ADD_GOAL_PROGRESS_INT_BY_SCORE_ID(Hash p0, int value)
	{
		STATS::CHAL_ADD_GOAL_PROGRESS_INT_BY_SCORE_ID(p0, value);
	}

	static void LUA_NATIVE_STATS_CHAL_ADD_GOAL_PROGRESS_FLOAT_BY_SCORE_ID(Hash p0, float value)
	{
		STATS::CHAL_ADD_GOAL_PROGRESS_FLOAT_BY_SCORE_ID(p0, value);
	}

	static bool LUA_NATIVE_STATS_CHAL_ACHIEVEMENT_IS_COMPLETE(Hash p0, Hash p1)
	{
		auto retval = (bool)STATS::CHAL_ACHIEVEMENT_IS_COMPLETE(p0, p1);
		return retval;
	}

	static int LUA_NATIVE_STATS_CHAL_ACHIEVEMENT_GET_PROGRESS_INT(Hash p0, Hash p1)
	{
		auto retval = STATS::CHAL_ACHIEVEMENT_GET_PROGRESS_INT(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_STATS_CHAL_NET_START_CHAL(Hash chalHash)
	{
		STATS::CHAL_NET_START_CHAL(chalHash);
	}

	static void LUA_NATIVE_STATS_CHAL_NET_STOP_CHAL(Hash chalHash)
	{
		STATS::CHAL_NET_STOP_CHAL(chalHash);
	}

	static void LUA_NATIVE_STATS_CHAL_NET_START_GOAL(Hash chalHash, Hash goalHash)
	{
		STATS::CHAL_NET_START_GOAL(chalHash, goalHash);
	}

	static void LUA_NATIVE_STATS_CHAL_NET_STOP_GOAL(Hash chalHash, Hash goalHash)
	{
		STATS::CHAL_NET_STOP_GOAL(chalHash, goalHash);
	}

	static int LUA_NATIVE_STATS__0xDDBD560745B1EE98(Hash chalHash, Hash goalHash, Player player)
	{
		auto retval = STATS::_0xDDBD560745B1EE98(chalHash, goalHash, player);
		return retval;
	}

	static const char* LUA_NATIVE_STATS__0xB112B9262EC29C20(Hash p0, int p1)
	{
		auto retval = STATS::_0xB112B9262EC29C20(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_STATS__0x4FCBCC0584CD08E9(Hash p0)
	{
		STATS::_0x4FCBCC0584CD08E9(p0);
	}

	static bool LUA_NATIVE_STATS__0xCA1F0B5103936891(Hash p0)
	{
		auto retval = (bool)STATS::_0xCA1F0B5103936891(p0);
		return retval;
	}

	static Hash LUA_NATIVE_STATS__0x8BA3D7B1E83EF803(Hash p0)
	{
		auto retval = STATS::_0x8BA3D7B1E83EF803(p0);
		return retval;
	}

	static int LUA_NATIVE_STATS_CHAL_MISSION_GET_NUM_GOALS(Hash missionHash)
	{
		auto retval = STATS::CHAL_MISSION_GET_NUM_GOALS(missionHash);
		return retval;
	}

	static int LUA_NATIVE_STATS_CHAL_MISSION_GET_NUM_GOALS_COMPLETE(Hash missionHash)
	{
		auto retval = STATS::CHAL_MISSION_GET_NUM_GOALS_COMPLETE(missionHash);
		return retval;
	}

	static bool LUA_NATIVE_STATS_CHAL_MISSION_IS_GOAL_COMPLETE(Hash missionHash, Hash goalHash)
	{
		auto retval = (bool)STATS::CHAL_MISSION_IS_GOAL_COMPLETE(missionHash, goalHash);
		return retval;
	}

	static void LUA_NATIVE_STATS_CHAL_MISSION_ADD_GOAL_PROGRESS_INT(Hash missionHash, Hash goalHash, int value)
	{
		STATS::CHAL_MISSION_ADD_GOAL_PROGRESS_INT(missionHash, goalHash, value);
	}

	static float LUA_NATIVE_STATS__0x9D0F5D2E1951CD84()
	{
		auto retval = STATS::_0x9D0F5D2E1951CD84();
		return retval;
	}

	static void LUA_NATIVE_STATS__0x218F7710A139D012()
	{
		STATS::_0x218F7710A139D012();
	}

	static bool LUA_NATIVE_STATS__0x3AEABAE3F3C7600C()
	{
		auto retval = (bool)STATS::_0x3AEABAE3F3C7600C();
		return retval;
	}

	static const char* LUA_NATIVE_STATS__0x3F6FD87D2030ADC6()
	{
		auto retval = STATS::_0x3F6FD87D2030ADC6();
		return retval;
	}

	static Any LUA_NATIVE_STATS__0xA2E2BEA4E83F6270(Hash p0)
	{
		auto retval = STATS::_0xA2E2BEA4E83F6270(p0);
		return retval;
	}

	static std::tuple<bool, Hash> LUA_NATIVE_STATS__0xB5E2EDA2135E0FA1(Hash p0, int p1, Hash scheduleLocation)
	{
		std::tuple<bool, Hash> return_values;
		std::get<0>(return_values) = (bool)STATS::_0xB5E2EDA2135E0FA1(p0, p1, &scheduleLocation);
		std::get<1>(return_values) = scheduleLocation;

		return return_values;
	}

	static int LUA_NATIVE_STATS_WEEKLY_COLLECTIBLE_GET_NUM_SETS(Hash chalHash)
	{
		auto retval = STATS::WEEKLY_COLLECTIBLE_GET_NUM_SETS(chalHash);
		return retval;
	}

	static Hash LUA_NATIVE_STATS_WEEKLY_COLLECTIBLE_GET_ITEM_SET_BUY_AWARD(Hash chalHash, int index)
	{
		auto retval = STATS::WEEKLY_COLLECTIBLE_GET_ITEM_SET_BUY_AWARD(chalHash, index);
		return retval;
	}

	static Hash LUA_NATIVE_STATS_WEEKLY_COLLECTIBLE_GET_ITEM_SET_LABEL(Hash chalHash, int index)
	{
		auto retval = STATS::WEEKLY_COLLECTIBLE_GET_ITEM_SET_LABEL(chalHash, index);
		return retval;
	}

	static int LUA_NATIVE_STATS_WEEKLY_COLLECTIBLE_GET_NUM_ITEMS_IN_SET(Hash chalHash, int index)
	{
		auto retval = STATS::WEEKLY_COLLECTIBLE_GET_NUM_ITEMS_IN_SET(chalHash, index);
		return retval;
	}

	static std::tuple<bool, Hash, int> LUA_NATIVE_STATS_WEEKLY_COLLECTIBLE_GET_ITEM_IN_SET(Hash chalHash, int setIndex, int itemIndex, Hash p3, int p4)
	{
		std::tuple<bool, Hash, int> return_values;
		std::get<0>(return_values) = (bool)STATS::WEEKLY_COLLECTIBLE_GET_ITEM_IN_SET(chalHash, setIndex, itemIndex, &p3, &p4);
		std::get<1>(return_values) = p3;
		std::get<2>(return_values) = p4;

		return return_values;
	}

	static void LUA_NATIVE_STATS__0x4F2D5FA23DB992DE()
	{
		STATS::_0x4F2D5FA23DB992DE();
	}

	static void LUA_NATIVE_STATS__0x4E463A3CDEFFFE96()
	{
		STATS::_0x4E463A3CDEFFFE96();
	}

	void RegisterNatives_STATS(sol::state& L)
	{
		auto STATS = L["STATS"].get_or_create<sol::table>();
		STATS.set_function("STAT_ID_IS_VALID", LUA_NATIVE_STATS_STAT_ID_IS_VALID);
		STATS.set_function("STAT_ID_SET_INT", LUA_NATIVE_STATS_STAT_ID_SET_INT);
		STATS.set_function("STAT_ID_SET_FLOAT", LUA_NATIVE_STATS_STAT_ID_SET_FLOAT);
		STATS.set_function("STAT_ID_SET_BOOL", LUA_NATIVE_STATS_STAT_ID_SET_BOOL);
		STATS.set_function("STAT_ID_SET_GXT_LABEL", LUA_NATIVE_STATS_STAT_ID_SET_GXT_LABEL);
		STATS.set_function("STAT_ID_SET_DATE", LUA_NATIVE_STATS_STAT_ID_SET_DATE);
		STATS.set_function("STAT_ID_GET_INT", LUA_NATIVE_STATS_STAT_ID_GET_INT);
		STATS.set_function("STAT_ID_GET_FLOAT", LUA_NATIVE_STATS_STAT_ID_GET_FLOAT);
		STATS.set_function("STAT_ID_GET_BOOL", LUA_NATIVE_STATS_STAT_ID_GET_BOOL);
		STATS.set_function("STAT_ID_GET_DATE", LUA_NATIVE_STATS_STAT_ID_GET_DATE);
		STATS.set_function("_0x0FEE2561120F3333", LUA_NATIVE_STATS__0x0FEE2561120F3333);
		STATS.set_function("_STAT_ID_INCREMENT_INT", LUA_NATIVE_STATS__STAT_ID_INCREMENT_INT);
		STATS.set_function("_STAT_ID_INCREMENT_FLOAT", LUA_NATIVE_STATS__STAT_ID_INCREMENT_FLOAT);
		STATS.set_function("_STAT_ID_DECREMENT_INT", LUA_NATIVE_STATS__STAT_ID_DECREMENT_INT);
		STATS.set_function("_0x91A4F58E01ED5E4C", LUA_NATIVE_STATS__0x91A4F58E01ED5E4C);
		STATS.set_function("_0xE141F6B40B1E3683", LUA_NATIVE_STATS__0xE141F6B40B1E3683);
		STATS.set_function("STAT_ID_SET_TO_POSSE_ID", LUA_NATIVE_STATS_STAT_ID_SET_TO_POSSE_ID);
		STATS.set_function("_STAT_CALCULATE_COOLDOWN", LUA_NATIVE_STATS__STAT_CALCULATE_COOLDOWN);
		STATS.set_function("_STAT_PHEROMONE_COOLDOWN_LEGENDARY_ANIMAL", LUA_NATIVE_STATS__STAT_PHEROMONE_COOLDOWN_LEGENDARY_ANIMAL);
		STATS.set_function("_STAT_ITEM_FISH_CAUGHT", LUA_NATIVE_STATS__STAT_ITEM_FISH_CAUGHT);
		STATS.set_function("_STAT_CARRIED_SATCHEL_ITEM_FROM_PED", LUA_NATIVE_STATS__STAT_CARRIED_SATCHEL_ITEM_FROM_PED);
		STATS.set_function("_STAT_DONATE_INCREMENT_ITEM", LUA_NATIVE_STATS__STAT_DONATE_INCREMENT_ITEM);
		STATS.set_function("_0x8312F09C56149A8A", LUA_NATIVE_STATS__0x8312F09C56149A8A);
		STATS.set_function("_0x378D3B1B11D9385B", LUA_NATIVE_STATS__0x378D3B1B11D9385B);
		STATS.set_function("_0xDA26263C07CCE9C2", LUA_NATIVE_STATS__0xDA26263C07CCE9C2);
		STATS.set_function("_0xD64DBC8B0424135F", LUA_NATIVE_STATS__0xD64DBC8B0424135F);
		STATS.set_function("_0xA59590050F80FF2E", LUA_NATIVE_STATS__0xA59590050F80FF2E);
		STATS.set_function("_STAT_ADD_ANIMAL_SAMPLE_TARGET", LUA_NATIVE_STATS__STAT_ADD_ANIMAL_SAMPLE_TARGET);
		STATS.set_function("_0xF8181B5EF156862C", LUA_NATIVE_STATS__0xF8181B5EF156862C);
		STATS.set_function("STAT_ADD_BOUNTY_TARGET", LUA_NATIVE_STATS_STAT_ADD_BOUNTY_TARGET);
		STATS.set_function("_0x8C889E4CBB4B2356", LUA_NATIVE_STATS__0x8C889E4CBB4B2356);
		STATS.set_function("STAT_BOUNTY_CAPTURED", LUA_NATIVE_STATS_STAT_BOUNTY_CAPTURED);
		STATS.set_function("_0xA596890CF55B5095", LUA_NATIVE_STATS__0xA596890CF55B5095);
		STATS.set_function("STAT_BOUNTY_ESCAPED", LUA_NATIVE_STATS_STAT_BOUNTY_ESCAPED);
		STATS.set_function("_0xF21A5D66874FCEDD", LUA_NATIVE_STATS__0xF21A5D66874FCEDD);
		STATS.set_function("_0x3EB2791A1FBC8A42", LUA_NATIVE_STATS__0x3EB2791A1FBC8A42);
		STATS.set_function("_0xDF95DF488A645CE7", LUA_NATIVE_STATS__0xDF95DF488A645CE7);
		STATS.set_function("STAT_PHOTOGRAPH_TAKEN", LUA_NATIVE_STATS_STAT_PHOTOGRAPH_TAKEN);
		STATS.set_function("_0xBE66B26B6529E943", LUA_NATIVE_STATS__0xBE66B26B6529E943);
		STATS.set_function("_0xF2B5ABDE09958689", LUA_NATIVE_STATS__0xF2B5ABDE09958689);
		STATS.set_function("STAT_REGISTER_LEGENDARY_ANIMAL_DEED", LUA_NATIVE_STATS_STAT_REGISTER_LEGENDARY_ANIMAL_DEED);
		STATS.set_function("_0x302E71C1D9EE75B9", LUA_NATIVE_STATS__0x302E71C1D9EE75B9);
		STATS.set_function("STATSTRACKER_IS_INITIALIZED", LUA_NATIVE_STATS_STATSTRACKER_IS_INITIALIZED);
		STATS.set_function("_0x6123E2832C34243D", LUA_NATIVE_STATS__0x6123E2832C34243D);
		STATS.set_function("_0xCA41E86545413B5B", LUA_NATIVE_STATS__0xCA41E86545413B5B);
		STATS.set_function("STATSTRACKER_DEED_STARTED", LUA_NATIVE_STATS_STATSTRACKER_DEED_STARTED);
		STATS.set_function("_STATSTRACKER_DEED_STATUS", LUA_NATIVE_STATS__STATSTRACKER_DEED_STATUS);
		STATS.set_function("_0x99230691875FC218", LUA_NATIVE_STATS__0x99230691875FC218);
		STATS.set_function("_0x025E98E317652CDD", LUA_NATIVE_STATS__0x025E98E317652CDD);
		STATS.set_function("_0xE5A680A5D8B1F687", LUA_NATIVE_STATS__0xE5A680A5D8B1F687);
		STATS.set_function("_0x4DAC398297981B87", LUA_NATIVE_STATS__0x4DAC398297981B87);
		STATS.set_function("CHAL_IS_GOAL_ACTIVE", LUA_NATIVE_STATS_CHAL_IS_GOAL_ACTIVE);
		STATS.set_function("CHAL_SET_GOAL_DISABLED", LUA_NATIVE_STATS_CHAL_SET_GOAL_DISABLED);
		STATS.set_function("CHAL_GET_NUM_RANKS_COMPLETED", LUA_NATIVE_STATS_CHAL_GET_NUM_RANKS_COMPLETED);
		STATS.set_function("CHAL_GET_MAX_RANKS", LUA_NATIVE_STATS_CHAL_GET_MAX_RANKS);
		STATS.set_function("CHAL_ADD_GOAL_PROGRESS_INT", LUA_NATIVE_STATS_CHAL_ADD_GOAL_PROGRESS_INT);
		STATS.set_function("CHAL_ADD_GOAL_PROGRESS_FLOAT", LUA_NATIVE_STATS_CHAL_ADD_GOAL_PROGRESS_FLOAT);
		STATS.set_function("CHAL_SET_GOAL_PROGRESS_INT", LUA_NATIVE_STATS_CHAL_SET_GOAL_PROGRESS_INT);
		STATS.set_function("CHAL_ADD_GOAL_PROGRESS_INT_BY_SCORE_ID", LUA_NATIVE_STATS_CHAL_ADD_GOAL_PROGRESS_INT_BY_SCORE_ID);
		STATS.set_function("CHAL_ADD_GOAL_PROGRESS_FLOAT_BY_SCORE_ID", LUA_NATIVE_STATS_CHAL_ADD_GOAL_PROGRESS_FLOAT_BY_SCORE_ID);
		STATS.set_function("CHAL_ACHIEVEMENT_IS_COMPLETE", LUA_NATIVE_STATS_CHAL_ACHIEVEMENT_IS_COMPLETE);
		STATS.set_function("CHAL_ACHIEVEMENT_GET_PROGRESS_INT", LUA_NATIVE_STATS_CHAL_ACHIEVEMENT_GET_PROGRESS_INT);
		STATS.set_function("CHAL_NET_START_CHAL", LUA_NATIVE_STATS_CHAL_NET_START_CHAL);
		STATS.set_function("CHAL_NET_STOP_CHAL", LUA_NATIVE_STATS_CHAL_NET_STOP_CHAL);
		STATS.set_function("CHAL_NET_START_GOAL", LUA_NATIVE_STATS_CHAL_NET_START_GOAL);
		STATS.set_function("CHAL_NET_STOP_GOAL", LUA_NATIVE_STATS_CHAL_NET_STOP_GOAL);
		STATS.set_function("_0xDDBD560745B1EE98", LUA_NATIVE_STATS__0xDDBD560745B1EE98);
		STATS.set_function("_0xB112B9262EC29C20", LUA_NATIVE_STATS__0xB112B9262EC29C20);
		STATS.set_function("_0x4FCBCC0584CD08E9", LUA_NATIVE_STATS__0x4FCBCC0584CD08E9);
		STATS.set_function("_0xCA1F0B5103936891", LUA_NATIVE_STATS__0xCA1F0B5103936891);
		STATS.set_function("_0x8BA3D7B1E83EF803", LUA_NATIVE_STATS__0x8BA3D7B1E83EF803);
		STATS.set_function("CHAL_MISSION_GET_NUM_GOALS", LUA_NATIVE_STATS_CHAL_MISSION_GET_NUM_GOALS);
		STATS.set_function("CHAL_MISSION_GET_NUM_GOALS_COMPLETE", LUA_NATIVE_STATS_CHAL_MISSION_GET_NUM_GOALS_COMPLETE);
		STATS.set_function("CHAL_MISSION_IS_GOAL_COMPLETE", LUA_NATIVE_STATS_CHAL_MISSION_IS_GOAL_COMPLETE);
		STATS.set_function("CHAL_MISSION_ADD_GOAL_PROGRESS_INT", LUA_NATIVE_STATS_CHAL_MISSION_ADD_GOAL_PROGRESS_INT);
		STATS.set_function("_0x9D0F5D2E1951CD84", LUA_NATIVE_STATS__0x9D0F5D2E1951CD84);
		STATS.set_function("_0x218F7710A139D012", LUA_NATIVE_STATS__0x218F7710A139D012);
		STATS.set_function("_0x3AEABAE3F3C7600C", LUA_NATIVE_STATS__0x3AEABAE3F3C7600C);
		STATS.set_function("_0x3F6FD87D2030ADC6", LUA_NATIVE_STATS__0x3F6FD87D2030ADC6);
		STATS.set_function("_0xA2E2BEA4E83F6270", LUA_NATIVE_STATS__0xA2E2BEA4E83F6270);
		STATS.set_function("_0xB5E2EDA2135E0FA1", LUA_NATIVE_STATS__0xB5E2EDA2135E0FA1);
		STATS.set_function("WEEKLY_COLLECTIBLE_GET_NUM_SETS", LUA_NATIVE_STATS_WEEKLY_COLLECTIBLE_GET_NUM_SETS);
		STATS.set_function("WEEKLY_COLLECTIBLE_GET_ITEM_SET_BUY_AWARD", LUA_NATIVE_STATS_WEEKLY_COLLECTIBLE_GET_ITEM_SET_BUY_AWARD);
		STATS.set_function("WEEKLY_COLLECTIBLE_GET_ITEM_SET_LABEL", LUA_NATIVE_STATS_WEEKLY_COLLECTIBLE_GET_ITEM_SET_LABEL);
		STATS.set_function("WEEKLY_COLLECTIBLE_GET_NUM_ITEMS_IN_SET", LUA_NATIVE_STATS_WEEKLY_COLLECTIBLE_GET_NUM_ITEMS_IN_SET);
		STATS.set_function("WEEKLY_COLLECTIBLE_GET_ITEM_IN_SET", LUA_NATIVE_STATS_WEEKLY_COLLECTIBLE_GET_ITEM_IN_SET);
		STATS.set_function("_0x4F2D5FA23DB992DE", LUA_NATIVE_STATS__0x4F2D5FA23DB992DE);
		STATS.set_function("_0x4E463A3CDEFFFE96", LUA_NATIVE_STATS__0x4E463A3CDEFFFE96);
	}
}
