#include "core/commands/LoopedCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Enums.hpp"
#include "game/features/Features.hpp"

namespace YimMenu::Features
{
    //Needs testing
	class AntiLasso : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int) eLassoFlags::LHF_CAN_BE_LASSOED, false);
            PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int) eLassoFlags::LHF_CAN_BE_LASSOED_BY_FRIENDLY_AI, false);
            PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int) eLassoFlags::LHF_CAN_BE_LASSOED_BY_FRIENDLY_PLAYERS, false);
            PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int) eLassoFlags::LHF_DISABLE_IN_MP, true);
		}

		//Doesn't work
		virtual void OnDisable() override
		{
			PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int) eLassoFlags::LHF_CAN_BE_LASSOED, true);
            PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int) eLassoFlags::LHF_CAN_BE_LASSOED_BY_FRIENDLY_AI, true);
            PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int) eLassoFlags::LHF_CAN_BE_LASSOED_BY_FRIENDLY_PLAYERS, true);
            PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int) eLassoFlags::LHF_DISABLE_IN_MP, false);
		}
	};

	static AntiLasso _AntiLasso{"antilasso", "Anti Lasso", "Avoid getting lasso'd by other players"};
}