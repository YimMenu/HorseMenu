#include "ListCommand.hpp" 
#include "game/backend/FiberPool.hpp" // TODO: game import in core

namespace YimMenu
{
	void ListCommand::OnCall()
	{
	}

	void ListCommand::SaveState(nlohmann::json& value)
	{
		value = m_State;
	}

	void ListCommand::LoadState(nlohmann::json& value)
	{
		m_State = value;
	}

	ListCommand::ListCommand(std::string name, std::string label, std::string description, std::vector<std::pair<int, const char*>> list, int def_val) :
	    Command(name, label, description, 0),
	    m_List(list),
	    m_State(def_val)
	{
	}

	int ListCommand::GetState()
	{
		return m_State;
	}

	void ListCommand::SetState(int state)
	{
		FiberPool::Push([this] {
			OnChange();
		});
		m_State = state;
		MarkDirty();
	}

	std::vector<std::pair<int, const char*>>& ListCommand::GetList()
	{
		return m_List;
	}
}