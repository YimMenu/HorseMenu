#include "ScriptPatcherService.hpp"

#include "ScriptData.hpp"
#include "ScriptPatch.hpp"
#include "util/Joaat.hpp"

#include <script/scrProgram.hpp>

namespace YimMenu
{
	ScriptPatcherService::ScriptPatcherService()
	{
		g_ScriptPatcherService = this;
	}

	ScriptPatcherService::~ScriptPatcherService()
	{
		m_ScriptData.clear();
		m_ScriptPatches.clear();
		g_ScriptPatcherService = nullptr;
	}

	ScriptData* ScriptPatcherService::GetDataForScript(joaat_t script)
	{
		for (auto& p : m_ScriptData)
		{
			if (p.first == script)
			{
				return p.second.get();
			}
		}

		return nullptr;
	}

	bool ScriptPatcherService::DoesScriptHavePatches(joaat_t script)
	{
		for (auto& p : m_ScriptPatches)
		{
			if (p.GetScript() == script)
			{
				return true;
			}
		}

		return false;
	}

	void ScriptPatcherService::CreateDataForScript(rage::scrProgram* program)
	{
		auto pages = new uint8_t*[program->GetNumCodePages()];

		for (auto i = 0u; i < program->GetNumCodePages(); i++)
		{
			pages[i] = new uint8_t[program->GetCodePageSize(i)];
			std::memcpy(pages[i], program->GetCodePage(i), program->GetCodePageSize(i));
		}

		m_ScriptData.emplace(program->m_NameHash, std::make_unique<ScriptData>(program->m_CodeSize, pages, program->GetNumCodePages()));
	}

	void ScriptPatcherService::UpdateAllPatchesForScript(joaat_t script)
	{
		auto data = GetDataForScript(script);

		for (auto& p : m_ScriptPatches)
		{
			if (p.GetScript() == script)
				p.Update(data);
		}
	}

	void ScriptPatcherService::AddPatch(ScriptPatch&& patch)
	{
		m_ScriptPatches.push_back(std::move(patch));
	}

	void ScriptPatcherService::OnScriptLoad(rage::scrProgram* program)
	{
		if (GetDataForScript(program->m_NameHash) == nullptr && DoesScriptHavePatches(program->m_NameHash))
		{
			CreateDataForScript(program);
			UpdateAllPatchesForScript(program->m_NameHash);
		}
	}

	uint8_t** ScriptPatcherService::GetScriptBytecode(joaat_t script)
	{
		if (auto data = GetDataForScript(script))
			return data->m_ByteCode;

		return nullptr;
	}

	void ScriptPatcherService::Update()
	{
		for (auto& p : m_ScriptPatches)
		{
			auto data = GetDataForScript(p.GetScript());
			if (data)
			{
				p.Update(data);
			}
		}
	}
}