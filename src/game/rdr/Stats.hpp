#pragma once
#include "util/Joaat.hpp"


namespace Terminus::Stats
{
	struct StatId
	{
		alignas(8) joaat_t m_BaseID{};
		alignas(8) joaat_t m_PermutationID{};
	};
	static_assert(sizeof(StatId) == 16);
	static_assert(offsetof(StatId, m_PermutationID) == 8);

	StatId MakeId(const joaat_t base, const joaat_t perm);
	StatId MakeId(const std::string_view base, const std::string_view perm);

	bool IsValid(StatId id);

	int GetInt(StatId& id);
	float GetFloat(StatId& id);
	bool GetBool(StatId& id);

	bool SetInt(StatId& id, int value, bool save);
	bool SetFloat(StatId& id, float value, bool save);
	bool SetBool(StatId& id, bool value, bool save);
	bool SetString(StatId& id, const std::string& value, bool save);

	void DecrementInt(StatId& id, int value);
	void IncrementInt(StatId& id, int value);
	void IncrementFloat(StatId& id, float value);
}
