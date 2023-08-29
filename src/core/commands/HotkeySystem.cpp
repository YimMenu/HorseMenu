#include "HotkeySystem.hpp"

#include "game/rdr/Natives.hpp"
#include "FeatureCommand.hpp"
#include "game/backend/ScriptMgr.hpp"

namespace YimMenu
{

	bool HotkeySystem::ListenAndApply(int& hotkey, std::vector<int> blacklist)
	{
		static auto is_key_blacklisted = [blacklist](int key) -> bool {
			for (auto key_ : blacklist)
				if (key_ == key)
					return true;

			return false;
		};

		//VK_OEM_CLEAR Is about the limit in terms of virtual key codes
		for (int i = 0; i < VK_OEM_CLEAR; i++)
		{
			if ((GetKeyState(i) & 0x8000) && i != 1 && !is_key_blacklisted(i))
			{
				hotkey = i;

				return true;
			}
		}

		return false;
	}
	//Will return the keycode if there are no labels
	std::string HotkeySystem::GetHotkeyLabel(int hotkey_modifier)
	{
		char key_name[32];
		GetKeyNameTextA(MapVirtualKey(hotkey_modifier, MAPVK_VK_TO_VSC) << 16, key_name, 32);

		if (std::string(key_name).empty())
			strcpy(key_name, std::to_string(hotkey_modifier).data());

		return key_name;
	}

	//Meant to be called in a loop
	void HotkeySystem::CreateHotkey(std::vector<int>& hotkey)
	{
		static auto is_key_unique = [this](int key, std::vector<int> list) -> bool {
			for (auto& key_ : list)
				if (GetHotkeyLabel(key_) == GetHotkeyLabel(key))
					return false;

			return true;
		};

		int pressed_key = 0;
		ListenAndApply(pressed_key, hotkey);


		if (pressed_key > 1)
		{
			if (is_key_unique(pressed_key, hotkey))
			{
				hotkey.push_back(pressed_key);
			}
		}
	}

	void HotkeySystem::FeatureCommandsHotkeyLoop()
	{
		for (auto& feature_command : RegisteredCommands | std::ranges::views::values)
		{
			if (feature_command.hotkey_modifiers.empty() || feature_command.hotkey_listener)
				continue;

			bool allkeyspressed = true;

			for (auto hotkey_modifier : feature_command.hotkey_modifiers)
			{
				if (!(GetAsyncKeyState(hotkey_modifier) & 0x8000))
				{
					allkeyspressed = false;
				}
			}

			if (allkeyspressed)
			{
				if (feature_command.IsLooped() && feature_command.GetGlobal())
				{
					*feature_command.GetGlobal() = !*feature_command.GetGlobal();
				}
				else
				{
					feature_command.Call();
				}

				ScriptMgr::Yield(100ms);
			}
		}
	}
}