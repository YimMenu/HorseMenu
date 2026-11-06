#pragma once
#include <string>
#include <vector>

namespace Terminus::Data
{
	struct ObjectModel
	{
		std::string model;
		std::string description;
	};

	// Declare the function that gets models
	const std::vector<ObjectModel>& GetObjectModels();

	// Declare the helper function (if you need it)
	std::string GetAppDataPath();
}