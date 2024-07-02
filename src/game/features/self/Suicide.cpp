#include "core/commands/Command.hpp"
#include "core/commands/Commands.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/Players.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"

#include <network/rlGamerHandle.hpp>
#include <network/rlGamerInfo.hpp>
#include <script/scriptId.hpp>

namespace YimMenu::Features
{
	class Suicide : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			ENTITY::SET_ENTITY_INVINCIBLE(Self::PlayerPed, FALSE);
			ENTITY::SET_ENTITY_HEALTH(Self::PlayerPed, 0, 0);
		}
	};

	static Suicide _Suicide{"suicide", "Suicide", "Kills you"};
}