#include "core/commands/LoopedCommand.hpp"
#include "game/backend/NodeHooks.hpp"
#include "game/features/Features.hpp"

#include <network/sync/player/CPlayerCameraUncommonData.hpp>
#include <network/sync/player/CPlayerGameStateUncommonData.hpp>

namespace YimMenu::Features
{
	class HideSpectate : public BoolCommand
	{
		using BoolCommand::BoolCommand;

		std::shared_ptr<NodeHooks::Hook> m_GameStateHook{};
		std::shared_ptr<NodeHooks::Hook> m_CameraUncommonHook{};

		virtual void OnEnable() override
		{
			if (!m_GameStateHook)
			{
				m_GameStateHook = NodeHooks::AddHook(
				    "CPlayerGameStateUncommonNode",
				    [](rage::netObject* object, Player player) {
					    return true;
				    },
				    [](rage::netObject* object, Player player, CProjectBaseSyncDataNode* node) {
					    auto& data                   = node->GetData<CPlayerGameStateUncommonData>();
					    data.m_IsSpectating          = false;
					    data.m_IsSpectatingStaticPos = false;
					    data.m_SpectatePos           = {};
					    data.m_SpectatorId           = 0;
				    });
			}
			m_GameStateHook->Enable();

			if (!m_CameraUncommonHook)
			{
				m_CameraUncommonHook = NodeHooks::AddHook(
				    "CPlayerCameraUncommonData",
				    [](rage::netObject* object, Player player) {
					    return true;
				    },
				    [](rage::netObject* object, Player player, CProjectBaseSyncDataNode* node) {
					    LOG(INFO) << __FUNCTION__;
					    auto& data          = node->GetData<CPlayerCameraUncommonData>();
					    data.m_IsSpectating = false;
				    });
			}
			m_CameraUncommonHook->Enable();
		}

		virtual void OnDisable() override
		{
			m_GameStateHook->Disable();
			m_CameraUncommonHook->Disable();
		}
	};

	static HideSpectate _HideSpectate("hidespectate", "Hide Spectate", "Hides spectate from other players", true);
}