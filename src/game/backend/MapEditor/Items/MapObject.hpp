#pragma once
#include "MapEntity.hpp"
#include "util/Joaat.hpp"

namespace YimMenu
{
	class MapObject final : public MapEntity
	{
	protected:
		virtual bool CreateGameObjectImpl() override;
		virtual void CreateBlip() override;

	public:

		MapObject() :
		    MapEntity()
		{
			m_Type      = Type::OBJECT;
			m_ModelHash = "p_chickenfence01x"_J;
		}

		MapObject(const MapObject& other) :
		    MapEntity(other)
		{
		}

		virtual void ChangeModel(std::uint32_t model) override;
		virtual std::shared_ptr<MapEntity> Clone() override;
		virtual void Update() override;
	};
}