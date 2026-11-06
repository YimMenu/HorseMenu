#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Ped.hpp"

namespace Terminus::Features
{
	class SuperBrake : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (!Terminus::Self::GetVehicle().IsValid()
			    || ENTITY::GET_ENTITY_SPEED_VECTOR(Terminus::Self::GetVehicle().GetHandle(), true).y < 1.f
			    || !VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(Terminus::Self::GetVehicle().GetHandle()))
			{
				return;
			}

			if (PAD::IS_CONTROL_PRESSED(0, (int)NativeInputs::INPUT_VEH_BRAKE) || PAD::IS_CONTROL_PRESSED(0, (int)NativeInputs::INPUT_VEH_HANDBRAKE))
			{
				VEHICLE::SET_VEHICLE_FORWARD_SPEED(Terminus::Self::GetVehicle().GetHandle(), 0);
			}
		}
	};

	static SuperBrake _SuperBrake{"superbrake", "Super Brake", "When the brake key is pressed, you will stop instantly"};
}