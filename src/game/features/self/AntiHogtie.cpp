#include "core/commands/LoopedCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Enums.hpp"

namespace YimMenu::Features
{
    //Needs testing
	class AntiHogtie : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			PED::_SET_ENTITY_CARRYING_FLAG(Self::PlayerPed, eCarryingFlags::CARRYING_FLAG_CAN_BE_HOGTIED, false);
           
		}

		virtual void OnDisable() override
		{
			PED::_SET_ENTITY_CARRYING_FLAG(Self::PlayerPed, eCarryingFlags::CARRYING_FLAG_CAN_BE_HOGTIED, true);
		}
	};

	static AntiHogtie _AntiHogtie{"antihogtie", "Anti Hogtie", "Avoid getting hogtied'd by other players"};
}