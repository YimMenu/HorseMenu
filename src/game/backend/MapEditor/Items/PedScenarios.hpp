#pragma once
#include "util/Joaat.hpp"
#include "CategoryUtils.hpp"

#include <unordered_set>

namespace YimMenu
{
	struct PedScenarioDefinition : public ModelDefinition
	{
	};

	// TODO: create scenario points and add props
	// some scenarios don't work for all peds due to gender locking etc. (UPDATE: I've hooked the gender conditions and made them return true for editor peds, not sure if they'll network yet)
	inline std::vector<PedScenarioDefinition> g_PedScenarios =
	{
	    {0, "None"},
	    {"WORLD_HUMAN_CLIPBOARD"_J, "Clipboard"},
	    {"WORLD_HUMAN_BROOM"_J, "Sweep"},
	    {"WORLD_HUMAN_CLEAN_TABLE"_J, "Clean Table"},
	    {"WORLD_HUMAN_CLEAN_WINDOW"_J, "Clean Window"},
	    {"PROP_HUMAN_PUMP_WATER"_J, "Pump Water"},
	    {"WORLD_HUMAN_DRINKING"_J, "Drink"},
	    {"WORLD_HUMAN_FAN"_J, "Fan"},
	    {"WORLD_HUMAN_BADASS"_J, "Badass"},
	    {"WORLD_HUMAN_GUARD_MILITARY"_J, "Guard"},
	    {"WORLD_HUMAN_GUARD_LEAN_WALL"_J, "Guard (Lean)"},
	    {"WORLD_HUMAN_INSPECT"_J, "Inspect"},
	    {"WORLD_HUMAN_CROUCH_INSPECT"_J, "Inspect (Crouched)"},
	    {"WORLD_HUMAN_KNOCK_DOOR"_J, "Knock Door"},
	    {"WORLD_HUMAN_PICKAXE_WALL"_J, "Use Pickaxe"},
	    {"WORLD_HUMAN_POCKET_MIRROR"_J, "Use Pocket Mirror"},
	    {"WORLD_HUMAN_PITCH_HAY_SCOOP"_J, "Scoop Hay"},
	    {"WORLD_HUMAN_SHOPKEEPER"_J, "Shopkeep"},
	    {"WORLD_HUMAN_BARTENDER"_J, "Bartend"},
	    {"WORLD_HUMAN_SLEDGEHAMMER"_J, "Use Sledgehammer"},
	    {"SC_WORLD_HUMAN_PREACHER"_J, "Preach"},
	    {"SC_PROP_HUMAN_TORCH"_J, "Hold Torch"}, // torch not included (TODO!)
	    {"WORLD_HUMAN_WRITE_NOTEBOOK"_J, "Write Journal"},
	    {"WORLD_HUMAN_LEAN_WALL_LEFT"_J, "Lean Left"},
	    {"WORLD_HUMAN_LEAN_WALL_RIGHT"_J, "Lean Right"},
	    {"WORLD_HUMAN_SMOKE"_J, "Smoke"}, // could be a cigarette or a cigar
	    {"WORLD_HUMAN_STAND_FISHING"_J, "Fish"},
	    {"WORLD_HUMAN_FEED_CHICKEN"_J, "Feed Chicken"},
	    {"WORLD_HUMAN_FEED_PIGS"_J, "Feed Pigs"},
	    {"WORLD_HUMAN_TRUMPET"_J, "Play Trumpet"}, // only a single ped can play the trumpet at any given time
	    {"PROP_HUMAN_PIANO"_J, "Play Piano"},
	    {"WORLD_HUMAN_VOMIT"_J, "Vomit"},
	    {"SC_AMB_VIG_VOMIT_WALL"_J, "Vomit (Lean)"},
	    {"WORLD_HUMAN_GRAVE_MOURNING_KNEEL"_J, "Mourn"},
	    {"WORLD_HUMAN_SIT_FALL_ASLEEP"_J, "Doze Off"},
	    {"WORLD_HUMAN_RE_LOST_DRUNK_SLEEP"_J, "Sleep"},
	    {"WORLD_HUMAN_SIT_GROUND"_J, "Sit Down"},
	    {"WORLD_HUMAN_SIT_GROUND_READING_BOOK"_J, "Read Book (Seated)"},
	    {"WORLD_HUMAN_SIT_GROUND_READING_JOURNAL"_J, "Read Journal (Seated)"},
	    {"WORLD_HUMAN_SIT_GROUND_SKETCHING"_J, "Sketch (Seated)"},
	    {"PROP_HUMAN_SEAT_CHAIR_TABLE_FAN_WHORE"_J, "Fan (Seated)"},
	    {"PROP_HUMAN_SEAT_CRATE_CLEAN_BOOTS"_J, "Clean Boots (Seated)"},
	    {"PROP_HUMAN_SEAT_CHAIR_SAD"_J, "Be Sad (Seated)"},
	    {"PROP_HUMAN_SEAT_CHAIR_SMOKING_TRAIN"_J, "Smoke (Seated)"},
	    {"PROP_HUMAN_SEAT_CHAIR_KNITTING"_J, "Knit Cloth (Seated)"},
	    {"PROP_HUMAN_SEAT_CHAIR_SEWING"_J, "Sew (Seated)"},
	};

	inline std::unordered_set<std::uint32_t> g_ScenariosUsingChair = 
	{
		"PROP_HUMAN_PIANO"_J,
	    "PROP_HUMAN_SEAT_CHAIR_TABLE_FAN_WHORE"_J,
	    "PROP_HUMAN_SEAT_CRATE_CLEAN_BOOTS"_J,
	    "PROP_HUMAN_SEAT_CHAIR_SAD"_J,
	    "PROP_HUMAN_SEAT_CHAIR_SMOKING_TRAIN"_J,
	    "PROP_HUMAN_SEAT_CHAIR_KNITTING"_J,
	    "PROP_HUMAN_SEAT_CHAIR_SEWING"_J
	};

	inline bool DoesScenarioUseChair(std::uint32_t value)
	{
		return g_ScenariosUsingChair.contains(value);
	}
}