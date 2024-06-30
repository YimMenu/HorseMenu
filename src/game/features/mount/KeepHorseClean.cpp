#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class KeepHorseClean : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			PED::_SET_PED_DAMAGE_CLEANLINESS(Self::Mount, (int)ePedDamageCleanliness::PED_DAMAGE_CLEANLINESS_PERFECT);
			PED::CLEAR_PED_WETNESS(Self::Mount);
			PED::CLEAR_PED_ENV_DIRT(Self::Mount);
			PED::CLEAR_PED_BLOOD_DAMAGE(Self::Mount);
			PED::CLEAR_PED_DAMAGE_DECAL_BY_ZONE(Self::Mount, 10, "ALL");
		}
	};

	static KeepHorseClean _KeepHorseClean{"keephorseclean", "Keep Horse Clean", "Keeps your horse from being dirty"};
}