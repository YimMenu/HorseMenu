#include "FloatCommand.hpp"
#include "game/backend/FiberPool.hpp" // TODO: game import in core

namespace YimMenu
{
	void FloatCommand::OnCall()
	{
	}

	void FloatCommand::SaveState(nlohmann::json& value)
	{
		value = m_State;
	}

	void FloatCommand::LoadState(nlohmann::json& value)
	{
		m_State = value;
	}

	FloatCommand::FloatCommand(std::string name, std::string label, std::string description, std::optional<float> min, std::optional<float> max, float def_val) :
	    Command(name, label, description, 0),
	    m_Min(min),
	    m_Max(max),
	    m_State(def_val)
	{
	}

	float FloatCommand::GetState()
	{
		return m_State;
	}

	void FloatCommand::SetState(float state)
	{
		FiberPool::Push([this] {
			OnChange();
		});
		m_State = state;
		MarkDirty();
	}

	std::optional<float> FloatCommand::GetMinimum()
	{
		return m_Min;
	}

	std::optional<float> FloatCommand::GetMaximum()
	{
		return m_Max;
	}
}