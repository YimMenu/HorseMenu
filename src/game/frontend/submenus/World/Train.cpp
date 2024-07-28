#include "Train.hpp"

#include "game/backend/Self.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/data/Trains.hpp"
#include "util/Joaat.hpp"
#include "util/teleport.hpp"


namespace YimMenu::Submenus
{
	void RenderTrainsMenu()
	{
		static uint32_t selectedTrain = 0;
		static bool hasPax            = false;
		static bool hasConductor      = false; // Depends on warpOnSpawn
		static bool warpOnSpawn       = true;  // Depends on hasConductor
		static bool stopsForStations  = false; // Depends on hasConductor

		ImGui::PushID("trains"_J);
		if (ImGui::BeginCombo("##Preset Model", "Train Model"))
		{
			for (size_t i = 0; i < std::size(Data::g_Trains); ++i)
			{
				const auto& train = Data::g_Trains[i];
				if (ImGui::Selectable(train.name.c_str(), train.model == selectedTrain))
				{
					selectedTrain = train.model;
				}
			}
			ImGui::EndCombo();
		}


		ImGui::Checkbox("Passengers", &hasPax);
		ImGui::SameLine();

		ImGui::Checkbox("Conductor", &hasConductor);
		ImGui::SameLine();

		ImGui::Checkbox("Warp Into Seat", &warpOnSpawn);
		ImGui::SameLine();

		ImGui::Checkbox("Station Stops", &stopsForStations);

		if (ImGui::Button("Spawn"))
		{
			if (selectedTrain != 0)
			{
				FiberPool::Push([=] {
					auto selfCoords = Self::GetPed().GetPosition();
					auto coords = VEHICLE::_GET_NEAREST_TRAIN_TRACK_POSITION(selfCoords.x, selfCoords.y, selfCoords.z);


					auto numcars = VEHICLE::_GET_NUM_CARS_FROM_TRAIN_CONFIG(selectedTrain);

					for (int i = 0; i <= numcars - 1; i++)
					{
						STREAMING::REQUEST_MODEL(VEHICLE::_GET_TRAIN_MODEL_FROM_TRAIN_CONFIG_BY_CAR_INDEX(selectedTrain, i), false);

						while (!STREAMING::HAS_MODEL_LOADED(VEHICLE::_GET_TRAIN_MODEL_FROM_TRAIN_CONFIG_BY_CAR_INDEX(selectedTrain, i)))
						{
							STREAMING::REQUEST_MODEL(VEHICLE::_GET_TRAIN_MODEL_FROM_TRAIN_CONFIG_BY_CAR_INDEX(selectedTrain, i), false);
							ScriptMgr::Yield();
						}
					}


					auto veh = VEHICLE::_CREATE_MISSION_TRAIN(selectedTrain, coords.x, coords.y, coords.z, 1, hasPax, true, hasConductor);
					VEHICLE::_0x06A09A6E0C6D2A84(veh, false);
					VEHICLE::_SET_TRAIN_STOPS_FOR_STATIONS(veh, stopsForStations);
					NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(NETWORK::VEH_TO_NET(veh), true);


					for (int i = 0; i <= numcars - 1; i++)
					{
						auto car = VEHICLE::GET_TRAIN_CARRIAGE(veh, i);
						VEHICLE::_0x762FDC4C19E5A981(car, true);
					}

					if (warpOnSpawn)
					{
						Teleport::WarpIntoVehicle(Self::GetPed().GetHandle(), veh);
					}
				});
			}
		}
		ImGui::PopID();
	}
}