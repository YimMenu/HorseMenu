#pragma once
#include "core/filemgr/FileMgr.hpp"


namespace Terminus::LuaJIT
{
	class LuaPathError : public std::runtime_error
	{
	public:
		using std::runtime_error::runtime_error;
	};

	class LuaPath
	{
	public:
		LuaPath() = default;
		explicit LuaPath(const fs::path& sandboxRoot, const fs::path& other);

		const fs::path& Get() const noexcept;

		bool Exists() const;
		bool IsFile() const;
		bool IsDir() const;
		bool MakeDir() const;
		bool MakeDirs() const;

		std::string Filename() const;
		std::string Extension() const;
		std::string Stem() const;
		uintmax_t Size() const;

		LuaPath Parent() const;
		LuaPath Join(const std::string& sub) const;

		bool operator==(const LuaPath& other) const noexcept
		{
			return m_Root == other.Get();
		}

		LuaPath operator/(const std::string& sub) const
		{
			return Join(sub);
		}

	private:
		fs::path m_SandboxRoot{};
		fs::path m_Root{};
	};
}
