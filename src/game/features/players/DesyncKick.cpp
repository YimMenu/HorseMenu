#include "core/frontend/Notifications.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Natives.hpp"

#include <network/CNetworkPlayerMgr.hpp>


namespace YimMenu::Features
{
	class DesyncKick : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			if (!player.IsValid() || !Pointers.NetworkPlayerMgr->m_LocalPlayer->IsValid())
			{
				Notifications::Show("Desync Kick", "Either you or the target player is invalid!", NotificationType::Error);
				return;
			}
			if (Pointers.NetworkPlayerMgr->m_LocalPlayer == nullptr)
			{
				Notifications::Show("Desync Kick", "Local Player is nullptr!", NotificationType::Error);
				return;
			}
			if (player.IsHost())
			{
				Notifications::Show("Desync Kick", "You can't kick the host!", NotificationType::Error);
				return;
			}
			Pointers.NetworkPlayerMgr->RemovePlayer(player.GetHandle());
			WEAPON::REMOVE_ALL_PED_WEAPONS(player.GetPed().GetHandle(), false, false); // trigger a sync
			Pointers.NetworkPlayerMgr->UpdatePlayerListsForPlayer(Pointers.NetworkPlayerMgr->m_LocalPlayer);
		}
	};

	static DesyncKick _DesyncKick{"desync", "Desync Kick", "Desync kick's a player to get them out of your session!"};
}