#include "core/commands/BoolCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/hooking/DetourHook.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/PlayerDatabase.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Packet.hpp"
#include "game/rdr/Player.hpp"
#include "game/rdr/data/MessageTypes.hpp"
#include "util/Chat.hpp"
#include "util/Helpers.hpp"
#include "core/frontend/widgets/imgui_colors.h"

#include <array>
#include <network/CNetGamePlayer.hpp>
#include <network/CNetworkScSession.hpp>
#include <network/InFrame.hpp>
#include <network/rlGamerHandle.hpp>
#include <network/rlScPeerConnection.hpp>
#include <rage/datBitBuffer.hpp>


namespace YimMenu::Features
{
	BoolCommand _LogPackets("logpackets", "Log Packets", "Log Packets");
	BoolCommand _LockLobby("locklobby", "Lock Lobby", "Allows no one to enter your session");
}

namespace YimMenu::Hooks
{
	static bool GetMessageType(NetMessageType& type, rage::datBitBuffer& buffer)
	{
		if (buffer.Read<int>(14) != '2F')
			return false;
		bool extended = buffer.Read<bool>(1);
		type          = buffer.Read<NetMessageType>(extended ? 16 : 8);
		return true;
	}

	static void LogFrame(rage::netConnection::InFrame* frame)
	{
		// TODO: reverse new endpoint system for sender data
		rage::datBitBuffer buffer(frame->m_Data, frame->m_Length);
		buffer.m_FlagBits |= 1u;

		NetMessageType msg_type;
		GetMessageType(msg_type, buffer);

		static constexpr const auto unloggables = std::to_array({NetMessageType::CLONE_SYNC, NetMessageType::PACKED_CLONE_SYNC_ACKS, NetMessageType::PACKED_EVENTS, NetMessageType::PACKED_RELIABLES, NetMessageType::PACKED_EVENT_RELIABLES_MSGS, NetMessageType::NET_ARRAY_MGR_UPDATE, NetMessageType::NET_ARRAY_MGR_UPDATE_ACK, NetMessageType::NET_ARRAY_MGR_SPLIT_UPDATE_ACK, NetMessageType::NET_TIME_SYNC, NetMessageType::SCRIPT_JOIN, NetMessageType::SCRIPT_JOIN_ACK, NetMessageType::SCRIPT_JOIN_HOST_ACK, NetMessageType::SCRIPT_HANDSHAKE, NetMessageType::SCRIPT_BOT_HANDSHAKE_ACK});
		if (std::find(unloggables.begin(), unloggables.end(), msg_type) == unloggables.end())
		{
			std::string player_name = std::format("{}.{}.{}.{}:{}",
			    frame->m_Address.m_external_ip.m_field1,
			    frame->m_Address.m_external_ip.m_field2,
			    frame->m_Address.m_external_ip.m_field3,
			    frame->m_Address.m_external_ip.m_field4,
			    frame->m_Address.m_external_port);
			std::string msg_name    = std::format("0x{:X}", (int)msg_type);
			if (auto it = Data::g_MessageTypes.find((int)msg_type); it != Data::g_MessageTypes.end())
				msg_name = it->second;

			auto session = (*Pointers.ScSession)->m_SessionMultiplayer;
			if (session && frame->m_MsgId != -1)
			{
				for (int i = 0; i < 32; i++)
				{
					if (session->GetPlayerByIndex(i) && session->GetPlayerByIndex(i)->m_SessionPeer->m_Connection
					    && session->GetPlayerByIndex(i)->m_SessionPeer->m_Connection->m_MessageId == frame->m_MsgId)
					{
						if (session->GetPlayerByIndex(i)->m_HasGamerInfo)
							player_name = session->GetPlayerByIndex(i)->m_GamerInfo.m_Name;
						break;
					}
				}
			}

			LOGF(VERBOSE, "PKT: {} [sz: {}, cxn: {}] from {}", msg_name, frame->m_Length, frame->m_ConnectionId, player_name);
		}
	}

