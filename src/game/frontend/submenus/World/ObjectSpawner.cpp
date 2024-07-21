#include "core/commands/Command.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/NativeHooks.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/backend/Self.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/rdr/Natives.hpp"
#include "game/rdr/data/ObjModels.hpp"

#include "ObjectSpawner.hpp"

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
		static bool isDynamic        = false;
		static int modelHash         = 0;

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
		if (isDynamic == false)
		{
			ImGui::SliderFloat("Offset Z", &positionOffsetZ, -10.0f, 10.0f);
		}
		ImGui::Checkbox("Dynamic", &isDynamic);
		if (ImGui::Button("Spawn Object"))
		{
			FiberPool::Push([=] {
				int modelHash         = Joaat(objectModelBuffer.c_str());

				if (!STREAMING::HAS_MODEL_LOADED(modelHash))
				{
					STREAMING::REQUEST_MODEL(modelHash, false);
					ScriptMgr::Yield();
				}

				Vector3 playerCoords  = ENTITY::GET_ENTITY_COORDS(Self::GetPed().GetHandle(), true, true);
				Vector3 forwardVector = ENTITY::GET_ENTITY_FORWARD_VECTOR(Self::GetPed().GetHandle());

				Vector3 spawnPosition;
				spawnPosition.x = playerCoords.x + forwardVector.x * positionOffsetX;
				spawnPosition.y = playerCoords.y + forwardVector.y * positionOffsetY;
				if (isDynamic == false)
				{
					spawnPosition.z = playerCoords.z + positionOffsetZ;
				}
				else
				{
					spawnPosition.z = playerCoords.z;
				}
				Object objectHandle = OBJECT::CREATE_OBJECT(modelHash, spawnPosition.x, spawnPosition.y, spawnPosition.z, true, true, isDynamic, false, false);
				if (isDynamic == false)
				{
					ENTITY::FREEZE_ENTITY_POSITION(objectHandle, true);
				}
				else
				{
					OBJECT::PLACE_OBJECT_ON_GROUND_PROPERLY(objectHandle, true);
				}

				OBJECT::_MAKE_ITEM_CARRIABLE(objectHandle); // For dropping pickup type items like mp001_s_mp_boxsm01x

				NETWORK::NETWORK_REGISTER_ENTITY_AS_NETWORKED(objectHandle);
				if (NETWORK::NETWORK_DOES_NETWORK_ID_EXIST(NETWORK::OBJ_TO_NET(objectHandle)))
				{
					NETWORK::SET_NETWORK_ID_EXISTS_ON_ALL_MACHINES(NETWORK::OBJ_TO_NET(objectHandle), true);
					NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(objectHandle);
				}

				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(modelHash);
				ENTITY::SET_OBJECT_AS_NO_LONGER_NEEDED(&objectHandle);
			});
		}
	}
}