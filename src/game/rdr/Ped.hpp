#include "Entity.hpp"

namespace YimMenu
{
	class Ped : public Entity
	{
	public:
		using Entity::Entity;

		constexpr Ped GetMount();
		rage::fvector3 GetBonePosition(int bone);
	};
}