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
			ENTITY::SET_ENTITY_VISIBLE(Self::PlayerPed, FALSE);
			NETWORK::SET_PLAYER_VISIBLE_LOCALLY(Self::Id, TRUE);
		}

		virtual void OnDisable() override
		{
			ENTITY::SET_ENTITY_VISIBLE(Self::PlayerPed, TRUE);
			NETWORK::SET_PLAYER_VISIBLE_LOCALLY(Self::Id, TRUE);
		}
	};

	static Invis _Invis{"invis", "Invisibility", "Be invisible"};
}