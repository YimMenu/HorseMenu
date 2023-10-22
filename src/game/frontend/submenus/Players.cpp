#include "Players.hpp"

#include "core/commands/Commands.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/Natives.hpp"
#include "util/teleport.hpp"

namespace YimMenu::Submenus
{
	bool popPlayerList = true; //TODO make optional
	void drawPlayerList(bool external, float offset = 25.0f)
	{
		struct ComparePlayerNames
		{
			bool operator()(YimMenu::Player a, YimMenu::Player b) const
			{
				std::string nameA = a.GetName();
				std::string nameB = b.GetName();
				return nameA < nameB;
			}
		};

		std::map<uint8_t, Player, ComparePlayerNames> sortedPlayers(YimMenu::Players::GetPlayers().begin(),
		    YimMenu::Players::GetPlayers().end());

		if (external)
		{
			ImGui::SetNextWindowPos(
			    ImVec2(ImGui::GetWindowPos().x + ImGui::GetWindowSize().x + offset, ImGui::GetWindowPos().y));
			ImGui::SetNextWindowSize(ImVec2(150, ImGui::GetWindowSize().y));
			ImGui::Begin("Player List", nullptr, ImGuiWindowFlags_NoDecoration);

			ImGui::Checkbox("Spectate", &YimMenu::g_Spectating);
			for (auto& [id, player] : sortedPlayers)
			{
				if (ImGui::Selectable(player.GetName(), (YimMenu::Players::GetSelected() == player)))
				{
					YimMenu::Players::SetSelected(id);
				}
			}
			ImGui::End();
		}
		else
		{
			for (auto& [id, player] : sortedPlayers)
			{
				if (ImGui::Selectable(player.GetName(), (YimMenu::Players::GetSelected() == player)))
				{
					YimMenu::Players::SetSelected(id);
				}
			}
		}
	}

	Players::Players() :
	    Submenu::Submenu("Players")
	{
		{
			auto main   = std::make_shared<Category>("Main");
			auto column = std::make_shared<Column>(2);

			auto playerOptionsGroup = std::make_shared<Group>("Info", ImVec2(0, 250));

			main->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(true);
			}));

			playerOptionsGroup->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
				ImGui::Separator();

				ImGui::Checkbox("Spectate", &YimMenu::g_Spectating);
				//Button Widget crashes the game, idk why. Changed to regular for now.
				if(ImGui::Button("Teleport To"))
				{
					FiberPool::Push([]{
						auto playerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(YimMenu::Players::GetSelected().GetId()), true, true);
						if(Teleport::TeleportEntity(Self::PlayerPed, playerCoords))
							g_Spectating = false;
						
					});
				}
				if (ImGui::Button("Teleport Behind"))
				{
					FiberPool::Push([] {
						auto playerCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(
						    PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(YimMenu::Players::GetSelected().GetId()),
						    0,
						    -10,
						    0);
						if (Teleport::TeleportEntity(Self::PlayerPed, playerCoords))
							g_Spectating = false;
					});
				}
			}));

			column->AddColumnOffset(1, 160);
			column->AddItem(playerOptionsGroup);
			main->AddItem(column);
			AddCategory(std::move(main));
		}

		{
			auto helpful = std::make_shared<Category>("Helpful");

			helpful->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(popPlayerList);
			}));

			AddCategory(std::move(helpful));
		}

		{
			auto toxic     = std::make_shared<Category>("Toxic");
			auto columns   = std::make_shared<Column>(2);
			auto miscGroup = std::make_shared<Group>("Misc", ImVec2(0, 250));

			toxic->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(popPlayerList);
			}));

			miscGroup->AddItem(std::make_shared<ImGuiItem>([] {
				if (ImGui::Button("Explode"))
				{
					FiberPool::Push([] {
						auto playerCoords = ENTITY::GET_ENTITY_COORDS(
						    PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(YimMenu::Players::GetSelected().GetId()),
						    true,
						    true);

						FIRE::ADD_EXPLOSION(playerCoords.x, playerCoords.y, playerCoords.z, 22, 1.0f, true, false, 1.0f);
					});
				};
			}));

			columns->AddColumnOffset(1, 160);
			columns->AddItem(miscGroup);
			toxic->AddItem(columns);

			AddCategory(std::move(toxic));
		}
	}
}