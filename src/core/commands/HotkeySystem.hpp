#pragma once
#include "../../common.hpp"

namespace YimMenu
{
	struct CommandLink
	{
	public:
		bool Looped;
		std::vector<int> Hotkey{};

		CommandLink(bool looped) :
		    Looped(looped)
		{
		}

		bool Listening;
	};

	class HotkeySystem
	{
	public:
		std::map<uint32_t, CommandLink> m_CommandHotkeys;
		void RegisterCommands();
		bool ListenAndApply(int& Hotkey, std::vector<int> blacklist = {0});
		std::string GetHotkeyLabel(int hotkey_modifiers);
		void CreateHotkey(std::vector<int>& Hotkey);

		void FeatureCommandsHotkeyLoop();
	};

	inline HotkeySystem g_HotkeySystem;
}