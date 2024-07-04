#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"


namespace YimMenu::Features
{
	class NPCIgnore : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			PLAYER::SET_EVERYONE_IGNORE_PLAYER(Self::GetPlayer().GetId(), true);
		}

		virtual void OnDisable() override
		{
			PLAYER::SET_EVERYONE_IGNORE_PLAYER(Self::GetPlayer().GetId(), false);
		}
	};

	static NPCIgnore _NPCIgnore{"npcignore", "NPC Ignore", "Makes all peds ignore you"};
}