#include "core/commands/Command.hpp"
#include "game/features/Features.hpp"
#include "game/rdr/Natives.hpp"

#include "game/rdr/Nodes.hpp"
#include <network/sync/CProjectBaseSyncDataNode.hpp>

#include "game/rdr/Scripts.hpp"
#include "game/backend/Players.hpp"

#include "core/commands/Commands.hpp"
#include "game/commands/PlayerCommand.hpp"

namespace YimMenu::Features
{
	class Suicide : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{

			for (auto& p : Players::GetPlayers())
				Commands::GetCommand<PlayerCommand>("defensive"_J)->Call(p.second);

			//ENTITY::SET_ENTITY_INVINCIBLE(Self::PlayerPed, false);
			//ENTITY::SET_ENTITY_HEALTH(Self::PlayerPed, 0, 0);
			//auto func = (void(*)())1;
			//func();
			/*
			Nodes::Init();
			for (int i = 0; i < (int)eNetObjType::Max; i++)
			{
				for (auto& node : Nodes::GetNodesForType(eNetObjType(i)))
				{
					auto vft = *(int64_t**)node.first;
					auto commondataops = *(int64_t**)((CProjectBaseSyncDataNode*)(node.first))->m_CommonDataOpsVFT;

					LOG(INFO) << node.second.name << ":" << HEX((__int64)vft - (__int64)GetModuleHandle(0)) << ":" << HEX((__int64)commondataops - (__int64)GetModuleHandle(0));
				}
			}
			*/
		}
	};

	static Suicide _Suicide{"suicide", "Suicide", "Kills you"};
}