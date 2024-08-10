#include "core/commands/LoopedCommand.hpp"
#include "game/backend/ScriptPatches.hpp"

namespace YimMenu::Features
{
	class RevealAllPlayers : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		std::shared_ptr<ScriptPatches::Patch> m_Patch1{};
		std::shared_ptr<ScriptPatches::Patch> m_Patch2{};
		std::shared_ptr<ScriptPatches::Patch> m_Patch3{};

		virtual void OnEnable() override
		{
			if (!m_Patch1)
			{
				m_Patch1 = ScriptPatches::AddPatch("net_main_offline"_J, true, "8B ? ? 5D ? ? ? 80 ? 66 01", 0, {0x41, 0x13, 0x13}); // make blip processor think that we're a security client
			}
			m_Patch1->Enable();

			if (!m_Patch2)
			{
				m_Patch2 = ScriptPatches::AddPatch("net_main_offline"_J, true, "8B ? ? 66 00 66 01 66 02 39 ? ? ? 66 00", 0, {0x41, 0x13, 0x13}); // some security client check
			}
			m_Patch2->Enable();

			if (!m_Patch3)
			{
				m_Patch3 = ScriptPatches::AddPatch("net_main_offline"_J, true, "22 04 0E 00 00 66 00 03", 5, {0x37, 0x8D, 0x7F, 0x92, 0xC6, 0x50, 0x04, 0x01}); // set everyone as your ally which makes their blips show up everywhere
			}
			m_Patch3->Enable();
		}

		virtual void OnTick() override
		{
		}

		virtual void OnDisable() override
		{
			if (m_Patch1)
			{
				m_Patch1->Disable();
			}

			if (m_Patch2)
			{
				m_Patch2->Disable();
			}

			if (m_Patch3)
			{
				m_Patch3->Disable();
			}
		}
	};

	static RevealAllPlayers _RevealAllPlayers{"revealall", "Reveal All Players", "Show all player blips from across the map"};
}