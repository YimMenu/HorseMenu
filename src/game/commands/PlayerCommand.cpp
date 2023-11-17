#include "PlayerCommand.hpp"

#include "game/backend/Players.hpp"

namespace YimMenu
{
	PlayerAllCommand::PlayerAllCommand(std::string name, std::string label, std::string description, int num_args, PlayerCommand* parent) :
	    Command(name + "all", label, description, num_args),
	    m_PlayerCommand(parent)
	{
	}

	void PlayerAllCommand::OnCall()
	{
		for (auto& p : Players::GetPlayers())
			m_PlayerCommand->Call(p.second);
	}

	PlayerCommand::PlayerCommand(std::string name, std::string label, std::string description, int num_args, bool all_version) :
	    Command::Command(name, label, description, num_args + 1)
	{
		if (all_version)
			m_AllCommand = std::make_unique<PlayerAllCommand>(name, label, description, num_args, this);
	}

	void PlayerCommand::OnCall()
	{
		LOG(WARNING) << GetName() << " requires a player argument";
	}

	void PlayerCommand::Call(Player target)
	{
		OnCall(target);
	}
}