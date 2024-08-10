#include "Voice.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/BoolCommand.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/Self.hpp"
#include "game/backend/Voice.hpp"
#include "game/rdr/Packet.hpp"

#include <network/rlGamerInfo.hpp>

namespace YimMenu::Submenus
{
	static std::optional<std::vector<std::string>> g_AudioFiles;

	static void RefreshAudioFileMap()
	{
		g_AudioFiles = std::vector<std::string>();

		for (const auto& entry : std::filesystem::recursive_directory_iterator(Voice::GetAudioDirectory()))
		{
			g_AudioFiles->push_back(entry.path().filename().string());
		}
	}

	static void ResendVoiceInfoPackets()
	{
		Packet pkt;
		pkt.WriteMessageHeader(NetMessageType::VOICE_CHAT_STATUS);
		pkt.GetBuffer().Write(0x41, 9);
		pkt.GetBuffer().Write(0, 7);
		pkt.GetBuffer().Write(0, 7);
		
		Player player = Self::GetPlayer();
		if (Voice::GetSpoofingPlayer())
			player = Voice::GetSpoofingPlayer();

		player.GetGamerInfo()->m_GamerHandle2.Serialize(pkt);

		for (auto& [_, player] : Players::GetPlayers())
		{
			pkt.Send(player, 13); // or 7?
		}
	}

	void ShowVoiceFileSelectionMenu()
	{
		static auto override = Commands::GetCommand<BoolCommand>("voicechatoverride"_J);
		if (!override->GetState())
			return;

		if (!g_AudioFiles)
			RefreshAudioFileMap();

		ImGui::Text("Audio Files");
		ImGui::Text("Note that all files must be encoded with a mono 16 bit 16kHz PCM format");
		if (ImGui::BeginListBox("##files", {200, -1}))
		{
			for (const auto& name : g_AudioFiles.value())
			{
				if (ImGui::Selectable(name.data(), name == Voice::GetVoiceFile()))
				{
					if (name != Voice::GetVoiceFile())
						Voice::SetVoiceFile(name);
				}
			}

			ImGui::EndListBox();
		}

		if (ImGui::Button("Refresh"))
		{
			RefreshAudioFileMap();
		}
	}

	void ShowVoiceSpoofingMenu()
	{
		auto player_name = Voice::GetSpoofingPlayer().IsValid() ? Voice::GetSpoofingPlayer().GetName() : "Disabled";
		ImGui::SetNextItemWidth(150);
		if (ImGui::BeginCombo("Spoof Sender", player_name))
		{
			if (ImGui::Selectable("Disabled", !Voice::GetSpoofingPlayer().IsValid()))
			{
				Voice::SetSpoofingPlayer(nullptr);
				FiberPool::Push([] {
					ResendVoiceInfoPackets();
				});
			}

			for (auto& [id, plyr] : Players::GetPlayers())
			{
				if (!plyr.IsValid())
					continue;

				if (ImGui::Selectable(plyr.GetName(), plyr == Voice::GetSpoofingPlayer()))
				{
					Voice::SetSpoofingPlayer(plyr);
					FiberPool::Push([] {
						ResendVoiceInfoPackets();
					});
				}

				if (plyr == Voice::GetSpoofingPlayer())
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndCombo();
		}
	}

	std::shared_ptr<Category> BuildVoiceMenu()
	{
		auto voice = std::make_shared<Category>("Voice");
		voice->AddItem(std::make_shared<BoolCommandItem>("hearall"_J));
		voice->AddItem(std::make_shared<ConditionalItem>("hearall"_J, std::make_shared<BoolCommandItem>("forcesendvc"_J)));
		voice->AddItem(std::make_shared<BoolCommandItem>("hidevcsender"_J));
		voice->AddItem(std::make_shared<ImGuiItem>(&ShowVoiceSpoofingMenu));
		voice->AddItem(std::make_shared<BoolCommandItem>("voicechatoverride"_J));
		voice->AddItem(std::make_shared<ImGuiItem>(&ShowVoiceFileSelectionMenu));

		return std::move(voice);
	}
}