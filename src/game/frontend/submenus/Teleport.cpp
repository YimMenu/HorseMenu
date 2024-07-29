#include "Teleport.hpp"

#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"
#include "game/backend/SavedLocations.hpp"
#include "game/backend/Self.hpp"
#include "game/frontend/items/Items.hpp"
#include "util/Math.hpp"
#include "util/Teleport.hpp"


namespace YimMenu::Submenus
{
	static float GetDistanceFromLocation(const SavedLocation& t)
	{
		return rage::fvector3(t.x, t.y, t.z).GetDistance(Self::GetPed().GetPosition());
	}

	void RenderCustomTeleport()
	{
		ImGui::BeginGroup();
		static std::string newLocationName{};
		static std::string category = "Default";
		static SavedLocation locationToDelete;

		if (!std::string(locationToDelete.name).empty())
			ImGui::OpenPopup("##deletelocation");

		if (ImGui::BeginPopupModal("##deletelocation", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
		{
			ImGui::Text("Are you sure you want to delete %s?", locationToDelete.name);

			ImGui::Spacing();

			if (ImGui::Button("Yes"))
			{
				SavedLocations::DeleteSavedLocation(category, locationToDelete.name);
				locationToDelete.name = "";
				ImGui::CloseCurrentPopup();
			}
			ImGui::SameLine();
			if (ImGui::Button("No"))
			{
				locationToDelete.name = "";
				ImGui::CloseCurrentPopup();
			}

			ImGui::EndPopup();
		}

		ImGui::PushItemWidth(300);
		InputTextWithHint("Category", "Category", &category).Draw();

		ImGui::PushItemWidth(200);
		InputTextWithHint("Location name", "New location", &newLocationName).Draw();
		ImGui::PopItemWidth();

		if (ImGui::Button("Save current location")) // Button widget still crashes
		{
			FiberPool::Push([=] {
				if (newLocationName.empty())
				{
					Notifications::Show("Custom Teleport", "Please enter a valid name.", NotificationType::Warning);
				}
				else if (SavedLocations::GetSavedLocationByName(newLocationName))
				{
					Notifications::Show("Custom Teleport", std::format("Location with the name {} already exists", newLocationName));
				}
				else
				{
					SavedLocation teleportLocation;
					Entity teleportEntity = Self::GetPed();
					if (auto vehicle = Self::GetVehicle())
						teleportEntity = vehicle;
					else if (auto mount = Self::GetMount())
						teleportEntity = mount;

					auto coords            = teleportEntity.GetPosition();
					teleportLocation.name  = newLocationName;
					teleportLocation.x     = coords.x;
					teleportLocation.y     = coords.y;
					teleportLocation.z     = coords.z;
					teleportLocation.yaw   = ENTITY::GET_ENTITY_HEADING(teleportEntity.GetHandle());
					teleportLocation.pitch = CAM::GET_GAMEPLAY_CAM_RELATIVE_PITCH();
					teleportLocation.roll  = CAM::GET_GAMEPLAY_CAM_RELATIVE_HEADING();
					SavedLocations::SaveNewLocation(category, teleportLocation);
				}
			});
		};


		ImGui::Separator();

		ImGui::Text("Double click to teleport\nShift click to delete");

		ImGui::Spacing();

		static std::string filter{};
		InputTextWithHint("##filter", "Search", &filter).Draw();

		ImGui::BeginGroup();
		ImGui::Text("Categories");
		if (ImGui::BeginListBox("##categories", {200, -1}))
		{
			for (auto& l : SavedLocations::GetAllSavedLocations() | std::ranges::views::keys)
			{
				if (ImGui::Selectable(l.data(), l == category))
				{
					category = l;
				}

				if (category.empty())
				{
					category = l;
				}
			}
			ImGui::EndListBox();
		}
		ImGui::EndGroup();
		ImGui::SameLine();
		ImGui::BeginGroup();
		ImGui::Text("Locations");
		if (ImGui::BeginListBox("##saved_locs", {200, -1})) // Need automatic dimensions instead of hard coded
		{
			if (SavedLocations::GetAllSavedLocations().find(category) != SavedLocations::GetAllSavedLocations().end())
			{
				std::vector<SavedLocation> current_list{};

				if (!filter.empty())
					current_list = SavedLocations::SavedLocationsFilteredList(filter);
				else
					current_list = SavedLocations::GetAllSavedLocations().at(category);

				for (const auto& l : current_list)
				{
					if (ImGui::Selectable(l.name.data(), false, ImGuiSelectableFlags_AllowDoubleClick))
					{
						if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
						{
							locationToDelete = l;
						}
						else
						{
							if (ImGui::IsMouseDoubleClicked(0))
							{
								FiberPool::Push([l] {
									rage::fvector3 l_ = {l.x, l.y, l.z};
									YimMenu::Teleport::TeleportEntity(Self::GetPed().GetHandle(), l_, false);
								});
							}
						}
					}

					if (ImGui::IsItemHovered())
					{
						ImGui::BeginTooltip();
						if (l.name.length() > 27)
							ImGui::Text(l.name.data());
						ImGui::Text("Distance: %f", GetDistanceFromLocation(l));
						ImGui::EndTooltip();
					}
				}
			}

			ImGui::EndListBox();
		}

		ImGui::EndGroup();

		ImGui::EndGroup();
	}

	Teleport::Teleport() :
	    Submenu::Submenu("Teleport")
	{
		auto main      = std::make_shared<Category>("Main");
		auto miscGroup = std::make_shared<Group>("Misc");

		miscGroup->AddItem(std::make_shared<BoolCommandItem>("autotp"_J));
		miscGroup->AddItem(std::make_shared<CommandItem>("tptowaypoint"_J));
		miscGroup->AddItem(std::make_shared<CommandItem>("tptomount"_J));
		miscGroup->AddItem(std::make_shared<CommandItem>("tptotraintrack"_J));
		miscGroup->AddItem(std::make_shared<CommandItem>("tptomoonshineshack"_J));
		miscGroup->AddItem(std::make_shared<CommandItem>("tptonazar"_J));

		main->AddItem(miscGroup);

		auto customteleport = std::make_shared<Category>("Saved");
		customteleport->AddItem(std::make_shared<ImGuiItem>([] {
			RenderCustomTeleport();
		}));


		AddCategory(std::move(main));
		AddCategory(std::move(customteleport));
	}
}
