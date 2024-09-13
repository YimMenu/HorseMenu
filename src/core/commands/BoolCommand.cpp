#include "BoolCommand.hpp"
#include "game/backend/FiberPool.hpp" // TODO: game import in core
#include "Commands.hpp"

namespace YimMenu
{
	BoolCommand::BoolCommand(std::string name, std::string label, std::string description, bool def_value) :
	    Command(name, label, description, 0),
	    m_State(def_value)
	{
		Commands::AddBoolCommand(this);
	}

	void BoolCommand::OnCall()
	{
		SetState(!m_State);
	}

	void BoolCommand::SaveState(nlohmann::json& value)
	{
		value = m_State;
	}

	void BoolCommand::LoadState(nlohmann::json& value)
	{
		m_State = value;
	}

	bool BoolCommand::GetState()
	{
		return m_State;
	}

	void BoolCommand::SetState(bool state)
	{
		if (state && !m_State)
			FiberPool::Push([this] {
				OnEnable();
			});
		else if (!state && m_State)
			FiberPool::Push([this] {
				OnDisable();
			});

		m_State = state;
		MarkDirty();
	}

	void BoolCommand::Initialize()
	{
		OnEnable();
	}

	void BoolCommand::Shutdown()
	{
		OnDisable();
	}
}