#include "SavedLocations.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "core/frontend/Notifications.hpp"

namespace YimMenu
{
	std::filesystem::path SavedLocations::GetSavedLocationsFilePath()
	{
		return FileMgr::GetProjectFile("./telelocations.json").Path();
	}

	std::vector<SavedLocation> SavedLocations::SavedLocationsFilteredListImpl(std::string filter)
	{
		std::vector<SavedLocation> filterList{};

		static auto toLower = [=](std::string text) -> std::string {
			std::transform(text.begin(), text.end(), text.begin(), ::tolower);
			return text;
		};

		for (auto& location : m_AllSavedLocations | std::views::values | std::views::join)
			if (toLower(location.name).find(toLower(filter)) != std::string::npos)
				filterList.push_back(location);

		return filterList;
	}

	bool SavedLocations::FetchSavedLocationsImpl()
	{
		m_AllSavedLocations.clear();

		auto path = GetSavedLocationsFilePath();
		std::ifstream file(path, std::ios::binary);

		try
		{
			if (!file.is_open())
				return false;

			nlohmann::json j;
			file >> j;
			m_AllSavedLocations = j.get<std::map<std::string, std::vector<SavedLocation>>>();

			return true;
		}
		catch (const std::exception& e)
		{
			LOG(WARNING) << "Failed fetching saved locations: " << e.what() << '\n';
			return false;
		}

		return false;
	}

	bool SavedLocations::SaveNewLocationImpl(const std::string& category, SavedLocation t)
	{
		const auto& pair = m_AllSavedLocations.insert({category, {t}});
		if (!pair.second)
		{
			pair.first->second.push_back(t);
		}

		auto path = GetSavedLocationsFilePath();

		std::ofstream fileOut(path, std::ofstream::trunc | std::ofstream::binary);
		if (!fileOut.is_open())
			return false;

		nlohmann::json j = m_AllSavedLocations;
		fileOut << j.dump(4);
		fileOut.close();

		return true;
	}

	bool SavedLocations::DeleteSavedLocationImpl(const std::string& category, const std::string& locationName)
	{
		auto path = GetSavedLocationsFilePath();

		const auto& it = m_AllSavedLocations.find(category);
		if (it == m_AllSavedLocations.end())
			return false;

		std::erase_if(it->second, [locationName](SavedLocation t) {
			return t.name == locationName;
		});

		if (!it->second.size())
		{
			m_AllSavedLocations.erase(category);
		}

		std::ofstream fileOut(path, std::ofstream::trunc | std::ofstream::binary);
		if (!fileOut.is_open())
			return false;

		nlohmann::json j = m_AllSavedLocations;
		fileOut << j.dump(4);
		fileOut.close();

		return true;
	}

	SavedLocation* SavedLocations::GetSavedLocationByNameImpl(std::string name)
	{
		for (auto& loc : SavedLocationsFilteredList())
			if (loc.name == name)
				return &loc;

		return nullptr;
	}
}
