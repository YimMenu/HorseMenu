#include "LuaModule.hpp"
#include "LuaMgr.hpp"


namespace Terminus::LuaJIT
{
	// https://sol2.readthedocs.io/en/latest/exceptions.html
	static int ExceptionHandler(lua_State* L, sol::optional<const std::exception&> maybe_exception, sol::string_view description)
	{
		if (maybe_exception)
		{
			const std::exception& e = *maybe_exception;
			LOG(FATAL) << e.what();
		}
		else
		{
			LOG(FATAL) << description;
		}

		return sol::stack::push(L, description);
	}

	static inline void PanicHandler(sol::optional<std::string> maybe_msg)
	{
		LOG(FATAL) << "Lua is in a panic state and will now abort the application";
		if (maybe_msg)
		{
			const std::string& msg = maybe_msg.value();
			LOG(FATAL) << "error message: " << msg;
		}
	}

	static int TracebackErrorHandler(lua_State* L)
	{
		std::string msg = "An unknown error has triggered the error handler";
		sol::optional<sol::string_view> maybetopmsg = sol::stack::unqualified_check_get<sol::string_view>(L, 1, &sol::no_panic);
		if (maybetopmsg)
		{
			const sol::string_view& topmsg = maybetopmsg.value();
			msg.assign(topmsg.data(), topmsg.size());
		}

		luaL_traceback(L, L, msg.c_str(), 1);
		sol::optional<sol::string_view> maybetraceback = sol::stack::unqualified_check_get<sol::string_view>(L, -1, &sol::no_panic);
		if (maybetraceback)
		{
			const sol::string_view& traceback = maybetraceback.value();
			msg.assign(traceback.data(), traceback.size());
		}

		LOG(FATAL) << msg;
		return sol::stack::push(L, msg);
	}

	template<size_t N>
	static constexpr auto DisabledLuaFunc(const char (&funcName)[N])
	{
		return [funcName](sol::this_state state, sol::variadic_args args)
		{
			sol::state_view L(state);
			luaL_error(L.lua_state(), std::format("Can not invoke '{}', a deleted function.", funcName).c_str());
		};
	}

	LuaModule::LuaModule(const fs::path& root) :
		m_LuaState(sol::state{}),
		m_Root(root),
		m_Entry(root / "main.lua")
	{
		m_LuaState.open_libraries(
		    sol::lib::base,
		    sol::lib::bit32,
		    sol::lib::coroutine,
		    sol::lib::ffi,
		    sol::lib::io,
		    sol::lib::jit,
		    sol::lib::math,
		    sol::lib::os,
		    sol::lib::package,
		    sol::lib::string,
		    sol::lib::table,
		    sol::lib::utf8);

		m_Metadata           = GetMetadata(root);
		m_LuaState["this*"]  = reinterpret_cast<void*>(this);
		m_LuaState["whodis"] = m_Metadata.m_Name;

		m_LuaState.set_exception_handler(ExceptionHandler);
		m_LuaState.set_panic(sol::c_call<decltype(&PanicHandler), &PanicHandler>);
		lua_CFunction traceback_function = sol::c_call<decltype(&TracebackErrorHandler), &TracebackErrorHandler>;
		sol::protected_function::set_default_handler(sol::object(m_LuaState.lua_state(), sol::in_place, traceback_function));

		std::error_code ec{};

		m_LastModified = fs::last_write_time(m_Entry, ec);
		auto strlib    = m_LuaState["string"];
		m_LuaStrFmt    = strlib["format"];

		LuaManager::RegisterLibraries(m_LuaState);
	}

	LuaModule::~LuaModule()
	{
		std::unique_lock lock(m_TaskMutex);
		m_Tasks.clear();
		m_MenuEventCallbacks.clear();
		m_GuiCallback = {};

		for (auto& patch : m_BytePatches)
			patch->Restore();

		for (auto mem : m_MemAllocs)
			delete[] mem;
	}

	LuaModule::LuaModuleMetadata LuaModule::GetMetadata(const fs::path& root)
	{
		std::error_code ec{};

		std::string fallback = root.filename().string();
		fs::path jsonPath    = root / "meta.json";
		if (!fs::exists(jsonPath, ec))
			return {.m_Name = fallback};

		try
		{
			nlohmann::json j;
			std::ifstream f(jsonPath);
			f >> j;
			return {
				j.value("name", fallback), 
				j.value("description", ""), 
				j.value("author", "Unknown"), 
				j.value("version", "1.0.0.0")
			};
		}
		catch (const std::exception&)
		{
			return {.m_Name = fallback};
		}
	}

