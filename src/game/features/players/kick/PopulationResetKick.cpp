#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Packet.hpp"
#include "game/pointers/Pointers.hpp"
#include "core/frontend/Notifications.hpp"

#include <network/rlScPeerConnection.hpp>
#include <script/scrThread.hpp>
#include <network/CNetworkScSessionPlayer.hpp>
#include <network/CNetworkScSession.hpp>

namespace YimMenu::Features
{
	class PopulationResetKick : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			if ((*Pointers.ScSession)->m_SessionMultiplayer->GetPlayerByIndex(player.GetId())->m_SessionPeer->m_IsHost)
			{
				Notifications::Show("Kick", "Cannot use this against the host", NotificationType::Error);
				return;
			}

			Packet sync;
			sync.WriteMessageHeader(NetMessageType::RESET_POPULATION);
			sync.GetBuffer().Write<bool>(false, 1);
			sync.GetBuffer().Write<bool>(false, 1);
			sync.Send(player, 13, true, true);
		}
	};

	static PopulationResetKick _PopulationResetKick{"popkick", "Population Reset Kick", "Kicks the player from the session by making them spam complaints to the server. Note that the player would simply be desynced, not booted to the landing page. Does not work against the host", 0, false};
}