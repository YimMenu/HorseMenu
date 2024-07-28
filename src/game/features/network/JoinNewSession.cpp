#include "core/commands/Command.hpp"
#include "core/commands/BoolCommand.hpp"
#include "core/commands/Vector3Command.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/rdr/Natives.hpp"

#include <network/rlScSession.hpp>

namespace YimMenu::Features
{
	static Vector3Command _MatchmakingPosition{"newsessionpos", "Matchmaking Position", "Game position to matchmake around"};
	static BoolCommand _JoinRandomPosse{"newsessionposse", "Join Random Posse", "Automatically join a random open posse when entering a new session"};

	class JoinNewSession : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			int flags = 0;
			auto pos  = _MatchmakingPosition.GetState();

			if (_JoinRandomPosse.GetState())
				flags |= 32;

			char id[36]{};
			Pointers.RequestSessionSeamless(*Pointers.ScSession, (rage::rlScSessionId*)&id, flags, &pos, 0);

			while (NETWORK::NETWORK_SESSION_IS_REQUEST_IN_PROGRESS(&id))
			{
				if (NETWORK::NETWORK_SESSION_IS_REQUEST_PENDING_TRANSITION(&id))
					NETWORK::_NETWORK_SESSION_TRANSITION_TO_SESSION(&id);

				ScriptMgr::Yield();
			}
		}
	};

	static JoinNewSession _JoinNewSession{"newsession", "Join New Session", "Seamlessly joins a new session"};
}