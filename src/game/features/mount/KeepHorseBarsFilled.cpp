#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	class KeepHorseBarsFilled : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			auto mount = Self::GetMount();

			if (!mount || mount.IsDead())
				return;

			auto health_bar  = mount.GetHealth();
			auto stamina_bar = mount.GetStamina();

			if (health_bar < mount.GetMaxHealth())
				mount.SetHealth(mount.GetMaxHealth());
			if (stamina_bar < mount.GetMaxStamina())
				mount.SetStamina(mount.GetMaxStamina());
		}
	};

	static KeepHorseBarsFilled _KeepHorseBarsFilled{"keephorsebarsfilled", "Keep Horse Bars Filled", "Keeps your horse's Health and Stamina filled"};
}
