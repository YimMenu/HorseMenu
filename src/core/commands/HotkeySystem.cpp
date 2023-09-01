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
			CommandLink link(false);
			m_CommandHotkeys.insert(std::make_pair(command->GetHash(), link));
		}
		
		for (auto looped_command : looped_commands)
		{
			CommandLink link(true);
			m_CommandHotkeys.insert(std::make_pair(looped_command->GetHash(), link));
		}
		
		LOG(INFO) << "Registered " << m_CommandHotkeys.size() << " commands";
	}

	bool HotkeySystem::ListenAndApply(int& Hotkey, std::vector<int> blacklist)
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
				Hotkey = i;

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
	void HotkeySystem::CreateHotkey(std::vector<int>& Hotkey)
	{
		static auto is_key_unique = [this](int key, std::vector<int> list) -> bool {
			for (auto& key_ : list)
				if (GetHotkeyLabel(key_) == GetHotkeyLabel(key))
					return false;

			return true;
		};

		int pressed_key = 0;
		ListenAndApply(pressed_key, Hotkey);


		if (pressed_key > 1)
		{
			if (is_key_unique(pressed_key, Hotkey))
			{
				Hotkey.push_back(pressed_key);
			}
		}
	}

	void HotkeySystem::FeatureCommandsHotkeyLoop()
	{
		for (auto& [hash, link] : m_CommandHotkeys)
		{
			if (link.Hotkey.empty() || link.Listening)
				continue;
	
			bool allkeyspressed = true;
	
			for (auto hotkey_modifier : link.Hotkey)
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
					auto looped_command = Commands::GetCommand<LoopedCommand>(hash);

					if (looped_command)
						looped_command->SetState(!looped_command->GetState());

					LOG(INFO) << "Hotkey detected for looped command " << looped_command->GetName();
				}
				else
				{
					auto command = Commands::GetCommand(hash);
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
