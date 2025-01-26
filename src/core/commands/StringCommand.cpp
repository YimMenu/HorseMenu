#include "StringCommand.hpp"

namespace YimMenu
{
	void StringCommand::OnCall()
	{
	}

	void StringCommand::SaveState(nlohmann::json& value)
	{
		value = m_StringValue;
	}

	void StringCommand::LoadState(nlohmann::json& value)
	{
		m_StringValue = value.get<std::string>();
	}

	StringCommand::StringCommand(std::string name, std::string label, std::string description, std::string defaultValue) :
	    Command(name, label, description, 0),
	    m_StringValue(defaultValue)
	{
	}

	std::string StringCommand::GetString() const
	{
		return m_StringValue;
	}

	void StringCommand::SetStringValue(const std::string& value)
	{
		m_StringValue = value;
		OnChange();
		MarkDirty();
	}
}
