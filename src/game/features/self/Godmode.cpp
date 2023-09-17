#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class Godmode : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			ENTITY::SET_ENTITY_INVINCIBLE(Self::PlayerPed, true);
		}

		virtual void OnDisable() override
		{
			ENTITY::SET_ENTITY_INVINCIBLE(Self::PlayerPed, false);
		}
	};

	static Godmode _Godmode{"godmode", "God Mode", "Blocks all incoming damage"};
}