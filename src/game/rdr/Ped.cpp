#include "Ped.hpp"
#include "Natives.hpp"
#include "game/backend/ScriptMgr.hpp"

namespace YimMenu
{
	Ped Ped::Create(std::uint32_t model, rage::fvector3 coords, float heading, bool blockNewPedMovement, bool spawnDead, bool invincible, bool invisible, int scale)
	{
		if (!STREAMING::IS_MODEL_IN_CDIMAGE(model))
		{
#ifdef ENTITY_DEBUG
			LOG(WARNING) << "Invalid model passed to Ped::Create: " << HEX(model);
#endif
			return nullptr;
		}

		for (int i = 0; i < 30 && !STREAMING::HAS_MODEL_LOADED(model); i++)
		{
			STREAMING::REQUEST_MODEL(model, false);
			ScriptMgr::Yield();
		}

		auto ped = Ped(PED::CREATE_PED(model, coords.x, coords.y, coords.z, heading, 1, 0, 0, 0));

		PED::_SET_RANDOM_OUTFIT_VARIATION(ped.GetHandle(), true);
		ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(ped.GetHandle(), true);

		ped.SetFrozen(blockNewPedMovement);
		ped.SetInvincible(invincible);
		ped.SetVisible(!invisible);
		PED::_SET_PED_SCALE(ped.GetHandle(), (float)scale);

		if (spawnDead)
			ped.SetHealth(0);

		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
		return ped;
	}

	Ped Ped::GetMount()
	{
		ENTITY_ASSERT_VALID();
		if (PED::IS_PED_ON_MOUNT(GetHandle()))
			return Ped(PED::GET_MOUNT(GetHandle()));
		else
			return nullptr;
	}

	Ped Ped::GetLastMount()
	{
		ENTITY_ASSERT_VALID();
		return Ped(PED::_GET_LAST_MOUNT(GetHandle()));
	}

	Entity Ped::GetVehicle()
	{
		ENTITY_ASSERT_VALID();
		return Entity(PED::GET_VEHICLE_PED_IS_IN(GetHandle(), true));
	}

	float Ped::GetStamina()
	{
		ENTITY_ASSERT_VALID();
		return PED::_GET_PED_STAMINA(GetHandle());
	}

	void Ped::SetStamina(float amount)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		PED::_CHANGE_PED_STAMINA(GetHandle(), amount - GetStamina());
	}

	float Ped::GetMaxStamina()
	{
		ENTITY_ASSERT_VALID();
		return PED::_GET_PED_MAX_STAMINA(GetHandle());
	}

	bool Ped::GetRagdoll()
	{
		ENTITY_ASSERT_VALID();
		return PED::CAN_PED_RAGDOLL(GetHandle());
	}

	void Ped::SetRagdoll(bool enabled)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		PED::SET_PED_CAN_RAGDOLL(GetHandle(), enabled);
	}

	float Ped::GetMotivation(MotivationState state)
	{
		ENTITY_ASSERT_VALID();
		return PED::_GET_PED_MOTIVATION(GetHandle(), (int)state, 0);
	}

	void Ped::SetMotivation(MotivationState state, float value)
	{
		ENTITY_ASSERT_VALID();
		// control not required
		PED::_SET_PED_MOTIVATION(GetHandle(), (int)state, value, 0);
	}

	void Ped::SetInMount(Ped mount, int seat)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		ENTITY_ASSERT_SCRIPT_CONTEXT();
		PED::SET_PED_ONTO_MOUNT(GetHandle(), mount.GetHandle(), seat, true);
	}

	rage::fvector3 Ped::GetBonePosition(int bone)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_SCRIPT_CONTEXT();
		auto coords = PED::GET_PED_BONE_COORDS(GetHandle(), bone, 0, 0, 0);
		return rage::fvector3(coords.x, coords.y, coords.z);
	}

	bool Ped::GetConfigFlag(PedConfigFlag flag)
	{
		ENTITY_ASSERT_VALID();
		return PED::GET_PED_CONFIG_FLAG(GetHandle(), (int)flag, false);
	}

	void Ped::SetConfigFlag(PedConfigFlag flag, bool value)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		PED::SET_PED_CONFIG_FLAG(GetHandle(), (int)flag, value);
	}

	int Ped::GetPlayer()
	{
		ENTITY_ASSERT_VALID();
#ifdef ENTITY_DEBUG
		if (!IsPlayer())
		{
			LOG(WARNING) << __FUNCTION__ ": ped is not a player!";
		}
#endif
		return NETWORK::NETWORK_GET_PLAYER_INDEX_FROM_PED(GetHandle());
	}
}