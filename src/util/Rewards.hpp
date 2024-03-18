#pragma once
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/rdr/Natives.hpp"

#include <string>
#include <vector>


namespace YimMenu::Rewards
{

	struct RewardInfo
	{
		std::string model;
		std::string description;
	};
	inline const RewardInfo GoldRewards[]{{"mp001_s_mp_boxsm01x", "Reward Box"}, {"s_inv_moneyclip01x", "Money Clip"}, {"p_moneyStack01x", "Money Stack"}, {"s_pu_coinpurse02x", "Coin Purse"}};

	inline const RewardInfo Heirlooms[]{{"MP005_S_HL_BR_BOARBRISTLE", "Boar Bristle Brush"}, {"MP005_S_HL_BR_EBNY", "Ebony Hairbrush"}, {"MP005_S_HL_BR_GOAT", "Goat Hair Brush"}, {"MP005_S_HL_BR_HORSE", "Horse Hair Brush"}, {"MP005_S_HL_BR_NG_RSEWD", "New Guinea Rosewood Brush"}, {"MP005_S_HL_BR_RSEWD", "Rosewood Brush"}, {"MP005_S_HL_CMB_BOXWOOD", "Boxwood Comb"}, {"MP005_S_HL_CMB_CHRYWD", "Cherrywood Comb"}, {"MP005_S_HL_CMB_IVRY", "Ivory Comb"}, {"MP005_S_HL_CMB_TORTSHELL", "Tortoiseshell Comb"}, {"MP005_S_HL_HP_CRVDWD", "Carved Wood Hairpin"}, {"MP005_S_HL_HP_EBNY", "Ebony Hairpin"}, {"MP005_S_HL_HP_IVRY", "Ivory Hairpin"}, {"MP005_S_HL_HP_JDE", "Jade Hairpin"}, {"MP005_S_HL_HP_MTL", "Metal Hairpin"}};

	inline const RewardInfo Coins[]{{"MP005_S_CN_1700_NYT", "1700 New Yorke Token"}, {"MP005_S_CN_1787_1C_APT", "1787 One Cent Token"}, {"MP005_S_CN_1789_PCTM", "1789 Penny"}, {"MP005_S_CN_1792_1866_5CNICK", "1792 Nickel"}, {"MP005_S_CN_1792_1870_QPD", "1792 Quarter"}, {"MP005_S_CN_1792_QLP", "1792 Liberty Quarter"}, {"MP005_S_CN_1794_1795_SD_FH", "1794 Silver Dollar"}, {"MP005_S_CN_1795_1797_5D_SHETR", "1795 Half Eagle"}, {"MP005_S_CN_1796_HALFPEN_CTN", "1796 Halfpenny"}, {"MP005_S_CN_1797_1804_10D_LC", "1797 Gold Eagle"}, {"MP005_S_CN_1798_1804_SD_DB", "1798 Draped Bust Silver Dollar"}, {"MP005_S_CN_1800_1805_S5C_DBHD", "1800 Half Dime"}, {"MP005_S_CN_1800_1888_5D_CB", "1800 Five Dollar Bechtler"}, {"MP005_S_CN_1800_1899_25C_SG", "1800 Gold Quarter"}, {"MP005_S_CN_1800_1899_GD_LO", "1800 Gold Dollar"}};

	inline const RewardInfo AlcBottles[]{{"MP005_S_AWB_C", "Cognac"}, {"MP005_S_AWB_CB", "Absinthe"}, {"MP005_S_AWB_CR", "Carribean Rum"}, {"MP005_S_AWB_IW", "Irish Whisky"}, {"MP005_S_AWB_LDG", "London Dry Gin"}, {"MP005_S_AWB_OTG", "Old Tom Gin"}, {"MP005_S_AWB_PG", "Gran Corazon Madeira"}, {"MP005_S_AWB_SW", "Scotch Whisky"}, {"MP005_S_AWB_TW", "Tennessee Whiskey"}};

	inline const RewardInfo Arrowheads[]{{"MP005_MP_AWHD_AGATE", "Agate Arrowhead"}, {"MP005_MP_AWHD_BONE", "Bone Arrowhead"}, {"MP005_MP_AWHD_CHIPPED", "Chipped Arrowhead"}, {"MP005_MP_AWHD_CRUDE", "Crude Arrowhead"}, {"MP005_MP_AWHD_FELDSPAR", "Feldspar Arrowhead"}, {"MP005_MP_AWHD_GRANITE", "Granite Arrowhead"}, {"MP005_MP_AWHD_OBSIDIAN", "Obsidian Arrowhead"}, {"MP005_MP_AWHD_QUARTZ", "Quartz Arrowhead"}, {"MP005_MP_AWHD_RAW", "Raw Arrowhead"}, {"MP005_MP_AWHD_ROUGH", "Rough Arrowhead"}, {"MP005_MP_AWHD_SLATE", "Slate Arrowhead"}, {"MP005_MP_AWHD_SPLNTR", "Splinter Arrowhead"}};

