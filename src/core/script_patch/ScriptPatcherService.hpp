#pragma once
#include "ScriptData.hpp"
#include "ScriptPatch.hpp"
#include "core/memory/Pattern.hpp"
#include "util/Joaat.hpp"

#include <script/scrProgram.hpp>


namespace YimMenu
{
	class ScriptPatcherService
	{
		std::vector<ScriptPatch> m_ScriptPatches;
		std::unordered_map<joaat_t, std::unique_ptr<ScriptData>> m_ScriptData;
		ScriptData* GetDataForScript(joaat_t script);
		bool DoesScriptHavePatches(joaat_t script);
		void CreateDataForScript(rage::scrProgram* program);
		void UpdateAllPatchesForScript(joaat_t script);

	public:
		ScriptPatcherService();
		~ScriptPatcherService();

		void AddPatch(ScriptPatch&& patch);
		void OnScriptLoad(rage::scrProgram* program);
		uint8_t** GetScriptBytecode(joaat_t script);
		void Update();
	};

	inline ScriptPatcherService* g_ScriptPatcherService;
}