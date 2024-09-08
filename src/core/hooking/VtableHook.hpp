#pragma once
#include <string_view>
#include "BaseHook.hpp"

namespace YimMenu
{
	class VtableHook : public BaseHook
	{
	public:
		explicit VtableHook(const std::string_view name, void** vft, std::size_t numFuncs);
		~VtableHook();

		VtableHook(VtableHook&& that)            = delete;
		VtableHook& operator=(VtableHook&& that) = delete;
		VtableHook(VtableHook const&)            = delete;
		VtableHook& operator=(VtableHook const&) = delete;

		void Hook(std::size_t index, void* func);
		void Unhook(std::size_t index);

		template<typename T>
		T GetOriginal(std::size_t index);

		inline void** GetOriginalTable()
		{
			return m_BackupTable.get();
		}

		bool Enable() override;
		bool Disable() override;

	private:
		std::size_t m_NumFuncs;
		void** m_Table;
		std::unique_ptr<void*[]> m_BackupTable;
		std::unique_ptr<void*[]> m_HookTable;
	};

	template<typename T>
	inline T VtableHook::GetOriginal(std::size_t index)
	{
		return static_cast<T>(m_BackupTable[index]);
	}
}
