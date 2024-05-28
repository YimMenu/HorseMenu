#include "World.hpp"

#include "game/backend/FiberPool.hpp"
#include "game/frontend/items/Items.hpp"
#include "util/Ped.hpp"
#include "util/libraries/PedModels.hpp"


namespace YimMenu::Submenus
{
	bool is_ped_model_in_ped_model_list(std::string model)
	{
		for (const auto& pedModel : pedModels)
		{
			if (pedModel.model == model)
				return true;
		}

		return false;
	}

	int PedSpawnerInputCallback(ImGuiInputTextCallbackData* data)
	{
		if (data->EventFlag == ImGuiInputTextFlags_CallbackCompletion)
		{
			std::string newText{};
			std::string inputLower = data->Buf;
			std::transform(inputLower.begin(), inputLower.end(), inputLower.begin(), ::tolower);
			for (const auto& pedModel : pedModels)
			{
				std::string modelLower = pedModel.model;
				std::transform(modelLower.begin(), modelLower.end(), modelLower.begin(), ::tolower);
				if (modelLower.find(inputLower) != std::string::npos)
				{
					newText = pedModel.model;
				}
			}

			if (!newText.empty())
			{
				data->DeleteChars(0, data->BufTextLen);
				data->InsertChars(0, newText.c_str());
			}
		}

		// remove this after done debugging
		return 1;
	}

	void PedSpawnerGroup()
	{
		static std::string pedModelBuffer;
		static float scale = 1;
		static bool dead, invis, godmode, freeze;
		InputTextWithHint("##pedmodel", "Ped Model", &pedModelBuffer, ImGuiInputTextFlags_CallbackCompletion, nullptr, PedSpawnerInputCallback)
		    .Draw();
		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Press Tab to auto fill");
		if (!pedModelBuffer.empty() && !is_ped_model_in_ped_model_list(pedModelBuffer))
		{
			ImGui::BeginListBox("##pedmodels", ImVec2(250, 100));

			std::string bufferLower = pedModelBuffer;
			std::transform(bufferLower.begin(), bufferLower.end(), bufferLower.begin(), ::tolower);
			for (const auto& pedModel : pedModels)
			{
				std::string pedModelLower = pedModel.model;
				std::transform(pedModelLower.begin(), pedModelLower.end(), pedModelLower.begin(), ::tolower);
				if (pedModelLower.find(bufferLower) != std::string::npos && ImGui::Selectable(pedModel.model.data()))
				{
					pedModelBuffer = pedModel.model;
				}
			}

			ImGui::EndListBox();
		}

		ImGui::Checkbox("Spawn Dead", &dead);
		ImGui::Checkbox("Invisible", &invis);
		ImGui::Checkbox("GodMode", &godmode);
		ImGui::Checkbox("Frozen", &freeze);
		ImGui::SliderFloat("Scale", &scale, 0.1, 10);
		if (ImGui::Button("Spawn"))
		{
			FiberPool::Push([] {
				Peds::SpawnPed(pedModelBuffer, ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(Self::PlayerPed, 0, 3, 0), 0, freeze, dead, godmode, invis, scale);
			});
		}
	}

	World::World() :
	    Submenu::Submenu("World")
	{
		auto spawners        = std::make_shared<Category>("Spawners");
		auto pedSpawnerGroup = std::make_shared<Group>("Ped Spawner", GetListBoxDimensions());

		pedSpawnerGroup->AddItem(std::make_shared<ImGuiItem>([] {
			PedSpawnerGroup();
		}));

		spawners->AddItem(pedSpawnerGroup);

		AddCategory(std::move(spawners));
	}
}