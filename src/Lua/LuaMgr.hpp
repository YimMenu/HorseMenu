#pragma once
#include <sol/sol.hpp>

#include "core/filemgr/FileMgr.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "util/Singleton.hpp"
#include "LuaModule.hpp"
#include "LuaLibrary.hpp"
#include "LuaMenuEvent.hpp"


namespace Terminus::LuaJIT
{
	class LuaManager : public Singleton<LuaManager>
	{
		friend class Singleton<LuaManager>;

	private:
		LuaManager() noexcept = default;
		~LuaManager()         = default;

		LuaManager(const LuaManager&)            = delete;
		LuaManager(LuaManager&&)                 = delete;
		LuaManager& operator=(const LuaManager&) = delete;
		LuaManager& operator=(LuaManager&&)      = delete;

		void LoadModuleImpl(const fs::path& path);
		void LoadDisabledModuleImpl(const fs::path& path, bool fullyDisable = false);
		void LoadDisabledModulesImpl(const fs::path& path);
		void EnableModuleImpl(const fs::path& path);
		void LoadModulesImpl();
		void ReloadAllModulesImpl();
		void RegisterLibraryImpl(LuaLibrary* library);
		void RegisterLibrariesImpl(sol::state& L);
		void UpdateImpl();

	public:
		struct DisabledModule
		{
			std::string m_Name;
			fs::path m_Path;
		};

		static void Init()
		{
			GetInstance().InitImpl();
		}

		static void Destroy()
		{
			GetInstance().DestroyImpl();
		}

		static void Update()
		{
			GetInstance().UpdateImpl();
		}

		static void RegisterLibrary(LuaLibrary* library)
		{
			GetInstance().RegisterLibraryImpl(library);
		}

		static void RegisterLibraries(sol::state& L)
		{
			GetInstance().RegisterLibrariesImpl(L);
		}

		static void LoadModule(const fs::path& modulePath)
		{
			GetInstance().LoadModuleImpl(modulePath);
		}

		static void EnableModule(const fs::path& modulePath)
		{
			GetInstance().EnableModuleImpl(modulePath);
		}

		static void ReloadAllModules()
		{
			GetInstance().m_ShouldReload.store(true);
		}

		static std::vector<std::shared_ptr<LuaModule>>& GetModules()
		{
			return GetInstance().m_Modules;
		}

		static std::vector<DisabledModule>& GetDisabledModules()
		{
			return GetInstance().m_DisabledModules;
		}

		template<eMenuEvent menuEvent_, typename Return = void, typename... Args>
		static inline std::conditional_t<std::is_void_v<Return>, void, std::optional<Return>> DispatchMenuEvent(Args&&... args)
		{
			std::lock_guard guard(GetInstance().m_LoadedModulesMutex);
			for (auto& m : GetInstance().m_Modules)
			{
				if (auto vec = m->m_MenuEventCallbacks.find(menuEvent_); vec != m->m_MenuEventCallbacks.end())
				{
					for (auto& cb : vec->second)
					{
						sol::protected_function_result result = cb(args...);
						if (!result.valid())
						{
							sol::error e = result;
							LOG(WARNING) << e.what();
							continue;
						}

						if constexpr (!std::is_void_v<Return>)
						{
							if (result.return_count() == 0)
								continue;

							if (!result[0].is<Return>())
								continue;

							return result[0].get<Return>();
						}
					}
				}
			}

			if constexpr (!std::is_void_v<Return>)
				return std::nullopt;
		}

	private:
		void InitImpl();
		void DestroyImpl();

		fs::path m_PluginsDir{};

		std::atomic_bool m_Initialized{false};
		std::atomic_bool m_ShouldReload{false};

		std::mutex m_LoadedModulesMutex{};
		std::mutex m_DisabledModulesMutex{};

		std::vector<std::shared_ptr<LuaModule>> m_Modules{};
		std::queue<fs::path> m_LoadQueue{};
		std::vector<DisabledModule> m_DisabledModules{};
		std::vector<LuaLibrary*> m_Libraries{};

		std::chrono::time_point<std::chrono::steady_clock> m_LastReload{};
	};
}
