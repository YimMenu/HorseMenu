#include "Entity.hpp"
#include "game/pointers/Pointers.hpp"
#include "Natives.hpp"
#include <entity/fwEntity.hpp>
#include <network/netObject.hpp>

namespace YimMenu
{
	void Entity::PopulatePointer()
	{
		m_Pointer = Pointers.HandleToPtr(m_Handle);
	}

	void Entity::PopulateHandle()
	{
		if (m_Pointer)
			m_Handle = Pointers.PtrToHandle(m_Pointer);
	}

	bool Entity::IsValid()
	{
		return m_Handle != -1 || m_Pointer != nullptr;
	}

	bool Entity::IsAlive()
	{
		return !ENTITY::IS_ENTITY_DEAD(GetHandle());
	}

	bool Entity::IsPed()
	{
		if (auto ptr = GetPointer<rage::fwEntity*>())
			return ptr->m_EntityType == 4;
		return false;
	}

	bool Entity::IsVehicle()
	{
		if (auto ptr = GetPointer<rage::fwEntity*>())
			return ptr->m_EntityType == 3;
		return false;
	}

	bool Entity::IsObject()
	{
		if (auto ptr = GetPointer<rage::fwEntity*>())
			return ptr->m_EntityType == 5;
		return false;
	}

	bool Entity::IsPlayer()
	{
		return PED::IS_PED_A_PLAYER(GetHandle());
	}

	rage::fvector3 Entity::GetPosition()
	{
		auto pos = ENTITY::GET_ENTITY_COORDS(GetHandle(), false, true);
		return rage::fvector3(pos.x, pos.y, pos.z);
	}

	void Entity::SetPosition(rage::fvector3 position)
	{
		ENTITY::SET_ENTITY_COORDS(GetHandle(), position.x, position.y, position.z, false, true, true, true);
	}

	bool Entity::IsNetworked()
	{
		return GetPointer<rage::fwEntity*>()->m_NetObject != nullptr;
	}

	bool Entity::HasControl()
	{
		if (!IsNetworked())
			return true;

		return GetPointer<rage::fwEntity*>()->m_NetObject->m_MigratingOwnerId < 32
		    && !GetPointer<rage::fwEntity*>()->m_NetObject->m_IsRemotelyControlled;
	}

	std::uint16_t Entity::GetNetworkObjectId()
	{
		if (!IsNetworked())
			return 0;

		return GetPointer<rage::fwEntity*>()->m_NetObject->m_ObjectId;
	}
}