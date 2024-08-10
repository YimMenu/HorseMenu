#include "IStateSerializer.hpp"
#include "Settings.hpp"

namespace YimMenu
{
	IStateSerializer::IStateSerializer(const std::string& name) :
	    m_SerComponentName(name),
	    m_IsDirty(false)
	{
		Settings::AddComponent(this);
	}
}