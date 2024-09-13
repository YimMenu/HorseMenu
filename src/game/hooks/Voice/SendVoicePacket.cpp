#include "core/hooking/CallHook.hpp"
#include "game/hooks/Hooks.hpp"
#include "game/rdr/Natives.hpp"
#include "game/backend/Players.hpp"
#include "core/commands/BoolCommand.hpp"
#include "game/backend/Voice.hpp"
#include "util/Storage/Spoofing.hpp"

#include <network/rlGamerInfo.hpp>
#include <network/CNetworkPlayerMgr.hpp>

namespace YimMenu::Features
{
	static BoolCommand _VoiceChatOverride{"voicechatoverride", "VC Override", "Plays the audio.wav file in the project folder through voice chat. The wave file must be encoded with a mono 16 bit 16kHz PCM format. You have to reset voice chat settings whenever you load the menu for the sound to play"};
	static BoolCommand _HideVoiceChatSender{"hidevcsender", "Hide VC Sender", "Prevents your name from appearing for other players when you are talking through voice chat. This only takes effect if sender spoofing is disabled"};
	static BoolCommand _ForceSendVoiceChat{"forcesendvc", "Force Send VC", "Attempts to bypass mutes and other local restrictions on remote peers"};
}

namespace YimMenu::Hooks
{
	static Player GetPlayerFromPeerAddress(rage::netPeerAddress* address)
	{
		for (auto& [_, player] : Players::GetPlayers())
		{
			if (player.GetExternalAddress().m_packed == address->m_external_ip.m_packed)
			{
				return player;
			}
		}

		return nullptr;
	}

	static std::uint64_t g_LastVoiceTickCount = 0;
	void Voice::SendVoicePacket(void* net_cxn_mgr, rage::netPeerAddress* address, int voice_cxn, void* packet, int size, int flags)
	{
		uint64_t* sender = reinterpret_cast<std::uint64_t*>(reinterpret_cast<std::uint64_t>(packet) + 4);
		auto target      = GetPlayerFromPeerAddress(address);
		auto fake_sender = YimMenu::Voice::GetSpoofingPlayer();

		if (Features::_ForceSendVoiceChat.GetState())
		{
			// case 1 (force broadcast)
			if (g_LastVoiceTickCount != GetTickCount64())
			{
				g_LastVoiceTickCount = GetTickCount64();
				for (auto& [_, player] : Players::GetPlayers())
				{
					if (fake_sender)
					{
						*sender = fake_sender.GetRID();
					}
					else if (Features::_HideVoiceChatSender.GetState())
					{
						*sender = player.GetRID();
					}

					auto new_address = Pointers.GetPeerAddressByMessageId(Pointers.NetworkPlayerMgr->m_NetConnectionManager, player.GetMessageId());
					if (new_address)
						BaseHook::Get<Voice::SendVoicePacket, CallHook<decltype(&Voice::SendVoicePacket)>>()->Original()(net_cxn_mgr, new_address, voice_cxn, packet, size, flags);
				}
			}
		}
		else
		{
			// case 2 (vanilla)
			if (fake_sender)
			{
				*sender = fake_sender.GetRID();
			}
			else if (Features::_HideVoiceChatSender.GetState() && target)
			{
				*sender = target.GetRID();
			}

			return BaseHook::Get<Voice::SendVoicePacket, CallHook<decltype(&Voice::SendVoicePacket)>>()->Original()(net_cxn_mgr, address, voice_cxn, packet, size, flags);
		}
	}
}