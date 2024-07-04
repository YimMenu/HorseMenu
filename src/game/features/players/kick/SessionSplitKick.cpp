#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Scripts.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/backend/PlayerData.hpp"

namespace YimMenu::Features
{
	class SessionSplitKick : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			Scripts::ForceScriptHost(Scripts::FindScriptThread("net_ambient_content_evaluator"_J));
			auto broadcast                                  = ScriptGlobal(1207480);
			*broadcast.At(2505).At(427).At(0, 1).As<int*>() = 0; // index
			auto mission                                    = broadcast.At(231).At(1066).At(0, 17);
			*mission.At(0).As<joaat_t*>()                   = "net_session_split"_J;
			*mission.At(1).As<joaat_t*>()                   = 128;     // micro
			*mission.At(6).As<int*>()                       = 1 | 128; // NET_ACE_LAUNCHER_CF_USE_LAUNCHER
			*mission.At(13).As<int*>()                      = 2;       // NET_ACE_LAUNCHER_HMS_MISSION_RUNNING?
			*mission.At(7).As<int*>()                       = 1;       // iNumLocations
			*mission.At(8).At(0, 4).At(1).As<int*>()        = 0;       // idk instance ID maybe?
			*mission.At(8).At(0, 4).At(3).As<int*>()        = 999999;  // range check
			*mission.At(14).As<int*>()                      = 0;
			*mission.At(15).As<int*>()                      = 0;
			*mission.At(16).As<int*>()                      = -1;
			auto uid_data                                   = broadcast.At(231).At(0, 15);
			*uid_data.At(1).As<int*>()                      = 2; // high priority
			*uid_data.At(5).As<int*>()                      = 3; // UID data
			*uid_data.At(6).As<int*>()                      = 0;
			auto location_data                              = broadcast.At(2505).At(0, 6).At(0, 3);
			*location_data.As<int*>()                       = (__rdtsc() % 2000) + 5; // start val
			player.GetData().m_UseSessionSplitKick = true;
		}
	};

	static SessionSplitKick _SessionSplitKick{"splitkick", "Split Kick", "Kicks the player from the session by triggering a session split. Note that the player would simply be desynced, not booted to the landing page"};
}