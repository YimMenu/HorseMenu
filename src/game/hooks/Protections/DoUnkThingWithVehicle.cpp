#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include <entity/fwEntity.hpp>

namespace YimMenu::Hooks
{
	void Protections::DoUnkThingWithVehicle(__int64 net_object, uint16_t a2, __int64 a3)
	{
		auto thingy = *(__int64*)(net_object + 0xA8);
		if (thingy)
		{
			auto thingy2 = *(__int64*)(thingy + 0x50);
			if (thingy2 && (*(int*)(thingy2 + 0x5C) & 0xF) >= 2)
			{
				auto vehicle = *(rage::fwEntity**)(thingy2);

				if (vehicle && vehicle->m_EntityType != 3) // peds don't have gadgets
				{
					LOG(WARNING) << __FUNCTION__ ": blocked crash attempt";
					*(rage::fwEntity**)(thingy2) = nullptr; // not a vehicle
				}
			}
		}

		BaseHook::Get<Protections::DoUnkThingWithVehicle, DetourHook<decltype(&Protections::DoUnkThingWithVehicle)>>()
		    ->Original()(net_object, a2, a3);
	}
}