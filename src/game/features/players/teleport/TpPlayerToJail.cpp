#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "util/teleport.hpp"
#include "game/rdr/data/JailTeleports.hpp"

namespace YimMenu::Features
{
	class TpPlayerToJail : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));
			int randomIndex = std::rand() % Data::g_JailCells.size();

			auto it = Data::g_JailCells.begin();
			std::advance(it, randomIndex);

			rage::fvector3 cell = it->second;
			Teleport::TeleportPlayerToCoords(player, cell);
		}
	};

	static TpPlayerToJail _TpPlayerToJail{"tpplayertojail", "Teleport To Jail", "Teleport the player to a random Saint Denis jail cell"};
}