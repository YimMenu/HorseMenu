#include "core/commands/Command.hpp"
#include "core/commands/BoolCommand.hpp"
#include "core/commands/Vector3Command.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/rdr/Natives.hpp"
#include "core/frontend/Notifications.hpp"

#include <network/rlScSession.hpp>

namespace Terminus::Features
{
	static Vector3Command _MatchmakingPosition{"newsessionpos", "Matchmaking Position", "Game position to matchmake around"};
	static BoolCommand _JoinRandomPosse{"newsessionposse", "Join Random Posse", "Automatically join a random open posse when entering a new session"};
	static BoolCommand _JoinPrivate{"newsessionprivate", "Private Session", "Sets the session to Private (Solo Public)"};

	class JoinNewSession : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			if (_JoinPrivate.GetState())
			{
				char id[36]{};
				if (NETWORK::NETWORK_SESSION_REQUEST_SESSION_PRIVATE(0, 32, 0, (Any*)&id))
				{
					while (NETWORK::NETWORK_SESSION_IS_REQUEST_IN_PROGRESS(&id))
					{
						if (NETWORK::NETWORK_SESSION_IS_REQUEST_PENDING_TRANSITION(&id))
							NETWORK::_NETWORK_SESSION_TRANSITION_TO_SESSION(&id);

						ScriptMgr::Yield();
					}

					ScriptMgr::Yield(3000ms);

					bool isSessionActive = NETWORK::NETWORK_IS_SESSION_ACTIVE();
					bool isSessionPrivate = NETWORK::NETWORK_SESSION_IS_PRIVATE();

					if (isSessionActive && isSessionPrivate)
					{
						NETWORK::NETWORK_SESSION_REMOVE_SESSION_FLAGS(4 | 8 | 16 | 32 | 64 | 128 | 256 | 512 | 1024 | 2048);
						NETWORK::_NETWORK_SESSION_ADD_SESSION_FLAGS(1 | 2);
						Notifications::Show("Session", "Session flags set to SF_INSTANCE | SF_MATCH!", NotificationType::Info);

						int sessionFlags = NETWORK::NETWORK_SESSION_GET_SESSION_FLAGS();
						Notifications::Show("Session", "Session is now joinable by anyone! Current Flags: " + std::to_string(sessionFlags), NotificationType::Success);
					}
					else
					{
						int sessionFlags = NETWORK::NETWORK_SESSION_GET_SESSION_FLAGS();
						Notifications::Show("Session", "Failed to make session public.  Current Flags: " + std::to_string(sessionFlags), NotificationType::Error);
					}
				}
			}
			else
			{
				int flags = 0;
				auto pos = _MatchmakingPosition.GetState();

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
		}
	};

	static JoinNewSession _JoinNewSession{"newsession", "Join New Session", "Seamlessly joins a new session"};
}