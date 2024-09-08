#include "Pools.hpp"

#include "game/pointers/Pointers.hpp"

#include <rage/pools.hpp>


namespace YimMenu
{
	rage::fwBasePool* GetPedPool()
	{
		if (Pointers.PedPool->m_IsSet)
		{
			uint64_t x = _rotl64(Pointers.PedPool->m_Second, 30);
			return reinterpret_cast<rage::fwBasePool*>(~_rotl64(_rotl64(x ^ Pointers.PedPool->m_First, ((x & 0xFF) & 31) + 3), 32));
		}

		return nullptr;
	}

	rage::fwBasePool* GetObjectPool()
	{
		if (Pointers.ObjectPool->m_IsSet)
		{
			uint64_t x = _rotl64(Pointers.ObjectPool->m_Second, 30);
			return reinterpret_cast<rage::fwBasePool*>(~_rotl64(_rotl64(x ^ Pointers.ObjectPool->m_First, 32), ((x & 0xFF) & 31) + 2));
		}

		return nullptr;
	}

	rage::fwBasePool* GetVehiclePool()
	{
		if (Pointers.VehiclePool->m_IsSet)
		{
			uint64_t x = _rotl64(Pointers.VehiclePool->m_Second, 31);
			return reinterpret_cast<rage::fwBasePool*>(~_rotl64(_rotl64(x ^ Pointers.VehiclePool->m_First, 32), ((x & 0xFF) & 31) + 4));
		}

		return nullptr;
	}

	rage::fwBasePool* GetPickupPool()
	{
		if (Pointers.PickupPool->m_IsSet)
		{
			uint64_t x = _rotl64(Pointers.PickupPool->m_Second, 30);
			return reinterpret_cast<rage::fwBasePool*>(~_rotl64(_rotl64(Pointers.PickupPool->m_First ^ x, 32), ((x & 0xFF) & 31) + 2));
		}

		return nullptr;
	}
	// This doesnt work
	rage::fwBasePool* GetScriptHandlePool()
	{
		if (Pointers.ScriptHandlePool->m_IsSet)
		{
			uint64_t x = _rotl64(Pointers.ScriptHandlePool->m_Second, 30);
			return reinterpret_cast<rage::fwBasePool*>(~_rotl64(_rotl64(Pointers.ScriptHandlePool->m_First ^ x, 32), ((x & 0xFF) & 31) + 2));
		}

		return nullptr;
	}
}