#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static bool LUA_NATIVE_VOICE__0xCCF71FCFA0070B1A()
	{
		auto retval = (bool)VOICE::_0xCCF71FCFA0070B1A();
		return retval;
	}

	static void LUA_NATIVE_VOICE__0x79F478FF5F9F4F05(bool enabled)
	{
		VOICE::_0x79F478FF5F9F4F05(enabled);
	}

	static bool LUA_NATIVE_VOICE__0xAA35FD9ABAB490A3(Player player)
	{
		auto retval = (bool)VOICE::_0xAA35FD9ABAB490A3(player);
		return retval;
	}

	static bool LUA_NATIVE_VOICE__0x356135B9B10A2A82(uintptr_t gamerHandle)
	{
		auto retval = (bool)VOICE::_0x356135B9B10A2A82((Any*)gamerHandle);
		return retval;
	}

	static bool LUA_NATIVE_VOICE__0xEF6F2A35FAAF2ED7(Player player)
	{
		auto retval = (bool)VOICE::_0xEF6F2A35FAAF2ED7(player);
		return retval;
	}

	static bool LUA_NATIVE_VOICE__0x49623BCFC3A3D829(Player player, bool muted)
	{
		auto retval = (bool)VOICE::_0x49623BCFC3A3D829(player, muted);
		return retval;
	}

	static bool LUA_NATIVE_VOICE__0x919AF2D93E9AA89D(Player player)
	{
		auto retval = (bool)VOICE::_0x919AF2D93E9AA89D(player);
		return retval;
	}

	static bool LUA_NATIVE_VOICE__0x0DED260A1958A82E(Player player)
	{
		auto retval = (bool)VOICE::_0x0DED260A1958A82E(player);
		return retval;
	}

	static bool LUA_NATIVE_VOICE__0x8E462DB1EAA9C47C(Player player)
	{
		auto retval = (bool)VOICE::_0x8E462DB1EAA9C47C(player);
		return retval;
	}

	static float LUA_NATIVE_VOICE__0x5CA7FB7D6DE49DCC(Player player)
	{
		auto retval = VOICE::_0x5CA7FB7D6DE49DCC(player);
		return retval;
	}

	static void LUA_NATIVE_VOICE__0x58125B691F6827D5(float proximity)
	{
		VOICE::_0x58125B691F6827D5(proximity);
	}

	static float LUA_NATIVE_VOICE__0x2F82CAB262C8AE26(Player player)
	{
		auto retval = VOICE::_0x2F82CAB262C8AE26(player);
		return retval;
	}

	static void LUA_NATIVE_VOICE__0x08797A8C03868CB8(float threshold)
	{
		VOICE::_0x08797A8C03868CB8(threshold);
	}

	static void LUA_NATIVE_VOICE__0xB779F4FA19269AEC(bool flag)
	{
		VOICE::_0xB779F4FA19269AEC(flag);
	}

	static void LUA_NATIVE_VOICE__0x1FBF7F5BA7E4BE3A(int p0)
	{
		VOICE::_0x1FBF7F5BA7E4BE3A(p0);
	}

	static void LUA_NATIVE_VOICE__0xDC9B361CB7776673(Player player)
	{
		VOICE::_0xDC9B361CB7776673(player);
	}

	static void LUA_NATIVE_VOICE__0xEC8703E4536A9952()
	{
		VOICE::_0xEC8703E4536A9952();
	}

	static Any LUA_NATIVE_VOICE__0xDB622ECD3DCBE078(Player player)
	{
		auto retval = VOICE::_0xDB622ECD3DCBE078(player);
		return retval;
	}

	static void LUA_NATIVE_VOICE__0xB6E79850B759A30E(int teamId, bool allow)
	{
		VOICE::_0xB6E79850B759A30E(teamId, allow);
	}

	static void LUA_NATIVE_VOICE__0x4791899615D70FA2(Player player, int p1, int p2)
	{
		VOICE::_0x4791899615D70FA2(player, p1, p2);
	}

	static void LUA_NATIVE_VOICE__0xF8938CF3984092A5(Player player)
	{
		VOICE::_0xF8938CF3984092A5(player);
	}

	static int LUA_NATIVE_VOICE__0x767931C727DF2ED7(Player player, int p1)
	{
		auto retval = VOICE::_0x767931C727DF2ED7(player, p1);
		return retval;
	}

	static void LUA_NATIVE_VOICE__0x1C38C3577901AF1F()
	{
		VOICE::_0x1C38C3577901AF1F();
	}

	static void LUA_NATIVE_VOICE__0xB3E8841F6BDAF83E()
	{
		VOICE::_0xB3E8841F6BDAF83E();
	}

	void RegisterNatives_VOICE(sol::state& L)
	{
		auto VOICE = L["VOICE"].get_or_create<sol::table>();
		VOICE.set_function("_0xCCF71FCFA0070B1A", LUA_NATIVE_VOICE__0xCCF71FCFA0070B1A);
		VOICE.set_function("_0x79F478FF5F9F4F05", LUA_NATIVE_VOICE__0x79F478FF5F9F4F05);
		VOICE.set_function("_0xAA35FD9ABAB490A3", LUA_NATIVE_VOICE__0xAA35FD9ABAB490A3);
		VOICE.set_function("_0x356135B9B10A2A82", LUA_NATIVE_VOICE__0x356135B9B10A2A82);
		VOICE.set_function("_0xEF6F2A35FAAF2ED7", LUA_NATIVE_VOICE__0xEF6F2A35FAAF2ED7);
		VOICE.set_function("_0x49623BCFC3A3D829", LUA_NATIVE_VOICE__0x49623BCFC3A3D829);
		VOICE.set_function("_0x919AF2D93E9AA89D", LUA_NATIVE_VOICE__0x919AF2D93E9AA89D);
		VOICE.set_function("_0x0DED260A1958A82E", LUA_NATIVE_VOICE__0x0DED260A1958A82E);
		VOICE.set_function("_0x8E462DB1EAA9C47C", LUA_NATIVE_VOICE__0x8E462DB1EAA9C47C);
		VOICE.set_function("_0x5CA7FB7D6DE49DCC", LUA_NATIVE_VOICE__0x5CA7FB7D6DE49DCC);
		VOICE.set_function("_0x58125B691F6827D5", LUA_NATIVE_VOICE__0x58125B691F6827D5);
		VOICE.set_function("_0x2F82CAB262C8AE26", LUA_NATIVE_VOICE__0x2F82CAB262C8AE26);
		VOICE.set_function("_0x08797A8C03868CB8", LUA_NATIVE_VOICE__0x08797A8C03868CB8);
		VOICE.set_function("_0xB779F4FA19269AEC", LUA_NATIVE_VOICE__0xB779F4FA19269AEC);
		VOICE.set_function("_0x1FBF7F5BA7E4BE3A", LUA_NATIVE_VOICE__0x1FBF7F5BA7E4BE3A);
		VOICE.set_function("_0xDC9B361CB7776673", LUA_NATIVE_VOICE__0xDC9B361CB7776673);
		VOICE.set_function("_0xEC8703E4536A9952", LUA_NATIVE_VOICE__0xEC8703E4536A9952);
		VOICE.set_function("_0xDB622ECD3DCBE078", LUA_NATIVE_VOICE__0xDB622ECD3DCBE078);
		VOICE.set_function("_0xB6E79850B759A30E", LUA_NATIVE_VOICE__0xB6E79850B759A30E);
		VOICE.set_function("_0x4791899615D70FA2", LUA_NATIVE_VOICE__0x4791899615D70FA2);
		VOICE.set_function("_0xF8938CF3984092A5", LUA_NATIVE_VOICE__0xF8938CF3984092A5);
		VOICE.set_function("_0x767931C727DF2ED7", LUA_NATIVE_VOICE__0x767931C727DF2ED7);
		VOICE.set_function("_0x1C38C3577901AF1F", LUA_NATIVE_VOICE__0x1C38C3577901AF1F);
		VOICE.set_function("_0xB3E8841F6BDAF83E", LUA_NATIVE_VOICE__0xB3E8841F6BDAF83E);
	}
}
