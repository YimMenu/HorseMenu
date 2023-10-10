#include "Features.hpp"
#include "game/rdr/Natives.hpp"
#include "core/commands/Commands.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "game/frontend/GUI.hpp"
#include "game/rdr/Enums.hpp"

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
		else
			Self::Veh = 0;

		if (PED::IS_PED_ON_MOUNT(Self::PlayerPed))
			Self::Mount = PED::GET_MOUNT(Self::PlayerPed);
		else if (ENTITY::DOES_ENTITY_EXIST(PED::_GET_LAST_MOUNT(Self::PlayerPed)))
			Self::Mount = PED::_GET_LAST_MOUNT(Self::PlayerPed);
		else
			Self::Mount = 0;
	}

	void FeatureLoop()
	{
		while (true)
		{
			UpdateSelfVars();
			*Pointers.RageSecurityInitialized = false;
			Commands::RunLoopedCommands();
			g_HotkeySystem.FeatureCommandsHotkeyLoop();
			ScriptMgr::Yield();
		}
	}

	void BlockControlsForUI()
	{
		while (true)
		{
			if (GUI::IsOpen())
			{
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_LOOK_LR, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_LOOK_UD, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_AIM, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_MELEE_ATTACK, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_VEH_DRIVE_LOOK, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_VEH_AIM, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_VEH_ATTACK, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_VEH_ATTACK2, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_HORSE_AIM, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_HORSE_ATTACK, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_HORSE_ATTACK2, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_HORSE_GUN_LR, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_HORSE_GUN_UD, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_VEH_DRIVE_LOOK2, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_ATTACK, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_ATTACK2, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_NEXT_WEAPON, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_PREV_WEAPON, 1);
			}

			ScriptMgr::Yield();
		}
	}
}
