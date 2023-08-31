#pragma once
#include "../../common.hpp"

namespace YimMenu
{
	struct CommandLink
	{
	public:
		uint32_t HashID;
		bool Looped;

		CommandLink(uint32_t hash, bool looped) :
		    HashID(hash),
		    Looped(looped)
		{
		}

		bool operator<(const CommandLink& other) const
		{
			if (HashID < other.HashID)
				return true;
			if (HashID > other.HashID)
				return false;
			return Looped < other.Looped;
		}

		bool operator==(const CommandLink& other) const
		{
			return HashID == other.HashID && Looped == other.Looped;
		}
	};

	class HotkeySystem
	{
	public:
		std::map<CommandLink, std::vector<int>> m_CommandHotkeys;
		void RegisterCommands();
		bool ListenAndApply(int& hotkey, std::vector<int> blacklist = {0});
		std::string GetHotkeyLabel(int hotkey_modifiers);
		void CreateHotkey(std::vector<int>& hotkey);

		void FeatureCommandsHotkeyLoop();
	};

	inline HotkeySystem g_HotkeySystem;
}