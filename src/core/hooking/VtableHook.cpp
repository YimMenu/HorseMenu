#include "VtableHook.hpp"


namespace YimMenu
{
	VtableHook::VtableHook(const std::string_view name, void** vft, std::size_t numFuncs) :
	    BaseHook::BaseHook(name),
	    m_NumFuncs(numFuncs),
	    m_Table(vft),
	    m_BackupTable(std::make_unique<void*[]>(m_NumFuncs)),
	    m_HookTable(std::make_unique<void*[]>(m_NumFuncs))
	{
		std::memcpy(m_BackupTable.get(), m_Table, m_NumFuncs * sizeof(void*));
		std::memcpy(m_HookTable.get(), m_Table, m_NumFuncs * sizeof(void*));
	}

	VtableHook::~VtableHook()
	{
		Disable();
	}

	void VtableHook::Hook(std::size_t index, void* func)
	{
		m_HookTable[index] = func;
	}

	void VtableHook::Unhook(std::size_t index)
	{
		m_HookTable[index] = m_BackupTable[index];
	}

	bool VtableHook::Enable()
	{
		std::memcpy(m_Table, m_HookTable.get(), m_NumFuncs * sizeof(void*));
		return true;
	}

	bool VtableHook::Disable()
	{
		std::memcpy(m_Table, m_BackupTable.get(), m_NumFuncs * sizeof(void*));
		return true;
	}
}