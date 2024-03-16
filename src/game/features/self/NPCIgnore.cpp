#include "core/commands/LoopedCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"


namespace YimMenu::Features
{
	class NPCIgnore : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnEnable() override
		{
			Notifications::Show("NPC Ignore", "You are now ignored!", NotificationType::Success);
		}


		virtual void OnTick() override
		{
			PLAYER::SET_EVERYONE_IGNORE_PLAYER(Self::Id, true);
		}

		virtual void OnDisable() override
		{
			PLAYER::SET_EVERYONE_IGNORE_PLAYER(Self::Id, false);
			Notifications::Show("NPC Ignore", "You are no longer ignored!", NotificationType::Success);
		}
	};

	static NPCIgnore _NPCIgnore{"npcignore", "NPC Ignore", "NPCs completely ignore this player!"};
}