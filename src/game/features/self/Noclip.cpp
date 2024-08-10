#include "core/commands/FloatCommand.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	static constexpr NativeInputs controls[] = {NativeInputs::INPUT_SPRINT, NativeInputs::INPUT_MOVE_UP_ONLY, NativeInputs::INPUT_MOVE_DOWN_ONLY, NativeInputs::INPUT_MOVE_LEFT_ONLY, NativeInputs::INPUT_MOVE_RIGHT_ONLY, NativeInputs::INPUT_DUCK, NativeInputs::INPUT_HORSE_STOP};
	static FloatCommand _NoclipSpeed{"noclipspeed", "Noclip Speed", "Features", 0.1f, 15.0f, 0.5f};

	class Noclip : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		Entity m_Entity{nullptr};
		float m_SpeedMultiplier;

		virtual void OnTick() override
		{
			for (const auto& control : controls)
				PAD::DISABLE_CONTROL_ACTION(0, static_cast<int>(control), true);

			Entity ent = Self::GetPed();

			if (auto mount = Self::GetMount())
				ent = mount;
			else if (auto veh = Self::GetVehicle())
				ent = veh;

			const auto location = ent.GetPosition();

			// cleanup when changing entities
			if (m_Entity != ent)
			{
				m_Entity.SetFrozen(false);
				m_Entity.SetCollision(true);

				m_Entity = ent;
			}

			rage::fvector3 vel{};

			// Left Shift
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)NativeInputs::INPUT_SPRINT))
				vel.z += _NoclipSpeed.GetState() / 2;
			// Left Control
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)NativeInputs::INPUT_DUCK) || PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)NativeInputs::INPUT_HORSE_STOP) || PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)NativeInputs::INPUT_VEH_DRAFT_BRAKE))
				vel.z -= _NoclipSpeed.GetState() / 2;
			// Forward
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)NativeInputs::INPUT_MOVE_UP_ONLY))
				vel.y += _NoclipSpeed.GetState();
			// Backward
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)NativeInputs::INPUT_MOVE_DOWN_ONLY))
				vel.y -= _NoclipSpeed.GetState();
			// Left
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)NativeInputs::INPUT_MOVE_LEFT_ONLY))
				vel.x -= _NoclipSpeed.GetState();
			// Right
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)NativeInputs::INPUT_MOVE_RIGHT_ONLY))
				vel.x += _NoclipSpeed.GetState();

			auto rot = CAM::GET_GAMEPLAY_CAM_ROT(2);
			ent.SetRotation({0.0f, rot.y, rot.z});
			ent.SetCollision(false);

			if (vel.x == 0.f && vel.y == 0.f && vel.z == 0.f)
			{
				// freeze entity to prevent drifting when standing still
				ent.SetFrozen(true);
				m_SpeedMultiplier = 0.f;
			}
			else
			{
				if (m_SpeedMultiplier < 20.f)
					m_SpeedMultiplier += 0.07f;

				ent.SetFrozen(false);

#if 0
				// TODO
				const auto offset = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ent.GetHandle(), vel.x, vel.y, 0.f);
				vel.x             = offset.x - location.x;
				vel.y             = offset.y - location.y;

				ent.SetVelocity({vel.x * m_SpeedMultiplier, vel.y * m_SpeedMultiplier, vel.z * m_SpeedMultiplier});
#else

				// TODO: we definitely need vector arithmetic
				const auto offset = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ent.GetHandle(), vel.x * m_SpeedMultiplier, vel.y * m_SpeedMultiplier, vel.z * m_SpeedMultiplier);
				ent.SetVelocity({});
				ent.SetPosition({offset.x, offset.y, offset.z});
#endif
			}
		}

		virtual void OnDisable() override
		{
			if (m_Entity)
			{
				m_Entity.SetFrozen(false);
				m_Entity.SetCollision(true);
			}
		}
	};

	static Noclip _NoClip{"noclip", "No Clip", "Allows you to fly through the map"};
}