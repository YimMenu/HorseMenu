#pragma once
#include <string>
#include <unordered_set>


namespace YimMenu::Data
{
	struct ObjModelInfo
	{
		std::string model;
		std::string category; 
	};

	const ObjModelInfo g_ObjModels[]{
        {"p_balconyflagnbx01x", "Flag"},
        {"p_barbpolenbx01x", "Pole"},
        {"p_barrelhoistnbx01x", "Hoist"},
        {"p_beerboardnbx01x", "Board"},
        {"p_bellhangnbx01x", "Bell"},
        {"p_bellwallnbx01x", "Bell"},
        {"p_benchironnbx01x", "Bench"},
        {"p_benchironnbx02x", "Bench"},
        {"p_benchnbx01x", "Bench"},
        {"p_benchnbx02x", "Bench"},
        {"p_benchnbx03x", "Bench"},
        {"p_bollardnbx01x", "Bollard"},
        {"p_bowlplantnbx01x", "Plant"},
        {"p_bowlplantnbx01xb", "Plant"},
        {"p_bowlplantnbx02x", "Plant"},
        {"p_canalpolenbx01a", "Pole"},
        {"p_canalpolenbx01x", "Pole"},
        {"p_canalpolenbx02x", "Pole"},
        {"p_canalpolenbx03a", "Pole"},
        {"p_canalpolenbx03b", "Pole"},
        {"p_canalpolenbx03c", "Pole"},
        {"p_canalpolenbx03d", "Pole"},
        {"p_canalpolenbx03x", "Pole"},
        {"p_candleboxnbx01x", "Candle"},
        {"p_chairironnbx01x", "Chair"},
        {"p_chairnbx02x", "Chair"},
        {"p_chairwicker03x", "Chair"},
        {"p_cherubstatuenbx01x", "Statue"},
        {"p_coffeeboardnbx01x", "Board"},
        {"p_couchwicker01x", "Couch"},
        {"p_ctyhal_left_door01x", "Door"},
        {"p_ctyhal_ryt_door01x", "Door"},
        {"p_debrisboardsstd01x", "Debris"},
        {"p_debrisboardsstd02x", "Debris"},
        {"p_debrisboardsstd03x", "Debris"},
        {"p_debrispilestd01x", "Debris"},
        {"p_debrispilestd02x", "Debris"},
        {"p_debrispilestd03x", "Debris"},
        {"p_debrispilestd04x", "Debris"},
        {"p_debrispilestd05x", "Debris"},
        {"p_debrispilestd06x", "Debris"},
        {"p_debrispilestd07x", "Debris"},
        {"p_debrispilestd08x", "Debris"},
        {"p_displaycasenbx01x", "Display Case"},
        {"p_displaycasenbx02x", "Display Case"},
        {"p_dollynbx01x", "Dolly"},
        {"p_doorbronte01x", "Door"},
        {"p_door_gatenbx01x", "Gate"},
        {"p_door_gatenbx01x_static", "Gate"},
        {"p_door_gatenbx02a", "Gate"},
        {"p_door_gatenbx02a_static", "Gate"},
        {"p_door_gatenbx02b", "Gate"},
        {"p_door_gatenbx03a", "Gate"},
        {"p_door_gatenbx03x", "Gate"},
        {"p_doorsaloonnbx01x", "Door"},
        {"p_door_sd_hotel01x_l", "Door"},
        {"p_door_sd_hotel01x_l_static", "Door"},
        {"p_door_sd_hotel01x_r", "Door"},
        {"p_door_sd_hotel01x_r_static", "Door"},
        {"p_door_traingate_l", "Gate"},
        {"p_door_traingate_r", "Gate"},
        {"p_door_warehougate_l", "Gate"},
        {"p_door_warehougate_l_static", "Gate"},
        {"p_door_warehougate_r", "Gate"},
        {"p_door_warehougate_r_static", "Gate"},
        {"p_door_wrh_02_1_01x", "Door"},
        {"p_door_wrh_02_2_l", "Door"},
        {"p_door_wrh_02_2_r", "Door"},
        {"p_door_wrh_gate_l", "Gate"},
        {"p_door_wrh_gate_r", "Gate"},
        {"p_dragon_chinatown01x", "Decoration"},
        {"p_fountainbronzenbx01x", "Fountain"},
        {"p_fountainnbx01x", "Fountain"},
        {"p_fountainnbx02x", "Fountain"},
        {"p_hairpomadeboardnbx01x", "Board"},
        {"p_hanginglanternnbx01x", "Lantern"},
        {"p_hanginglightnbx01x", "Light"},
        {"p_lamphangnbx01x", "Lamp"},
        {"p_lampstreetnbx02x", "Lamp"},
        {"p_lanternnbx01x", "Lantern"},
        {"p_leveesignnbx01x", "Sign"},
        {"p_lightcourtnbx01x", "Light"},
        {"p_lightcourtnbx02x", "Light"},
        {"p_lightpolenbx01x", "Pole"},
        {"p_lightpolenbx02x", "Pole"},
        {"p_lightpolenbx03x", "Pole"},
        {"p_lightpolenbx04x", "Pole"},
        {"p_lightpostjksqnbx01x", "Lamp"},
        {"p_lightpostnbx01x", "Lamp"},
        {"p_lightwallnbx01x", "Light"},
        {"p_lightwallnbx02x", "Light"},
        {"p_lightwallnbx03x", "Light"},
        {"p_litternbx01x", "Litter"},
        {"p_litternbx02x", "Litter"},
        {"p_litternbx03x", "Litter"},
        {"p_mandolinboardnbx01x", "Board"},
        {"p_menuboardnbx01x", "Board"},
        {"p_nbxcloseddoor", "Door"},
        {"p_nbx_closed_door_02", "Door"},
        {"p_nbx_splitdoor01", "Door"},
        {"p_nbx_splitdoor02", "Door"},
        {"p_nbx_splitdoor02_static", "Door"},
        {"p_nbx_splitdoor03lft", "Door"},
        {"p_nbx_splitdoor03rht", "Door"},
        {"p_newspaperbw01x", "Newspaper"},
        {"p_newspapernbx01x", "Newspaper"},
        {"p_newspapersdx01x", "Newspaper"},
        {"p_newspaperstandbl_01x", "Newspaper Stand"},
        {"p_newspaperstandbl_02x", "Newspaper Stand"},
        {"p_newspaperstandbl_03x", "Newspaper Stand"},
        {"p_newspaperstandbl_04x", "Newspaper Stand"},
        {"p_newspaperstandbl_05x", "Newspaper Stand"},
        {"p_newspaperstandbl_06x", "Newspaper Stand"},
        {"p_newspaperstandbl_07x", "Newspaper Stand"},
        {"p_newspaperstandbl_08x", "Newspaper Stand"},
        {"p_newspaperstandbl_09x", "Newspaper Stand"},
        {"p_newspaperstandbl_10x", "Newspaper Stand"},
        {"p_newspaperstandbl_11x", "Newspaper Stand"},
        {"p_newspaperstandbl_12x", "Newspaper Stand"},
        {"p_newspaperstandbl_13x", "Newspaper Stand"},
        {"p_newspaperstandbl_14x", "Newspaper Stand"},
        {"p_newspaperstandnh_01x", "Newspaper Stand"},
        {"p_newspaperstandnh_02x", "newspaper stand"},
        {"p_newspaperstandnh_03x", "newspaper stand"},
        {"p_newspaperstandnh_04x", "newspaper stand"},
        {"p_newspaperstandnh_05x", "newspaper stand"},
        {"p_newspaperstandnh_06x", "newspaper stand"},
        {"p_newspaperstandnh_07x", "newspaper stand"},
        {"p_newspaperstandnh_08x", "newspaper stand"},
        {"p_newspaperstandnh_09x", "newspaper stand"},
        {"p_newspaperstandnh_10x", "newspaper stand"},
        {"p_newspaperstandnh_11x", "newspaper stand"},
        {"p_newspaperstandnh_12x", "newspaper stand"},
        {"p_newspaperstandnh_13x", "newspaper stand"},
        {"p_newspaperstandnh_14x", "newspaper stand"},
        {"p_newspaperstandsd_01x", "newspaper stand"},
        {"p_newspaperstandsd_02x", "newspaper stand"},
        {"p_newspaperstandsd_03x", "newspaper stand"},
        {"p_newspaperstandsd_04x", "newspaper stand"},
        {"p_newspaperstandsd_05x", "newspaper stand"},
        {"p_newspaperstandsd_06x", "newspaper stand"},
        {"p_newspaperstandsd_07x", "newspaper stand"},
        {"p_newspaperstandsd_08x", "newspaper stand"},
        {"p_newspaperstandsd_09x", "newspaper stand"},
        {"p_newspaperstandsd_10x", "newspaper stand"},
        {"p_newspaperstandsd_11x", "newspaper stand"},
        {"p_newspaperstandsd_12x", "newspaper stand"},
        {"p_newspaperstandsd_13x", "newspaper stand"},
        {"p_newspaperstandsd_14x", "newspaper stand"},
        {"p_newspapervalx01x", "newspaper"},
        {"p_newsstand01x_new", "news stand"},
        {"p_new_stonebench02x", "stone bench"},
        {"p_palletnbx01a", "pallet"},
        {"p_palletnbx01b", "pallet"},
        {"p_pierpolenbx01x", "pallet"},
        {"p_pie_train_stop", "train stop"},
        {"p_planter03a", "planter"},
        {"p_planternbx01x", "lantern"},
        {"p_planternbx02x", "lantern"},
        {"p_planternbx04a", "lantern"},
        {"p_planternbx04b", "lantern"},
        {"p_planternbx04c", "lantern"},
        {"p_plantpothangnbx01x", "hanging plant pot"},
        {"p_plantpothangnbx02x", "hanging plant pot"},
        {"p_plantpotnbx01x", "plant pot"},
        {"p_plantpotnbx02x", "plant pot"},
        {"p_plantpotnbx03x", "plant pot"},
        {"p_plantpotnbx04x", "plant pot"},
        {"p_plantpotnbx05x", "plant pot"},
        {"p_plantpotnbx06x", "plant pot"},
        {"p_plantpotnbx07x", "plant pot"},
        {"p_plantpotnbx08x", "plant pot"},
        {"p_plantpotwallnbx01x", "wall plant pot"},
        {"p_plantpotwallnbx02x", "wall plant pot"},
        {"p_playingcards01x", "playing cards"},
        {"p_postironnbx01x", "post iron"},
        {"p_potceramicnbx01x", "ceramic pot"},
        {"p_potclaynbx01x", "clay pot"},
        {"p_potsbrokenstd02", "broken pots"},
        {"p_potsbrokenstd03", "broken pots"},
        {"p_potterynbx01x", "pottery"},
        {"p_potterynbx02x", "pottery"},
        {"p_railpartsnbx01x", "rail parts"},
        {"p_re_fund_sign01x", "refund sign"},
        {"p_re_fund_sign02x", "refund sign"},
        {"p_sandwichboardlaundry01x", "sandwich board (laundry)"},
        {"p_sandwichboardmrbear01x", "sandwich board (Mr. Bear)"},
        {"p_sandwichboardnbx01ax", "sandwich board"},
        {"p_sandwichboardnbx01x", "sandwich board"},
        {"p_sandwichboardpascal01x", "sandwich board (Pascal)"},
        {"p_sbbeaumontburly01x", "sandwich board (Beaumont)"},
        {"p_sbdirectdamnation01x", "sandwich board (Direct Damnation)"},
        {"p_sbfarmersdaughter01x", "sandwich board (Farmer's Daughter)"},
        {"p_sbghastlyserenade01x", "sandwich board (Ghastly Serenade)"},
        {"p_sbmodernmedicine01x", "sandwich board (Modern Medicine)"},
        {"p_sboardjosiahblackwate01x", "sandwich board (Josiah Blackwater)"},
        {"p_sboardmanflight01x", "sandwich board (Manflight)"},
        {"p_sboardsaviorssavages01x", "sandwich board (Saviors & Savages)"},
        {"p_sboardsweetheart01x", "sandwich board (Sweetheart)"},
        {"p_sdwhbrddbrngsmith01x", "sandwich board (Smith)"},
        {"p_skylightnbx01x", "skylight"},
        {"p_skylightnbx02x", "skylight"},
        {"p_skylightnbx03x", "skylight"},
        {"p_sraleurtheatre01x", "theater"},
        {"p_statueharrisnbx01x", "statue"},
        {"p_statuenbcom06x", "statue"},
        {"p_storageboxnbx01x", "storage box"},
        {"p_storagecartnbx01x", "storage cart"},
        {"p_streetcarpolenbx03x", "streetcar pole"},
        {"p_streetcarpolenbx04x", "streetcar pole"},
        {"p_streetclockhangnbx01x", "street clock (hanging)"},
        {"p_streetclocknbx01x", "street clock"},
        {"p_streetlampnbx01x", "street lamp"},
        {"p_streetlightnbx01x", "street light"},
        {"p_streetlightnbx02x", "street light"},
        {"p_streetlightnbx03x", "street light"},
        {"p_streetlightnbx04x", "street light"},
        {"p_streetlightnbx05x", "street light"},
        {"p_streetlightnbx06x", "street light"},
        {"p_streetlightnbx07x", "street light"},
        {"p_streetlightnbx08x", "street light"},
        {"p_streetlightnbx09x", "street light"},
        {"p_streettrashcannbx01x", "street trash can"},
	    {"s_lootablemiscchest_wagon", "Chest"},
	    {"s_lootablemoneybox_a", "Money Box"},
	    {"mp005_s_posse_foldingchair_01x", "Chair"},
	    {"mp005_s_posse_ammotable01x", "Ammo Table"},
	    {"mp005_s_posse_ammotable02x", "Ammo Table"},
	    {"mp005_s_posse_ammotable03x", "Ammo Table"},
	    {"mp005_s_posse_ammotable04x", "Ammo Table"},
	    {"mp005_s_posse_bnty_decorlrg01x", "Decor Large"},
	    {"mp005_s_posse_bnty_decorlrg02x", "Decor Large"},
	    {"mp005_s_posse_butcher01x", "Butcher"},
	    {"mp005_s_posse_butcher02x", "Butcher"},
	    {"mp005_s_posse_butcher03x", "Butcher"},
	    {"mp005_s_posse_butcher04x", "Butcher"},
	    {"mp005_s_posse_col_cloth01x", "Cloth"},
	    {"mp005_s_posse_col_cloth02x", "Cloth"},
	    {"mp005_s_posse_col_cloth03x", "Cloth"},
	    {"mp005_s_posse_col_decorlrg01x", "Decor Large"},
	    {"mp005_s_posse_col_decorlrg02x", "Decor Large"},
	    {"mp005_s_posse_foodpile01x", "Food Pile"},
	    {"mp005_s_posse_foodpile02x", "Food Pile"},
	    {"mp005_s_posse_foodpile03x", "Food Pile"},
	    {"mp005_s_posse_foodpile04x", "Food Pile"},
	    {"mp005_s_posse_goods01bx", "Goods"},
	    {"mp005_s_posse_goods01x", "Goods"},
	    {"mp005_s_posse_goods02bx", "Goods"},
	    {"mp005_s_posse_goods02x", "Goods"},
	    {"mp005_s_posse_goods03bx", "Goods"},
	    {"mp005_s_posse_goods03x", "Goods"},
	    {"mp005_s_posse_goods04bx", "Goods"},
	    {"mp005_s_posse_goods04x", "Goods"},
	    {"mp005_s_posse_medtable01x", "Medical Table"},
	    {"mp005_s_posse_medtable02x", "Medical Table"},
	    {"mp005_s_posse_medtable03x", "Medical Table"},
	    {"mp005_s_posse_medtable04x", "Medical Table"},
	    {"mp005_s_posse_table_bountyhunter02x", "Table"},
	    {"mp005_s_posse_tent_bountyhunter01x", "Tent"},
	    {"mp005_s_posse_tent_bountyhunter02x", "Tent"},
	    {"mp005_s_posse_tent_bountyhunter04x", "Tent"},
	    {"mp005_s_posse_tent_bountyhunter06x", "Tent"},
	    {"mp005_s_posse_tent_bountyhunter07x", "Tent"},
	    {"mp005_s_posse_tent_collector01x", "Tent"},
	    {"mp005_s_posse_tent_collector02x", "Tent"},
	    {"mp005_s_posse_tent_collector03x", "Tent"},
	    {"mp005_s_posse_tent_collector04x", "Tent"},
	    {"mp005_s_posse_tent_collector05x", "Tent"},
	    {"mp005_s_posse_tent_collector06x", "Tent"},
	    {"mp005_s_posse_tent_collector07x", "Tent"},
	    {"mp005_s_posse_tent_trader01x", "Tent"},
	    {"mp005_s_posse_tent_trader02x", "Tent"},
	    {"mp005_s_posse_tent_trader03x", "Tent"},
	    {"mp005_s_posse_tent_trader04x", "Tent"},
	    {"mp005_s_posse_tent_trader05x", "Tent"},
	    {"mp005_s_posse_tent_trader06x", "Tent"},
	    {"mp005_s_posse_tent_trader07x", "Tent"},
	    {"mp005_s_posse_trad_decorlrg01x", "Decor Large"},
	    {"mp005_s_posse_trad_decorlrg02x", "Decor Large"},
	    {"mp005_s_posse_trader_candle01x", "Candle"},
	    {"mp005_s_posse_trader_fireset01x", "Fire Set"},
	    {"mp005_s_posse_trader_fireset02x", "Fire Set"},
	    {"mp005_s_posse_weaponslocker01x", "Weapons Locker"},
	    {"mp005_s_posse_bottleterrarium01x", "Terrarium"},
	    {"mp005_s_posse_col_bat01x", "Bat"},
	    {"mp005_s_posse_col_book01x", "Book"},
	    {"mp005_s_posse_col_chair01x", "Chair"},
	    {"mp005_s_posse_col_net01x", "Net"},
	    {"mp005_s_posse_col_posters01x", "Posters"},
	    {"mp005_s_posse_col_posters02x", "Posters"},
	    {"mp005_s_posse_col_posters03x", "Posters"},
	    {"mp005_s_posse_col_tel_astro_01x", "Telescope"},
	    {"mp005_s_posse_capotecoat_hang01x", "Coat"},
	    {"mp005_s_posse_capotecoat_sew01x", "Coat"},
	    {"mp005_s_posse_fleshingboard01x", "Fleshing Board"},
	    {"mp005_s_posse_goodsbundle01x", "Goods Bundle"},
	    {"mp005_s_posse_lardbarrels01x", "Lard Barrels"},
	    {"mp005_s_posse_lardbarrels02x", "Lard Barrels"},
	    {"mp005_s_posse_paintedhide01x", "Painted Hide"},
	    {"mp005_s_posse_raccoonpelt01x", "Raccoon Pelt"},
	    {"mp005_s_posse_trad_blanket01x", "Blanket"},
	    {"mp005_s_posse_trad_chair01x", "Chair"},
	    {"mp005_s_posse_turkeyplume01x", "Turkey Plume"},
	    {"s_crossburning01x", "Burning Cross"},
	    {"mp001_s_mp_boxsm01x", "Gold & Cash"}, 
	};
}