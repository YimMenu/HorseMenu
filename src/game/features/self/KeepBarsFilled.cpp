#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"

namespace YimMenu::Features
{
	static BoolCommand _Deadeye{"keepdeadeyefilled", "Deadeye", "Keep Deadeye Bar Filled", true};
	static BoolCommand _Stamina{"keepstaminafilled", "Stamina", "Keep Stamina Bar Filled", true};
	static BoolCommand _Health{"keephealthfilled", "Health", "Keep Health Bar Filled", true};

	class KeepBarsFilled : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			auto ped = Self::GetPed();
			if (!ped || ped.IsDead())
				return;

			auto health_bar  = ped.GetHealth();
			auto stamina_bar = PLAYER::_GET_PLAYER_STAMINA(Self::GetPlayer().GetId());
			auto deadeye_bar = PLAYER::_GET_PLAYER_DEAD_EYE(Self::GetPlayer().GetId());

			if (health_bar < ped.GetMaxHealth() && _Health.GetState())
				ped.SetHealth(ped.GetMaxHealth());
			if (stamina_bar < PED::_GET_PED_MAX_STAMINA(ped.GetHandle()) && _Stamina.GetState())
				PED::_CHANGE_PED_STAMINA(ped.GetHandle(), PED::_GET_PED_MAX_STAMINA(ped.GetHandle()) - stamina_bar);
			if (deadeye_bar < PLAYER::_GET_PLAYER_MAX_DEAD_EYE(Self::GetPlayer().GetId(), 0) && _Deadeye.GetState())
				PLAYER::_SPECIAL_ABILITY_RESTORE_BY_AMOUNT(Self::GetPlayer().GetId(),
				    PLAYER::_GET_PLAYER_MAX_DEAD_EYE(Self::GetPlayer().GetId(), false),
				    0,
				    0,
				    1);
		}
	};

	static KeepBarsFilled _KeepBarsFilled{"keepbarsfilled", "Keep Bars Filled", "Keeps your Health, Stamina and Deadeye filled"};
}