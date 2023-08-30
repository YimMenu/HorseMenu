#include "Features.hpp"
#include "game/rdr/Natives.hpp"
#include "core/commands/Commands.hpp"
#include "game/backend/ScriptMgr.hpp"

namespace YimMenu
{
	static void UpdateSelfVars()
	{
		Self::PlayerPed = PLAYER::PLAYER_PED_ID();
		Self::Id  = PLAYER::PLAYER_ID();
		Self::Pos = ENTITY::GET_ENTITY_COORDS(Self::PlayerPed, true, true);
		Self::Rot = ENTITY::GET_ENTITY_ROTATION(Self::PlayerPed, 2);

		if (PED::IS_PED_IN_ANY_VEHICLE(Self::PlayerPed, true))
			Self::Veh = PED::GET_VEHICLE_PED_IS_IN(Self::PlayerPed, true);

		if (PED::IS_PED_ON_MOUNT(Self::PlayerPed))
			Self::Mount = PED::GET_MOUNT(Self::PlayerPed);
		
		if (!ENTITY::DOES_ENTITY_EXIST(Self::Mount) && ENTITY::DOES_ENTITY_EXIST(PED::_GET_LAST_MOUNT(Self::PlayerPed)))
			Self::Mount = PED::_GET_LAST_MOUNT(Self::PlayerPed);
	}

	void FeatureLoop()
	{
		while (true)
		{
			UpdateSelfVars();
			Commands::RunLoopedCommands();
			ScriptMgr::Yield();
		}
	}
}
