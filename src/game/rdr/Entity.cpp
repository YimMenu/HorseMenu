#include "Entity.hpp"

#include "Natives.hpp"
#include "game/pointers/Pointers.hpp"
#include "util/Joaat.hpp"
#include "Network.hpp"

#include <entity/fwEntity.hpp>
#include <entity/CDynamicEntity.hpp>
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
		if (!*Pointers.CurrentScriptThread)
		{
			LOG(WARNING) << "*Pointers.CurrentScriptThread == nullptr for " << function_name;
		}
	}

	bool Entity::IsValid()
	{
		if (m_Handle)
			return ENTITY::DOES_ENTITY_EXIST(m_Handle);
		else if (m_Pointer)
			return true; // TODO: potential use after free

		return false;
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

	bool Entity::IsAnimal()
	{
		ENTITY_ASSERT_VALID();
		return ENTITY::GET_IS_ANIMAL(GetHandle());
	}

	int Entity::GetModel()
	{
		ENTITY_ASSERT_VALID();
		return ENTITY::GET_ENTITY_MODEL(GetHandle());
	}

	rage::fvector3 Entity::GetPosition()
	{
		ENTITY_ASSERT_VALID();
		return ENTITY::GET_ENTITY_COORDS(GetHandle(), false, true);
	}

	void Entity::SetPosition(rage::fvector3 position)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		ENTITY_ASSERT_SCRIPT_CONTEXT();
		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(GetHandle(), position.x, position.y, position.z, true, true, true);
	}

	rage::fvector3 Entity::GetRotation(int order)
	{
		ENTITY_ASSERT_VALID();
		return ENTITY::GET_ENTITY_ROTATION(GetHandle(), order);
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
		return ENTITY::GET_ENTITY_VELOCITY(GetHandle(), 0);
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

	void Entity::Delete()
	{
		ENTITY_ASSERT_VALID();

		if (!IsValid())
			return;

		if (IsNetworked())
		{
			auto net = GetPointer<CDynamicEntity*>()->m_NetObject;
			Network::ForceRemoveNetworkEntity(net->m_ObjectId, net->m_OwnershipToken);
		}
		else
		{
			if (!ENTITY::IS_ENTITY_A_MISSION_ENTITY(GetHandle()))
				ENTITY::SET_ENTITY_AS_MISSION_ENTITY(GetHandle(), true, true);
			auto hnd = GetHandle();
			ENTITY::DELETE_ENTITY(&hnd);
		}
	}

	bool Entity::IsNetworked()
	{
		return GetNetworkObject() != nullptr;
	}

	rage::netObject* Entity::GetNetworkObject()
	{
		if (!IsValid())
			return nullptr;

		return GetPointer<CDynamicEntity*>()->m_NetObject;
	}

	bool Entity::HasControl()
	{
		if (!IsNetworked())
			return true;

		return !GetNetworkObject()->m_IsRemotelyControlled;
	}

	std::uint16_t Entity::GetNetworkObjectId()
	{
		ENTITY_ASSERT_VALID();
		if (!IsNetworked())
			return 0;

		return GetNetworkObject()->m_ObjectId;
	}

	void Entity::ForceControl()
	{
		ENTITY_ASSERT_VALID();

		if (!IsNetworked() || HasControl())
			return;

		(*Pointers.NetworkObjectMgr)->ChangeOwner(GetNetworkObject(), Pointers.NetworkPlayerMgr->m_LocalPlayer, 5, true);
	}

	void Entity::ForceSync(Player* for_player)
	{
		ENTITY_ASSERT_VALID();
		ENTITY_ASSERT_CONTROL();
		ENTITY_ASSERT_SCRIPT_CONTEXT();

		if (!IsNetworked())
			return;

		char data[0x400];
		auto net = GetNetworkObject();
		for (int i = 0; i < 32; i++)
		{
			if (Pointers.NetworkPlayerMgr->m_PlayerList[i] && Pointers.NetworkPlayerMgr->m_PlayerList[i] != Pointers.NetworkPlayerMgr->m_LocalPlayer && (!for_player || !for_player->IsValid() || for_player->GetId() == i))
			{
				rage::datBitBuffer buffer(data, sizeof(data));
				(*Pointers.NetworkObjectMgr)->PackCloneCreate(net, Pointers.NetworkPlayerMgr->m_PlayerList[i], &buffer);
			}
		}
	}

	bool Entity::IsInvincible()
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
			auto ptr             = GetPointer<CDynamicEntity*>();
			auto local           = reinterpret_cast<CDynamicEntity*>(Pointers.GetLocalPed());
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