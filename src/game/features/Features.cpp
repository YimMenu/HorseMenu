#include "Features.hpp"
#include "game/rdr/Natives.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Players.hpp"
#include "game/rdr/Enums.hpp"
#include "game/frontend/GUI.hpp"

namespace YimMenu
{
	static void UpdateSelfVars()
	{
		Self::PlayerPed = PLAYER::PLAYER_PED_ID();
		Self::Id        = PLAYER::PLAYER_ID();
		Self::Pos       = ENTITY::GET_ENTITY_COORDS(Self::PlayerPed, true, true);
		Self::Rot       = ENTITY::GET_ENTITY_ROTATION(Self::PlayerPed, 2);

		if (PED::IS_PED_IN_ANY_VEHICLE(Self::PlayerPed, true))
			Self::Veh = PED::GET_VEHICLE_PED_IS_IN(Self::PlayerPed, true);
		else
			Self::Veh = 0;

		if (PED::IS_PED_ON_MOUNT(Self::PlayerPed))
			Self::Mount = PED::GET_MOUNT(Self::PlayerPed);
		else if (ENTITY::DOES_ENTITY_EXIST(PED::_GET_LAST_MOUNT(Self::PlayerPed)))
			Self::Mount = PED::_GET_LAST_MOUNT(Self::PlayerPed);
		else if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_MOUNT_OWNED_BY_PLAYER(Self::Id)))
			Self::Mount = PLAYER::GET_MOUNT_OWNED_BY_PLAYER(Self::Id);
		else
			Self::Mount = 0;

		Self::IsOnMount = PED::IS_PED_ON_MOUNT(Self::PlayerPed);
	}

	void SpectateTick()
	{
		if (g_Spectating && Players::GetSelected().GetPed().IsValid())
		{
			auto playerPed = Players::GetSelected().GetPed().GetHandle();

			if (CAM::HAS_LETTER_BOX())
			{
				CAM::_REQUEST_LETTER_BOX_NOW(false, false);
				CAM::_FORCE_LETTER_BOX_THIS_UPDATE();
			}

			NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(true, playerPed);

			if (!STREAMING::IS_ENTITY_FOCUS(playerPed) || g_SpectateId != Players::GetSelected().GetId())
			{
				STREAMING::SET_FOCUS_ENTITY(playerPed);
			}

			if (!Players::GetSelected().IsValid())
			{
				Notifications::Show("Spectate", "Player is no longer in the session.\nSpectate mode disabled.", NotificationType::Warning);
				g_Spectating = false;
			}
			g_SpectateId = Players::GetSelected().GetId();
		}
		else
		{
			NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(false, Self::PlayerPed);
			STREAMING::CLEAR_FOCUS();
			CAM::_REQUEST_LETTER_BOX_NOW(false, false);
			CAM::_FORCE_LETTER_BOX_THIS_UPDATE();
		}
	}


	void BlockAllControls()
	{
		FiberPool::Push([] {
			PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
		});
	}

	void FeatureLoop()
	{
		while (true)
		{
			Players::Tick();
			UpdateSelfVars();
			*Pointers.RageSecurityInitialized = false;
			*Pointers.ExplosionBypass         = true;
			Commands::RunLoopedCommands();
			g_HotkeySystem.FeatureCommandsHotkeyLoop();
			SpectateTick();

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
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_VEH_CAR_AIM, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_VEH_CAR_ATTACK, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_VEH_CAR_ATTACK2, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_VEH_CAR_ATTACK2, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_VEH_BOAT_AIM, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_VEH_BOAT_ATTACK, 1);
				PAD::DISABLE_CONTROL_ACTION(0, (Hash)eNativeInputs::INPUT_VEH_BOAT_ATTACK2, 1);
			}

			ScriptMgr::Yield();
		}
	}
}
