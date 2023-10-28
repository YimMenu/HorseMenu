#pragma once
#include <rage/vector.hpp>

namespace YimMenu
{
	class Entity
	{
		void* m_Pointer;
		int m_Handle;

		void PopulatePointer();
		void PopulateHandle();

	public:

		constexpr Entity(void* pointer) :
			m_Pointer(pointer),
		    m_Handle(-1)
		{
		}

		constexpr Entity(int handle) :
		    m_Pointer(nullptr),
			m_Handle(handle)
		{
		}

		template<typename T>
		constexpr T GetPointer()
		{
			if (!m_Pointer)
				PopulatePointer();
			return (T)m_Pointer;
		}

		constexpr int GetHandle()
		{
			if (m_Handle == -1)
				PopulateHandle();
			return m_Handle;
		}

		bool IsValid();
		bool IsAlive();
		rage::fvector3 GetPosition();
		void SetPosition(rage::fvector3 position);
		bool IsNetworked();
		bool HasControl();
		std::uint16_t GetNetworkObjectId();
	};
}