#include "Features.hpp"

#include "core/commands/BoolCommand.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/frontend/ContextMenu.hpp"
#include "game/frontend/GUI.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	BoolCommand _IsFirstLoadComplete{"firstloadcomplete", "Is First Load Complete", "Used to detect if the first load has been completed or not."};
}

namespace YimMenu
{
	void SpectateTick()
	{
		if (g_SpectateId != Players::GetSelected().GetId() && g_Spectating
		    && ENTITY::DOES_ENTITY_EXIST(Players::GetSelected().GetPed().GetHandle()))
		{
			g_SpectateId = Players::GetSelected().GetId();
			NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(true, Players::GetSelected().GetPed().GetHandle());
		}

		if (g_Spectating && g_SpectateId == Players::GetSelected().GetId())
		{
			auto playerPed = Players::GetSelected().GetPed().GetHandle();

			if (!STREAMING::IS_ENTITY_FOCUS(playerPed))
				STREAMING::SET_FOCUS_ENTITY(playerPed);

			if (!NETWORK::NETWORK_IS_IN_SPECTATOR_MODE() && ENTITY::DOES_ENTITY_EXIST(playerPed))
			{
				NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(true, playerPed);
			}
			if (!Players::GetSelected().IsValid())
			{
				STREAMING::CLEAR_FOCUS();
				NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(false, Self::GetPed().GetHandle());
				g_Spectating = false;
				Notifications::Show("Spectate", "Player is no longer in the session.\nSpectate mode disabled.", NotificationType::Warning);
			}
		}
		else
		{
			if (NETWORK::NETWORK_IS_IN_SPECTATOR_MODE())
			{
				STREAMING::CLEAR_FOCUS();
				NETWORK::NETWORK_SET_IN_SPECTATOR_MODE(false, Self::GetPed().GetHandle());
				CAM::_FORCE_LETTER_BOX_THIS_UPDATE();
				CAM::_DISABLE_CINEMATIC_MODE_THIS_FRAME();
			}
		}
	}

	void BlockAllControls()
	{
		FiberPool::Push([] {
			PAD::DISABLE_ALL_CONTROL_ACTIONS(0);
		});
	}

	void TryFirstLoad()
	{
		if (!Features::_IsFirstLoadComplete.GetState())
		{
			Commands::GetCommand<BoolCommand>("detectspoofednames"_J)->SetState(true);
			Commands::GetCommand<BoolCommand>("chathelper"_J)->SetState(true);
			Features::_IsFirstLoadComplete.SetState(true);
		}
	}

	void FeatureLoop()
	{
		TryFirstLoad();
		while (true)
		{
			Players::Tick();
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

	void ContextMenuTick()
	{
		while (true)
		{
			ContextMenu::GameTick();
			ScriptMgr::Yield();
		}
	}
}
