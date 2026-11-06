#include "core/commands/LoopedCommand.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Pools.hpp"

namespace Terminus::Features
{
	class FastTrain : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			for (auto veh : Pools::GetVehicles())
			{
				Hash model = ENTITY::GET_ENTITY_MODEL(veh.GetHandle());
				if (VEHICLE::IS_THIS_MODEL_A_TRAIN(model))
				{
					veh.ForceControl();
					VEHICLE::SET_TRAIN_SPEED(veh.GetHandle(), 50.0f);
					VEHICLE::SET_TRAIN_CRUISE_SPEED(veh.GetHandle(), 50.0f);
					VEHICLE::_SET_TRAIN_MAX_SPEED(veh.GetHandle(), 50.0f);
					VEHICLE::MODIFY_VEHICLE_TOP_SPEED(veh.GetHandle(), 50.0f);
				}
			}
		}
	};

	static FastTrain _FastTrain{"fasttrain", "Fast Train", "Make trains go fast"};
}