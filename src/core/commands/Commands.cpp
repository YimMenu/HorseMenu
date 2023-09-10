#include "Commands.hpp"
#include "Command.hpp"
#include "LoopedCommand.hpp"

namespace YimMenu
{
	Commands::Commands() :
	    IStateSerializer("commands")
	{
	}

	void Commands::AddCommandImpl(Command* command)
	{
		m_Commands.insert({command->GetHash(), command});
	}

	void Commands::AddLoopedCommandImpl(LoopedCommand* command)
	{
		m_LoopedCommands.push_back(command);
	}

	void Commands::RunLoopedCommandsImpl()
	{
		for (auto& command : m_LoopedCommands)
			if (command->GetState())
				command->Tick();
	}

	Command* Commands::GetCommandImpl(joaat_t hash)
	{
		if (auto it = m_Commands.find(hash); it != m_Commands.end())
			return it->second;
		return nullptr;
	}

	void Commands::SaveStateImpl(nlohmann::json& state)
	{
		for (auto& command : m_Commands)
		{
			if (!state.contains(command.second->GetName()))
				state[command.second->GetName()] = nlohmann::json::object();

			command.second->SaveState(state[command.second->GetName()]);
		}
	}

	void Commands::LoadStateImpl(nlohmann::json& state)
	{
		for (auto& command : m_Commands)
		{
			if (state.contains(command.second->GetName()))
				command.second->LoadState(state[command.second->GetName()]);
		}
	}

	void Commands::ShutdownImpl()
	{
		for (auto& command : m_LoopedCommands)
			if (command->GetState())
				command->Shutdown();
	}
}