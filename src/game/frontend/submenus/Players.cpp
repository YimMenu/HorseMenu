#include "Players.hpp"

#include "core/commands/Commands.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/Players.hpp"
#include "game/commands/PlayerCommand.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/Natives.hpp"
#include "util/spectate.hpp"

namespace YimMenu::Submenus
{
	Players::Players() :
	    Submenu::Submenu("Players")
	{
		{
			auto main   = std::make_shared<Category>("Main");
			auto column = std::make_shared<Column>(2);

			auto playersListGroup = std::make_shared<Group>("Players");

			playersListGroup->AddItem(std::make_shared<ImGuiItem>([] {
				for (auto& [name, player] : YimMenu::Players::GetPlayers())
				{
					if (ImGui::Selectable(name.c_str(), (YimMenu::Players::GetSelected() == player)))
					{
						YimMenu::Players::SetSelected(player);

						if(YimMenu::g_Spectating)
							YimMenu::SpectatePlayer(player);
					}
				}
			}));

			auto playerOptionsGroup = std::make_shared<Group>("Info");

			playerOptionsGroup->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
				ImGui::Separator();

				if(ImGui::Checkbox("Spectate", &YimMenu::g_Spectating))
				{
					YimMenu::SpectatePlayer(YimMenu::Players::GetSelected());
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
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
			}));

			AddCategory(std::move(helpful));
		}

		{
			auto trolling = std::make_shared<Category>("Trolling");

			trolling->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
			}));

			trolling->AddItem(std::make_shared<ImGuiItem>([] {
				if (ImGui::Button("Explode"))
				{
					FiberPool::Push([] {
						auto playerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(YimMenu::Players::GetSelected().GetId()), true, true);


						FIRE::ADD_EXPLOSION(playerCoords.x, playerCoords.y, playerCoords.z, 22, 1.0f, true, false, 1.0f);
					});
				};
			}));


			AddCategory(std::move(trolling));
		}

		{
			auto toxic = std::make_shared<Category>("Toxic");

			toxic->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
			}));

			AddCategory(std::move(toxic));
		}

		{
			auto kick = std::make_shared<Category>("Kick"); // would we ever find one?

			kick->AddItem(std::make_shared<ImGuiItem>([] {
				ImGui::Text(YimMenu::Players::GetSelected().GetName());
			}));

			AddCategory(std::move(kick));
		}
	}
}