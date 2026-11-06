#include "core/commands/BoolCommand.hpp"
#include "core/commands/FloatCommand.hpp"
#include "core/commands/ListCommand.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Entity.hpp"
#include "game/rdr/Ped.hpp"
#include "game/rdr/Player.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Pools.hpp"
#include "util/Math.hpp"
#include "rage/vector.hpp"

#include <numbers>


namespace Terminus::Features
{
	static FloatCommand _AimbotDistance{"aimbotdistance", "Distance", "Aimbot maximum distance.", 50.0f, 500.0f, 50.0f};
	static FloatCommand _AimbotFOV{"aimbotfov", "FOV", "Field Of View", 0.0f, 50.0f, 1.0f};
	static FloatCommand _AimbotSmoothingSpd{"aimbotsmoothingspd", "Smoothing ", "Smoothing speed. Higher value = smoother snapping onto target.", 0.0f, 10.0f, 0.0f};

	static BoolCommand _AimbotSmoothing{"aimbotsmoothing", "Smoothing", "Enable aimbot smoothing."};
	static BoolCommand _AimbotEnemies{"aimbotenemies", "Enemies", "Aim at enemies"};
	static BoolCommand _AimbotPlayers{"aimbotplayers", "Players", "Aim at players"};
	static BoolCommand _AimbotNPC{"aimbotnpc", "NPC", "Aim at neutral NPCs"};
	static BoolCommand _AimbotAnimals{"aimbotanimals", "Animals", "Aim at animals."};
	static BoolCommand _AimbotWildAnimals{"aimbotwildanimals", "Only Wild Animals", "Only aim at wild animals."};
	static BoolCommand _AimbotIgnoreFriendlies{"aimbotignorefriendlies", "Exclude Friendlies", "Exclude friendly peds and player friends."};

	static ListCommand _AimbotBone{"aimbotbone", "Bone", "Target body part to aim at.", 
	{
		{21030, "Head"},
		{14283, "Neck"},
		{14410, "Torso"},
		{44903, "Left Shoulder"},
		{22711, "Left Elbow"},
		{34606, "Left Hand"},
		{4312, "Right Shoulder"},
		{2992, "Right Elbow"},
		{22798, "Right Hand"},
		{22173, "Left Knee"}, 
		{45454, "Left Foot"}, 
		{63133, "Right Knee"},
		{33646, "Right Foot"}},
	21030};

	static const bool IsZeroVector(const Vector3& vec)
	{
		return vec.x == 0.f && vec.y == 0.f && vec.z == 0.f;
	}

	static float GetMagnitudeFromVector3(const rage::fvector3& vec)
	{
		return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	}

	static rage::fvector3 NormalizeVector3(const rage::fvector3& vec)
	{
		auto len = GetMagnitudeFromVector3(vec);
		if (len)
			return vec * (1 / len);

		return vec;
	}

	class Aimbot : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		static inline bool initialized;
		static inline Vector3 smoothing;
		static inline Vector3 targetPos;
		static inline Ped target{0};

		static const bool IsFriendly(Ped ped)
		{
			if (ped.IsPlayer())
			{
				Player other = Player(ped.GetPlayer());
				if (other.IsFriend())
					return true;

				return Self::GetPlayer().GetTeam() == other.GetTeam();
			}

			return ped.IsFriendly();
		}

		static void AcquireTarget()
		{
			target = Ped(0);

			Ped self                  = Self::GetPed();
			const int playerHandle    = self.GetHandle();
			const int playerIndex     = Self::GetPlayer().GetId();
			const int mountHandle     = Self::GetMount().GetHandle();
			const int lastMountHandle = self.GetLastMount().GetHandle();

			if (!GetPedPool() || !WEAPON::IS_PED_ARMED(playerHandle, 4) || !PLAYER::IS_PLAYER_FREE_AIMING(playerIndex))
			{
				Reset();
				return;
			}

			const Vector3 playerPos = self.GetPosition();
			const Vector3 camPos    = CAM::GET_GAMEPLAY_CAM_COORD();
			const Vector3 camRot    = CAM::GET_GAMEPLAY_CAM_ROT(0);
			const Vector3 camDir    = NormalizeVector3(Math::RotationToDirection(camRot));

			const float distance      = _AimbotDistance.GetState();
			const float maxDistanceSq = distance * distance;
			const float fovRadians    = _AimbotFOV.GetState() * std::numbers::pi_v<float> / 180.0f;
			const float minDot        = std::cos(fovRadians * 0.5f);

			float bestDot = -1.0f;
			Ped bestTarget(0);

			for (auto ped : Pools::GetPeds())
			{
				const int handle = ped.GetHandle();

				if (handle == 0 || handle == playerHandle || handle == mountHandle || handle == lastMountHandle)
					continue;

				if (ped.IsDead() || !ENTITY::_GET_ENTITY_CAN_BE_DAMAGED(handle))
					continue;

				if (_AimbotIgnoreFriendlies.GetState() && IsFriendly(ped))
					continue;

				const Vector3 pos = ped.GetPosition();
				if (BUILTIN::VDIST2(playerPos.x, playerPos.y, playerPos.z, pos.x, pos.y, pos.z) > maxDistanceSq)
					continue;

				const bool isAnimal     = ped.IsAnimal();
				const bool isPlayer     = ped.IsPlayer();
				const bool isEnemy      = ped.IsEnemy();
				const bool isNPC        = (!isAnimal && !isPlayer && !isEnemy);
				const bool isWildAnimal = isAnimal && FLOCK::_GET_ANIMAL_IS_WILD(handle);

				bool found = false;

				if (isPlayer && _AimbotPlayers.GetState())
					found = true;

				if (isEnemy && _AimbotEnemies.GetState())
					found = true;

				if (isNPC && _AimbotNPC.GetState())
					found = true;

				if (isAnimal && _AimbotAnimals.GetState())
					found = _AimbotWildAnimals.GetState() ? isWildAnimal : true;

				if (!found)
					continue;

				if (!ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(playerHandle, handle, 17))
					continue;

				Vector3 bonePos       = ped.GetBonePosition(_AimbotBone.GetState());
				Vector3 direction     = bonePos - camPos;
				const float magnitude = std::hypot(direction.x, direction.y, direction.z);
				if (magnitude < 0.001f)
					continue;

				direction.x /= magnitude;
				direction.y /= magnitude;
				direction.z /= magnitude;

				const float dot = camDir.x * direction.x + camDir.y * direction.y + camDir.z * direction.z;
				if (dot < minDot || dot <= bestDot)
					continue;

				bestDot    = dot;
				bestTarget = ped;
			}

			target = bestTarget;
		}

