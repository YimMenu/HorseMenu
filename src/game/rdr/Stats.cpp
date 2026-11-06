#include "Stats.hpp"
#include "Natives.hpp"


namespace Terminus::Stats
{
	StatId MakeId(const joaat_t base, const joaat_t perm)
	{
		return {base, perm};
	}

	StatId MakeId(const std::string_view base, const std::string_view perm)
	{
		return {Joaat(base), Joaat(perm)};
	}

	bool IsValid(StatId id)
	{
		return STATS::STAT_ID_IS_VALID(&id);
	}

	int GetInt(StatId& id)
	{
		if (!IsValid(id))
			return 0;

		int out = 0;
		STATS::STAT_ID_GET_INT(&id, &out);
		return out;
	}

	float GetFloat(StatId& id)
	{
		if (!IsValid(id))
			return 0.f;

		float out = 0;
		STATS::STAT_ID_GET_FLOAT(&id, &out);
		return out;
	}

	bool GetBool(StatId& id)
	{
		if (!IsValid(id))
			return false;

		int out = 0;
		STATS::STAT_ID_GET_BOOL(&id, &out);
		return static_cast<bool>(out);
	}

	bool SetInt(StatId& id, int value, bool save)
	{
		if (!IsValid(id))
			return false;

		return STATS::STAT_ID_SET_INT(&id, value, save);
	}

	bool SetFloat(StatId& id, float value, bool save)
	{
		if (!IsValid(id))
			return false;

		return STATS::STAT_ID_SET_FLOAT(&id, value, save);
	}

	bool SetBool(StatId& id, bool value, bool save)
	{
		if (!IsValid(id))
			return false;

		return STATS::STAT_ID_SET_BOOL(&id, value, save);
	}

	bool SetString(StatId& id, const std::string& value, bool save)
	{
		if (!IsValid(id))
			return false;

		return STATS::STAT_ID_SET_GXT_LABEL(&id, value.data(), save);
	}

	void DecrementInt(StatId& id, int value)
	{
		if (!IsValid(id))
			return;

		STATS::_STAT_ID_DECREMENT_INT(&id, value);
	}

	void IncrementInt(StatId& id, int value)
	{
		if (!IsValid(id))
			return;

		STATS::_STAT_ID_INCREMENT_INT(&id, value);
	}

	void IncrementFloat(StatId& id, float value)
	{
		if (!IsValid(id))
			return;

		STATS::_STAT_ID_INCREMENT_FLOAT(&id, value);
	}
}
