#include "core/commands/LoopedCommand.hpp"
#include "game/backend/NodeHooks.hpp"
#include "game/features/Features.hpp"

#include <network/sync/player/CPlayerHealthData.hpp>

namespace YimMenu::Features
{
	class HideGod : public BoolCommand
	{
		using BoolCommand::BoolCommand;

		std::shared_ptr<NodeHooks::Hook> m_Hook{};

		virtual void OnEnable() 
		{
			if (!m_Hook)
			{
				m_Hook = NodeHooks::AddHook("CPlayerHealthNode", [](rage::netObject* object, Player player) {
					return true;
				},
				[](rage::netObject* object, Player player, CProjectBaseSyncDataNode* node) {
					auto& data = node->GetData<CPlayerHealthData>();
					memset(&data, 0, sizeof(data));
					data.m_Unused = 100.0f;
				}); 
			}
			m_Hook->Enable();
		}

		virtual void OnDisable()
		{
			m_Hook->Disable();
		}
	};

	static HideGod _HideGod("hidegod", "Hide Godmode", "Hides godmode from other players", true);
}