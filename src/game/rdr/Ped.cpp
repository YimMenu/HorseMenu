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
			LOG(WARNING) << "Invalid model passed to Ped::Create: " << HASH(model);
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
		return Ped(PED::GET_MOUNT(GetHandle()));
	}

	Entity Ped::GetVehicle()
	{
		ENTITY_ASSERT_VALID();
		return Entity(PED::GET_VEHICLE_PED_IS_IN(GetHandle(), true));
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
}