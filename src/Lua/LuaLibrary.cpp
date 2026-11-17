#include "LuaLibrary.hpp"
#include "LuaMgr.hpp"


namespace Terminus::LuaJIT
{
	LuaLibrary::LuaLibrary()
	{
		LuaManager::RegisterLibrary(this);
	}
}
