#include "Commands.hpp"
#include "Command.hpp"
#include "LoopedCommand.hpp"

namespace YimMenu
{
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
}