#pragma once
#include "Entity.hpp"

namespace YimMenu
{
	class Vehicle : public Entity
	{
	public:
		using Entity::Entity;

		static Vehicle Create(std::uint32_t model, rage::fvector3 coords, float heading = 0.0f);

		// draft
		bool IsDraft();
		int GetNumDraftAnimals();
		Entity GetPedInHarness(int id);
	};
}