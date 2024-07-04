#include "Entity.hpp"
#include "Enums.hpp"

namespace YimMenu
{
	class Ped : public Entity
	{
	public:
		using Entity::Entity;

		static Ped Create(std::uint32_t model, rage::fvector3 coords, float heading = 0.0f, bool blockNewPedMovement = false, bool spawnDead = false, bool invincible = false, bool invisible = false, int scale = 1);
		Ped GetMount();
		Entity GetVehicle();
		rage::fvector3 GetBonePosition(int bone);

		// config flags
		bool GetConfigFlag(PedConfigFlag flag);
		void SetConfigFlag(PedConfigFlag flag, bool value);
	};
}