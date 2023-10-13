#pragma once
#include "util/Joaat.hpp"
#include "core/settings/IStateSerializer.hpp"

namespace YimMenu
{
	class Command;
	class LoopedCommand;

	class Commands : 
		private IStateSerializer
	{
	private:
		std::unordered_map<joaat_t, Command*> m_Commands;
		std::vector<LoopedCommand*> m_LoopedCommands;
		Commands();

	public:
		static void AddCommand(Command* command)
		{
			GetInstance().AddCommandImpl(command);
		}

		static void AddLoopedCommand(LoopedCommand* command)
		{
			GetInstance().AddLoopedCommandImpl(command);
		
		}

		static void RunLoopedCommands()
		{
			GetInstance().RunLoopedCommandsImpl();
		}

		template<typename T = Command>
		static T* GetCommand(joaat_t hash)
		{
			return reinterpret_cast<T*>(GetInstance().GetCommandImpl(hash));
		}

		static std::unordered_map<joaat_t, Command*> GetCommands()
		{
			return GetInstance().m_Commands;
		};
		
		static std::vector<LoopedCommand*> GetLoopedCommands()
		{
			return GetInstance().m_LoopedCommands;
		}

		static void MarkDirty()
		{
			GetInstance().MarkStateDirty();
		}
		
		static void Shutdown()
		{
			GetInstance().ShutdownImpl();
		}

	private:
		void AddCommandImpl(Command* command);
		void AddLoopedCommandImpl(LoopedCommand* command);
		void RunLoopedCommandsImpl();
		Command* GetCommandImpl(joaat_t hash);
		virtual void SaveStateImpl(nlohmann::json& state) override;
		virtual void LoadStateImpl(nlohmann::json& state) override;
		void ShutdownImpl();

		static Commands& GetInstance()
		{
			static Commands instance{};
			return instance;
		}
	};
}