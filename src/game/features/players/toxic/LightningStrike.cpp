#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"


namespace YimMenu::Features
{
	class LightningStrike : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			auto playerCoords = player.GetPed().GetPosition();
			FIRE::ADD_EXPLOSION(playerCoords.x, playerCoords.y, playerCoords.z, (int)ExplosionTypes::SPARKS_WITH_FIRE_AFTERWARDS, 5.0f, true, false, 5.0f);
		}
	};

	static LightningStrike _LightningStrike{"lightning", "Lightning", "Strikes the player with lightning"};
}
