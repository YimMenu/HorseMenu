#include "core/commands/LoopedCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"


namespace YimMenu::Features
{
	class Drunk : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			AUDIO::SET_PED_IS_DRUNK(Self::PlayerPed, TRUE);
			PED::_SET_PED_DRUNKNESS(Self::PlayerPed, TRUE, 1.0f);
		}

		virtual void OnDisable() override
		{
			if (PED::_GET_PED_DRUNKNESS(Self::PlayerPed))
			{
				AUDIO::SET_PED_IS_DRUNK(Self::PlayerPed, TRUE);
				PED::_SET_PED_DRUNKNESS(Self::PlayerPed, TRUE, 0.0f);
			}
		}
	};

	static Drunk _Drunk{"drunk", "Drunk", "Sets the player to be drunk"};
}