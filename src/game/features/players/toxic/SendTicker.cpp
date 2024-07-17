#include "game/backend/Self.hpp"
#include "game/backend/Players.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "core/commands/ListCommand.hpp"
#include "core/commands/BoolCommand.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Scripts.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/data/TickerEvents.hpp"

namespace YimMenu::Features
{
	static ListCommand _TickerMessage{"tickermessage", "Ticker Message", "The ticker message to send", Data::g_TickerEvents, 2};

	void SendTickerMessage(Player player)
	{
		uint64_t data[19]{};
		data[0]  = static_cast<uint64_t>(ScriptEvent::SCRIPT_EVENT_TICKER_MESSAGE);
		data[1]  = player.GetId();
		data[2]  = NETWORK::GET_NETWORK_TIME_ACCURATE();
		data[4]  = _TickerMessage.GetState();
		data[12] = -1;
		data[13] = -1;
		data[14] = 255;
		data[18] = 1;

		Scripts::SendScriptEvent(data, 19, 7, 1 << player.GetId());
	}

	class SendTicker : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			SendTickerMessage(player);
		}
	};

	static SendTicker _SendTicker{"sendticker", "Send Ticker Message", "Sends the player a ticker notification", 0, false};
}