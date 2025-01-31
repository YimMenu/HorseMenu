#include "MapPed.hpp"
#include "game/rdr/Ped.hpp"
#include "game/rdr/Natives.hpp"
#include "PedScenarios.hpp"

namespace YimMenu
{
	bool MapPed::CreateGameObjectImpl()
	{
		if (m_GameEntity)
			DestroyGameObject();

		m_GameEntity = Ped::Create(m_ModelHash, m_Position, 0.0);
		if (!m_GameEntity)
			return false;

		m_GameEntity.PreventMigration();
		m_GameEntity.SetRotation(m_Rotation);
		m_GameEntity.SetInvincible(true);
		m_GameEntity.As<Ped>().SetVariation(m_Variation);
		ChangeScenario(m_Scenario);
		ChangeScale(m_Scale);

		if (m_Hidden)
			Hide();
		if (m_Selected)
			Select();
		return true;
	}

	void MapPed::CreateBlip()
	{
		if (m_Blip || !m_GameEntity)
			return;

		m_Blip = MAP::BLIP_ADD_FOR_ENTITY("BLIP_STYLE_CREATOR_DEFAULT"_J, m_GameEntity.GetHandle());
		MAP::BLIP_ADD_MODIFIER(m_Blip, "BLIP_MODIFIER_MP_COLOR_10"_J);
		MAP::SET_BLIP_SPRITE(m_Blip, "BLIP_AMBIENT_PED_SMALL"_J, true);
		MAP::_SET_BLIP_NAME(m_Blip, "Actor"sv.data());
	}
	
	void MapPed::ChangeModel(std::uint32_t model)
	{
		if (m_ModelHash == model)
			return;

		DestroyGameObject();
		m_ModelHash = model;
		m_Variation = 0;
		CreateGameObject(); // run this again to recreate ped
	}

	std::shared_ptr<MapEntity> MapPed::Clone()
	{
		return std::make_shared<MapPed>(*this);
	}

	void MapPed::Update()
	{
		MapEntity::Update();
		if (auto entity = m_GameEntity)
			PED::_REQUEST_PED_FACIAL_MOOD_THIS_FRAME(entity.GetHandle(), m_Expression, 6);
	}

	void MapPed::ChangeVariation(int new_variation)
	{
		m_Variation = new_variation;

		if (m_GameEntity)
			m_GameEntity.As<Ped>().SetVariation(m_Variation);

		ChangeScale(m_Scale); // you need to do this or the scale reverts back
	}

	void MapPed::ChangeScenario(std::uint32_t new_scenario)
	{
		m_Scenario = new_scenario;

		if (m_GameEntity)
		{
			auto handle = m_GameEntity.GetHandle();
			TASK::CLEAR_PED_TASKS_IMMEDIATELY(handle, true, true);
			if (DoesScenarioUseChair(m_Scenario))
			{
				auto dimensions = GetDimensions();
				auto pos_to_use = m_Position;
				pos_to_use.z -= std::abs(dimensions.m_Min.z);
				TASK::TASK_START_SCENARIO_AT_POSITION(handle, m_Scenario, pos_to_use.x, pos_to_use.y, pos_to_use.z, m_Rotation.z, -1, false, true, nullptr, 1.0f, 0); // locks the ped during selection, but
				                                                                                                                                                      // TASK_START_SCENARIO_IN_PLACE_HASH does that for these task types too
			}
			else
			{
				TASK::TASK_START_SCENARIO_IN_PLACE_HASH(handle, m_Scenario, -1, false, 0, -1, false);
			}
		}
	}

	void MapPed::ChangeScale(float scale)
	{
		m_Scale = scale;
		if (m_GameEntity)
			m_GameEntity.As<Ped>().SetScale(m_Scale);
	}

	void MapPed::Serialize(nlohmann::json& object)
	{
		MapEntity::Serialize(object);
		object["variation"] = m_Variation;
		object["scenario"] = m_Scenario;
		object["expression"] = m_Expression;
		object["scale"] = m_Scale;
	}

	void MapPed::Deserialize(nlohmann::json& object)
	{
		MapEntity::Deserialize(object);
		m_Variation = object["variation"];
		m_Scenario = object["scenario"];
		if (auto it = object.find("expression"); it != object.end())
			m_Expression = *it;
		if (auto it = object.find("scale"); it != object.end())
			m_Scale = *it;
	}
}