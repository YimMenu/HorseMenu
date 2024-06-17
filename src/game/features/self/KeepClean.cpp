#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class KeepClean : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			PED::_SET_PED_DAMAGE_CLEANLINESS(Self::PlayerPed, (int)ePedDamageCleanliness::PED_DAMAGE_CLEANLINESS_PERFECT);
			PED::CLEAR_PED_WETNESS(Self::PlayerPed);
			PED::CLEAR_PED_ENV_DIRT(Self::PlayerPed);
			PED::CLEAR_PED_BLOOD_DAMAGE(Self::PlayerPed);
			PED::CLEAR_PED_DAMAGE_DECAL_BY_ZONE(Self::PlayerPed, 10, "ALL");
		}
	};

	static KeepClean _KeepClean{"keepclean", "Keep Clean", "Keeps your character from being dirty"};
}