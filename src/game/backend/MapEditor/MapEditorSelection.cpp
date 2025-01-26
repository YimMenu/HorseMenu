#include "MapEditorSelection.hpp"
#include "MapEditor.hpp"

namespace YimMenu
{
	float MapEditorSelection::GetGroundOffset(rage::fvector3& rotation, MapEntity::ModelDimensions& dimensions)
	{
		return std::abs(dimensions.m_Min.z);
	}

	void MapEditorSelection::Update(MapEditorCamera& cam, MapControls& controls)
	{
		auto raycast = cam.Raycast(m_Entity ? m_Entity->m_GameEntity : nullptr);

		auto pointed_entity = raycast ? raycast->m_HitEntity : nullptr;
		std::optional<std::uint32_t> pointed_item;
		bool can_pick_up_item = !HasSelection() || !HasConcreteSelection();
		bool accept_pressed = controls.GetDpadAccept().IsJustPressed(MapControl::Subsystem::SELECTION);
		bool cancel_pressed = controls.GetDpadCancel().IsJustPressed(MapControl::Subsystem::SELECTION);
		bool delete_pressed = controls.GetDpadDelete().IsJustPressed(MapControl::Subsystem::SELECTION);

		if (pointed_entity)
		{
			pointed_item = MapEditor::GetIndexFromGameEntity(pointed_entity);
		}

		if (pointed_item.has_value() && can_pick_up_item && accept_pressed)
		{
			// let go of an existing item if we have one
			if (HasSelection())
				MapEditor::CancelSelection();

			// and select this one
			MapEditor::SelectItem(*pointed_item);
		}
		else if (HasSelection() && accept_pressed)
		{
			MapEditor::PlaceItem();
		}
		else if (HasConcreteSelection() && cancel_pressed)
		{
			MapEditor::CancelSelection();
		}
		else if (HasConcreteSelection() && delete_pressed)
		{
			// TODO: is this normal creator behavior?
			MapEditor::DeleteEntity(*m_ExistingEntity);
		}
		else if (pointed_item && delete_pressed)
		{
			// delete pointed item
			MapEditor::DeleteEntity(*pointed_item);
			pointed_item = std::nullopt;
			pointed_entity = nullptr;
		}

		if (HasConcreteSelection())
		{
			// ensure that we handle all back button events when selecting an existing entity
			controls.GetDpadCancel().SetExclusive(MapControl::Subsystem::SELECTION);
		}

		if (accept_pressed)
		{
			AUDIO::PLAY_SOUND_FRONTEND("SELECT", "HUD_PLAYER_MENU", 1, 0);
		}

		if (cancel_pressed)
		{
			AUDIO::PLAY_SOUND_FRONTEND("BACK", "HUD_PLAYER_MENU", 1, 0);
		}

		if (raycast)
		{
			if (HasSelection())
				UpdateControls(raycast->m_Position, controls);
			DrawCursor(raycast->m_Position);
		}
	}

	void MapEditorSelection::UpdateControls(rage::fvector3& hit_coords, MapControls& controls)
	{
		auto preview_pos = hit_coords;
		auto dimensions  = m_Entity->GetDimensions();
		preview_pos.z += GetGroundOffset(m_Entity->m_Rotation, dimensions);
		m_Entity->Move(preview_pos);

		bool rotate_left = controls.GetRotateLeft().IsPressed(MapControl::Subsystem::SELECTION);
		bool rotate_right = controls.GetRotateRight().IsPressed(MapControl::Subsystem::SELECTION);

		if (rotate_left ^ rotate_right)
		{
			auto rot = m_Entity->m_Rotation;

			if (rotate_left)
			{
				rot.z += 5.0f;
			}

			if (rotate_right)
			{
				rot.z -= 5.0f;
			}

			m_Entity->Rotate(rot);
		}
	}

	void MapEditorSelection::DrawCursor(rage::fvector3& hit_coords)
	{
		GRAPHICS::_DRAW_MARKER(0x6903B113, hit_coords.x, hit_coords.y, hit_coords.z + 0.01f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 255, 255, 255, 255, false, true, 2, false, nullptr, nullptr, false);
	}
}