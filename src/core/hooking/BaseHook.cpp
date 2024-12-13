#include "BaseHook.hpp"

#include <MinHook.h>

namespace YimMenu
{
	BaseHook::BaseHook(const std::string_view name) :
	    m_Name(name),
	    m_Enabled(false)
	{
		m_Hooks.emplace_back(this);
	}

	std::vector<BaseHook*>& BaseHook::Hooks()
	{
		return m_Hooks;
	}

	bool BaseHook::EnableAll()
	{
		bool status = true;
		for (auto hook : m_Hooks)
		{
			status = hook->Enable() && status;
		}
		return status;
	}

	bool BaseHook::DisableAll()
	{
		bool status = true;
		for (auto hook : m_Hooks)
		{
			status = hook->Disable() && status;
		}
		return status;
	}
}