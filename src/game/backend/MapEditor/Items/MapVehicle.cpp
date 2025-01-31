#include "MapVehicle.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Vehicle.hpp"

namespace YimMenu
{
	bool MapVehicle::CreateGameObjectImpl()
	{
		if (m_GameEntity)
			DestroyGameObject();

		m_GameEntity = Vehicle::Create(m_ModelHash, m_Position);
		if (!m_GameEntity)
			return false;

		m_GameEntity.PreventMigration();
		m_GameEntity.SetRotation(m_Rotation);
		m_GameEntity.SetInvincible(true);

		if (m_Hidden)
			Hide();
		if (m_Selected)
			Select();
		return true;
	}

	void MapVehicle::CreateBlip()
	{
		if (m_Blip || !m_GameEntity)
			return;

		m_Blip = MAP::BLIP_ADD_FOR_ENTITY("BLIP_STYLE_CREATOR_DEFAULT"_J, m_GameEntity.GetHandle());
		MAP::BLIP_ADD_MODIFIER(m_Blip, "BLIP_MODIFIER_MP_COLOR_13"_J);
		MAP::SET_BLIP_SPRITE(m_Blip, "BLIP_AMBIENT_PED_SMALL"_J, true);
		MAP::_SET_BLIP_NAME(m_Blip, "Vehicle"sv.data());
	}

	void MapVehicle::ChangeModel(std::uint32_t model)
	{
		if (m_ModelHash == model)
			return;

		DestroyGameObject();
		m_ModelHash = model;
		CreateGameObject();
	}

	std::shared_ptr<MapEntity> MapVehicle::Clone()
	{
		return std::make_shared<MapVehicle>(*this);
	}

	void MapVehicle::Update()
	{
		MapEntity::Update();
	}
}