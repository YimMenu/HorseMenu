#include "core/commands/LoopedCommand.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"

namespace Terminus::Features
{
	class LightningStrike : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			auto playerCoords = player.GetPed().GetPosition();
			FIRE::ADD_EXPLOSION(playerCoords.x, playerCoords.y, playerCoords.z, (int)ExplosionTypes::EXP_TAG_LIGHTNING_STRIKE, 5.0f, true, false, 5.0f);
		}
	};

	static LightningStrike _LightningStrike{"lightning", "Lightning Strike", "Strikes the player with lightning"};

	BoolCommand _LightningLoopActive{"lightningactive", "Lightning Loop Enabled", "Turn off to stop lightning", false};

	class LightningStrikeLoop : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			if (!player.IsValid())
				return;

			_LightningLoopActive.SetState(true);

			for (int i = 0; i < 2500; i++)
			{
				if (!_LightningLoopActive.GetState())
				{
					_LightningLoopActive.SetState(false);
					return;
				}

				while (PED::IS_PED_DEAD_OR_DYING(player.GetPed().GetHandle(), true)
				    || PLAYER::IS_PLAYER_DEAD(player.GetPed().GetHandle()))
				{
					if (!_LightningLoopActive.GetState() || !player.IsValid())
					{
						_LightningLoopActive.SetState(false);
						return;
					}

					ScriptMgr::Yield(500ms);

					if (!player.IsValid())
					{
						_LightningLoopActive.SetState(false);
						return;
					}
				}

				if (!_LightningLoopActive.GetState())
				{
					_LightningLoopActive.SetState(false);
					return;
				}

				if (!PLAYER::IS_PLAYER_DEAD(player.GetPed().GetHandle()) || !PED::IS_PED_DEAD_OR_DYING(player.GetPed().GetHandle(), true))
				{
					auto playerCoords = player.GetPed().GetPosition();
					
					FIRE::ADD_EXPLOSION(playerCoords.x, playerCoords.y, playerCoords.z, (int)ExplosionTypes::EXP_TAG_LIGHTNING_STRIKE, 5.0f, true, false, 5.0f);
					ScriptMgr::Yield(50ms);
				}
			}
			_LightningLoopActive.SetState(false);
		}
	};

	static LightningStrikeLoop _LightningStrikeLoop{"lightningloop", "Lightning Loop", "Loops 2500 lightning strikes on the selected player ONLY while they are alive"};
}