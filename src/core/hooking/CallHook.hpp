#pragma once
#include "BaseHook.hpp"
#include "core/memory/PointerCalculator.hpp"

#include <MinHook.h>
#include <string_view>

namespace YimMenu
{
	class CallHookMemory
	{
		PointerCalculator m_Memory;
		int m_Offset;

	public:
		CallHookMemory()
		{
			m_Memory = VirtualAlloc((void*)((uintptr_t)GetModuleHandle(0) + 0x20000000), 1024, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
			m_Offset = 0;
		}

		~CallHookMemory()
		{
			VirtualFree(m_Memory.As<void*>(), 0, MEM_RELEASE);
			m_Memory = nullptr;
		}

		void* AllocateJumpSeq(void* func)
		{
			m_Offset = m_Offset + ((16 - (m_Offset % 16)) % 16); // align

			*m_Memory.Add(m_Offset).As<int16_t*>()         = 0xB848;
			*m_Memory.Add(m_Offset).Add(2).As<void**>()    = func;
			*m_Memory.Add(m_Offset).Add(10).As<int16_t*>() = 0xE0FF;

			m_Offset += 12;

			return m_Memory.Add(m_Offset).Sub(12).As<void*>();
		}
	};

	inline CallHookMemory g_CallHookMemory;

	template<typename T = int*>
	class CallHook : public BaseHook
	{
	private:
		void* m_DetourFunc;
		void* m_TargetFunc;
		void* m_OriginalFunc;
		char m_OriginalBytes[5];
		char m_PatchedBytes[5];

	public:
		CallHook(const std::string_view name, void* target, T detour);
		virtual ~CallHook();

		bool Enable() override;
		bool Disable() override;
		T Original() const;
	};

	template<typename T>
	inline CallHook<T>::CallHook(const std::string_view name, void* target, T detour) :
	    BaseHook(name),
	    m_DetourFunc(detour),
	    m_TargetFunc(target)
	{
		auto seq = g_CallHookMemory.AllocateJumpSeq(detour);
		m_PatchedBytes[0] = 0xE8;
		*(int32_t*)&m_PatchedBytes[1] = (int32_t)((uint64_t)seq - (uint64_t)target - 5);
		memcpy(m_OriginalBytes, target, 5);
		m_OriginalFunc = PointerCalculator(target).Add(1).Rip().As<void*>();
	}

	template<typename T>
	inline CallHook<T>::~CallHook()
	{
		Disable();
	}

	template<typename T>
	inline bool CallHook<T>::Enable()
	{
		if (m_Enabled)
			return true;

		memcpy(m_TargetFunc, m_PatchedBytes, 5);
		m_Enabled = true;
		return true;
	}

	template<typename T>
	inline bool CallHook<T>::Disable()
	{
		if (!m_Enabled)
			return true;

		memcpy(m_TargetFunc, m_OriginalBytes, 5);
		m_Enabled = false;
		return true;
	}

	template<typename T>
	inline T CallHook<T>::Original() const
	{
		return reinterpret_cast<T>(m_OriginalFunc);
	}
}