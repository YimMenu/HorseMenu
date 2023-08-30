#include "BoolCommand.hpp"

namespace YimMenu
{
	BoolCommand::BoolCommand(std::string name, std::string label, std::string description) :
	    Command(name, label, description, 0)
	{
	}

	void BoolCommand::OnCall()
	{
		SetState(!m_State);
	}

	bool BoolCommand::GetState()
	{
		return m_State;
	}

	void BoolCommand::SetState(bool state)
	{
		if (state && !m_State)
			OnEnable();
		else if (!state && m_State)
			OnDisable();

		m_State = state;
	}
}