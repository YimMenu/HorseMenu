#include "core/commands/LoopedCommand.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Natives.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/BoolCommand.hpp"
#include "game/backend/Players.hpp"

namespace Terminus::Features
{
	class PlayMusic : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			//TODO: Add a dropdown selection to play music, this is just a test for now
			//TODO: Move this to a music manager class that can handle multiple music events and stop them when needed
			//TODO: Move this to a different section in the menu, this only works locally so maybe Self?
			const char* eventName = "FIN1_OPTION_A_HIGH_OS";


			bool isPrepared = AUDIO::PREPARE_MUSIC_EVENT(eventName);

			if (isPrepared)
			{
				AUDIO::TRIGGER_MUSIC_EVENT(eventName);
			}
		}
	};

	class StopMusic : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			const char* eventName = "MC_MUSIC_STOP";


			bool isPrepared = AUDIO::PREPARE_MUSIC_EVENT(eventName);

			if (isPrepared)
			{
				AUDIO::TRIGGER_MUSIC_EVENT(eventName);
			}
		}
	};

	static PlayMusic _PlayMusic{"playmusic", "Play Music", "Plays Arthurs last ride music"};
	static StopMusic _StopMusic{"stopmusic", "Stop Music", "Stops all music"};
}