	inline const RewardInfo Bracelets[]{{"MP005_S_BRCLT_DMD_GLD", "Abello Ruby Bangle Bracelet"}, {"MP005_S_BRCLT_EDW_PRL", "Durant Pearl Bracelet"}, {"MP005_S_BRCLT_GLD", "Elliston Carved Bracelet"}, {"MP005_S_BRCLT_GLD_BNGL", "Ojeda Rose Gold Bracelet"}, {"MP005_S_BRCLT_SAP", "Greco Sapphire Bracelet"}, {"MP005_S_BRCLT_SAP_BNGL", "Helena Sapphire Bracelet"}, {"MP005_S_BRCLT_SLV", "Infanta Turquoise Bracelet"}, {"MP005_S_BRCLT_SLV_BNGL", "Hajnal Garnet Bangle Bracelet"}};

	inline const RewardInfo Earrings[]{{"MP005_S_ERRNG_CIT_DROP", "Ursula Citrine Earrings"}, {"MP005_S_ERRNG_CRL_DNGL", "Emmeline Coral Earrings"}, {"MP005_S_ERRNG_ELK_THT", "Sterling Tooth Earrings"}, {"MP005_S_ERRNG_EMR", "Dutchess Emerald Earrings"}, {"MP005_S_ERRNG_FLRL_DMD", "Orchidee Diamond Earrings"}, {"MP005_S_ERRNG_GLD_PRL", "Josephine Pearl Earrings"}, {"MP005_S_ERRNG_GLD_RDY_DNGL", "Beauchene Ruby Earrings"}, {"MP005_S_ERRNG_GRN_SLV", "Harford Garnet Earrings"}, {"MP005_S_ERRNG_OLD_MINE", "Endicott Diamond Earrings"}, {"MP005_S_ERRNG_QNS_DMD", "Royal Victoria Diamond Earrings"}, {"MP005_S_ERRNG_TRQ_STUD", "Calumet Turquoise Earrings"}};

	inline const RewardInfo Necklaces[]{{"MP005_S_NKLC_BLK_PRL", "Tuamotu Pearl Necklace"}, {"MP005_S_NKLC_GLD_AME", "Braxton Amethyst Necklace"}, {"MP005_S_NKLC_GLD_CROSS", "Ainsworth Cross Necklace"}, {"MP005_S_NKLC_GLD_LAV", "Gosselin White Gold Necklace"}, {"MP005_S_NKLC_MTHR_PRL", "Pelle Pearl Necklace"}, {"MP005_S_NKLC_ORI_PRL", "Rou Pearl Necklace"}, {"MP005_S_NKLC_PLT_TPZ", "Dane Topaz Necklace"}, {"MP005_S_NKLC_PNT_POR", "Blakely Miniature Necklace"}, {"MP005_S_NKLC_SLV_PRL", "Richelieu Amethyst Necklace"}};

	inline const RewardInfo Rings[]{{"MP005_S_RNG_CORAL", "Harland Coral Ring"}, {"MP005_S_RNG_DMND_ONYX", "Aubrey Onyx Ring"}, {"MP005_S_RNG_EMR_GLD", "Bosque Emerald Ring"}, {"MP005_S_RNG_FRN_DMD", "Beaulieux Diamond Ring"}, {"MP005_S_RNG_GLD_DMD", "Yates Diamond Ring"}, {"MP005_S_RNG_GLD_PRL", "Bonnard Pearl Ring"}, {"MP005_S_RNG_MNSTN", "Pilgrim Moonstone Ring"}, {"MP005_S_RNG_PTRN_DMD", "Sackville Diamond Ring"}, {"MP005_S_RNG_TOP_WED", "Banais Topaz Ring"}, {"MP005_S_RNG_TRQ_GLD", "Magnate Turquoise Ring"}, {"MP005_S_RNG_TRQ_MOT", "Thorburn Turquoise Ring"}};

