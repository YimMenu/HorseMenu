#pragma once
#include "Items/MapEntity.hpp"
#include "Camera/MapEditorCamera.hpp"
#include "MapControls.hpp"

namespace YimMenu
{
	// please do not use anything here directly, use the interfaces provided by MapEditor instead
	class MapEditorSelection
	{
		static float GetGroundOffset(rage::fvector3& rotation, MapEntity::ModelDimensions& dimensions);

	public:
		std::shared_ptr<MapEntity> m_Entity           = nullptr;
		std::optional<std::uint32_t> m_ExistingEntity = std::nullopt;

		bool HasSelection() const
		{
			return m_Entity != nullptr;
		}

		// an existing entity rather than an "ambient" one
		bool HasConcreteSelection() const
		{
			return HasSelection() && m_ExistingEntity.has_value();
		}

		bool IsEntitySelected(std::uint32_t index) const
		{
			return HasSelection() && m_ExistingEntity.has_value() && m_ExistingEntity.value() == index;
		}

		void UnlinkSelectedEntity()
		{
			if (HasSelection())
				m_ExistingEntity = std::nullopt;
		}

		void Clear()
		{
			m_Entity         = nullptr;
			m_ExistingEntity = std::nullopt;		
		}

		void Update(MapEditorCamera& cam, MapControls& controls);
		void UpdateControls(rage::fvector3& hit_coords, MapControls& controls);
		void DrawCursor(rage::fvector3& hit_coords);
	};
}