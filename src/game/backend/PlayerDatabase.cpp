#include "PlayerDatabase.hpp"
#include "Detections.hpp"

namespace YimMenu
{
	using json = nlohmann::json;

	PlayerDatabase::PlayerDatabase() :
	    m_File(std::filesystem::path(std::getenv("appdata")) / "HorseMenu" / "database.json")
	{
		Load();

		g_PlayerDatabase = this;

		LOG(INFO) << "Player Database Initialized";
	}

	PlayerDatabase::~PlayerDatabase()
	{
		LOG(INFO) << "Player Database Uninitialized";

		g_PlayerDatabase = nullptr;
	}

	void PlayerDatabase::Load()
	{
		m_Selected = nullptr;
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

			for (auto& [key, value] : jsonData.items())
			{
				auto player             = value.get<std::shared_ptr<persistent_player>>();
				m_Data[std::stoll(key)] = player;
			}
		}
	}

	void PlayerDatabase::Save()
	{
		// TODO: save in thread pool
		json data;

		for (auto& [rid, player] : m_Data)
		{
			data[std::to_string(rid)] = player;
		}

		std::ofstream fileStream(m_File);
		if (fileStream.is_open())
		{
			fileStream << std::setw(4) << data << std::endl;
			fileStream.close();
		}
		else
			LOG(WARNING) << "Unable to save Player Database!";
	}

	std::shared_ptr<persistent_player> PlayerDatabase::GetPlayer(uint64_t rid)
	{
		auto it = m_Data.find(rid);
		if (it != m_Data.end())
		{
			return it->second;
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
			m_Data[rid]  = player;
			Save();
		}
	}

	std::shared_ptr<persistent_player> PlayerDatabase::GetOrCreatePlayer(uint64_t rid, std::string name)
	{
		auto player = GetPlayer(rid);
		if (!player)
		{
			player       = std::make_shared<persistent_player>();
			player->rid  = rid;
			player->name = name;
			m_Data[rid]  = player;
			Save();
		}
		return player;
	}

	std::unordered_map<uint64_t, std::shared_ptr<persistent_player>>& PlayerDatabase::GetAllPlayers()
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

	std::string PlayerDatabase::ConvertDetectionToDescription(Detection infraction)
	{
		if (auto it = g_DetectionDescs.find(infraction); it != g_DetectionDescs.end())
			return it->second;
		return "";
	}

	void PlayerDatabase::AddDetection(std::shared_ptr<persistent_player> player, Detection infraction)
	{
		if (!player->trust)
		{
			player->infractions.insert((int)infraction);
			if (!player->is_modder)
			{
				player->is_modder = true;
			}
			Save();
		}
	}

	void PlayerDatabase::RemoveRID(uint64_t rockstar_id)
	{
		if (m_Selected && m_Selected->rid == rockstar_id)
		{
			m_Selected = nullptr;
		}

		if (auto it = m_Data.find(rockstar_id); it != m_Data.end())
		{
			m_Data.erase(it);
			Save();
		}
	}
}