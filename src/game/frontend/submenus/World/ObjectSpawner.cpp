#include "core/commands/Command.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/NativeHooks.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/data/ObjModels.hpp"
#include "ObjectSpawner.hpp"
#include "util/SpawnObject.hpp"

namespace YimMenu::Submenus
{
	static bool IsObjectModelInList(const std::string& model)
	{
		for (const auto& objModel : YimMenu::Data::g_ObjModels)
		{
			if (objModel.model == model)
				return true;
		}
		return false;
	}

	static int ObjectSpawnerInputCallback(ImGuiInputTextCallbackData* data)
	{
		if (data->EventFlag == ImGuiInputTextFlags_CallbackCompletion)
		{
			std::string newText;
			std::string inputLower = data->Buf;
			std::transform(inputLower.begin(), inputLower.end(), inputLower.begin(), ::tolower);

			for (const auto& objModel : YimMenu::Data::g_ObjModels)
			{
				std::string modelLower = objModel.model;
				std::transform(modelLower.begin(), modelLower.end(), modelLower.begin(), ::tolower);
				if (modelLower.find(inputLower) != std::string::npos)
				{
					newText = objModel.model;
					break;
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
		static std::string objectModelBuffer;
		static float positionOffsetX = 5.0f;
		static float positionOffsetY = 5.0f;
		static float positionOffsetZ = 0.0f;
		static float pitch           = 0.0f;
		static float yaw             = 0.0f;
		static float roll            = 0.0f;
		static bool onGround         = false;
		static bool isFrozen         = false;
		static bool isBurning        = false;
		static bool isPickup         = false;
		static bool showPreview      = false;
		static int modelHash         = 0;

		Vector3 playerCoords  = ENTITY::GET_ENTITY_COORDS(Self::GetPed().GetHandle(), true, true);
		Vector3 forwardVector = ENTITY::GET_ENTITY_FORWARD_VECTOR(Self::GetPed().GetHandle());

		Vector3 spawnPosition;
		spawnPosition.x = playerCoords.x + forwardVector.x * positionOffsetX;
		spawnPosition.y = playerCoords.y + forwardVector.y * positionOffsetY;
		spawnPosition.z = playerCoords.z + positionOffsetZ;

		char buffer[256];
		strncpy(buffer, objectModelBuffer.c_str(), sizeof(buffer));

		ImGui::InputTextWithHint("##objectmodel", "Object Model", buffer, sizeof(buffer), ImGuiInputTextFlags_CallbackCompletion, ObjectSpawnerInputCallback);

		objectModelBuffer = buffer;

		if (ImGui::IsItemHovered())
			ImGui::SetTooltip("Press Tab to auto-fill");

		if (!objectModelBuffer.empty() && !IsObjectModelInList(objectModelBuffer))
		{
			ImGui::BeginListBox("##objectmodels", ImVec2(250, 100));

			std::string bufferLower = objectModelBuffer;
			std::transform(bufferLower.begin(), bufferLower.end(), bufferLower.begin(), ::tolower);
			for (const auto& objModel : YimMenu::Data::g_ObjModels)
			{
				std::string objModelLower = objModel.model;
				std::transform(objModelLower.begin(), objModelLower.end(), objModelLower.begin(), ::tolower);
				if (objModelLower.find(bufferLower) != std::string::npos && ImGui::Selectable(objModel.model.c_str()))
				{
					objectModelBuffer = objModel.model;
					modelHash         = Joaat(objectModelBuffer.c_str());
					STREAMING::REQUEST_MODEL(modelHash, false);
					while (!STREAMING::HAS_MODEL_LOADED(modelHash))
					{
						return;
					}
				}
			}

			ImGui::EndListBox();
		}

		ImGui::SliderFloat("Offset X", &positionOffsetX, -25.0f, 25.0f);
		ImGui::SliderFloat("Offset Y", &positionOffsetY, -25.0f, 25.0f);
		ImGui::SliderFloat("Offset Z", &positionOffsetZ, -10.0f, 10.0f);
		ImGui::SliderFloat("Pitch", &pitch, -180.0f, 180.0f);
		ImGui::SliderFloat("Yaw", &yaw, -180.0f, 180.0f);
		ImGui::SliderFloat("Roll", &roll, -180.0f, 180.0f);

		ImGui::Checkbox("Place on Ground", &onGround);
		ImGui::SameLine();
		ImGui::Checkbox("Freeze Position", &isFrozen);
		ImGui::SameLine();
		ImGui::Checkbox("Set on Fire", &isBurning);
		ImGui::SameLine();
		ImGui::Checkbox("Set as Pickup", &isPickup);
		ImGui::Checkbox("Show Preview", &showPreview);

		if (ImGui::Button("Spawn Object"))
		{
			int modelHash = Joaat(objectModelBuffer.c_str());
			SpawnObject(modelHash, spawnPosition, pitch, yaw, roll, onGround, isFrozen, isBurning, isPickup);
		}
		ImGui::SameLine();
		if (ImGui::Button("Reset Sliders"))
		{
			positionOffsetX = 5.0f;
			positionOffsetY = 5.0f;
			positionOffsetZ = 0.0f;
			pitch           = 0.0f;
			yaw             = 0.0f;
			roll            = 0.0f;
		}

		if (showPreview == true)
		{
			int modelHash = Joaat(objectModelBuffer.c_str());
			PreviewObject(modelHash, spawnPosition, pitch, yaw, roll, showPreview);
		}
	}
}