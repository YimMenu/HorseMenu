#include "game/backend/Self.hpp"
#include "game/backend/Players.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "core/commands/ListCommand.hpp"
#include "core/commands/BoolCommand.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Scripts.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	static std::vector<std::pair<int, const char*>> g_TickerEvents = 
	{
	    {0, "JOINED_DEFAULT"},
	    {2, "VERSUS_NORMAL"},
	    {3, "VERSUS_TEAMKILL"},
	    {4, "VERSUS_SUICIDE"},
	    {6, "VERSUS_INCAPACITATED"},
	    {7, "VERSUS_INCAPACITATED_EXECUTION"},
	    {8, "INCAPACITATION_REVIVE"},
	    {9, "INCAPACITATION_SELF_REVIVE"},
	    {10, "MONEYBAG_PICKUP"},
	    {11, "MONEYBAG_DROPPED"},
	    {12, "INVITE_RECEIVED"},
	    {13, "J_SKIP"},
	    {14, "P_SKIP"},
	    {15, "F_SKIP"},
	    {16, "S_SKIP"},
	    {17, "MISSION_TIMER_SKIP"},
	    {18, "TIME_SKIP"},
	    {19, "WEATHER"},
	    {20, "INVULNERABLE"},
	    {21, "VULNERABLE"},
	    {22, "WEAPONS"},
	    {23, "CHEAT_XP_PLUS"},
	    {24, "CHEAT_XP_MINUS"},
	    {25, "CHEAT_MONEY"},
	    {26, "CHEAT_HONOR_PLUS"},
	    {27, "CHEAT_HONOR_MINUS"},
	    {28, "CHEAT_WARP"},
	    {29, "CHEAT_DEADEYE"},
	    {30, "CHEAT_INFINITE_DEADEYE"},
	    {31, "CHEAT_INFINITE_STAMINA"},
	    {32, "CHEAT_REFILL_RPG_CORES"},
	    {33, "CHEAT_REFILL_RPG_TANKS"},
	    {34, "CHEAT_OVERPOWER_RPG_CORES"},
	    {35, "CHEAT_DISABLE_INFINITE_STAMINA"},
	    {36, "CHEAT_DISABLE_INFINITE_DEADEYE"},
	    {37, "CHEAT_DEADEYE_REMOVE_ALL"},
	    {38, "CHEAT_HEALTH"},
	    {39, "CHEAT_VEHICLE"},
	    {44, "NET_UNLOCK"},
	    {45, "PERSONA_LEVEL_UP"},
	    {46, "GANG_INVITE"},
	    {47, "GANG_REQUEST"},
	    {48, "GANG_JOINED"},
	    {50, "GANG_KICKED"},
	    {51, "GANG_LEFT"},
	    {52, "GANG_STARTED"},
	    {53, "GANG_CAMP_PLACED"},
	    {54, "GANG_CAMP_FAIL"},
	    {55, "GANG_CAMP_READY"},
	    {56, "GANG_CAMP_ATTEMPT"},
	    {57, "GANG_CAMP_SEARCH"},
	    {58, "GANG_CAMP_SHUTDOWN"},
	    {60, "GANG_ON_MISSION"},
	    {61, "P_POSSE_START"},
	    {62, "P_POSSE_FAIL"},
	    {63, "P_POSSE_JOIN"},
	    {64, "P_POSSE_LEAVE"},
	    {65, "P_POSSE_PROMOTED"},
	    {66, "P_POSSE_DEMOTED"},
	    {68, "STORY_MISSION_INVITE_RECEIVED"},
	    {71, "NET_GANG_BOUNTY_TURNIN"},
	    {72, "VS_MISSION_INVITE"},
	    {73, "VS_MISSION_FAILED_TO_JOIN"},
	    {74, "VS_MISSION_REQUEST_TO_LEADER"},
	    {75, "VS_MISSION_FORCE_JOIN"},
	    {76, "VS_MISSION_FORCE_LEAVE_FULL"},
	    {77, "VS_MISSION_FORCE_REMOVE_INVITE"},
	    {78, "IN_WORLD_DEATHMATCH_1V1"},
	    {79, "IN_WORLD_DEATHMATCH_POSSE_V_POSSE"},
	    {80, "IN_WORLD_DEATHMATCH_POSSE_LEADER_FEUD"},
	    {81, "IN_WORLD_DEATHMATCH_POSSE_FEUD"},
	    {82, "IN_WORLD_DEATHMATCH_POSSE_INFIGHTING"},
	    {83, "IN_WORLD_DEATHMATCH_POSSE_FEUD_MEMBERS"},
	    {84, "IN_WORLD_DEATHMATCH_POSSE_LEADER_FEUD_MEMBERS"},
	    {92, "HUNTSMEN_PRISTINE_SKIN_FOUND"},
	    {93, "CONVOY_ROBBERY_TURN_IN"},
	    {94, "PLAYER_FORCE_DEBUG_WARP"},
	    {95, "ANIMAL_ATTACK_REWARD"},
	    {96, "MINIGAME_INVITE"},
	    {101, "SHOP_SPLIT_MONEY_WITH_POSSE"},
	    {102, "PASSIVE_MODE_ENDED"},
	    {103, "PRESSED_CHARGES"},
	    {108, "PLAYER_BOUNTY_PVP_MISSION_FAILED_TO_LAUNCH"},
	    {109, "PLAYER_FLAVORED_MOONSHINE"},
	    {110, "PLAYER_KILLED_LEGENDARY_ANIMAL"},
	    {111, "PLAYER_TRANQUILIZED_LEGENDARY_ANIMAL"},
	    {112, "ABANDONED_LOOT_OPENED"}
	};

	static ListCommand _TickerMessage{"tickermessage", "Ticker Message", "The ticker message to send", g_TickerEvents, 0};
	//static BoolCommand _RandomSender{"randomsender", "Random Sender", "Randomize the sending player"};

	void SendTickerMessage(Player player)
	{
		auto bits = 1 << player.GetId();		uint64_t data[19]{};
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