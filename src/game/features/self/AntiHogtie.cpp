#include "core/commands/LoopedCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Enums.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
    //Needs testing
	class AntiHogtie : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			ENTITY::_SET_ENTITY_CARRYING_FLAG(Self::GetPed().GetHandle(), (int)CarryingFlags::CARRYING_FLAG_CAN_BE_HOGTIED, false);
           
		}

		virtual void OnDisable() override
		{
			ENTITY::_SET_ENTITY_CARRYING_FLAG(Self::GetPed().GetHandle(), (int)CarryingFlags::CARRYING_FLAG_CAN_BE_HOGTIED, true);
		}
	};

	static AntiHogtie _AntiHogtie{"antihogtie", "Anti Hogtie", "Disable getting hogtied by other players"};
}