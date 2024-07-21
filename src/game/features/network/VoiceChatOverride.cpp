#include "core/commands/LoopedCommand.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/Entity.hpp"

namespace YimMenu::Features
{
	class VoiceChatOverride : public LoopedCommand
	{
		using LoopedCommand::LoopedCommand;

		virtual void OnEnable() override
		{
		}

		virtual void OnTick() override
		{
			VOICE::_0x58125B691F6827D5(99999.0f);
		}

		virtual void OnDisable() override
		{
		}
	};

	static VoiceChatOverride _VoiceChatOverride{"voicechatoverride", "Voice Chat Override", "Plays the audio.wav file in the project folder through voice chat. The wave file must be encoded with a mono 16 bit 16kHz PCM format. You have to reset voice chat settings whenever you load the menu for the sound to play"};
}