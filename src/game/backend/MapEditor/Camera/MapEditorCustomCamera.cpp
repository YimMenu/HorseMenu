#include "MapEditorCustomCamera.hpp"
#include "util/Math.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu
{
	std::optional<MapEditorCamera::RaycastResult> MapEditorCustomCamera::Raycast(Entity ignoreEntity)
	{
		if (!m_Camera)
			return std::nullopt;

		BOOL hit{};
		Vector3 end_coords{};
		Vector3 surface_normal{};
		int hit_entity{};
		Vector3 dir = Math::RotationToDirection(m_Rotation);
		Vector3 far_coords;

		far_coords.x = m_Position.x + dir.x * 1000;
		far_coords.y = m_Position.y + dir.y * 1000;
		far_coords.z = m_Position.z + dir.z * 1000;

		int ray = SHAPETEST::START_EXPENSIVE_SYNCHRONOUS_SHAPE_TEST_LOS_PROBE(
		    m_Position.x, m_Position.y, m_Position.z, far_coords.x, far_coords.y, far_coords.z, 511, ignoreEntity.GetHandle(), 7);
		auto res = SHAPETEST::GET_SHAPE_TEST_RESULT(ray, &hit, &end_coords, &surface_normal, &hit_entity);

		if (!hit)
			return std::nullopt;

		return MapEditorCamera::RaycastResult{rage::fvector3(end_coords), hit_entity};
	}

	void MapEditorCustomCamera::Setup()
	{
		if (m_Camera)
			return;

		m_Camera       = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 0);
		m_Position     = CAM::GET_GAMEPLAY_CAM_COORD();
		m_Rotation     = CAM::GET_GAMEPLAY_CAM_ROT(2);
		m_PanAcceleration = 0.0f;
		m_ZoomAcceleration = 0.0f;
		m_Speed        = 0.02f;

		CAM::SET_CAM_COORD(m_Camera, m_Position.x, m_Position.y, m_Position.z);
		CAM::SET_CAM_ROT(m_Camera, m_Rotation.x, m_Rotation.y, m_Rotation.z, 2);
		CAM::SET_CAM_ACTIVE(m_Camera, true);
		CAM::RENDER_SCRIPT_CAMS(true, true, 500, true, true, 0);

		m_OldPlayerPos = Self::GetPed().GetPosition();
		TASK::TASK_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Self::GetPed().GetHandle(), true);
	}

	void MapEditorCustomCamera::Destroy()
	{
		Self::GetPed().SetPosition(m_OldPlayerPos);
		TASK::TASK_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(Self::GetPed().GetHandle(), false);
		CAM::SET_CAM_ACTIVE(m_Camera, false);
		CAM::RENDER_SCRIPT_CAMS(false, true, 500, true, true, 0);
		CAM::DESTROY_CAM(m_Camera, false);
		m_Camera = 0;
	}

	void MapEditorCustomCamera::Update(MapControls& controls)
	{
		Vector3 PosChange{};

		Vector3 rot = CAM::GET_CAM_ROT(m_Camera, 2);
		auto pitch = Math::DegToRad(rot.x);
		float yaw   = Math::DegToRad(rot.z);

		// Forward
		if (controls.GetMoveForward().IsPressed(MapControl::Subsystem::CAMERA))
		{
			PosChange.y += m_Speed;
		}
		// Backward
		if (controls.GetMoveBackward().IsPressed(MapControl::Subsystem::CAMERA))
		{
			PosChange.y -= m_Speed;
		}
		// Left
		if (controls.GetMoveLeft().IsPressed(MapControl::Subsystem::CAMERA))
		{
			PosChange.x -= m_Speed;
		}
		// Right
		if (controls.GetMoveRight().IsPressed(MapControl::Subsystem::CAMERA))
		{
			PosChange.x += m_Speed;
		}
		// Zoom In
		if (controls.GetZoomIn().IsPressed(MapControl::Subsystem::CAMERA))
		{
			// move forward AND down
			PosChange.y += m_Speed * 1.2;
			PosChange.z += (m_Speed / Math::DegToRad(45)) * pitch;
		}
		// Zoom Out
		if (controls.GetZoomOut().IsPressed(MapControl::Subsystem::CAMERA))
		{
			// move backward AND up
			PosChange.y -= m_Speed * 1.2;
			PosChange.z -= (m_Speed / Math::DegToRad(45)) * pitch;
		}

		if (PosChange.x == 0.0f && PosChange.y == 0.0f && PosChange.z == 0.0f)
		{
			m_PanAcceleration = 0.0f;
		}
		else if (m_PanAcceleration < 10)
		{
			m_PanAcceleration += 0.15f;
		}

		float additional_accel = 1;
		
		if (controls.GetSpeedUp().IsPressed(MapControl::Subsystem::CAMERA))
			additional_accel = 2.5;

		m_Position.x += (PosChange.x * cos(yaw) - PosChange.y * sin(yaw)) * m_PanAcceleration * additional_accel;
		m_Position.y += (PosChange.x * sin(yaw) + PosChange.y * cos(yaw)) * m_PanAcceleration * additional_accel;
		m_Position.z += PosChange.z * m_PanAcceleration;

		CAM::SET_CAM_COORD(m_Camera, m_Position.x, m_Position.y, m_Position.z);
		Self::GetPed().SetPosition(m_Position);
		m_Rotation = CAM::GET_GAMEPLAY_CAM_ROT(2);
		CAM::SET_CAM_ROT(m_Camera, m_Rotation.x, m_Rotation.y, m_Rotation.z, 2);
		Self::GetPed().SetRotation(m_Rotation);
	}

	bool MapEditorCustomCamera::IsPlayerMode()
	{
		return false; // we don't support that yet
	}
}