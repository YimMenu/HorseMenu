#pragma once
#include "util/Joaat.hpp"
#include "CategoryUtils.hpp"

namespace YimMenu
{
	struct VehicleModelDefinition : public ModelDefinition
	{
	};

	inline std::vector<std::pair<const char*, std::vector<VehicleModelDefinition>>> g_VehicleCategories = 
	{
		{"Wagons", {
			{"wagoncircus01x"_J, "Circus Wagon 1"},
			{"wagoncircus02x"_J, "Circus Wagon 2"},
			{"wagontraveller01x"_J, "Traveller Wagon"},
			{"wagondoc01x"_J, "Doctor Wagon"},
			{"wagondairy01x"_J, "Dairy Wagon"},
			{"policewagon01x"_J, "Police Wagon 1"},
			{"policewagongatling01x"_J, "Police Wagon 2"},
			{"coal_wagon"_J, "Coal Wagon"},
			{"oilwagon01x"_J, "Oil Wagon 1"},
			{"oilwagon02x"_J, "Oil Wagon 2"},
			{"supplywagon"_J, "Supply Wagon 1"},
			{"supplywagon2"_J, "Supply Wagon 2"},
			{"wagonwork01x"_J, "Work Wagon"},
		}},
	    {"Mounted Weapons", {
			{"gatling_gun"_J, "Gatling Gun"},
			{"gatlingmaxim02"_J, "Maxim Gun"},
		}},
	};
}