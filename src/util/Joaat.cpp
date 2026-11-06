#include "Joaat.hpp"

namespace Terminus
{
	constexpr joaat_t Joaat(const std::string_view str)
	{
		if (str.empty())
			return 0;

		joaat_t hash = 0;
		for (auto c : str)
		{
			hash += ToLower(c);
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}
		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);
		return hash;
	}
}