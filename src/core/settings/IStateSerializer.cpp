#include "IStateSerializer.hpp"
#include "Settings.hpp"

namespace Terminus
{
	IStateSerializer::IStateSerializer(const std::string& name) :
	    m_SerComponentName(name),
	    m_IsDirty(false)
	{
		Settings::AddComponent(this);
	}
}