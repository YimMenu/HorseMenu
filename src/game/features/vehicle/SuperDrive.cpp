#include "core/commands/LoopedCommand.hpp"
#include "core/commands/IntCommand.hpp"
#include "util/Math.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Ped.hpp"

namespace YimMenu::Features
{
	BoolCommand _SuperDriveDirectional{"superdrivedirectional", "Super Drive Directional", "Boosts your vehicle in the direction you're looking at when pressing the forward key"};
	IntCommand _SuperDriveForce{"superdriveforce", "Super Drive Force", "The force that will boost your vehicle", 1, 500, 1};

	class SuperDrive : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (!YimMenu::Self::GetVehicle().IsValid())
				return;

			if (PAD::IS_CONTROL_PRESSED(0, (int)NativeInputs::INPUT_VEH_ACCELERATE))
			{
				float force = _SuperDriveForce.GetState() / 100.0f;
				Vector3 direction;

				if (_SuperDriveDirectional.GetState())
				{
					Vector3 cam_rot = CAM::GET_GAMEPLAY_CAM_ROT(2);
					direction       = Math::RotationToDirection(cam_rot);
				}
				else
					direction = ENTITY::GET_ENTITY_FORWARD_VECTOR(YimMenu::Self::GetVehicle().GetHandle());

				Vector3 force_vector = direction * force;
				ENTITY::APPLY_FORCE_TO_ENTITY(YimMenu::Self::GetVehicle().GetHandle(), 1, force_vector.x, force_vector.y, force_vector.z, 0.0f, 0.0f, 0.0f, -1, false, true, true, false, true);
			}
		}
	};

	static SuperDrive _SuperDrive{"superdrive", "Super Drive", "Boosts your vehicle when pressing the forward key"};
}
