#include "ColorCommand.hpp"
#include "game/backend/FiberPool.hpp" // TODO: game import in core

namespace YimMenu
{
	void ColorCommand::OnCall()
	{
	}

	void ColorCommand::SaveState(nlohmann::json& value)
	{
		value = {m_ColorState.x, m_ColorState.y, m_ColorState.z, m_ColorState.w};
	}

	void ColorCommand::LoadState(nlohmann::json& value)
	{
		if (value.is_array() && value.size() == 4)
		{
			m_ColorState = ImVec4(value[0], value[1], value[2], value[3]);
		}
		else
		{
			m_ColorState = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		}
	}

	ColorCommand::ColorCommand(std::string name, std::string label, std::string description, ImVec4 color) :
	    Command(name, label, description, 0),
	    m_ColorState(color)
	{
	}

	ImVec4 ColorCommand::GetState()
	{
		return m_ColorState;
	}

	void ColorCommand::SetColorState(ImVec4 state)
	{
		FiberPool::Push([this] {
			OnChange();
		});
		m_ColorState = state;
		MarkDirty();
	}
}