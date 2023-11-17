#include "Ped.hpp"

#include "Natives.hpp"

namespace YimMenu
{
	Ped Ped::GetMount()
	{
		return Ped(PED::GET_MOUNT(GetHandle()));
	}

	rage::fvector3 Ped::GetBonePosition(int bone)
	{
		auto coords = PED::GET_PED_BONE_COORDS(GetHandle(), bone, 0, 0, 0);
		return rage::fvector3(coords.x, coords.y, coords.z);
	}
}