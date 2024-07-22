#include "core/commands/Command.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/Players.hpp"
#include "util/teleport.hpp"
#include "game/rdr/data/JailTeleports.hpp"

namespace YimMenu::Features
{
	class TpAllToJail : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto& [idx, player] : Players::GetPlayers()) 
			{
				std::srand(static_cast<unsigned int>(std::time(nullptr)));
				int randomIndex = std::rand() % Data::g_JailCells.size();
				
				auto it = Data::g_JailCells.begin();
				std::advance(it, randomIndex);

				rage::fvector3 cell = it->second;
				Teleport::TeleportPlayerToCoords(player, cell);
			}
		}
	};

	static TpAllToJail _TpAllToJail{"tpalltojail", "Teleport To Jail", "Teleport all players to a random Saint Denis jail cell"};
}