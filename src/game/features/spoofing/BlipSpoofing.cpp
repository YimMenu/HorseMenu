#include "core/commands/LoopedCommand.hpp"
#include "core/commands/ListCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "util/Joaat.hpp"

namespace YimMenu::Features
{
	static std::vector<std::pair<int, const char*>> g_OverheadSprites = {
	    {"REVIVE"_J, "REVIVE"},
	    {"POSSE_LEADER"_J, "POSSE LEADER"},
	    {"POSSE_DEPUTY"_J, "POSSE DEPUTY"},
	    {"GENERIC_PLAYER"_J, "GENERIC PLAYER"},
	    {"GENERIC_OBJECTIVE"_J, "GENERIC OBJECTIVE"},
	    {"KING"_J, "KING"},
	    {"CASH_BAG"_J, "CASH_BAG"},
	    {"VIP"_J, "VIP"},
	    {"WAGON"_J, "WAGON"},
	    {"DEADEYE"_J, "DEADEYE"},
	    {"KILL_1"_J, "KILL_1"},
	    {"KILL_2"_J, "KILL_2"},
	    {"KILL_3"_J, "KILL_3"},
	    {"KILL_4"_J, "KILL_4"},
	    {"KILL_5"_J, "KILL_5"},
	    {"KILL_6"_J, "KILL_6"},
	    {"KILL_7"_J, "KILL_7"},
	    {"KILL_8"_J, "KILL_8"},
	    {"KILL_9"_J, "KILL_9"},
	    {"KILL_10"_J, "KILL_10"},
	    {"KILL_11"_J, "KILL_11"},
	    {"KILL_12"_J, "KILL_12"},
	    {"KILL_13"_J, "KILL_13"},
	    {"KILL_14"_J, "KILL_14"},
	    {"KILL_15"_J, "KILL_15"},
	    {"KILL_16"_J, "KILL_16"},
	    {"KILL_17"_J, "KILL_17"},
	    {"KILL_18"_J, "KILL_18"},
	    {"KILL_19"_J, "KILL_19"},
	    {"KILL_20"_J, "KILL_20"},
	    {"KILL_21"_J, "KILL_21"},
	    {"KILL_22"_J, "KILL_22"},
	    {"KILL_23"_J, "KILL_23"},
	    {"KILL_24"_J, "KILL_24"},
	    {"KILL_25"_J, "KILL_25"},
	    {"KILL_26"_J, "KILL_26"},
	    {"KILL_27"_J, "KILL_27"},
	    {"KILL_28"_J, "KILL_28"},
	    {"KILL_29"_J, "KILL_29"},
	    {"KILL_30"_J, "KILL_30"},
	    {"KILL_31"_J, "KILL_31"},
	    {"KILL_32"_J, "KILL_32"},
	    {"PLAYER_HORSE"_J, "PLAYER_HORSE"},
	    {"PLAYER_HORSE_TEMP"_J, "PLAYER_HORSE_TEMP"},
	    {"SPEAKER"_J, "SPEAKER"},
	    {"BOUNTY"_J, "BOUNTY"},
	    {"AMBIENT_HUNTER"_J, "AMBIENT_HUNTER"},
	    {"MARKED_FOR_DEATH"_J, "MARKED_FOR_DEATH"},
	    {"GENERIC_ARROW"_J, "GENERIC_ARROW"},
	    {"SPEAKER_OFF"_J, "SPEAKER_OFF"},
	    {"GENERIC_BAG"_J, "GENERIC_BAG"},
	    {"SHIELD"_J, "SHIELD"},
	    {"HONOUR"_J, "HONOUR"},
	};

	static ListCommand _PrimaryStatusIcon{"primaryicon", "Primary Status Icon", "The primary status icon", g_OverheadSprites, (int)0xA243B5A4};
	static ListCommand _SecondaryStatusIcon{"secondaryicon", "Secondary Status Icon", "The secondary status icon", g_OverheadSprites, (int)0xA243B5A4};

	class SpoofPrimaryStatusIcon : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;
		static constexpr auto primaryStatusIcon = ScriptGlobal(1072759).At(21889).At(581);

		virtual void OnTick() override
		{
			if (*Pointers.IsSessionStarted)
			{
				if (primaryStatusIcon.CanAccess())
				{
					*primaryStatusIcon.As<int*>() = _PrimaryStatusIcon.GetState();
				}
			}
		}
	};

    class SpoofSecondaryStatusIcon : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;
		static constexpr auto secondaryStatusIcon = ScriptGlobal(1072759).At(21889).At(582);

		virtual void OnTick() override
		{
			if (*Pointers.IsSessionStarted)
			{
				if (secondaryStatusIcon.CanAccess())
				{
					*secondaryStatusIcon.As<int*>() = _SecondaryStatusIcon.GetState();
				}
			}
		}
	};

	static SpoofPrimaryStatusIcon _SpoofPrimaryStatusIcon{"spoofprimaryicon", "Spoof Primary Status Icon", "Spoofs the primary status icon that appears above your head"};
	static SpoofSecondaryStatusIcon _SpoofSecondaryStatusIcon{"spoofsecondaryicon", "Spoof Secondary Status Icon", "Spoofs the secondary status icon that appears above your head"};
}