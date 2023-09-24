#include "Entity.hpp"
#include "game/pointers/Pointers.hpp"
#include "Natives.hpp"
#include <entity/fwEntity.hpp>
#include <network/netObject.hpp>

namespace YimMenu
{
	constexpr void Entity::PopulatePointer()
	{
		m_Pointer = Pointers.HandleToPtr(m_Handle);
	}

	constexpr void Entity::PopulateHandle()
	{
		m_Handle = Pointers.PtrToHandle(m_Pointer);
	}

	constexpr bool Entity::IsAlive()
	{
		return !ENTITY::IS_ENTITY_DEAD(GetHandle());
	}

	constexpr rage::fvector3 Entity::GetPosition()
	{
		auto pos = ENTITY::GET_ENTITY_COORDS(GetHandle(), false, true);
		return rage::fvector3(pos.x, pos.y, pos.z);
	}

	constexpr void Entity::SetPosition(rage::fvector3 position)
	{
		ENTITY::SET_ENTITY_COORDS(GetHandle(), position.x, position.y, position.z, false, true, true, true);
	}

	constexpr bool Entity::IsNetworked()
	{
		return GetPointer<rage::fwEntity*>()->m_NetObject != nullptr;
	}

	constexpr bool Entity::HasControl()
	{
		if (!IsNetworked())
			return true;

		return GetPointer<rage::fwEntity*>()->m_NetObject->m_MigratingOwnerId < 32
		    && !GetPointer<rage::fwEntity*>()->m_NetObject->m_IsRemotelyControlled;
	}
}