#include "Menu.hpp"

#include "core/memory/ModuleMgr.hpp"
#include "game/pointers/Pointers.hpp"
#include "util/Joaat.hpp"
#include "game/rdr/natives.hpp"

namespace YimMenu
{
	void Menu::Main()
	{
		if (!GUI::IsOpen())
			return;

		if (ImGui::Begin("Test"))
		{
			if (ImGui::Button("Suicide"))
			{
				auto player_ped = PLAYER::PLAYER_PED_ID();

				LOG(INFO) << player_ped;

				ENTITY::SET_ENTITY_HEALTH(player_ped, 0, 0);
			}

			if (ImGui::Button("Get Coords"))
			{
				auto coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false, false);

				LOG(INFO) << coords.x << "x\t" << coords.y << "y\t" << coords.z << "z";
			}

			if (ImGui::Button("Unload"))
				g_Running = false;
		}
		ImGui::End();
	}
}