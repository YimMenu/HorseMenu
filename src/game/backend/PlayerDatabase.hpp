#pragma once
#include "core/filemgr/File.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "game/rdr/Player.hpp"

#include <memory>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>
#include <unordered_set>


namespace nlohmann
{
	template<typename T>
	struct adl_serializer<std::shared_ptr<T>>
	{
		static void to_json(json& j, const std::shared_ptr<T>& value)
		{
			j = *value;
		}

		static void from_json(const json& j, std::shared_ptr<T>& value)
		{
			value  = std::make_shared<T>();
			*value = j.get<T>();
		}
	};
}

namespace YimMenu
{
	enum class Detection : uint32_t;
	struct persistent_player;

	class PlayerDatabase
	{
	private:
		std::filesystem::path m_File;
		std::unordered_map<uint64_t /*rid*/, std::shared_ptr<persistent_player>> m_Data;
		std::shared_ptr<persistent_player> m_Selected = nullptr;

	public:
		PlayerDatabase();
		~PlayerDatabase();

		void Load();
		void Save();

		std::shared_ptr<persistent_player> GetPlayer(uint64_t rid);
		void AddPlayer(uint64_t rid, std::string name);
		std::shared_ptr<persistent_player> GetOrCreatePlayer(uint64_t rid, std::string name = "Unknown Player");
		std::unordered_map<uint64_t, std::shared_ptr<persistent_player>>& GetAllPlayers();
		void SetSelected(std::shared_ptr<persistent_player> player);
		std::shared_ptr<persistent_player> GetSelected();
		std::string ConvertDetectionToDescription(Detection infraction);
		void AddDetection(std::shared_ptr<persistent_player> player, Detection infraction);
		void RemoveRID(uint64_t rockstar_id);
	};

	struct persistent_player
	{
		uint64_t rid;
		std::string name;
		bool is_modder  = false;
		bool is_admin   = false;
		bool block_join = false;
		bool trust      = false;
		std::unordered_set<uint32_t> infractions;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(persistent_player, rid, name, is_modder, is_admin, block_join, trust, infractions);
	};


	inline PlayerDatabase* g_PlayerDatabase; // TODO: REMOVE THIS!!!!!!
}