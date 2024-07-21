#include "IntCommand.hpp"
#include "game/backend/FiberPool.hpp" // TODO: game import in core

namespace YimMenu
{
	void IntCommand::OnCall()
	{
	}

	void IntCommand::SaveState(nlohmann::json& value)
	{
		value = m_State;
	}

	void IntCommand::LoadState(nlohmann::json& value)
	{
		m_State = value;
	}

	IntCommand::IntCommand(std::string name, std::string label, std::string description, std::optional<int> min, std::optional<int> max, int def_val) :
	    Command(name, label, description, 0),
	    m_Min(min),
	    m_Max(max),
	    m_State(def_val)
	{
	}

	int IntCommand::GetState()
	{
		return m_State;
	}

	void IntCommand::SetState(int state)
	{
		FiberPool::Push([this] {
			OnChange();
		});
		m_State = state;
		MarkDirty();
	}

	std::optional<int> IntCommand::GetMinimum()
	{
		return m_Min;
	}

	std::optional<int> IntCommand::GetMaximum()
	{
		return m_Max;
	}
}