	std::string LuaModule::LuaFormatString(const std::string& fmt, sol::variadic_args args)
	{
		if (!m_LuaStrFmt.valid())
			return fmt;

		auto res = m_LuaStrFmt(fmt, args);
		return res.valid() ? res.get<std::string>() : fmt;
	}

	bool LuaModule::Load()
	{
		auto res = m_LuaState.safe_script_file(m_Entry.string(), &sol::script_pass_on_error, sol::load_mode::text);
		if (!res.valid())
		{
			sol::error e = res;
			LOG(FATAL) << "Failed to load module '" << m_Metadata.m_Name << "' : " << e.what();
			Suspend(e.what());
			return false; // TODO
		}

		LOG(INFO) << "Loaded module " << m_Metadata.m_Name;
		m_LoadState = RUNNING;
		return true;
	}

	void LuaModule::Reload()
	{
		m_LoadState = WANTS_RELOAD;
	}

	void LuaModule::Unload()
	{
		m_LoadState = WANTS_UNLOAD;
	}

	void LuaModule::Suspend(std::optional<std::string> errorMsg)
	{
		m_LoadState = SUSPENDED;
		m_LastError = errorMsg.value_or("");
	}

	void LuaModule::Disable()
	{
		m_LoadState = WANTS_DISABLE;
	}

	const std::string LuaModule::GetErrorMsg() const
	{
		return m_LastError;
	}

	const bool LuaModule::IsSafeToUnload() const noexcept
	{
		return !m_IsRunningTasks;
	}

	lua_State* LuaModule::GetLuaState()
	{
		return m_LuaState.lua_state();
	}

	const LuaModule::eLuaLoadState LuaModule::GetLoadState() const noexcept
	{
		return m_LoadState;
	}

	std::string_view LuaModule::GetName() const noexcept
	{
		return m_Metadata.m_Name;
	}

	fs::path LuaModule::GetRoot() const noexcept
	{
		return m_Root;
	}

	LuaModule::LuaModuleMetadata LuaModule::GetMetadata()
	{
		return m_Metadata;
	}

	void LuaModule::SandboxOsLib()
	{
		auto os = m_LuaState["os"];
		sol::table sandboxedOs(m_LuaState, sol::create);

		sandboxedOs["clock"]    = os["clock"];
		sandboxedOs["date"]     = os["date"];
		sandboxedOs["difftime"] = os["difftime"];
		sandboxedOs["time"]     = os["time"];

		sandboxedOs["rename"] = [this](const std::string& oldname, const std::string& newname) -> sol::object
		{
			const auto oldPath = FileMgr::MakeAbsPath(m_Root, oldname);
			const auto newPath = FileMgr::MakeAbsPath(m_Root, newname);

			if (!oldPath || !newPath)
			{
				LOG(WARNING) << "os.rename is restricted to the module's root only.";
				return sol::make_object(m_LuaState, std::make_tuple(false, "Invalid file path."));
			}

			try
			{
				fs::rename(oldPath.value(), newPath.value());
				return sol::make_object(m_LuaState, true);
			}
			catch (const std::exception& e)
			{
				return sol::make_object(m_LuaState, std::make_tuple(false, e.what()));
			}
		};

		m_LuaState["os"] = sandboxedOs;
	}

	void LuaModule::SandboxIoLib()
	{
		auto ioLib  = m_LuaState["io"];
		m_LuaIoOpen = ioLib["open"];

		sol::table sandboxedIo(m_LuaState, sol::create);
		sandboxedIo["open"] = [this](const std::string& filename, const std::string& mode)
		{
			const auto absPath = FileMgr::MakeAbsPath(m_Root, filename);
			if (!absPath.has_value())
				return std::make_tuple(sol::reference(m_LuaState, sol::lua_nil), "io is restricted to the module's root only.");

			auto result = m_LuaIoOpen(absPath->u8string().c_str(), mode);
			if (!result.valid())
			{
				sol::error err = result;
				return std::make_tuple(sol::reference(m_LuaState, sol::lua_nil), err.what());
			}

			return std::make_tuple(result.get<sol::reference>(), "");
		};

		sandboxedIo["exists"] = [this](const std::string& filename) -> bool {
			const auto absPath = FileMgr::MakeAbsPath(m_Root, filename);
			if (!absPath)
			{
				LOG(FATAL) << "io is restricted to the module's root only.";
				return false;
			}

			std::error_code ec{};
			return fs::exists(*absPath, ec);
		};

		m_LuaState["io"] = sandboxedIo;
	}

