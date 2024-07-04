#include "core/commands/LoopedCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/ScriptGlobal.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	//TODO: fix this
	class OffTheRadar : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			DECORATOR::DECOR_SET_INT(Self::GetPed().GetHandle(), "MP_HUD_Hide_My_Blip_FOR_TEAMS", -1);
		}

		virtual void OnDisable() override
		{
			DECORATOR::DECOR_REMOVE(Self::GetPed().GetHandle(), "MP_HUD_Hide_My_Blip_FOR_TEAMS");
		}
	};

	static OffTheRadar _OffTheRadar{"offtheradar", "Off The Radar", "You won't show up on the maps of other players"};
}