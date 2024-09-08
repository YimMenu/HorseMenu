#include "core/frontend/Notifications.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/PlayerData.hpp"
#include "game/rdr/Packet.hpp"

#include <network/CNetworkScSession.hpp>
#include <network/CNetworkScSessionPlayer.hpp>
#include <network/rlScPeerConnection.hpp>
#include <script/scrThread.hpp>

namespace YimMenu::Features
{
	class IceKick : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player target) override
		{
			if (target.GetConnectionType() != 1)
			{
				if (target.GetConnectionType() == 2)
					Notifications::Show("Kick", "Cannot kick the player since they're connected though a relay", NotificationType::Error);
				else if (target.GetConnectionType() == 3)
					Notifications::Show("Kick", "Cannot kick the player since they're connected though a peer relay", NotificationType::Error);
				return;
			}

			for (auto& [_, player] : YimMenu::Players::GetPlayers())
			{
				if (player == Self::GetPlayer() || player == target)
					continue;

				if (!target.IsValid())
					break;

				rage::rlTaskStatus stat{};

				target.GetData().m_PeerIdToSpoofTo = player.GetGamerInfo()->m_PeerId;

				rage::rlGamerInfoBase base      = *target.GetGamerInfo();
				base.m_GamerHandle.m_RockstarId = rand();

				if (!Pointers.OpenIceTunnel(&base, target.GetAddress(), target.GetAddress(), true, 0, 0, &stat))
				{
					LOG(WARNING) << "OpenIceTunnel failed for " << target.GetName();
				}

				while (stat.m_Status == 1)
					ScriptMgr::Yield();

				if (stat.m_Status == 2)
				{
					LOG(WARNING) << "ICE tunnel failed with error code " << stat.m_ErrorCode << " for " << target.GetName();
				}

				target.GetData().m_PeerIdToSpoofTo = std::nullopt;
			}
		}
	};

	static IceKick _IceKick{"icekick", "ICE Kick", "Desyncs the player from the session. Doesn't work if the player is connected through a relay", 0, false};
}