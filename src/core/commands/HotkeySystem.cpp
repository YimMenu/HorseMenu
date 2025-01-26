#include "HotkeySystem.hpp"
#include "game/backend/FiberPool.hpp" // TODO: yet another game import in core
                                      // we should migrate the FiberPool to core eventually
#include "game/backend/ScriptMgr.hpp"
#include "Commands.hpp"
#include "LoopedCommand.hpp"

// TODO: serialization isn't stable

namespace YimMenu
{
	HotkeySystem::HotkeySystem() : 
		IStateSerializer("hotkeys")
	{
	}

	void HotkeySystem::RegisterCommands()
	{
		auto& cmds = Commands::GetCommands();
		
		for (auto& [hash, cmd] : cmds)
		{
			CommandLink link;
			m_CommandHotkeys.insert(std::make_pair(hash, link));
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

		// VK_OEM_CLEAR Is about the limit in terms of virtual key codes
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

	// Will return the keycode if there are no labels
	std::string HotkeySystem::GetHotkeyLabel(int HotkeyModifier)
	{
		char KeyName[32];
		GetKeyNameTextA(MapVirtualKey(HotkeyModifier, MAPVK_VK_TO_VSC) << 16, KeyName, 32);

		if (std::string(KeyName).empty())
			strcpy(KeyName, std::to_string(HotkeyModifier).data());

		return KeyName;
	}

	// Meant to be called in a loop
	void HotkeySystem::CreateHotkey(std::vector<int>& chain)
	{
		static auto is_key_unique = [this](int Key, std::vector<int> List) -> bool {
			for (auto& Key_ : List)
				if (GetHotkeyLabel(Key_) == GetHotkeyLabel(Key))
					return false;

			return true;
		};

		int pressed_key = 0;
		ListenAndApply(pressed_key, chain);

		if (pressed_key > 1)
		{
			if (is_key_unique(pressed_key, chain))
			{
				chain.push_back(pressed_key);
			}
		}

		MarkStateDirty();
	}

	void HotkeySystem::Update()
	{
		for (auto& [hash, link] : m_CommandHotkeys)
		{
			if (link.m_Chain.empty() || link.m_BeingModified)
				continue;
	
			bool all_keys_pressed = true;
	
			for (auto modifier : link.m_Chain)
			{
				if (!(GetAsyncKeyState(modifier) & 0x8000))
				{
					all_keys_pressed = false;
				}
			}
	
			if (all_keys_pressed && std::chrono::system_clock::now() - m_LastHotkeyTriggerTime > 100ms)
			{
				auto command = Commands::GetCommand(hash);
				if (command)
				{
					// TODO: this is the only way I can prevent chat from blocking the main loop while keeping everything else fast
					if (hash != "chathelper"_J)
						command->Call();
					else
					{
						FiberPool::Push([command] {
							command->Call();
						});
					}
				}
				m_LastHotkeyTriggerTime = std::chrono::system_clock::now();
			}
		}
	}

	void HotkeySystem::SaveStateImpl(nlohmann::json& state)
	{
		for (auto& hotkey : m_CommandHotkeys)
		{
			if (!hotkey.second.m_Chain.empty())
			{
				state[std::to_string(hotkey.first).data()] = hotkey.second.m_Chain;
			}
		}
	}

	void HotkeySystem::LoadStateImpl(nlohmann::json& state)
	{
		for (auto& [key, value] : state.items())
		{
			if (m_CommandHotkeys.contains(std::atoi(key.data())))
				m_CommandHotkeys[std::atoi(key.data())].m_Chain = value.get<std::vector<int>>(); 
		}
	}
}
