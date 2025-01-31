#include "MapEntity.hpp"
#include "../MapEditor.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu
{
	void MapEntity::AddToGlobalStore()
	{
		MapEditor::AddEntityToGlobalStore(this);
	}

	void MapEntity::RemoveFromGlobalStore()
	{
		MapEditor::RemoveEntityFromGlobalStore(this);
	}

	void MapEntity::DeleteBlip()
	{
		MAP::_0x01B928CA2E198B01(m_Blip);
		MAP::REMOVE_BLIP(&m_Blip);
	}

	MapEntity::~MapEntity()
	{
		DestroyGameObject();
		RemoveFromGlobalStore();
	}

	void MapEntity::CreateGameObject()
	{
		if (!m_GameEntity)
			m_ObjectCreationPending = true;
	}

	void MapEntity::Update()
	{
		if (m_ObjectCreationPending)
		{
			STREAMING::REQUEST_MODEL(m_ModelHash, false);
			if (STREAMING::HAS_MODEL_LOADED(m_ModelHash))
			{
				// assume the code there would take care of unloading the entity model
				if (CreateGameObjectImpl())
				{
					CreateBlip();
					m_ObjectCreationPending = false;
				}
			}
		}

		if ((m_Hidden || !MapEditor::IsOpen()) && m_Blip)
			MAP::BLIP_ADD_MODIFIER(m_Blip, "BLIP_MODIFIER_HIDDEN"_J);
		else if (m_Blip)
			MAP::BLIP_REMOVE_MODIFIER(m_Blip, "BLIP_MODIFIER_HIDDEN"_J);

		if (m_GameEntity && !m_GameEntity.IsVehicle() && !m_GameEntity.HasControl())
			m_GameEntity.ForceControl();
	}

	void MapEntity::DestroyGameObject()
	{
		if (!m_GameEntity)
			return;

		DeleteBlip();
		m_GameEntity.Delete();
		m_GameEntity = nullptr;
		m_ObjectCreationPending = false;
	}

	void MapEntity::Move(rage::fvector3 new_pos)
	{
		m_Position = new_pos;

		if (m_GameEntity)
			m_GameEntity.SetPosition(new_pos);
	}

	void MapEntity::Rotate(rage::fvector3 new_rot)
	{
		m_Rotation = new_rot;

		if (m_GameEntity)
			m_GameEntity.SetRotation(new_rot);
	}

	void MapEntity::Select()
	{
		if (m_GameEntity)
		{
			m_GameEntity.SetFrozen(true);
			m_GameEntity.SetCollision(false);
			m_GameEntity.SetAlpha(190);
		}
		m_Selected = true;
	}

	void MapEntity::Place()
	{
		if (m_GameEntity)
		{
			m_GameEntity.SetFrozen(false);
			m_GameEntity.SetCollision(true);
			m_GameEntity.ResetAlpha();
		}
		m_Selected = false;
		m_LastEditTime = std::chrono::system_clock::now(); // object has ideally been modified now
	}

	void MapEntity::Hide()
	{
		m_GameEntity.SetCollision(false);
		m_GameEntity.SetVisible(false);
		m_Hidden = true;
	}

	void MapEntity::Unhide()
	{
		m_GameEntity.SetCollision(true);
		m_GameEntity.SetVisible(true);
		m_Hidden = false;
	}

	MapEntity::ModelDimensions MapEntity::GetDimensions()
	{
		ModelDimensions dim;
		Vector3 min;
		Vector3 max;
		MISC::GET_MODEL_DIMENSIONS(m_ModelHash, &min, &max);
		dim.m_Min = min;
		dim.m_Max = max;
		return dim;
	}

	void MapEntity::Serialize(nlohmann::json& object)
	{
		object["type"] = static_cast<int>(m_Type);
		object["model_hash"] = m_ModelHash;
		object["position"] = nlohmann::json::object();
		object["position"]["x"] = m_Position.x;
		object["position"]["y"] = m_Position.y;
		object["position"]["z"] = m_Position.z;
		object["rotation"] = nlohmann::json::object();
		object["rotation"]["x"] = m_Rotation.x;
		object["rotation"]["y"] = m_Rotation.y;
		object["rotation"]["z"] = m_Rotation.z;
	}

	void MapEntity::Deserialize(nlohmann::json& object)
	{
		m_Type = static_cast<Type>(object["type"]);
		m_ModelHash = object["model_hash"];
		m_Position.x = object["position"]["x"];
		m_Position.y = object["position"]["y"];
		m_Position.z = object["position"]["z"];
		m_Rotation.x = object["rotation"]["x"];
		m_Rotation.y = object["rotation"]["y"];
		m_Rotation.z = object["rotation"]["z"];
	}
}