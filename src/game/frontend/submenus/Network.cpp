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
		spoofing->AddItem(std::make_shared<BoolCommandItem>("hidegod"_J));
		spoofing->AddItem(std::make_shared<BoolCommandItem>("voicechatoverride"_J));
		database->AddItem(std::make_shared<ImGuiItem>([] {
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

						for (auto& infraction : current_player->infractions)
						{
							ImGui::BulletText(g_PlayerDatabase->ConvertInfractionToDescription(infraction).c_str());
						}
					}
				}
			}
		}));
		AddCategory(std::move(session));
		AddCategory(std::move(spoofing));
		AddCategory(std::move(database));
	}
}