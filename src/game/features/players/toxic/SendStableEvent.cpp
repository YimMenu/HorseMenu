#include "core/commands/BoolCommand.hpp"
#include "core/commands/ListCommand.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Scripts.hpp"
#include "game/rdr/data/StableEvents.hpp"

namespace YimMenu::Features
{
	static ListCommand _MountInstance{"mountinstance", "Mount Instance", "Which type of vehicle/mount to target", Data::g_MountInstance, 0};
	static ListCommand _StableMountEvent{"stablemountevent", "Stable Mount Event", "The event to send", Data::g_StableMountEvent, 0};

	void SendNetStableMountEvent(Player player)
	{
		uint64_t data[6]{};
		data[0] = static_cast<uint64_t>(ScriptEvent::SCRIPT_EVENT_NET_STABLE_MOUNT);
		data[1] = player.GetId();
		data[2] = NETWORK::GET_NETWORK_TIME_ACCURATE();
		data[4] = _StableMountEvent.GetState();
		data[5] = _MountInstance.GetState();

		Scripts::SendScriptEvent(data, 6, 0, 1 << player.GetId());
	}

	class SendStableMountEvent : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			SendNetStableMountEvent(player);
		}
	};

	static SendStableMountEvent _SendStableMountEvent{"sendstablemountevent", "Send Stable Mount Event", "Not known yet", 0, false};
}
