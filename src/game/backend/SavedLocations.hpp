#pragma once
#include "util/teleport.hpp"

namespace YimMenu
{
	struct SavedLocation
	{
		std::string name;
		float x, y, z;
		float yaw = 0.0f, pitch = 0.0f, roll = 0.0f;
	};

	NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(SavedLocation, name, x, y, z, yaw, pitch, roll);

	class SavedLocations
	{
	private:
		std::filesystem::path GetSavedLocationsFilePath();
		std::map<std::string, std::vector<SavedLocation>> m_AllSavedLocations;

	private:
		bool FetchSavedLocationsImpl();
		bool SaveNewLocationImpl(const std::string& category, SavedLocation t);
		bool DeleteSavedLocationImpl(const std::string& category, const std::string& location_name);
		SavedLocation* GetSavedLocationByNameImpl(std::string);
		std::vector<SavedLocation> SavedLocationsFilteredListImpl(std::string filter = "");

		static SavedLocations& GetInstance()
		{
			static SavedLocations instance{};
			return instance;
		}

	public:
		static std::map<std::string, std::vector<SavedLocation>>& GetAllSavedLocations()
		{
			return GetInstance().m_AllSavedLocations;
		}

		static bool FetchSavedLocations()
		{
			return GetInstance().FetchSavedLocationsImpl();
		};

		static bool SaveNewLocation(const std::string& category, SavedLocation t)
		{
			return GetInstance().SaveNewLocationImpl(category, t);
		};

		static bool DeleteSavedLocation(const std::string& category, const std::string& location_name)
		{
			return GetInstance().DeleteSavedLocationImpl(category, location_name);
		};

		static SavedLocation* GetSavedLocationByName(std::string location_name)
		{
			return GetInstance().GetSavedLocationByNameImpl(location_name);
		};

		static std::vector<SavedLocation> SavedLocationsFilteredList(std::string filter = "")
		{
			return GetInstance().SavedLocationsFilteredListImpl(filter);
		};
	};

}