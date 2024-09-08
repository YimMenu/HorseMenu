#pragma once
#include "Entity.hpp"
#include "Ped.hpp"

#include <rage/fwBasePool.hpp>


namespace YimMenu
{
	rage::fwBasePool* GetPedPool();
	rage::fwBasePool* GetObjectPool();
	rage::fwBasePool* GetVehiclePool();
	rage::fwBasePool* GetPickupPool();
	rage::fwBasePool* GetScriptHandlePool();

	template<typename Wrapper>
	class PoolIterator
	{
	public:
		rage::fwBasePool* m_Pool = nullptr;
		uint32_t m_Index         = 0;

		explicit PoolIterator(rage::fwBasePool* pool, int32_t index = 0)
		{
			this->m_Pool  = pool;
			this->m_Index = index;
		}

		PoolIterator& operator++()
		{
			for (m_Index++; m_Index < m_Pool->m_Size; m_Index++)
			{
				if (m_Pool->IsValid(m_Index))
				{
					return *this;
				}
			}

			m_Index = m_Pool->m_Size;
			return *this;
		}

		Wrapper operator*()
		{
			auto addr = m_Pool->GetAt(m_Index);
			return Wrapper(addr);
		}

		bool operator!=(const PoolIterator& other) const
		{
			return this->m_Index != other.m_Index;
		}
	};

	// Common functions for VehiclePool and GenericPool
	template<typename Wrapper = Entity>
	class PoolUtils
	{
		rage::fwBasePool* m_Pool;

	public:
		PoolUtils(rage::fwBasePool* pool) :
		    m_Pool(pool)
		{
		}

		auto begin()
		{
			return ++PoolIterator<Wrapper>(m_Pool, -1);
		}

		auto end()
		{
			return ++PoolIterator<Wrapper>(m_Pool, m_Pool->m_Size);
		}

		auto size()
		{
			return m_Pool->m_Size;
		}
	};

	namespace Pools
	{
		inline PoolUtils<Ped> GetPeds()
		{
			return PoolUtils<Ped>(GetPedPool());
		}

		inline PoolUtils<Entity> GetObjects()
		{
			return PoolUtils<Entity>(GetObjectPool());
		}

		inline PoolUtils<Entity> GetVehicles()
		{
			return PoolUtils<Entity>(GetVehiclePool());
		}

		inline PoolUtils<Entity> GetPickups()
		{
			return PoolUtils<Entity>(GetPickupPool());
		}
	}
}