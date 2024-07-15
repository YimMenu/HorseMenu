#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class Invis : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetPed())
			{
				Self::GetPed().SetVisible(false);
				NETWORK::SET_PLAYER_VISIBLE_LOCALLY(Self::GetPlayer().GetId(), true);
			}
		}

		virtual void OnDisable() override
		{
			if (Self::GetPed())
			{
				Self::GetPed().SetVisible(true);
				NETWORK::SET_PLAYER_VISIBLE_LOCALLY(Self::GetPlayer().GetId(), false);
			}
		}
	};

	static Invis _Invis{"invis", "Invisibility", "Be invisible"};
}