#include "World.hpp"

#include "game/backend/FiberPool.hpp"
#include "World/Weather.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/frontend/items/Items.hpp"
#include "util/libraries/PedModels.hpp"
#include "game/rdr/Ped.hpp"
#include "game/backend/Self.hpp"
#include "World/PedSpawner.hpp"
#include "World/Shows.hpp"

#include <game/rdr/Natives.hpp>

namespace YimMenu::Submenus
{
	World::World() :
	    Submenu::Submenu("World")
	{
		auto main    = std::make_shared<Category>("Main");
		auto weather = std::make_shared<Category>("Weather");
		auto shows = std::make_shared<Category>("Shows");


		main->AddItem(std::make_shared<ImGuiItem>([] {
			static std::string hour, minute, second;
			InputTextWithHint("Hour", "Enter Hour", &hour).Draw();
			InputTextWithHint("Minute", "Enter Minute", &minute).Draw();
			InputTextWithHint("Second", "Enter Second", &second).Draw();
			if (ImGui::Button("Change Time"))
			{
				int h = std::stoi(hour);
				int m = std::stoi(minute);
				int s = std::stoi(second);
				FiberPool::Push([=] {
					ChangeTime(h, m, s);
				});
			}
		}));


		weather->AddItem(std::make_shared<ImGuiItem>([] {
			static const char* current_weather = WeatherTypes[0]; // Default weather
			if (ImGui::BeginCombo("Weather Types", current_weather))
			{
				for (auto& weather_type : WeatherTypes)
				{
					bool is_selected = (current_weather == weather_type);
					if (ImGui::Selectable(weather_type, is_selected))
					{
						current_weather = weather_type;
						FiberPool::Push([=] {
							ChangeWeather(weather_type);
						});
					}
					if (is_selected)
						ImGui::SetItemDefaultFocus();
				}
				ImGui::EndCombo();
			}
		}));


		auto spawners        = std::make_shared<Category>("Spawners");
		auto pedSpawnerGroup = std::make_shared<Group>("Ped Spawner");

		pedSpawnerGroup->AddItem(std::make_shared<ImGuiItem>([] {
			RenderPedSpawnerMenu();
		}));

		spawners->AddItem(pedSpawnerGroup);

		auto killPeds = std::make_shared<Group>("", 1);
		killPeds->AddItem(std::make_shared<CommandItem>("killallpeds"_J));
		killPeds->AddItem(std::make_shared<CommandItem>("killallenemies"_J));

		main->AddItem(std::move(killPeds));
		main->AddItem(std::make_shared<CommandItem>("forcelighting"_J));

		shows->AddItem(std::make_shared<ImGuiItem>([] {
			RenderShowsMenu();
		}));

		AddCategory(std::move(main));
		AddCategory(std::move(weather));
		AddCategory(std::move(spawners));
		AddCategory(std::move(shows));
	}

}
