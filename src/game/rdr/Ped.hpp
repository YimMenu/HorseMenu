#pragma once
#include "Entity.hpp"
#include "Enums.hpp"

namespace YimMenu
{
	class Ped : public Entity
	{
	public:
		using Entity::Entity;

		static Ped Create(std::uint32_t model, rage::fvector3 coords, float heading = 0.0f, bool blockNewPedMovement = false, bool spawnDead = false, bool invincible = false, bool invisible = false, int scale = 1);

		// info
		Ped GetMount();
		Ped GetLastMount();
		Entity GetVehicle();

		// stamina
		float GetStamina();
		void SetStamina(float amount);
		float GetMaxStamina();

		// ragdoll
		bool GetRagdoll();
		void SetRagdoll(bool enabled);

		// motivation
		float GetMotivation(MotivationState state);
		void SetMotivation(MotivationState state, float value);

		// mount
		void SetInMount(Ped mount, int seat = -1);

		// bones
		rage::fvector3 GetBonePosition(int bone);

		// config flags
		bool GetConfigFlag(PedConfigFlag flag);
		void SetConfigFlag(PedConfigFlag flag, bool value);

		// player
		// We're returning a handle here and not a Player because we don't want to create a cyclic import dependency
		int GetPlayer();
	};
}