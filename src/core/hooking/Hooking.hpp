#pragma once
#include "MinHook.hpp"

namespace YimMenu
{
	template <typename T>
	inline void* GetVF(T ptr, uint64_t index)
	{
		void** VFT{ *reinterpret_cast<void***>(ptr) };
		return VFT[index];
	}
	
	class Hooking
	{
	private:
		Hooking();

		MinHook m_MinHook;

	public:
		virtual ~Hooking();
		Hooking(const Hooking&) = delete;
		Hooking(Hooking&&) noexcept  = delete;
		Hooking& operator=(const Hooking&) = delete;
		Hooking& operator=(Hooking&&) noexcept  = delete;
		
		static bool Init();
		static bool LateInit();
		static void Destroy();

	private:
		bool InitImpl();
		bool LateInitImpl();
		void DestroyImpl();

	private:
		static Hooking& GetInstance()
		{
			static Hooking i{};
			return i;
		}

	};
}
