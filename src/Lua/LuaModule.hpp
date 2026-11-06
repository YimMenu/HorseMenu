#pragma once

#include <sol/sol.hpp>
#include "core/memory/BytePatch.hpp"
#include "LuaMenuEvent.hpp"


namespace Terminus::LuaJIT
{
	class LuaModule
	{
	public:
		LuaModule(const fs::path& root);
		~LuaModule();

		enum eLuaLoadState : uint8_t
		{
			NONE,
			RUNNING,
			SUSPENDED,
			WANTS_RELOAD,
			WANTS_UNLOAD,
			WANTS_DISABLE, // WANTS_UNLOAD + move to the disabled folder
		};

	private:
		struct LuaTask
		{
			sol::thread m_Thread{};
			sol::coroutine m_Coroutine{};
			std::chrono::steady_clock::time_point m_NextRun{};
		};

		struct LuaModuleMetadata
		{
			std::string m_Name{};
			std::string m_Description{};

			std::string m_Author  = "Unknown";
			std::string m_Version = "1.0.0.0";
		};

	public:
		bool Load();

		void Reload();
		void Unload();
		void Disable();
		void Suspend(std::optional<std::string> errorMsg = std::nullopt);
		void Tick();
		void OnFileEdit();
		void RegisterTask(sol::protected_function func, std::chrono::milliseconds delayMs = 0ms);
		void SandboxAPI(const fs::path& pluginsPath);

		std::string LuaFormatString(const std::string& fmt, sol::variadic_args args);

		const bool IsSafeToUnload() const noexcept;
		const bool IsRunningTasks() const noexcept;

		const eLuaLoadState GetLoadState() const noexcept;

		const std::string GetErrorMsg() const;

		lua_State* GetLuaState();

		std::string_view GetName() const noexcept;

		fs::path GetRoot() const noexcept;

		LuaModuleMetadata GetMetadata();

		sol::protected_function m_GuiCallback{};

		bool m_UnloadFromCode{false}; // just for UnloadThisModule

		std::vector<std::shared_ptr<BytePatch>> m_BytePatches{};
		std::vector<void*> m_MemAllocs;
		std::unordered_map<eMenuEvent, std::vector<sol::protected_function>> m_MenuEventCallbacks{};

	private:
		LuaModuleMetadata m_Metadata;
		std::string m_LastError{};

		fs::path m_Root{};
		fs::path m_Entry{};

		sol::state m_LuaState{};

		eLuaLoadState m_LoadState{NONE};

		std::mutex m_TaskMutex{};

		std::vector<LuaTask> m_Tasks{};

		std::atomic_bool m_IsRunningTasks{false};

		std::chrono::time_point<std::chrono::steady_clock> m_LastAutoReload{};
		std::chrono::time_point<std::chrono::file_clock> m_LastModified{};

		sol::protected_function m_LuaIoOpen{};
		sol::protected_function m_LuaStrFmt{};

		void SetRequireFolder(const fs::path& pluginsPath);
		void SandboxOsLib();
		void SandboxIoLib();

		static LuaModuleMetadata GetMetadata(const fs::path& root);
	};

	inline LuaModule* GetModuleFromLuaState(lua_State* L, std::optional<std::string_view> errorMsg = std::nullopt)
	{
		auto sv  = sol::state_view(L);
		auto ptr = sv["this*"];
		if (!ptr.is<void*>())
		{
			if (errorMsg.has_value())
				throw sol::error(errorMsg.value().data());
			else
				LOG(FATAL) << "Module pointer is null!";

			return nullptr;
		}

		return static_cast<LuaModule*>(ptr.get<void*>());
	};

	inline std::string LuaStringFormat(lua_State* L, const std::string& fmt, sol::variadic_args args)
	{
		if (auto mod = GetModuleFromLuaState(L))
			return mod->LuaFormatString(fmt, args);

		return "<format-error!>";
	}
}
