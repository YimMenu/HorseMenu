#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/pointers/Pointers.hpp"

#include <format>


namespace YimMenu::Features
{
	class PresenceKick : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			if (player.IsValid())
			{
				std::string msg = std::vformat("{'gm.evt':{'e':'RsJoinRequest','d':{'j':'Gk25CAAAAAAAAAMAAAAAAA==','n':'{}','u':214470434,'f':8257,'d':2603989090,'a':0}}}",
				    std::make_format_args(player.GetName()));
				Pointers.PostPresenceMessage(0, player.GetGamerInfo(), 1, msg.c_str(), 0);
			}
		}
	};

	static PresenceKick _PresenceKick{"presencekick", "Presence Kick", "Kicks a player from your session using presence events!"};
}