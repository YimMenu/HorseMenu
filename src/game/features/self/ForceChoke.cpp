#include "core/commands/LoopedCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/NativeHooks.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/rdr/Scripts.hpp"

#include <cmath>

namespace Terminus::Features
{
	class ForceChoke : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		Entity m_HeldEntity = 0;
		bool m_WasShooting = false;
		bool m_HasShownNotification = false;
		bool m_SoundLoaded = false;
		std::string m_SoundSetRef = "";

		static constexpr float HOLD_DISTANCE = 5.0f;

		Vector3 getCameraDirection()
		{
			Vector3 cameraRotation = CAM::GET_GAMEPLAY_CAM_ROT(0);

			float pitch = cameraRotation.x * 0.0174532924f;
			float yaw = cameraRotation.z * 0.0174532924f;

			float cosPitch = std::cos(pitch);

			Vector3 direction{-std::sin(yaw) * cosPitch, std::cos(yaw) * cosPitch, std::sin(pitch)};

			return direction;
		}

		Vector3 getCrosshairCoords(float distance)
		{
			Vector3 cameraCoords = CAM::GET_GAMEPLAY_CAM_COORD();
			Vector3 cameraRotation = CAM::GET_GAMEPLAY_CAM_ROT(0);

			float pitch = cameraRotation.x * 0.0174532924f;
			float yaw = cameraRotation.z * 0.0174532924f;

			float cosPitch = std::cos(pitch);
			float sinPitch = std::sin(pitch);
			float cosYaw = std::cos(yaw);
			float sinYaw = std::sin(yaw);

			Vector3 direction;
			direction.x = -sinYaw * cosPitch;
			direction.y = cosYaw * cosPitch;
			direction.z = sinPitch;

			Vector3 targetPos = {cameraCoords.x + direction.x * distance,
			    cameraCoords.y + direction.y * distance,
			    cameraCoords.z + direction.z * distance};

			return targetPos;
		}

		Vector3 getThrowDirection()
		{
			return getCameraDirection();

			Vector3 rotation = CAM::GET_GAMEPLAY_CAM_ROT(0);

			float pitch = rotation.x * 0.0174532924f;

			float yaw = rotation.z * 0.0174532924f;

			float cosPitch = std::cos(pitch);

			return {-std::sin(yaw) * cosPitch, std::cos(yaw) * cosPitch, std::sin(pitch)};
		}

		void setPedFacingCamera(Entity target)
		{
			Ped npc = ENTITY::GET_PED_INDEX_FROM_ENTITY_INDEX(target.GetHandle());

			Vector3 playerPos = Self::GetPed().GetPosition();
			Vector3 npcPos = ENTITY::GET_ENTITY_COORDS(npc.GetHandle(), true, true);

			float dx = playerPos.x - npcPos.x;
			float dy = playerPos.y - npcPos.y;

			float heading = (std::atan2(dy, dx) * 57.2957795f) - 90.0f;

			if (heading < 0.0f)
				heading += 360.0f;
			if (heading >= 360.0f)
				heading -= 360.0f;

			ENTITY::SET_ENTITY_HEADING(npc.GetHandle(), heading);
		}

