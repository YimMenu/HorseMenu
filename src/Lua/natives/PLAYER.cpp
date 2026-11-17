#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static Ped LUA_NATIVE_PLAYER_GET_PLAYER_PED(Player PlayerIndex)
	{
		auto retval = PLAYER::GET_PLAYER_PED(PlayerIndex);
		return retval;
	}

	static Ped LUA_NATIVE_PLAYER__GET_PLAYER_PED_2(Player player)
	{
		auto retval = PLAYER::_GET_PLAYER_PED_2(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x325434C68358D282(bool toggle)
	{
		PLAYER::_0x325434C68358D282(toggle);
	}

	static Ped LUA_NATIVE_PLAYER_GET_PLAYER_PED_SCRIPT_INDEX(Player PlayerIndex)
	{
		auto retval = PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_MODEL(Player PlayerIndex, Hash PlayerModelHashKey, bool p2)
	{
		PLAYER::SET_PLAYER_MODEL(PlayerIndex, PlayerModelHashKey, p2);
	}

	static bool LUA_NATIVE_PLAYER__NETWORK_HAS_PLAYER_VALID_PED(Player player)
	{
		auto retval = (bool)PLAYER::_NETWORK_HAS_PLAYER_VALID_PED(player);
		return retval;
	}

	static int LUA_NATIVE_PLAYER_GET_PLAYER_TEAM(Player PlayerIndex)
	{
		auto retval = PLAYER::GET_PLAYER_TEAM(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_TEAM(Player PlayerIndex, int Team, bool bRestrictToThisScript)
	{
		PLAYER::SET_PLAYER_TEAM(PlayerIndex, Team, bRestrictToThisScript);
	}

	static const char* LUA_NATIVE_PLAYER_GET_PLAYER_NAME(Player PlayerIndex)
	{
		auto retval = PLAYER::GET_PLAYER_NAME(PlayerIndex);
		return retval;
	}

	static const char* LUA_NATIVE_PLAYER__FORMAT_PLAYER_NAME_STRING(sol::stack_object string)
	{
		auto retval = PLAYER::_FORMAT_PLAYER_NAME_STRING(string.is<const char*>() ? string.as<const char*>() : nullptr);
		return retval;
	}

	static float LUA_NATIVE_PLAYER_GET_WANTED_LEVEL_RADIUS(int WantedLevel)
	{
		auto retval = PLAYER::GET_WANTED_LEVEL_RADIUS(WantedLevel);
		return retval;
	}

	static int LUA_NATIVE_PLAYER_GET_WANTED_LEVEL_THRESHOLD(int wantedLevel)
	{
		auto retval = PLAYER::GET_WANTED_LEVEL_THRESHOLD(wantedLevel);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_WANTED_LEVEL(Player PlayerIndex, int WantedLevel, bool bDelayLawResponse)
	{
		PLAYER::SET_PLAYER_WANTED_LEVEL(PlayerIndex, WantedLevel, bDelayLawResponse);
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_WANTED_LEVEL_GREATER(Player PlayerIndex, int WantedLevel)
	{
		auto retval = (bool)PLAYER::IS_PLAYER_WANTED_LEVEL_GREATER(PlayerIndex, WantedLevel);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_CLEAR_PLAYER_WANTED_LEVEL(Player PlayerIndex)
	{
		PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PlayerIndex);
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_DEAD(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::IS_PLAYER_DEAD(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_CONTROL(Player iPlayerIndex, bool bSetControlOn, int iFlags, bool bPreventHeadingChange)
	{
		PLAYER::SET_PLAYER_CONTROL(iPlayerIndex, bSetControlOn, iFlags, bPreventHeadingChange);
	}

	static int LUA_NATIVE_PLAYER_GET_PLAYER_WANTED_LEVEL(Player PlayerIndex)
	{
		auto retval = PLAYER::GET_PLAYER_WANTED_LEVEL(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_SET_MAX_WANTED_LEVEL(int NewMaxLevel)
	{
		PLAYER::SET_MAX_WANTED_LEVEL(NewMaxLevel);
	}

	static void LUA_NATIVE_PLAYER__SET_MAX_WANTED_LEVEL_2(int maxWantedLevel)
	{
		PLAYER::_SET_MAX_WANTED_LEVEL_2(maxWantedLevel);
	}

	static void LUA_NATIVE_PLAYER_SET_POLICE_RADAR_BLIPS(bool bBlips)
	{
		PLAYER::SET_POLICE_RADAR_BLIPS(bBlips);
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_PLAYING(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::IS_PLAYER_PLAYING(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_SET_EVERYONE_IGNORE_PLAYER(Player PlayerIndex, bool IgnorePlayer)
	{
		PLAYER::SET_EVERYONE_IGNORE_PLAYER(PlayerIndex, IgnorePlayer);
	}

	static bool LUA_NATIVE_PLAYER_GET_IS_PLAYER_UI_PROMPT_ACTIVE(Player player, int p1)
	{
		auto retval = (bool)PLAYER::GET_IS_PLAYER_UI_PROMPT_ACTIVE(player, p1);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__MODIFY_PLAYER_UI_PROMPT(Player player, int promptType, int promptMode, bool disabled)
	{
		PLAYER::_MODIFY_PLAYER_UI_PROMPT(player, promptType, promptMode, disabled);
	}

	static bool LUA_NATIVE_PLAYER__GET_PLAYER_UI_PROMPT_IS_DISABLED(Player player, int promptType, int promptMode)
	{
		auto retval = (bool)PLAYER::_GET_PLAYER_UI_PROMPT_IS_DISABLED(player, promptType, promptMode);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__MODIFY_PLAYER_UI_PROMPT_FOR_PED(Player player, Ped ped, int promptType, int promptMode, bool enabled)
	{
		PLAYER::_MODIFY_PLAYER_UI_PROMPT_FOR_PED(player, ped, promptType, promptMode, enabled);
	}

	static bool LUA_NATIVE_PLAYER__GET_PLAYER_UI_PROMPT_FOR_PED_IS_ENABLED(Player player, Ped ped, int promptType, int promptMode)
	{
		auto retval = (bool)PLAYER::_GET_PLAYER_UI_PROMPT_FOR_PED_IS_ENABLED(player, ped, promptType, promptMode);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x93624B36E8851B42(Player player)
	{
		PLAYER::_0x93624B36E8851B42(player);
	}

	static void LUA_NATIVE_PLAYER__0x9073EC5456651A90(Any p0, Any p1)
	{
		PLAYER::_0x9073EC5456651A90(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0x2E67707BEC52CA4B(Any p0)
	{
		PLAYER::_0x2E67707BEC52CA4B(p0);
	}

	static void LUA_NATIVE_PLAYER_SET_ALL_RANDOM_PEDS_FLEE(Player PlayerIndex, bool PedsFlee)
	{
		PLAYER::SET_ALL_RANDOM_PEDS_FLEE(PlayerIndex, PedsFlee);
	}

	static void LUA_NATIVE_PLAYER_SET_ALL_RANDOM_PEDS_FLEE_THIS_FRAME(Player PlayerIndex)
	{
		PLAYER::SET_ALL_RANDOM_PEDS_FLEE_THIS_FRAME(PlayerIndex);
	}

	static void LUA_NATIVE_PLAYER_SET_ALL_NEUTRAL_RANDOM_PEDS_FLEE_THIS_FRAME(Player PlayerIndex)
	{
		PLAYER::SET_ALL_NEUTRAL_RANDOM_PEDS_FLEE_THIS_FRAME(PlayerIndex);
	}

	static void LUA_NATIVE_PLAYER__0x1D256EED194F5B58(Any p0)
	{
		PLAYER::_0x1D256EED194F5B58(p0);
	}

	static Any LUA_NATIVE_PLAYER__0x5B7B97E99F84138B(Any p0)
	{
		auto retval = PLAYER::_0x5B7B97E99F84138B(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_DISABLE_PLAYER_WANTED_LEVEL(Player player, bool disable)
	{
		PLAYER::_SET_DISABLE_PLAYER_WANTED_LEVEL(player, disable);
	}

	static float LUA_NATIVE_PLAYER__GET_WANTED_LEVEL_MULTIPLIER()
	{
		auto retval = PLAYER::_GET_WANTED_LEVEL_MULTIPLIER();
		return retval;
	}

	static void LUA_NATIVE_PLAYER_SET_WANTED_LEVEL_MULTIPLIER(float Multiplier)
	{
		PLAYER::SET_WANTED_LEVEL_MULTIPLIER(Multiplier);
	}

	static void LUA_NATIVE_PLAYER_RESET_WANTED_LEVEL_DIFFICULTY(Player PlayerIndex)
	{
		PLAYER::RESET_WANTED_LEVEL_DIFFICULTY(PlayerIndex);
	}

	static void LUA_NATIVE_PLAYER_UPDATE_WANTED_POSITION_THIS_FRAME(Player PlayerIndex)
	{
		PLAYER::UPDATE_WANTED_POSITION_THIS_FRAME(PlayerIndex);
	}

	static void LUA_NATIVE_PLAYER_SUPPRESS_WITNESSES_CALLING_POLICE_THIS_FRAME(Player PlayerIndex)
	{
		PLAYER::SUPPRESS_WITNESSES_CALLING_POLICE_THIS_FRAME(PlayerIndex);
	}

	static void LUA_NATIVE_PLAYER_REPORT_POLICE_SPOTTED_PLAYER(Player PlayerIndex)
	{
		PLAYER::REPORT_POLICE_SPOTTED_PLAYER(PlayerIndex);
	}

	static void LUA_NATIVE_PLAYER_SET_LAW_RESPONSE_DELAY_OVERRIDE(float fLawResponseDelay)
	{
		PLAYER::SET_LAW_RESPONSE_DELAY_OVERRIDE(fLawResponseDelay);
	}

	static void LUA_NATIVE_PLAYER_RESET_LAW_RESPONSE_DELAY_OVERRIDE()
	{
		PLAYER::RESET_LAW_RESPONSE_DELAY_OVERRIDE();
	}

	static bool LUA_NATIVE_PLAYER_CAN_PLAYER_START_MISSION(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::CAN_PLAYER_START_MISSION(PlayerIndex);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_READY_FOR_CUTSCENE(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::IS_PLAYER_READY_FOR_CUTSCENE(PlayerIndex);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_TARGETTING_ENTITY(Player PlayerIndex, Entity EntityIndex, bool p2)
	{
		auto retval = (bool)PLAYER::IS_PLAYER_TARGETTING_ENTITY(PlayerIndex, EntityIndex, p2);
		return retval;
	}

	static std::tuple<bool, Entity> LUA_NATIVE_PLAYER_GET_PLAYER_TARGET_ENTITY(Player PlayerIndex, Entity EntityIndex)
	{
		std::tuple<bool, Entity> return_values;
		std::get<0>(return_values) = (bool)PLAYER::GET_PLAYER_TARGET_ENTITY(PlayerIndex, &EntityIndex);
		std::get<1>(return_values) = EntityIndex;

		return return_values;
	}

	static bool LUA_NATIVE_PLAYER__0x927861B2C08DBEA5(Player player)
	{
		auto retval = (bool)PLAYER::_0x927861B2C08DBEA5(player);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER__IS_PLAYER_FREE_FOCUSING(Player player)
	{
		auto retval = (bool)PLAYER::_IS_PLAYER_FREE_FOCUSING(player);
		return retval;
	}

	static std::tuple<bool, Entity> LUA_NATIVE_PLAYER_GET_PLAYER_INTERACTION_TARGET_ENTITY(Player player, Entity outEntity, bool p2, bool p3)
	{
		std::tuple<bool, Entity> return_values;
		std::get<0>(return_values) = (bool)PLAYER::GET_PLAYER_INTERACTION_TARGET_ENTITY(player, &outEntity, p2, p3);
		std::get<1>(return_values) = outEntity;

		return return_values;
	}

	static Any LUA_NATIVE_PLAYER__0xBEA3A6E5F5F79A6F(Any p0, Any p1)
	{
		auto retval = PLAYER::_0xBEA3A6E5F5F79A6F(p0, p1);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER__IS_PLAYER_IN_SCOPE(Player player)
	{
		auto retval = (bool)PLAYER::_IS_PLAYER_IN_SCOPE(player);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_FREE_AIMING(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::IS_PLAYER_FREE_AIMING(PlayerIndex);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_FREE_AIMING_AT_ENTITY(Player PlayerIndex, Entity EntityIndex)
	{
		auto retval = (bool)PLAYER::IS_PLAYER_FREE_AIMING_AT_ENTITY(PlayerIndex, EntityIndex);
		return retval;
	}

	static std::tuple<bool, Entity> LUA_NATIVE_PLAYER_GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(Player PlayerIndex, Entity EntityIndex)
	{
		std::tuple<bool, Entity> return_values;
		std::get<0>(return_values) = (bool)PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(PlayerIndex, &EntityIndex);
		std::get<1>(return_values) = EntityIndex;

		return return_values;
	}

	static void LUA_NATIVE_PLAYER__0x3DAABE78A23694BC(Any p0, Any p1)
	{
		PLAYER::_0x3DAABE78A23694BC(p0, p1);
	}

	static std::tuple<bool, Ped> LUA_NATIVE_PLAYER__0x7AE93C45EC14A166(Player player, Ped ped)
	{
		std::tuple<bool, Ped> return_values;
		std::get<0>(return_values) = (bool)PLAYER::_0x7AE93C45EC14A166(player, &ped);
		std::get<1>(return_values) = ped;

		return return_values;
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_LOCKON_RANGE_OVERRIDE(Player PlayerIndex, float Range)
	{
		PLAYER::SET_PLAYER_LOCKON_RANGE_OVERRIDE(PlayerIndex, Range);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(Player PlayerIndex, bool bCanBeHassled)
	{
		PLAYER::SET_PLAYER_CAN_BE_HASSLED_BY_GANGS(PlayerIndex, bCanBeHassled);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_CAN_USE_COVER(Player PlayerIndex, bool CanUseCover)
	{
		PLAYER::SET_PLAYER_CAN_USE_COVER(PlayerIndex, CanUseCover);
	}

	static void LUA_NATIVE_PLAYER__0xD1A70C1E8D1031FE(Any p0, Any p1)
	{
		PLAYER::_0xD1A70C1E8D1031FE(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0xACA45DDCEF6071C4(Player player, bool p1)
	{
		PLAYER::_0xACA45DDCEF6071C4(player, p1);
	}

	static void LUA_NATIVE_PLAYER__0xA0C683284DF027C7(Player player, int p1, bool enable)
	{
		PLAYER::_0xA0C683284DF027C7(player, p1, enable);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_CAN_MERCY_KILL(Player player, bool toggle)
	{
		PLAYER::_SET_PLAYER_CAN_MERCY_KILL(player, toggle);
	}

	static void LUA_NATIVE_PLAYER__0x4EC8BE63B8A5D4EF(Player player, int p1)
	{
		PLAYER::_0x4EC8BE63B8A5D4EF(player, p1);
	}

	static int LUA_NATIVE_PLAYER_GET_MAX_WANTED_LEVEL()
	{
		auto retval = PLAYER::GET_MAX_WANTED_LEVEL();
		return retval;
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_TARGETTING_ANYTHING(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::IS_PLAYER_TARGETTING_ANYTHING(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_RESTORE_PLAYER_STAMINA(Player PlayerIndex, float fPercent)
	{
		PLAYER::RESTORE_PLAYER_STAMINA(PlayerIndex, fPercent);
	}

	static void LUA_NATIVE_PLAYER__0x8591EE69CC3ED257(Player player, bool toggle)
	{
		PLAYER::_0x8591EE69CC3ED257(player, toggle);
	}

	static int LUA_NATIVE_PLAYER_GET_PLAYER_GROUP(Player PlayerIndex)
	{
		auto retval = PLAYER::GET_PLAYER_GROUP(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x3D9DA5C9EFD20D88(Any p0, Any p1)
	{
		PLAYER::_0x3D9DA5C9EFD20D88(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0x2BEED53B912537D0(Any p0, Any p1, Any p2)
	{
		PLAYER::_0x2BEED53B912537D0(p0, p1, p2);
	}

	static void LUA_NATIVE_PLAYER__0x908D4B72854C8F62(Any p0)
	{
		PLAYER::_0x908D4B72854C8F62(p0);
	}

	static Any LUA_NATIVE_PLAYER__0xD1F6B912785BFD35(Any p0)
	{
		auto retval = PLAYER::_0xD1F6B912785BFD35(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0xC4873B053054C04B(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7)
	{
		PLAYER::_0xC4873B053054C04B(p0, p1, p2, p3, p4, p5, p6, p7);
	}

	static void LUA_NATIVE_PLAYER__0xCA59808E51FD67C4(Any p0, Any p1)
	{
		PLAYER::_0xCA59808E51FD67C4(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0xBA5CA1FEB5DE0DF6(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5)
	{
		PLAYER::_0xBA5CA1FEB5DE0DF6(p0, p1, p2, p3, p4, p5);
	}

	static void LUA_NATIVE_PLAYER__0x0869D499A7848309(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7)
	{
		PLAYER::_0x0869D499A7848309(p0, p1, p2, p3, p4, p5, p6, p7);
	}

	static bool LUA_NATIVE_PLAYER__0xB331D8A73F9D2BDF(Player player, uintptr_t p1)
	{
		auto retval = (bool)PLAYER::_0xB331D8A73F9D2BDF(player, (Any*)p1);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__ADD_PLAYER_AS_FOLLOW_TARGET(Player player, Ped ped, float p2, float p3, int followMode, int followPriority, bool p6)
	{
		PLAYER::_ADD_PLAYER_AS_FOLLOW_TARGET(player, ped, p2, p3, followMode, followPriority, p6);
	}

	static void LUA_NATIVE_PLAYER__REMOVE_PLAYER_AS_FOLLOW_TARGET(Player player, Ped ped)
	{
		PLAYER::_REMOVE_PLAYER_AS_FOLLOW_TARGET(player, ped);
	}

	static void LUA_NATIVE_PLAYER__0x12E09E278C6C29B7(Any p0)
	{
		PLAYER::_0x12E09E278C6C29B7(p0);
	}

	static void LUA_NATIVE_PLAYER__0xDD33A82352C4652F(Player player, Ped ped, int p2)
	{
		PLAYER::_0xDD33A82352C4652F(player, ped, p2);
	}

	static void LUA_NATIVE_PLAYER__0x1FDA57E8908F2609(Player player, Ped ped, bool useSteerassist)
	{
		PLAYER::_0x1FDA57E8908F2609(player, ped, useSteerassist);
	}

	static void LUA_NATIVE_PLAYER__0x84481018E668E1B8(Player player, Ped ped, Any p2)
	{
		PLAYER::_0x84481018E668E1B8(player, ped, p2);
	}

	static bool LUA_NATIVE_PLAYER__0x2009F8AB7A5E9D6D(Player player)
	{
		auto retval = (bool)PLAYER::_0x2009F8AB7A5E9D6D(player);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER__IS_PLAYER_FOLLOWING_TARGET(Player player, Ped ped)
	{
		auto retval = (bool)PLAYER::_IS_PLAYER_FOLLOWING_TARGET(player, ped);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER__0xE7F8707269544B29(Player player, Ped ped)
	{
		auto retval = (bool)PLAYER::_0xE7F8707269544B29(player, ped);
		return retval;
	}

	static Any LUA_NATIVE_PLAYER__0xE631EAF35828FA67(Any p0)
	{
		auto retval = PLAYER::_0xE631EAF35828FA67(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x086549F3B0381CB1(Any p0, Any p1)
	{
		PLAYER::_0x086549F3B0381CB1(p0, p1);
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_CONTROL_ON(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::IS_PLAYER_CONTROL_ON(PlayerIndex);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_SCRIPT_CONTROL_ON(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::IS_PLAYER_SCRIPT_CONTROL_ON(PlayerIndex);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_CLIMBING(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::IS_PLAYER_CLIMBING(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0xEBB6E27AC2FF32DA(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		PLAYER::_0xEBB6E27AC2FF32DA(p0, p1, p2, p3, p4);
	}

	static Any LUA_NATIVE_PLAYER__0xB15CD2F9932C9AB5(Any p0)
	{
		auto retval = PLAYER::_0xB15CD2F9932C9AB5(p0);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER__0x621D1B289CAF5978(Player player)
	{
		auto retval = (bool)PLAYER::_0x621D1B289CAF5978(player);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_BEING_ARRESTED(Player PlayerIndex, bool CheckBustedTask)
	{
		auto retval = (bool)PLAYER::IS_PLAYER_BEING_ARRESTED(PlayerIndex, CheckBustedTask);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_RESET_PLAYER_ARREST_STATE(Player PlayerIndex)
	{
		PLAYER::RESET_PLAYER_ARREST_STATE(PlayerIndex);
	}

	static void LUA_NATIVE_PLAYER__0xCBB54CC7FFFFAB86(Any p0, Any p1, Any p2, Any p3)
	{
		PLAYER::_0xCBB54CC7FFFFAB86(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_PLAYER__0xBED386157F65942C(Any p0, Any p1)
	{
		PLAYER::_0xBED386157F65942C(p0, p1);
	}

	static Any LUA_NATIVE_PLAYER__0xDAB6A2FC56B7DE65(Any p0)
	{
		auto retval = PLAYER::_0xDAB6A2FC56B7DE65(p0);
		return retval;
	}

	static Any LUA_NATIVE_PLAYER__0x0F4EAF69DA41AF43(Any p0)
	{
		auto retval = PLAYER::_0x0F4EAF69DA41AF43(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_BOUNTY_TARGET(Player player, Player target)
	{
		PLAYER::_SET_BOUNTY_TARGET(player, target);
	}

	static void LUA_NATIVE_PLAYER__CLEAR_BOUNTY_TARGET(Player player)
	{
		PLAYER::_CLEAR_BOUNTY_TARGET(player);
	}

	static Vehicle LUA_NATIVE_PLAYER_GET_PLAYERS_LAST_VEHICLE()
	{
		auto retval = PLAYER::GET_PLAYERS_LAST_VEHICLE();
		return retval;
	}

	static Player LUA_NATIVE_PLAYER_GET_PLAYER_INDEX()
	{
		auto retval = PLAYER::GET_PLAYER_INDEX();
		return retval;
	}

	static Player LUA_NATIVE_PLAYER_INT_TO_PLAYERINDEX(int Arg)
	{
		auto retval = PLAYER::INT_TO_PLAYERINDEX(Arg);
		return retval;
	}

	static int LUA_NATIVE_PLAYER_INT_TO_PARTICIPANTINDEX(int Arg)
	{
		auto retval = PLAYER::INT_TO_PARTICIPANTINDEX(Arg);
		return retval;
	}

	static Player LUA_NATIVE_PLAYER_PLAYER_ID()
	{
		auto retval = PLAYER::PLAYER_ID();
		return retval;
	}

	static Ped LUA_NATIVE_PLAYER_PLAYER_PED_ID()
	{
		auto retval = PLAYER::PLAYER_PED_ID();
		return retval;
	}

	static int LUA_NATIVE_PLAYER_NETWORK_PLAYER_ID_TO_INT()
	{
		auto retval = PLAYER::NETWORK_PLAYER_ID_TO_INT();
		return retval;
	}

	static bool LUA_NATIVE_PLAYER_HAS_FORCE_CLEANUP_OCCURRED(int ForceCleanupBitField)
	{
		auto retval = (bool)PLAYER::HAS_FORCE_CLEANUP_OCCURRED(ForceCleanupBitField);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_FORCE_CLEANUP(int ForceCleanupBitField)
	{
		PLAYER::FORCE_CLEANUP(ForceCleanupBitField);
	}

	static void LUA_NATIVE_PLAYER_FORCE_CLEANUP_FOR_ALL_THREADS_WITH_THIS_NAME(sol::stack_object pName, int ForceCleanupBitField)
	{
		PLAYER::FORCE_CLEANUP_FOR_ALL_THREADS_WITH_THIS_NAME(pName.is<const char*>() ? pName.as<const char*>() : nullptr, ForceCleanupBitField);
	}

	static void LUA_NATIVE_PLAYER_FORCE_CLEANUP_FOR_THREAD_WITH_THIS_ID(int Thread_Id, int ForceCleanupBitField)
	{
		PLAYER::FORCE_CLEANUP_FOR_THREAD_WITH_THIS_ID(Thread_Id, ForceCleanupBitField);
	}

	static int LUA_NATIVE_PLAYER_GET_CAUSE_OF_MOST_RECENT_FORCE_CLEANUP()
	{
		auto retval = PLAYER::GET_CAUSE_OF_MOST_RECENT_FORCE_CLEANUP();
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_MOOD(Player player, int mood)
	{
		PLAYER::_SET_PLAYER_MOOD(player, mood);
	}

	static int LUA_NATIVE_PLAYER__GET_PLAYER_MOOD(Player player)
	{
		auto retval = PLAYER::_GET_PLAYER_MOOD(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_MAY_ONLY_ENTER_THIS_VEHICLE(Player PlayerIndex, Vehicle iVehicleID)
	{
		PLAYER::SET_PLAYER_MAY_ONLY_ENTER_THIS_VEHICLE(PlayerIndex, iVehicleID);
	}

	static void LUA_NATIVE_PLAYER__0xC71D07C96946E263(Any p0, Any p1)
	{
		PLAYER::_0xC71D07C96946E263(p0, p1);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_MAY_NOT_ENTER_ANY_VEHICLE(Player PlayerIndex)
	{
		PLAYER::SET_PLAYER_MAY_NOT_ENTER_ANY_VEHICLE(PlayerIndex);
	}

	static bool LUA_NATIVE_PLAYER_IS_SYSTEM_UI_BEING_DISPLAYED()
	{
		auto retval = (bool)PLAYER::IS_SYSTEM_UI_BEING_DISPLAYED();
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0xD48227263E3D06AE(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9)
	{
		PLAYER::_0xD48227263E3D06AE(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	}

	static void LUA_NATIVE_PLAYER__0x3946FC742AC305CD(Player player, Ped ped, sol::stack_object p2, float x, float y, float z, Entity targetEntity, sol::stack_object p7)
	{
		PLAYER::_0x3946FC742AC305CD(player, ped, p2.is<const char*>() ? p2.as<const char*>() : nullptr, x, y, z, targetEntity, p7.is<const char*>() ? p7.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PLAYER__0xA28056CD1B04B250(Any p0, Any p1, Any p2, Any p3, Any p4, Any p5, Any p6, Any p7, Any p8, Any p9, Any p10)
	{
		PLAYER::_0xA28056CD1B04B250(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
	}

	static void LUA_NATIVE_PLAYER__0xC67A4910425F11F1(Player player, sol::stack_object name)
	{
		PLAYER::_0xC67A4910425F11F1(player, name.is<const char*>() ? name.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_INVINCIBLE(Player PlayerIndex, bool Invincible)
	{
		PLAYER::SET_PLAYER_INVINCIBLE(PlayerIndex, Invincible);
	}

	static bool LUA_NATIVE_PLAYER_GET_PLAYER_INVINCIBLE(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::GET_PLAYER_INVINCIBLE(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_LOCKON(Player PlayerIndex, bool bActive)
	{
		PLAYER::SET_PLAYER_LOCKON(PlayerIndex, bActive);
	}

	static void LUA_NATIVE_PLAYER_SET_LOCKON_TO_FRIENDLY_PLAYERS(Player player, bool toggle)
	{
		PLAYER::SET_LOCKON_TO_FRIENDLY_PLAYERS(player, toggle);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_TARGETING_MODE(int TargetMode)
	{
		PLAYER::SET_PLAYER_TARGETING_MODE(TargetMode);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_IN_VEHICLE_TARGETING_MODE(int targetMode)
	{
		PLAYER::_SET_PLAYER_IN_VEHICLE_TARGETING_MODE(targetMode);
	}

	static Any LUA_NATIVE_PLAYER__0x747257807B8721CE(Any p0, Any p1)
	{
		auto retval = PLAYER::_0x747257807B8721CE(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_PLAYER__0x8702D9150D9FBB3D(Any p0, Any p1)
	{
		auto retval = PLAYER::_0x8702D9150D9FBB3D(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0xCB0B9506BC91E441(Any p0, Any p1)
	{
		PLAYER::_0xCB0B9506BC91E441(p0, p1);
	}

	static void LUA_NATIVE_PLAYER_CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_PED(Player PlayerIndex)
	{
		PLAYER::CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_PED(PlayerIndex);
	}

	static bool LUA_NATIVE_PLAYER_HAS_PLAYER_DAMAGED_AT_LEAST_ONE_PED(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::HAS_PLAYER_DAMAGED_AT_LEAST_ONE_PED(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_NON_ANIMAL_PED(Player PlayerIndex)
	{
		PLAYER::CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_NON_ANIMAL_PED(PlayerIndex);
	}

	static bool LUA_NATIVE_PLAYER_HAS_PLAYER_DAMAGED_AT_LEAST_ONE_NON_ANIMAL_PED(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::HAS_PLAYER_DAMAGED_AT_LEAST_ONE_NON_ANIMAL_PED(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0xEACEBAAE0A33FB3F(Any p0)
	{
		PLAYER::_0xEACEBAAE0A33FB3F(p0);
	}

	static bool LUA_NATIVE_PLAYER__0x72AD59F7B7FB6E24(Player player, int p1)
	{
		auto retval = (bool)PLAYER::_0x72AD59F7B7FB6E24(player, p1);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER__0x1A6E84F13C952094(Player player, int p1, uintptr_t p2)
	{
		auto retval = (bool)PLAYER::_0x1A6E84F13C952094(player, p1, (Any*)p2);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_DAMAGE_INFO_OVERRIDE(Player player, sol::stack_object damageInfo)
	{
		PLAYER::_SET_PLAYER_DAMAGE_INFO_OVERRIDE(player, damageInfo.is<const char*>() ? damageInfo.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PLAYER__0x1F488807BC8E0630(Player player)
	{
		PLAYER::_0x1F488807BC8E0630(player);
	}

	static void LUA_NATIVE_PLAYER_SET_AIR_DRAG_MULTIPLIER_FOR_PLAYERS_VEHICLE(Player PlayerIndex, float fDragMult)
	{
		PLAYER::SET_AIR_DRAG_MULTIPLIER_FOR_PLAYERS_VEHICLE(PlayerIndex, fDragMult);
	}

	static void LUA_NATIVE_PLAYER_SET_SWIM_MULTIPLIER_FOR_PLAYER(Player PlayerIndex, float fMultiplier)
	{
		PLAYER::SET_SWIM_MULTIPLIER_FOR_PLAYER(PlayerIndex, fMultiplier);
	}

	static bool LUA_NATIVE_PLAYER__0x73EB2EF2E92D23BF()
	{
		auto retval = (bool)PLAYER::_0x73EB2EF2E92D23BF();
		return retval;
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_FORCED_AIM(Player PlayerIndex, bool ForcedAim, Ped ped, int p3, bool p4)
	{
		PLAYER::SET_PLAYER_FORCED_AIM(PlayerIndex, ForcedAim, ped, p3, p4);
	}

	static void LUA_NATIVE_PLAYER__0x310CE349E0C0EC4B(Player player, Ped ped, int p2)
	{
		PLAYER::_0x310CE349E0C0EC4B(player, ped, p2);
	}

	static void LUA_NATIVE_PLAYER_DISABLE_PLAYER_FIRING(Player PlayerIndex, bool disable)
	{
		PLAYER::DISABLE_PLAYER_FIRING(PlayerIndex, disable);
	}

	static void LUA_NATIVE_PLAYER__0xEBFF94328FF7A18A(Any p0, Any p1)
	{
		PLAYER::_0xEBFF94328FF7A18A(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0xF993373285053D77(Any p0, Any p1, Any p2)
	{
		PLAYER::_0xF993373285053D77(p0, p1, p2);
	}

	static Any LUA_NATIVE_PLAYER__0xE956C2340A76272E(Any p0)
	{
		auto retval = PLAYER::_0xE956C2340A76272E(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__ENABLE_CUSTOM_DEADEYE_ABILITY(Player player, bool enable)
	{
		PLAYER::_ENABLE_CUSTOM_DEADEYE_ABILITY(player, enable);
	}

	static Any LUA_NATIVE_PLAYER__0xDE6C85975F9D4894(Any p0)
	{
		auto retval = PLAYER::_0xDE6C85975F9D4894(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0xBBA140062B15A8AC(Player player)
	{
		PLAYER::_0xBBA140062B15A8AC(player);
	}

	static void LUA_NATIVE_PLAYER__SPECIAL_ABILITY_SET_DISABLED(Player player, bool disabled)
	{
		PLAYER::_SPECIAL_ABILITY_SET_DISABLED(player, disabled);
	}

	static bool LUA_NATIVE_PLAYER__IS_SPECIAL_ABILITY_ACTIVE(Player player)
	{
		auto retval = (bool)PLAYER::_IS_SPECIAL_ABILITY_ACTIVE(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__MODIFY_INFINITE_TRAIL_VISION(Player player, bool toggle)
	{
		PLAYER::_MODIFY_INFINITE_TRAIL_VISION(player, toggle);
	}

	static void LUA_NATIVE_PLAYER__SPECIAL_ABILITY_SET_EAGLE_EYE_DISABLED(Player player)
	{
		PLAYER::_SPECIAL_ABILITY_SET_EAGLE_EYE_DISABLED(player);
	}

	static void LUA_NATIVE_PLAYER__SPECIAL_ABILITY_RESTORE_BY_AMOUNT(Player player, float amount, int p2, int p3, int p4)
	{
		PLAYER::_SPECIAL_ABILITY_RESTORE_BY_AMOUNT(player, amount, p2, p3, p4);
	}

	static void LUA_NATIVE_PLAYER__0xFA437FA0738C370C(Player player, float p1, int p2, int p3, int p4)
	{
		PLAYER::_0xFA437FA0738C370C(player, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_PLAYER__SPECIAL_ABILITY_RESTORE_OUTER_RING(Player player, float amount)
	{
		PLAYER::_SPECIAL_ABILITY_RESTORE_OUTER_RING(player, amount);
	}

	static float LUA_NATIVE_PLAYER__GET_PLAYER_REQUIRED_DEAD_EYE_AMOUNT(Player player)
	{
		auto retval = PLAYER::_GET_PLAYER_REQUIRED_DEAD_EYE_AMOUNT(player);
		return retval;
	}

	static float LUA_NATIVE_PLAYER__SPECIAL_ABILITY_GET_AMOUNT_CACHED(Player player)
	{
		auto retval = PLAYER::_SPECIAL_ABILITY_GET_AMOUNT_CACHED(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SPECIAL_ABILITY_DRAIN_BY_AMOUNT(Player player, float amount, Any p2)
	{
		PLAYER::_SPECIAL_ABILITY_DRAIN_BY_AMOUNT(player, amount, p2);
	}

	static void LUA_NATIVE_PLAYER__SPECIAL_ABILITY_START_RESTORE(Player player, int p1, bool p2)
	{
		PLAYER::_SPECIAL_ABILITY_START_RESTORE(player, p1, p2);
	}

	static void LUA_NATIVE_PLAYER__SET_SPECIAL_ABILITY_MULTIPLIER(Player player, float multiplier)
	{
		PLAYER::_SET_SPECIAL_ABILITY_MULTIPLIER(player, multiplier);
	}

	static float LUA_NATIVE_PLAYER__GET_PLAYER_SPECIAL_ABILITY_MULTIPLIER(Player player)
	{
		auto retval = PLAYER::_GET_PLAYER_SPECIAL_ABILITY_MULTIPLIER(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_SPECIAL_ABILITY_TYPE(Player player, int type)
	{
		PLAYER::_SET_SPECIAL_ABILITY_TYPE(player, type);
	}

	static void LUA_NATIVE_PLAYER__0x22B3CABEDDB538B2(Player player, float p1)
	{
		PLAYER::_0x22B3CABEDDB538B2(player, p1);
	}

	static void LUA_NATIVE_PLAYER__SET_SPECIAL_ABILITY_DURATION_COST(Player player, float durationCost)
	{
		PLAYER::_SET_SPECIAL_ABILITY_DURATION_COST(player, durationCost);
	}

	static void LUA_NATIVE_PLAYER__SET_SPECIAL_ABILITY_DISABLE_TIMER(Player player, float timer)
	{
		PLAYER::_SET_SPECIAL_ABILITY_DISABLE_TIMER(player, timer);
	}

	static Any LUA_NATIVE_PLAYER__0x57D9991DC1334151(Any p0)
	{
		auto retval = PLAYER::_0x57D9991DC1334151(p0);
		return retval;
	}

	static Any LUA_NATIVE_PLAYER__0x21091B4BEB6376EE(Any p0)
	{
		auto retval = PLAYER::_0x21091B4BEB6376EE(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_SPECIAL_ABILITY_ACTIVATION_COST(Player player, float activationCost, int p2)
	{
		PLAYER::_SET_SPECIAL_ABILITY_ACTIVATION_COST(player, activationCost, p2);
	}

	static void LUA_NATIVE_PLAYER__0x4D1699543B1C023C(Player player, float p1)
	{
		PLAYER::_0x4D1699543B1C023C(player, p1);
	}

	static float LUA_NATIVE_PLAYER__GET_PLAYER_DEAD_EYE_METER_LEVEL(Player player, bool p1)
	{
		auto retval = PLAYER::_GET_PLAYER_DEAD_EYE_METER_LEVEL(player, p1);
		return retval;
	}

	static float LUA_NATIVE_PLAYER__GET_PLAYER_DEAD_EYE(Player player)
	{
		auto retval = PLAYER::_GET_PLAYER_DEAD_EYE(player);
		return retval;
	}

	static float LUA_NATIVE_PLAYER__GET_PLAYER_CACHED_DEAD_EYE_AMOUNT(Player player)
	{
		auto retval = PLAYER::_GET_PLAYER_CACHED_DEAD_EYE_AMOUNT(player);
		return retval;
	}

	static float LUA_NATIVE_PLAYER__GET_PLAYER_MAX_DEAD_EYE(Player player, Any p1)
	{
		auto retval = PLAYER::_GET_PLAYER_MAX_DEAD_EYE(player, p1);
		return retval;
	}

	static float LUA_NATIVE_PLAYER__GET_PLAYER_HEALTH(Player player)
	{
		auto retval = PLAYER::_GET_PLAYER_HEALTH(player);
		return retval;
	}

	static float LUA_NATIVE_PLAYER__GET_PLAYER_STAMINA(Player player)
	{
		auto retval = PLAYER::_GET_PLAYER_STAMINA(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_STAT_FLAG_HASH(Player player, Hash p1)
	{
		PLAYER::_SET_PLAYER_STAT_FLAG_HASH(player, p1);
	}

	static void LUA_NATIVE_PLAYER__SET_USED_ITEM_EFFECT(float health, float stamina, float deadeye, int healthCore, int staminaCore, int deadeyeCore)
	{
		PLAYER::_SET_USED_ITEM_EFFECT(health, stamina, deadeye, healthCore, staminaCore, deadeyeCore);
	}

	static void LUA_NATIVE_PLAYER__0x08E22898A6AF4905(Any p0, Any p1)
	{
		PLAYER::_0x08E22898A6AF4905(p0, p1);
	}

	static Any LUA_NATIVE_PLAYER__0xBEFED69CE8317F91(Any p0)
	{
		auto retval = PLAYER::_0xBEFED69CE8317F91(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__ENABLE_EAGLEEYE(Player player, bool enable)
	{
		PLAYER::_ENABLE_EAGLEEYE(player, enable);
	}

	static bool LUA_NATIVE_PLAYER__IS_SECONDARY_SPECIAL_ABILITY_ENABLED(Player player)
	{
		auto retval = (bool)PLAYER::_IS_SECONDARY_SPECIAL_ABILITY_ENABLED(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SECONDARY_SPECIAL_ABILITY_SET_ACTIVE(Player player)
	{
		PLAYER::_SECONDARY_SPECIAL_ABILITY_SET_ACTIVE(player);
	}

	static void LUA_NATIVE_PLAYER__SECONDARY_SPECIAL_ABILITY_SET_DISABLED(Player player, bool disabled)
	{
		PLAYER::_SECONDARY_SPECIAL_ABILITY_SET_DISABLED(player, disabled);
	}

	static bool LUA_NATIVE_PLAYER__IS_SECONDARY_SPECIAL_ABILITY_ACTIVE(Player player)
	{
		auto retval = (bool)PLAYER::_IS_SECONDARY_SPECIAL_ABILITY_ACTIVE(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x107F2A66E1C4C83A(Any p0)
	{
		PLAYER::_0x107F2A66E1C4C83A(p0);
	}

	static void LUA_NATIVE_PLAYER_START_PLAYER_TELEPORT(Player PlayerIndex, float VecCoorsX, float VecCoorsY, float VecCoorsZ, float heading, bool p5, bool p6, bool p7, bool p8)
	{
		PLAYER::START_PLAYER_TELEPORT(PlayerIndex, VecCoorsX, VecCoorsY, VecCoorsZ, heading, p5, p6, p7, p8);
	}

	static void LUA_NATIVE_PLAYER__0x2C2D287748E8E9B7(bool p0)
	{
		PLAYER::_0x2C2D287748E8E9B7(p0);
	}

	static bool LUA_NATIVE_PLAYER_UPDATE_PLAYER_TELEPORT(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::UPDATE_PLAYER_TELEPORT(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_STOP_PLAYER_TELEPORT()
	{
		PLAYER::STOP_PLAYER_TELEPORT();
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_TELEPORT_ACTIVE()
	{
		auto retval = (bool)PLAYER::IS_PLAYER_TELEPORT_ACTIVE();
		return retval;
	}

	static float LUA_NATIVE_PLAYER_GET_PLAYER_CURRENT_STEALTH_NOISE(Player PlayerIndex)
	{
		auto retval = PLAYER::GET_PLAYER_CURRENT_STEALTH_NOISE(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_HEALTH_RECHARGE_MULTIPLIER(Player PlayerIndex, float Mult)
	{
		PLAYER::SET_PLAYER_HEALTH_RECHARGE_MULTIPLIER(PlayerIndex, Mult);
	}

	static float LUA_NATIVE_PLAYER__GET_PLAYER_HEALTH_RECHARGE_MULTIPLIER(Player player)
	{
		auto retval = PLAYER::_GET_PLAYER_HEALTH_RECHARGE_MULTIPLIER(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_HEALTH_RECHARGE_TIME_MODIFIER(Player player, float modifier)
	{
		PLAYER::_SET_PLAYER_HEALTH_RECHARGE_TIME_MODIFIER(player, modifier);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_STAMINA_RECHARGE_MULTIPLIER(Player player, float multiplier)
	{
		PLAYER::SET_PLAYER_STAMINA_RECHARGE_MULTIPLIER(player, multiplier);
	}

	static float LUA_NATIVE_PLAYER__GET_PLAYER_STAMINA_RECHARGE_MULTIPLIER(Player player)
	{
		auto retval = PLAYER::_GET_PLAYER_STAMINA_RECHARGE_MULTIPLIER(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_STAMINA_SPRINT_DEPLETION_MULTIPLIER(Player player, float multiplier)
	{
		PLAYER::_SET_PLAYER_STAMINA_SPRINT_DEPLETION_MULTIPLIER(player, multiplier);
	}

	static float LUA_NATIVE_PLAYER__GET_PLAYER_STAMINA_DEPLETION_MULTIPLIER(Player player)
	{
		auto retval = PLAYER::_GET_PLAYER_STAMINA_DEPLETION_MULTIPLIER(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_PED_ACTIVE_PLAYER_HORSE(Player player, Ped horse)
	{
		PLAYER::_SET_PED_ACTIVE_PLAYER_HORSE(player, horse);
	}

	static Ped LUA_NATIVE_PLAYER__GET_ACTIVE_HORSE_FOR_PLAYER(Player player)
	{
		auto retval = PLAYER::_GET_ACTIVE_HORSE_FOR_PLAYER(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_PED_AS_SADDLE_HORSE_FOR_PLAYER(Player player, Ped mount)
	{
		PLAYER::_SET_PED_AS_SADDLE_HORSE_FOR_PLAYER(player, mount);
	}

	static Ped LUA_NATIVE_PLAYER__GET_SADDLE_HORSE_FOR_PLAYER(Player player)
	{
		auto retval = PLAYER::_GET_SADDLE_HORSE_FOR_PLAYER(player);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER_SET_PED_AS_TEMP_PLAYER_HORSE(Player player, Ped horse)
	{
		auto retval = (bool)PLAYER::SET_PED_AS_TEMP_PLAYER_HORSE(player, horse);
		return retval;
	}

	static Ped LUA_NATIVE_PLAYER__GET_TEMP_PLAYER_HORSE(Player player)
	{
		auto retval = PLAYER::_GET_TEMP_PLAYER_HORSE(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x77B0B6D17A3AC9AA(Any p0, Any p1)
	{
		PLAYER::_0x77B0B6D17A3AC9AA(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_MOUNT_STATE_ACTIVE(Player player, bool active)
	{
		PLAYER::_SET_PLAYER_MOUNT_STATE_ACTIVE(player, active);
	}

	static void LUA_NATIVE_PLAYER__0x694FFA4308060CD1(Any p0, Any p1)
	{
		PLAYER::_0x694FFA4308060CD1(p0, p1);
	}

	static void LUA_NATIVE_PLAYER_BOOST_PLAYER_HORSE_SPEED_FOR_TIME(Player player, float speedBoost, int duration)
	{
		PLAYER::BOOST_PLAYER_HORSE_SPEED_FOR_TIME(player, speedBoost, duration);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_WEAPON_DAMAGE_MODIFIER(Player PlayerIndex, float Modifier)
	{
		PLAYER::SET_PLAYER_WEAPON_DAMAGE_MODIFIER(PlayerIndex, Modifier);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_WEAPON_DEFENSE_MODIFIER(Player PlayerIndex, float Modifier)
	{
		PLAYER::SET_PLAYER_WEAPON_DEFENSE_MODIFIER(PlayerIndex, Modifier);
	}

	static void LUA_NATIVE_PLAYER__0x818241B3EDA84191(Player player, bool p1)
	{
		PLAYER::_0x818241B3EDA84191(player, p1);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(Player PlayerIndex, float Modifier)
	{
		PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(PlayerIndex, Modifier);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_EXPLOSIVE_WEAPON_DAMAGE_MODIFIER(Player player, float modifier)
	{
		PLAYER::_SET_PLAYER_EXPLOSIVE_WEAPON_DAMAGE_MODIFIER(player, modifier);
	}

	static void LUA_NATIVE_PLAYER__0x83C989D5B5B5B466(Any p0, Any p1)
	{
		PLAYER::_0x83C989D5B5B5B466(p0, p1);
	}

	static Any LUA_NATIVE_PLAYER__0x03B4B759A8990505(Any p0)
	{
		auto retval = PLAYER::_0x03B4B759A8990505(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x67659A8F248E0141(Any p0, Any p1)
	{
		PLAYER::_0x67659A8F248E0141(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__SET_RECEIVED_HORSEBACK_DAMAGE_DECREASE(Player player, float damageDecrease)
	{
		PLAYER::_SET_RECEIVED_HORSEBACK_DAMAGE_DECREASE(player, damageDecrease);
	}

	static void LUA_NATIVE_PLAYER__SET_AI_PLAYER_DEFENSE_MODIFIER_AGAINST_AI(Player player, float modifier)
	{
		PLAYER::_SET_AI_PLAYER_DEFENSE_MODIFIER_AGAINST_AI(player, modifier);
	}

	static float LUA_NATIVE_PLAYER__GET_AI_PLAYER_DEFENSE_MODIFIER_AGAINST_AI(Player player)
	{
		auto retval = PLAYER::_GET_AI_PLAYER_DEFENSE_MODIFIER_AGAINST_AI(player);
		return retval;
	}

	static Any LUA_NATIVE_PLAYER__0x19B2C7A6C34FAD54(Any p0, Any p1)
	{
		auto retval = PLAYER::_0x19B2C7A6C34FAD54(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_PLAYER__0x9422743A5BA50E10(Any p0)
	{
		auto retval = PLAYER::_0x9422743A5BA50E10(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_DEFENSE_MODIFIER(Player player, float weaponDefenseMod, float meleeDefenseMod)
	{
		PLAYER::_SET_PLAYER_DEFENSE_MODIFIER(player, weaponDefenseMod, meleeDefenseMod);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_DEFENSE_TYPE_MODIFIER(Player player, int type, float defenseModifier)
	{
		PLAYER::_SET_PLAYER_DEFENSE_TYPE_MODIFIER(player, type, defenseModifier);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_WEAPON_TYPE_DAMAGE_MODIFIER(Player player, Hash weaponHash, float damageModifier)
	{
		PLAYER::SET_PLAYER_WEAPON_TYPE_DAMAGE_MODIFIER(player, weaponHash, damageModifier);
	}

	static float LUA_NATIVE_PLAYER__GET_PLAYER_WEAPON_DAMAGE(Player player, Hash weaponHash)
	{
		auto retval = PLAYER::_GET_PLAYER_WEAPON_DAMAGE(player, weaponHash);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x5C2E5E3CAEEB1F58(Any p0, Any p1, Any p2)
	{
		PLAYER::_0x5C2E5E3CAEEB1F58(p0, p1, p2);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_WEAPON_GROUP_DAMAGE_MODIFIER(Player player, Hash weaponGroup, float modifier)
	{
		PLAYER::_SET_PLAYER_WEAPON_GROUP_DAMAGE_MODIFIER(player, weaponGroup, modifier);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_WEAPON_GROUP_AS_INSTANT_KILL(Player player, Hash weaponGroup, bool toggle)
	{
		PLAYER::_SET_PLAYER_WEAPON_GROUP_AS_INSTANT_KILL(player, weaponGroup, toggle);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_TRAMPLE_DAMAGE_MODIFIER(Player player, float modifier)
	{
		PLAYER::_SET_PLAYER_TRAMPLE_DAMAGE_MODIFIER(player, modifier);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_LASSO_DAMAGE_PER_SECOND(Player player, float damage)
	{
		PLAYER::_SET_PLAYER_LASSO_DAMAGE_PER_SECOND(player, damage);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_TOTAL_ACCURACY_MODIFIER(Player player, float accuracy)
	{
		PLAYER::_SET_PLAYER_TOTAL_ACCURACY_MODIFIER(player, accuracy);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_LOCAL_ACCURACY_FLOOR_MODIFIER(Player player, float accuracy)
	{
		PLAYER::_SET_PLAYER_LOCAL_ACCURACY_FLOOR_MODIFIER(player, accuracy);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_REMOTE_ACCURACY_FLOOR_MODIFIER(Player player, float accuracy)
	{
		PLAYER::_SET_PLAYER_REMOTE_ACCURACY_FLOOR_MODIFIER(player, accuracy);
	}

	static void LUA_NATIVE_PLAYER__0x3AD212429E095EFB(Any p0, Any p1)
	{
		PLAYER::_0x3AD212429E095EFB(p0, p1);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_NOISE_MULTIPLIER(Player PlayerIndex, float Mult)
	{
		PLAYER::SET_PLAYER_NOISE_MULTIPLIER(PlayerIndex, Mult);
	}

	static void LUA_NATIVE_PLAYER__0x113EF458AB6CDA67(Any p0, Any p1)
	{
		PLAYER::_0x113EF458AB6CDA67(p0, p1);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_SNEAKING_NOISE_MULTIPLIER(Player PlayerIndex, float Mult)
	{
		PLAYER::SET_PLAYER_SNEAKING_NOISE_MULTIPLIER(PlayerIndex, Mult);
	}

	static void LUA_NATIVE_PLAYER_SIMULATE_PLAYER_INPUT_GAIT(Player playerIdx, float moveBlendRatio, int timer, float heading, bool useRelativeHeading, bool noInputInterruption)
	{
		PLAYER::SIMULATE_PLAYER_INPUT_GAIT(playerIdx, moveBlendRatio, timer, heading, useRelativeHeading, noInputInterruption);
	}

	static void LUA_NATIVE_PLAYER_RESET_PLAYER_INPUT_GAIT(Player playerIdx)
	{
		PLAYER::RESET_PLAYER_INPUT_GAIT(playerIdx);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_SIMULATE_AIMING(Player PlayerIndex, bool SimulateAiming)
	{
		PLAYER::SET_PLAYER_SIMULATE_AIMING(PlayerIndex, SimulateAiming);
	}

	static void LUA_NATIVE_PLAYER_SET_PLAYER_CLOTH_PIN_FRAMES(Player PlayerIndex, int pinFrames)
	{
		PLAYER::SET_PLAYER_CLOTH_PIN_FRAMES(PlayerIndex, pinFrames);
	}

	static bool LUA_NATIVE_PLAYER_HAS_PLAYER_BEEN_SPOTTED_IN_STOLEN_VEHICLE(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::HAS_PLAYER_BEEN_SPOTTED_IN_STOLEN_VEHICLE(PlayerIndex);
		return retval;
	}

	static bool LUA_NATIVE_PLAYER_GET_PLAYER_RECEIVED_BATTLE_EVENT_RECENTLY(Player PlayerIndex, int nTime, bool bIncludeLocalEvents)
	{
		auto retval = (bool)PLAYER::GET_PLAYER_RECEIVED_BATTLE_EVENT_RECENTLY(PlayerIndex, nTime, bIncludeLocalEvents);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_MOUNT_PROMPT_DISABLED(bool disabled)
	{
		PLAYER::_SET_MOUNT_PROMPT_DISABLED(disabled);
	}

	static bool LUA_NATIVE_PLAYER_IS_PLAYER_RIDING_TRAIN(Player PlayerIndex)
	{
		auto retval = (bool)PLAYER::IS_PLAYER_RIDING_TRAIN(PlayerIndex);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x9AFCF9FE1884BF62(Any p0, Any p1)
	{
		PLAYER::_0x9AFCF9FE1884BF62(p0, p1);
	}

	static Any LUA_NATIVE_PLAYER__0x1E8099F449ABB0BA(Any p0)
	{
		auto retval = PLAYER::_0x1E8099F449ABB0BA(p0);
		return retval;
	}

	static int LUA_NATIVE_PLAYER__GET_DEADEYE_ABILITY_LEVEL(Player player)
	{
		auto retval = PLAYER::_GET_DEADEYE_ABILITY_LEVEL(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_DEADEYE_ABILITY_LEVEL(Player player, int level)
	{
		PLAYER::_SET_DEADEYE_ABILITY_LEVEL(player, level);
	}

	static bool LUA_NATIVE_PLAYER__IS_DEADEYE_ABILITY_LOCKED(Player player, int abilityType)
	{
		auto retval = (bool)PLAYER::_IS_DEADEYE_ABILITY_LOCKED(player, abilityType);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_DEADEYE_ABILITY_LOCKED(Player player, int abilityType, bool toggle)
	{
		PLAYER::_SET_DEADEYE_ABILITY_LOCKED(player, abilityType, toggle);
	}

	static void LUA_NATIVE_PLAYER__SET_DEADEYE_TAGGING_ENABLED(Player player, bool toggle)
	{
		PLAYER::_SET_DEADEYE_TAGGING_ENABLED(player, toggle);
	}

	static bool LUA_NATIVE_PLAYER__GET_IS_DEADEYE_TAGGING_ENABLED(Player player)
	{
		auto retval = (bool)PLAYER::_GET_IS_DEADEYE_TAGGING_ENABLED(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x3C4AE8506638C7E2(Any p0, Any p1)
	{
		PLAYER::_0x3C4AE8506638C7E2(p0, p1);
	}

	static Any LUA_NATIVE_PLAYER__0x51139D8C17B16FBC(Any p0)
	{
		auto retval = PLAYER::_0x51139D8C17B16FBC(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x8F44EBB3BA8F6D44(Any p0, Any p1)
	{
		PLAYER::_0x8F44EBB3BA8F6D44(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__SET_DEADEYE_TAGGING_CONFIG(Player player, int filter)
	{
		PLAYER::_SET_DEADEYE_TAGGING_CONFIG(player, filter);
	}

	static Any LUA_NATIVE_PLAYER__0xE92261BD28C0878F(Any p0)
	{
		auto retval = PLAYER::_0xE92261BD28C0878F(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_DEADEYE_ABILITY_DEPLETION_DELAY(Player player, float delay)
	{
		PLAYER::_SET_DEADEYE_ABILITY_DEPLETION_DELAY(player, delay);
	}

	static Any LUA_NATIVE_PLAYER__0xA54000D4BFD90BDE(Any p0)
	{
		auto retval = PLAYER::_0xA54000D4BFD90BDE(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x6EDB5D08CB03E763(Any p0, Any p1)
	{
		PLAYER::_0x6EDB5D08CB03E763(p0, p1);
	}

	static Any LUA_NATIVE_PLAYER__0x27AD7162D3FED01E(Any p0, Any p1)
	{
		auto retval = PLAYER::_0x27AD7162D3FED01E(p0, p1);
		return retval;
	}

	static int LUA_NATIVE_PLAYER__GET_NUM_MARKED_DEADEYE_TARGETS(Player player)
	{
		auto retval = PLAYER::_GET_NUM_MARKED_DEADEYE_TARGETS(player);
		return retval;
	}

	static Any LUA_NATIVE_PLAYER__0xC93A9A45430D484E(Any p0)
	{
		auto retval = PLAYER::_0xC93A9A45430D484E(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x570A13A4CA2799BB(Player player, bool p1)
	{
		PLAYER::_0x570A13A4CA2799BB(player, p1);
	}

	static void LUA_NATIVE_PLAYER__0x3ACAC8832E77BC93(Player player, bool p1)
	{
		PLAYER::_0x3ACAC8832E77BC93(player, p1);
	}

	static void LUA_NATIVE_PLAYER__0x2B12B6FC8B8772AB(Player player, int p1)
	{
		PLAYER::_0x2B12B6FC8B8772AB(player, p1);
	}

	static void LUA_NATIVE_PLAYER__0xE910932F4B30BE23(Player player)
	{
		PLAYER::_0xE910932F4B30BE23(player);
	}

	static void LUA_NATIVE_PLAYER__0x131E294EF60160DF(Player player, float p1, float p2, float p3, float p4, Any p5)
	{
		PLAYER::_0x131E294EF60160DF(player, p1, p2, p3, p4, p5);
	}

	static void LUA_NATIVE_PLAYER__0x0E9057A9DA78D0F8(Player player, int bitflag)
	{
		PLAYER::_0x0E9057A9DA78D0F8(player, bitflag);
	}

	static void LUA_NATIVE_PLAYER__0x263D69767F76059C(Player player, int p1)
	{
		PLAYER::_0x263D69767F76059C(player, p1);
	}

	static void LUA_NATIVE_PLAYER__REGISTER_EAGLE_EYE_FOR_ENTITY(Player player, Entity entity, bool p2)
	{
		PLAYER::_REGISTER_EAGLE_EYE_FOR_ENTITY(player, entity, p2);
	}

	static void LUA_NATIVE_PLAYER__REGISTER_EAGLE_EYE_TRAILS_FOR_ENTITY(Player player, Entity entity, Any p2)
	{
		PLAYER::_REGISTER_EAGLE_EYE_TRAILS_FOR_ENTITY(player, entity, p2);
	}

	static void LUA_NATIVE_PLAYER__UNREGISTER_EAGLE_EYE_FOR_ENTITY(Player player, Entity entity)
	{
		PLAYER::_UNREGISTER_EAGLE_EYE_FOR_ENTITY(player, entity);
	}

	static void LUA_NATIVE_PLAYER__UNREGISTER_EAGLE_EYE_TRAILS_FOR_ENTITY(Player player, Entity entity, Any p2)
	{
		PLAYER::_UNREGISTER_EAGLE_EYE_TRAILS_FOR_ENTITY(player, entity, p2);
	}

	static void LUA_NATIVE_PLAYER__0xE5D3EB37ABC1EB03(Player player)
	{
		PLAYER::_0xE5D3EB37ABC1EB03(player);
	}

	static bool LUA_NATIVE_PLAYER__IS_EAGLE_EYE_REGISTERED_FOR_ENTITY(Player player, Entity entity)
	{
		auto retval = (bool)PLAYER::_IS_EAGLE_EYE_REGISTERED_FOR_ENTITY(player, entity);
		return retval;
	}

	static Any LUA_NATIVE_PLAYER__0x6852288340B43239(Any p0, Any p1)
	{
		auto retval = PLAYER::_0x6852288340B43239(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_PLAYER__0xE50A67C33514A390(Any p0, Any p1)
	{
		auto retval = PLAYER::_0xE50A67C33514A390(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0xD288E02E364972D2(Any p0, Any p1, Any p2)
	{
		PLAYER::_0xD288E02E364972D2(p0, p1, p2);
	}

	static void LUA_NATIVE_PLAYER__EAGLE_EYE_DISABLE_TRACKING_TRAIL(Entity entity, sol::stack_object trail, Any p2, Any p3)
	{
		PLAYER::_EAGLE_EYE_DISABLE_TRACKING_TRAIL(entity, trail.is<const char*>() ? trail.as<const char*>() : nullptr, p2, p3);
	}

	static void LUA_NATIVE_PLAYER__0x6ECFC621A168424C(Entity entity1, Entity entity2, Any p2, float p3)
	{
		PLAYER::_0x6ECFC621A168424C(entity1, entity2, p2, p3);
	}

	static void LUA_NATIVE_PLAYER__0xDC5E09D012D759C4(Entity entity1, Entity entity2, Any p2)
	{
		PLAYER::_0xDC5E09D012D759C4(entity1, entity2, p2);
	}

	static void LUA_NATIVE_PLAYER__0x00B156AFEBCC5AE0(Any p0)
	{
		PLAYER::_0x00B156AFEBCC5AE0(p0);
	}

	static void LUA_NATIVE_PLAYER__0xC58CE6824E604DEC(Any p0)
	{
		PLAYER::_0xC58CE6824E604DEC(p0);
	}

	static void LUA_NATIVE_PLAYER__0x330CA55A3647FA1C(Any p0, Any p1)
	{
		PLAYER::_0x330CA55A3647FA1C(p0, p1);
	}

	static Any LUA_NATIVE_PLAYER__0xA62BBAAE67A05BB0(Any p0)
	{
		auto retval = PLAYER::_0xA62BBAAE67A05BB0(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__EAGLE_EYE_SET_COLOR(Player player, bool p1, uintptr_t p2)
	{
		PLAYER::_EAGLE_EYE_SET_COLOR(player, p1, (Any*)p2);
	}

	static void LUA_NATIVE_PLAYER__0x22C8B10802301381(Any p0, Any p1)
	{
		PLAYER::_0x22C8B10802301381(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__EAGLE_EYE_SET_DRAIN_RATE_MODIFIER(Player player, float modifier)
	{
		PLAYER::_EAGLE_EYE_SET_DRAIN_RATE_MODIFIER(player, modifier);
	}

	static void LUA_NATIVE_PLAYER__0x06E1FB78B1E59CA5(Ped ped, bool p1)
	{
		PLAYER::_0x06E1FB78B1E59CA5(ped, p1);
	}

	static void LUA_NATIVE_PLAYER__EAGLE_EYE_SET_PLUS_FLAG_DISABLED(Ped ped, bool disabled)
	{
		PLAYER::_EAGLE_EYE_SET_PLUS_FLAG_DISABLED(ped, disabled);
	}

	static Any LUA_NATIVE_PLAYER__0x3813E11A378958A5(Any p0)
	{
		auto retval = PLAYER::_0x3813E11A378958A5(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__EAGLE_EYE_SET_FOCUS_ON_ASSOCIATED_CLUE_TRAIL(Player player, Entity linkedWaypointPed)
	{
		PLAYER::_EAGLE_EYE_SET_FOCUS_ON_ASSOCIATED_CLUE_TRAIL(player, linkedWaypointPed);
	}

	static void LUA_NATIVE_PLAYER__0x0F9CF06986300875(Any p0)
	{
		PLAYER::_0x0F9CF06986300875(p0);
	}

	static void LUA_NATIVE_PLAYER__EAGLE_EYE_SET_TRACKING_UPGRADE(Player player, float p1)
	{
		PLAYER::_EAGLE_EYE_SET_TRACKING_UPGRADE(player, p1);
	}

	static void LUA_NATIVE_PLAYER__EAGLE_EYE_SET_TRACKING_UPGRADE_2(Player player, float p1)
	{
		PLAYER::_EAGLE_EYE_SET_TRACKING_UPGRADE_2(player, p1);
	}

	static Any LUA_NATIVE_PLAYER__0x1DA5C5B0923E1B85(Any p0)
	{
		auto retval = PLAYER::_0x1DA5C5B0923E1B85(p0);
		return retval;
	}

	static Any LUA_NATIVE_PLAYER__0xAAED694CE814817F(Any p0)
	{
		auto retval = PLAYER::_0xAAED694CE814817F(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER_EAGLE_EYE_SET_CUSTOM_ENTITY_TINT(Entity entity, int red, int green, int blue)
	{
		PLAYER::EAGLE_EYE_SET_CUSTOM_ENTITY_TINT(entity, red, green, blue);
	}

	static void LUA_NATIVE_PLAYER__0xBC02B3D151D3859F(Entity entity, Any p1)
	{
		PLAYER::_0xBC02B3D151D3859F(entity, p1);
	}

	static void LUA_NATIVE_PLAYER__EAGLE_EYE_SET_CUSTOM_DISTANCE(Entity entity, float distance)
	{
		PLAYER::_EAGLE_EYE_SET_CUSTOM_DISTANCE(entity, distance);
	}

	static void LUA_NATIVE_PLAYER__0xF21C7A3F3FFBA629(Player player)
	{
		PLAYER::_0xF21C7A3F3FFBA629(player);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_MANAGE_BUFF_SUPER_JUMP(Player player, float p1)
	{
		PLAYER::_SET_PLAYER_MANAGE_BUFF_SUPER_JUMP(player, p1);
	}

	static void LUA_NATIVE_PLAYER__SET_LOCAL_PLAYER_PERSONA_ABILITY_FLAG(int flagId, bool toggle)
	{
		PLAYER::_SET_LOCAL_PLAYER_PERSONA_ABILITY_FLAG(flagId, toggle);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_MAX_AMMO_OVERRIDE_FOR_AMMO_TYPE(Player player, Hash ammoType, int amount)
	{
		PLAYER::_SET_PLAYER_MAX_AMMO_OVERRIDE_FOR_AMMO_TYPE(player, ammoType, amount);
	}

	static void LUA_NATIVE_PLAYER__0xC900A465364A85D6(Player player)
	{
		PLAYER::_0xC900A465364A85D6(player);
	}

	static void LUA_NATIVE_PLAYER__0xCFB2EED4FCB7BD77(Any p0, Any p1, Any p2)
	{
		PLAYER::_0xCFB2EED4FCB7BD77(p0, p1, p2);
	}

	static void LUA_NATIVE_PLAYER__0x2BB8D58E88777499(Any p0)
	{
		PLAYER::_0x2BB8D58E88777499(p0);
	}

	static void LUA_NATIVE_PLAYER__0x00EB5A760638DB55(Any p0, Any p1, Any p2)
	{
		PLAYER::_0x00EB5A760638DB55(p0, p1, p2);
	}

	static void LUA_NATIVE_PLAYER__0x65887EAC535A0B0C(Any p0)
	{
		PLAYER::_0x65887EAC535A0B0C(p0);
	}

	static void LUA_NATIVE_PLAYER__SET_WEAPON_DEGRADATION_MODIFIER(Player player, float modifier)
	{
		PLAYER::_SET_WEAPON_DEGRADATION_MODIFIER(player, modifier);
	}

	static void LUA_NATIVE_PLAYER__SET_BOW_DRAW_REDUCTION_TIME_IN_DEADEYE(Player player, float drawReductionTime)
	{
		PLAYER::_SET_BOW_DRAW_REDUCTION_TIME_IN_DEADEYE(player, drawReductionTime);
	}

	static void LUA_NATIVE_PLAYER__SET_BOW_STAMINA_DRAIN_SPEED(Player player, float staminaDrain)
	{
		PLAYER::_SET_BOW_STAMINA_DRAIN_SPEED(player, staminaDrain);
	}

	static void LUA_NATIVE_PLAYER__SET_DAMAGE_CLOSE_DISTANCE_BONUS(Player player, float closeRangeLowerBound, float closeRangeUpperBound)
	{
		PLAYER::_SET_DAMAGE_CLOSE_DISTANCE_BONUS(player, closeRangeLowerBound, closeRangeUpperBound);
	}

	static void LUA_NATIVE_PLAYER__SET_DAMAGE_CLOSE_DISTANCE_BONUS_TOTAL(Player player, float closeDamageBonus)
	{
		PLAYER::_SET_DAMAGE_CLOSE_DISTANCE_BONUS_TOTAL(player, closeDamageBonus);
	}

	static void LUA_NATIVE_PLAYER__SET_DAMAGE_FAR_DISTANCE_BONUS(Player player, float farRangeLowerBound, float farRangeUpperBound)
	{
		PLAYER::_SET_DAMAGE_FAR_DISTANCE_BONUS(player, farRangeLowerBound, farRangeUpperBound);
	}

	static void LUA_NATIVE_PLAYER__SET_DAMAGE_FAR_DISTANCE_BONUS_TOTAL(Player player, float farDamageBonus)
	{
		PLAYER::_SET_DAMAGE_FAR_DISTANCE_BONUS_TOTAL(player, farDamageBonus);
	}

	static Any LUA_NATIVE_PLAYER__0x6C54E69516CC56BD(Any p0)
	{
		auto retval = PLAYER::_0x6C54E69516CC56BD(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x3A8611BD7BDE84F7(Any p0, Any p1)
	{
		PLAYER::_0x3A8611BD7BDE84F7(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0xC177C827CEFC0AA4(Any p0, Any p1)
	{
		PLAYER::_0xC177C827CEFC0AA4(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0xBD96185264DDAAEA(Any p0, Any p1)
	{
		PLAYER::_0xBD96185264DDAAEA(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0x628E742FE1F79C4A(Any p0, Any p1)
	{
		PLAYER::_0x628E742FE1F79C4A(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_INTERACTION_POSITIVE_RESPONSE(Player player, sol::stack_object speech)
	{
		PLAYER::_SET_PLAYER_INTERACTION_POSITIVE_RESPONSE(player, speech.is<const char*>() ? speech.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_INTERACTION_NEGATIVE_RESPONSE(Player player, sol::stack_object speech)
	{
		PLAYER::_SET_PLAYER_INTERACTION_NEGATIVE_RESPONSE(player, speech.is<const char*>() ? speech.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PLAYER__0x216BC0D3D2E413D2(Player player, Any p1)
	{
		PLAYER::_0x216BC0D3D2E413D2(player, p1);
	}

	static void LUA_NATIVE_PLAYER__0x45EF176B532CA851(Any p0, Any p1)
	{
		PLAYER::_0x45EF176B532CA851(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0xA342495F93B7B838(Any p0, Any p1)
	{
		PLAYER::_0xA342495F93B7B838(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0x3BB84F812E052C90(Any p0)
	{
		PLAYER::_0x3BB84F812E052C90(p0);
	}

	static void LUA_NATIVE_PLAYER__0x9FC5A003FB76EDBD(Any p0, Any p1)
	{
		PLAYER::_0x9FC5A003FB76EDBD(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0x0FAF95D71ED67ADE(Player player, sol::stack_object p1)
	{
		PLAYER::_0x0FAF95D71ED67ADE(player, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PLAYER__0x988C9045531B9FCE(Player player, sol::stack_object p1)
	{
		PLAYER::_0x988C9045531B9FCE(player, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PLAYER__0x06C3DB00B69D5435(Player player, sol::stack_object p1)
	{
		PLAYER::_0x06C3DB00B69D5435(player, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_PLAYER__0xBB6EA5D59E926095(int category, Hash emote)
	{
		PLAYER::_0xBB6EA5D59E926095(category, emote);
	}

	static bool LUA_NATIVE_PLAYER__0xE1D356F5A66D0FFA(Hash emote)
	{
		auto retval = (bool)PLAYER::_0xE1D356F5A66D0FFA(emote);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x929DDD5538F3DF1F(Any p0, Any p1)
	{
		PLAYER::_0x929DDD5538F3DF1F(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0xFA7DAAE3959E6C7B(Any p0, Any p1)
	{
		PLAYER::_0xFA7DAAE3959E6C7B(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0x9461A8FAB0378E5B(Any p0, Any p1)
	{
		PLAYER::_0x9461A8FAB0378E5B(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0xCB61A63AA53D7D22(Any p0, Any p1)
	{
		PLAYER::_0xCB61A63AA53D7D22(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__0xCFFC3ECCD7A5CCEB(Player player, Hash weapon, bool p2)
	{
		PLAYER::_0xCFFC3ECCD7A5CCEB(player, weapon, p2);
	}

	static void LUA_NATIVE_PLAYER__0x76F7E1BCD623A429(Any p0)
	{
		PLAYER::_0x76F7E1BCD623A429(p0);
	}

	static void LUA_NATIVE_PLAYER__0x585CE159DB46FADB(Any p0, Any p1)
	{
		PLAYER::_0x585CE159DB46FADB(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_RESET_FLAG(Player player, int playerResetFlag, bool p2)
	{
		PLAYER::_SET_PLAYER_RESET_FLAG(player, playerResetFlag, p2);
	}

	static bool LUA_NATIVE_PLAYER__GET_PLAYER_RESET_FLAG(Player player, int playerResetFlag)
	{
		auto retval = (bool)PLAYER::_GET_PLAYER_RESET_FLAG(player, playerResetFlag);
		return retval;
	}

	static Ped LUA_NATIVE_PLAYER_GET_MOUNT_OWNED_BY_PLAYER(Player player)
	{
		auto retval = PLAYER::GET_MOUNT_OWNED_BY_PLAYER(player);
		return retval;
	}

	static Player LUA_NATIVE_PLAYER__GET_PLAYER_OWNER_OF_MOUNT(Ped mount)
	{
		auto retval = PLAYER::_GET_PLAYER_OWNER_OF_MOUNT(mount);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_OWNS_MOUNT(Player player, Ped mount)
	{
		PLAYER::_SET_PLAYER_OWNS_MOUNT(player, mount);
	}

	static Vehicle LUA_NATIVE_PLAYER__GET_VEHICLE_OWNED_BY_PLAYER(Player player)
	{
		auto retval = PLAYER::_GET_VEHICLE_OWNED_BY_PLAYER(player);
		return retval;
	}

	static Player LUA_NATIVE_PLAYER__GET_PLAYER_OWNER_OF_VEHICLE(Vehicle vehicle)
	{
		auto retval = PLAYER::_GET_PLAYER_OWNER_OF_VEHICLE(vehicle);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_OWNS_VEHICLE(Player player, Vehicle vehicle)
	{
		PLAYER::_SET_PLAYER_OWNS_VEHICLE(player, vehicle);
	}

	static Vehicle LUA_NATIVE_PLAYER__GET_PLAYER_HUNTING_WAGON(Player player)
	{
		auto retval = PLAYER::_GET_PLAYER_HUNTING_WAGON(player);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_HUNTING_WAGON(Player player, Vehicle wagon)
	{
		PLAYER::_SET_PLAYER_HUNTING_WAGON(player, wagon);
	}

	static void LUA_NATIVE_PLAYER__0x9044835BE9D9DBFE(Any p0, Any p1)
	{
		PLAYER::_0x9044835BE9D9DBFE(p0, p1);
	}

	static std::tuple<Hash, Hash> LUA_NATIVE_PLAYER_GET_DISCOVERABLE_NAME_HASH_AND_TYPE_FOR_ENTITY(Entity entity, Hash type)
	{
		std::tuple<Hash, Hash> return_values;
		std::get<0>(return_values) = PLAYER::GET_DISCOVERABLE_NAME_HASH_AND_TYPE_FOR_ENTITY(entity, &type);
		std::get<1>(return_values) = type;

		return return_values;
	}

	static Hash LUA_NATIVE_PLAYER__GET_CONSTRUCTED_DISCOVERED_CHARACTER_NAME(Hash p0, bool model, bool outfit)
	{
		auto retval = PLAYER::_GET_CONSTRUCTED_DISCOVERED_CHARACTER_NAME(p0, model, outfit);
		return retval;
	}

	static Hash LUA_NATIVE_PLAYER_GET_TARGET_CHARACTER_NAME_SCRIPT_OVERRIDE_HASH(Ped ped)
	{
		auto retval = PLAYER::GET_TARGET_CHARACTER_NAME_SCRIPT_OVERRIDE_HASH(ped);
		return retval;
	}

	static const char* LUA_NATIVE_PLAYER_GET_TARGET_CHARACTER_NAME_SCRIPT_OVERRIDE_RAW_STRING(Ped ped)
	{
		auto retval = PLAYER::GET_TARGET_CHARACTER_NAME_SCRIPT_OVERRIDE_RAW_STRING(ped);
		return retval;
	}

	static Hash LUA_NATIVE_PLAYER_GET_TARGET_CHARACTER_NAME_FOR_LOCAL_PLAYER(Ped ped)
	{
		auto retval = PLAYER::GET_TARGET_CHARACTER_NAME_FOR_LOCAL_PLAYER(ped);
		return retval;
	}

	static Any LUA_NATIVE_PLAYER__0xDA9D7BE231FE865F(Any p0, Any p1, Any p2)
	{
		auto retval = PLAYER::_0xDA9D7BE231FE865F(p0, p1, p2);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_HAS_DISCOVERED_CHARACTER_NAME_SP(Player player, int p1, Hash discoveryHash)
	{
		PLAYER::_SET_PLAYER_HAS_DISCOVERED_CHARACTER_NAME_SP(player, p1, discoveryHash);
	}

	static bool LUA_NATIVE_PLAYER__GET_HAS_PLAYER_DISCOVERED_CHARACTER_NAME_SP(Player player, int p1, Hash discoveryHash)
	{
		auto retval = (bool)PLAYER::_GET_HAS_PLAYER_DISCOVERED_CHARACTER_NAME_SP(player, p1, discoveryHash);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0xCDDD4B74660E2335(Any p0, Any p1, Any p2)
	{
		PLAYER::_0xCDDD4B74660E2335(p0, p1, p2);
	}

	static void LUA_NATIVE_PLAYER__0x77E83C315A3B31CA(Any p0)
	{
		PLAYER::_0x77E83C315A3B31CA(p0);
	}

	static void LUA_NATIVE_PLAYER__SET_PLAYER_HAS_DISCOVERED_CHARACTER_NAME_MP(Hash discoveryHash)
	{
		PLAYER::_SET_PLAYER_HAS_DISCOVERED_CHARACTER_NAME_MP(discoveryHash);
	}

	static bool LUA_NATIVE_PLAYER_GET_HAS_PLAYER_DISCOVERED_CHARACTER_NAME_MP(Hash discoveryHash)
	{
		auto retval = (bool)PLAYER::GET_HAS_PLAYER_DISCOVERED_CHARACTER_NAME_MP(discoveryHash);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__MODIFY_PLAYER_DISCOVERED_CHARACTER_NAME_MP_SET_UNDISCOVERED(Hash discoveryHash)
	{
		PLAYER::_MODIFY_PLAYER_DISCOVERED_CHARACTER_NAME_MP_SET_UNDISCOVERED(discoveryHash);
	}

	static void LUA_NATIVE_PLAYER__SET_SHOW_INFO_CARD(Player player, bool showingInfoCard)
	{
		PLAYER::_SET_SHOW_INFO_CARD(player, showingInfoCard);
	}

	static void LUA_NATIVE_PLAYER__0x4DBC4873707E8FD6(Any p0, Any p1, Any p2, Any p3)
	{
		PLAYER::_0x4DBC4873707E8FD6(p0, p1, p2, p3);
	}

	static void LUA_NATIVE_PLAYER__0xCEDC16930526F728(Any p0)
	{
		PLAYER::_0xCEDC16930526F728(p0);
	}

	static void LUA_NATIVE_PLAYER__0x14E57F88BA0A07FC(Hash location)
	{
		PLAYER::_0x14E57F88BA0A07FC(location);
	}

	static Any LUA_NATIVE_PLAYER__0x2E1ABE627C95ED9B()
	{
		auto retval = PLAYER::_0x2E1ABE627C95ED9B();
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x497A18F8F88AA9D8()
	{
		PLAYER::_0x497A18F8F88AA9D8();
	}

	static void LUA_NATIVE_PLAYER__0x4F0D2256AAE94EDA(int p0)
	{
		PLAYER::_0x4F0D2256AAE94EDA(p0);
	}

	static void LUA_NATIVE_PLAYER__SET_LOCKON_FOCUS_FIRE_VFX(Player player, sol::stack_object p1)
	{
		PLAYER::_SET_LOCKON_FOCUS_FIRE_VFX(player, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
	}

	static Any LUA_NATIVE_PLAYER__0x0B7803F6F7BB43E0()
	{
		auto retval = PLAYER::_0x0B7803F6F7BB43E0();
		return retval;
	}

	static Any LUA_NATIVE_PLAYER__0xC74EB3F2EC169F6B(Any p0)
	{
		auto retval = PLAYER::_0xC74EB3F2EC169F6B(p0);
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x3B296934DB026873(Any p0, Any p1)
	{
		PLAYER::_0x3B296934DB026873(p0, p1);
	}

	static void LUA_NATIVE_PLAYER_SET_MIN_TIME_BEFORE_HORSE_BUCKING(Ped mount, int iMinBuckTime)
	{
		PLAYER::SET_MIN_TIME_BEFORE_HORSE_BUCKING(mount, iMinBuckTime);
	}

	static Any LUA_NATIVE_PLAYER__0xF4CB347D7B5EB0FD()
	{
		auto retval = PLAYER::_0xF4CB347D7B5EB0FD();
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0xCD7CA3013FD12749(Any p0, Any p1)
	{
		PLAYER::_0xCD7CA3013FD12749(p0, p1);
	}

	static void LUA_NATIVE_PLAYER__FORCE_REST_SCENARIO(bool toggle)
	{
		PLAYER::_FORCE_REST_SCENARIO(toggle);
	}

	static bool LUA_NATIVE_PLAYER__0x57028FD99886F6F9()
	{
		auto retval = (bool)PLAYER::_0x57028FD99886F6F9();
		return retval;
	}

	static void LUA_NATIVE_PLAYER__0x35A33783EC3C3448(Any p0)
	{
		PLAYER::_0x35A33783EC3C3448(p0);
	}

	static void LUA_NATIVE_PLAYER__0x39D8D7082BC34B72(Any p0)
	{
		PLAYER::_0x39D8D7082BC34B72(p0);
	}

	static void LUA_NATIVE_PLAYER__0x1AD8AD999C27F44A(Any p0)
	{
		PLAYER::_0x1AD8AD999C27F44A(p0);
	}

	void RegisterNatives_PLAYER(sol::state& L)
	{
		auto PLAYER = L["PLAYER"].get_or_create<sol::table>();
		PLAYER.set_function("GET_PLAYER_PED", LUA_NATIVE_PLAYER_GET_PLAYER_PED);
		PLAYER.set_function("_GET_PLAYER_PED_2", LUA_NATIVE_PLAYER__GET_PLAYER_PED_2);
		PLAYER.set_function("_0x325434C68358D282", LUA_NATIVE_PLAYER__0x325434C68358D282);
		PLAYER.set_function("GET_PLAYER_PED_SCRIPT_INDEX", LUA_NATIVE_PLAYER_GET_PLAYER_PED_SCRIPT_INDEX);
		PLAYER.set_function("SET_PLAYER_MODEL", LUA_NATIVE_PLAYER_SET_PLAYER_MODEL);
		PLAYER.set_function("_NETWORK_HAS_PLAYER_VALID_PED", LUA_NATIVE_PLAYER__NETWORK_HAS_PLAYER_VALID_PED);
		PLAYER.set_function("GET_PLAYER_TEAM", LUA_NATIVE_PLAYER_GET_PLAYER_TEAM);
		PLAYER.set_function("SET_PLAYER_TEAM", LUA_NATIVE_PLAYER_SET_PLAYER_TEAM);
		PLAYER.set_function("GET_PLAYER_NAME", LUA_NATIVE_PLAYER_GET_PLAYER_NAME);
		PLAYER.set_function("_FORMAT_PLAYER_NAME_STRING", LUA_NATIVE_PLAYER__FORMAT_PLAYER_NAME_STRING);
		PLAYER.set_function("GET_WANTED_LEVEL_RADIUS", LUA_NATIVE_PLAYER_GET_WANTED_LEVEL_RADIUS);
		PLAYER.set_function("GET_WANTED_LEVEL_THRESHOLD", LUA_NATIVE_PLAYER_GET_WANTED_LEVEL_THRESHOLD);
		PLAYER.set_function("SET_PLAYER_WANTED_LEVEL", LUA_NATIVE_PLAYER_SET_PLAYER_WANTED_LEVEL);
		PLAYER.set_function("IS_PLAYER_WANTED_LEVEL_GREATER", LUA_NATIVE_PLAYER_IS_PLAYER_WANTED_LEVEL_GREATER);
		PLAYER.set_function("CLEAR_PLAYER_WANTED_LEVEL", LUA_NATIVE_PLAYER_CLEAR_PLAYER_WANTED_LEVEL);
		PLAYER.set_function("IS_PLAYER_DEAD", LUA_NATIVE_PLAYER_IS_PLAYER_DEAD);
		PLAYER.set_function("SET_PLAYER_CONTROL", LUA_NATIVE_PLAYER_SET_PLAYER_CONTROL);
		PLAYER.set_function("GET_PLAYER_WANTED_LEVEL", LUA_NATIVE_PLAYER_GET_PLAYER_WANTED_LEVEL);
		PLAYER.set_function("SET_MAX_WANTED_LEVEL", LUA_NATIVE_PLAYER_SET_MAX_WANTED_LEVEL);
		PLAYER.set_function("_SET_MAX_WANTED_LEVEL_2", LUA_NATIVE_PLAYER__SET_MAX_WANTED_LEVEL_2);
		PLAYER.set_function("SET_POLICE_RADAR_BLIPS", LUA_NATIVE_PLAYER_SET_POLICE_RADAR_BLIPS);
		PLAYER.set_function("IS_PLAYER_PLAYING", LUA_NATIVE_PLAYER_IS_PLAYER_PLAYING);
		PLAYER.set_function("SET_EVERYONE_IGNORE_PLAYER", LUA_NATIVE_PLAYER_SET_EVERYONE_IGNORE_PLAYER);
		PLAYER.set_function("GET_IS_PLAYER_UI_PROMPT_ACTIVE", LUA_NATIVE_PLAYER_GET_IS_PLAYER_UI_PROMPT_ACTIVE);
		PLAYER.set_function("_MODIFY_PLAYER_UI_PROMPT", LUA_NATIVE_PLAYER__MODIFY_PLAYER_UI_PROMPT);
		PLAYER.set_function("_GET_PLAYER_UI_PROMPT_IS_DISABLED", LUA_NATIVE_PLAYER__GET_PLAYER_UI_PROMPT_IS_DISABLED);
		PLAYER.set_function("_MODIFY_PLAYER_UI_PROMPT_FOR_PED", LUA_NATIVE_PLAYER__MODIFY_PLAYER_UI_PROMPT_FOR_PED);
		PLAYER.set_function("_GET_PLAYER_UI_PROMPT_FOR_PED_IS_ENABLED", LUA_NATIVE_PLAYER__GET_PLAYER_UI_PROMPT_FOR_PED_IS_ENABLED);
		PLAYER.set_function("_0x93624B36E8851B42", LUA_NATIVE_PLAYER__0x93624B36E8851B42);
		PLAYER.set_function("_0x9073EC5456651A90", LUA_NATIVE_PLAYER__0x9073EC5456651A90);
		PLAYER.set_function("_0x2E67707BEC52CA4B", LUA_NATIVE_PLAYER__0x2E67707BEC52CA4B);
		PLAYER.set_function("SET_ALL_RANDOM_PEDS_FLEE", LUA_NATIVE_PLAYER_SET_ALL_RANDOM_PEDS_FLEE);
		PLAYER.set_function("SET_ALL_RANDOM_PEDS_FLEE_THIS_FRAME", LUA_NATIVE_PLAYER_SET_ALL_RANDOM_PEDS_FLEE_THIS_FRAME);
		PLAYER.set_function("SET_ALL_NEUTRAL_RANDOM_PEDS_FLEE_THIS_FRAME", LUA_NATIVE_PLAYER_SET_ALL_NEUTRAL_RANDOM_PEDS_FLEE_THIS_FRAME);
		PLAYER.set_function("_0x1D256EED194F5B58", LUA_NATIVE_PLAYER__0x1D256EED194F5B58);
		PLAYER.set_function("_0x5B7B97E99F84138B", LUA_NATIVE_PLAYER__0x5B7B97E99F84138B);
		PLAYER.set_function("_SET_DISABLE_PLAYER_WANTED_LEVEL", LUA_NATIVE_PLAYER__SET_DISABLE_PLAYER_WANTED_LEVEL);
		PLAYER.set_function("_GET_WANTED_LEVEL_MULTIPLIER", LUA_NATIVE_PLAYER__GET_WANTED_LEVEL_MULTIPLIER);
		PLAYER.set_function("SET_WANTED_LEVEL_MULTIPLIER", LUA_NATIVE_PLAYER_SET_WANTED_LEVEL_MULTIPLIER);
		PLAYER.set_function("RESET_WANTED_LEVEL_DIFFICULTY", LUA_NATIVE_PLAYER_RESET_WANTED_LEVEL_DIFFICULTY);
		PLAYER.set_function("UPDATE_WANTED_POSITION_THIS_FRAME", LUA_NATIVE_PLAYER_UPDATE_WANTED_POSITION_THIS_FRAME);
		PLAYER.set_function("SUPPRESS_WITNESSES_CALLING_POLICE_THIS_FRAME", LUA_NATIVE_PLAYER_SUPPRESS_WITNESSES_CALLING_POLICE_THIS_FRAME);
		PLAYER.set_function("REPORT_POLICE_SPOTTED_PLAYER", LUA_NATIVE_PLAYER_REPORT_POLICE_SPOTTED_PLAYER);
		PLAYER.set_function("SET_LAW_RESPONSE_DELAY_OVERRIDE", LUA_NATIVE_PLAYER_SET_LAW_RESPONSE_DELAY_OVERRIDE);
		PLAYER.set_function("RESET_LAW_RESPONSE_DELAY_OVERRIDE", LUA_NATIVE_PLAYER_RESET_LAW_RESPONSE_DELAY_OVERRIDE);
		PLAYER.set_function("CAN_PLAYER_START_MISSION", LUA_NATIVE_PLAYER_CAN_PLAYER_START_MISSION);
		PLAYER.set_function("IS_PLAYER_READY_FOR_CUTSCENE", LUA_NATIVE_PLAYER_IS_PLAYER_READY_FOR_CUTSCENE);
		PLAYER.set_function("IS_PLAYER_TARGETTING_ENTITY", LUA_NATIVE_PLAYER_IS_PLAYER_TARGETTING_ENTITY);
		PLAYER.set_function("GET_PLAYER_TARGET_ENTITY", LUA_NATIVE_PLAYER_GET_PLAYER_TARGET_ENTITY);
		PLAYER.set_function("_0x927861B2C08DBEA5", LUA_NATIVE_PLAYER__0x927861B2C08DBEA5);
		PLAYER.set_function("_IS_PLAYER_FREE_FOCUSING", LUA_NATIVE_PLAYER__IS_PLAYER_FREE_FOCUSING);
		PLAYER.set_function("GET_PLAYER_INTERACTION_TARGET_ENTITY", LUA_NATIVE_PLAYER_GET_PLAYER_INTERACTION_TARGET_ENTITY);
		PLAYER.set_function("_0xBEA3A6E5F5F79A6F", LUA_NATIVE_PLAYER__0xBEA3A6E5F5F79A6F);
		PLAYER.set_function("_IS_PLAYER_IN_SCOPE", LUA_NATIVE_PLAYER__IS_PLAYER_IN_SCOPE);
		PLAYER.set_function("IS_PLAYER_FREE_AIMING", LUA_NATIVE_PLAYER_IS_PLAYER_FREE_AIMING);
		PLAYER.set_function("IS_PLAYER_FREE_AIMING_AT_ENTITY", LUA_NATIVE_PLAYER_IS_PLAYER_FREE_AIMING_AT_ENTITY);
		PLAYER.set_function("GET_ENTITY_PLAYER_IS_FREE_AIMING_AT", LUA_NATIVE_PLAYER_GET_ENTITY_PLAYER_IS_FREE_AIMING_AT);
		PLAYER.set_function("_0x3DAABE78A23694BC", LUA_NATIVE_PLAYER__0x3DAABE78A23694BC);
		PLAYER.set_function("_0x7AE93C45EC14A166", LUA_NATIVE_PLAYER__0x7AE93C45EC14A166);
		PLAYER.set_function("SET_PLAYER_LOCKON_RANGE_OVERRIDE", LUA_NATIVE_PLAYER_SET_PLAYER_LOCKON_RANGE_OVERRIDE);
		PLAYER.set_function("SET_PLAYER_CAN_BE_HASSLED_BY_GANGS", LUA_NATIVE_PLAYER_SET_PLAYER_CAN_BE_HASSLED_BY_GANGS);
		PLAYER.set_function("SET_PLAYER_CAN_USE_COVER", LUA_NATIVE_PLAYER_SET_PLAYER_CAN_USE_COVER);
		PLAYER.set_function("_0xD1A70C1E8D1031FE", LUA_NATIVE_PLAYER__0xD1A70C1E8D1031FE);
		PLAYER.set_function("_0xACA45DDCEF6071C4", LUA_NATIVE_PLAYER__0xACA45DDCEF6071C4);
		PLAYER.set_function("_0xA0C683284DF027C7", LUA_NATIVE_PLAYER__0xA0C683284DF027C7);
		PLAYER.set_function("_SET_PLAYER_CAN_MERCY_KILL", LUA_NATIVE_PLAYER__SET_PLAYER_CAN_MERCY_KILL);
		PLAYER.set_function("_0x4EC8BE63B8A5D4EF", LUA_NATIVE_PLAYER__0x4EC8BE63B8A5D4EF);
		PLAYER.set_function("GET_MAX_WANTED_LEVEL", LUA_NATIVE_PLAYER_GET_MAX_WANTED_LEVEL);
		PLAYER.set_function("IS_PLAYER_TARGETTING_ANYTHING", LUA_NATIVE_PLAYER_IS_PLAYER_TARGETTING_ANYTHING);
		PLAYER.set_function("RESTORE_PLAYER_STAMINA", LUA_NATIVE_PLAYER_RESTORE_PLAYER_STAMINA);
		PLAYER.set_function("_0x8591EE69CC3ED257", LUA_NATIVE_PLAYER__0x8591EE69CC3ED257);
		PLAYER.set_function("GET_PLAYER_GROUP", LUA_NATIVE_PLAYER_GET_PLAYER_GROUP);
		PLAYER.set_function("_0x3D9DA5C9EFD20D88", LUA_NATIVE_PLAYER__0x3D9DA5C9EFD20D88);
		PLAYER.set_function("_0x2BEED53B912537D0", LUA_NATIVE_PLAYER__0x2BEED53B912537D0);
		PLAYER.set_function("_0x908D4B72854C8F62", LUA_NATIVE_PLAYER__0x908D4B72854C8F62);
		PLAYER.set_function("_0xD1F6B912785BFD35", LUA_NATIVE_PLAYER__0xD1F6B912785BFD35);
		PLAYER.set_function("_0xC4873B053054C04B", LUA_NATIVE_PLAYER__0xC4873B053054C04B);
		PLAYER.set_function("_0xCA59808E51FD67C4", LUA_NATIVE_PLAYER__0xCA59808E51FD67C4);
		PLAYER.set_function("_0xBA5CA1FEB5DE0DF6", LUA_NATIVE_PLAYER__0xBA5CA1FEB5DE0DF6);
		PLAYER.set_function("_0x0869D499A7848309", LUA_NATIVE_PLAYER__0x0869D499A7848309);
		PLAYER.set_function("_0xB331D8A73F9D2BDF", LUA_NATIVE_PLAYER__0xB331D8A73F9D2BDF);
		PLAYER.set_function("_ADD_PLAYER_AS_FOLLOW_TARGET", LUA_NATIVE_PLAYER__ADD_PLAYER_AS_FOLLOW_TARGET);
		PLAYER.set_function("_REMOVE_PLAYER_AS_FOLLOW_TARGET", LUA_NATIVE_PLAYER__REMOVE_PLAYER_AS_FOLLOW_TARGET);
		PLAYER.set_function("_0x12E09E278C6C29B7", LUA_NATIVE_PLAYER__0x12E09E278C6C29B7);
		PLAYER.set_function("_0xDD33A82352C4652F", LUA_NATIVE_PLAYER__0xDD33A82352C4652F);
		PLAYER.set_function("_0x1FDA57E8908F2609", LUA_NATIVE_PLAYER__0x1FDA57E8908F2609);
		PLAYER.set_function("_0x84481018E668E1B8", LUA_NATIVE_PLAYER__0x84481018E668E1B8);
		PLAYER.set_function("_0x2009F8AB7A5E9D6D", LUA_NATIVE_PLAYER__0x2009F8AB7A5E9D6D);
		PLAYER.set_function("_IS_PLAYER_FOLLOWING_TARGET", LUA_NATIVE_PLAYER__IS_PLAYER_FOLLOWING_TARGET);
		PLAYER.set_function("_0xE7F8707269544B29", LUA_NATIVE_PLAYER__0xE7F8707269544B29);
		PLAYER.set_function("_0xE631EAF35828FA67", LUA_NATIVE_PLAYER__0xE631EAF35828FA67);
		PLAYER.set_function("_0x086549F3B0381CB1", LUA_NATIVE_PLAYER__0x086549F3B0381CB1);
		PLAYER.set_function("IS_PLAYER_CONTROL_ON", LUA_NATIVE_PLAYER_IS_PLAYER_CONTROL_ON);
		PLAYER.set_function("IS_PLAYER_SCRIPT_CONTROL_ON", LUA_NATIVE_PLAYER_IS_PLAYER_SCRIPT_CONTROL_ON);
		PLAYER.set_function("IS_PLAYER_CLIMBING", LUA_NATIVE_PLAYER_IS_PLAYER_CLIMBING);
		PLAYER.set_function("_0xEBB6E27AC2FF32DA", LUA_NATIVE_PLAYER__0xEBB6E27AC2FF32DA);
		PLAYER.set_function("_0xB15CD2F9932C9AB5", LUA_NATIVE_PLAYER__0xB15CD2F9932C9AB5);
		PLAYER.set_function("_0x621D1B289CAF5978", LUA_NATIVE_PLAYER__0x621D1B289CAF5978);
		PLAYER.set_function("IS_PLAYER_BEING_ARRESTED", LUA_NATIVE_PLAYER_IS_PLAYER_BEING_ARRESTED);
		PLAYER.set_function("RESET_PLAYER_ARREST_STATE", LUA_NATIVE_PLAYER_RESET_PLAYER_ARREST_STATE);
		PLAYER.set_function("_0xCBB54CC7FFFFAB86", LUA_NATIVE_PLAYER__0xCBB54CC7FFFFAB86);
		PLAYER.set_function("_0xBED386157F65942C", LUA_NATIVE_PLAYER__0xBED386157F65942C);
		PLAYER.set_function("_0xDAB6A2FC56B7DE65", LUA_NATIVE_PLAYER__0xDAB6A2FC56B7DE65);
		PLAYER.set_function("_0x0F4EAF69DA41AF43", LUA_NATIVE_PLAYER__0x0F4EAF69DA41AF43);
		PLAYER.set_function("_SET_BOUNTY_TARGET", LUA_NATIVE_PLAYER__SET_BOUNTY_TARGET);
		PLAYER.set_function("_CLEAR_BOUNTY_TARGET", LUA_NATIVE_PLAYER__CLEAR_BOUNTY_TARGET);
		PLAYER.set_function("GET_PLAYERS_LAST_VEHICLE", LUA_NATIVE_PLAYER_GET_PLAYERS_LAST_VEHICLE);
		PLAYER.set_function("GET_PLAYER_INDEX", LUA_NATIVE_PLAYER_GET_PLAYER_INDEX);
		PLAYER.set_function("INT_TO_PLAYERINDEX", LUA_NATIVE_PLAYER_INT_TO_PLAYERINDEX);
		PLAYER.set_function("INT_TO_PARTICIPANTINDEX", LUA_NATIVE_PLAYER_INT_TO_PARTICIPANTINDEX);
		PLAYER.set_function("PLAYER_ID", LUA_NATIVE_PLAYER_PLAYER_ID);
		PLAYER.set_function("PLAYER_PED_ID", LUA_NATIVE_PLAYER_PLAYER_PED_ID);
		PLAYER.set_function("NETWORK_PLAYER_ID_TO_INT", LUA_NATIVE_PLAYER_NETWORK_PLAYER_ID_TO_INT);
		PLAYER.set_function("HAS_FORCE_CLEANUP_OCCURRED", LUA_NATIVE_PLAYER_HAS_FORCE_CLEANUP_OCCURRED);
		PLAYER.set_function("FORCE_CLEANUP", LUA_NATIVE_PLAYER_FORCE_CLEANUP);
		PLAYER.set_function("FORCE_CLEANUP_FOR_ALL_THREADS_WITH_THIS_NAME", LUA_NATIVE_PLAYER_FORCE_CLEANUP_FOR_ALL_THREADS_WITH_THIS_NAME);
		PLAYER.set_function("FORCE_CLEANUP_FOR_THREAD_WITH_THIS_ID", LUA_NATIVE_PLAYER_FORCE_CLEANUP_FOR_THREAD_WITH_THIS_ID);
		PLAYER.set_function("GET_CAUSE_OF_MOST_RECENT_FORCE_CLEANUP", LUA_NATIVE_PLAYER_GET_CAUSE_OF_MOST_RECENT_FORCE_CLEANUP);
		PLAYER.set_function("_SET_PLAYER_MOOD", LUA_NATIVE_PLAYER__SET_PLAYER_MOOD);
		PLAYER.set_function("_GET_PLAYER_MOOD", LUA_NATIVE_PLAYER__GET_PLAYER_MOOD);
		PLAYER.set_function("SET_PLAYER_MAY_ONLY_ENTER_THIS_VEHICLE", LUA_NATIVE_PLAYER_SET_PLAYER_MAY_ONLY_ENTER_THIS_VEHICLE);
		PLAYER.set_function("_0xC71D07C96946E263", LUA_NATIVE_PLAYER__0xC71D07C96946E263);
		PLAYER.set_function("SET_PLAYER_MAY_NOT_ENTER_ANY_VEHICLE", LUA_NATIVE_PLAYER_SET_PLAYER_MAY_NOT_ENTER_ANY_VEHICLE);
		PLAYER.set_function("IS_SYSTEM_UI_BEING_DISPLAYED", LUA_NATIVE_PLAYER_IS_SYSTEM_UI_BEING_DISPLAYED);
		PLAYER.set_function("_0xD48227263E3D06AE", LUA_NATIVE_PLAYER__0xD48227263E3D06AE);
		PLAYER.set_function("_0x3946FC742AC305CD", LUA_NATIVE_PLAYER__0x3946FC742AC305CD);
		PLAYER.set_function("_0xA28056CD1B04B250", LUA_NATIVE_PLAYER__0xA28056CD1B04B250);
		PLAYER.set_function("_0xC67A4910425F11F1", LUA_NATIVE_PLAYER__0xC67A4910425F11F1);
		PLAYER.set_function("SET_PLAYER_INVINCIBLE", LUA_NATIVE_PLAYER_SET_PLAYER_INVINCIBLE);
		PLAYER.set_function("GET_PLAYER_INVINCIBLE", LUA_NATIVE_PLAYER_GET_PLAYER_INVINCIBLE);
		PLAYER.set_function("SET_PLAYER_LOCKON", LUA_NATIVE_PLAYER_SET_PLAYER_LOCKON);
		PLAYER.set_function("SET_LOCKON_TO_FRIENDLY_PLAYERS", LUA_NATIVE_PLAYER_SET_LOCKON_TO_FRIENDLY_PLAYERS);
		PLAYER.set_function("SET_PLAYER_TARGETING_MODE", LUA_NATIVE_PLAYER_SET_PLAYER_TARGETING_MODE);
		PLAYER.set_function("_SET_PLAYER_IN_VEHICLE_TARGETING_MODE", LUA_NATIVE_PLAYER__SET_PLAYER_IN_VEHICLE_TARGETING_MODE);
		PLAYER.set_function("_0x747257807B8721CE", LUA_NATIVE_PLAYER__0x747257807B8721CE);
		PLAYER.set_function("_0x8702D9150D9FBB3D", LUA_NATIVE_PLAYER__0x8702D9150D9FBB3D);
		PLAYER.set_function("_0xCB0B9506BC91E441", LUA_NATIVE_PLAYER__0xCB0B9506BC91E441);
		PLAYER.set_function("CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_PED", LUA_NATIVE_PLAYER_CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_PED);
		PLAYER.set_function("HAS_PLAYER_DAMAGED_AT_LEAST_ONE_PED", LUA_NATIVE_PLAYER_HAS_PLAYER_DAMAGED_AT_LEAST_ONE_PED);
		PLAYER.set_function("CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_NON_ANIMAL_PED", LUA_NATIVE_PLAYER_CLEAR_PLAYER_HAS_DAMAGED_AT_LEAST_ONE_NON_ANIMAL_PED);
		PLAYER.set_function("HAS_PLAYER_DAMAGED_AT_LEAST_ONE_NON_ANIMAL_PED", LUA_NATIVE_PLAYER_HAS_PLAYER_DAMAGED_AT_LEAST_ONE_NON_ANIMAL_PED);
		PLAYER.set_function("_0xEACEBAAE0A33FB3F", LUA_NATIVE_PLAYER__0xEACEBAAE0A33FB3F);
		PLAYER.set_function("_0x72AD59F7B7FB6E24", LUA_NATIVE_PLAYER__0x72AD59F7B7FB6E24);
		PLAYER.set_function("_0x1A6E84F13C952094", LUA_NATIVE_PLAYER__0x1A6E84F13C952094);
		PLAYER.set_function("_SET_PLAYER_DAMAGE_INFO_OVERRIDE", LUA_NATIVE_PLAYER__SET_PLAYER_DAMAGE_INFO_OVERRIDE);
		PLAYER.set_function("_0x1F488807BC8E0630", LUA_NATIVE_PLAYER__0x1F488807BC8E0630);
		PLAYER.set_function("SET_AIR_DRAG_MULTIPLIER_FOR_PLAYERS_VEHICLE", LUA_NATIVE_PLAYER_SET_AIR_DRAG_MULTIPLIER_FOR_PLAYERS_VEHICLE);
		PLAYER.set_function("SET_SWIM_MULTIPLIER_FOR_PLAYER", LUA_NATIVE_PLAYER_SET_SWIM_MULTIPLIER_FOR_PLAYER);
		PLAYER.set_function("_0x73EB2EF2E92D23BF", LUA_NATIVE_PLAYER__0x73EB2EF2E92D23BF);
		PLAYER.set_function("SET_PLAYER_FORCED_AIM", LUA_NATIVE_PLAYER_SET_PLAYER_FORCED_AIM);
		PLAYER.set_function("_0x310CE349E0C0EC4B", LUA_NATIVE_PLAYER__0x310CE349E0C0EC4B);
		PLAYER.set_function("DISABLE_PLAYER_FIRING", LUA_NATIVE_PLAYER_DISABLE_PLAYER_FIRING);
		PLAYER.set_function("_0xEBFF94328FF7A18A", LUA_NATIVE_PLAYER__0xEBFF94328FF7A18A);
		PLAYER.set_function("_0xF993373285053D77", LUA_NATIVE_PLAYER__0xF993373285053D77);
		PLAYER.set_function("_0xE956C2340A76272E", LUA_NATIVE_PLAYER__0xE956C2340A76272E);
		PLAYER.set_function("_ENABLE_CUSTOM_DEADEYE_ABILITY", LUA_NATIVE_PLAYER__ENABLE_CUSTOM_DEADEYE_ABILITY);
		PLAYER.set_function("_0xDE6C85975F9D4894", LUA_NATIVE_PLAYER__0xDE6C85975F9D4894);
		PLAYER.set_function("_0xBBA140062B15A8AC", LUA_NATIVE_PLAYER__0xBBA140062B15A8AC);
		PLAYER.set_function("_SPECIAL_ABILITY_SET_DISABLED", LUA_NATIVE_PLAYER__SPECIAL_ABILITY_SET_DISABLED);
		PLAYER.set_function("_IS_SPECIAL_ABILITY_ACTIVE", LUA_NATIVE_PLAYER__IS_SPECIAL_ABILITY_ACTIVE);
		PLAYER.set_function("_MODIFY_INFINITE_TRAIL_VISION", LUA_NATIVE_PLAYER__MODIFY_INFINITE_TRAIL_VISION);
		PLAYER.set_function("_SPECIAL_ABILITY_SET_EAGLE_EYE_DISABLED", LUA_NATIVE_PLAYER__SPECIAL_ABILITY_SET_EAGLE_EYE_DISABLED);
		PLAYER.set_function("_SPECIAL_ABILITY_RESTORE_BY_AMOUNT", LUA_NATIVE_PLAYER__SPECIAL_ABILITY_RESTORE_BY_AMOUNT);
		PLAYER.set_function("_0xFA437FA0738C370C", LUA_NATIVE_PLAYER__0xFA437FA0738C370C);
		PLAYER.set_function("_SPECIAL_ABILITY_RESTORE_OUTER_RING", LUA_NATIVE_PLAYER__SPECIAL_ABILITY_RESTORE_OUTER_RING);
		PLAYER.set_function("_GET_PLAYER_REQUIRED_DEAD_EYE_AMOUNT", LUA_NATIVE_PLAYER__GET_PLAYER_REQUIRED_DEAD_EYE_AMOUNT);
		PLAYER.set_function("_SPECIAL_ABILITY_GET_AMOUNT_CACHED", LUA_NATIVE_PLAYER__SPECIAL_ABILITY_GET_AMOUNT_CACHED);
		PLAYER.set_function("_SPECIAL_ABILITY_DRAIN_BY_AMOUNT", LUA_NATIVE_PLAYER__SPECIAL_ABILITY_DRAIN_BY_AMOUNT);
		PLAYER.set_function("_SPECIAL_ABILITY_START_RESTORE", LUA_NATIVE_PLAYER__SPECIAL_ABILITY_START_RESTORE);
		PLAYER.set_function("_SET_SPECIAL_ABILITY_MULTIPLIER", LUA_NATIVE_PLAYER__SET_SPECIAL_ABILITY_MULTIPLIER);
		PLAYER.set_function("_GET_PLAYER_SPECIAL_ABILITY_MULTIPLIER", LUA_NATIVE_PLAYER__GET_PLAYER_SPECIAL_ABILITY_MULTIPLIER);
		PLAYER.set_function("_SET_SPECIAL_ABILITY_TYPE", LUA_NATIVE_PLAYER__SET_SPECIAL_ABILITY_TYPE);
		PLAYER.set_function("_0x22B3CABEDDB538B2", LUA_NATIVE_PLAYER__0x22B3CABEDDB538B2);
		PLAYER.set_function("_SET_SPECIAL_ABILITY_DURATION_COST", LUA_NATIVE_PLAYER__SET_SPECIAL_ABILITY_DURATION_COST);
		PLAYER.set_function("_SET_SPECIAL_ABILITY_DISABLE_TIMER", LUA_NATIVE_PLAYER__SET_SPECIAL_ABILITY_DISABLE_TIMER);
		PLAYER.set_function("_0x57D9991DC1334151", LUA_NATIVE_PLAYER__0x57D9991DC1334151);
		PLAYER.set_function("_0x21091B4BEB6376EE", LUA_NATIVE_PLAYER__0x21091B4BEB6376EE);
		PLAYER.set_function("_SET_SPECIAL_ABILITY_ACTIVATION_COST", LUA_NATIVE_PLAYER__SET_SPECIAL_ABILITY_ACTIVATION_COST);
		PLAYER.set_function("_0x4D1699543B1C023C", LUA_NATIVE_PLAYER__0x4D1699543B1C023C);
		PLAYER.set_function("_GET_PLAYER_DEAD_EYE_METER_LEVEL", LUA_NATIVE_PLAYER__GET_PLAYER_DEAD_EYE_METER_LEVEL);
		PLAYER.set_function("_GET_PLAYER_DEAD_EYE", LUA_NATIVE_PLAYER__GET_PLAYER_DEAD_EYE);
		PLAYER.set_function("_GET_PLAYER_CACHED_DEAD_EYE_AMOUNT", LUA_NATIVE_PLAYER__GET_PLAYER_CACHED_DEAD_EYE_AMOUNT);
		PLAYER.set_function("_GET_PLAYER_MAX_DEAD_EYE", LUA_NATIVE_PLAYER__GET_PLAYER_MAX_DEAD_EYE);
		PLAYER.set_function("_GET_PLAYER_HEALTH", LUA_NATIVE_PLAYER__GET_PLAYER_HEALTH);
		PLAYER.set_function("_GET_PLAYER_STAMINA", LUA_NATIVE_PLAYER__GET_PLAYER_STAMINA);
		PLAYER.set_function("_SET_PLAYER_STAT_FLAG_HASH", LUA_NATIVE_PLAYER__SET_PLAYER_STAT_FLAG_HASH);
		PLAYER.set_function("_SET_USED_ITEM_EFFECT", LUA_NATIVE_PLAYER__SET_USED_ITEM_EFFECT);
		PLAYER.set_function("_0x08E22898A6AF4905", LUA_NATIVE_PLAYER__0x08E22898A6AF4905);
		PLAYER.set_function("_0xBEFED69CE8317F91", LUA_NATIVE_PLAYER__0xBEFED69CE8317F91);
		PLAYER.set_function("_ENABLE_EAGLEEYE", LUA_NATIVE_PLAYER__ENABLE_EAGLEEYE);
		PLAYER.set_function("_IS_SECONDARY_SPECIAL_ABILITY_ENABLED", LUA_NATIVE_PLAYER__IS_SECONDARY_SPECIAL_ABILITY_ENABLED);
		PLAYER.set_function("_SECONDARY_SPECIAL_ABILITY_SET_ACTIVE", LUA_NATIVE_PLAYER__SECONDARY_SPECIAL_ABILITY_SET_ACTIVE);
		PLAYER.set_function("_SECONDARY_SPECIAL_ABILITY_SET_DISABLED", LUA_NATIVE_PLAYER__SECONDARY_SPECIAL_ABILITY_SET_DISABLED);
		PLAYER.set_function("_IS_SECONDARY_SPECIAL_ABILITY_ACTIVE", LUA_NATIVE_PLAYER__IS_SECONDARY_SPECIAL_ABILITY_ACTIVE);
		PLAYER.set_function("_0x107F2A66E1C4C83A", LUA_NATIVE_PLAYER__0x107F2A66E1C4C83A);
		PLAYER.set_function("START_PLAYER_TELEPORT", LUA_NATIVE_PLAYER_START_PLAYER_TELEPORT);
		PLAYER.set_function("_0x2C2D287748E8E9B7", LUA_NATIVE_PLAYER__0x2C2D287748E8E9B7);
		PLAYER.set_function("UPDATE_PLAYER_TELEPORT", LUA_NATIVE_PLAYER_UPDATE_PLAYER_TELEPORT);
		PLAYER.set_function("STOP_PLAYER_TELEPORT", LUA_NATIVE_PLAYER_STOP_PLAYER_TELEPORT);
		PLAYER.set_function("IS_PLAYER_TELEPORT_ACTIVE", LUA_NATIVE_PLAYER_IS_PLAYER_TELEPORT_ACTIVE);
		PLAYER.set_function("GET_PLAYER_CURRENT_STEALTH_NOISE", LUA_NATIVE_PLAYER_GET_PLAYER_CURRENT_STEALTH_NOISE);
		PLAYER.set_function("SET_PLAYER_HEALTH_RECHARGE_MULTIPLIER", LUA_NATIVE_PLAYER_SET_PLAYER_HEALTH_RECHARGE_MULTIPLIER);
		PLAYER.set_function("_GET_PLAYER_HEALTH_RECHARGE_MULTIPLIER", LUA_NATIVE_PLAYER__GET_PLAYER_HEALTH_RECHARGE_MULTIPLIER);
		PLAYER.set_function("_SET_PLAYER_HEALTH_RECHARGE_TIME_MODIFIER", LUA_NATIVE_PLAYER__SET_PLAYER_HEALTH_RECHARGE_TIME_MODIFIER);
		PLAYER.set_function("SET_PLAYER_STAMINA_RECHARGE_MULTIPLIER", LUA_NATIVE_PLAYER_SET_PLAYER_STAMINA_RECHARGE_MULTIPLIER);
		PLAYER.set_function("_GET_PLAYER_STAMINA_RECHARGE_MULTIPLIER", LUA_NATIVE_PLAYER__GET_PLAYER_STAMINA_RECHARGE_MULTIPLIER);
		PLAYER.set_function("_SET_PLAYER_STAMINA_SPRINT_DEPLETION_MULTIPLIER", LUA_NATIVE_PLAYER__SET_PLAYER_STAMINA_SPRINT_DEPLETION_MULTIPLIER);
		PLAYER.set_function("_GET_PLAYER_STAMINA_DEPLETION_MULTIPLIER", LUA_NATIVE_PLAYER__GET_PLAYER_STAMINA_DEPLETION_MULTIPLIER);
		PLAYER.set_function("_SET_PED_ACTIVE_PLAYER_HORSE", LUA_NATIVE_PLAYER__SET_PED_ACTIVE_PLAYER_HORSE);
		PLAYER.set_function("_GET_ACTIVE_HORSE_FOR_PLAYER", LUA_NATIVE_PLAYER__GET_ACTIVE_HORSE_FOR_PLAYER);
		PLAYER.set_function("_SET_PED_AS_SADDLE_HORSE_FOR_PLAYER", LUA_NATIVE_PLAYER__SET_PED_AS_SADDLE_HORSE_FOR_PLAYER);
		PLAYER.set_function("_GET_SADDLE_HORSE_FOR_PLAYER", LUA_NATIVE_PLAYER__GET_SADDLE_HORSE_FOR_PLAYER);
		PLAYER.set_function("SET_PED_AS_TEMP_PLAYER_HORSE", LUA_NATIVE_PLAYER_SET_PED_AS_TEMP_PLAYER_HORSE);
		PLAYER.set_function("_GET_TEMP_PLAYER_HORSE", LUA_NATIVE_PLAYER__GET_TEMP_PLAYER_HORSE);
		PLAYER.set_function("_0x77B0B6D17A3AC9AA", LUA_NATIVE_PLAYER__0x77B0B6D17A3AC9AA);
		PLAYER.set_function("_SET_PLAYER_MOUNT_STATE_ACTIVE", LUA_NATIVE_PLAYER__SET_PLAYER_MOUNT_STATE_ACTIVE);
		PLAYER.set_function("_0x694FFA4308060CD1", LUA_NATIVE_PLAYER__0x694FFA4308060CD1);
		PLAYER.set_function("BOOST_PLAYER_HORSE_SPEED_FOR_TIME", LUA_NATIVE_PLAYER_BOOST_PLAYER_HORSE_SPEED_FOR_TIME);
		PLAYER.set_function("SET_PLAYER_WEAPON_DAMAGE_MODIFIER", LUA_NATIVE_PLAYER_SET_PLAYER_WEAPON_DAMAGE_MODIFIER);
		PLAYER.set_function("SET_PLAYER_WEAPON_DEFENSE_MODIFIER", LUA_NATIVE_PLAYER_SET_PLAYER_WEAPON_DEFENSE_MODIFIER);
		PLAYER.set_function("_0x818241B3EDA84191", LUA_NATIVE_PLAYER__0x818241B3EDA84191);
		PLAYER.set_function("SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER", LUA_NATIVE_PLAYER_SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER);
		PLAYER.set_function("_SET_PLAYER_EXPLOSIVE_WEAPON_DAMAGE_MODIFIER", LUA_NATIVE_PLAYER__SET_PLAYER_EXPLOSIVE_WEAPON_DAMAGE_MODIFIER);
		PLAYER.set_function("_0x83C989D5B5B5B466", LUA_NATIVE_PLAYER__0x83C989D5B5B5B466);
		PLAYER.set_function("_0x03B4B759A8990505", LUA_NATIVE_PLAYER__0x03B4B759A8990505);
		PLAYER.set_function("_0x67659A8F248E0141", LUA_NATIVE_PLAYER__0x67659A8F248E0141);
		PLAYER.set_function("_SET_RECEIVED_HORSEBACK_DAMAGE_DECREASE", LUA_NATIVE_PLAYER__SET_RECEIVED_HORSEBACK_DAMAGE_DECREASE);
		PLAYER.set_function("_SET_AI_PLAYER_DEFENSE_MODIFIER_AGAINST_AI", LUA_NATIVE_PLAYER__SET_AI_PLAYER_DEFENSE_MODIFIER_AGAINST_AI);
		PLAYER.set_function("_GET_AI_PLAYER_DEFENSE_MODIFIER_AGAINST_AI", LUA_NATIVE_PLAYER__GET_AI_PLAYER_DEFENSE_MODIFIER_AGAINST_AI);
		PLAYER.set_function("_0x19B2C7A6C34FAD54", LUA_NATIVE_PLAYER__0x19B2C7A6C34FAD54);
		PLAYER.set_function("_0x9422743A5BA50E10", LUA_NATIVE_PLAYER__0x9422743A5BA50E10);
		PLAYER.set_function("_SET_PLAYER_DEFENSE_MODIFIER", LUA_NATIVE_PLAYER__SET_PLAYER_DEFENSE_MODIFIER);
		PLAYER.set_function("_SET_PLAYER_DEFENSE_TYPE_MODIFIER", LUA_NATIVE_PLAYER__SET_PLAYER_DEFENSE_TYPE_MODIFIER);
		PLAYER.set_function("SET_PLAYER_WEAPON_TYPE_DAMAGE_MODIFIER", LUA_NATIVE_PLAYER_SET_PLAYER_WEAPON_TYPE_DAMAGE_MODIFIER);
		PLAYER.set_function("_GET_PLAYER_WEAPON_DAMAGE", LUA_NATIVE_PLAYER__GET_PLAYER_WEAPON_DAMAGE);
		PLAYER.set_function("_0x5C2E5E3CAEEB1F58", LUA_NATIVE_PLAYER__0x5C2E5E3CAEEB1F58);
		PLAYER.set_function("_SET_PLAYER_WEAPON_GROUP_DAMAGE_MODIFIER", LUA_NATIVE_PLAYER__SET_PLAYER_WEAPON_GROUP_DAMAGE_MODIFIER);
		PLAYER.set_function("_SET_PLAYER_WEAPON_GROUP_AS_INSTANT_KILL", LUA_NATIVE_PLAYER__SET_PLAYER_WEAPON_GROUP_AS_INSTANT_KILL);
		PLAYER.set_function("_SET_PLAYER_TRAMPLE_DAMAGE_MODIFIER", LUA_NATIVE_PLAYER__SET_PLAYER_TRAMPLE_DAMAGE_MODIFIER);
		PLAYER.set_function("_SET_PLAYER_LASSO_DAMAGE_PER_SECOND", LUA_NATIVE_PLAYER__SET_PLAYER_LASSO_DAMAGE_PER_SECOND);
		PLAYER.set_function("_SET_PLAYER_TOTAL_ACCURACY_MODIFIER", LUA_NATIVE_PLAYER__SET_PLAYER_TOTAL_ACCURACY_MODIFIER);
		PLAYER.set_function("_SET_PLAYER_LOCAL_ACCURACY_FLOOR_MODIFIER", LUA_NATIVE_PLAYER__SET_PLAYER_LOCAL_ACCURACY_FLOOR_MODIFIER);
		PLAYER.set_function("_SET_PLAYER_REMOTE_ACCURACY_FLOOR_MODIFIER", LUA_NATIVE_PLAYER__SET_PLAYER_REMOTE_ACCURACY_FLOOR_MODIFIER);
		PLAYER.set_function("_0x3AD212429E095EFB", LUA_NATIVE_PLAYER__0x3AD212429E095EFB);
		PLAYER.set_function("SET_PLAYER_NOISE_MULTIPLIER", LUA_NATIVE_PLAYER_SET_PLAYER_NOISE_MULTIPLIER);
		PLAYER.set_function("_0x113EF458AB6CDA67", LUA_NATIVE_PLAYER__0x113EF458AB6CDA67);
		PLAYER.set_function("SET_PLAYER_SNEAKING_NOISE_MULTIPLIER", LUA_NATIVE_PLAYER_SET_PLAYER_SNEAKING_NOISE_MULTIPLIER);
		PLAYER.set_function("SIMULATE_PLAYER_INPUT_GAIT", LUA_NATIVE_PLAYER_SIMULATE_PLAYER_INPUT_GAIT);
		PLAYER.set_function("RESET_PLAYER_INPUT_GAIT", LUA_NATIVE_PLAYER_RESET_PLAYER_INPUT_GAIT);
		PLAYER.set_function("SET_PLAYER_SIMULATE_AIMING", LUA_NATIVE_PLAYER_SET_PLAYER_SIMULATE_AIMING);
		PLAYER.set_function("SET_PLAYER_CLOTH_PIN_FRAMES", LUA_NATIVE_PLAYER_SET_PLAYER_CLOTH_PIN_FRAMES);
		PLAYER.set_function("HAS_PLAYER_BEEN_SPOTTED_IN_STOLEN_VEHICLE", LUA_NATIVE_PLAYER_HAS_PLAYER_BEEN_SPOTTED_IN_STOLEN_VEHICLE);
		PLAYER.set_function("GET_PLAYER_RECEIVED_BATTLE_EVENT_RECENTLY", LUA_NATIVE_PLAYER_GET_PLAYER_RECEIVED_BATTLE_EVENT_RECENTLY);
		PLAYER.set_function("_SET_MOUNT_PROMPT_DISABLED", LUA_NATIVE_PLAYER__SET_MOUNT_PROMPT_DISABLED);
		PLAYER.set_function("IS_PLAYER_RIDING_TRAIN", LUA_NATIVE_PLAYER_IS_PLAYER_RIDING_TRAIN);
		PLAYER.set_function("_0x9AFCF9FE1884BF62", LUA_NATIVE_PLAYER__0x9AFCF9FE1884BF62);
		PLAYER.set_function("_0x1E8099F449ABB0BA", LUA_NATIVE_PLAYER__0x1E8099F449ABB0BA);
		PLAYER.set_function("_GET_DEADEYE_ABILITY_LEVEL", LUA_NATIVE_PLAYER__GET_DEADEYE_ABILITY_LEVEL);
		PLAYER.set_function("_SET_DEADEYE_ABILITY_LEVEL", LUA_NATIVE_PLAYER__SET_DEADEYE_ABILITY_LEVEL);
		PLAYER.set_function("_IS_DEADEYE_ABILITY_LOCKED", LUA_NATIVE_PLAYER__IS_DEADEYE_ABILITY_LOCKED);
		PLAYER.set_function("_SET_DEADEYE_ABILITY_LOCKED", LUA_NATIVE_PLAYER__SET_DEADEYE_ABILITY_LOCKED);
		PLAYER.set_function("_SET_DEADEYE_TAGGING_ENABLED", LUA_NATIVE_PLAYER__SET_DEADEYE_TAGGING_ENABLED);
		PLAYER.set_function("_GET_IS_DEADEYE_TAGGING_ENABLED", LUA_NATIVE_PLAYER__GET_IS_DEADEYE_TAGGING_ENABLED);
		PLAYER.set_function("_0x3C4AE8506638C7E2", LUA_NATIVE_PLAYER__0x3C4AE8506638C7E2);
		PLAYER.set_function("_0x51139D8C17B16FBC", LUA_NATIVE_PLAYER__0x51139D8C17B16FBC);
		PLAYER.set_function("_0x8F44EBB3BA8F6D44", LUA_NATIVE_PLAYER__0x8F44EBB3BA8F6D44);
		PLAYER.set_function("_SET_DEADEYE_TAGGING_CONFIG", LUA_NATIVE_PLAYER__SET_DEADEYE_TAGGING_CONFIG);
		PLAYER.set_function("_0xE92261BD28C0878F", LUA_NATIVE_PLAYER__0xE92261BD28C0878F);
		PLAYER.set_function("_SET_DEADEYE_ABILITY_DEPLETION_DELAY", LUA_NATIVE_PLAYER__SET_DEADEYE_ABILITY_DEPLETION_DELAY);
		PLAYER.set_function("_0xA54000D4BFD90BDE", LUA_NATIVE_PLAYER__0xA54000D4BFD90BDE);
		PLAYER.set_function("_0x6EDB5D08CB03E763", LUA_NATIVE_PLAYER__0x6EDB5D08CB03E763);
		PLAYER.set_function("_0x27AD7162D3FED01E", LUA_NATIVE_PLAYER__0x27AD7162D3FED01E);
		PLAYER.set_function("_GET_NUM_MARKED_DEADEYE_TARGETS", LUA_NATIVE_PLAYER__GET_NUM_MARKED_DEADEYE_TARGETS);
		PLAYER.set_function("_0xC93A9A45430D484E", LUA_NATIVE_PLAYER__0xC93A9A45430D484E);
		PLAYER.set_function("_0x570A13A4CA2799BB", LUA_NATIVE_PLAYER__0x570A13A4CA2799BB);
		PLAYER.set_function("_0x3ACAC8832E77BC93", LUA_NATIVE_PLAYER__0x3ACAC8832E77BC93);
		PLAYER.set_function("_0x2B12B6FC8B8772AB", LUA_NATIVE_PLAYER__0x2B12B6FC8B8772AB);
		PLAYER.set_function("_0xE910932F4B30BE23", LUA_NATIVE_PLAYER__0xE910932F4B30BE23);
		PLAYER.set_function("_0x131E294EF60160DF", LUA_NATIVE_PLAYER__0x131E294EF60160DF);
		PLAYER.set_function("_0x0E9057A9DA78D0F8", LUA_NATIVE_PLAYER__0x0E9057A9DA78D0F8);
		PLAYER.set_function("_0x263D69767F76059C", LUA_NATIVE_PLAYER__0x263D69767F76059C);
		PLAYER.set_function("_REGISTER_EAGLE_EYE_FOR_ENTITY", LUA_NATIVE_PLAYER__REGISTER_EAGLE_EYE_FOR_ENTITY);
		PLAYER.set_function("_REGISTER_EAGLE_EYE_TRAILS_FOR_ENTITY", LUA_NATIVE_PLAYER__REGISTER_EAGLE_EYE_TRAILS_FOR_ENTITY);
		PLAYER.set_function("_UNREGISTER_EAGLE_EYE_FOR_ENTITY", LUA_NATIVE_PLAYER__UNREGISTER_EAGLE_EYE_FOR_ENTITY);
		PLAYER.set_function("_UNREGISTER_EAGLE_EYE_TRAILS_FOR_ENTITY", LUA_NATIVE_PLAYER__UNREGISTER_EAGLE_EYE_TRAILS_FOR_ENTITY);
		PLAYER.set_function("_0xE5D3EB37ABC1EB03", LUA_NATIVE_PLAYER__0xE5D3EB37ABC1EB03);
		PLAYER.set_function("_IS_EAGLE_EYE_REGISTERED_FOR_ENTITY", LUA_NATIVE_PLAYER__IS_EAGLE_EYE_REGISTERED_FOR_ENTITY);
		PLAYER.set_function("_0x6852288340B43239", LUA_NATIVE_PLAYER__0x6852288340B43239);
		PLAYER.set_function("_0xE50A67C33514A390", LUA_NATIVE_PLAYER__0xE50A67C33514A390);
		PLAYER.set_function("_0xD288E02E364972D2", LUA_NATIVE_PLAYER__0xD288E02E364972D2);
		PLAYER.set_function("_EAGLE_EYE_DISABLE_TRACKING_TRAIL", LUA_NATIVE_PLAYER__EAGLE_EYE_DISABLE_TRACKING_TRAIL);
		PLAYER.set_function("_0x6ECFC621A168424C", LUA_NATIVE_PLAYER__0x6ECFC621A168424C);
		PLAYER.set_function("_0xDC5E09D012D759C4", LUA_NATIVE_PLAYER__0xDC5E09D012D759C4);
		PLAYER.set_function("_0x00B156AFEBCC5AE0", LUA_NATIVE_PLAYER__0x00B156AFEBCC5AE0);
		PLAYER.set_function("_0xC58CE6824E604DEC", LUA_NATIVE_PLAYER__0xC58CE6824E604DEC);
		PLAYER.set_function("_0x330CA55A3647FA1C", LUA_NATIVE_PLAYER__0x330CA55A3647FA1C);
		PLAYER.set_function("_0xA62BBAAE67A05BB0", LUA_NATIVE_PLAYER__0xA62BBAAE67A05BB0);
		PLAYER.set_function("_EAGLE_EYE_SET_COLOR", LUA_NATIVE_PLAYER__EAGLE_EYE_SET_COLOR);
		PLAYER.set_function("_0x22C8B10802301381", LUA_NATIVE_PLAYER__0x22C8B10802301381);
		PLAYER.set_function("_EAGLE_EYE_SET_DRAIN_RATE_MODIFIER", LUA_NATIVE_PLAYER__EAGLE_EYE_SET_DRAIN_RATE_MODIFIER);
		PLAYER.set_function("_0x06E1FB78B1E59CA5", LUA_NATIVE_PLAYER__0x06E1FB78B1E59CA5);
		PLAYER.set_function("_EAGLE_EYE_SET_PLUS_FLAG_DISABLED", LUA_NATIVE_PLAYER__EAGLE_EYE_SET_PLUS_FLAG_DISABLED);
		PLAYER.set_function("_0x3813E11A378958A5", LUA_NATIVE_PLAYER__0x3813E11A378958A5);
		PLAYER.set_function("_EAGLE_EYE_SET_FOCUS_ON_ASSOCIATED_CLUE_TRAIL", LUA_NATIVE_PLAYER__EAGLE_EYE_SET_FOCUS_ON_ASSOCIATED_CLUE_TRAIL);
		PLAYER.set_function("_0x0F9CF06986300875", LUA_NATIVE_PLAYER__0x0F9CF06986300875);
		PLAYER.set_function("_EAGLE_EYE_SET_TRACKING_UPGRADE", LUA_NATIVE_PLAYER__EAGLE_EYE_SET_TRACKING_UPGRADE);
		PLAYER.set_function("_EAGLE_EYE_SET_TRACKING_UPGRADE_2", LUA_NATIVE_PLAYER__EAGLE_EYE_SET_TRACKING_UPGRADE_2);
		PLAYER.set_function("_0x1DA5C5B0923E1B85", LUA_NATIVE_PLAYER__0x1DA5C5B0923E1B85);
		PLAYER.set_function("_0xAAED694CE814817F", LUA_NATIVE_PLAYER__0xAAED694CE814817F);
		PLAYER.set_function("EAGLE_EYE_SET_CUSTOM_ENTITY_TINT", LUA_NATIVE_PLAYER_EAGLE_EYE_SET_CUSTOM_ENTITY_TINT);
		PLAYER.set_function("_0xBC02B3D151D3859F", LUA_NATIVE_PLAYER__0xBC02B3D151D3859F);
		PLAYER.set_function("_EAGLE_EYE_SET_CUSTOM_DISTANCE", LUA_NATIVE_PLAYER__EAGLE_EYE_SET_CUSTOM_DISTANCE);
		PLAYER.set_function("_0xF21C7A3F3FFBA629", LUA_NATIVE_PLAYER__0xF21C7A3F3FFBA629);
		PLAYER.set_function("_SET_PLAYER_MANAGE_BUFF_SUPER_JUMP", LUA_NATIVE_PLAYER__SET_PLAYER_MANAGE_BUFF_SUPER_JUMP);
		PLAYER.set_function("_SET_LOCAL_PLAYER_PERSONA_ABILITY_FLAG", LUA_NATIVE_PLAYER__SET_LOCAL_PLAYER_PERSONA_ABILITY_FLAG);
		PLAYER.set_function("_SET_PLAYER_MAX_AMMO_OVERRIDE_FOR_AMMO_TYPE", LUA_NATIVE_PLAYER__SET_PLAYER_MAX_AMMO_OVERRIDE_FOR_AMMO_TYPE);
		PLAYER.set_function("_0xC900A465364A85D6", LUA_NATIVE_PLAYER__0xC900A465364A85D6);
		PLAYER.set_function("_0xCFB2EED4FCB7BD77", LUA_NATIVE_PLAYER__0xCFB2EED4FCB7BD77);
		PLAYER.set_function("_0x2BB8D58E88777499", LUA_NATIVE_PLAYER__0x2BB8D58E88777499);
		PLAYER.set_function("_0x00EB5A760638DB55", LUA_NATIVE_PLAYER__0x00EB5A760638DB55);
		PLAYER.set_function("_0x65887EAC535A0B0C", LUA_NATIVE_PLAYER__0x65887EAC535A0B0C);
		PLAYER.set_function("_SET_WEAPON_DEGRADATION_MODIFIER", LUA_NATIVE_PLAYER__SET_WEAPON_DEGRADATION_MODIFIER);
		PLAYER.set_function("_SET_BOW_DRAW_REDUCTION_TIME_IN_DEADEYE", LUA_NATIVE_PLAYER__SET_BOW_DRAW_REDUCTION_TIME_IN_DEADEYE);
		PLAYER.set_function("_SET_BOW_STAMINA_DRAIN_SPEED", LUA_NATIVE_PLAYER__SET_BOW_STAMINA_DRAIN_SPEED);
		PLAYER.set_function("_SET_DAMAGE_CLOSE_DISTANCE_BONUS", LUA_NATIVE_PLAYER__SET_DAMAGE_CLOSE_DISTANCE_BONUS);
		PLAYER.set_function("_SET_DAMAGE_CLOSE_DISTANCE_BONUS_TOTAL", LUA_NATIVE_PLAYER__SET_DAMAGE_CLOSE_DISTANCE_BONUS_TOTAL);
		PLAYER.set_function("_SET_DAMAGE_FAR_DISTANCE_BONUS", LUA_NATIVE_PLAYER__SET_DAMAGE_FAR_DISTANCE_BONUS);
		PLAYER.set_function("_SET_DAMAGE_FAR_DISTANCE_BONUS_TOTAL", LUA_NATIVE_PLAYER__SET_DAMAGE_FAR_DISTANCE_BONUS_TOTAL);
		PLAYER.set_function("_0x6C54E69516CC56BD", LUA_NATIVE_PLAYER__0x6C54E69516CC56BD);
		PLAYER.set_function("_0x3A8611BD7BDE84F7", LUA_NATIVE_PLAYER__0x3A8611BD7BDE84F7);
		PLAYER.set_function("_0xC177C827CEFC0AA4", LUA_NATIVE_PLAYER__0xC177C827CEFC0AA4);
		PLAYER.set_function("_0xBD96185264DDAAEA", LUA_NATIVE_PLAYER__0xBD96185264DDAAEA);
		PLAYER.set_function("_0x628E742FE1F79C4A", LUA_NATIVE_PLAYER__0x628E742FE1F79C4A);
		PLAYER.set_function("_SET_PLAYER_INTERACTION_POSITIVE_RESPONSE", LUA_NATIVE_PLAYER__SET_PLAYER_INTERACTION_POSITIVE_RESPONSE);
		PLAYER.set_function("_SET_PLAYER_INTERACTION_NEGATIVE_RESPONSE", LUA_NATIVE_PLAYER__SET_PLAYER_INTERACTION_NEGATIVE_RESPONSE);
		PLAYER.set_function("_0x216BC0D3D2E413D2", LUA_NATIVE_PLAYER__0x216BC0D3D2E413D2);
		PLAYER.set_function("_0x45EF176B532CA851", LUA_NATIVE_PLAYER__0x45EF176B532CA851);
		PLAYER.set_function("_0xA342495F93B7B838", LUA_NATIVE_PLAYER__0xA342495F93B7B838);
		PLAYER.set_function("_0x3BB84F812E052C90", LUA_NATIVE_PLAYER__0x3BB84F812E052C90);
		PLAYER.set_function("_0x9FC5A003FB76EDBD", LUA_NATIVE_PLAYER__0x9FC5A003FB76EDBD);
		PLAYER.set_function("_0x0FAF95D71ED67ADE", LUA_NATIVE_PLAYER__0x0FAF95D71ED67ADE);
		PLAYER.set_function("_0x988C9045531B9FCE", LUA_NATIVE_PLAYER__0x988C9045531B9FCE);
		PLAYER.set_function("_0x06C3DB00B69D5435", LUA_NATIVE_PLAYER__0x06C3DB00B69D5435);
		PLAYER.set_function("_0xBB6EA5D59E926095", LUA_NATIVE_PLAYER__0xBB6EA5D59E926095);
		PLAYER.set_function("_0xE1D356F5A66D0FFA", LUA_NATIVE_PLAYER__0xE1D356F5A66D0FFA);
		PLAYER.set_function("_0x929DDD5538F3DF1F", LUA_NATIVE_PLAYER__0x929DDD5538F3DF1F);
		PLAYER.set_function("_0xFA7DAAE3959E6C7B", LUA_NATIVE_PLAYER__0xFA7DAAE3959E6C7B);
		PLAYER.set_function("_0x9461A8FAB0378E5B", LUA_NATIVE_PLAYER__0x9461A8FAB0378E5B);
		PLAYER.set_function("_0xCB61A63AA53D7D22", LUA_NATIVE_PLAYER__0xCB61A63AA53D7D22);
		PLAYER.set_function("_0xCFFC3ECCD7A5CCEB", LUA_NATIVE_PLAYER__0xCFFC3ECCD7A5CCEB);
		PLAYER.set_function("_0x76F7E1BCD623A429", LUA_NATIVE_PLAYER__0x76F7E1BCD623A429);
		PLAYER.set_function("_0x585CE159DB46FADB", LUA_NATIVE_PLAYER__0x585CE159DB46FADB);
		PLAYER.set_function("_SET_PLAYER_RESET_FLAG", LUA_NATIVE_PLAYER__SET_PLAYER_RESET_FLAG);
		PLAYER.set_function("_GET_PLAYER_RESET_FLAG", LUA_NATIVE_PLAYER__GET_PLAYER_RESET_FLAG);
		PLAYER.set_function("GET_MOUNT_OWNED_BY_PLAYER", LUA_NATIVE_PLAYER_GET_MOUNT_OWNED_BY_PLAYER);
		PLAYER.set_function("_GET_PLAYER_OWNER_OF_MOUNT", LUA_NATIVE_PLAYER__GET_PLAYER_OWNER_OF_MOUNT);
		PLAYER.set_function("_SET_PLAYER_OWNS_MOUNT", LUA_NATIVE_PLAYER__SET_PLAYER_OWNS_MOUNT);
		PLAYER.set_function("_GET_VEHICLE_OWNED_BY_PLAYER", LUA_NATIVE_PLAYER__GET_VEHICLE_OWNED_BY_PLAYER);
		PLAYER.set_function("_GET_PLAYER_OWNER_OF_VEHICLE", LUA_NATIVE_PLAYER__GET_PLAYER_OWNER_OF_VEHICLE);
		PLAYER.set_function("_SET_PLAYER_OWNS_VEHICLE", LUA_NATIVE_PLAYER__SET_PLAYER_OWNS_VEHICLE);
		PLAYER.set_function("_GET_PLAYER_HUNTING_WAGON", LUA_NATIVE_PLAYER__GET_PLAYER_HUNTING_WAGON);
		PLAYER.set_function("_SET_PLAYER_HUNTING_WAGON", LUA_NATIVE_PLAYER__SET_PLAYER_HUNTING_WAGON);
		PLAYER.set_function("_0x9044835BE9D9DBFE", LUA_NATIVE_PLAYER__0x9044835BE9D9DBFE);
		PLAYER.set_function("GET_DISCOVERABLE_NAME_HASH_AND_TYPE_FOR_ENTITY", LUA_NATIVE_PLAYER_GET_DISCOVERABLE_NAME_HASH_AND_TYPE_FOR_ENTITY);
		PLAYER.set_function("_GET_CONSTRUCTED_DISCOVERED_CHARACTER_NAME", LUA_NATIVE_PLAYER__GET_CONSTRUCTED_DISCOVERED_CHARACTER_NAME);
		PLAYER.set_function("GET_TARGET_CHARACTER_NAME_SCRIPT_OVERRIDE_HASH", LUA_NATIVE_PLAYER_GET_TARGET_CHARACTER_NAME_SCRIPT_OVERRIDE_HASH);
		PLAYER.set_function("GET_TARGET_CHARACTER_NAME_SCRIPT_OVERRIDE_RAW_STRING", LUA_NATIVE_PLAYER_GET_TARGET_CHARACTER_NAME_SCRIPT_OVERRIDE_RAW_STRING);
		PLAYER.set_function("GET_TARGET_CHARACTER_NAME_FOR_LOCAL_PLAYER", LUA_NATIVE_PLAYER_GET_TARGET_CHARACTER_NAME_FOR_LOCAL_PLAYER);
		PLAYER.set_function("_0xDA9D7BE231FE865F", LUA_NATIVE_PLAYER__0xDA9D7BE231FE865F);
		PLAYER.set_function("_SET_PLAYER_HAS_DISCOVERED_CHARACTER_NAME_SP", LUA_NATIVE_PLAYER__SET_PLAYER_HAS_DISCOVERED_CHARACTER_NAME_SP);
		PLAYER.set_function("_GET_HAS_PLAYER_DISCOVERED_CHARACTER_NAME_SP", LUA_NATIVE_PLAYER__GET_HAS_PLAYER_DISCOVERED_CHARACTER_NAME_SP);
		PLAYER.set_function("_0xCDDD4B74660E2335", LUA_NATIVE_PLAYER__0xCDDD4B74660E2335);
		PLAYER.set_function("_0x77E83C315A3B31CA", LUA_NATIVE_PLAYER__0x77E83C315A3B31CA);
		PLAYER.set_function("_SET_PLAYER_HAS_DISCOVERED_CHARACTER_NAME_MP", LUA_NATIVE_PLAYER__SET_PLAYER_HAS_DISCOVERED_CHARACTER_NAME_MP);
		PLAYER.set_function("GET_HAS_PLAYER_DISCOVERED_CHARACTER_NAME_MP", LUA_NATIVE_PLAYER_GET_HAS_PLAYER_DISCOVERED_CHARACTER_NAME_MP);
		PLAYER.set_function("_MODIFY_PLAYER_DISCOVERED_CHARACTER_NAME_MP_SET_UNDISCOVERED", LUA_NATIVE_PLAYER__MODIFY_PLAYER_DISCOVERED_CHARACTER_NAME_MP_SET_UNDISCOVERED);
		PLAYER.set_function("_SET_SHOW_INFO_CARD", LUA_NATIVE_PLAYER__SET_SHOW_INFO_CARD);
		PLAYER.set_function("_0x4DBC4873707E8FD6", LUA_NATIVE_PLAYER__0x4DBC4873707E8FD6);
		PLAYER.set_function("_0xCEDC16930526F728", LUA_NATIVE_PLAYER__0xCEDC16930526F728);
		PLAYER.set_function("_0x14E57F88BA0A07FC", LUA_NATIVE_PLAYER__0x14E57F88BA0A07FC);
		PLAYER.set_function("_0x2E1ABE627C95ED9B", LUA_NATIVE_PLAYER__0x2E1ABE627C95ED9B);
		PLAYER.set_function("_0x497A18F8F88AA9D8", LUA_NATIVE_PLAYER__0x497A18F8F88AA9D8);
		PLAYER.set_function("_0x4F0D2256AAE94EDA", LUA_NATIVE_PLAYER__0x4F0D2256AAE94EDA);
		PLAYER.set_function("_SET_LOCKON_FOCUS_FIRE_VFX", LUA_NATIVE_PLAYER__SET_LOCKON_FOCUS_FIRE_VFX);
		PLAYER.set_function("_0x0B7803F6F7BB43E0", LUA_NATIVE_PLAYER__0x0B7803F6F7BB43E0);
		PLAYER.set_function("_0xC74EB3F2EC169F6B", LUA_NATIVE_PLAYER__0xC74EB3F2EC169F6B);
		PLAYER.set_function("_0x3B296934DB026873", LUA_NATIVE_PLAYER__0x3B296934DB026873);
		PLAYER.set_function("SET_MIN_TIME_BEFORE_HORSE_BUCKING", LUA_NATIVE_PLAYER_SET_MIN_TIME_BEFORE_HORSE_BUCKING);
		PLAYER.set_function("_0xF4CB347D7B5EB0FD", LUA_NATIVE_PLAYER__0xF4CB347D7B5EB0FD);
		PLAYER.set_function("_0xCD7CA3013FD12749", LUA_NATIVE_PLAYER__0xCD7CA3013FD12749);
		PLAYER.set_function("_FORCE_REST_SCENARIO", LUA_NATIVE_PLAYER__FORCE_REST_SCENARIO);
		PLAYER.set_function("_0x57028FD99886F6F9", LUA_NATIVE_PLAYER__0x57028FD99886F6F9);
		PLAYER.set_function("_0x35A33783EC3C3448", LUA_NATIVE_PLAYER__0x35A33783EC3C3448);
		PLAYER.set_function("_0x39D8D7082BC34B72", LUA_NATIVE_PLAYER__0x39D8D7082BC34B72);
		PLAYER.set_function("_0x1AD8AD999C27F44A", LUA_NATIVE_PLAYER__0x1AD8AD999C27F44A);
	}
}
