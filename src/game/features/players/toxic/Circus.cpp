#include "game/commands/PlayerCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "util/VehicleSpawner.hpp"


namespace YimMenu::Features
{
	class Circus : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			float rot      = ENTITY::GET_ENTITY_ROTATION(player.GetPed().GetHandle(), 0).z;
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(player.GetPed().GetHandle(), true, true);
			SpawnVehicle("wagonCircus01x", coords, rot);
		}
	};

	static Circus _Circus{"circus", "Circus", "Cages the player using a circus wagon"};
}