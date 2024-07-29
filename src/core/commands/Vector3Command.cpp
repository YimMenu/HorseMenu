#include "Vector3Command.hpp"
#include "game/backend/FiberPool.hpp" // TODO: game import in core

namespace YimMenu
{
	void Vector3Command::OnCall()
	{
	}

	void Vector3Command::SaveState(nlohmann::json& value)
	{
		value = nlohmann::json::object();
		value["x"] = m_State.x;
		value["y"] = m_State.y;
		value["z"] = m_State.z;
	}

	void Vector3Command::LoadState(nlohmann::json& value)
	{
		if (value.is_object())
		{
			m_State.x = value["x"];
			m_State.y = value["y"];
			m_State.z = value["z"];
		}
	}

	Vector3Command::Vector3Command(std::string name, std::string label, std::string description, rage::fvector3 def_val) :
	    Command(name, label, description, 0),
	    m_State(def_val)
	{
	}

	rage::fvector3 Vector3Command::GetState()
	{
		return m_State;
	}

	void Vector3Command::SetState(const rage::fvector3& state)
	{
		FiberPool::Push([this] {
			OnChange();
		});
		m_State = state;
		MarkDirty();
	}
}