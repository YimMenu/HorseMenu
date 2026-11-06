#pragma once

#include "../LuaLibrary.hpp"
#include "../LuaModule.hpp"
#include "../natives/NativeBinding.hpp"


namespace Terminus::LuaJIT
{
	class LuaNativesLib : public LuaLibrary
	{
		using LuaLibrary::LuaLibrary;

	public:
		void Register(sol::state& L) override
		{
			Natives::RegisterNatives(L);
		}
	};

	LuaNativesLib _LuaNativesLib;
}