		static void Reset()
		{
			target      = Ped(0);
			targetPos   = {};
			initialized = false;
		}

		virtual void OnTick() override
		{
			const int playerHandle = Self::GetPed().GetHandle();
			const int playerIndex  = Self::GetPlayer().GetId();

			if (PED::IS_PED_RELOADING(playerHandle))
				return;

			if (!PLAYER::IS_PLAYER_FREE_AIMING(playerIndex))
			{
				Reset();
				return;
			}

			if (!target.IsValid() || target.IsDead())
			{
				AcquireTarget();

				if (!target.IsValid())
					return;
			}

			targetPos = target.GetBonePosition(_AimbotBone.GetState());
			if (IsZeroVector(targetPos))
			{
				Reset();
				return;
			}

			Vector3 targetDir = targetPos - CAM::GET_GAMEPLAY_CAM_COORD();
			float magnitude   = std::hypot(targetDir.x, targetDir.y, targetDir.z);
			if (magnitude < 0.001f)
			{
				Reset();
				return;
			}

			targetDir.x /= magnitude;
			targetDir.y /= magnitude;
			targetDir.z /= magnitude;

			Vector3 camTarget;

			if (_AimbotSmoothing.GetState())
			{
				if (!initialized)
				{
					smoothing   = Math::RotationToDirection(CAM::GET_GAMEPLAY_CAM_ROT(0));
					initialized = true;
				}

				float alpha = std::clamp(_AimbotSmoothingSpd.GetState() / 10.f, 0.001f, 1.0f);

				smoothing.x += (targetDir.x - smoothing.x) * alpha;
				smoothing.y += (targetDir.y - smoothing.y) * alpha;
				smoothing.z += (targetDir.z - smoothing.z) * alpha;

				magnitude = std::hypot(smoothing.x, smoothing.y, smoothing.z);
				if (magnitude < 0.001f)
				{
					Reset();
					return;
				}

				smoothing.x /= magnitude;
				smoothing.y /= magnitude;
				smoothing.z /= magnitude;

				camTarget = smoothing;
			}
			else
			{
				camTarget = targetDir;
			}

			constexpr float RADPI = 180.0f / std::numbers::pi;
			float camMagnitude    = std::hypot(camTarget.x, camTarget.y, camTarget.z);
			float camHeading      = atan2f(camTarget.x, camTarget.y) * RADPI;
			float camPitch        = asinf(camTarget.z / camMagnitude) * RADPI;
			float selfHeading     = ENTITY::GET_ENTITY_HEADING(playerHandle);
			float selfPitch       = ENTITY::GET_ENTITY_PITCH(playerHandle);

			if (camHeading >= 0.0f && camHeading <= 180.0f)
			{
				camHeading = 360.0f - camHeading;
			}
			else if (camHeading <= -0.0f && camHeading >= -180.0f)
			{
				camHeading = -camHeading;
			}

			float headingDelta = camHeading - selfHeading;
			float pitchDelta   = camPitch - selfPitch;
			if (CAM::IS_FIRST_PERSON_CAMERA_ACTIVE(0, 0, 0))
			{
				CAM::SET_FIRST_PERSON_AIM_CAM_RELATIVE_HEADING_LIMITS_THIS_UPDATE(headingDelta, headingDelta);
				CAM::SET_FIRST_PERSON_AIM_CAM_RELATIVE_PITCH_LIMITS_THIS_UPDATE(pitchDelta, pitchDelta);
			}
			else
			{
				CAM::SET_GAMEPLAY_CAM_RELATIVE_HEADING(headingDelta, 1.0f);
				CAM::SET_GAMEPLAY_CAM_RELATIVE_PITCH(pitchDelta, 1.0f);
			}
		}

		virtual void OnDisable() override
		{
			Reset();
		}
	};

	static Aimbot _Aimbot{"aimbot", "Aimbot", "Aims for you."};
}