		void playAnimation(Entity target)
		{
			if (target.GetHandle() == 0 || !ENTITY::DOES_ENTITY_EXIST(target.GetHandle()))
			{
				return;
			}

			Ped npc = ENTITY::GET_PED_INDEX_FROM_ENTITY_INDEX(target.GetHandle());

			if (npc.GetHandle() == 0 || !PED::IS_PED_HUMAN(npc.GetHandle()))
			{
				return;
			}

			target.ForceControl();
			npc.ForceControl();

			ENTITY::FREEZE_ENTITY_POSITION(npc.GetHandle(), true);
			PED::SET_PED_KEEP_TASK(npc.GetHandle(), true);
			PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(npc.GetHandle(), true);
			PED::SET_PED_CAN_PLAY_AMBIENT_ANIMS(npc.GetHandle(), false);
			PED::SET_PED_CAN_PLAY_AMBIENT_BASE_ANIMS(npc.GetHandle(), false);
			WEAPON::REMOVE_ALL_PED_WEAPONS(npc.GetHandle(), true, true);
			PED::SET_PED_MAX_MOVE_BLEND_RATIO(npc.GetHandle(), 0.0f);
			PED::SET_PED_MOVE_RATE_OVERRIDE(npc.GetHandle(), 0.0f);
			PED::SET_PED_CAN_RAGDOLL(npc.GetHandle(), false);
			TASK::CLEAR_PED_TASKS_IMMEDIATELY(npc.GetHandle(), true, true);

			const char* animDict = "script_story@tre2@ig@ig2_dutch_v_hunter";
			const char* animName = "choke_loop_alt_dutch";

			STREAMING::REQUEST_ANIM_DICT(animDict);

			int timeout = 0;
			while (!STREAMING::HAS_ANIM_DICT_LOADED(animDict) && timeout < 100)
			{
				ScriptMgr::Yield(0ms);
				timeout++;
			}

			if (STREAMING::HAS_ANIM_DICT_LOADED(animDict))
			{
				TASK::CLEAR_PED_TASKS_IMMEDIATELY(npc.GetHandle(), true, true);

				TASK::TASK_PLAY_ANIM(npc.GetHandle(), animDict, animName, 8.0f, -8.0f, -1, 1, 0.0f, false, 0, false, "Default", false);

				PED::SET_PED_CAN_PLAY_AMBIENT_ANIMS(npc.GetHandle(), false);
				PED::SET_PED_CAN_PLAY_AMBIENT_BASE_ANIMS(npc.GetHandle(), false);
			}
		}

		void attachEntityToCrosshair(Entity target)
		{
			if (target.GetHandle() == 0 || !ENTITY::DOES_ENTITY_EXIST(target.GetHandle()))
			{
				return;
			}

			target.ForceControl();

			Vector3 coords = getCrosshairCoords(HOLD_DISTANCE);

			coords.z -= 1.3f;

			Ped npc = ENTITY::GET_PED_INDEX_FROM_ENTITY_INDEX(target.GetHandle());

			ENTITY::SET_ENTITY_COORDS(target.GetHandle(), coords.x, coords.y, coords.z, false, true, false, false);
		}

		void resetPedState(Entity target)
		{
			if (target.GetHandle() == 0 || !ENTITY::DOES_ENTITY_EXIST(target.GetHandle()))
			{
				return;
			}

			Ped npc = ENTITY::GET_PED_INDEX_FROM_ENTITY_INDEX(target.GetHandle());

			if (npc.GetHandle() == 0)
			{
				return;
			}

			ENTITY::FREEZE_ENTITY_POSITION(npc.GetHandle(), false);
			PED::SET_PED_KEEP_TASK(npc.GetHandle(), false);
			PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(npc.GetHandle(), false);
			PED::SET_PED_CAN_PLAY_AMBIENT_ANIMS(npc.GetHandle(), true);
			PED::SET_PED_CAN_PLAY_AMBIENT_BASE_ANIMS(npc.GetHandle(), true);
			PED::SET_PED_MAX_MOVE_BLEND_RATIO(npc.GetHandle(), 1.0f);
			PED::SET_PED_MOVE_RATE_OVERRIDE(npc.GetHandle(), 1.0f);
			TASK::CLEAR_PED_TASKS_IMMEDIATELY(npc.GetHandle(), true, true);
			PED::SET_PED_CAN_RAGDOLL(npc.GetHandle(), true);
		}

		void applyForceToTarget(Entity target, float scale)
		{
			if (target.GetHandle() == 0 || !ENTITY::DOES_ENTITY_EXIST(target.GetHandle()))
			{
				return;
			}

			Ped npc = ENTITY::GET_PED_INDEX_FROM_ENTITY_INDEX(target.GetHandle());

			resetPedState(target);

			target.ForceControl();

			Vector3 direction = getThrowDirection();

			float forceScale = scale * 2.5f;
			Vector3 scaledDir = {direction.x * forceScale, direction.y * forceScale, direction.z * forceScale};

			PED::SET_PED_TO_RAGDOLL(npc.GetHandle(), 1, 1, 0, false, false, "DraggedByCart");

			ENTITY::SET_ENTITY_VELOCITY(target.GetHandle(), scaledDir.x, scaledDir.y, scaledDir.z);

			ENTITY::APPLY_FORCE_TO_ENTITY(target.GetHandle(), 1, 0.0f, 0.0f, 2500.0f, 0.0f, 0.0f, 0.0f, 0, false, true, false, false, false);
		}

