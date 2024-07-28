#include "World.hpp"

#include "World/PedSpawner.hpp"
#include "World/Shows.hpp"
#include "World/Train.hpp"
#include "World/VehicleSpawner.hpp"
#include "World/Weather.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/frontend/items/Items.hpp"
#include <game/rdr/Natives.hpp>


namespace YimMenu::Submenus
{
	World::World() :
	    Submenu::Submenu("World")
	{
		auto main    = std::make_shared<Category>("Main");
		auto weather = std::make_shared<Category>("Weather");
		auto shows   = std::make_shared<Category>("Shows");
		auto time    = std::make_shared<Category>("Time");


		time->AddItem(std::make_shared<ImGuiItem>([] {
			static int hour, minute, second;
			static bool freeze;
			ImGui::SliderInt("Hour", &hour, 0, 23);
			ImGui::SliderInt("Minute", &minute, 0, 59);
			ImGui::SliderInt("Second", &second, 0, 59);
			ImGui::Checkbox("Freeze", &freeze);
			if (ImGui::Button("Change Time"))
			{
				FiberPool::Push([] {
					ChangeTime(hour, minute, second, 0, freeze);
				});
			}
			if (ImGui::Button("Restore"))
			{
				FiberPool::Push([] {
					NETWORK::_NETWORK_CLEAR_CLOCK_OVERRIDE_OVERTIME(0);
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
			if (ImGui::Button("Restore"))
			{
				FiberPool::Push([] {
					MISC::CLEAR_OVERRIDE_WEATHER();
				});
			}
		}));


		auto spawners            = std::make_shared<Category>("Spawners");
		auto pedSpawnerGroup     = std::make_shared<Group>("Ped Spawner");
		auto vehicleSpawnerGroup = std::make_shared<Group>("Vehicle Spawner");
		auto trainSpawnerGroup   = std::make_shared<Group>("Train Spawner");

		pedSpawnerGroup->AddItem(std::make_shared<ImGuiItem>([] {
			RenderPedSpawnerMenu();
		}));

		vehicleSpawnerGroup->AddItem(std::make_shared<ImGuiItem>([] {
			RenderVehicleSpawnerMenu();
		}));

		trainSpawnerGroup->AddItem(std::make_shared<ImGuiItem>([] {
			RenderTrainsMenu();
		}));

		spawners->AddItem(pedSpawnerGroup);
		spawners->AddItem(vehicleSpawnerGroup);
		spawners->AddItem(trainSpawnerGroup);

		auto killPeds = std::make_shared<Group>("Kill", 1);
		killPeds->AddItem(std::make_shared<CommandItem>("killallpeds"_J));
		killPeds->AddItem(std::make_shared<CommandItem>("killallenemies"_J));
		auto deleteOpts = std::make_shared<Group>("Delete", 1);
		deleteOpts->AddItem(std::make_shared<CommandItem>("delpeds"_J));
		deleteOpts->AddItem(std::make_shared<CommandItem>("delvehs"_J));
		deleteOpts->AddItem(std::make_shared<CommandItem>("delobjs"_J));
		auto bringOpts = std::make_shared<Group>("Bring", 1);
		bringOpts->AddItem(std::make_shared<CommandItem>("bringpeds"_J));
		bringOpts->AddItem(std::make_shared<CommandItem>("bringvehs"_J));
		bringOpts->AddItem(std::make_shared<CommandItem>("bringobjs"_J));

		main->AddItem(std::move(killPeds));
		main->AddItem(std::move(deleteOpts));
		main->AddItem(std::move(bringOpts));
		main->AddItem(std::make_shared<BoolCommandItem>("disableguardzones"_J));
		main->AddItem(std::make_shared<CommandItem>("forcelighting"_J));

		shows->AddItem(std::make_shared<ImGuiItem>([] {
			RenderShowsMenu();
		}));


		AddCategory(std::move(main));
		AddCategory(std::move(weather));
		AddCategory(std::move(spawners));
		AddCategory(std::move(shows));
		AddCategory(std::move(time));
	}

}
