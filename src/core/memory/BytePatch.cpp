#include "BytePatch.hpp"

namespace Terminus
{
	BytePatch::BytePatch(void* addr, std::span<uint8_t const> const bytes) :
	    m_Address(addr),
	    m_Applied(false)
	{
		m_Size = bytes.size();

		m_Original = std::make_unique<uint8_t[]>(m_Size);
		memcpy(m_Original.get(), m_Address, m_Size);

		m_Patch = std::make_unique<uint8_t[]>(m_Size);
		for (size_t i = 0; i < m_Size; i++)
			m_Patch[i] = bytes[i];
	}

	BytePatch::~BytePatch()
	{
		Restore();
	}

	void BytePatch::Apply()
	{
		if (m_Applied)
			return;

		unsigned long old_protect;
		unsigned long temp;
		VirtualProtect(m_Address, m_Size, PAGE_EXECUTE_READWRITE, &old_protect);
		memcpy(m_Address, m_Patch.get(), m_Size);
		VirtualProtect(m_Address, m_Size, old_protect, &temp);
		m_Applied = true;
	}

	void BytePatch::Restore()
	{
		if (!m_Applied)
			return;

		unsigned long old_protect;
		unsigned long temp;
		VirtualProtect(m_Address, m_Size, PAGE_EXECUTE_READWRITE, &old_protect);
		memcpy(m_Address, m_Original.get(), m_Size);
		VirtualProtect(m_Address, m_Size, old_protect, &temp);
		m_Applied = false;
	}

	bool operator==(const std::unique_ptr<BytePatch>& a, const BytePatch* b)
	{
		return a->m_Address == b->m_Address;
	}
}