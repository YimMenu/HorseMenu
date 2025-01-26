#include "MapInfo.hpp"

namespace YimMenu
{
	void MapInfo::Setup()
	{
	}

	void MapInfo::Update()
	{
	}

	void MapInfo::Destroy()
	{
	}

	void MapInfo::Reset()
	{
		m_Name = "";
		m_Description = "";
		m_CurrentIndex = 0;
	}

	void MapInfo::Serialize(nlohmann::json& object)
	{
		object["name"] = m_Name;
		object["description"] = m_Description;
		object["current_index"] = m_CurrentIndex;
	}

	void MapInfo::Deserialize(nlohmann::json& object)
	{
		m_Name = object["name"];
		m_Description = object["description"];
		m_CurrentIndex = object["current_index"];
	}
}