#include "PlayerDatabase.hpp"

namespace YimMenu
{
	using json = nlohmann::json;

	PlayerDatabase::PlayerDatabase() :
	    m_File(std::filesystem::path(std::getenv("appdata")) / "HorseMenu" / "database.json")
	{
	}

	void PlayerDatabase::Load()
	{
		if (!std::filesystem::exists(m_File))
		{
			LOG(VERBOSE) << "Player Database Doesn't Exist";
			std::ofstream file(m_File, std::ios::out | std::ios::trunc);
			file << "{}" << std::endl;
			file.close();

			if (!std::filesystem::exists(m_File))
			{
				LOG(VERBOSE) << "Player Database unable to open!";
			}
			else
				LOG(VERBOSE) << "Player Database Reset!";
		}

		std::ifstream fileStream(m_File);
		if (fileStream.is_open())
		{
			json jsonData;
			fileStream >> jsonData;
			fileStream.close();

			for (const auto& item : jsonData)
			{
				auto player         = std::make_shared<persistent_player>();
				player->rid         = item["rid"];
				player->name        = item["name"];
				player->is_modder   = item["is_modder"];
				player->is_admin    = item["is_admin"];
				player->infractions = item["infractions"].get<std::unordered_set<int>>();

				m_Data.push_back(std::make_pair(player->rid, player));
			}
		}
	}

	void PlayerDatabase::Save() const
	{
		json data;

		for (const auto& pair : m_Data)
		{
			json item;
			const auto& player  = pair.second;
			item["rid"]         = player->rid;
			item["name"]        = player->name;
			item["is_modder"]   = player->is_modder;
			item["is_admin"]    = player->is_admin;
			item["infractions"] = player->infractions;
			data.push_back(item);
		}

		std::ofstream fileStream(m_File);
		if (fileStream.is_open())
		{
			fileStream << data << std::endl;
			fileStream.close();
		}
		else
			LOG(WARNING) << "Unable to save Player Database!";
	}

	std::shared_ptr<persistent_player> PlayerDatabase::GetPlayer(uint64_t rid)
	{
		for (const auto& pair : m_Data)
		{
			if (pair.second->rid == rid)
			{
				return pair.second;
			}
		}

		return nullptr;
	}

	void PlayerDatabase::AddPlayer(uint64_t rid, std::string name)
	{
		if (GetPlayer(rid) == nullptr)
		{
			auto player  = std::make_shared<persistent_player>();
			player->rid  = rid;
			player->name = name;
			m_Data.push_back(std::make_pair(rid, player));
		}
	}

	std::shared_ptr<persistent_player> PlayerDatabase::GetOrCreatePlayer(uint64_t rid)
	{
		auto player = GetPlayer(rid);
		if (!player)
		{
			player      = std::make_shared<persistent_player>();
			player->rid = rid;
			m_Data.push_back(std::make_pair(rid, player));
		}
		return player;
	}

	std::vector<std::pair<uint64_t, std::shared_ptr<persistent_player>>> PlayerDatabase::GetAllPlayers() const
	{
		return m_Data;
	}

	void PlayerDatabase::SetSelected(std::shared_ptr<persistent_player> player)
	{
		m_Selected = player;
	}

	std::shared_ptr<persistent_player> PlayerDatabase::GetSelected()
	{
		return m_Selected;
	}
}