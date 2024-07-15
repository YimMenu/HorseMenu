#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class Superpunch : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(Self::GetPlayer().GetId(), 100.0f);
		}

		virtual void OnDisable() override
		{
			PLAYER::SET_PLAYER_MELEE_WEAPON_DAMAGE_MODIFIER(Self::GetPlayer().GetId(), 1.0f);
		}
	};

	static Superpunch _Superpunch{"superpunch", "Superpunch", "Makes your punches 100x more powerful"};
}