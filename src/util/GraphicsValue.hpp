#pragma once
#include <cstdint>

namespace YimMenu
{
	inline const char* GetGraphicsValue(int value)
	{
		const char* ret = "Unkown";

		switch (value)
		{
		  case 0: ret = "Low"; break;
		  case 1: ret = "Medium"; break;
		  case 2: ret = "High"; break;
		  case 3: ret = "Ultra"; break;
		  case 4: ret = "Custom"; break;
		  case 5: ret = "Special"; break;
		  default: ret = "Default"; break;
		}

		return ret;
	}


}