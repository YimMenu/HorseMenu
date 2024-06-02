#include "Network.hpp"

#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/player_database/PlayerDatabase.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"
// remove scriptmgr include after testing
#include "game/backend/ScriptMgr.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/pointers/Pointers.hpp"

#include <ranges>


namespace YimMenu::Submenus
{
	std::shared_ptr<persistent_player> current_player;
	static char search[64];
	static char name_buf[32];
	static char new_player_name_buf[32];
	static uint64_t new_player_rid;

	void draw_player_db_entry(std::shared_ptr<persistent_player> player, const std::string& lower_search)
	{
		std::string name = player->name;
		std::transform(name.begin(), name.end(), name.begin(), ::tolower);

		if (lower_search.empty() || name.find(lower_search) != std::string::npos)
		{
			ImGui::PushID(player->rid);

			//float circle_size = 7.5f;
			//auto cursor_pos   = ImGui::GetCursorScreenPos();

			//render status circle
			//ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(cursor_pos.x + 4.f + circle_size, cursor_pos.y + 4.f + circle_size), circle_size, ImColor(get_player_color(*player)));

			//we need some padding
			//ImVec2 cursor = ImGui::GetCursorPos();
			//ImGui::SetCursorPos(ImVec2(cursor.x + 25.f, cursor.y));

			if (ImGui::Selectable(player->name.c_str(), player == g_PlayerDatabase->GetSelected()))
			{
				g_PlayerDatabase->SetSelected(player);
				current_player = player;
				strncpy(name_buf, current_player->name.data(), sizeof(name_buf));
			}

			ImGui::PopID();
		}
	}

	Network::Network() :
	    Submenu::Submenu("Network")
	{
		auto session  = std::make_shared<Category>("Session");
		auto spoofing = std::make_shared<Category>("Spoofing");
		auto database = std::make_shared<Category>("Player Database");
		session->AddItem(std::make_shared<CommandItem>("explodeall"_J));
		session->AddItem(std::make_shared<CommandItem>("maxhonorall"_J));
		session->AddItem(std::make_shared<CommandItem>("minhonorall"_J));
		session->AddItem(std::make_shared<BoolCommandItem>("blockalltelemetry"_J));
		session->AddItem(std::make_shared<BoolCommandItem>("locklobby"_J));
		// remove code below before PR
		session->AddItem(std::make_shared<ImGuiItem>([] {
			if (ImGui::Button("Get Host"))
				FiberPool::Push([] {
					for (auto& player : YimMenu::Players::GetPlayers())
					{
						if (player.second.IsHost())
						{
							Notifications::Show("Host", player.second.GetName());
							break;
						}
					}
				});
		}));
		spoofing->AddItem(std::make_shared<BoolCommandItem>("hidegod"_J));
		spoofing->AddItem(std::make_shared<BoolCommandItem>("voicechatoverride"_J));
		spoofing->AddItem(std::make_shared<BoolCommandItem>("spoofmodel"_J));
		database->AddItem(std::make_shared<ImGuiItem>([] {
			static bool show_new_player = true;
			ImGui::SetNextItemWidth(300.f);
			ImGui::InputText("Player Name", search, sizeof(search));


			if (ImGui::BeginListBox("###players", {180, static_cast<float>(Pointers.ScreenResY - 400 - 38 * 4)}))
			{
				auto& item_arr = g_PlayerDatabase->GetAllPlayers();

				std::string lower_search = search;
				std::transform(lower_search.begin(), lower_search.end(), lower_search.begin(), ::tolower);

				for (auto& player : item_arr)
				{
					draw_player_db_entry(player.second, lower_search);
				}

				ImGui::EndListBox();
			}
			if (auto selected = g_PlayerDatabase->GetSelected())
			{
				show_new_player = false;
				ImGui::SameLine();
				if (ImGui::BeginChild("###selected_player", {500, static_cast<float>(Pointers.ScreenResY - 388 - 38 * 4)}, false, ImGuiWindowFlags_NoBackground))
				{
					if (ImGui::InputText("Name", name_buf, sizeof(name_buf)))
					{
						current_player->name = name_buf;
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
							ImGui::BulletText(std::string(g_PlayerDatabase->ConvertInfractionToDescription(pair.first))
							                      .append(" - ")
							                      .append("x")
							                      .append(std::to_string(pair.second))
							                      .c_str());
						}
					}
				}
			}
			if (show_new_player)
			{
				ImGui::NewLine();
				ImGui::InputText("Player Name", new_player_name_buf, sizeof(new_player_name_buf));
				ImGui::InputScalar("RID", ImGuiDataType_U64, &new_player_rid);
				if (ImGui::Button("Add"))
				{
					current_player       = g_PlayerDatabase->GetOrCreatePlayer(new_player_rid);
					current_player->name = new_player_name_buf;
				}
			}
		}));
		AddCategory(std::move(session));
		AddCategory(std::move(spoofing));
		AddCategory(std::move(database));
	}
}