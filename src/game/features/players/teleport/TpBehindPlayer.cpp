#include "game/backend/Self.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "game/features/Features.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Features
{
	class TpBehindPlayer : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			auto pos        = player.GetPed().GetPosition();
			auto forward    = ENTITY::GET_ENTITY_FORWARD_VECTOR(player.GetPed().GetHandle());
			float distance  = -7.5f;
			rage::fvector3 coords{pos.x + (forward.x * distance), pos.y + (forward.y * distance), pos.z + .75f};

			if (Teleport::TeleportEntity(Self::GetPed().GetHandle(), {coords.x, coords.y, coords.z}, false))
				g_Spectating = false;
		}
	};

	static TpBehindPlayer _TpBehindPlayer{"tpbehindplayer", "Teleport Behind Player", "Teleport behind the player"};
}