#include "game/commands/PlayerCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Vehicle.hpp"


namespace YimMenu::Features
{
	class Circus : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			float rot = player.GetPed().GetRotation(0).z;
			auto coords = player.GetPed().GetPosition();
			Vehicle::Create("wagonCircus01x"_J, coords, rot);
		}
	};

	static Circus _Circus{"cageplayercircus", "Cage Player(Circus)", "Cages the player using a circus wagon"};
}
