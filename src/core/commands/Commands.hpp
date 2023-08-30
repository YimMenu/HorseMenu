#pragma once
#include "util/Joaat.hpp"

namespace YimMenu
{
	class Command;
	class LoopedCommand;

	class Commands
	{
	private:
		std::unordered_map<joaat_t, Command*> m_Commands;
		std::vector<LoopedCommand*> m_LoopedCommands;
		Commands(){};

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

	private:
		void AddCommandImpl(Command* command);
		void AddLoopedCommandImpl(LoopedCommand* command);
		void RunLoopedCommandsImpl();
		Command* GetCommandImpl(joaat_t hash);

		static Commands& GetInstance()
		{
			static Commands instance{};
			return instance;
		}
	};
}