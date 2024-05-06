#pragma once
#include "core/filemgr/File.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Player.hpp"

#include <nlohmann/json.hpp>
#include <string>
#include <unordered_set>
#include <vector>

namespace YimMenu
{
	struct persistent_player;

	class PlayerDatabase
	{
	private:
		std::filesystem::path m_File;
		std::vector<std::pair<uint64_t /*rid*/, persistent_player>> m_Data;
		Player m_Selected;

	public:
		PlayerDatabase();

		void Load();
		void Save() const;

		persistent_player GetPlayer(uint64_t rid);
		void AddPlayer(uint64_t rid, std::string name);
		persistent_player GetOrCreatePlayer(uint64_t rid);
		std::vector<std::pair<uint64_t, persistent_player>> GetAllPlayers() const;
		void SetSelected(Player player);
		persistent_player GetSelected() const;
	};

	struct persistent_player
	{
		uint64_t rid;
		std::string name;
		bool is_modder = false;
		bool is_admin  = false;
		std::unordered_set<int> infractions;
	};

	static PlayerDatabase g_PlayerDatabase;


}