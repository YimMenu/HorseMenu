#include "core/commands/Command.hpp"
#include "game/rdr/Pools.hpp"

namespace YimMenu::Features
{
	class KillAllEnemies : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto ped : Pools::GetPeds())
			{
				if (!ped.IsPlayer() && ped.IsEnemy())
					ped.Kill();
			}
		}
	};

	static KillAllEnemies _KillAllEnemies{"killallenemies", "Kill All Enemies", "Kills all enemies in the game world"};
}