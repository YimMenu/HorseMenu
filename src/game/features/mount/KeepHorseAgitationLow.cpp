#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	//Horse still kicks player off on max agitation on online
	class KeepHorseAgitationLow : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			auto mount = Self::GetMount();
			if (!mount || mount.IsDead())
				return;

			auto agitation = mount.GetMotivation(MotivationState::AGITATION_STATE);

			if (agitation > 0)
				mount.SetMotivation(MotivationState::AGITATION_STATE, 0.0f);
		}
	};

	static KeepHorseAgitationLow _KeepHorseAgitationLow{"keephorseagitationlow", "Keep Horse Agitation Low", "Keeps your horse from getting agitated"};
}
