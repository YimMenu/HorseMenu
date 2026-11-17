#include "DataExtractor.hpp"

#include <fstream>
#include <shlobj.h>
#include <string>
#include <urlmon.h>
#include <windows.h>

#pragma comment(lib, "urlmon.lib")

namespace Terminus::Data
{
	const char* MODELS_URL = "https://raw.githubusercontent.com/Deadlineem/HorseMenu/refs/heads/master/src/game/rdr/data/models.json";

	std::string GetAppDataPath()
	{
		char path[MAX_PATH];
		if (SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, path) == S_OK)
		{
			std::string result = path;
			result += "\\Terminus";
			CreateDirectoryA(result.c_str(), NULL);
			return result + "\\";
		}
		return "";
	}

	bool DownloadModelsJson()
	{
		std::string appDataPath = GetAppDataPath();
		if (appDataPath.empty())
			return false;

		std::string destPath = appDataPath + "models.json";

		// Check if file already exists in AppData
		if (GetFileAttributesA(destPath.c_str()) != INVALID_FILE_ATTRIBUTES)
			return true; // Already exists

		// Download the file from the URL
		HRESULT hr = URLDownloadToFileA(NULL, // Callback
		    MODELS_URL,                       // URL to download
		    destPath.c_str(),                 // Destination path
		    0,                                // Reserved
		    NULL                              // Callback
		);

		if (hr != S_OK)
		{
			// Download failed, create empty JSON as fallback
			std::ofstream file(destPath);
			if (file.is_open())
			{
				file << "[]"; // Empty array
				file.close();
				return true;
			}
			return false;
		}

		return true;
	}

	// Keep for backward compatibility
	bool ExtractModelsJson()
	{
		return DownloadModelsJson();
	}
}