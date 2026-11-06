#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_GANG_NETWORK_IS_GANG_ID_VALID(Any gangId)
	{
		auto retval = (bool)GANG::NETWORK_IS_GANG_ID_VALID(gangId);
		return retval;
	}

	static bool LUA_NATIVE_GANG_NETWORK_IS_GANG_IN_SESSION(Any gangId)
	{
		auto retval = (bool)GANG::NETWORK_IS_GANG_IN_SESSION(gangId);
		return retval;
	}

	static bool LUA_NATIVE_GANG_NETWORK_IS_GANG_ACTIVE(Any gangId)
	{
		auto retval = (bool)GANG::NETWORK_IS_GANG_ACTIVE(gangId);
		return retval;
	}

	static bool LUA_NATIVE_GANG__NETWORK_IS_GANG_OPEN(Any gangId)
	{
		auto retval = (bool)GANG::_NETWORK_IS_GANG_OPEN(gangId);
		return retval;
	}

	static int LUA_NATIVE_GANG__NETWORK_GET_GANG_PRIVACY()
	{
		auto retval = GANG::_NETWORK_GET_GANG_PRIVACY();
		return retval;
	}

	static void LUA_NATIVE_GANG__NETWORK_START_GANG(bool openStatus, int campSize)
	{
		GANG::_NETWORK_START_GANG(openStatus, campSize);
	}

	static bool LUA_NATIVE_GANG__NETWORK_SET_GANG_PRIVACY(int privacyType)
	{
		auto retval = (bool)GANG::_NETWORK_SET_GANG_PRIVACY(privacyType);
		return retval;
	}

	static void LUA_NATIVE_GANG__NETWORK_LEAVE_GANG(bool disband)
	{
		GANG::_NETWORK_LEAVE_GANG(disband);
	}

	static void LUA_NATIVE_GANG__NETWORK_KICK_GANG_MEMBER(Player player, int banTimeSeconds)
	{
		GANG::_NETWORK_KICK_GANG_MEMBER(player, banTimeSeconds);
	}

	static bool LUA_NATIVE_GANG__NETWORK_REQUEST_GANG_JOIN(Any gangId)
	{
		auto retval = (bool)GANG::_NETWORK_REQUEST_GANG_JOIN(gangId);
		return retval;
	}

	static bool LUA_NATIVE_GANG_NETWORK_IS_GANG_LEADER(Player player)
	{
		auto retval = (bool)GANG::NETWORK_IS_GANG_LEADER(player);
		return retval;
	}

	static bool LUA_NATIVE_GANG__NETWORK_IS_GANG_MEMBER(Any gangId, Player player)
	{
		auto retval = (bool)GANG::_NETWORK_IS_GANG_MEMBER(gangId, player);
		return retval;
	}

	static bool LUA_NATIVE_GANG_NETWORK_IS_IN_SAME_GANG(Player player1, Player player2)
	{
		auto retval = (bool)GANG::NETWORK_IS_IN_SAME_GANG(player1, player2);
		return retval;
	}

	static bool LUA_NATIVE_GANG__NETWORK_IS_IN_MY_GANG(Player player)
	{
		auto retval = (bool)GANG::_NETWORK_IS_IN_MY_GANG(player);
		return retval;
	}

	static int LUA_NATIVE_GANG_NETWORK_GET_NUM_GANG_MEMBERS(Any gangId)
	{
		auto retval = GANG::NETWORK_GET_NUM_GANG_MEMBERS(gangId);
		return retval;
	}

	static int LUA_NATIVE_GANG__NETWORK_GET_GANG_SIZE(Any gangId)
	{
		auto retval = GANG::_NETWORK_GET_GANG_SIZE(gangId);
		return retval;
	}

	static bool LUA_NATIVE_GANG__NETWORK_SET_GANG_SIZE(int size)
	{
		auto retval = (bool)GANG::_NETWORK_SET_GANG_SIZE(size);
		return retval;
	}

	static Any LUA_NATIVE_GANG_NETWORK_GET_GANG_ID(Player player)
	{
		auto retval = GANG::NETWORK_GET_GANG_ID(player);
		return retval;
	}

	static int LUA_NATIVE_GANG__NETWORK_GET_GANG_MEMBERS(Any gangId, uintptr_t memberHandles)
	{
		auto retval = GANG::_NETWORK_GET_GANG_MEMBERS(gangId, (Any*)memberHandles);
		return retval;
	}

	static bool LUA_NATIVE_GANG__0xDA801F7F6A5278D3(Player player)
	{
		auto retval = (bool)GANG::_0xDA801F7F6A5278D3(player);
		return retval;
	}

	static Any LUA_NATIVE_GANG__0x2F7EB8B6F6AFE79C(Any p0)
	{
		auto retval = GANG::_0x2F7EB8B6F6AFE79C(p0);
		return retval;
	}

	static Any LUA_NATIVE_GANG__0x53A94294FDDCF98C(Any p0, Any p1)
	{
		auto retval = GANG::_0x53A94294FDDCF98C(p0, p1);
		return retval;
	}

	static Player LUA_NATIVE_GANG_NETWORK_GET_GANG_LEADER(Any gangId)
	{
		auto retval = GANG::NETWORK_GET_GANG_LEADER(gangId);
		return retval;
	}

	static bool LUA_NATIVE_GANG__NETWORK_GET_GANG_LEADER_HANDLE(Any gangId, uintptr_t gamerHandle)
	{
		auto retval = (bool)GANG::_NETWORK_GET_GANG_LEADER_HANDLE(gangId, (Any*)gamerHandle);
		return retval;
	}

	static bool LUA_NATIVE_GANG__0x6102830F764B3DE1(Player player)
	{
		auto retval = (bool)GANG::_0x6102830F764B3DE1(player);
		return retval;
	}

	static void LUA_NATIVE_GANG__0xB38C256498748413()
	{
		GANG::_0xB38C256498748413();
	}

	static Any LUA_NATIVE_GANG__0xE4C64CD37CB176AA(int p0)
	{
		auto retval = GANG::_0xE4C64CD37CB176AA(p0);
		return retval;
	}

	static Any LUA_NATIVE_GANG__0x7BAA30C9BBE8AEE7(Any p0, Any p1)
	{
		auto retval = GANG::_0x7BAA30C9BBE8AEE7(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_GANG__0x0E5C9FB9ED5DFF1C(Any p0)
	{
		auto retval = GANG::_0x0E5C9FB9ED5DFF1C(p0);
		return retval;
	}

	static void LUA_NATIVE_GANG__0xB22B1D9F74095382(Any p0)
	{
		GANG::_0xB22B1D9F74095382(p0);
	}

	static void LUA_NATIVE_GANG__0xEE4F20004D0288B7()
	{
		GANG::_0xEE4F20004D0288B7();
	}

	static void LUA_NATIVE_GANG__0xAD22AB64FA428DF3(Any p0)
	{
		GANG::_0xAD22AB64FA428DF3(p0);
	}

	static Any LUA_NATIVE_GANG__0x48D82C83987E18E4(Any p0)
	{
		auto retval = GANG::_0x48D82C83987E18E4(p0);
		return retval;
	}

	static void LUA_NATIVE_GANG__0xA9CEAE8D6637FBAD(Any p0)
	{
		GANG::_0xA9CEAE8D6637FBAD(p0);
	}

	static Any LUA_NATIVE_GANG__0x51C5EF47086AA0D7()
	{
		auto retval = GANG::_0x51C5EF47086AA0D7();
		return retval;
	}

	static Any LUA_NATIVE_GANG__0x644E02F24F9D4E98(Any p0, Any p1)
	{
		auto retval = GANG::_0x644E02F24F9D4E98(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_GANG__0x3ADC71A66356D706()
	{
		auto retval = GANG::_0x3ADC71A66356D706();
		return retval;
	}

	static Any LUA_NATIVE_GANG__0xFA7C5B7E087A4CEB()
	{
		auto retval = GANG::_0xFA7C5B7E087A4CEB();
		return retval;
	}

	static Any LUA_NATIVE_GANG__0x1F11702DDBD915C6(Any p0, Any p1)
	{
		auto retval = GANG::_0x1F11702DDBD915C6(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_GANG__0x7933754F260B428A(Player player)
	{
		auto retval = GANG::_0x7933754F260B428A(player);
		return retval;
	}

	static Any LUA_NATIVE_GANG__0xAFD3599A3CC5637D()
	{
		auto retval = GANG::_0xAFD3599A3CC5637D();
		return retval;
	}

	static void LUA_NATIVE_GANG__0xC81A9E2C8EFD28D5(Any p0)
	{
		GANG::_0xC81A9E2C8EFD28D5(p0);
	}

	void RegisterNatives_GANG(sol::state& L)
	{
		auto GANG = L["GANG"].get_or_create<sol::table>();
		GANG.set_function("NETWORK_IS_GANG_ID_VALID", LUA_NATIVE_GANG_NETWORK_IS_GANG_ID_VALID);
		GANG.set_function("NETWORK_IS_GANG_IN_SESSION", LUA_NATIVE_GANG_NETWORK_IS_GANG_IN_SESSION);
		GANG.set_function("NETWORK_IS_GANG_ACTIVE", LUA_NATIVE_GANG_NETWORK_IS_GANG_ACTIVE);
		GANG.set_function("_NETWORK_IS_GANG_OPEN", LUA_NATIVE_GANG__NETWORK_IS_GANG_OPEN);
		GANG.set_function("_NETWORK_GET_GANG_PRIVACY", LUA_NATIVE_GANG__NETWORK_GET_GANG_PRIVACY);
		GANG.set_function("_NETWORK_START_GANG", LUA_NATIVE_GANG__NETWORK_START_GANG);
		GANG.set_function("_NETWORK_SET_GANG_PRIVACY", LUA_NATIVE_GANG__NETWORK_SET_GANG_PRIVACY);
		GANG.set_function("_NETWORK_LEAVE_GANG", LUA_NATIVE_GANG__NETWORK_LEAVE_GANG);
		GANG.set_function("_NETWORK_KICK_GANG_MEMBER", LUA_NATIVE_GANG__NETWORK_KICK_GANG_MEMBER);
		GANG.set_function("_NETWORK_REQUEST_GANG_JOIN", LUA_NATIVE_GANG__NETWORK_REQUEST_GANG_JOIN);
		GANG.set_function("NETWORK_IS_GANG_LEADER", LUA_NATIVE_GANG_NETWORK_IS_GANG_LEADER);
		GANG.set_function("_NETWORK_IS_GANG_MEMBER", LUA_NATIVE_GANG__NETWORK_IS_GANG_MEMBER);
		GANG.set_function("NETWORK_IS_IN_SAME_GANG", LUA_NATIVE_GANG_NETWORK_IS_IN_SAME_GANG);
		GANG.set_function("_NETWORK_IS_IN_MY_GANG", LUA_NATIVE_GANG__NETWORK_IS_IN_MY_GANG);
		GANG.set_function("NETWORK_GET_NUM_GANG_MEMBERS", LUA_NATIVE_GANG_NETWORK_GET_NUM_GANG_MEMBERS);
		GANG.set_function("_NETWORK_GET_GANG_SIZE", LUA_NATIVE_GANG__NETWORK_GET_GANG_SIZE);
		GANG.set_function("_NETWORK_SET_GANG_SIZE", LUA_NATIVE_GANG__NETWORK_SET_GANG_SIZE);
		GANG.set_function("NETWORK_GET_GANG_ID", LUA_NATIVE_GANG_NETWORK_GET_GANG_ID);
		GANG.set_function("_NETWORK_GET_GANG_MEMBERS", LUA_NATIVE_GANG__NETWORK_GET_GANG_MEMBERS);
		GANG.set_function("_0xDA801F7F6A5278D3", LUA_NATIVE_GANG__0xDA801F7F6A5278D3);
		GANG.set_function("_0x2F7EB8B6F6AFE79C", LUA_NATIVE_GANG__0x2F7EB8B6F6AFE79C);
		GANG.set_function("_0x53A94294FDDCF98C", LUA_NATIVE_GANG__0x53A94294FDDCF98C);
		GANG.set_function("NETWORK_GET_GANG_LEADER", LUA_NATIVE_GANG_NETWORK_GET_GANG_LEADER);
		GANG.set_function("_NETWORK_GET_GANG_LEADER_HANDLE", LUA_NATIVE_GANG__NETWORK_GET_GANG_LEADER_HANDLE);
		GANG.set_function("_0x6102830F764B3DE1", LUA_NATIVE_GANG__0x6102830F764B3DE1);
		GANG.set_function("_0xB38C256498748413", LUA_NATIVE_GANG__0xB38C256498748413);
		GANG.set_function("_0xE4C64CD37CB176AA", LUA_NATIVE_GANG__0xE4C64CD37CB176AA);
		GANG.set_function("_0x7BAA30C9BBE8AEE7", LUA_NATIVE_GANG__0x7BAA30C9BBE8AEE7);
		GANG.set_function("_0x0E5C9FB9ED5DFF1C", LUA_NATIVE_GANG__0x0E5C9FB9ED5DFF1C);
		GANG.set_function("_0xB22B1D9F74095382", LUA_NATIVE_GANG__0xB22B1D9F74095382);
		GANG.set_function("_0xEE4F20004D0288B7", LUA_NATIVE_GANG__0xEE4F20004D0288B7);
		GANG.set_function("_0xAD22AB64FA428DF3", LUA_NATIVE_GANG__0xAD22AB64FA428DF3);
		GANG.set_function("_0x48D82C83987E18E4", LUA_NATIVE_GANG__0x48D82C83987E18E4);
		GANG.set_function("_0xA9CEAE8D6637FBAD", LUA_NATIVE_GANG__0xA9CEAE8D6637FBAD);
		GANG.set_function("_0x51C5EF47086AA0D7", LUA_NATIVE_GANG__0x51C5EF47086AA0D7);
		GANG.set_function("_0x644E02F24F9D4E98", LUA_NATIVE_GANG__0x644E02F24F9D4E98);
		GANG.set_function("_0x3ADC71A66356D706", LUA_NATIVE_GANG__0x3ADC71A66356D706);
		GANG.set_function("_0xFA7C5B7E087A4CEB", LUA_NATIVE_GANG__0xFA7C5B7E087A4CEB);
		GANG.set_function("_0x1F11702DDBD915C6", LUA_NATIVE_GANG__0x1F11702DDBD915C6);
		GANG.set_function("_0x7933754F260B428A", LUA_NATIVE_GANG__0x7933754F260B428A);
		GANG.set_function("_0xAFD3599A3CC5637D", LUA_NATIVE_GANG__0xAFD3599A3CC5637D);
		GANG.set_function("_0xC81A9E2C8EFD28D5", LUA_NATIVE_GANG__0xC81A9E2C8EFD28D5);
	}
}
