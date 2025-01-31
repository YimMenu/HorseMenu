#pragma once
#include "game/backend/MapEditor/MapControls.hpp"
#include "game/rdr/Entity.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu
{
	class MapEditorCamera
	{
	public:
		struct RaycastResult
		{
			rage::fvector3 m_Position;
			Entity m_HitEntity;
		};

		virtual void Setup() = 0;
		virtual void Destroy() = 0;
		virtual void Update(MapControls& controls) = 0;
		virtual bool IsPlayerMode() = 0;
		virtual std::optional<RaycastResult> Raycast(Entity ignoreEntity) = 0;
	};
}