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
		auto Commands        = Commands::GetCommands();
		auto LoopedCommands = Commands::GetLoopedCommands();
		
		for (auto [Hash, Command] : Commands)
		{
			CommandLink link(false);
			m_CommandHotkeys.insert(std::make_pair(Command->GetHash(), link));
		}
		
		for (auto looped_command : LoopedCommands)
		{
			CommandLink link(true);
			m_CommandHotkeys.insert(std::make_pair(looped_command->GetHash(), link));
		}
		
		LOG(INFO) << "Registered " << m_CommandHotkeys.size() << " commands";
	}

	bool HotkeySystem::ListenAndApply(int& Hotkey, std::vector<int> Blacklist)
	{
		static auto IsKeyBlacklisted = [Blacklist](int Key) -> bool {
			for (auto Key_ : Blacklist)
				if (Key_ == Key)
					return true;

			return false;
		};

		//VK_OEM_CLEAR Is about the limit in terms of virtual key codes
		for (int i = 0; i < VK_OEM_CLEAR; i++)
		{
			if ((GetKeyState(i) & 0x8000) && i != 1 && !IsKeyBlacklisted(i))
			{
				Hotkey = i;

				return true;
			}
		}

		return false;
	}
	//Will return the keycode if there are no labels
	std::string HotkeySystem::GetHotkeyLabel(int HotkeyModifier)
	{
		char KeyName[32];
		GetKeyNameTextA(MapVirtualKey(HotkeyModifier, MAPVK_VK_TO_VSC) << 16, KeyName, 32);

		if (std::string(KeyName).empty())
			strcpy(KeyName, std::to_string(HotkeyModifier).data());

		return KeyName;
	}

	//Meant to be called in a loop
	void HotkeySystem::CreateHotkey(std::vector<int>& Hotkey)
	{
		static auto IsKeyUnique = [this](int Key, std::vector<int> List) -> bool {
			for (auto& Key_ : List)
				if (GetHotkeyLabel(Key_) == GetHotkeyLabel(Key))
					return false;

			return true;
		};

		int PressedKey = 0;
		ListenAndApply(PressedKey, Hotkey);


		if (PressedKey > 1)
		{
			if (IsKeyUnique(PressedKey, Hotkey))
			{
				Hotkey.push_back(PressedKey);
			}
		}
	}

	void HotkeySystem::FeatureCommandsHotkeyLoop()
	{
		for (auto& [Hash, Link] : m_CommandHotkeys)
		{
			if (Link.Hotkey.empty() || Link.Listening)
				continue;
	
			bool AllKeysPressed = true;
	
			for (auto HotkeyModifier : Link.Hotkey)
			{
				if (!(GetAsyncKeyState(HotkeyModifier) & 0x8000))
				{
					AllKeysPressed = false;
				}
			}
	
			if (AllKeysPressed && GetForegroundWindow() == Pointers.Hwnd)
			{
				if (Link.Looped)
				{
					auto LoopedCommand_ = Commands::GetCommand<LoopedCommand>(Hash);

					if (LoopedCommand_)
						LoopedCommand_->SetState(!LoopedCommand_->GetState());

					LOG(INFO) << "Hotkey detected for looped command " << LoopedCommand_->GetName();
				}
				else
				{
					auto Command = Commands::GetCommand(Hash);
					if (Command)
					{
						Command->Call();
						LOG(INFO) << "Hotkey detected for command " << Command->GetName();
					}
				}
	
				ScriptMgr::Yield(100ms);
			}
		}
	}
}
