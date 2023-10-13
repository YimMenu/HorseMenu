#include "util/Joaat.hpp"
#include "Command.hpp"
#include "Commands.hpp"

namespace YimMenu
{
	Command::Command(std::string name, std::string label, std::string description, int num_args) :
	    m_Name(name),
	    m_Label(label),
	    m_Description(description),
	    m_NumArgs(num_args),
	    m_Hash(Joaat(name))
	{
		Commands::AddCommand(this);
	}

	void Command::Call()
	{
		OnCall();
	}

	void Command::MarkDirty()
	{
		Commands::MarkDirty();
	}
}