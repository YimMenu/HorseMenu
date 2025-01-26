#include "Network.hpp"

#include "Network/Voice.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/PlayerDatabase.hpp"
#include "game/backend/Players.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/rdr/Enums.hpp"
#include "game/rdr/Natives.hpp"
#include "util/Chat.hpp"
#include "util/Storage/Spoofing.hpp"
#include "util/teleport.hpp"
#include "Self.hpp"
#include "game/rdr/Packet.hpp"

#include <map>
#include <network/rlGamerHandle.hpp>
#include <network/CNetworkScSession.hpp>
#include <network/snConnectToPeerTask.hpp>
#include <rage/rlTaskStatus.hpp>
#include <network/CNetworkPlayerMgr.hpp>
#include <network/netEncryption.hpp>
#include <ranges>
#include <string>

namespace rage
{
	class rlQueryPresenceAttributesContext
	{
	public:
		char m_presence_attribute_key[64]; //0x0000
		union {
			char m_presence_attribute_string_value[256]; //0x0040
			uint64_t m_presence_attribute_int_value;
		};
		uint32_t m_presence_attibute_type; //0x0140
		char pad_0144[4];                  //0x0144
	};                                     //Size: 0x0148
	static_assert(sizeof(rlQueryPresenceAttributesContext) == 0x148);

	struct rlScTaskStatus
	{
		void* pad  = 0;
		int status = 0;
		int unk    = 0;
	};
}

namespace YimMenu::Submenus
{
	std::shared_ptr<persistent_player> current_player;
	static char search[64];
	static char name_buf[32];
	static char new_player_name_buf[32];
	static uint64_t new_player_rid;
	static bool show_player_editor = false;
	static bool show_new_player    = true;

	void draw_player_db_entry(std::shared_ptr<persistent_player> player, const std::string& lower_search)
	{
		std::string name = player->name;
		std::transform(name.begin(), name.end(), name.begin(), ::tolower);

		if (lower_search.empty() || name.find(lower_search) != std::string::npos)
		{
			ImGui::PushID(player->rid);

			if (ImGui::Selectable(player->name.c_str(), player == g_PlayerDatabase->GetSelected()))
			{
				g_PlayerDatabase->SetSelected(player);
				current_player = player;
				strncpy(name_buf, current_player->name.data(), sizeof(name_buf));
				show_new_player    = false;
				show_player_editor = true;
			}

			ImGui::PopID();
		}
	}

