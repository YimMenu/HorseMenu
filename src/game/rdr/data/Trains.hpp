#pragma once
#include <string>

namespace YimMenu::Data
{
	struct TrainData
	{
		uint32_t model;
		std::string name;
	};

	const TrainData g_Trains[] = {
	    {0x3D72571D, "Gunslinger 1"},
	    {0x5AA369CA, "Gunslinger 2"},
	    {0x515E31ED, "Prisoner Escort(Passenger Train)"},
	    {0x487B2BE7, "Winter Train"},
	    {0x0E62D710, "Ghost Train"},
	    {0x005E03AD, "Standard Train 1"},
	    {0x0392C83A, "Standard Train 2"}, 
		{0x0660E567, "Standard Train 3"},
	};
}