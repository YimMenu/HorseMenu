#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"


namespace YimMenu::Features
{
	class Drunk : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetPed())
			{
				AUDIO::SET_PED_IS_DRUNK(Self::GetPed().GetHandle(), true);
				PED::_SET_PED_DRUNKNESS(Self::GetPed().GetHandle(), true, 1.0f);
			}
		}

		virtual void OnDisable() override
		{
			if (Self::GetPed().GetHandle())
			{
				AUDIO::SET_PED_IS_DRUNK(Self::GetPed().GetHandle(), false);
				PED::_SET_PED_DRUNKNESS(Self::GetPed().GetHandle(), false, 1.0f);
			}
		}
	};

	static Drunk _Drunk{"drunk", "Drunk", "Sets the player to be drunk"};
}