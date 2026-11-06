#include "LuaMgr.hpp"
#include "LuaModule.hpp"


namespace Terminus::LuaJIT
{
	using FileMgr = Terminus::FileMgr;
	void LuaManager::InitImpl()
	{
		if (m_Initialized)
			return;

		m_PluginsDir = FileMgr::GetProjectFolder("scripts");
		FileMgr::CreateFolderIfNotExists(m_PluginsDir);
		FileMgr::CreateFolderIfNotExists(m_PluginsDir / "shared");
		FileMgr::CreateFolderIfNotExists(m_PluginsDir / "disabled");

		LoadModulesImpl();
		m_Initialized.store(true);
		LOG(INFO) << "LuaManager initialized.";
	}

	void LuaManager::DestroyImpl()
	{
		if (!m_Initialized)
			return;

		m_Initialized.store(false);
		std::unique_lock lock(m_LoadedModulesMutex);
		m_Modules.clear();
		m_DisabledModules.clear();
		LOG(INFO) << "LuaManager destroyed.";
	}

	void LuaManager::RegisterLibraryImpl(LuaLibrary* library)
	{
		m_Libraries.push_back(library);
	}

	void LuaManager::RegisterLibrariesImpl(sol::state& L)
	{
		int count = 0;
		for (auto library : m_Libraries)
		{
			count += 1;
			library->Register(L);
		}
	}

	void LuaManager::LoadModuleImpl(const fs::path& root)
	{
		std::error_code ec{};
		if (!fs::is_directory(root, ec))
			return;

		for (auto& entry : fs::directory_iterator(root))
		{
			if (!fs::is_regular_file(entry, ec))
				continue;

			if (entry.path().filename().string() == "main.lua")
			{
				m_LoadQueue.push(root);
				break;
			}
		}
	}

	void LuaManager::EnableModuleImpl(const fs::path& root)
	{
		std::scoped_lock lock(m_DisabledModulesMutex);
		std::erase_if(m_DisabledModules, [this, root](const DisabledModule& m) {
			if (m.m_Path == root)
			{
				if (root.parent_path().filename().string() == "disabled")
				{
					auto newRoot = m_PluginsDir / root.filename().string();
					try
					{
						fs::rename(root, newRoot);
					}
					catch (const fs::filesystem_error& e)
					{
						LOG(FATAL) << "Failed to enable module" << root.string() << " : " << e.what();
						return false;
					}
					
					LoadModuleImpl(newRoot);
					return true;
				}

				LoadModuleImpl(root);
				return true;
			}
			return false;
		});
	}

	void LuaManager::LoadDisabledModulesImpl(const fs::path& root)
	{
		std::error_code ec{};
		if (!fs::exists(root, ec) || !fs::is_directory(root, ec))
			return;

		for (auto& entry : fs::directory_iterator(root))
		{
			if (!fs::is_directory(entry, ec))
				continue;

			auto rootname = entry.path().filename().string();
			if (rootname.empty())
				continue;

			m_DisabledModules.push_back({rootname, entry.path()});
		}
	}

	void LuaManager::LoadDisabledModuleImpl(const fs::path& root, bool fullyDisable)
	{
		fs::path __path  = root;
		fs::path newRoot = m_PluginsDir / "disabled" / root.filename().string();

		if (fullyDisable)
		{
			try
			{
				fs::rename(root, newRoot);
				__path = newRoot;
			}
			catch (const fs::filesystem_error& e)
			{
				LOG(FATAL) << "Failed to disable module" << root.string() << " : " << e.what();
				return;
			}
		}

		std::scoped_lock lock(m_DisabledModulesMutex);
		m_DisabledModules.push_back({__path.filename().string(), __path});
	}

	void LuaManager::LoadModulesImpl()
	{
		std::error_code ec{};
		if (!fs::exists(m_PluginsDir, ec) || !fs::is_directory(m_PluginsDir, ec) || fs::is_empty(m_PluginsDir, ec))
			return;

		for (auto& entry : fs::directory_iterator(m_PluginsDir))
		{
			if (!fs::is_directory(entry, ec))
				continue;

			auto rootname = entry.path().filename().string();
			if (rootname.empty() || rootname == "shared")
				continue;

			if (rootname == "disabled")
				LoadDisabledModulesImpl(entry.path());
			else
				LoadModuleImpl(entry.path());
		}
	}

	// enabled modules only
	void LuaManager::ReloadAllModulesImpl()
	{
		{
			std::scoped_lock loadedLock(m_LoadedModulesMutex);
			std::scoped_lock disabledLock(m_DisabledModulesMutex);
			m_Modules.clear();
			m_DisabledModules.clear();
		}
		LoadModulesImpl();
	}

	void LuaManager::UpdateImpl()
	{
		while (m_Initialized && g_Running)
		{
			{
				std::scoped_lock lock(m_LoadedModulesMutex);
				while (!m_LoadQueue.empty())
				{
					auto m = std::make_shared<LuaModule>(m_LoadQueue.front());
					m->SandboxAPI(m_PluginsDir);

					if (m->Load())
						m_Modules.push_back(m);
					else
						m_DisabledModules.push_back({m->GetName().data(), m->GetRoot()});

					m_LoadQueue.pop();
				}

				std::erase_if(m_Modules, [this](auto& m) {
					if (!m->IsSafeToUnload())
						return false;

					if (m_ShouldReload)
						return true;

					auto state = m->GetLoadState();
					if (state == LuaModule::WANTS_UNLOAD || state == LuaModule::WANTS_DISABLE)
					{
						LoadDisabledModuleImpl(m->GetRoot(), state == LuaModule::WANTS_DISABLE);
						return true;
					}
					else if (state == LuaModule::WANTS_RELOAD)
					{
						m_LoadQueue.push(m->GetRoot());
						return true;
					}

					return false;
				});

				for (auto& m : m_Modules)
				{
					if (m->GetLoadState() == LuaModule::RUNNING)
						m->Tick();

					m->OnFileEdit();
				}
			}

			auto now = std::chrono::steady_clock::now();
			if (m_ShouldReload && m_Modules.empty() && now - m_LastReload >= 1200ms)
			{
				m_ShouldReload = false;
				m_LastReload   = now;
				ReloadAllModulesImpl();
			}

			ScriptMgr::Yield();
		}
	}
}
