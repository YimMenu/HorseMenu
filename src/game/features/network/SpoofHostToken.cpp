#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Players.hpp"
#include "game/features/Features.hpp"
#include "game/pointers/Pointers.hpp"

#include <network/rlGamerInfo.hpp>


namespace YimMenu::Features
{
	class SpoofHostToken : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (auto self = Player(Self::Id); !self.IsHost() && self.IsValid())
			{
				for (auto& player : Players::GetPlayers())
				{
					if (player.second.IsHost() && player.second.IsValid()
					    && (self.GetGamerInfo()->m_HostToken - 1 != player.second.GetGamerInfo()->m_HostToken - 1))
					{
						*Pointers.HostToken = player.second.GetGamerInfo()->m_HostToken - 1;
					}
				}
			}
		}

		virtual void OnDisable() override
		{
			uint64_t host_token;
			Pointers.GenerateUUID(&host_token);
			*Pointers.HostToken = host_token;
		}
	};

	static SpoofHostToken _SpoofHostToken{"spoofhosttoken", "Spoof Host Token", "Allows you to be host once the current one leaves!"};
}