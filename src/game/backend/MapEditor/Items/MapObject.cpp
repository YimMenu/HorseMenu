#include "MapObject.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Object.hpp"

namespace YimMenu
{
	bool MapObject::CreateGameObjectImpl()
	{
		if (m_GameEntity)
			DestroyGameObject();

		m_GameEntity = Object::Create(m_ModelHash, m_Position);
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

	void MapObject::CreateBlip()
	{
		if (m_Blip || !m_GameEntity)
			return;

		m_Blip = MAP::BLIP_ADD_FOR_ENTITY("BLIP_STYLE_CREATOR_DEFAULT"_J, m_GameEntity.GetHandle());
		MAP::BLIP_ADD_MODIFIER(m_Blip, "BLIP_MODIFIER_MP_COLOR_22"_J);
		MAP::SET_BLIP_SPRITE(m_Blip, "BLIP_AMBIENT_PED_SMALL"_J, true);
		MAP::_SET_BLIP_NAME(m_Blip, "Prop"sv.data());
	}

	void MapObject::ChangeModel(std::uint32_t model)
	{
		if (m_ModelHash == model)
			return;

		DestroyGameObject();
		m_ModelHash = model;
		CreateGameObject();
	}

	std::shared_ptr<MapEntity> MapObject::Clone()
	{
		return std::make_shared<MapObject>(*this);
	}

	void MapObject::Update()
	{
		MapEntity::Update();
		if (m_GameEntity && m_GameEntity.HasControl())
			m_GameEntity.SetFrozen(true);
	}
}