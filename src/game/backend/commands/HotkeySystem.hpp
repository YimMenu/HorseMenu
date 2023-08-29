#pragma once
#include "../../../common.hpp"

namespace YimMenu
{
	class HotkeySystem
	{
	public:
		bool listening;

		bool ListenAndApply(int& hotkey, std::vector<int> blacklist = {0});
		std::string GetHotkeyLabel(int hotkey_modifiers);
		void CreateHotkey(std::vector<int>& hotkey);

		void FeatureCommandsHotkeyLoop();
	};

	inline HotkeySystem g_HotkeySystem;
}