#pragma once
#include "MapEditorCamera.hpp"

namespace YimMenu
{
	class MapEditorCustomCamera final : public MapEditorCamera
	{
	public:
		Cam m_Camera;
		rage::fvector3 m_Position;
		rage::fvector3 m_Rotation;
		float m_Speed;
		float m_PanAcceleration;
		float m_ZoomAcceleration;
		rage::fvector3 m_OldPlayerPos;

		virtual void Setup() override;
		virtual void Destroy() override;
		virtual void Update(MapControls& controls) override;
		virtual bool IsPlayerMode() override;
		virtual std::optional<RaycastResult> Raycast(Entity ignoreEntity) override;
	};
}