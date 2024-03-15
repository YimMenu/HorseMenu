#include "world.hpp"
#include "game/backend/FiberPool.hpp"
#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/backend/ScriptMgr.hpp"

#include <game/rdr/Natives.hpp>
#include <imgui.h> // Include for ImGui
#include <memory>  // Include for std::make_shared
#include "features.hpp"

namespace monopoly::Submenus
{
	World::World() :
	    Submenu::Submenu("World")
	{
		auto main     = std::make_shared<Category>("Main");
		auto weather = std::make_shared<Category>("Weather");
		
	

		main->AddItem(std::make_shared<ImGuiItem>([] {
			if (ImGui::Button("always night"))
			{
				
				NETWORK::_NETWORK_CLOCK_TIME_OVERRIDE(1, 0, 0, 0, false);
			}
		}));
		main->AddItem(std::make_shared<ImGuiItem>([] {
			if (ImGui::Button("always day"))
			{
				NETWORK::_NETWORK_CLOCK_TIME_OVERRIDE(15, 0, 0, 0, false);
			}
		}));
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
					RDR2_ChangeTime(h, m, s);
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

								RDR2_ChangeWeather(weather_type);
							});
						}
						if (is_selected)
							ImGui::SetItemDefaultFocus();
					}
					ImGui::EndCombo();
				}
			}));
		weather->AddItem(std::make_shared<ImGuiItem>([] {
			static std::string deep;
			InputTextWithHint("Snow", "Enter Snow Depth", &deep).Draw();

			if (ImGui::Button("Change Snow Depth"))
			{
				float snow_depth = std::stof(deep);

				FiberPool::Push([=] {
					std::cout << "Snow Level: " << MISC::GET_SNOW_LEVEL() << std::endl;
					MISC::_SET_SNOW_LEVEL(snow_depth);
				});
			}
		}));



		AddCategory(std::move(main));
		AddCategory(std::move(weather));




	}
	
}
