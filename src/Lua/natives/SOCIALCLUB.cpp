#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static int LUA_NATIVE_SOCIALCLUB_SC_INBOX_GET_TOTAL_NUM_MESSAGES()
	{
		auto retval = SOCIALCLUB::SC_INBOX_GET_TOTAL_NUM_MESSAGES();
		return retval;
	}

	static Hash LUA_NATIVE_SOCIALCLUB_SC_INBOX_GET_MESSAGE_TYPE_AT_INDEX(int msgIndex)
	{
		auto retval = SOCIALCLUB::SC_INBOX_GET_MESSAGE_TYPE_AT_INDEX(msgIndex);
		return retval;
	}

	static bool LUA_NATIVE_SOCIALCLUB_SC_INBOX_GET_MESSAGE_IS_READ_AT_INDEX(int msgIndex)
	{
		auto retval = (bool)SOCIALCLUB::SC_INBOX_GET_MESSAGE_IS_READ_AT_INDEX(msgIndex);
		return retval;
	}

	static bool LUA_NATIVE_SOCIALCLUB_SC_INBOX_SET_MESSAGE_AS_READ_AT_INDEX(int msgIndex)
	{
		auto retval = (bool)SOCIALCLUB::SC_INBOX_SET_MESSAGE_AS_READ_AT_INDEX(msgIndex);
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_SOCIALCLUB_SC_INBOX_MESSAGE_GET_DATA_INT(int msgIndex, sol::stack_object name, int value)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_INBOX_MESSAGE_GET_DATA_INT(msgIndex, name.is<const char*>() ? name.as<const char*>() : nullptr, &value);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static std::tuple<bool, char> LUA_NATIVE_SOCIALCLUB_SC_INBOX_MESSAGE_GET_DATA_STRING(int msgIndex, sol::stack_object name, char value)
	{
		std::tuple<bool, char> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_INBOX_MESSAGE_GET_DATA_STRING(msgIndex, name.is<const char*>() ? name.as<const char*>() : nullptr, &value);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static const char* LUA_NATIVE_SOCIALCLUB_SC_INBOX_MESSAGE_GET_RAW_TYPE_AT_INDEX(int msgIndex)
	{
		auto retval = SOCIALCLUB::SC_INBOX_MESSAGE_GET_RAW_TYPE_AT_INDEX(msgIndex);
		return retval;
	}

	static bool LUA_NATIVE_SOCIALCLUB_SC_PRESENCE_ATTR_SET_FLOAT(Hash valueId, float value)
	{
		auto retval = (bool)SOCIALCLUB::SC_PRESENCE_ATTR_SET_FLOAT(valueId, value);
		return retval;
	}

	static bool LUA_NATIVE_SOCIALCLUB_SC_PRESENCE_ATTR_SET_INT_EX(sol::stack_object attrName, int value, bool p2)
	{
		auto retval = (bool)SOCIALCLUB::SC_PRESENCE_ATTR_SET_INT_EX(attrName.is<const char*>() ? attrName.as<const char*>() : nullptr, value, p2);
		return retval;
	}

	static bool LUA_NATIVE_SOCIALCLUB_SC_PRESENCE_ATTR_SET_FLOAT_EX(sol::stack_object attrName, float value, bool p2)
	{
		auto retval = (bool)SOCIALCLUB::SC_PRESENCE_ATTR_SET_FLOAT_EX(attrName.is<const char*>() ? attrName.as<const char*>() : nullptr, value, p2);
		return retval;
	}

	static bool LUA_NATIVE_SOCIALCLUB_SC_PRESENCE_ATTR_SET_STRING_EX(sol::stack_object attrName, sol::stack_object value, bool p2)
	{
		auto retval = (bool)SOCIALCLUB::SC_PRESENCE_ATTR_SET_STRING_EX(attrName.is<const char*>() ? attrName.as<const char*>() : nullptr, value.is<const char*>() ? value.as<const char*>() : nullptr, p2);
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_SOCIALCLUB_SC_PROFANITY_CHECK_STRING(sol::stack_object textString, int outToken)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_PROFANITY_CHECK_STRING(textString.is<const char*>() ? textString.as<const char*>() : nullptr, &outToken);
		std::get<1>(return_values) = outToken;

		return return_values;
	}

	static bool LUA_NATIVE_SOCIALCLUB_SC_PROFANITY_GET_CHECK_IS_VALID(int token)
	{
		auto retval = (bool)SOCIALCLUB::SC_PROFANITY_GET_CHECK_IS_VALID(token);
		return retval;
	}

	static bool LUA_NATIVE_SOCIALCLUB_SC_PROFANITY_GET_CHECK_IS_PENDING(int token)
	{
		auto retval = (bool)SOCIALCLUB::SC_PROFANITY_GET_CHECK_IS_PENDING(token);
		return retval;
	}

	static bool LUA_NATIVE_SOCIALCLUB_SC_PROFANITY_GET_STRING_PASSED(int token)
	{
		auto retval = (bool)SOCIALCLUB::SC_PROFANITY_GET_STRING_PASSED(token);
		return retval;
	}

	static int LUA_NATIVE_SOCIALCLUB_SC_PROFANITY_GET_STRING_STATUS(int token)
	{
		auto retval = SOCIALCLUB::SC_PROFANITY_GET_STRING_STATUS(token);
		return retval;
	}

	static bool LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_IS_ACTIVE()
	{
		auto retval = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_IS_ACTIVE();
		return retval;
	}

	static int LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EVENT_ID()
	{
		auto retval = SOCIALCLUB::SC_COMMUNITY_EVENT_GET_EVENT_ID();
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT(sol::stack_object name, int value)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT(name.is<const char*>() ? name.as<const char*>() : nullptr, &value);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static std::tuple<bool, float> LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT(sol::stack_object name, float value)
	{
		std::tuple<bool, float> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT(name.is<const char*>() ? name.as<const char*>() : nullptr, &value);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static std::tuple<bool, char> LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING(sol::stack_object name, char value)
	{
		std::tuple<bool, char> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING(name.is<const char*>() ? name.as<const char*>() : nullptr, &value);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static std::tuple<bool, char> LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_DISPLAY_NAME(char value)
	{
		std::tuple<bool, char> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_GET_DISPLAY_NAME(&value);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static bool LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_IS_ACTIVE_FOR_TYPE(sol::stack_object eventType)
	{
		auto retval = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_IS_ACTIVE_FOR_TYPE(eventType.is<const char*>() ? eventType.as<const char*>() : nullptr);
		return retval;
	}

	static int LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EVENT_ID_FOR_TYPE(sol::stack_object eventType)
	{
		auto retval = SOCIALCLUB::SC_COMMUNITY_EVENT_GET_EVENT_ID_FOR_TYPE(eventType.is<const char*>() ? eventType.as<const char*>() : nullptr);
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT_FOR_TYPE(sol::stack_object name, int value, sol::stack_object eventType)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT_FOR_TYPE(name.is<const char*>() ? name.as<const char*>() : nullptr, &value, eventType.is<const char*>() ? eventType.as<const char*>() : nullptr);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static std::tuple<bool, float> LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT_FOR_TYPE(sol::stack_object name, float value, sol::stack_object eventType)
	{
		std::tuple<bool, float> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT_FOR_TYPE(name.is<const char*>() ? name.as<const char*>() : nullptr, &value, eventType.is<const char*>() ? eventType.as<const char*>() : nullptr);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static std::tuple<bool, char> LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING_FOR_TYPE(sol::stack_object name, char value, sol::stack_object eventType)
	{
		std::tuple<bool, char> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING_FOR_TYPE(name.is<const char*>() ? name.as<const char*>() : nullptr, &value, eventType.is<const char*>() ? eventType.as<const char*>() : nullptr);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static std::tuple<bool, char> LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_DISPLAY_NAME_FOR_TYPE(char value, sol::stack_object p1)
	{
		std::tuple<bool, char> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_GET_DISPLAY_NAME_FOR_TYPE(&value, p1.is<const char*>() ? p1.as<const char*>() : nullptr);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static bool LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_IS_ACTIVE_BY_ID(int eventId)
	{
		auto retval = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_IS_ACTIVE_BY_ID(eventId);
		return retval;
	}

	static std::tuple<bool, int> LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT_BY_ID(int eventId, sol::stack_object name, int value)
	{
		std::tuple<bool, int> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT_BY_ID(eventId, name.is<const char*>() ? name.as<const char*>() : nullptr, &value);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static std::tuple<bool, float> LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT_BY_ID(int eventId, sol::stack_object name, float value)
	{
		std::tuple<bool, float> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT_BY_ID(eventId, name.is<const char*>() ? name.as<const char*>() : nullptr, &value);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static std::tuple<bool, char> LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING_BY_ID(int eventId, sol::stack_object name, char value)
	{
		std::tuple<bool, char> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING_BY_ID(eventId, name.is<const char*>() ? name.as<const char*>() : nullptr, &value);
		std::get<1>(return_values) = value;

		return return_values;
	}

	static std::tuple<bool, char> LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_DISPLAY_NAME_BY_ID(int eventID, char value)
	{
		std::tuple<bool, char> return_values;
		std::get<0>(return_values) = (bool)SOCIALCLUB::SC_COMMUNITY_EVENT_GET_DISPLAY_NAME_BY_ID(eventID, &value);
		std::get<1>(return_values) = value;

		return return_values;
	}

	void RegisterNatives_SOCIALCLUB(sol::state& L)
	{
		auto SOCIALCLUB = L["SOCIALCLUB"].get_or_create<sol::table>();
		SOCIALCLUB.set_function("SC_INBOX_GET_TOTAL_NUM_MESSAGES", LUA_NATIVE_SOCIALCLUB_SC_INBOX_GET_TOTAL_NUM_MESSAGES);
		SOCIALCLUB.set_function("SC_INBOX_GET_MESSAGE_TYPE_AT_INDEX", LUA_NATIVE_SOCIALCLUB_SC_INBOX_GET_MESSAGE_TYPE_AT_INDEX);
		SOCIALCLUB.set_function("SC_INBOX_GET_MESSAGE_IS_READ_AT_INDEX", LUA_NATIVE_SOCIALCLUB_SC_INBOX_GET_MESSAGE_IS_READ_AT_INDEX);
		SOCIALCLUB.set_function("SC_INBOX_SET_MESSAGE_AS_READ_AT_INDEX", LUA_NATIVE_SOCIALCLUB_SC_INBOX_SET_MESSAGE_AS_READ_AT_INDEX);
		SOCIALCLUB.set_function("SC_INBOX_MESSAGE_GET_DATA_INT", LUA_NATIVE_SOCIALCLUB_SC_INBOX_MESSAGE_GET_DATA_INT);
		SOCIALCLUB.set_function("SC_INBOX_MESSAGE_GET_DATA_STRING", LUA_NATIVE_SOCIALCLUB_SC_INBOX_MESSAGE_GET_DATA_STRING);
		SOCIALCLUB.set_function("SC_INBOX_MESSAGE_GET_RAW_TYPE_AT_INDEX", LUA_NATIVE_SOCIALCLUB_SC_INBOX_MESSAGE_GET_RAW_TYPE_AT_INDEX);
		SOCIALCLUB.set_function("SC_PRESENCE_ATTR_SET_FLOAT", LUA_NATIVE_SOCIALCLUB_SC_PRESENCE_ATTR_SET_FLOAT);
		SOCIALCLUB.set_function("SC_PRESENCE_ATTR_SET_INT_EX", LUA_NATIVE_SOCIALCLUB_SC_PRESENCE_ATTR_SET_INT_EX);
		SOCIALCLUB.set_function("SC_PRESENCE_ATTR_SET_FLOAT_EX", LUA_NATIVE_SOCIALCLUB_SC_PRESENCE_ATTR_SET_FLOAT_EX);
		SOCIALCLUB.set_function("SC_PRESENCE_ATTR_SET_STRING_EX", LUA_NATIVE_SOCIALCLUB_SC_PRESENCE_ATTR_SET_STRING_EX);
		SOCIALCLUB.set_function("SC_PROFANITY_CHECK_STRING", LUA_NATIVE_SOCIALCLUB_SC_PROFANITY_CHECK_STRING);
		SOCIALCLUB.set_function("SC_PROFANITY_GET_CHECK_IS_VALID", LUA_NATIVE_SOCIALCLUB_SC_PROFANITY_GET_CHECK_IS_VALID);
		SOCIALCLUB.set_function("SC_PROFANITY_GET_CHECK_IS_PENDING", LUA_NATIVE_SOCIALCLUB_SC_PROFANITY_GET_CHECK_IS_PENDING);
		SOCIALCLUB.set_function("SC_PROFANITY_GET_STRING_PASSED", LUA_NATIVE_SOCIALCLUB_SC_PROFANITY_GET_STRING_PASSED);
		SOCIALCLUB.set_function("SC_PROFANITY_GET_STRING_STATUS", LUA_NATIVE_SOCIALCLUB_SC_PROFANITY_GET_STRING_STATUS);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_IS_ACTIVE", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_IS_ACTIVE);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_EVENT_ID", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EVENT_ID);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_DISPLAY_NAME", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_DISPLAY_NAME);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_IS_ACTIVE_FOR_TYPE", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_IS_ACTIVE_FOR_TYPE);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_EVENT_ID_FOR_TYPE", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EVENT_ID_FOR_TYPE);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT_FOR_TYPE", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT_FOR_TYPE);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT_FOR_TYPE", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT_FOR_TYPE);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING_FOR_TYPE", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING_FOR_TYPE);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_DISPLAY_NAME_FOR_TYPE", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_DISPLAY_NAME_FOR_TYPE);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_IS_ACTIVE_BY_ID", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_IS_ACTIVE_BY_ID);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT_BY_ID", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_INT_BY_ID);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT_BY_ID", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_FLOAT_BY_ID);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING_BY_ID", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_EXTRA_DATA_STRING_BY_ID);
		SOCIALCLUB.set_function("SC_COMMUNITY_EVENT_GET_DISPLAY_NAME_BY_ID", LUA_NATIVE_SOCIALCLUB_SC_COMMUNITY_EVENT_GET_DISPLAY_NAME_BY_ID);
	}
}