	bool Protections::ReceiveNetMessage(void* a1, rage::netConnectionManager* ncm, rage::netConnection::InFrame* frame)
	{
		if (frame->GetEventType() != rage::netConnection::InFrame::EventType::FrameReceived)
		{
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()->Original()(a1, ncm, frame);
		}

		if (frame->m_Data == nullptr || frame->m_Length == 0)
		{
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()->Original()(a1, ncm, frame);
		}

		rage::datBitBuffer buffer(frame->m_Data, frame->m_Length);
		buffer.m_FlagBits |= 1u;

		NetMessageType msg_type;

		CNetworkScSessionPlayer* player = nullptr;

		auto session = (*Pointers.ScSession)->m_SessionMultiplayer;
		if (session)
		{
			if (frame->m_MsgId != -1)
			{
				for (int i = 0; i < 32; i++)
				{
					if (session->GetPlayerByIndex(i) && session->GetPlayerByIndex(i)->m_SessionPeer->m_Connection
					    && session->GetPlayerByIndex(i)->m_SessionPeer->m_Connection->m_MessageId == frame->m_MsgId)
					{
						player = session->GetPlayerByIndex(i);
						break;
					}
				}
			}
			else
			{
				if (frame->m_Address.m_connection_type == 1)
				{
					for (int i = 0; i < 32; i++)
					{
						if (session->GetPlayerByIndex(i) && session->GetPlayerByIndex(i)->m_SessionPeer->m_Connection)
						{
							if (auto addr = Pointers.GetPeerAddressByMessageId(ncm, session->GetPlayerByIndex(i)->m_SessionPeer->m_Connection->m_MessageId); addr && addr->m_external_ip.m_packed == frame->m_Address.m_external_ip.m_packed)
							{
								player = session->GetPlayerByIndex(i);
								break;
							}
						}
					}
				}
				else if (frame->m_Address.m_connection_type == 2)
				{
					for (int i = 0; i < 32; i++)
					{
						if (session->GetPlayerByIndex(i))
						{
							if (auto addr = Pointers.GetPeerAddressByMessageId(ncm, session->GetPlayerByIndex(i)->m_SessionPeer->m_Connection->m_MessageId); addr && addr->m_relay_address.m_packed == frame->m_Address.m_relay_address.m_packed)
							{
								player = session->GetPlayerByIndex(i);
								break;
							}
						}
					}
				}
			}
		}

		if (frame->m_ConnectionId == 2 && frame->m_Length >= 12 && player)
		{
			if (*(uint64_t*)(((uint64_t)frame->m_Data) + 4) != player->m_GamerInfo.m_GamerHandle2.m_RockstarId)
			{
				*(uint64_t*)(((uint64_t)frame->m_Data) + 4) = player->m_GamerInfo.m_GamerHandle2.m_RockstarId;
				if (auto p = Players::GetByMessageId(frame->m_MsgId))
					p.AddDetection(Detection::SPOOFING_VC);
			}

			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()->Original()(a1, ncm, frame);
		}

		if (!GetMessageType(msg_type, buffer))
		{
			return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()->Original()(a1, ncm, frame);
		}

		if (Features::_LogPackets.GetState())
		{
			LogFrame(frame);
		}

		switch (msg_type)
		{
		case NetMessageType::TEXT_CHAT:
		{
			char message[256];
			uint64_t senderHostToken;
			Helpers::ReadString(message, sizeof(message) * 8, &buffer);
			senderHostToken = buffer.Read<uint64_t>(64);
			buffer.Read<bool>(1);

			if (player && player->m_HasGamerInfo)
			{
				auto color = ImGui::Colors::LightBlue;

				if (auto p = Players::GetByMessageId(frame->m_MsgId); p && !p.IsFriend())
					color = ImGui::Colors::Red;

				RenderChatMessage(message, player->m_GamerInfo.m_Name, color);
			}
			break;
		}
		case NetMessageType::RESET_POPULATION:
		{
			if (!player || !player->m_SessionPeer->m_IsHost)
			{
				if (player)
				{
					if (auto p = Players::GetByMessageId(frame->m_MsgId))
						p.AddDetection(Detection::TRIED_KICK_PLAYER);

					Notifications::Show("Protections", std::string("Blocked Reset Population Kick from ").append(player->m_GamerInfo.m_Name), NotificationType::Warning);
				}

				return true;
			}
			break;
		}
		case NetMessageType::TEXT_CHAT_STATUS:
		{
			return true;
		}
		case NetMessageType::CONNECT_REQUEST:
		{
			if (*Pointers.IsSessionStarted && Features::_LockLobby.GetState())
			{
				LOG(WARNING) << "Denying a player from joining";
				return true;
			}
			break;
		}
		case NetMessageType::NET_ICE_SESSION_OFFER:
		{
			if (player)
			{
				if (!player->m_Initialized)
					break;

				// this should ideally *never* happen, but let's check for the peer ID mismatch just in case

				auto version = buffer.Read<uint8_t>(8);
				auto v1 = buffer.Read<uint32_t>(32);
				auto v2 = buffer.Read<uint32_t>(32);
				auto peer_id = buffer.Read<uint64_t>(64);

				if (peer_id != player->m_GamerInfo.m_PeerId)
				{
					if (auto p = Players::GetByMessageId(frame->m_MsgId))
						p.AddDetection(Detection::TRIED_KICK_PLAYER);

					Notifications::Show("Protections", std::format("Blocked ICE kick from {}", player->m_GamerInfo.m_Name), NotificationType::Warning);
					return true;
				}
			}
			else
			{
				// now this is a... weirder case. if we let this go, then this peer could overwrite those who've already joined us

				auto version = buffer.Read<uint8_t>(8);
				auto v1      = buffer.Read<uint32_t>(32);
				auto v2      = buffer.Read<uint32_t>(32);
				auto peer_id = buffer.Read<uint64_t>(64);

				for (auto& [id, plyr] : Players::GetPlayers())
				{
					if (plyr.GetGamerInfo()->m_PeerId == peer_id)
					{
						// this will cause a takeover
						Notifications::Show("Protections", "Blocked ICE kick from unknown player", NotificationType::Warning);
						return true;
					}
				}
			}
			break;
		}
		}

		return BaseHook::Get<Protections::ReceiveNetMessage, DetourHook<decltype(&Protections::ReceiveNetMessage)>>()->Original()(a1, ncm, frame);
	}
}