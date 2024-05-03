#pragma once
#include "core/filemgr/File.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "game/features/Features.hpp"

#include <iostream>
#include <mutex>
#include <nlohmann/json.hpp>


namespace YimMenu
{
	class PointerCache
	{
	private:
		std::filesystem::path m_File;
		std::vector<std::pair<std::string, uintptr_t>> m_Data;
		std::uintptr_t m_Version;

	public:
		PointerCache(uintptr_t version);
		~PointerCache();

		void Load();
		void Save() const;
		void Unload();

		uintptr_t GetData(std::string name);
		uintptr_t GetOrUpdate(std::string name, uintptr_t value);

		uintptr_t GetCacheVersion();
		uintptr_t GetCacheFileVersion();
		bool IsCacheOutdated();
		void IncrementCacheVersion();
	};

}