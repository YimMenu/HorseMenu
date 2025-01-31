#pragma once
#include "util/Joaat.hpp"
#include "CategoryUtils.hpp"

namespace YimMenu
{
	struct ObjectModelDefinition : public ModelDefinition
	{
	};

	inline std::vector<std::pair<const char*, std::vector<ObjectModelDefinition>>> g_ObjectCategories = 
	{
		{"Fences", {
			{"p_chickenfence01x"_J, "Chicken Fence"},
			{"p_chickenfence03x"_J, "Chicken Fence 2"},
			{"p_chickenfencepost"_J, "Chicken Fence Post"},
			{"p_app_stablefence01ax"_J, "Stable Fence"},
			{"p_app_stablefence01x"_J, "Stable Fence 2"},
			{"p_app_stablefence04x"_J, "Stable Fence 3"},
			{"p_app_stablefence06x"_J, "Stable Fence Post"},
		}},
		{"Signs", {
			{"p_sign01x"_J, "Posters 1"},
			{"p_sign03x"_J, "Posters 2"},
			{"p_sign05x"_J, "Posters 3"},
			{"p_sign_church01x"_J, "Church Sign"},
			{"p_signdoctorrho_a"_J, "Doctor Sign 1"},
			{"p_signdoctorrho_b"_J, "Doctor Sign 2"},
			{"p_sign_miners01x"_J, "Union Sign 1"},
			{"p_sign_miners02x"_J, "Union Sign 2"},
			{"p_sign_miners03x"_J, "Union Sign 3"},
			{"p_sign_miners04x"_J, "Union Sign 4"},
			{"p_signmorgrho_a"_J, "Morgue Sign"},
			{"p_sign_roomsval_a"_J, "Hotel Sign 1"},
			{"p_valhotelsign_01x"_J, "Hotel Sign 2"},
			{"p_sign_suffragette01x"_J, "Suffragette Sign 1"},
			{"p_sign_suffragette02x"_J, "Suffragette Sign 2"},
			{"p_sign_suffragette03x"_J, "Suffragette Sign 3"},
			{"p_sign_suffragette04x"_J, "Suffragette Sign 4"},
			{"p_sign_suffragette05x"_J, "Suffragette Sign 5"},
			{"p_sign_protestwag01x"_J, "Suffragette Sign 6"},
			{"p_sandwichboardwomen01x"_J, "Suffragette Sign 7"},
			{"p_valsmithsign01x"_J, "Blacksmith Sign"},
			{"p_sandwichboard01x"_J, "Market Sign"},
			{"p_sandwichboard02x"_J, "Now Open Sign"},
			{"p_sandwichboard03x"_J, "Hats Sign"}, // idk what to call this one
			{"p_sandwichboard05x"_J, "Lager Sign"},
			{"p_sandwichboard07x"_J, "Menu Sign"},
			{"p_sandwichboard08x"_J, "Eugenics Sign"},
			{"p_sandwichboard09x"_J, "Cult Sign"},
			{"p_helpwantedsign01x"_J, "Help Wanted"},
			{"p_sca_lemoynebordersign"_J, "Lemoyne Sign"},
			{"p_sca_westelizabeth_sign"_J, "West Elizabeth Sign"},
			{"rho_tsign_01"_J, "Rhodes Sign"},
		}},
		{"Racetracks", { // TODO: no work?
			{"mp001_p_mp_track_joint01"_J, "Joint 1"},
			{"mp001_p_mp_track_joint02"_J, "Joint 2"},
			{"mp001_p_mp_track_joint03"_J, "Joint 3"},
			{"mp001_p_mp_track_joint04"_J, "Joint 4"},
			{"mp001_p_mp_track_leftturn01"_J, "Left Turn 1"},
			{"mp001_p_mp_track_leftturn02"_J, "Left Turn 2"},
			{"mp001_p_mp_track_leftturn03"_J, "Left Turn 3"},
			{"mp001_p_mp_track_leftturn04"_J, "Left Turn 4"},
			{"mp001_p_mp_track_narrow01"_J, "Narrow 1"},
			{"mp001_p_mp_track_narrow02"_J, "Narrow 2"},
			{"mp001_p_mp_track_narrow03"_J, "Narrow 3"},
			{"mp001_p_mp_track_narrow04"_J, "Narrow 4"},
			{"mp001_p_mp_track_narrowjoint01"_J, "Narrow Joint 1"},
			{"mp001_p_mp_track_narrowjoint02"_J, "Narrow Joint 2"},
			{"mp001_p_mp_track_narrowjoint03"_J, "Narrow Joint 3"},
			{"mp001_p_mp_track_narrowjoint04"_J, "Narrow Joint 4"},
			{"mp001_p_mp_track_rightturn01"_J, "Right Turn 1"},
			{"mp001_p_mp_track_rightturn02"_J, "Right Turn 2"},
			{"mp001_p_mp_track_rightturn03"_J, "Right Turn 3"},
			{"mp001_p_mp_track_rightturn04"_J, "Right Turn 4"},
			{"mp001_p_mp_track_shaped01"_J, "Shaped 1"},
			{"mp001_p_mp_track_shaped02"_J, "Shaped 2"},
			{"mp001_p_mp_track_shaped03"_J, "Shaped 3"},
			{"mp001_p_mp_track_shaped04"_J, "Shaped 4"},
			{"mp001_p_mp_track_straight01"_J, "Straight 1"},
			{"mp001_p_mp_track_straight02"_J, "Straight 2"},
			{"mp001_p_mp_track_straight03"_J, "Straight 3"},
			{"mp001_p_mp_track_straight04"_J, "Straight 4"},
		}},
	};
}