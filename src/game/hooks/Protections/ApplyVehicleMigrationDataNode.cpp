#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Entity.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Natives.hpp"

#include <entity/fwEntity.hpp>
#include <network/netObject.hpp>
#include <ped/CPed.hpp>

namespace YimMenu::Hooks
{
	void Protections::ApplyVehicleMigrationDataNode(__int64 iface, __int64 data)
	{
		auto vehicle = Entity(*((void**)iface - 0x3D8));
		auto seats   = (int16_t*)(data + 0x16);
		auto player_ped = Pointers.GetLocalPed();

		if (player_ped && player_ped->m_NetObject)
		{
			for (int i = 0; i < 16; i++)
			{
				if (seats[i] == player_ped->m_NetObject->m_ObjectId)
				{
					auto plyr_veh = Entity(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), true));

					if (plyr_veh.GetPointer<void*>() != vehicle.GetPointer<void*>())
					{
						LOG(WARNING) << "Blocked possible teleport attempt";
						return;
					}

					break;
				}
			}
		}

		BaseHook::Get<Protections::ApplyVehicleMigrationDataNode, DetourHook<decltype(&Protections::ApplyVehicleMigrationDataNode)>>()
		    ->Original()(iface, data);
	}
}