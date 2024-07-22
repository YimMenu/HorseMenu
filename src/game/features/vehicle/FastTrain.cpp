#include "core/commands/LoopedCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	class FastTrain : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			Vehicle vehicle       = PED::GET_VEHICLE_PED_IS_USING(Self::GetPed().GetHandle());
			Hash vehicleModelHash = ENTITY::GET_ENTITY_MODEL(vehicle);

			// Check if the vehicle is a train
			if (VEHICLE::IS_THIS_MODEL_A_TRAIN(vehicleModelHash))
			{
				// If it's a train, set its speed high
				VEHICLE::SET_TRAIN_SPEED(vehicle, 1000.0);
				VEHICLE::SET_TRAIN_CRUISE_SPEED(vehicle, 1000.0);
				VEHICLE::_SET_TRAIN_MAX_SPEED(vehicle, 1000.0);
				GRAPHICS::_SET_LIGHTS_INTENSITY_FOR_ENTITY(vehicle, 1000.0);
			}
		}

		virtual void OnDisable() override
		{
			Vehicle vehicle       = PED::GET_VEHICLE_PED_IS_USING(Self::GetPed().GetHandle());
			Hash vehicleModelHash = ENTITY::GET_ENTITY_MODEL(vehicle);

			if (VEHICLE::IS_THIS_MODEL_A_TRAIN(vehicleModelHash))
			{
				VEHICLE::SET_TRAIN_SPEED(vehicle, 0.0); // Instantly stops the train
				VEHICLE::SET_TRAIN_CRUISE_SPEED(vehicle, 0.0);
				VEHICLE::_SET_TRAIN_MAX_SPEED(vehicle, 0.0);
			}
		}
	};

	static FastTrain _FastTrain{"fasttrain", "Fast Train", "Makes the train much faster than normal. Instantly stops it when disabled."};
}