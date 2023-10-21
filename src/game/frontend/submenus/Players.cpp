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
	void drawPlayerList(bool external, float offset = 15.0f)
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

			auto playersListGroup = std::make_shared<Group>("Players");

			playersListGroup->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(false);
			}));

			auto playerOptionsGroup = std::make_shared<Group>("Info");

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
			}));

			column->AddColumnOffset(1, 160);
			column->AddItem(playersListGroup);
			column->AddNextColumn();
			column->AddItem(playerOptionsGroup);

			main->AddItem(column);
			AddCategory(std::move(main));
		}

		{
			auto helpful = std::make_shared<Category>("Helpful");

			helpful->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(popPlayerList);
			}));

			helpful->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
			}));

			AddCategory(std::move(helpful));
		}

		{
			auto trolling = std::make_shared<Category>("Trolling");

			trolling->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(popPlayerList);
			}));

			trolling->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
			}));

			trolling->AddItem(std::make_shared<ImGuiItem>([] {
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


			AddCategory(std::move(trolling));
		}

		{
			auto toxic = std::make_shared<Category>("Toxic");

			toxic->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(true);
			}));

			toxic->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
			}));

			AddCategory(std::move(toxic));
		}

		{
			auto kick = std::make_shared<Category>("Kick"); // would we ever find one?

			kick->AddItem(std::make_shared<ImGuiItem>([] {
				drawPlayerList(true);
			}));

			kick->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
			}));

			AddCategory(std::move(kick));
		}
	}
}