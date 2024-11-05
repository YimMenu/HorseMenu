#include "ColorCommand.hpp"
#include "game/backend/FiberPool.hpp" // TODO: game import in core

namespace YimMenu
{
	void ColorCommand::OnCall()
	{
	}

	void ColorCommand::SaveState(nlohmann::json& value)
	{
		value      = nlohmann::json::object();
		value["r"] = m_State.x;
		value["g"] = m_State.y;
		value["b"] = m_State.z;
		value["a"] = m_State.w;
	}

	void ColorCommand::LoadState(nlohmann::json& value)
	{
		if (value.is_object())
		{
			m_State.x = value["r"];
			m_State.y = value["g"];
			m_State.z = value["b"];
			m_State.w = value["a"];
		}
		else if (value.is_array())
		{
			auto arr = value.get<std::array<float, 4>>();
			m_State.x = arr[0];
			m_State.y = arr[1];
			m_State.z = arr[2];
			m_State.w = arr[3];
		}
	}

	ColorCommand::ColorCommand(std::string name, std::string label, std::string description, ImVec4 color) :
	    Command(name, label, description, 0),
	    m_State(color)
	{
	}

	ImVec4 ColorCommand::GetState()
	{
		return m_State;
	}

	void ColorCommand::SetState(ImVec4 state)
	{
		if (m_State != state)
		{
			FiberPool::Push([this] {
				OnChange();
			});
			m_State = state;
			MarkDirty();
		}
	}
}