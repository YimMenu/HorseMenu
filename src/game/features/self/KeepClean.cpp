#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class KeepClean : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			auto ped = Self::GetPed();
			if (!ped || ped.IsDead())
				return;

			PED::_SET_PED_DAMAGE_CLEANLINESS(ped.GetHandle(), (int)PedDamageCleanliness::PED_DAMAGE_CLEANLINESS_PERFECT);
			PED::CLEAR_PED_WETNESS(ped.GetHandle());
			PED::CLEAR_PED_ENV_DIRT(ped.GetHandle());
			PED::CLEAR_PED_BLOOD_DAMAGE(ped.GetHandle());
			PED::CLEAR_PED_DAMAGE_DECAL_BY_ZONE(ped.GetHandle(), 10, "ALL");
		}
	};

	static KeepClean _KeepClean{"keepclean", "Keep Clean", "Keeps your character from being dirty"};
}