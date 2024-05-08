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
		if (player && player->name.find(lower_search) != std::string::npos)
		{
			if (ImGui::Selectable(player->name.c_str()))
			{
				g_PlayerDatabase.SetSelected(player);
			}

			if (auto selected = g_PlayerDatabase.GetSelected())
			{
				if (selected->rid == player->rid)
				{
					ImGui::InputScalar("RID", ImGuiDataType_U64, &player->rid);
					ImGui::Checkbox("Is Modder", &player->is_modder);
					ImGui::Checkbox("Is Admin", &player->is_admin);
					ImGui::Checkbox("Block Join", &player->block_join);
					ImGui::Checkbox("Trust", &player->trust);

					if (!player->infractions.empty())
					{
						ImGui::Text("Infractions:");
						for (const auto& infraction : player->infractions)
						{
							ImGui::BulletText(g_PlayerDatabase.ConvertInfractionToDescription(infraction).c_str());
						}
					}
				}
			}
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
					{
						std::string player_name_lower = player->name;
						std::transform(player_name_lower.begin(), player_name_lower.end(), player_name_lower.begin(), tolower);
						if (player_name_lower.find(lower_search) != std::string::npos)
						{
							draw_player_db_entry(player, lower_search);
						}
					}
				}
				else
				{
					ImGui::Text("No Stored Players");
				}

				ImGui::EndListBox();
			}
		}));
		AddCategory(std::move(session));
		AddCategory(std::move(spoofing));
		AddCategory(std::move(database));
	}
}