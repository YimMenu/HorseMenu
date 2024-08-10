#include "BytePatch.hpp"

namespace YimMenu
{
	BytePatch::~BytePatch()
	{
		Restore();
	}

	void BytePatch::Apply() const
	{
		std::copy_n(m_Patch.get(), m_Size, reinterpret_cast<std::byte*>(m_Address));
	}

	void BytePatch::Restore() const
	{
		std::copy_n(m_Original.get(), m_Size, reinterpret_cast<std::byte*>(m_Address));
	}

	bool operator==(const std::unique_ptr<BytePatch>& a, const BytePatch* b)
	{
		return a->m_Address == b->m_Address;
	}

	BytePatch::operator bool()
	{
		return m_Active;
	}
}