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
			PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int)eLassoFlags::LHF_CAN_BE_LASSOED, FALSE);
			PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int)eLassoFlags::LHF_CAN_BE_LASSOED_BY_FRIENDLY_AI, FALSE);
			PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int)eLassoFlags::LHF_CAN_BE_LASSOED_BY_FRIENDLY_PLAYERS, FALSE);
			PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int)eLassoFlags::LHF_DISABLE_IN_MP, FALSE);
		}

		virtual void OnDisable() override
		{
			PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int) eLassoFlags::LHF_CAN_BE_LASSOED, TRUE);
			PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int)eLassoFlags::LHF_CAN_BE_LASSOED_BY_FRIENDLY_AI, TRUE);
			PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int)eLassoFlags::LHF_CAN_BE_LASSOED_BY_FRIENDLY_PLAYERS, TRUE);
			PED::SET_PED_LASSO_HOGTIE_FLAG(Self::PlayerPed, (int)eLassoFlags::LHF_DISABLE_IN_MP, TRUE);
		}
	};

	static AntiLasso _AntiLasso{"antilasso", "Anti Lasso", "Avoid getting lasso'd by other players"};
}