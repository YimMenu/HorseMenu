#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	//WEAPON::_SET_PED_INFINITE_AMMO_CLIP Changes too many things to be considered, such as granting all ammo types.
	class InfiniteClip : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			Hash current_weapon = WEAPON::_GET_PED_CURRENT_HELD_WEAPON(Self::PlayerPed);
			int current_clip_ammo{};

			WEAPON::GET_AMMO_IN_CLIP(Self::PlayerPed, &current_clip_ammo, current_weapon);

			auto clip_size = WEAPON::GET_WEAPON_CLIP_SIZE(current_weapon);

			if (current_clip_ammo < clip_size)
				WEAPON::_REFILL_AMMO_IN_CURRENT_PED_WEAPON(Self::PlayerPed);
		}
	};

	static InfiniteClip _InfiniteClip{"infiniteclip", "Infinite Clip", "Have an endless clip in your gun"};
}