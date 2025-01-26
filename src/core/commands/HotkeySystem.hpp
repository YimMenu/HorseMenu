#pragma once
#include "core/settings/IStateSerializer.hpp"

namespace YimMenu
{
	struct CommandLink
	{
	public:
		std::vector<int> m_Chain{};
		bool m_BeingModified = false;

		CommandLink(){};
	};

	class HotkeySystem : 
		private IStateSerializer
	{
		std::chrono::system_clock::time_point m_LastHotkeyTriggerTime;

	public:
		HotkeySystem();

		std::map<uint32_t, CommandLink> m_CommandHotkeys;
		void RegisterCommands();
		bool ListenAndApply(int& Hotkey, std::vector<int> blacklist = {0});
		std::string GetHotkeyLabel(int hotkey_modifiers);
		void CreateHotkey(std::vector<int>& Hotkey);

		void Update();

		virtual void SaveStateImpl(nlohmann::json& state) override;
		virtual void LoadStateImpl(nlohmann::json& state) override;
	};

	inline HotkeySystem g_HotkeySystem;
}