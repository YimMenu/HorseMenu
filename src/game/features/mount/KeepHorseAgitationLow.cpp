#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class KeepHorseAgitationLow : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (!ENTITY::DOES_ENTITY_EXIST(Self::Mount))
				return;

			auto agitation = PED::_GET_PED_MOTIVATION(Self::Mount,(int) eMotivationState::AGITATION_STATE, 0);

			if (agitation > 0)
				PED::_SET_PED_MOTIVATION(Self::Mount, (int)eMotivationState::AGITATION_STATE, 0, 0);
		}
	};

	static KeepHorseAgitationLow _KeepHorseAgitationLow{"keephorseagitationlow", "Keep Horse Agitation Low", "Keeps your horse from getting agitated"};
}
