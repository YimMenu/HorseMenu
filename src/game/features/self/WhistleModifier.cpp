#include "game/frontend/submenus/Self.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "game/features/Features.hpp"

namespace YimMenu::Features
{
	class WhistleOverride : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			AUDIO::_SET_WHISTLE_CONFIG_FOR_PED(Self::PlayerPed, "Ped.WhistlePitch", SelfStorage::pitch);
			AUDIO::_SET_WHISTLE_CONFIG_FOR_PED(Self::PlayerPed, "Ped.WhistleClarity", SelfStorage::clarity);
			AUDIO::_SET_WHISTLE_CONFIG_FOR_PED(Self::PlayerPed, "Ped.WhistleShape", SelfStorage::shape);
		}
	};

	static WhistleOverride _WhistleOverride{"overridewhistle", "Whistle Modifier", "Modify your whistle tone"};
}