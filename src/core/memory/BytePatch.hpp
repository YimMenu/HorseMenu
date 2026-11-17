#pragma once

#include <memory>
#include <span>
#include <cstddef>
#include <type_traits>

namespace Terminus
{
	template<typename T>
	concept SpanCompatibleType = requires(T a) { std::span{a}; };

	class BytePatch
	{
	private:
		void* m_Address;
		std::unique_ptr<uint8_t[]> m_Patch;
		std::unique_ptr<uint8_t[]> m_Original;
		std::size_t m_Size;
		bool m_Applied;

	public:
		virtual ~BytePatch();

		void Apply();
		void Restore();

		explicit operator bool()
		{
			return m_Applied;
		}

		template<typename TAddr>
		BytePatch(TAddr addr, std::remove_pointer_t<std::remove_reference_t<TAddr>> value);

		BytePatch(void* addr, std::span<uint8_t const> const bytes);

		friend bool operator==(const std::unique_ptr<BytePatch>& a, const BytePatch* b);
	};

	template<typename TAddr>
	inline BytePatch::BytePatch(TAddr addr, std::remove_pointer_t<std::remove_reference_t<TAddr>> value) :
	    m_Address(addr)
	{
		m_Size = sizeof(std::remove_pointer_t<std::remove_reference_t<TAddr>>);

		m_Original = std::make_unique<uint8_t[]>(m_Size);
		memcpy(m_Original.get(), m_Address, m_Size);

		m_Patch = std::make_unique<uint8_t[]>(m_Size);
		memcpy(m_Patch.get(), &value, m_Size);

		m_Applied = true;
	}
}