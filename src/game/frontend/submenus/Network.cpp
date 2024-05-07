#include "Network.hpp"

#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "core/frontend/Notifications.hpp"
#include "core/player_database/PlayerDatabase.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/pointers/Pointers.hpp"

#include <ranges>


namespace YimMenu::Submenus
{
	void draw_player_db_entry(std::shared_ptr<persistent_player> player, const std::string& lower_search)
	{
		std::string name = player->name;
		std::transform(name.begin(), name.end(), name.begin(), ::tolower);

		if (lower_search.empty() || name.find(lower_search) != std::string::npos)
		{
			ImGui::PushID(player->rid);

			float circle_size = 7.5f;
			auto cursor_pos   = ImGui::GetCursorScreenPos();

			//render status circle
			//ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(cursor_pos.x + 4.f + circle_size, cursor_pos.y + 4.f + circle_size), circle_size, ImColor(get_player_color(*player)));

			//we need some padding
			ImVec2 cursor = ImGui::GetCursorPos();
			ImGui::SetCursorPos(ImVec2(cursor.x + 25.f, cursor.y));

			if (ImGui::Selectable(player->name.c_str(), player == g_PlayerDatabase.GetSelected()))
			{
				g_PlayerDatabase.SetSelected(player);
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
			static char search[64];
			ImGui::InputText("##search", search, sizeof(search));

			if (ImGui::BeginListBox("###players"))
			{
				auto players = g_PlayerDatabase.GetAllPlayers();
				if (players.size() > 0)
				{
					std::string lower_search = search;
					std::transform(lower_search.begin(), lower_search.end(), lower_search.begin(), tolower);

					for (auto& player : players | std::ranges::views::values)
						draw_player_db_entry(player, lower_search);
				}
				else
				{
					ImGui::Text("No Stored Players");
				}

				ImGui::EndListBox();
			}

			if (auto selected = g_PlayerDatabase.GetSelected())
			{
				static char name_buf[32];
				ImGui::SameLine();
				if (ImGui::InputText("Name", name_buf, sizeof(name_buf)))
				{
					selected->name = std::string(name_buf);
				}
				ImGui::InputScalar("RID", ImGuiDataType_S64, &selected->rid);
				ImGui::Checkbox("Is Modder", &selected->is_modder);
				ImGui::Checkbox("Is Admin", &selected->is_admin);
				ImGui::Checkbox("Block Join", &selected->block_join);

				if (!selected->infractions.empty())
				{
					for (auto& infraction : selected->infractions)
					{
						//ImGui::BulletText(selected->GetInfractionDescription(infraction));
					}
				}
			}
		}));
		AddCategory(std::move(session));
		AddCategory(std::move(spoofing));
		AddCategory(std::move(database));
	}
}