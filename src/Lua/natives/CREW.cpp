#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_CREW_NETWORK_FIND_GAMERS_IN_CREW(int crewId)
	{
		auto retval = (bool)CREW::NETWORK_FIND_GAMERS_IN_CREW(crewId);
		return retval;
	}

	static bool LUA_NATIVE_CREW_NETWORK_CLAN_SERVICE_IS_VALID()
	{
		auto retval = (bool)CREW::NETWORK_CLAN_SERVICE_IS_VALID();
		return retval;
	}

	static bool LUA_NATIVE_CREW_NETWORK_CLAN_PLAYER_IS_ACTIVE(uintptr_t gamerHandle)
	{
		auto retval = (bool)CREW::NETWORK_CLAN_PLAYER_IS_ACTIVE((Any*)gamerHandle);
		return retval;
	}

	static bool LUA_NATIVE_CREW_NETWORK_CLAN_PLAYER_GET_DESC(uintptr_t memberInfo, int sizeOfData, uintptr_t gamerHandle)
	{
		auto retval = (bool)CREW::NETWORK_CLAN_PLAYER_GET_DESC((Any*)memberInfo, sizeOfData, (Any*)gamerHandle);
		return retval;
	}

	static int LUA_NATIVE_CREW_NETWORK_CLAN_GET_LOCAL_MEMBERSHIPS_COUNT()
	{
		auto retval = CREW::NETWORK_CLAN_GET_LOCAL_MEMBERSHIPS_COUNT();
		return retval;
	}

	static bool LUA_NATIVE_CREW_NETWORK_CLAN_GET_MEMBERSHIP_DESC(uintptr_t memberInfo, int membershipIndex)
	{
		auto retval = (bool)CREW::NETWORK_CLAN_GET_MEMBERSHIP_DESC((Any*)memberInfo, membershipIndex);
		return retval;
	}

	static bool LUA_NATIVE_CREW__0x58D378AF2C8765B7(Any p0)
	{
		auto retval = (bool)CREW::_0x58D378AF2C8765B7(p0);
		return retval;
	}

	static bool LUA_NATIVE_CREW__NETWORK_CLAN_INVITE_PLAYER(Any p0)
	{
		auto retval = (bool)CREW::_NETWORK_CLAN_INVITE_PLAYER(p0);
		return retval;
	}

	static bool LUA_NATIVE_CREW__NETWORK_ACCEPT_CLAN_INVITE(int crewInviteIndex)
	{
		auto retval = (bool)CREW::_NETWORK_ACCEPT_CLAN_INVITE(crewInviteIndex);
		return retval;
	}

	static bool LUA_NATIVE_CREW_NETWORK_CLAN_REQUEST_EMBLEM(int clanId)
	{
		auto retval = (bool)CREW::NETWORK_CLAN_REQUEST_EMBLEM(clanId);
		return retval;
	}

	static bool LUA_NATIVE_CREW_NETWORK_CLAN_IS_EMBLEM_READY(int clanId, uintptr_t outTXDName)
	{
		auto retval = (bool)CREW::NETWORK_CLAN_IS_EMBLEM_READY(clanId, (Any*)outTXDName);
		return retval;
	}

	static void LUA_NATIVE_CREW_NETWORK_CLAN_RELEASE_EMBLEM(int clanId)
	{
		CREW::NETWORK_CLAN_RELEASE_EMBLEM(clanId);
	}

	static Any LUA_NATIVE_CREW_NETWORK_GET_PRIMARY_CLAN_DATA_CLEAR()
	{
		auto retval = CREW::NETWORK_GET_PRIMARY_CLAN_DATA_CLEAR();
		return retval;
	}

	static bool LUA_NATIVE_CREW_NETWORK_GET_PRIMARY_CLAN_DATA_START(uintptr_t gamerHandleData, int nGamerHandles)
	{
		auto retval = (bool)CREW::NETWORK_GET_PRIMARY_CLAN_DATA_START((Any*)gamerHandleData, nGamerHandles);
		return retval;
	}

	static bool LUA_NATIVE_CREW_NETWORK_GET_PRIMARY_CLAN_DATA_PENDING()
	{
		auto retval = (bool)CREW::NETWORK_GET_PRIMARY_CLAN_DATA_PENDING();
		return retval;
	}

	static bool LUA_NATIVE_CREW_NETWORK_GET_PRIMARY_CLAN_DATA_SUCCESS()
	{
		auto retval = (bool)CREW::NETWORK_GET_PRIMARY_CLAN_DATA_SUCCESS();
		return retval;
	}

	static bool LUA_NATIVE_CREW_NETWORK_GET_PRIMARY_CLAN_DATA_NEW(uintptr_t hGamer, uintptr_t memberInfo)
	{
		auto retval = (bool)CREW::NETWORK_GET_PRIMARY_CLAN_DATA_NEW((Any*)hGamer, (Any*)memberInfo);
		return retval;
	}

	static Any LUA_NATIVE_CREW__NETWORK_CLAN_SET_ACTIVE(Any p0)
	{
		auto retval = CREW::_NETWORK_CLAN_SET_ACTIVE(p0);
		return retval;
	}

	void RegisterNatives_CREW(sol::state& L)
	{
		auto CREW = L["CREW"].get_or_create<sol::table>();
		CREW.set_function("NETWORK_FIND_GAMERS_IN_CREW", LUA_NATIVE_CREW_NETWORK_FIND_GAMERS_IN_CREW);
		CREW.set_function("NETWORK_CLAN_SERVICE_IS_VALID", LUA_NATIVE_CREW_NETWORK_CLAN_SERVICE_IS_VALID);
		CREW.set_function("NETWORK_CLAN_PLAYER_IS_ACTIVE", LUA_NATIVE_CREW_NETWORK_CLAN_PLAYER_IS_ACTIVE);
		CREW.set_function("NETWORK_CLAN_PLAYER_GET_DESC", LUA_NATIVE_CREW_NETWORK_CLAN_PLAYER_GET_DESC);
		CREW.set_function("NETWORK_CLAN_GET_LOCAL_MEMBERSHIPS_COUNT", LUA_NATIVE_CREW_NETWORK_CLAN_GET_LOCAL_MEMBERSHIPS_COUNT);
		CREW.set_function("NETWORK_CLAN_GET_MEMBERSHIP_DESC", LUA_NATIVE_CREW_NETWORK_CLAN_GET_MEMBERSHIP_DESC);
		CREW.set_function("_0x58D378AF2C8765B7", LUA_NATIVE_CREW__0x58D378AF2C8765B7);
		CREW.set_function("_NETWORK_CLAN_INVITE_PLAYER", LUA_NATIVE_CREW__NETWORK_CLAN_INVITE_PLAYER);
		CREW.set_function("_NETWORK_ACCEPT_CLAN_INVITE", LUA_NATIVE_CREW__NETWORK_ACCEPT_CLAN_INVITE);
		CREW.set_function("NETWORK_CLAN_REQUEST_EMBLEM", LUA_NATIVE_CREW_NETWORK_CLAN_REQUEST_EMBLEM);
		CREW.set_function("NETWORK_CLAN_IS_EMBLEM_READY", LUA_NATIVE_CREW_NETWORK_CLAN_IS_EMBLEM_READY);
		CREW.set_function("NETWORK_CLAN_RELEASE_EMBLEM", LUA_NATIVE_CREW_NETWORK_CLAN_RELEASE_EMBLEM);
		CREW.set_function("NETWORK_GET_PRIMARY_CLAN_DATA_CLEAR", LUA_NATIVE_CREW_NETWORK_GET_PRIMARY_CLAN_DATA_CLEAR);
		CREW.set_function("NETWORK_GET_PRIMARY_CLAN_DATA_START", LUA_NATIVE_CREW_NETWORK_GET_PRIMARY_CLAN_DATA_START);
		CREW.set_function("NETWORK_GET_PRIMARY_CLAN_DATA_PENDING", LUA_NATIVE_CREW_NETWORK_GET_PRIMARY_CLAN_DATA_PENDING);
		CREW.set_function("NETWORK_GET_PRIMARY_CLAN_DATA_SUCCESS", LUA_NATIVE_CREW_NETWORK_GET_PRIMARY_CLAN_DATA_SUCCESS);
		CREW.set_function("NETWORK_GET_PRIMARY_CLAN_DATA_NEW", LUA_NATIVE_CREW_NETWORK_GET_PRIMARY_CLAN_DATA_NEW);
		CREW.set_function("_NETWORK_CLAN_SET_ACTIVE", LUA_NATIVE_CREW__NETWORK_CLAN_SET_ACTIVE);
	}
}
