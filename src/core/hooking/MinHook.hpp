#pragma once
#include <MinHook.h>

namespace Terminus
{
	class MinHook
	{
	public:
		MinHook()
		{
			MH_Initialize();
		}

		~MinHook()
		{
			MH_Uninitialize();
		}

		MH_STATUS ApplyQueued()
		{
			return MH_ApplyQueued();
		}
	};
}