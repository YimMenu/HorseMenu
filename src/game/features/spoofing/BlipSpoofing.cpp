#include "core/commands/LoopedCommand.hpp"
#include "core/commands/ListCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "util/Joaat.hpp"

namespace YimMenu::Features
{
	static std::vector<std::pair<int, const char*>> g_BlipSprites = {
	    {-861219276, "Ambient Bounty Hunter"},
	    {-535302224, "Ambient Bounty Hunter Higher"},
	    {28148096, "Ambient Bounty Hunter Lower"},
	    {1481032477, "Ambient Bounty Target"},
	    {1321928545, "Ambient Chore"},
	    {1012165077, "Ambient Coach"},
	    {-185399168, "Ambient Companion"},
	    {54149631, "Ambient Companion Higher"},
	    {-1971029474, "Ambient Companion Lower"},
	    {-1116208957, "Ambient Corpse"},
	    {350569997, "Ambient Death"},
	    {-2018361632, "Ambient Eyewitness"},
	    {-1489164512, "Ambient Gang Leader"},
	    {423351566, "Ambient Herd"},
	    {-1979146842, "Ambient Herd Straggler"},
	    {-920572370, "Ambient Higher"},
	    {1220803671, "Ambient Hitching Post"},
	    {-643888085, "Ambient Horse"},
	    {-1596758107, "Ambient Law"},
	    {1838354131, "Ambient Loan Shark"},
	    {-1843639063, "Ambient Lower"},
	    {419258445, "Ambient New"},
	    {587827268, "Ambient Newspaper"},
	    {305281166, "Ambient Npc"},
	    {978474677, "Ambient Npc Higher"},
	    {-67528377, "Ambient Npc Lower"},
	    {1453767378, "Ambient Ped Downed"},
	    {-1350763423, "Ambient Ped Medium"},
	    {1386031480, "Ambient Ped Medium Higher"},
	    {1995891146, "Ambient Ped Medium Lower"},
	    {692310, "Ambient Ped Small"},
	    {195811413, "Ambient Ped Small Higher"},
	    {511626456, "Ambient Ped Small Lower"},
	    {249721687, "Ambient Quartermaster"},
	    {2033397166, "Ambient Riverboat"},
	    {675509286, "Ambient Secret"},
	    {-693644997, "Ambient Sheriff"},
	    {503049244, "Ambient Telegraph"},
	    {-417940443, "Ambient Theatre"},
	    {-1954662204, "Ambient Tithing"},
	    {-1580514024, "Ambient Tracking"},
	    {-250506368, "Ambient Train"},
	    {874255393, "Ambient Wagon"},
	    {784218150, "Ambient Warp"},
	    {573732443, "Ammo Arrow"},
	    {1445158214, "Ammo Bullets"},
	    {-1646261997, "Animal"},
	    {1340161527, "Animal Dead"},
	    {1996684768, "Animal Quality 01"},
	    {-171082889, "Animal Quality 02"},
	    {-480291173, "Animal Quality 03"},
	    {218395012, "Animal Skin"},
	    {1173759417, "App Connected"},
	    {-774688241, "Attention"},
	    {1869246576, "Bank Debt"},
	    {-304640465, "Bath House"},
	    {327180499, "Camp"},
	    {-1043855483, "Camp Request"},
	    {-910004446, "Camp Tent"},
	    {1754365229, "Campfire"},
	    {773587962, "Campfire Full"},
	    {62421675, "Canoe"},
	    {1420154945, "Cash Arthur"},
	    {688589278, "Cash Bag"},
	    {-1138864184, "Chest"},
	    {-758439257, "Code Center"},
	    {648067515, "Code Center On Horse"},
	    {960467426, "Code Waypoint"},
	    {1754506823, "Deadeye Cross"},
	    {456887900, "Destroy"},
	    {51988200, "Direction Pointer"},
	    {-1236018085, "Donate Food"},
	    {1904459580, "Event Appleseed"},
	    {-1989725258, "Event Castor"},
	    {-487631996, "Event Railroad Camp"},
	    {-1944395098, "Event Riggs Camp"},
	    {-1179229323, "Fence Building"},
	    {-1383036426, "For Sale"},
	    {571063529, "Gang Savings"},
	    {1350383321, "Gang Savings Special"},
	    {935247438, "Grub"},
	    {990667866, "Hat"},
	    {600220762, "Horse Higher"},
	    {2131881492, "Horse Lower"},
	    {-1715189579, "Horse Owned"},
	    {1210165179, "Horse Owned Active"},
	    {-217389439, "Horse Owned Bonding 0"},
	    {13992470, "Horse Owned Bonding 1"},
	    {396341162, "Horse Owned Bonding 2"},
	    {623069873, "Horse Owned Bonding 3"},
	    {-637422489, "Horse Owned Bonding 4"},
	    {-44909892, "Horse Owned Hitched"},
	    {-641397381, "Horse Temp"},
	    {937553910, "Horse Temp Bonding 0"},
	    {489732756, "Horse Temp Bonding 1"},
	    {195204984, "Horse Temp Bonding 2"},
	    {-103418913, "Horse Temp Bonding 3"},
	    {-815685893, "Horse Temp Bonding 4"},
	    {444737100, "Horse Temp Hitched"},
	    {1887082874, "Horseshoe 0"},
	    {2100933368, "Horseshoe 1"},
	    {1166328735, "Horseshoe 2"},
	    {1463641872, "Horseshoe 3"},
	    {687278724, "Horseshoe 4"},
	    {-211556852, "Hotel Bed"},
	    {-986795390, "Job"},
	    {-902701436, "Location Higher"},
	    {-432067112, "Location Lower"},
	    {1255312268, "Locked"},
	    {595820042, "Mg Blackjack"},
	    {-1650465405, "Mg Dominoes"},
	    {-1581061148, "Mg Dominoes All3s"},
	    {-48718882, "Mg Dominoes All5s"},
	    {-379108622, "Mg Dominoes Draw"},
	    {1242464081, "Mg Drinking"},
	    {-1575595762, "Mg Fishing"},
	    {1974815632, "Mg Five Finger Fillet"},
	    {1015604260, "Mg Five Finger Fillet Burnout"},
	    {126262516, "Mg Five Finger Fillet Guts"},
	    {1243830185, "Mg Poker"},
	    {-1477394468, "Mission Area Beau"},
	    {455154152, "Mission Area Bill"},
	    {2125146709, "Mission Area Bounty"},
	    {-702538745, "Mission Area Bronte"},
	    {1403865185, "Mission Area David Geddes"},
	    {1729623738, "Mission Area Dutch"},
	    {508736310, "Mission Area Eagle Flies"},
	    {-486409706, "Mission Area Edith"},
	    {1876890949, "Mission Area Grays"},
	    {-1849394918, "Mission Area Gunslinger 1"},
	    {1665113105, "Mission Area Gunslinger 2"},
	    {1048219592, "Mission Area Henri"},
	    {783937097, "Mission Area Hosea"},
	    {495717394, "Mission Area Javier"},
	    {231806605, "Mission Area John"},
	    {1003036114, "Mission Area Kitty"},
	    {-686621143, "Mission Area Leon"},
	    {1084717321, "Mission Area Lightning"},
	    {-1034306897, "Mission Area Loanshark"},
	    {-925245417, "Mission Area Mary"},
	    {-977737823, "Mission Area Micah"},
	    {1255014523, "Mission Area Rains"},
	    {-1998899839, "Mission Area Rc"},
	    {-164151171, "Mission Area Reverend"},
	    {1631595563, "Mission Area Sadie"},
	    {-721238161, "Mission Area Strauss"},
	    {-1245830589, "Mission Area Trelawney"},
	    {-125278436, "Mission Bg"},
	    {944812202, "Mission Bill"},
	    {-907204276, "Mission Bounty"},
	    {-1125110489, "Mission Camp"},
	    {-106554210, "Mission Dutch"},
	    {1605798866, "Mission Higher"},
	    {-1724301546, "Mission Hosea"},
	    {-887880659, "Mission John"},
	    {-839061276, "Mission Lower"},
	    {1267381595, "Mission Micah"},
	    {1109348405, "Mp Pickup"},
	    {2031478856, "Npc Search"},
	    {-570710357, "Objective"},
	    {1192138201, "Objective Minor"},
	    {480724882, "Overlay 1"},
	    {-300946848, "Overlay 2"},
	    {7900981, "Overlay 3"},
	    {1675187701, "Overlay 4"},
	    {1846307419, "Overlay 5"},
	    {68100707, "Overlay Bill"},
	    {-674292488, "Overlay Charles"},
	    {-985772686, "Overlay Hosea"},
	    {495452413, "Overlay Javier"},
	    {-1764128257, "Overlay John"},
	    {-1283959649, "Overlay Karen"},
	    {577712810, "Overlay Kieran"},
	    {-1491306790, "Overlay Lenny"},
	    {-1713383509, "Overlay Loanshark"},
	    {809358939, "Overlay Micah"},
	    {1097265030, "Overlay Party"},
	    {1083384676, "Overlay Pearson"},
	    {-184692826, "Overlay Ring"},
	    {-271586249, "Overlay Saddle"},
	    {-656301087, "Overlay Sean"},
	    {1737923688, "Overlay Strauss"},
	    {2009192597, "Overlay Tilly"},
	    {-1706952903, "Overlay Uncle"},
	    {-810005617, "Overlay White 1"},
	    {-512626942, "Overlay White 2"},
	    {-1268149006, "Overlay White 3"},
	    {-969951106, "Overlay White 4"},
	    {1222000069, "Overlay White 5"},
	    {1364029453, "Photo Studio"},
	    {-675651933, "Plant"},
	    {-523921054, "Player"},
	    {-361388975, "Player Coach"},
	    {-2039778370, "Poi"},
	    {1861010125, "Post Office"},
	    {1475382911, "Post Office Rec"},
	    {-2128054417, "Proc Bank"},
	    {-1636832113, "Proc Bounty Poster"},
	    {1586273744, "Proc Home"},
	    {-1498696713, "Proc Home Locked"},
	    {-997121570, "Proc Loanshark"},
	    {421058601, "Proc Track"},
	    {-1192977721, "Radar Edge Pointer"},
	    {150441873, "Radius Search"},
	    {-1822497728, "Rc"},
	    {-1259688762, "Rc Albert"},
	    {2107943776, "Rc Algernon Wasp"},
	    {-434412386, "Rc Art"},
	    {-1744398657, "Rc Calloway"},
	    {-622951465, "Rc Chain Gang"},
	    {-1676833170, "Rc Charlotte Balfour"},
	    {877823184, "Rc Crackpot"},
	    {1162303770, "Rc Deborah"},
	    {858349040, "Rc Gunslinger 1"},
	    {479604938, "Rc Gunslinger 2"},
	    {240424007, "Rc Gunslinger 3"},
	    {1813565390, "Rc Gunslinger 5"},
	    {-340501579, "Rc Henri"},
	    {1986498931, "Rc Hobbs"},
	    {-273196610, "Rc Jeremy Gill"},
	    {1970061205, "Rc Kitty"},
	    {-1962480616, "Rc Lightning"},
	    {415367144, "Rc Obediah Hinton"},
	    {825960713, "Rc Odd Fellows"},
	    {-1280269885, "Rc Oh Brother"},
	    {1429600911, "Rc Old Flame"},
	    {194953189, "Rc Slave Catcher"},
	    {1770336866, "Rc War Veteran"},
	    {-1606321000, "Region Caravan"},
	    {-428972082, "Region Hideout"},
	    {500148876, "Region Hunting"},
	    {623155783, "Robbery Bank"},
	    {-729441538, "Robbery Coach"},
	    {444204045, "Robbery Home"},
	    {-1107942598, "Rpg Overweight"},
	    {1111652008, "Rpg Underweight"},
	    {-1327110633, "Saddle"},
	    {1879260108, "Saloon"},
	    {469700298, "Scm Abe Stablehand"},
	    {2134645637, "Scm Abigail"},
	    {2125693359, "Scm Albert Cakes"},
	    {-68985291, "Scm Andreas"},
	    {-194220735, "Scm Ansel Atherton"},
	    {1301148265, "Scm Beau"},
	    {-1137631263, "Scm Bronte"},
	    {-809133732, "Scm Calderon"},
	    {-1419869332, "Scm Charles"},
	    {-1715293734, "Scm David Geddes"},
	    {332378857, "Scm Dorkins"},
	    {1079956634, "Scm Eagle Flies"},
	    {-661151214, "Scm Edith"},
	    {-1610853131, "Scm Evelyn"},
	    {-781551276, "Scm Frances"},
	    {-982604554, "Scm Grays"},
	    {388668855, "Scm Jack"},
	    {-2071559757, "Scm Javier"},
	    {-420584813, "Scm Kieran"},
	    {818727011, "Scm Lenny"},
	    {-491324266, "Scm Leon"},
	    {-2100584570, "Scm Letter"},
	    {611792857, "Scm Marybeth"},
	    {1306049414, "Scm Molly Oshea"},
	    {-301979999, "Scm Monroe"},
	    {-699499938, "Scm Pearson"},
	    {-510064667, "Scm Penelope"},
	    {-264232183, "Scm Rains"},
	    {-675600022, "Scm Reverend"},
	    {1232829146, "Scm Sadie"},
	    {1598675467, "Scm Sean"},
	    {2145479193, "Scm Strauss"},
	    {1010322007, "Scm Susan"},
	    {-1295983414, "Scm Tom Dickens"},
	    {-1151477989, "Scm Trelawney"},
	    {-338536163, "Scm Uncle"},
	    {-1406874050, "Shop Animal Trapper"},
	    {-2090472724, "Shop Barber"},
	    {-758970771, "Shop Blacksmith"},
	    {-1665418949, "Shop Butcher"},
	    {-1989306548, "Shop Coach Fencing"},
	    {-1739686743, "Shop Doctor"},
	    {-145868367, "Shop Gunsmith"},
	    {1938782895, "Shop Horse"},
	    {-1456209806, "Shop Horse Fencing"},
	    {469827317, "Shop Horse Saddle"},
	    {819673798, "Shop Market Stall"},
	    {531267562, "Shop Shady Store"},
	    {1475879922, "Shop Store"},
	    {-852241114, "Shop Tackle"},
	    {1195729388, "Shop Tailor"},
	    {103490298, "Shop Train"},
	    {1542275196, "Shop Trainer"},
	    {-73168905, "Stable"},
	    {1078668923, "Summer Cow"},
	    {669307703, "Summer Feed"},
	    {-1735903728, "Summer Guard"},
	    {552659337, "Summer Horse"},
	    {1576459965, "Supplies Ammo"},
	    {-1852063472, "Supplies Food"},
	    {-695368421, "Supplies Health"},
	    {1378990590, "Supply Icon Ammo"},
	    {412928073, "Supply Icon Food"},
	    {-924021303, "Supply Icon Health"},
	    {-1505442625, "Swap"},
	    {-1733535731, "Taxidermist"},
	    {-369711600, "Time Of Day"},
	    {-1258576797, "Town"},
	    {549686661, "Weapon"},
	    {-132369645, "Weapon Bow"},
	    {-363516712, "Weapon Cannon"},
	    {1125369187, "Weapon Dynamite"},
	    {2120954438, "Weapon Gatling"},
	    {-1052367340, "Weapon Handgun"},
	    {-995686252, "Weapon Longarm"},
	    {501323084, "Weapon Melee"},
	    {526225529, "Weapon Molotov"},
	    {-1796682476, "Weapon Shotgun"},
	    {-1634577211, "Weapon Sniper"},
	    {1482572802, "Weapon Throwable"},
	    {908365526, "Weapon Throwing Knife"},
	    {1480984695, "Weapon Tomahawk"},
	    {2119944996, "Weapon Torch"},
	};

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

