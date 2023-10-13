#include "IStateSerializer.hpp"
#include "Settings.hpp"

namespace YimMenu
{
	IStateSerializer::IStateSerializer(const std::string& name) :
	    m_SerComponentName(name),
	    m_IsDirty(false)
	{
		if (Settings::InitialLoadDone())
		{
			LOG(FATAL) << "Component initialized too late: " << name;
			LOG(FATAL) << "Attempting recovery";
			Settings::LoadComponent(this);
		}

		Settings::AddComponent(this);
	}
}