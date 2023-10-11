#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class HorseInvincibility : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			ENTITY::SET_ENTITY_INVINCIBLE(Self::Mount, true);
		}

        virtual void OnDisable() override
        {
            PED::SET_PED_CAN_RAGDOLL(Self::Mount, false);
        }
	};

	static HorseInvincibility _HorseInvincibility{"horseinvincibility", "Horse Invincibility", "Your horse will be invincible"};
}