#pragma once
#include <rage/vector.hpp>

#define ENTITY_DEBUG

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

	public:
		// debug
		void AssertValid(const std::string& function_name);
		void AssertControl(const std::string& function_name);
		void AssertScriptContext(const std::string& function_name);

		constexpr Entity(void* pointer) :
		    m_Pointer(pointer),
		    m_Handle(0)
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
			if (m_Handle == 0)
				PopulateHandle();
			return m_Handle;
		}

		template<typename T>
		constexpr T As()
		{
			return T(this);
		}

		bool IsValid();
		inline operator bool()
		{
			return IsValid();
		}
		inline operator int() = delete;

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
		void SetFrozen(bool enabled);
		void Delete();

		// networking
		bool IsNetworked();
		bool HasControl();
		std::uint16_t GetNetworkObjectId();
		/// <summary>
		/// WARNING: This function is potentially unstable when used on vehicles and horses. Use RequestControl instead
		/// </summary>
		void ForceControl();

		// health
		bool GetInvincible();
		void SetInvincible(bool status);
		bool IsDead();
		void Kill();
		int GetHealth();
		void SetHealth(int health);
		int GetMaxHealth();

		// visibility
		bool IsVisible();
		void SetVisible(bool status);

		bool operator==(const Entity& other);
		bool operator!=(const Entity& other)
		{
			return !this->operator==(other);
		}
	};
}