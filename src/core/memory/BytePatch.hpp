#pragma once

#include <memory>
#include <span>
#include <vector>

namespace YimMenu
{
	template<typename T>
	concept SpanCompatibleType = requires(T a) { std::span{a}; };

	class BytePatch
	{
	private:
		std::byte* m_Address;
		std::unique_ptr<std::byte[]> m_Patch;
		std::unique_ptr<std::byte[]> m_Original;
		std::size_t m_Size;
		bool m_Active;

	public:
		virtual ~BytePatch();

		void Apply() const;
		void Restore() const;

	private:
		template<typename TAddr>
		BytePatch(TAddr addr, std::remove_pointer_t<std::remove_reference_t<TAddr>> value);

		template<typename TAddr, typename T, std::size_t N>
		BytePatch(TAddr addr, std::span<T, N> span);

		friend bool operator==(const std::unique_ptr<BytePatch>& a, const BytePatch* b);
		inline operator bool();
	};

	template<typename TAddr>
	inline BytePatch::BytePatch(TAddr addr, std::remove_pointer_t<std::remove_reference_t<TAddr>> value) :
	    m_Address(addr)
	{
		m_Size = sizeof(std::remove_pointer_t<std::remove_reference_t<TAddr>>);

		m_Original = std::make_unique<std::byte[]>(m_Size);
		std::copy_n(m_Address, m_Size, m_Original.get());

		m_Patch = std::make_unique<std::byte[]>(m_Size);
		std::copy_n(&value, m_Size, m_Patch.get());

		m_Active = true;
	}

	template<typename TAddr, typename T, std::size_t N>
	inline BytePatch::BytePatch(TAddr addr, std::span<T, N> span) :
	    m_Address((std::byte*)addr)
	{
		m_Size = span.size();

		m_Original = std::make_unique<std::byte[]>(m_Size);
		std::copy_n(m_Address, m_Size, m_Original.get());

		m_Patch = std::make_unique<std::byte[]>(m_Size);
		std::copy(span.begin(), span.end(), m_Patch.get());

		m_Active = true;
	}
}