#pragma once

namespace YimMenu
{
	struct MapInfo
	{
		std::string m_Name = "";
		std::string m_Description = "";
		std::uint32_t m_CurrentIndex = 0;

		void Setup();
		void Update();
		void Destroy();

		// void ChangeWeather(int weather);

		// serialization
		void Reset();
		void Serialize(nlohmann::json& object);
		void Deserialize(nlohmann::json& object);
	};
}