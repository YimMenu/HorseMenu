#include "Ped.hpp"

#include "Natives.hpp"
#include "game/backend/ScriptMgr.hpp"


namespace YimMenu
{
	Ped Ped::Create(uint32_t model, rage::fvector3 coords, float heading)
	{
		ENTITY_ASSERT_SCRIPT_CONTEXT();
		if (!STREAMING::IS_MODEL_IN_CDIMAGE(model))
		{
#ifdef ENTITY_DEBUG
			LOGF(WARNING, "Invalid model passed to Ped::Create: 0x{:X}", model);
#endif
			return nullptr;
		}

		for (int i = 0; !STREAMING::HAS_MODEL_LOADED(model); i++)
		{
			STREAMING::REQUEST_MODEL(model, false);
			ScriptMgr::Yield();

			if (i > 30)
			{
#ifdef ENTITY_DEBUG
				LOGF(WARNING, "Model 0x{:X} failed to load after 30 ticks, bailing out", model);
#endif
				return nullptr;
			}
		}

		auto ped = Ped(PED::CREATE_PED(model, coords.x, coords.y, coords.z, heading, 1, 0, 0, 0));

		if (!ped)
		{
#ifdef ENTITY_DEBUG
			LOGF(WARNING, "CREATE_PED failed when creating a ped with model {:X}", model);
#endif
			return nullptr;
		}

		PED::_SET_RANDOM_OUTFIT_VARIATION(ped.GetHandle(), true);
		ENTITY::PLACE_ENTITY_ON_GROUND_PROPERLY(ped.GetHandle(), true);
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

	Vehicle Ped::GetVehicle()
	{
		ENTITY_ASSERT_VALID();
		return Vehicle(PED::GET_VEHICLE_PED_IS_IN(GetHandle(), true));
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
		return PED::GET_PED_BONE_COORDS(GetHandle(), bone, 0, 0, 0);
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

	void Ped::SetTargetActionDisableFlag(int flag, bool enabled)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();

		if (enabled)
			PED::_SET_PED_TARGET_ACTION_DISABLE_FLAG(GetHandle(), flag);
		else
			PED::_CLEAR_PED_TARGET_ACTION_DISABLE_FLAG(GetHandle(), flag);
	}

	bool Ped::IsEnemy()
	{
		ENTITY_ASSERT_VALID();

		// TODO: maybe use a class member?
		auto r1  = PED::GET_RELATIONSHIP_BETWEEN_PEDS(GetHandle(), PLAYER::PLAYER_PED_ID());
		auto r2  = PED::GET_RELATIONSHIP_BETWEEN_PEDS(PLAYER::PLAYER_PED_ID(), GetHandle());
		auto r3  = PED::IS_PED_IN_COMBAT(GetHandle(), PLAYER::PLAYER_PED_ID()) ? 5 : 0;
		auto rel = std::max({r1, r2, r3});

		return rel == 3 || rel == 4 || rel == 5;
	}

	void Ped::SetScale(float scale)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		PED::_SET_PED_SCALE(GetHandle(), scale);
	}

	int Ped::GetAccuracy()
	{
		ENTITY_ASSERT_VALID();
		return PED::GET_PED_ACCURACY(GetHandle());
	}

	void Ped::SetAccuracy(int accuracy)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		PED::SET_PED_ACCURACY(GetHandle(), accuracy);
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