		void releaseHeldEntity()
		{
			if (m_HeldEntity.GetHandle() == 0)
			{
				return;
			}

			if (!ENTITY::DOES_ENTITY_EXIST(m_HeldEntity.GetHandle()))
			{
				m_HeldEntity = 0;
				return;
			}

			ENTITY::DETACH_ENTITY(m_HeldEntity.GetHandle(), true, true);

			applyForceToTarget(m_HeldEntity, 100000.0f);

			m_HeldEntity = 0;
		}

		virtual void OnTick() override
		{
				auto playerPed = Self::GetPed().GetHandle();

				PLAYER::DISABLE_PLAYER_FIRING(Self::GetPlayer().GetId(), true);

				PAD::DISABLE_CONTROL_ACTION(0, (int)NativeInputs::INPUT_ATTACK, true);

				bool isAimingHeld = PAD::IS_CONTROL_PRESSED(0, (int)NativeInputs::INPUT_AIM);

				bool isShootingHeld = PAD::IS_DISABLED_CONTROL_PRESSED(0, (int)NativeInputs::INPUT_ATTACK);

				bool isShootingReleased = PAD::IS_DISABLED_CONTROL_JUST_RELEASED(0, (int)NativeInputs::INPUT_ATTACK);

				if (m_WasShooting && isShootingReleased)
				{
					releaseHeldEntity();

					m_HasShownNotification = false;
				}

				if (isAimingHeld && isShootingHeld)
				{
					PLAYER::DISABLE_PLAYER_FIRING(Self::GetPlayer().GetId(), true);

					if (m_HeldEntity.GetHandle() == 0)
					{
						auto entityID = 0;
						PLAYER::SET_PLAYER_TARGETING_MODE(3);
						PLAYER::GET_ENTITY_PLAYER_IS_FREE_AIMING_AT(Self::GetPlayer().GetId(), &entityID);

						if (entityID != 0 && ENTITY::DOES_ENTITY_EXIST(entityID) && ENTITY::IS_ENTITY_A_PED(entityID))
						{
							m_HeldEntity = entityID;
							m_HeldEntity.ForceControl();

							setPedFacingCamera(m_HeldEntity);
							playAnimation(m_HeldEntity);

							if (!m_HasShownNotification)
							{
								Notifications::Show("Force Push", "Force Push grabbed entity: " + std::to_string(entityID), NotificationType::Success, 2000);

								m_HasShownNotification = true;
							}
						}
					}

					if (m_HeldEntity.GetHandle() != 0 && ENTITY::DOES_ENTITY_EXIST(m_HeldEntity.GetHandle()))
					{
						attachEntityToCrosshair(m_HeldEntity);
						setPedFacingCamera(m_HeldEntity);
					}
				}

				if (isShootingReleased && m_HeldEntity.GetHandle() != 0)
				{
					releaseHeldEntity();
					m_HasShownNotification = false;
				}

				m_WasShooting = isShootingHeld;
		}

		virtual void OnDisable() override
		{
			if (m_HeldEntity.GetHandle() != 0)
			{
				releaseHeldEntity();
			}

			m_HeldEntity = 0;
			m_WasShooting = false;
			m_HasShownNotification = false;

			PAD::DISABLE_CONTROL_ACTION(0, (int)NativeInputs::INPUT_AIM, false);
			PAD::DISABLE_CONTROL_ACTION(0, (int)NativeInputs::INPUT_ATTACK, false);
		}
	};

	static ForceChoke _ForceChoke{"forcechoke", "Force Choke", "Grabs Peds while holding aim and shoot buttons choking them until you release the shoot button then throws them"};
}