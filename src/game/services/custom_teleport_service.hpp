#pragma once
#include "util/teleport.hpp"

namespace YimMenu
{
	struct Telelocation
	{
		std::string name;
		float x, y, z;
		float yaw = 0.0f, pitch = 0.0f, roll = 0.0f;
	};

	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(Telelocation, name, x, y, z, yaw, pitch, roll);

	class CustomTeleportService
	{
	public:
		std::map<std::string, std::vector<Telelocation>> m_AllSavedLocations;
		bool FetchSavedLocations();
		bool SaveNewLocation(const std::string& category, Telelocation t);
		bool DeleteSavedLocation(const std::string& category, const std::string& location_name);
		Telelocation* GetSavedLocationByName(std::string);
		std::vector<Telelocation> SavedLocationsFilteredList(std::string filter = "");

	private:
		std::filesystem::path GetTelelocationsFile();
	};

	inline CustomTeleportService g_CustomTeleportService;
}