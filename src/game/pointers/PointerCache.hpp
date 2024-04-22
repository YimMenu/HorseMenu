#pragma once
#include "core/filemgr/File.hpp"
#include "core/filemgr/FileMgr.hpp"
#include "game/features/Features.hpp"

#include <iostream>
#include <nlohmann/json.hpp>


namespace YimMenu
{
	class PointerCache
	{
	private:
		std::filesystem::path m_File;
		std::vector<std::pair<std::string, uintptr_t>> m_Data;
		std::uint32_t m_Version;

	public:
		PointerCache(uint32_t version);

		void Load();
		void Save() const;

		uintptr_t GetData(std::string name) const;
		uintptr_t GetOrUpdate(std::string name, uintptr_t value);

		constexpr uint32_t GetCacheVersion() const;
	};

}