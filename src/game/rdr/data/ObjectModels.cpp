#include "ObjectModels.hpp"

#include "game/backend/DataExtractor.hpp"

#include <fstream>
#include <nlohmann/json.hpp>

namespace Terminus::Data
{
	const std::vector<ObjectModel>& GetObjectModels()
	{
		static const std::vector<ObjectModel> models = []() {
			std::vector<ObjectModel> result;

			DownloadModelsJson();

			// Load from %APPDATA%\Terminus\models.json
			std::string appDataPath = GetAppDataPath();
			std::string filePath = appDataPath + "models.json";

			std::ifstream fileStream(filePath);
			if (!fileStream.is_open())
			{
				return result;
			}

			try
			{
				auto json = nlohmann::json::parse(fileStream);
				result.reserve(json.size());

				for (const auto& item : json)
				{
					result.push_back({item["model"].get<std::string>(), item["description"].get<std::string>()});
				}
			}
			catch (...)
			{
				// JSON parsing failed
			}

			return result;
		}();
		return models;
	}
}