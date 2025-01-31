#pragma once
#include "MapEntity.hpp"
#include "util/Joaat.hpp"

namespace YimMenu
{
	class MapVehicle final : public MapEntity
	{
	protected:
		virtual bool CreateGameObjectImpl() override;
		virtual void CreateBlip() override;

	public:
		MapVehicle() :
		    MapEntity()
		{
			m_Type      = Type::VEHICLE;
			m_ModelHash = "wagoncircus01x"_J;
		}

		MapVehicle(const MapVehicle& other) :
		    MapEntity(other)
		{
		}

		virtual void ChangeModel(std::uint32_t model) override;
		virtual std::shared_ptr<MapEntity> Clone() override;
		virtual void Update() override;
	};
}