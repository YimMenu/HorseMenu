#pragma once
#include <rage/vector.hpp>

// TODO: debug stuff
#ifdef ENTITY_DEBUG
	#define ENTITY_ASSERT_VALID() AssertValid(__FUNCTION__);
	#define ENTITY_ASSERT_CONTROL() AssertControl(__FUNCTION__);
	#define ENTITY_ASSERT_SCRIPT_CONTEXT() AssertScriptContext(__FUNCTION__);
#else
	#define ENTITY_ASSERT_VALID()
	#define ENTITY_ASSERT_CONTROL()
	#define ENTITY_ASSERT_SCRIPT_CONTEXT()
#endif

namespace YimMenu
{
	class Entity
	{
		void* m_Pointer;
		int m_Handle;

		void PopulatePointer();
		void PopulateHandle();

		// debug
		void AssertValid(const std::string& function_name);
		void AssertControl(const std::string& function_name);
		void AssertScriptContext(const std::string& function_name);

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

		constexpr Entity(void* pointer, int handle) :
		    m_Pointer(pointer),
		    m_Handle(handle)
		{
		}

		// raw data
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
		inline operator bool() { return IsValid(); }
		bool IsAlive();

		bool IsPed();
		bool IsVehicle();
		bool IsObject();
		bool IsPlayer();

		// position
		rage::fvector3 GetPosition();
		void SetPosition(rage::fvector3 position);
		rage::fvector3 GetRotation(int order = 2);
		void SetRotation(rage::fvector3 rotation, int order = 2);
		rage::fvector3 GetVelocity();
		void SetVelocity(rage::fvector3 velocity);

		// physical
		void SetCollision(bool enabled);
		bool SetFrozen(bool enabled);

		// networking
		bool IsNetworked();
		bool HasControl();
		std::uint16_t GetNetworkObjectId();

		// health
		bool GetInvincible();
		void SetInvincible(bool status);
		bool IsDead();
		int GetHealth();
		void SetHealth(int health);
		int GetMaxHealth();

		// visibility
		bool IsVisible();
		void SetVisible(bool status);

		bool operator==(const Entity& other);
	};
}