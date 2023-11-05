#include "Teleport.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/bigfeatures/CustomTeleport.hpp"
#include "util/Math.hpp"
#include "util/Teleport.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/backend/FiberPool.hpp"

namespace YimMenu::Submenus
{
	Telelocation GetLocationPlayerIsClosestTo()
	{
		if (!Pointers.GetLocalPed)
			return {};

		float distance = 500;
		Telelocation closestLocation{};
		//saved_locations_filtered_list can be used to get a joint list of all categories when the filter is empty.
		for (auto& loc : CustomTeleport::SavedLocationsFilteredList())
		{
			float newDistance = Math::DistanceBetweenVectors(Self::Pos, {loc.x, loc.y, loc.z});

			if (newDistance < distance)
				closestLocation = loc, distance = newDistance;
		}

		return closestLocation;
	}

	float GetDistanceToTelelocation(Telelocation t)
	{
		return Math::DistanceBetweenVectors(Vector3(t.x, t.y, t.z), Self::Pos);
	}


	void RenderCustomTeleport()
	{
		ImGui::BeginGroup();
		static std::string NewLocationName{};
		static std::string category = "Default";
		static Telelocation deleteTelelocation;
		static std::string filter{};

		if (!std::string(deleteTelelocation.name).empty())
			ImGui::OpenPopup("##deletelocation");

		if (ImGui::BeginPopupModal("##deletelocation", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove))
		{
			ImGui::Text("Are you sure you want to delete %s?", deleteTelelocation.name);

			ImGui::Spacing();

			if (ImGui::Button("Yes"))
			{
				CustomTeleport::DeleteSavedLocation(category, deleteTelelocation.name);
				deleteTelelocation.name = "";
				ImGui::CloseCurrentPopup();
			}
			ImGui::SameLine();
			if (ImGui::Button("No"))
			{
				deleteTelelocation.name = "";
				ImGui::CloseCurrentPopup();
			}

			ImGui::EndPopup();
		}

		ImGui::PushItemWidth(300);
		InputTextWithHint("Category", "Category", &category).Draw();

		InputTextWithHint("Location name", "New location", &NewLocationName).Draw();
		ImGui::PopItemWidth();

		if (ImGui::Button("Save current location")) //Button widget still crashes
		{
			FiberPool::Push([=] {
				if (NewLocationName.empty())
				{
					Notifications::Show("Custom Teleport", "Please enter a valid name.", NotificationType::Warning);
				}
				else if (CustomTeleport::GetSavedLocationByName(NewLocationName))
				{
					Notifications::Show("Custom Teleport", std::format("Location with the name {} already exists", NewLocationName));
				}
				else
				{
					Telelocation teleportLocation;
					Entity teleportEntity = Self::PlayerPed;
					if (Self::Veh != 0)
						teleportEntity = Self::Veh;
					else if (Self::IsOnMount)
						teleportEntity = Self::Mount;

					auto coords             = ENTITY::GET_ENTITY_COORDS(teleportEntity, false, true);
					teleportLocation.name  = NewLocationName;
					teleportLocation.x     = coords.x;
					teleportLocation.y     = coords.y;
					teleportLocation.z     = coords.z;
					teleportLocation.yaw   = ENTITY::GET_ENTITY_HEADING(teleportEntity);
					teleportLocation.pitch = CAM::GET_GAMEPLAY_CAM_RELATIVE_PITCH();
					teleportLocation.roll  = CAM::GET_GAMEPLAY_CAM_RELATIVE_HEADING();
					CustomTeleport::SaveNewLocation(category, teleportLocation);
				}
			});
		};


		ImGui::Separator();

		ImGui::Text("Double click to teleport\nShift click to delete");

		ImGui::Spacing();
		InputTextWithHint("##filter", "Search", &filter).Draw();

		ImGui::BeginGroup();
		ImGui::Text("Categories");
		if (ImGui::BeginListBox("##categories", {200, -1}))
		{
			for (auto& l : CustomTeleport::GetAllSavedLocations() | std::ranges::views::keys)
			{
				if (ImGui::Selectable(l.data(), l == category))
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
		if (ImGui::BeginListBox("##Telelocations", {200, -1})) //Need automatic dimensions instead of hard coded
		{
			if (CustomTeleport::GetAllSavedLocations().find(category) != CustomTeleport::GetAllSavedLocations().end())
			{
				std::vector<Telelocation> current_list{};

				if (!filter.empty())
					current_list = CustomTeleport::SavedLocationsFilteredList(filter);
				else
					current_list = CustomTeleport::GetAllSavedLocations().at(category);

				for (const auto& l : current_list)
				{
					if (ImGui::Selectable(l.name.data(), l.name == GetLocationPlayerIsClosestTo().name, ImGuiSelectableFlags_AllowDoubleClick))
					{
						if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
						{
							deleteTelelocation = l;
						}
						else
						{
							if (ImGui::IsMouseDoubleClicked(0))
							{
								FiberPool::Push([l] {
									Vector3 l_ = {l.x, l.y, l.z};
									YimMenu::Teleport::TeleportEntity(Self::PlayerPed,l_, false);
								});
							}
						}
					}
					if (ImGui::IsItemHovered())
					{
						ImGui::BeginTooltip();
						if (l.name.length() > 27)
							ImGui::Text(l.name.data());
						ImGui::Text("Distance: %f", GetDistanceToTelelocation(l));
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
		auto main = std::make_shared<Category>("Main");
		auto columns = std::make_shared<Column>(2);
		auto miscGroup = std::make_shared<Group>("Misc", GetListBoxDimensions());

		miscGroup->AddItem(std::make_shared<CommandItem>("tptowaypoint"_J));
		miscGroup->AddItem(std::make_shared<CommandItem>("tptomount"_J));

		columns->AddItem(miscGroup);
		main->AddItem(columns);

		auto customteleport = std::make_shared<Category>("Saved");
		customteleport->AddItem(std::make_shared<ImGuiItem>([] {
			RenderCustomTeleport();
		}));


		AddCategory(std::move(main));
		AddCategory(std::move(customteleport));
	}
}