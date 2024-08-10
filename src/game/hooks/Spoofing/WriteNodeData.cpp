#include "core/commands/BoolCommand.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Nodes.hpp"

#include <network/netObject.hpp>
#include <network/sync/CProjectBaseSyncDataNode.hpp>
#include <network/sync/player/CPlayerAppearanceData.hpp>
#include <network/sync/player/CPlayerCameraUncommonData.hpp>
#include <network/sync/player/CPlayerCreationData.hpp>
#include <network/sync/player/CPlayerGameStateUncommonData.hpp>
#include <network/sync/player/CPlayerHealthData.hpp>
#include <rage/datBitBuffer.hpp>

namespace YimMenu::Features
{
	BoolCommand _HideGod("hidegod", "Hide Godmode", "Hides godmode from other players", true);
	BoolCommand _HideSpectate("hidespectate", "Hide Spectate", "Hides spectate from other players", true);
}

namespace YimMenu::Hooks
{
	void Spoofing::WriteNodeData(CProjectBaseSyncDataNode* node, rage::netObject* object, rage::datBitBuffer* buffer, void* logger, bool update)
	{
		auto orig_buffer = *buffer;
		bool node_dirty  = false;
		BaseHook::Get<Spoofing::WriteNodeData, DetourHook<decltype(&Spoofing::WriteNodeData)>>()->Original()(node, object, buffer, logger, update);

		Nodes::Init();
		const auto& id = Nodes::Find((NetObjType)object->m_ObjectType, reinterpret_cast<uint64_t>(node));

		switch (id.id)
		{
		case "CPlayerHealthNode"_J:
		{
			if (Features::_HideGod.GetState())
			{
				auto& data = node->GetData<CPlayerHealthData>();
				memset(&data, 0, sizeof(data));
				data.m_Unused = 100.0f;
				node_dirty    = true;
			}
			break;
		}
		case "CPlayerCameraUncommonNode"_J:
		{
			if (Features::_HideSpectate.GetState())
			{
				auto& data          = node->GetData<CPlayerCameraUncommonData>();
				data.m_IsSpectating = false;
				node_dirty          = true;
			}
			break;
		}
		case "CPlayerGameStateUncommonNode"_J:
		{
			if (Features::_HideSpectate.GetState())
			{
				auto& data                   = node->GetData<CPlayerGameStateUncommonData>();
				data.m_IsSpectating          = false;
				data.m_IsSpectatingStaticPos = false;
				data.m_SpectatePos           = {};
				data.m_SpectatorId           = 0;
				node_dirty                   = true;
			}
			break;
		}
		}

		if (node_dirty)
		{
			*buffer = orig_buffer;
			BaseHook::Get<Spoofing::WriteNodeData, DetourHook<decltype(&Spoofing::WriteNodeData)>>()->Original()(node, object, buffer, logger, false);
		}
	}
}