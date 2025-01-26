#pragma once
#include "util/Joaat.hpp"
#include "CategoryUtils.hpp"

namespace YimMenu
{
	struct PedModelDefinition : public ModelDefinition
	{
		int m_NumVariations;
	};

	/*
	* The following peds are blacklisted in MP, do not add them
	* a_m_y_nbxstreetkids_slums_01
	* re_rally_males_01
	* re_rallydispute_males_01
	* re_rallysetup_males_01
	* a_m_y_asbminer_01
	* a_m_y_asbminer_02
	* a_m_y_asbminer_03
	* a_m_y_asbminer_04
	* a_m_y_nbxstreetkids_01
	* a_m_y_sdstreetkids_slums_02
	* a_m_y_unicorpse_01
	* s_m_y_newspaperboy_01
	* s_m_y_racrailworker_01
	*/

	inline std::vector<std::pair<const char*, std::vector<PedModelDefinition>>> g_PedCategories = 
	{
		{"Story", {
			{"player_zero"_J, "Arthur", 74},
			{"player_three"_J, "John", 33},
			{"cs_abigailroberts"_J, "Abigail", 15},
			{"cs_dutch"_J, "Dutch", 31},
			{"cs_hoseamatthews"_J, "Hosea", 13},
			{"cs_javierescuella"_J, "Javier", 32},
			{"cs_micahbell"_J, "Micah", 32},
			{"cs_leostrauss"_J, "Strauss", 11},
			{"cs_jackmarston_teen"_J, "Jack", 10},
			{"cs_mrsadler"_J, "Sadie", 22},
			{"cs_charlessmith"_J, "Charles", 34},
			{"cs_uncle"_J, "Uncle", 12},
			{"cs_tilly"_J, "Tilly", 12},
			{"cs_revswanson"_J, "Rev. Swanson", 4},
			{"cs_mollyoshea"_J, "Molly", 8},
			{"cs_mrsgeddes"_J, "Mrs. Geddes", 1},
			{"cs_leviticuscornwall"_J, "Cornwall", 1},
			{"CS_miltonandrews"_J, "Mr. Milton", 2},
		}},
		{"Valentine", {
			{"a_f_m_valtownfolk_01"_J, "Resident 1", 20},
			{"a_m_m_valtownfolk_01"_J, "Resident 2", 36},
			{"a_m_m_valtownfolk_02"_J, "Resident 3", 44},
			{"cs_valsheriff"_J, "Sheriff", 2},
			{"s_m_m_valdeputy_01"_J, "Deputy", 20},
			{"u_m_m_valbartender_01"_J, "Bartender", 9},
			{"u_m_m_valdoctor_01"_J, "Doctor", 9},
			{"u_m_m_valgunsmith_01"_J, "Gunsmith", 9},
			{"u_m_m_valhotelowner_01"_J, "Hotel Owner", 9},
			{"a_m_m_valfarmer_01"_J, "Farmer", 29},
			{"a_m_m_vallaborer_01"_J, "Laborer", 58},
			{"s_m_m_valbankguards_01"_J, "Guard", 10},
			{"a_m_m_valcriminals_01"_J, "Criminal", 10},
			{"s_m_m_valdealer_01"_J, "Dealer", 8},
			{"cs_valprostitute_02"_J, "Prostitute 1", 1}, // anastasia
			{"cs_valprostitute_01"_J, "Prostitute 2", 1}, // the killer prostitute
			{"a_f_m_valprostitute_01"_J, "Prostitute 3", 23},
		}},
		{"Rhodes", {
			{"a_f_m_rhdtownfolk_01"_J, "Resident 1", 23},
			{"a_f_m_rhdtownfolk_02"_J, "Resident 2", 22},
			{"a_f_m_rhdupperclass_01"_J, "Resident 3", 50},
			{"a_m_m_rhdtownfolk_01"_J, "Resident 4", 42},
			{"a_m_m_rhdtownfolk_02"_J, "Resident 5", 35},
			{"a_m_m_rhdupperclass_01"_J, "Resident 6", 63},
			{"u_m_m_rhdsheriff_01"_J, "Sheriff", 5},
			{"a_m_m_rhddeputyresident_01"_J, "Deputy", 23},
			{"u_m_m_rhdbartender_01"_J, "Bartender", 7},
			{"u_m_m_rhddoctor_01"_J, "Doctor", 1},
			{"u_m_m_rhdgunsmith_01"_J, "Gunsmith", 9},
			{"u_m_m_rhdpreacher_01"_J, "Preacher", 1},
			{"u_m_m_rhdundertaker_01"_J, "Undertaker", 1},
			{"a_m_m_rhdforeman_01"_J, "Foreman", 30},
			{"s_m_m_rhdcowpoke_01"_J, "Cowpoke", 20},
			{"s_m_m_rhddealer_01"_J, "Dealer", 8},
			{"a_f_m_rhdprostitute_01"_J, "Prostitute", 35},
		}},
		{"Annesburg", {
			{"a_f_m_asbtownfolk_01"_J, "Resident 1", 35},
			{"a_m_m_asbtownfolk_01"_J, "Resident 2", 86},
			{"u_m_o_asbsheriff_01"_J, "Sheriff", 5},
			{"cs_asbdeputy_01"_J, "Deputy", 1},
			{"u_m_m_asbgunsmith_01"_J, "Gunsmith", 9},
			{"a_m_m_asbminer_01"_J, "Miner 1", 61},
			{"a_m_m_asbminer_02"_J, "Miner 2", 42},
			{"a_m_y_asbminer_01"_J, "Miner 3", 81},
			{"a_m_y_asbminer_02"_J, "Miner 4", 69}, // there are more miners
			{"a_m_m_asbtownfolk_01_laborer"_J, "Laborer", 70},
			{"s_m_m_asbdealer_01"_J, "Dealer", 10},
			{"u_m_m_asbprisoner_01"_J, "Prisoner", 2},
			{"cs_meredith"_J, "Meredith", 1},
			{"cs_meredithsmother"_J, "Meredith's Mother", 1},
		}},
		{"Wapiti", {
			{"cs_eagleflies"_J, "Eagle Flies", 10},
			{"cs_rainsfall"_J, "Rains Fall", 5},
			{"a_f_m_waptownfolk_01"_J, "Resident 1", 25},
			{"a_f_o_waptownfolk_01"_J, "Resident 2", 21},
			{"a_m_m_wapwarriors_01"_J, "Resident 3", 69}, // all the guys are warriors apparently
			{"a_m_o_waptownfolk_01"_J, "Resident 4", 26},
		}},
		{"Braithwaites", {
			{"cs_catherinebraithwaite"_J, "Catherine", 2},
			{"u_f_y_braithwaitessecret_01"_J, "Gertrude", 2}, // variation 2 is a literal skeleton lmao
			{"cs_bartholomewbraithwaite"_J, "Bartholomew", 2},
			{"cs_geraldbraithwaite"_J, "Gerald", 2},
			{"cs_garethbraithwaite"_J, "Gareth", 1},
			{"cs_penelopebraithwaite"_J, "Penelope", 2},
			{"cs_braithwaitebutler"_J, "Butler", 1},
			{"cs_braithwaitemaid"_J, "Maid", 1},
			{"cs_braithwaiteservant"_J, "Servant", 1},
			{"g_m_m_unibraithwaites_01"_J, "Goon", 50},
		}},
		{"Saint Denis", { // nbx = New Bordeaux, the original name for Saint Denis that had to be changed because Mafia 3 had a city with the same name. The prefix sd is also used for stuff added after the name change
						  // TODO: there is so much more to add here
			{"cs_bronte"_J, "Angelo Bronte", 4},
			{"cs_guidomartelli"_J, "Martelli", 3},
			{"cs_henrilemiux"_J, "Mayor", 2},
			{"cs_lillianpowell"_J, "Miss Powell", 3},
			{"cs_hobartcrawley"_J, "Mr. Crawley", 2},
			{"cs_brendacrawley"_J, "Mrs. Crawley", 2},
			{"a_f_m_nbxupperclass_01"_J, "Resident 1", 45},
			{"a_f_m_nbxslums_01"_J, "Resident 2", 42},
			{"a_m_m_nbxupperclass_01"_J, "Resident 3", 50},
			{"a_m_m_nbxslums_01"_J, "Resident 4", 85},
			{"a_f_m_sdchinatown_01"_J, "Resident 5", 20},
			{"a_m_m_lowersdtownfolk_01"_J, "Resident 6", 91},
			{"a_m_m_lowersdtownfolk_02"_J, "Resident 7", 91}, // there are more residents but I think having 500+ resident variations is more than enough
			{"a_m_m_nbxlaborers_01"_J, "Laborer", 70},
			{"a_m_m_nbxdockworkers_01"_J, "Dock-worker", 70},
			{"u_m_m_nbxbartender_01"_J, "Bartender 1", 9},
			{"u_m_m_nbxbartender_02"_J, "Bartender 2", 9},
			{"u_m_m_nbxgeneralstoreowner_01"_J, "Store Owner", 9},
			{"u_m_m_nbxpriest_01"_J, "Priest", 1},
			{"u_m_m_nbxgunsmith_01"_J, "Gunsmith", 9},
			{"u_m_m_nbxmusician_01"_J, "Musician", 2},
			{"u_m_m_nbxgraverobber_01"_J, "Grave Robber", 2},
			{"u_m_m_nbxshadydealer_01"_J, "Dealer", 9},
			{"a_f_m_nbxwhore_01"_J, "Prostitute 1", 25},
			{"a_f_m_sdfancywhore_01"_J, "Prostitute 2", 20},
		}},
		{"Van Horn", {
			{"a_f_m_vhttownfolk_01"_J, "Resident 1", 25},
			{"a_m_m_vhttownfolk_01"_J, "Resident 2", 86},
			{"u_f_m_vhtbartender_01"_J, "Bartender", 7},
			{"u_m_m_vhtstationclerk_01"_J, "Station Clerk", 9},
			{"cs_vht_bathgirl"_J, "Bathing Lady", 1},
			{"a_m_m_vhtthug_01"_J, "Thug", 40},
			{"s_m_m_vhtdealer_01"_J, "Dealer", 8},
			{"u_m_o_vhtexoticshopkeeper_01"_J, "Fence", 9},
			{"a_f_m_vhtprostitute_01"_J, "Prostitute", 11},
		}},
		{"Theatre Raleur", { // RDR can't render the diacritics
			{"cs_cabaretmc"_J, "Aldridge", 1},
			{"cs_cancan_01"_J, "Can-Can Dancer 1", 1},
			{"cs_cancan_02"_J, "Can-Can Dancer 2", 1},
			{"cs_cancan_03"_J, "Can-Can Dancer 3", 1},
			{"cs_cancan_04"_J, "Can-Can Dancer 4", 1},
			{"cs_cancanman_01"_J, "Can-Can Man", 1},
			{"cs_sworddancer"_J, "Snake Dancer", 1}, // yes, this is not a typo
			{"cs_fire_breather"_J, "Fire Breather", 1},
			{"cs_bandsinger"_J, "Robin", 1},
			{"cs_bandbassist"_J, "Band Bassist", 1},
			{"cs_banddrummer"_J, "Band Drummer", 1},
			{"cs_bandpianist"_J, "Band Pianist", 1},
			{"cs_escapeartist"_J, "Escape Artist", 5},
			{"cs_escapeartistassistant"_J, "Escape Assistant", 1},
			{"cs_missmarjorie"_J, "Miss Marjorie", 3},
			{"cs_oddfellowspinhead"_J, "Bertram", 2},
			{"cs_magnifico"_J, "Magnifico", 2},
	        {"cs_acrobat"_J, "Acrobat", 1},  // cut content
		}},
	    {"Random Encounters", {
			{"cs_gavin"_J, "Nigel", 2},
			{"cs_norrisforsythe"_J, "Norris Forsythe", 2},
			{"cs_reverendfortheringham"_J, "Reverend Fortheringam", 2},
			{"cs_cassidy"_J, "Cassidy", 3},
			{"cs_mickey"_J, "Mickey", 2},
			{"cs_agnesdowd"_J, "Agnes Dowd", 4},
			{"cs_andershelgerson"_J, "Mr. Helgerson", 4},
			{"cs_towncrier"_J, "Town Crier", 2},
			{"cs_chelonianmaster"_J, "Chelonian Master", 5},
			{"u_m_o_cmrcivilwarcommando_01"_J, "War Veteran", 2},
			{"cs_doroetheawicklow"_J, "Doroethea Wicklow", 3},
			{"cs_grizzledjon"_J, "Grizzled Jon", 3},
			{"cs_joebutler"_J, "Joe Butler", 2},
			{"cs_johnthebaptisingmadman"_J, "Madman", 2}, // not sure who this is yet, might be cut content
			{"cs_drmalcolmmacintosh"_J, "Dr. Malcolm", 1},
			{"cs_nicholastimmins"_J, "Nicholas Timmins", 2},
			{"cs_cavehermit"_J, "Philosopher", 1},
			{"cs_poorjoe"_J, "Poor Joe", 1},
			{"cs_soothsayer"_J, "Soothsayer", 2},
			{"cs_sunworshipper"_J, "Bob Brownlee", 1},
			{"cs_swampweirdosonny"_J, "Sonny", 1},
			{"cs_timothydonahue"_J, "Timothy Donahue", 2},
			{"cs_tinyhermit"_J, "Hermit", 2},
	        {"cs_vampire"_J, "Vampire", 1},
	        {"re_snakebite_males_01"_J, "Norbert", 2},
		}},
	    {"Misc", {
			{"cs_princessisabeau"_J, "Princess Isabeau", 1}, // cut content
			{"cs_balloonoperator"_J, "Balloon Operator", 4}, 
			{"cs_mysteriousstranger"_J, "Strange Man", 1},
			{"u_f_m_rhdnudewoman_01"_J, "Nude Woman", 1},
			{"cs_featherstonchambers"_J, "Featherston Chambers", 1}, // cut content
			{"cs_drhiggins"_J, "Dr. Higgins", 1}, // cut content
		}},
	};
}