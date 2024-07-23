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
			auto vehicle = Self::GetVehicle();
			if (vehicle)
			{
				Hash vehicleModelHash = ENTITY::GET_ENTITY_MODEL(vehicle);

				if (VEHICLE::IS_THIS_MODEL_A_TRAIN(vehicleModelHash))
				{
					VEHICLE::SET_TRAIN_SPEED(vehicle, 1000.0);
					VEHICLE::SET_TRAIN_CRUISE_SPEED(vehicle, 1000.0);
					VEHICLE::_SET_TRAIN_MAX_SPEED(vehicle, 1000.0);
				}
			}
		}

		virtual void OnDisable() override
		{
			auto vehicle       = Self::GetVehicle();
			if (vehicle)
			{
				Hash vehicleModelHash = ENTITY::GET_ENTITY_MODEL(vehicle);

				if (VEHICLE::IS_THIS_MODEL_A_TRAIN(vehicleModelHash))
				{
					VEHICLE::SET_TRAIN_SPEED(vehicle, 0.0);
					VEHICLE::SET_TRAIN_CRUISE_SPEED(vehicle, 0.0);
					VEHICLE::_SET_TRAIN_MAX_SPEED(vehicle, 0.0);
				}
			}
		}
	};

	static FastTrain _FastTrain{"fasttrain", "Fast Train", "Makes the train much faster than normal. Instantly stops it when disabled."};
}