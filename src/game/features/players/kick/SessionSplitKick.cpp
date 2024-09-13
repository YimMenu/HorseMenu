#include "game/commands/PlayerCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Scripts.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/backend/PlayerData.hpp"

#include <script/globals/ACEHostData.hpp>

namespace YimMenu::Features
{
	class SessionSplitKick : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			if (auto thread = Scripts::FindScriptThread("net_ambient_content_evaluator"_J))
			{
				Scripts::ForceScriptHost(thread);

				auto data                          = ScriptGlobal(1207480).As<ACE_HOST_DATA*>();
				data->RuntimeData.SlotIndices[0]   = 0;
				data->Missions.Datas[0].ScriptHash = "net_session_split"_J;
				data->Missions.Datas[0].StackSize  = 128;
				data->Missions.Datas[0].ConfigFlags.Value = 0;
				data->Missions.Datas[0].ConfigFlags.Set(ACEConfigFlags::USE_LAUNCHER);
				data->Missions.Datas[0].ConfigFlags.Set(ACEConfigFlags::USE_BEAT_THREAD);
				data->Missions.Datas[0].State                       = ACEHostMissionState::MISSION_RUNNING;
				data->Missions.Datas[0].NumLocations                = 1;
				data->Missions.Datas[0].Locations[0].InstanceId     = 0;
				data->Missions.Datas[0].Locations[0].LaunchDistance = 999999;
				data->Missions.Datas[0].BeatParameter2              = 0;
				data->Missions.Datas[0].BeatParameter3              = 0;
				data->Missions.Datas[0].BeatParameter4              = -1;
				data->Missions.Slots[0].Priority                    = ACESlotPriority::HIGH;
				data->Missions.Slots[0].IdentifierData.UID          = {3, 0};
				data->RuntimeData.RuntimeMissionDatas[0].Locations[0].State = ACEHostRuntimeState((__rdtsc() % 2000) + 5);

				player.GetData().m_UseSessionSplitKick = true;
			}
		}
	};

	static SessionSplitKick _SessionSplitKick{"splitkick", "Split Kick", "Kicks the player from the session by triggering a session split. Note that the player would simply be desynced, not booted to the landing page"};
}