#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class InfiniteClip : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			WEAPON::_SET_PED_INFINITE_AMMO_CLIP(Self::PlayerPed, TRUE);
		}

		virtual void OnDisable() override
		{
			WEAPON::_SET_PED_INFINITE_AMMO_CLIP(Self::PlayerPed, FALSE);
		}
	};

	static InfiniteClip _InfiniteClip{"infiniteclip", "Infinite Clip", "Have an endless clip in your gun"};
}