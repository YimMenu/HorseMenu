#pragma once
#include "game/pointers/Pointers.hpp"
#include "game/rdr/natives.hpp"

#include <rage/datBitBuffer.hpp>
#include <rage/fwBasePool.hpp>
#include <script/types.hpp>


namespace YimMenu::Helpers
{
	static rage::fwBasePool* GetPedPool()
	{
		if (Pointers.PedPool->m_IsSet)
		{
			uint64_t x = _rotl64(Pointers.PedPool->m_Second, 30);
			return reinterpret_cast<rage::fwBasePool*>(~_rotl64(_rotl64(x ^ Pointers.PedPool->m_First, ((x & 0xFF) & 31) + 3), 32));
		}

		return nullptr;
	}

	static rage::fwBasePool* GetObjectPool()
	{
		if (Pointers.ObjectPool->m_IsSet)
		{
			uint64_t x = _rotl64(Pointers.ObjectPool->m_Second, 30);
			return reinterpret_cast<rage::fwBasePool*>(~_rotl64(_rotl64(x ^ Pointers.ObjectPool->m_First, 32), ((x & 0xFF) & 31) + 2));
		}

		return nullptr;
	}

	static rage::fwBasePool* GetVehiclePool()
	{
		if (Pointers.VehiclePool->m_IsSet)
		{
			uint64_t x = _rotl64(Pointers.VehiclePool->m_Second, 31);
			return reinterpret_cast<rage::fwBasePool*>(~_rotl64(_rotl64(x ^ Pointers.VehiclePool->m_First, 32), ((x & 0xFF) & 31) + 4));
		}

		return nullptr;
	}

	static rage::fwBasePool* GetPickupPool()
	{
		if (Pointers.PickupPool->m_IsSet)
		{
			uint64_t x = _rotl64(Pointers.PickupPool->m_Second, 30);
			return reinterpret_cast<rage::fwBasePool*>(~_rotl64(_rotl64(Pointers.PickupPool->m_First ^ x, 32), ((x & 0xFF) & 31) + 2));
		}

		return nullptr;
	}

	inline std::vector<Ped> GetAllPeds()
	{
		std::vector<Ped> result;

		if (const rage::fwBasePool* pool = GetPedPool())
		{
			for (uint32_t i = 0; i < pool->m_Size; i++)
			{
				if (pool->IsValid(i))
				{
					if (void* obj = pool->GetAt(i))
					{
						uint32_t ent = Pointers.FwScriptGuidCreateGuid(obj);
						if (ENTITY::DOES_ENTITY_EXIST(ent))
							result.push_back(ent);
					}
				}
			}
		}

		return result;
	}

	inline std::vector<Object> GetAllObjects()
	{
		std::vector<Object> result;

		if (const rage::fwBasePool* pool = GetObjectPool())
		{
			for (uint32_t i = 0; i < pool->m_Size; i++)
			{
				if (pool->IsValid(i))
				{
					if (void* obj = pool->GetAt(i))
					{
						uint32_t ent = Pointers.FwScriptGuidCreateGuid(obj);
						if (ENTITY::DOES_ENTITY_EXIST(ent))
							result.push_back(ent);
					}
				}
			}
		}

		return result;
	}

	inline std::vector<Vehicle> GetAllVehicles()
	{
		std::vector<Vehicle> result;

		if (const rage::fwBasePool* pool = GetVehiclePool())
		{
			for (uint32_t i = 0; i < pool->m_Size; i++)
			{
				if (pool->IsValid(i))
				{
					if (void* obj = pool->GetAt(i))
					{
						uint32_t ent = Pointers.FwScriptGuidCreateGuid(obj);
						if (ENTITY::DOES_ENTITY_EXIST(ent))
							result.push_back(ent);
					}
				}
			}
		}

		return result;
	}

	inline std::vector<Pickup> GetAllPickups()
	{
		std::vector<Pickup> result;

		if (const rage::fwBasePool* pool = GetPickupPool())
		{
			for (uint32_t i = 0; i < pool->m_Size; i++)
			{
				if (pool->IsValid(i))
				{
					if (void* obj = pool->GetAt(i))
					{
						uint32_t ent = Pointers.FwScriptGuidCreateGuid(obj);
						if (ENTITY::DOES_ENTITY_EXIST(ent))
							result.push_back(ent);
					}
				}
			}
		}

		return result;
	}

	inline bool WriteArray(void* array, int size, rage::datBitBuffer* buffer)
	{
		return Pointers.WriteBitBufferArray(buffer, array, size, 0);
	}

	inline bool ReadArray(PVOID array, int size, rage::datBitBuffer* buffer)
	{
		return Pointers.ReadBitBufferArray(buffer, array, size, 0);
	}

	inline void WriteBufferString(const char* str, int max_len, rage::datBitBuffer* buffer)
	{
		auto len      = std::min(max_len, (int)strlen(str) + 1);
		bool extended = len > 127;
		buffer->Write<bool>(extended, 1);
		buffer->Write<int>(len, extended ? 15 : 7);
		WriteArray((void*)str, 8 * len, buffer);
	}

	inline bool ReadString(char* str, int bits, rage::datBitBuffer* buffer)
	{
		return Pointers.ReadBitBufferString(buffer, str, bits);
	}
}