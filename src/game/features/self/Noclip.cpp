#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/ScriptMgr.hpp"

namespace YimMenu::Features
{
	static constexpr eNativeInputs controls[] = {eNativeInputs::INPUT_SPRINT, eNativeInputs::INPUT_MOVE_UP_ONLY, eNativeInputs::INPUT_MOVE_DOWN_ONLY, eNativeInputs::INPUT_MOVE_LEFT_ONLY, eNativeInputs::INPUT_MOVE_RIGHT_ONLY, eNativeInputs::INPUT_DUCK, eNativeInputs::INPUT_HORSE_STOP};
	static constexpr float speed = 0.57f;

	class Noclip : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		Entity m_Entity = 0;
		float m_SpeedMultiplier;

		virtual void OnTick() override
		{
			for (const auto& control : controls)
				PAD::DISABLE_CONTROL_ACTION(0, static_cast<int>(control), true);

			const auto location = Self::Pos;
			Entity ent = Self::PlayerPed;

			if (Self::Mount && PED::IS_PED_ON_MOUNT(Self::PlayerPed))
				ent = Self::Mount;
			else if (Self::Veh)
				ent = Self::Veh;

			// cleanup when changing entities
			if (m_Entity != ent)
			{
				ENTITY::FREEZE_ENTITY_POSITION(m_Entity, false);
				ENTITY::SET_ENTITY_COLLISION(m_Entity, true, false);

				m_Entity = ent;
			}

			Vector3 vel{};

			// Left Shift
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)eNativeInputs::INPUT_SPRINT))
				vel.z += speed / 2;
			// Left Control
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)eNativeInputs::INPUT_DUCK) || PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)eNativeInputs::INPUT_HORSE_STOP))
				vel.z -= speed / 2;
			// Forward
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)eNativeInputs::INPUT_MOVE_UP_ONLY))
				vel.y += speed;
			// Backward
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)eNativeInputs::INPUT_MOVE_DOWN_ONLY))
				vel.y -= speed;
			// Left
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)eNativeInputs::INPUT_MOVE_LEFT_ONLY))
				vel.x -= speed;
			// Right
			if (PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)eNativeInputs::INPUT_MOVE_RIGHT_ONLY))
				vel.x += speed;

			auto rot = CAM::GET_GAMEPLAY_CAM_ROT(2);
			ENTITY::SET_ENTITY_ROTATION(ent, 0.f, rot.y, rot.z, 2, 0);
			ENTITY::SET_ENTITY_COLLISION(ent, false, false);
			if (vel.x == 0.f && vel.y == 0.f && vel.z == 0.f)
			{
				// freeze entity to prevent drifting when standing still
				ENTITY::FREEZE_ENTITY_POSITION(ent, true);
				m_SpeedMultiplier = 0.f;
			}
			else
			{
				if (m_SpeedMultiplier < 20.f)
					m_SpeedMultiplier += 0.07f;

				ENTITY::FREEZE_ENTITY_POSITION(ent, false);

				#if 0
				// TODO
				const auto offset = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ent, vel.x, vel.y, 0.f);
				vel.x             = offset.x - location.x;
				vel.y             = offset.y - location.y;

				ENTITY::SET_ENTITY_VELOCITY(ent, vel.x * m_SpeedMultiplier, vel.y * m_SpeedMultiplier, vel.z * m_SpeedMultiplier);
				#else
				const auto offset = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(ent, vel.x * m_SpeedMultiplier, vel.y * m_SpeedMultiplier, vel.z * m_SpeedMultiplier);

				ENTITY::SET_ENTITY_VELOCITY(ent, 0, 0, 0);
				ENTITY::SET_ENTITY_COORDS_NO_OFFSET(ent, offset.x, offset.y, offset.z, true, true, true);
				#endif
			}
		}

		virtual void OnDisable() override
		{
			ENTITY::FREEZE_ENTITY_POSITION(m_Entity, false);
			ENTITY::SET_ENTITY_COLLISION(m_Entity, true, false);
		}
	};

	static Noclip _NoClip{"noclip", "No Clip", "Allows you to fly through the map"};
}