#include "core/frontend/Notifications.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Ped.hpp"


namespace YimMenu::Features
{

	class RemoteBolas : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			bool canUseBolas = PED::_GET_PED_LASSO_HOGTIE_FLAG(player.GetPed().GetHandle(), (int)LassoFlags::LHF_CAN_BE_LASSOED)
			    && !PED::_GET_PED_LASSO_HOGTIE_FLAG(player.GetPed().GetHandle(), (int)LassoFlags::LHF_DISABLE_IN_MP);
			if (canUseBolas)
			{
				auto striker = Ped::Create("cs_brendacrawley"_J,
				    player.GetPed().GetPosition() - Vector3(5, 0, 0),
				    player.GetPed().GetRotation().z);

				striker.SetVisible(false);

				const auto strikerPos = striker.GetPosition();
				const auto targetPos  = player.GetPed().GetPosition();

				MISC::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(strikerPos.x,
				    strikerPos.y,
				    strikerPos.z,
				    targetPos.x,
				    targetPos.y,
				    targetPos.z,
				    0,
				    true,
				    "weapon_thrown_bolas_ironspiked"_J,
				    striker.GetHandle(),
				    false,
				    false,
				    100.f,
				    true);

				striker.ForceControl();
				striker.Delete();
			}
			else
			{
				Notifications::Show("Remote Bolas", "This player has bolas protections enabled!", NotificationType::Error);
			}
		}
	};

	static RemoteBolas _RemoteBolas{"remotebolas", "Remote Bolas", "Remotely strike the player with bolas"};
}