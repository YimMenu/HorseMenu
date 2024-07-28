#include "Network.hpp"

#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/PlayerDatabase.hpp"
#include "game/backend/FiberPool.hpp"
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

#include <map>
#include <network/rlGamerHandle.hpp>
#include <ranges>
#include <string>
#include "Network.hpp"


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
		auto session          = std::make_shared<Category>("Session");
		auto spoofing         = std::make_shared<Category>("Spoofing");
		auto database         = std::make_shared<Category>("Player Database");
		auto sessionSwitcherGroup = std::make_shared<Group>("Session Switcher");
		auto teleportGroup  = std::make_shared<Group>("Teleport");
		auto toxicGroup = std::make_shared<Group>("Toxic");
		auto miscGroup = std::make_shared<Group>("Misc");
		auto nameChangerGroup = std::make_shared<Group>("Name Changer");
		auto blipSpoofingGroup = std::make_shared<Group>("Blip Spoofing");
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
		miscGroup->AddItem(std::make_shared<BoolCommandItem>("blockalltelemetry"_J));

		session->AddItem(sessionSwitcherGroup);
		session->AddItem(teleportGroup);
		session->AddItem(toxicGroup);
		session->AddItem(miscGroup);

		spoofing->AddItem(std::make_shared<BoolCommandItem>("hidegod"_J));
		spoofing->AddItem(std::make_shared<BoolCommandItem>("voicechatoverride"_J));
		database->AddItem(std::make_shared<ImGuiItem>([] {
			ImGui::SetNextItemWidth(300.f);
			ImGui::PushID(3);
			ImGui::InputText("Player Name", search, sizeof(search));
			ImGui::PopID();

			if (ImGui::BeginListBox("###players", {180, static_cast<float>(Pointers.ScreenResY - 400 - 38 * 4)}))
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
				if (ImGui::BeginChild("###selected_player", {500, static_cast<float>(Pointers.ScreenResY - 388 - 38 * 4)}, false, ImGuiWindowFlags_NoBackground))
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

					if (ImGui::Button("Join Player"))
					{
						FiberPool::Push([] {
							using gp = void*(*)();
							using join = void(*)(void*, rage::rlGamerHandle*, int);

							gp g = (gp)((__int64)GetModuleHandleA(0) + 0x22b9800);
							join j = (join)((__int64)GetModuleHandleA(0) + 0x22d7080);

							rage::rlGamerHandle hnd(current_player->rid);

							j(g(), &hnd, 512);
						});
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
		static std::string name_input_buf, color_spoof_buf = "";
		nameChangerGroup->AddItem(std::make_shared<ImGuiItem>([=] {
			static std::map<std::string, std::string> color_translations = {{"~e~", "Red"}, {"~f~", "Off White"}, {"~p~", "White"}, {"~o~", "Yellow"}, {"~q~", "Pure White"}, {"~d~", "Orange"}, {"~m~", "Light Grey"}, {"~t~", "Grey"}, {"~v~", "Black"}, {"~pa~", "Blue"}, {"~t1~", "Purple"}, {"~t2~", "Orange"}, {"~t3~", "Teal"}, {"~t4~", "Light Yellow"}, {"~t5~", "Pink"}, {"~t6~", "Green"}, {"~t7~", "Dark Blue"}, {"", "None"}};


			InputTextWithHint("New Name", "Enter New Name", &name_input_buf).Draw();

			if (ImGui::BeginCombo("Color Selection", color_translations[color_spoof_buf].c_str()))
			{
				for (auto& [code, translation] : color_translations)
				{
					if (ImGui::Selectable(translation.c_str(), code == color_spoof_buf))
					{
						color_spoof_buf = code;
					}
				}
				ImGui::EndCombo();
			}

			if (ImGui::Button("Set Spoofed Name"))
			{
				std::string concat_name        = std::string(color_spoof_buf) + name_input_buf;
				g_SpoofingStorage.spoofed_name = concat_name;
			}
			if (ImGui::IsItemHovered())
			{
				ImGui::SetTooltip("This will take affect once a new player joins the session. This effect does not appear locally.");
			}
		}));
		blipSpoofingGroup->AddItem(std::make_shared<BoolCommandItem>("spoofprimaryicon"_J));
		blipSpoofingGroup->AddItem(std::make_shared<ConditionalItem>("spoofprimaryicon"_J, std::make_shared<ListCommandItem>("primaryicon"_J, "Icon##primary")));
		blipSpoofingGroup->AddItem(std::make_shared<BoolCommandItem>("spoofsecondaryicon"_J));
		blipSpoofingGroup->AddItem(std::make_shared<ConditionalItem>("spoofsecondaryicon"_J, std::make_shared<ListCommandItem>("secondaryicon"_J, "Icon##secondary"))); 

		auto discriminatorGroup = std::make_shared<Group>("", 1);
		sessionSpoofingGroup->AddItem(std::make_shared<BoolCommandItem>("spoofdiscriminator"_J));
		discriminatorGroup->AddItem(std::make_shared<IntCommandItem>("discriminator"_J));
		discriminatorGroup->AddItem(std::make_shared<CommandItem>("copydiscriminator"_J, "Copy Current"));
		sessionSpoofingGroup->AddItem(std::make_shared<ConditionalItem>("spoofdiscriminator"_J, std::move(discriminatorGroup)));

		spoofing->AddItem(nameChangerGroup);
		spoofing->AddItem(blipSpoofingGroup);
		spoofing->AddItem(sessionSpoofingGroup);
		AddCategory(std::move(session));
		AddCategory(std::move(spoofing));
		AddCategory(std::move(database));
	}
}
