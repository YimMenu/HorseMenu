#pragma once
#include <string>

namespace Terminus::Data
{
	std::string GetAppDataPath();
	bool DownloadModelsJson();
	bool ExtractModelsJson(); // Keep for backward compatibility
}