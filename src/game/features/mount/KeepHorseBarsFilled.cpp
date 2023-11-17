#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	// TODO: this should be moved out of self
	class KeepHorseBarsFilled : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (!ENTITY::DOES_ENTITY_EXIST(Self::Mount))
				return;

			auto health_bar  = ENTITY::GET_ENTITY_HEALTH(Self::Mount);
			auto stamina_bar = PED::_GET_PED_STAMINA(Self::Mount);

			if (health_bar < ENTITY::GET_ENTITY_MAX_HEALTH(Self::Mount, 0))
				ENTITY::SET_ENTITY_HEALTH(Self::Mount, ENTITY::GET_ENTITY_MAX_HEALTH(Self::Mount, 0), 0);
			if (stamina_bar < PED::_GET_PED_MAX_STAMINA(Self::Mount))
				PED::_CHANGE_PED_STAMINA(Self::Mount, PED::_GET_PED_MAX_STAMINA(Self::Mount));
		}
	};

	static KeepHorseBarsFilled _KeepHorseBarsFilled{"keephorsebarsfilled", "Keep Horse Bars Filled", "Keeps your horse's Health and Stamina filled"};
}