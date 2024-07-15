#include "Entity.hpp"

#include "Natives.hpp"
#include "game/pointers/Pointers.hpp"
#include "util/Joaat.hpp"
#include "game/backend/Self.hpp"

#include <entity/fwEntity.hpp>
#include <network/CNetObjectMgr.hpp>
#include <network/CNetworkPlayerMgr.hpp>
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

	void Entity::AssertValid(const std::string& function_name)
	{
		if (!IsValid())
		{
			LOG(WARNING) << "IsValid() assertion failed for " << function_name;
		}
	}

	void Entity::AssertControl(const std::string& function_name)
	{
		if (!IsValid())
			return;

		if (!HasControl())
		{
			LOG(WARNING) << "HasControl() assertion failed for " << function_name;
		}
	}

	void Entity::AssertScriptContext(const std::string& function_name)
	{
		// TODO
	}

	// TODO: potential use after free
	bool Entity::IsValid()
	{
		return m_Handle != 0 || m_Pointer != nullptr;
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
		ENTITY_ASSERT_VALID();
		return PED::IS_PED_A_PLAYER(GetHandle());
	}

	rage::fvector3 Entity::GetPosition()
	{
		ENTITY_ASSERT_VALID();
		auto pos = ENTITY::GET_ENTITY_COORDS(GetHandle(), false, true);
		return rage::fvector3(pos.x, pos.y, pos.z);
	}

	void Entity::SetPosition(rage::fvector3 position)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		ENTITY_ASSERT_SCRIPT_CONTEXT();
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(GetHandle(), position.x, position.y, position.z, true, true, true);
	}

	float Entity::GetDistance()
	{
		ENTITY_ASSERT_VALID();
		auto pos     = ENTITY::GET_ENTITY_COORDS(GetHandle(), false, true);
		auto selfPos = Self::GetPed().GetPosition();
		auto dist    = MISC::GET_DISTANCE_BETWEEN_COORDS(pos.x, pos.y, pos.z, selfPos.x, selfPos.y, selfPos.z, TRUE);
		return dist;
	}

	rage::fvector3 Entity::GetRotation(int order)
	{
		ENTITY_ASSERT_VALID();
		auto pos = ENTITY::GET_ENTITY_ROTATION(GetHandle(), order);
		return rage::fvector3(pos.x, pos.y, pos.z);
	}

	void Entity::SetRotation(rage::fvector3 rotation, int order)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		ENTITY::SET_ENTITY_ROTATION(GetHandle(), rotation.x, rotation.y, rotation.z, order, false);
	}

	rage::fvector3 Entity::GetVelocity()
	{
		ENTITY_ASSERT_VALID();
		auto pos = ENTITY::GET_ENTITY_VELOCITY(GetHandle(), 0);
		return rage::fvector3(pos.x, pos.y, pos.z);
	}

	void Entity::SetVelocity(rage::fvector3 vel)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		ENTITY::SET_ENTITY_VELOCITY(GetHandle(), vel.x, vel.y, vel.z);
	}

	void Entity::SetCollision(bool enabled)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		ENTITY::SET_ENTITY_COLLISION(GetHandle(), enabled, true);
	}

	void Entity::SetFrozen(bool enabled)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		ENTITY::FREEZE_ENTITY_POSITION(GetHandle(), enabled);
	}

	bool Entity::IsNetworked()
	{
		if (!IsValid())
			return false;

		return GetPointer<rage::fwEntity*>()->m_NetObject != nullptr;
	}

	bool Entity::HasControl()
	{
		if (!IsNetworked())
			return true;

		return !GetPointer<rage::fwEntity*>()->m_NetObject->m_IsRemotelyControlled;
	}

	std::uint16_t Entity::GetNetworkObjectId()
	{
		ENTITY_ASSERT_VALID();
		if (!IsNetworked())
			return 0;

		return GetPointer<rage::fwEntity*>()->m_NetObject->m_ObjectId;
	}

	void Entity::ForceControl()
	{
		ENTITY_ASSERT_VALID();

		if (!IsNetworked() || HasControl())
			return;

		(*Pointers.NetworkObjectMgr)->ChangeOwner(GetPointer<rage::fwEntity*>()->m_NetObject, Pointers.NetworkPlayerMgr->m_LocalPlayer, 5, true);
	}

	bool Entity::GetInvincible()
	{
		// TODO this is bad!
		ENTITY_ASSERT_VALID();
		return !ENTITY::_GET_ENTITY_CAN_BE_DAMAGED(GetHandle());
	}

	void Entity::SetInvincible(bool status)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		ENTITY::SET_ENTITY_INVINCIBLE(GetHandle(), status);
	}

	bool Entity::IsDead()
	{
		ENTITY_ASSERT_VALID();
		return ENTITY::IS_ENTITY_DEAD(GetHandle());
	}

	void Entity::Kill()
	{
		ENTITY_ASSERT_VALID();

		if (HasControl())
		{
			ENTITY::SET_ENTITY_HEALTH(GetHandle(), 0, PLAYER::PLAYER_PED_ID());
		}
		else
		{
			auto ptr             = GetPointer<rage::fwEntity*>();
			auto local           = reinterpret_cast<rage::fwEntity*>(Pointers.GetLocalPed());
			auto pos             = GetPosition();
			std::uint32_t weapon = "WEAPON_EXPLOSION"_J;

			if (!ptr || !ptr->m_NetObject || !local || !local->m_NetObject)
				return;

			Pointers.TriggerWeaponDamageEvent(local->m_NetObject, ptr->m_NetObject, nullptr, &pos, nullptr, nullptr, true, &weapon, 9999.9f, 9999.0f, -1, -1, 16, nullptr, false, false, true, false, false, -1, 0, 0, 0, 0, 0);
		}
	}

	int Entity::GetHealth()
	{
		ENTITY_ASSERT_VALID();
		return ENTITY::GET_ENTITY_HEALTH(GetHandle());
	}

	void Entity::SetHealth(int health)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		ENTITY::SET_ENTITY_HEALTH(GetHandle(), health, 0);
	}

	int Entity::GetMaxHealth()
	{
		ENTITY_ASSERT_VALID();
		return ENTITY::GET_ENTITY_MAX_HEALTH(GetHandle(), 0);
	}

	bool Entity::IsVisible()
	{
		ENTITY_ASSERT_VALID();
		return ENTITY::IS_ENTITY_VISIBLE(GetHandle());
	}

	void Entity::SetVisible(bool status)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		ENTITY::SET_ENTITY_VISIBLE(GetHandle(), status);
	}

	// TODO: find a better way to compare entities
	bool Entity::operator==(const Entity& other)
	{
		if (m_Handle != 0 && other.m_Handle != 0)
			return m_Handle == other.m_Handle;

		if (m_Pointer != nullptr && other.m_Pointer != nullptr)
			return m_Pointer == other.m_Pointer;

		if (other.m_Pointer != nullptr)
			if (auto ptr = GetPointer<void*>())
				return ptr == other.m_Pointer;

		if (other.m_Handle != 0)
			if (auto handle = GetHandle(); handle != 0)
				return handle == other.m_Handle;

		return false;
	}
}