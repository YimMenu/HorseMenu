#pragma once
#include "core/memory/Pattern.hpp"
#include "util/Joaat.hpp"

namespace rage
{
	class scrProgram;
}

namespace YimMenu
{
	class ScriptPatches
	{
	public:
		class Data
		{
			std::uint8_t** m_Data;
			std::uint32_t m_Pages;
			std::uint32_t m_Size;

		public:
			inline std::uint8_t** GetData()
			{
				return m_Data;
			}

			inline std::uint32_t GetSize()
			{
				return m_Size;
			}

			Data(rage::scrProgram* program);
			~Data();
		};

		class Patch
		{
			std::vector<uint8_t> m_OriginalBytes;
			std::vector<uint8_t> m_PatchedBytes;
			std::optional<int32_t> m_Pc;
			SimplePattern m_Pattern;
			int32_t m_Offset;
			joaat_t m_ScriptHash;
			bool m_Enabled;
			bool m_IsMP;

			std::optional<int32_t> GetPC();
			void Apply();
			void Restore();

		public:
			Patch(joaat_t script, bool is_mp, SimplePattern pattern, int32_t offset, std::vector<uint8_t> patch);
			void Enable();
			void Disable();
			void Update();
			bool InScope(joaat_t hash);
		};

		static std::shared_ptr<Patch> AddPatch(joaat_t script, bool is_mp, const std::string& pattern, int32_t offset, std::vector<uint8_t> patch)
		{
			return GetInstance().AddPatchImpl(script, is_mp, pattern, offset, patch);
		}

		static void RegisterProgram(rage::scrProgram* program)
		{
			GetInstance().RegisterProgramImpl(program);
		}

		static void UnregisterProgram(rage::scrProgram* program)
		{
			GetInstance().UnregisterProgramImpl(program);
		}

		static void OnScriptVMEnter(rage::scrProgram* program)
		{
			GetInstance().OnScriptVMEnterImpl(program);
		}

		static void OnScriptVMLeave(rage::scrProgram* program)
		{
			GetInstance().OnScriptVMLeaveImpl(program);
		}

	private:
		ScriptPatches();
		~ScriptPatches();

		static ScriptPatches& GetInstance()
		{
			static ScriptPatches Instance;
			return Instance;
		}

		std::shared_ptr<Patch> AddPatchImpl(joaat_t script, bool is_mp, const std::string& pattern, int32_t offset, std::vector<uint8_t> patch);
		void RegisterProgramImpl(rage::scrProgram* program);
		void UnregisterProgramImpl(rage::scrProgram* program);
		void OnScriptVMEnterImpl(rage::scrProgram* program);
		void OnScriptVMLeaveImpl(rage::scrProgram* program);
		Data* GetDataImpl(joaat_t script);
		void UpdateScriptMPStatus();

		std::vector<std::shared_ptr<Patch>> m_Patches;
		std::unordered_map<joaat_t, std::unique_ptr<Data>> m_Datas;
		std::uint8_t** m_CurrentlyReplacedBytecode;
		bool m_UsingMPScripts;
	};
}