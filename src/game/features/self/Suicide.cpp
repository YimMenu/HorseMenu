#include "core/commands/Command.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"

#include "game/backend/Players.hpp"
#include <script/scriptId.hpp>
#include <network/rlGamerHandle.hpp>
#include <network/rlGamerInfo.hpp>

#include "core/frontend/Notifications.hpp"
#include "core/commands/Commands.hpp"

namespace YimMenu::Features
{
	class Suicide : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			static int test = 0;
			if (ImGui::Button("Test"))
			{
				Notifications::Show(
				    "Hello",
				    std::string("Kys").append(std::to_string(test)),
				    NotificationType::Info,
				    5000,
				    [=] {
					    Commands::GetCommand("suicide"_J)->Call();
				    },
				    "Suicide");
				test++;
			}

			#if 0
			ENTITY::SET_ENTITY_INVINCIBLE(Self::PlayerPed, false);
			ENTITY::SET_ENTITY_HEALTH(Self::PlayerPed, 0, 0);
			#endif
		}
	};

	static Suicide _Suicide{"suicide", "Suicide", "Kills you"};
}