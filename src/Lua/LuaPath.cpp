#include "LuaPath.hpp"


namespace Terminus::LuaJIT
{
	LuaPath::LuaPath(const fs::path& sandboxRoot, const fs::path& other) :
	    m_SandboxRoot(sandboxRoot)
	{
		if (sandboxRoot == other)
		{
			m_Root = other;
			return;
		}

		auto absPath = FileMgr::MakeAbsPath(sandboxRoot, other);
		if (!absPath.has_value())
		{
			LOG(FATAL) << "[LuaPath]: The Path class is restricted to the module's root folder. Path '" << other.string() << "' is not allowed.";
			throw LuaPathError("The Path class is restricted to the module's root folder.");
		}

		m_Root = *absPath;
	}

	const fs::path& LuaPath::Get() const noexcept
	{
		return m_Root;
	}

	bool LuaPath::Exists() const
	{
		std::error_code ec{};
		return fs::exists(m_Root, ec);
	}

	bool LuaPath::IsFile() const
	{
		std::error_code ec{};
		return fs::is_regular_file(m_Root, ec);
	}

	bool LuaPath::IsDir() const
	{
		std::error_code ec{};
		return fs::is_directory(m_Root, ec);
	}

	bool LuaPath::MakeDir() const
	{
		if (Exists())
			return true;

		std::error_code ec{};
		return fs::create_directory(m_Root, ec);
	}

	bool LuaPath::MakeDirs() const
	{
		if (Exists())
			return true;

		std::error_code ec{};
		return fs::create_directories(m_Root, ec);
	}

	std::string LuaPath::Filename() const
	{
		return m_Root.filename().string();
	}

	std::string LuaPath::Stem() const
	{
		return m_Root.filename().stem().string();
	}

	std::string LuaPath::Extension() const
	{
		return m_Root.extension().string();
	}

	uintmax_t LuaPath::Size() const
	{
		return fs::file_size(m_Root);
	}

	LuaPath LuaPath::Parent() const
	{
		auto parent = m_Root.parent_path();
		if (parent == m_SandboxRoot)
			return LuaPath(m_SandboxRoot, m_SandboxRoot);

		return LuaPath(m_SandboxRoot, parent);
	}

	LuaPath LuaPath::Join(const std::string& sub) const
	{
		fs::path other = fs::path(sub);
		if (!m_Root.string().empty())
			other = m_Root / sub;

		return LuaPath(m_SandboxRoot, other);
	}
}
