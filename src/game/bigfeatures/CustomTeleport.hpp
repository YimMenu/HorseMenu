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

	class CustomTeleport
	{
	private:
		std::filesystem::path GetTelelocationsFile();
		std::map<std::string, std::vector<Telelocation>> m_AllSavedLocations;

	private:
		bool FetchSavedLocationsImpl();
		bool SaveNewLocationImpl(const std::string& category, Telelocation t);
		bool DeleteSavedLocationImpl(const std::string& category, const std::string& location_name);
		Telelocation* GetSavedLocationByNameImpl(std::string);
		std::vector<Telelocation> SavedLocationsFilteredListImpl(std::string filter = "");

		static CustomTeleport& GetInstance()
		{
			static CustomTeleport instance{};
			return instance;
		}

	public:
		static std::map<std::string, std::vector<Telelocation>>& GetAllSavedLocations()
		{
			return GetInstance().m_AllSavedLocations;
		}
		static bool FetchSavedLocations()
		{
			return GetInstance().FetchSavedLocationsImpl();
		};
		static bool SaveNewLocation(const std::string& category, Telelocation t)
		{
			return GetInstance().SaveNewLocationImpl(category, t);
		};
		static bool DeleteSavedLocation(const std::string& category, const std::string& location_name)
		{
			return GetInstance().DeleteSavedLocationImpl(category, location_name);
		};
		static Telelocation* GetSavedLocationByName(std::string location_name)
		{
			return GetInstance().GetSavedLocationByNameImpl(location_name);
		};
		static std::vector<Telelocation> SavedLocationsFilteredList(std::string filter = "")
		{
			return GetInstance().SavedLocationsFilteredListImpl(filter);
		};
	};

}