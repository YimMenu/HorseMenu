#include "game/commands/PlayerCommand.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/ScriptMgr.hpp"

namespace Terminus::Features
{
	class ExplodePlayer : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			auto playerCoords = player.GetPed().GetPosition();
			FIRE::ADD_EXPLOSION(playerCoords.x, playerCoords.y, playerCoords.z, (int)ExplosionTypes::EXP_TAG_GRENADE, 10.0f, true, false, 5.0f);
		}
	};

	static ExplodePlayer _ExplodePlayer{"explode", "Explode", "Spawns an explosion on the player"};

	BoolCommand _ExplodePlayerActive{"explodeactive", "Explosions Enabled", "Turn off to stop explosions", false};

	class ExplodePlayerAlot : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			if (!player.IsValid())
				return;

			// Set active state
			_ExplodePlayerActive.SetState(true);

			// Loop 250 times, but only when player is alive
			for (int i = 0; i < 2500; i++)
			{
				// Check if we should stop
				if (!_ExplodePlayerActive.GetState())
				{
					// Reset active state for next use
					_ExplodePlayerActive.SetState(false);
					return;
				}

				// Wait until player is alive before next explosion
				while (PED::IS_PED_DEAD_OR_DYING(player.GetPed().GetHandle(), true)
				    || PLAYER::IS_PLAYER_DEAD(player.GetPed().GetHandle()))
				{
					// Check stop condition during wait
					if (!_ExplodePlayerActive.GetState() || !player.IsValid())
					{
						_ExplodePlayerActive.SetState(false);
						return;
					}

					// Small sleep to prevent freezing the game
					ScriptMgr::Yield(500ms); // or similar

					// Re-check if player is still valid (they might have left)
					if (!player.IsValid())
					{
						_ExplodePlayerActive.SetState(false);
						return;
					}
				}

				// Check stop condition before exploding
				if (!_ExplodePlayerActive.GetState())
				{
					_ExplodePlayerActive.SetState(false);
					return;
				}

				if (!PLAYER::IS_PLAYER_DEAD(player.GetPed().GetHandle()) || !PED::IS_PED_DEAD_OR_DYING(player.GetPed().GetHandle(), true))
				{
					// Player is alive, trigger explosion
					auto playerCoords = player.GetPed().GetPosition();
					FIRE::ADD_EXPLOSION(playerCoords.x, playerCoords.y, playerCoords.z, (int)ExplosionTypes::EXP_TAG_GRENADE, 10.0f, true, false, 5.0f);
					ScriptMgr::Yield(50ms); // Wait a bit between explosions to give player time to react
				}
			}

			// Reset active state when finished
			_ExplodePlayerActive.SetState(false);
		}
	};

	static ExplodePlayerAlot _ExplodePlayerAlot{"explodeloop", "Explode Loop", "Loops 2500 explosions on the selected player ONLY while they are alive"};
}