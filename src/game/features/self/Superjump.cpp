#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	class Superjump : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			MISC::SET_SUPER_JUMP_THIS_FRAME(Self::GetPed().GetHandle());
		}
	};

	static Superjump _Superjump{"superjump", "Superjump", "Jump higher than normal"};
}