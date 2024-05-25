#pragma once
#include <string>

namespace YimMenu
{
	struct Spoofing
	{
		std::string spoofed_name;
	};
	inline YimMenu::Spoofing g_SpoofingStorage;
}