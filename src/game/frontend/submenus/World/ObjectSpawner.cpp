#include "ObjectSpawner.hpp"

#include "core/commands/LoopedCommand.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/Object.hpp"
#include "game/rdr/data/ObjectModels.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/data/VehicleModels.hpp"

namespace Terminus::Submenus
{
	static rage::fvector3 GetForwardOffset(float headingDegrees, float distance)
	{
		float heading = headingDegrees * 3.14159265f / 180.0f;
		return rage::fvector3(-std::sin(heading) * distance, std::cos(heading) * distance, 0.0f);
	}

	static bool IsObjectModelInList(const std::string& model)
	{
		for (const auto& objModel : Data::GetObjectModels())
		{
			if (objModel.model == model)
				return true;
		}
		return false;
	}

	static int ObjSpawnerInputCallback(ImGuiInputTextCallbackData* data)
	{
		if (data->EventFlag == ImGuiInputTextFlags_CallbackCompletion)
		{
			std::string newText{};
			std::string inputLower = data->Buf;
			std::transform(inputLower.begin(), inputLower.end(), inputLower.begin(), ::tolower);

			for (const auto& objModel : Data::GetObjectModels())
			{
				std::string modelLower = objModel.model;
				std::transform(modelLower.begin(), modelLower.end(), modelLower.begin(), ::tolower);

				if (modelLower.find(inputLower) != std::string::npos)
				{
					newText = objModel.model;
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

	void RenderObjectSpawnerMenu()
	{
		ImGui::PushID("objects"_J);

		static std::string objModelBuffer;

		InputTextWithHint("##objmodel", "Object Model", &objModelBuffer, ImGuiInputTextFlags_CallbackCompletion, nullptr, ObjSpawnerInputCallback)
		    .Draw();

		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Press Tab to auto fill");

		if (!objModelBuffer.empty() && !IsObjectModelInList(objModelBuffer))
		{
			ImGui::BeginListBox("##objmodels", ImVec2(250, 100));

			std::string bufferLower = objModelBuffer;
			std::transform(bufferLower.begin(), bufferLower.end(), bufferLower.begin(), ::tolower);

			for (const auto& objModel : Data::GetObjectModels())
			{
				std::string modelLower = objModel.model;
				std::transform(modelLower.begin(), modelLower.end(), modelLower.begin(), ::tolower);

				if (modelLower.find(bufferLower) != std::string::npos && ImGui::Selectable(objModel.model.c_str()))
				{
					objModelBuffer = objModel.model;
				}
			}

			ImGui::EndListBox();
		}

		if (ImGui::Button("Spawn"))
		{
			FiberPool::Push([=] {
				auto ped = Self::GetPed();
				auto coords = ped.GetPosition();
				float heading = ped.GetRotation().z;

				auto forward = GetForwardOffset(heading, 3.0f);
				auto newPos = coords + forward;

				Object::Create(Joaat(objModelBuffer), newPos);
		});
		}
		ImGui::PopID();
	}
}
