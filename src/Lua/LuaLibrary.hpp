#pragma once
#include <sol/sol.hpp>
#include "LuaModule.hpp"


namespace Terminus::LuaJIT
{
	class LuaLibrary
	{
	public:
		LuaLibrary();
		virtual void Register(sol::state& L) = 0;
	};
}