	static ListCommand _BlipSprite{"blipsprite", "Blip Sprite", "The blip sprite", g_BlipSprites, (int)350569997};
	static ListCommand _PrimaryStatusIcon{"primaryicon", "Primary Status Icon", "The primary status icon", g_OverheadSprites, (int)0xA243B5A4};
	static ListCommand _SecondaryStatusIcon{"secondaryicon", "Secondary Status Icon", "The secondary status icon", g_OverheadSprites, (int)0xA243B5A4};

	class SpoofBlip : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;
		static constexpr auto blipSprite = ScriptGlobal(1072759).At(21626).At(257);

		virtual void OnTick() override
		{
			if (blipSprite.CanAccess(true))
			{
				*blipSprite.As<int*>() = _BlipSprite.GetState();
			}
		}
	};

	class SpoofPrimaryStatusIcon : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;
		static constexpr auto primaryStatusIcon = ScriptGlobal(1072759).At(21889).At(581);

		virtual void OnTick() override
		{
			if (primaryStatusIcon.CanAccess(true))
			{
				*primaryStatusIcon.As<int*>() = _PrimaryStatusIcon.GetState();
			}
		}
	};

    class SpoofSecondaryStatusIcon : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;
		static constexpr auto secondaryStatusIcon = ScriptGlobal(1072759).At(21889).At(582);

		virtual void OnTick() override
		{
			if (secondaryStatusIcon.CanAccess(true))
			{
				*secondaryStatusIcon.As<int*>() = _SecondaryStatusIcon.GetState();
			}
		}
	};

	static SpoofBlip _SpoofBlip{"spoofblip", "Spoof Blip", "Spoofs your blip for other players"};
	static SpoofPrimaryStatusIcon _SpoofPrimaryStatusIcon{"spoofprimaryicon", "Spoof Primary Status Icon", "Spoofs the primary status icon that appears above your head"};
	static SpoofSecondaryStatusIcon _SpoofSecondaryStatusIcon{"spoofsecondaryicon", "Spoof Secondary Status Icon", "Spoofs the secondary status icon that appears above your head"};
}