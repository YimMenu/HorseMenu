#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static int LUA_NATIVE_MONEY__MONEY_GET_CASH_BALANCE()
	{
		auto retval = MONEY::_MONEY_GET_CASH_BALANCE();
		return retval;
	}

	static bool LUA_NATIVE_MONEY__MONEY_DECREMENT_CASH_BALANCE(int amount)
	{
		auto retval = (bool)MONEY::_MONEY_DECREMENT_CASH_BALANCE(amount);
		return retval;
	}

	static bool LUA_NATIVE_MONEY__MONEY_INCREMENT_CASH_BALANCE(int amount, Hash addReason)
	{
		auto retval = (bool)MONEY::_MONEY_INCREMENT_CASH_BALANCE(amount, addReason);
		return retval;
	}

	static const char* LUA_NATIVE_MONEY__NETWORK_GET_STRING_CASH_BALANCE()
	{
		auto retval = MONEY::_NETWORK_GET_STRING_CASH_BALANCE();
		return retval;
	}

	static bool LUA_NATIVE_MONEY__NETWORK_IS_MONEY_BALANCE_NOT_LESS_THAN(int cashBalance, int goldBarBalance)
	{
		auto retval = (bool)MONEY::_NETWORK_IS_MONEY_BALANCE_NOT_LESS_THAN(cashBalance, goldBarBalance);
		return retval;
	}

	static const char* LUA_NATIVE_MONEY__0xA46FD001D1BE896C()
	{
		auto retval = MONEY::_0xA46FD001D1BE896C();
		return retval;
	}

	static bool LUA_NATIVE_MONEY__0x07AD9E43FD478527(Any p0, Any p1)
	{
		auto retval = (bool)MONEY::_0x07AD9E43FD478527(p0, p1);
		return retval;
	}

	static int LUA_NATIVE_MONEY__NETWORK_GET_CASH_BALANCE()
	{
		auto retval = MONEY::_NETWORK_GET_CASH_BALANCE();
		return retval;
	}

	void RegisterNatives_MONEY(sol::state& L)
	{
		auto MONEY = L["MONEY"].get_or_create<sol::table>();
		MONEY.set_function("_MONEY_GET_CASH_BALANCE", LUA_NATIVE_MONEY__MONEY_GET_CASH_BALANCE);
		MONEY.set_function("_MONEY_DECREMENT_CASH_BALANCE", LUA_NATIVE_MONEY__MONEY_DECREMENT_CASH_BALANCE);
		MONEY.set_function("_MONEY_INCREMENT_CASH_BALANCE", LUA_NATIVE_MONEY__MONEY_INCREMENT_CASH_BALANCE);
		MONEY.set_function("_NETWORK_GET_STRING_CASH_BALANCE", LUA_NATIVE_MONEY__NETWORK_GET_STRING_CASH_BALANCE);
		MONEY.set_function("_NETWORK_IS_MONEY_BALANCE_NOT_LESS_THAN", LUA_NATIVE_MONEY__NETWORK_IS_MONEY_BALANCE_NOT_LESS_THAN);
		MONEY.set_function("_0xA46FD001D1BE896C", LUA_NATIVE_MONEY__0xA46FD001D1BE896C);
		MONEY.set_function("_0x07AD9E43FD478527", LUA_NATIVE_MONEY__0x07AD9E43FD478527);
		MONEY.set_function("_NETWORK_GET_CASH_BALANCE", LUA_NATIVE_MONEY__NETWORK_GET_CASH_BALANCE);
	}
}
