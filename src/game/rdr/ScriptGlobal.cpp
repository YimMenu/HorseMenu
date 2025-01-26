#include "game/pointers/Pointers.hpp"
#include "ScriptGlobal.hpp"
#include "game/rdr/Scripts.hpp"

namespace YimMenu
{
    void* ScriptGlobal::Get() const
    {
        return Pointers.ScriptGlobals[m_Index >> 0x12 & 0x3F] + (m_Index & 0x3FFFF);
	}

	bool ScriptGlobal::CanAccess(bool is_mp) const
	{
		if (is_mp != Scripts::UsingMPScripts())
			return false;

		return Pointers.ScriptGlobals && (m_Index >> 0x12 & 0x3F) < 0x40 && Pointers.ScriptGlobals[m_Index >> 0x12 & 0x3F];
	}
}