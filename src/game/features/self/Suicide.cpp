#include "core/commands/Command.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"

#include "game/rdr/Nodes.hpp"
#include <network/sync/CProjectBaseSyncDataNode.hpp>

#include "game/rdr/Scripts.hpp"
#include "game/backend/Players.hpp"

#include "core/commands/Commands.hpp"
#include "game/commands/PlayerCommand.hpp"

namespace YimMenu::Features
{
	class Suicide : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			ENTITY::SET_ENTITY_INVINCIBLE(Self::PlayerPed, false);
			ENTITY::SET_ENTITY_HEALTH(Self::PlayerPed, 0, 0);
		}
	};

	static Suicide _Suicide{"suicide", "Suicide", "Kills you"};
}