	Network::Network() :
	    Submenu::Submenu("Network")
	{
		// TODO: this needs a rework
		auto session              = std::make_shared<Category>("Session");
		auto spoofing             = std::make_shared<Category>("Spoofing");
		auto database             = std::make_shared<Category>("Player Database");
		auto sessionSwitcherGroup = std::make_shared<Group>("Session Switcher");
		auto teleportGroup        = std::make_shared<Group>("Teleport");
		auto toxicGroup           = std::make_shared<Group>("Toxic");
		auto miscGroup            = std::make_shared<Group>("Misc");
		auto infoSpoofingGroup    = std::make_shared<Group>("Info Spoofing");
		auto blipSpoofingGroup    = std::make_shared<Group>("Blip Spoofing");
		auto sessionSpoofingGroup = std::make_shared<Group>("Session Spoofing");

		sessionSwitcherGroup->AddItem(std::make_shared<Vector3CommandItem>("newsessionpos"_J));
		sessionSwitcherGroup->AddItem(std::make_shared<BoolCommandItem>("newsessionposse"_J));
		sessionSwitcherGroup->AddItem(std::make_shared<CommandItem>("newsession"_J));

		teleportGroup->AddItem(std::make_shared<CommandItem>("bringall"_J, "Bring All"));
		teleportGroup->AddItem(std::make_shared<CommandItem>("tpalltowaypoint"_J));
		teleportGroup->AddItem(std::make_shared<CommandItem>("tpalltojail"_J));

		toxicGroup->AddItem(std::make_shared<CommandItem>("explodeall"_J));
		toxicGroup->AddItem(std::make_shared<CommandItem>("maxhonorall"_J));
		toxicGroup->AddItem(std::make_shared<CommandItem>("minhonorall"_J));

		miscGroup->AddItem(std::make_shared<BoolCommandItem>("revealall"_J));
		miscGroup->AddItem(std::make_shared<BoolCommandItem>("disableshopunavailable"_J)); // finish this
		miscGroup->AddItem(std::make_shared<BoolCommandItem>("disablecampshopunavailable"_J));
		miscGroup->AddItem(std::make_shared<BoolCommandItem>("disablecampraids"_J));

		miscGroup->AddItem(std::make_shared<BoolCommandItem>("blockalltelemetry"_J)); // move this to protections->misc
		miscGroup->AddItem(std::make_shared<BoolCommandItem>("locklobby"_J));

		session->AddItem(sessionSwitcherGroup);
		session->AddItem(teleportGroup);
		session->AddItem(toxicGroup);
		session->AddItem(miscGroup);

		spoofing->AddItem(std::make_shared<BoolCommandItem>("hidegod"_J));
		spoofing->AddItem(std::make_shared<BoolCommandItem>("hidespectate"_J));

		database->AddItem(std::make_shared<ImGuiItem>([] {
			ImGui::SetNextItemWidth(300.f);
			ImGui::PushID(3);
			ImGui::InputText("Player Name", search, sizeof(search));
			ImGui::PopID();

			if (ImGui::BeginListBox("###players", {180, static_cast<float>(*Pointers.ScreenResY - 400 - 38 * 4)}))
			{
				auto& item_arr = g_PlayerDatabase->GetAllPlayers();
				if (item_arr.size() > 0)
				{
					std::string lower_search = search;
					std::transform(lower_search.begin(), lower_search.end(), lower_search.begin(), ::tolower);

					for (auto& player : item_arr)
					{
						draw_player_db_entry(player.second, lower_search);
					}
				}
				else
				{
					ImGui::Text("No Players Found!");
				}

				ImGui::EndListBox();
			}
			if (auto selected = g_PlayerDatabase->GetSelected() && show_player_editor)
			{
				ImGui::PushID(1);
				ImGui::SameLine();
				if (ImGui::BeginChild("###selected_player", {500, static_cast<float>(*Pointers.ScreenResY - 388 - 38 * 4)}, false, ImGuiWindowFlags_NoBackground))
				{
					if (ImGui::InputText("Name", name_buf, sizeof(name_buf)))
					{
						current_player->name = name_buf;
						g_PlayerDatabase->Save();
					}

					if (ImGui::InputScalar("RID", ImGuiDataType_S64, &current_player->rid)
					    || ImGui::Checkbox("Is Modder", &current_player->is_modder)
					    || ImGui::Checkbox("Trust", &current_player->trust)
					    || ImGui::Checkbox("Block Join", &current_player->block_join))
					{
						g_PlayerDatabase->Save();
					}

					if (!current_player->infractions.empty())
					{
						ImGui::Text("Infractions");

						std::unordered_map<int, int /*count*/> count_map;

						for (const auto& item : current_player->infractions)
						{
							count_map[item]++;
						}

						for (const auto& pair : count_map)
						{
							// TODO: find a better way to do this
							ImGui::BulletText(std::string(g_PlayerDatabase->ConvertDetectionToDescription(Detection(pair.first)))
							                      .append(" - ")
							                      .append("x")
							                      .append(std::to_string(pair.second))
							                      .c_str());
						}
					}

					if (ImGui::Button("Delete Player"))
					{
						g_PlayerDatabase->RemoveRID(current_player->rid);
					}

					if (ImGui::Button("Hide Editor"))
					{
						show_player_editor = false;
						show_new_player    = true;
					}
					ImGui::PopID();
				}
			}
			if (show_new_player)
			{
				ImGui::PushID(2);
				ImGui::NewLine();
				ImGui::InputText("Player Name", new_player_name_buf, sizeof(new_player_name_buf));
				ImGui::InputScalar("RID", ImGuiDataType_U64, &new_player_rid);
				if (ImGui::Button("Add"))
				{
					current_player = g_PlayerDatabase->GetOrCreatePlayer(new_player_rid, new_player_name_buf);
					memset(new_player_name_buf, 0, sizeof(new_player_name_buf));
				}
				ImGui::PopID();
			}
		}));
		static std::string nameBuf, colorBuf = "";
		static const char* iconBuf = "";
		infoSpoofingGroup->AddItem(std::make_shared<ImGuiItem>([=] {
			static std::map<std::string, std::string> colors = {{"", "None"}, {"~e~", "Red"}, {"~f~", "Off White"}, {"~p~", "White"}, {"~o~", "Yellow"}, {"~q~", "Pure White"}, {"~d~", "Orange"}, {"~m~", "Light Grey"}, {"~t~", "Grey"}, {"~v~", "Black"}, {"~pa~", "Blue"}, {"~t1~", "Purple"}, {"~t2~", "Orange"}, {"~t3~", "Teal"}, {"~t4~", "Light Yellow"}, {"~t5~", "Pink"}, {"~t6~", "Green"}, {"~t7~", "Dark Blue"}};
			static std::map<const char*, std::string> icons = {{"", "None"}, {(const char*)u8"\u2211", "Rockstar Icon"}};
			ImGui::Text("Spoofed data will not appear locally, and will only be visible when joining a new session,\n or when a player joins you");

			ImGui::Text("Name");
			ImGui::Checkbox("Spoof Name", &g_SpoofingStorage.spoofName);
			if (ImGui::IsItemHovered())
				ImGui::SetTooltip("Spoof your name");

			if (ImGui::BeginCombo("Color Prefix", colors[colorBuf].c_str()))
			{
				for (auto& [code, translation] : colors)
				{
					if (ImGui::Selectable(translation.c_str(), code == colorBuf))
					{
						colorBuf = code;
					}
				}
				ImGui::EndCombo();
			}

			if (ImGui::BeginCombo("Icon Prefix", icons[iconBuf].c_str()))
			{
				for (auto& [icon, translation] : icons)
				{
					if (ImGui::Selectable(translation.c_str(), icon == iconBuf))
					{
						iconBuf = icon;
					}
				}
				ImGui::EndCombo();
			}

			InputTextWithHint("Spoofed Name", "Enter spoofed name", &nameBuf).Draw();
			if (ImGui::Button("Set Spoofed Name"))
			{
				std::string concatName        = std::string(colorBuf) + std::string(iconBuf) + nameBuf;
				g_SpoofingStorage.spoofedName = concatName;
			}
			if (ImGui::IsItemHovered())
				ImGui::SetTooltip("Update your spoofed name");

			ImGui::Text("IP Address");
			ImGui::Checkbox("Spoof IP", &g_SpoofingStorage.spoofIP);
			if (ImGui::IsItemHovered())
				ImGui::SetTooltip("Spoof your IP");

			ImGui::DragInt4("##ip_fields", g_SpoofingStorage.spoofedIP.data(), 0, 255);

			ImGui::Text("Rockstar ID");
			ImGui::Checkbox("Spoof RID", &g_SpoofingStorage.spoofRID);
			if (ImGui::IsItemHovered())
				ImGui::SetTooltip("Spoof your Rockstar ID");

			ImGui::InputScalar("##rockstar_id_input", ImGuiDataType_U64, &g_SpoofingStorage.spoofedRID);
		}));

		blipSpoofingGroup->AddItem(std::make_shared<BoolCommandItem>("spoofblip"_J));
		blipSpoofingGroup->AddItem(std::make_shared<ConditionalItem>("spoofblip"_J, std::make_shared<ListCommandItem>("blipsprite"_J, "Blip")));
		blipSpoofingGroup->AddItem(std::make_shared<BoolCommandItem>("spoofprimaryicon"_J));
		blipSpoofingGroup->AddItem(std::make_shared<ConditionalItem>("spoofprimaryicon"_J, std::make_shared<ListCommandItem>("primaryicon"_J, "Icon##primary")));
		blipSpoofingGroup->AddItem(std::make_shared<BoolCommandItem>("spoofsecondaryicon"_J));
		blipSpoofingGroup->AddItem(std::make_shared<ConditionalItem>("spoofsecondaryicon"_J, std::make_shared<ListCommandItem>("secondaryicon"_J, "Icon##secondary")));

		auto discriminatorGroup = std::make_shared<Group>("", 1);
		sessionSpoofingGroup->AddItem(std::make_shared<BoolCommandItem>("spoofdiscriminator"_J));
		discriminatorGroup->AddItem(std::make_shared<IntCommandItem>("discriminator"_J));
		discriminatorGroup->AddItem(std::make_shared<CommandItem>("copydiscriminator"_J, "Copy Current"));
		sessionSpoofingGroup->AddItem(std::make_shared<ConditionalItem>("spoofdiscriminator"_J, std::move(discriminatorGroup)));

		spoofing->AddItem(infoSpoofingGroup);
		spoofing->AddItem(blipSpoofingGroup);
		spoofing->AddItem(sessionSpoofingGroup);

		auto voice = BuildVoiceMenu();

		AddCategory(std::move(session));
		AddCategory(std::move(spoofing));
		AddCategory(std::move(voice));
		AddCategory(std::move(database));
	}
}
