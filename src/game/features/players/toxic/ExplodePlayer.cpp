#include "game/commands/PlayerCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"


namespace YimMenu::Features
{
	class ExplodePlayer : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			auto playerCoords = player.GetPed().GetPosition();
			FIRE::ADD_EXPLOSION(playerCoords.x, playerCoords.y, playerCoords.z, (int)ExplosionTypes::UNK, 10.0f, true, false, 5.0f);
		}
	};

	static ExplodePlayer _ExplodePlayer{"explode", "Explode", "Spawns an explosion on the player"};
}