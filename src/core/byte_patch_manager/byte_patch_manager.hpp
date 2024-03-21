#pragma once
#include "core/memory/BytePatch.hpp"

namespace YimMenu
{
	class Byte_Patch_Manager
	{
	public:
		~Byte_Patch_Manager();

		static void Init();

	private:
		static Byte_Patch_Manager& GetInstance()
		{
			static Byte_Patch_Manager i{};
			return i;
		}

		void InitImpl();
	};
}