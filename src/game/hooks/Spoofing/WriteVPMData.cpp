#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "util/Storage/Spoofing.hpp"

#include <entity/CDynamicEntity.hpp>
#include <network/netObject.hpp>
#include <network/sync/vehicle/CVehicleProximityMigrationData.hpp>


namespace YimMenu::Hooks
{
	void Spoofing::WriteVPMData(void* veh, CVehicleProximityMigrationData* data)
	{
		CDynamicEntity* vehicle = *(CDynamicEntity**)(((__int64)veh) - 984);

		BaseHook::Get<Spoofing::WriteVPMData, DetourHook<decltype(&Spoofing::WriteVPMData)>>()->Original()(veh, data);

		if (auto it = g_SpoofingStorage.m_RemotePlayerTeleports.find(vehicle->m_NetObject->m_ObjectId);
		    it != g_SpoofingStorage.m_RemotePlayerTeleports.end())
		{
			data->m_PassengersActive[0]   = true;
			data->m_PassengerObjectIds[0] = it->second.m_PlayerNetId;
			data->m_HasPositionData       = true;
			data->m_Position              = it->second.m_Position;
			data->m_VelocityX             = 1;
			data->m_VelocityY             = 1;
			data->m_VelocityZ             = 1;
		}
	}
}