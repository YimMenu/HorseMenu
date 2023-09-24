#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"

namespace
{
	static void DoNothing()
	{
	}

	struct NothingVtable
	{
		void* m_Funcs[0x50];
	};

	struct Nothing
	{
		NothingVtable* m_Vft;
		NothingVtable m_Table;

		Nothing()
		{
			m_Vft = &m_Table;

			for (int i = 0; i < 0x50; i++)
				m_Table.m_Funcs[i] = &DoNothing;
		}
	};

	static Nothing _Nothing;
}

namespace YimMenu::Hooks
{
	void* Protections::GetUnkPlayerThing(__int64 player, int index)
	{
		int16_t* counter =  (int16_t*)(player + 0xC18);
		void** array      = *(void***)(player + 0xC10);

		if (array == nullptr || array[index] == nullptr)
		{
			LOG(WARNING) << __FUNCTION__ ": blocked crash attempt";
			*counter = 0;
			return &_Nothing;
		}

		return array[index];
	}
}