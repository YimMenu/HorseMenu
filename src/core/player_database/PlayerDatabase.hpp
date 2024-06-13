#pragma once
#include "core/filemgr/File.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "game/features/Features.hpp"
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
		std::string ConvertInfractionToDescription(int infraction);
		void AddInfraction(std::shared_ptr<persistent_player> player, int infraction);

		enum class eInfraction
		{
			TRIED_CRASH_PLAYER,
			TRIED_KICK_PLAYER,
			REMOTE_NATIVE_CALL,
			TRIED_ATTACH,
			REMOTE_TELEPORT,
			INVALID_PROPSET,
		};

		std::unordered_map<eInfraction, std::string> InfractionDescriptions = {{eInfraction::TRIED_CRASH_PLAYER, "Tried to crash you!"}, {eInfraction::TRIED_KICK_PLAYER, "Tried to kick you!"}};
	};

	struct persistent_player
	{
		uint64_t rid;
		std::string name;
		bool is_modder  = false;
		bool is_admin   = false;
		bool block_join = false;
		bool trust      = false;
		std::unordered_set<int> infractions;

		NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(persistent_player, rid, name, is_modder, is_admin, block_join, trust, infractions);
	};


	inline PlayerDatabase* g_PlayerDatabase;


}