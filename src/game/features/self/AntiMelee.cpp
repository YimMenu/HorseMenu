#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"


namespace YimMenu::Features
{

	class AntiMelee : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (Self::GetPed())
			{
				for (int i = 0; i < 35; i++)
				{
					PED::_SET_PED_TARGET_ACTION_DISABLE_FLAG(Self::GetPed().GetHandle(), i);
				}
			}
		}

		virtual void OnDisable() override
		{
			if (Self::GetPed())
			{
				for (int i = 0; i < 35; i++)
				{
					PED::_CLEAR_PED_TARGET_ACTION_DISABLE_FLAG(Self::GetPed().GetHandle(), i);
				}
			}
		}
	};

	static AntiMelee _AntiMelee{"antimelee", "Anti Melee", "Disables getting assaulted by other players."};
}