	inline const RewardInfo TarotCards_Cups[]{{"MP005_S_CARDT_2C", "2 of Cups"}, {"MP005_S_CARDT_3C", "3 of Cups"}, {"MP005_S_CARDT_4C", "4 of Cups"}, {"MP005_S_CARDT_5C", "5 of Cups"}, {"MP005_S_CARDT_6C", "6 of Cups"}, {"MP005_S_CARDT_7C", "7 of Cups"}, {"MP005_S_CARDT_8C", "8 of Cups"}, {"MP005_S_CARDT_9C", "9 of Cups"}, {"MP005_S_CARDT_10C", "10 of Cups"}, {"MP005_S_CARDT_ACC", "Ace of Cups"}, {"MP005_S_CARDT_KIC", "King of Cups"}, {"MP005_S_CARDT_KNC", "Knight of Cups"}, {"MP005_S_CARDT_PAC", "Page of Cups"}, {"MP005_S_CARDT_QUC", "Queen of Cups"}};

	inline const RewardInfo TarotCards_Pentacles[]{{"MP005_S_CARDT_2P", "2 of Pentacles"}, {"MP005_S_CARDT_3P", "3 of Pentacles"}, {"MP005_S_CARDT_4P", "4 of Pentacles"}, {"MP005_S_CARDT_5P", "5 of Pentacles"}, {"MP005_S_CARDT_6P", "6 of Pentacles"}, {"MP005_S_CARDT_7P", "7 of Pentacles"}, {"MP005_S_CARDT_8P", "8 of Pentacles"}, {"MP005_S_CARDT_9P", "9 of Pentacles"}, {"MP005_S_CARDT_10P", "10 of Pentacles"}, {"MP005_S_CARDT_ACP", "Ace of Pentacles"}, {"MP005_S_CARDT_KIP", "King of Pentacles"}, {"MP005_S_CARDT_KNP", "Knight of Pentacles"}, {"MP005_S_CARDT_PAP", "Page of Pentacles"}, {"MP005_S_CARDT_QUP", "Queen of Pentacles"}};

	inline const RewardInfo TarotCards_Swords[]{{"MP005_S_CARDT_2S", "2 of Swords"}, {"MP005_S_CARDT_3S", "3 of Swords"}, {"MP005_S_CARDT_4S", "4 of Swords"}, {"MP005_S_CARDT_5S", "5 of Swords"}, {"MP005_S_CARDT_6S", "6 of Swords"}, {"MP005_S_CARDT_7S", "7 of Swords"}, {"MP005_S_CARDT_8S", "8 of Swords"}, {"MP005_S_CARDT_9S", "9 of Swords"}, {"MP005_S_CARDT_10S", "10 of Swords"}, {"MP005_S_CARDT_ACS", "Ace of Swords"}, {"MP005_S_CARDT_KIS", "King of Swords"}, {"MP005_S_CARDT_KNS", "Knight of Swords"}, {"MP005_S_CARDT_PAS", "Page of Swords"}, {"MP005_S_CARDT_QUS", "Queen of Swords"}};

	inline const RewardInfo TarotCards_Wands[]{{"MP005_S_CARDT_2W", "2 of Wands"}, {"MP005_S_CARDT_3W", "3 of Wands"}, {"MP005_S_CARDT_4W", "4 of Wands"}, {"MP005_S_CARDT_5W", "5 of Wands"}, {"MP005_S_CARDT_6W", "6 of Wands"}, {"MP005_S_CARDT_7W", "7 of Wands"}, {"MP005_S_CARDT_8W", "8 of Wands"}, {"MP005_S_CARDT_9W", "9 of Wands"}, {"MP005_S_CARDT_10W", "10 of Wands"}, {"MP005_S_CARDT_ACW", "Ace of Wands"}, {"MP005_S_CARDT_KIW", "King of Wands"}, {"MP005_S_CARDT_KNW", "Knight of Wands"}, {"MP005_S_CARDT_PAW", "Page of Wands"}, {"MP005_S_CARDT_QUW", "Queen of Wands"}};

	enum class eRewardType : int
	{
		GOLD_REWARDS         = 0,
		HEIRLOOMS            = 1,
		COINS                = 2,
		ALCBOTTLES           = 3,
		ARROWHEADS           = 4,
		BRACELETS            = 5,
		EARRINGS             = 6,
		NECKLACES            = 7,
		RINGS                = 8,
		TAROTCARDS_CUPS      = 9,
		TAROTCARDS_PENTACLES = 10,
		TAROTCARDS_SWORDS    = 11,
		TAROTCARDS_WANDS     = 12,
	};

	void SpawnRequestedRewards(std::vector<eRewardType> rewards);
	void SpawnRequestedRewards_Helper(std::string model_name);
}