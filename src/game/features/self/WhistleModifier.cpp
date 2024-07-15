#include "core/commands/LoopedCommand.hpp"
#include "core/commands/FloatCommand.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	static FloatCommand _WhistlePitch{"whistlepitch", "Whistle Pitch", "The pitch of your whistle", 0.0f, 1.0f, 0.0f};
	static FloatCommand _WhistleClarity{"whistleclarity", "Whistle Clarity", "The clarity of your whistle", 0.0f, 1.0f, 0.0f};
	static FloatCommand _WhistleShape{"whistleshape", "Whistle Shape", "The shape of your whistle", 0.0f, 10.0f, 0.0f};

	class WhistleOverride : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnTick() override
		{
			if (auto ped = Self::GetPed())
			{
				AUDIO::_SET_WHISTLE_CONFIG_FOR_PED(ped.GetHandle(), "Ped.WhistlePitch", _WhistlePitch.GetState());
				AUDIO::_SET_WHISTLE_CONFIG_FOR_PED(ped.GetHandle(), "Ped.WhistleClarity", _WhistleClarity.GetState());
				AUDIO::_SET_WHISTLE_CONFIG_FOR_PED(ped.GetHandle(), "Ped.WhistleShape", _WhistleShape.GetState());
			}
		}
	};

	static WhistleOverride _WhistleOverride{"overridewhistle", "Modify Whistles", "Modify your whistle tone"};
}