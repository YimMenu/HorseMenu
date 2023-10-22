#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	//TODO: OnDisable doesn't call if menu is unloaded prematurely
	class Invis : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			ENTITY::SET_ENTITY_VISIBLE(Self::PlayerPed, false);
			NETWORK::SET_PLAYER_VISIBLE_LOCALLY(Self::Id, true);
		}

		virtual void OnDisable() override
		{
			ENTITY::SET_ENTITY_VISIBLE(Self::PlayerPed, true);
			NETWORK::SET_PLAYER_VISIBLE_LOCALLY(Self::Id, true);
		}
	};

	static Invis _Invis{"invis", "Invisibility", "Be invisible"};
}