	// https://github.com/Mr-X-GTA/YimMenu/blob/master/src/lua/lua_module.cpp#L175
	void LuaModule::SetRequireFolder(const fs::path& pluginsPath)
	{
		std::string searchPath = pluginsPath.string() + "/?.lua;";
		for (const auto& entry : std::filesystem::recursive_directory_iterator(pluginsPath, std::filesystem::directory_options::skip_permission_denied))
		{
			if (!entry.is_directory())
				continue;

			if (std::filesystem::relative(entry, pluginsPath).wstring().contains(L"disabled"))
				continue;

			searchPath += entry.path().string() + "/?.lua;";
		}

		searchPath.pop_back();
		m_LuaState["package"]["path"] = searchPath;
	}

	// https://github.com/Mr-X-GTA/YimMenu/blob/master/src/lua/lua_module.cpp#L321
	void LuaModule::SandboxAPI(const fs::path& pluginsPath)
	{
		m_LuaState["load"]       = DisabledLuaFunc("load");
		m_LuaState["loadstring"] = DisabledLuaFunc("loadstring");
		m_LuaState["loadfile"]   = DisabledLuaFunc("loadfile");
		m_LuaState["dofile"]     = DisabledLuaFunc("dofile");

		m_LuaState["package"]["loadlib"]      = DisabledLuaFunc("package.loadlib");
		m_LuaState["package"]["cpath"]        = "";
		m_LuaState["package"]["searchers"][3] = DisabledLuaFunc("package.searcher C");
		m_LuaState["package"]["searchers"][4] = DisabledLuaFunc("package.searcher Croot");

		SetRequireFolder(pluginsPath);
		SandboxIoLib();
		SandboxOsLib();
	}

	void LuaModule::OnFileEdit()
	{
		const auto now = std::chrono::steady_clock::now();
		if (now - m_LastAutoReload > 1s)
		{
			std::error_code ec{};
			if (m_LastModified < fs::last_write_time(m_Entry, ec))
			{
				m_LastModified = fs::last_write_time(m_Entry, ec);
				m_LoadState    = WANTS_RELOAD;
			}

			m_LastAutoReload = now;
		}
	}

	const bool LuaModule::IsRunningTasks() const noexcept
	{
		return m_IsRunningTasks;
	}

	void LuaModule::RegisterTask(sol::protected_function func, std::chrono::milliseconds delayMs)
	{
		std::unique_lock lock(m_TaskMutex);
		auto thread = sol::thread::create(m_LuaState);
		auto co     = sol::coroutine(m_LuaState, func);
		m_Tasks.push_back({std::move(thread), std::move(co), std::chrono::steady_clock::now() + delayMs});
	}

	void LuaModule::Tick()
	{
		if (m_UnloadFromCode)
		{
			m_UnloadFromCode = false;
			m_LoadState      = WANTS_UNLOAD;
			return;
		}

		if (!m_Tasks.empty() && m_LoadState == RUNNING)
		{
			const auto now = std::chrono::steady_clock::now();

			m_IsRunningTasks.store(true);
			std::scoped_lock lock(m_TaskMutex);

			for (auto it = m_Tasks.begin(); it != m_Tasks.end();)
			{
				if (!g_Running)
					break;

				if (now < it->m_NextRun)
				{
					++it;
					continue;
				}

				auto result = it->m_Coroutine();
				if (!result.valid())
				{
					sol::error e = result;
					Suspend(e.what());
					break;
				}

				if (!it->m_Coroutine.runnable())
				{
					it = m_Tasks.erase(it);
					continue;
				}

				const auto delay = result.return_count() > 0 ? result[0] : 0;
				it->m_NextRun = now + std::chrono::milliseconds(delay);
				++it;
			}

			m_IsRunningTasks.store(false);
		}
	}
}
