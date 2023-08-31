#include "HotkeySystem.hpp"

#include "game/rdr/Natives.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "Commands.hpp"
#include "LoopedCommand.hpp"

// TODO: hotkeys


namespace YimMenu
{

	void HotkeySystem::RegisterCommands()
	{
		auto commands        = Commands::GetCommands();
		auto looped_commands = Commands::GetLoopedCommands();
		
		for (auto [hash, command] : commands)
		{
			CommandLink command(hash, false);
			m_CommandHotkeys.insert(std::make_pair(command, std::vector<int>{}));
		}
		
		for (auto looped_command : looped_commands)
		{
			CommandLink command(looped_command->GetHash(), false);
			m_CommandHotkeys.insert(std::make_pair(command, std::vector<int>{}));
		}
		
		LOG(INFO) << "Registered " << m_CommandHotkeys.size() << " commands";
	}

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
		for (auto& [link, hotkey] : m_CommandHotkeys)
		{
			if (hotkey.empty())
				continue;
	
			bool allkeyspressed = true;
	
			for (auto hotkey_modifier : hotkey)
			{
				if (!(GetAsyncKeyState(hotkey_modifier) & 0x8000))
				{
					allkeyspressed = false;
				}
			}
	
			if (allkeyspressed)
			{
				if (link.Looped)
				{
					auto looped_command = Commands::GetCommand<LoopedCommand>(link.HashID);

					if (looped_command)
						looped_command->SetState(!looped_command->GetState());

					LOG(INFO) << "Hotkey detected for looped command " << looped_command->GetName();
				}
				else
				{
					auto command = Commands::GetCommand(link.HashID);
					if (command)
					{
						command->Call();
						LOG(INFO) << "Hotkey detected for command " << command->GetName();
					}
				}
	
				ScriptMgr::Yield(100ms);
			}
		}
	}
}
