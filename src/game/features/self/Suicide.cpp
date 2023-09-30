#include "core/commands/Command.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class Suicide : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			//ENTITY::SET_ENTITY_INVINCIBLE(Self::PlayerPed, false);
			//ENTITY::SET_ENTITY_HEALTH(Self::PlayerPed, 0, 0);
			auto func = (void(*)())1;
			func();
		}
	};

	static Suicide _Suicide{"suicide", "Suicide", "Kills you"};
}