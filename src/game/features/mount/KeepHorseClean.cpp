#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class KeepHorseClean : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (auto mount = Self::GetMount())
			{
				PED::_SET_PED_DAMAGE_CLEANLINESS(mount.GetHandle(), (int)PedDamageCleanliness::PED_DAMAGE_CLEANLINESS_PERFECT);
				PED::CLEAR_PED_WETNESS(mount.GetHandle());
				PED::CLEAR_PED_ENV_DIRT(mount.GetHandle());
				PED::CLEAR_PED_BLOOD_DAMAGE(mount.GetHandle());
				PED::CLEAR_PED_DAMAGE_DECAL_BY_ZONE(mount.GetHandle(), 10, "ALL");
			}
		}
	};

	static KeepHorseClean _KeepHorseClean{"keephorseclean", "Keep Horse Clean", "Keeps your horse from being dirty"};
}