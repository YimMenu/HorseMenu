#include "VehicleSpawner.hpp"

#include "core/commands/LoopedCommand.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/data/VehicleModels.hpp"
#include "game/backend/Self.hpp"
#include "game/rdr/Vehicle.hpp"


namespace YimMenu::Submenus
{
	static bool IsVehModelInList(std::string model)
	{
		for (const auto& vehModel : Data::g_VehicleModels)
		{
			if (vehModel.model == model)
				return true;
		}

		return false;
	}

	static int VehSpawnerInputCallback(ImGuiInputTextCallbackData* data)
	{
		if (data->EventFlag == ImGuiInputTextFlags_CallbackCompletion)
		{
			std::string newText{};
			std::string inputLower = data->Buf;
			std::transform(inputLower.begin(), inputLower.end(), inputLower.begin(), ::tolower);
			for (const auto& vehModel : Data::g_VehicleModels)
			{
				std::string modelLower = vehModel.model;
				std::transform(modelLower.begin(), modelLower.end(), modelLower.begin(), ::tolower);
				if (modelLower.find(inputLower) != std::string::npos)
				{
					newText = vehModel.model;
				}
			}

			if (!newText.empty())
			{
				data->DeleteChars(0, data->BufTextLen);
				data->InsertChars(0, newText.c_str());
			}

			return 1;
		}
		return 0;
	}

	void RenderVehicleSpawnerMenu()
	{
		ImGui::PushID("vehicles"_J);
		static std::string vehModelBuffer;
		InputTextWithHint("##vehmodel", "Vehicle Model", &vehModelBuffer, ImGuiInputTextFlags_CallbackCompletion, nullptr, VehSpawnerInputCallback)
		    .Draw();
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Press Tab to auto fill");
		if (!vehModelBuffer.empty() && !IsVehModelInList(vehModelBuffer))
		{
			ImGui::BeginListBox("##vehmodels", ImVec2(250, 100));

			std::string bufferLower = vehModelBuffer;
			std::transform(bufferLower.begin(), bufferLower.end(), bufferLower.begin(), ::tolower);
			for (const auto& vehModel : Data::g_VehicleModels)
			{
				std::string vehModelLower = vehModel.model;
				std::transform(vehModelLower.begin(), vehModelLower.end(), vehModelLower.begin(), ::tolower);
				if (vehModelLower.find(bufferLower) != std::string::npos && ImGui::Selectable(vehModel.model.data()))
				{
					vehModelBuffer = vehModel.model;
				}
			}

			ImGui::EndListBox();
		}

		if (ImGui::Button("Spawn"))
		{
			FiberPool::Push([=] {
				auto coords    = Self::GetPed().GetPosition();
				auto newCoords = coords + rage::fvector3(10, 10, 0);
				Vehicle::Create(Joaat(vehModelBuffer), newCoords, Self::GetPed().GetRotation().z);
			});
		}
		ImGui::PopID();
	}
}
