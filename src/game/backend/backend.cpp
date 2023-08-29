#include "backend.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Enums.hpp"
#include "game/frontend/GUI.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "looped/Looped.hpp"
#include "commands/FeatureCommand.hpp"
#include "game/backend/commands/HotkeySystem.hpp"

namespace YimMenu
{
	void backend::controls()
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
			}

			
			

			ScriptMgr::Yield();
		}
	}

	void backend::hotkeys()
	{
		while (true)
		{

			g_HotkeySystem.FeatureCommandsHotkeyLoop();

			ScriptMgr::Yield();
		}
	}

	void backend::self()
	{
		while (true)
		{
			looped::SelfLoop();
			looped::KeepHorseBarsFilled();
			looped::KeepHorseCoresFilled();

			ScriptMgr::Yield();
		}
	}

	void backend::looped_commands()
	{
		while (true)
		{
			for (auto& feature_command : RegisteredCommands | std::ranges::views::values)
				if (feature_command.IsLooped() && feature_command.GetGlobal() && *feature_command.GetGlobal())
					feature_command.Call();

			ScriptMgr::Yield();
		}
	}
}