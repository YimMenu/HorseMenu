#include "MapEditorMenu.hpp"
#include "NativeDrawing.hpp"
#include "../MapEditor.hpp"
#include "../Items/PedCategories.hpp"
#include "../Items/VehicleCategories.hpp"
#include "../Items/ObjectCategories.hpp"
#include "../Items/PedScenarios.hpp"
#include "../Items/PedExpressions.hpp"
#include "../Items/MapPed.hpp"
#include "../Items/MapObject.hpp"
#include "../Items/MapVehicle.hpp"

namespace YimMenu
{
	std::unordered_map<MapEntity::Type, std::vector<NativeMenu::Submenu>> MapEditorMenu::sm_SubmenusByType = {
	    {MapEntity::Type::PED, {
			"Actors"sv,
		}},
		{MapEntity::Type::OBJECT, {
			"Props"sv,
		}},
		{MapEntity::Type::VEHICLE, {
			"Vehicles"sv,
		}},
	};

	// TODO: we're calling this a "mission creator" but this is actually just a glorified map editor
	MapEditorMenu::MapEditorMenu(MapInfo* info) :
	    NativeMenu::NativeMenu("Creator", 0.012499f, 0.07422201f, "Mission Creator"sv),
	    m_Info(info)
	{
	}

	void MapEditorMenu::UpdateView()
	{
		if (BeginSubmenu("Mission Creator"sv))
		{
			SubmenuButton("Mission Details", "Mission Details"sv, "Access Mission details");
			SubmenuButton("Placement", "Placement"sv, "Place items");
			BeginDisabled(m_Info->m_Name.empty(), "A Mission must have a name");
			if (Button("Save", "Save the mission to disk"))
			{
				MapEditor::SaveMap();
				NativeUI::ShowAlertMessage("Alert", "Your Mission has been saved", "IB_ACCEPT"_J);
			}
			EndDisabled();
			SubmenuButton("Load", "Load"sv, "Load Missions from disk");
			if (Button("Exit"sv))
			{
				if (NativeUI::ShowAlertMessage("Alert", "Are you sure you want to leave Mission Creator? Any unsaved data will be lost", "IB_YES"_J, "IB_NO"_J))
				{
					MapEditor::Toggle();
				}
			}
			EndSubmenu();
		}

		if (BeginSubmenu("Mission Details"sv))
		{
			char mission_name[26]; strncpy(mission_name, m_Info->m_Name.c_str(), sizeof(mission_name));
			char mission_desc[255]; strncpy(mission_desc, m_Info->m_Description.c_str(), sizeof(mission_desc));
			if (TextOption("Name", mission_name, sizeof(mission_name), "Sets the name of the mission"))
			{
				m_Info->m_Name = mission_name;
			}
			if (TextOption("Description", mission_desc, sizeof(mission_desc), "Sets the mission description"))
			{
				m_Info->m_Description = mission_desc;
			}
			EndSubmenu();
		}

		if (BeginSubmenu("Load"sv))
		{
			if (DidJustEnterSubmenu())
			{
				MapEditor::RefreshAvailableMaps();
			}

			std::optional<std::string> map_to_delete = std::nullopt;
			for (const auto& map : MapEditor::GetAvailableMaps())
			{
				if (Button(map, "Load the selected map"))
				{
					bool are_we_loading = false;

					// try saving the old map (this doesn't match GTA's behavior, but our creator doesn't separate the main menu from the editor menu)
					if (!m_Info->m_Name.empty())
					{
						MapEditor::SaveMap();
						are_we_loading = true;
					}
					else
					{
						are_we_loading = NativeUI::ShowAlertMessage("Alert", "Are you sure you want to load this Mission? Any unsaved data will be lost", "IB_YES"_J, "IB_NO"_J);
					}

					if (are_we_loading)
					{
						bool success = MapEditor::LoadMap(map);
						if (!success)
						{
							NativeUI::ShowAlertMessage("Alert", std::format("The Mission \"{}\" is corrupt and cannot be loaded", map), "IB_ACCEPT"_J);
						}
						else
						{
							NativeUI::ShowAlertMessage("Alert", std::format("The Mission \"{}\" has been loaded", map), "IB_ACCEPT"_J);
						}
					}

					NativeUI::FadeScreenIn(2000);
				}
			}

			if (map_to_delete)
				MapEditor::DeleteMap(*map_to_delete);

			EndSubmenu();
		}

		if (BeginSubmenu("Placement"sv))
		{
			SubmenuButton("Actors", "Actors"sv, "Place actors (peds) in the mission");
			SubmenuButton("Vehicles", "Vehicles"sv, "Place vehicles in the mission");
			SubmenuButton("Props", "Props"sv, "Place props in the mission");
			EndSubmenu();
		}

		if (BeginSubmenu("Actors"sv))
		{
			auto editing_ped = MapEditor::GetEditingEntity(MapEntity::Type::PED);
			if (editing_ped)
			{
				auto as_ped = (MapPed*)(&*editing_ped); // we do this to avoid a dynamic cast (which requires RTTI)
				auto sel_model_hash = as_ped->m_ModelHash;
				bool model_updated = false;

				auto cat_view = CategoryUtils::GetCategoryView(g_PedCategories, sel_model_hash);

				if (!cat_view.m_CurrentEntry)
				{
					LOG(WARNING) << "Failed to get category view of ped with hash " << HEX(sel_model_hash);
					sel_model_hash = "player_zero"_J;
					cat_view = CategoryUtils::GetCategoryView(g_PedCategories, sel_model_hash);
				}

				auto delta = ListOption("Category",
				    cat_view.m_CurrentEntry->first,
				    cat_view.m_PreviousEntry ? std::optional(cat_view.m_PreviousEntry->first) : std::nullopt,
				    cat_view.m_NextEntry ? std::optional(cat_view.m_NextEntry->first) : std::nullopt,
				    "Sets the category from which the Actor can be chosen");

				if (delta < 0)
				{
					cat_view.m_CurrentEntry = cat_view.m_PreviousEntry; // surely there's a better way to write this
					sel_model_hash = cat_view.m_CurrentEntry->second[0].m_Hash;
					model_updated = true;
				}
				else if (delta > 0)
				{
					cat_view.m_CurrentEntry = cat_view.m_NextEntry;
					sel_model_hash = cat_view.m_CurrentEntry->second[0].m_Hash;
					model_updated = true;
				}
				
				auto list_view = CategoryUtils::GetListView(cat_view.m_CurrentEntry->second, sel_model_hash);

				auto list_delta = ListOption("Type",
				    list_view.m_CurrentEntry->m_FriendlyName,
				    list_view.m_PreviousEntry ? std::optional(list_view.m_PreviousEntry->m_FriendlyName) : std::nullopt,
				    list_view.m_NextEntry ? std::optional(list_view.m_NextEntry->m_FriendlyName) : std::nullopt,
				    "Sets the Actor's type from the chosen category");
				
				if (list_delta < 0)
				{
					sel_model_hash = list_view.m_PreviousEntry->m_Hash;
					model_updated = true;
				}
				else if (list_delta > 0)
				{
					sel_model_hash = list_view.m_NextEntry->m_Hash;
					model_updated = true;
				}

				if (model_updated)
				{
					as_ped->ChangeModel(sel_model_hash);
				}

				int ui_variation = as_ped->m_Variation + 1;
				if (IntOption("Variation", ui_variation, 1, list_view.m_CurrentEntry->m_NumVariations, 1, "Select the variation"))
				{
					as_ped->ChangeVariation(ui_variation - 1);
				}

				auto scen_view = CategoryUtils::GetListView(g_PedScenarios, as_ped->m_Scenario);
				if (!scen_view.m_CurrentEntry)
				{
					LOG(WARNING) << "Failed to get scenario view with hash " << HEX(as_ped->m_Scenario);
					scen_view = CategoryUtils::GetListView(g_PedScenarios, 0);
				}

				auto scen_delta = ListOption("Scenario",
				    scen_view.m_CurrentEntry->m_FriendlyName,
				    scen_view.m_PreviousEntry ? std::optional(scen_view.m_PreviousEntry->m_FriendlyName) : std::nullopt,
				    scen_view.m_NextEntry ? std::optional(scen_view.m_NextEntry->m_FriendlyName) : std::nullopt,
				    "Choose the ambient scenario for the Actor");

				if (scen_delta < 0)
				{
					as_ped->ChangeScenario(scen_view.m_PreviousEntry->m_Hash);
				}
				else if (scen_delta > 0)
				{
					as_ped->ChangeScenario(scen_view.m_NextEntry->m_Hash);
				}

				auto exp_view = CategoryUtils::GetListView(g_PedExpressions, as_ped->m_Expression);
				if (!exp_view.m_CurrentEntry)
				{
					LOG(WARNING) << "Failed to get facial expression view with hash " << HEX(as_ped->m_Expression);
					exp_view = CategoryUtils::GetListView(g_PedExpressions, "MoodNone"_J);
				}
				auto exp_delta = ListOption("Expression",
				    exp_view.m_CurrentEntry->m_FriendlyName,
				    exp_view.m_PreviousEntry ? std::optional(exp_view.m_PreviousEntry->m_FriendlyName) : std::nullopt,
				    exp_view.m_NextEntry ? std::optional(exp_view.m_NextEntry->m_FriendlyName) : std::nullopt,
				    "Choose the facial expression for the Actor");
				if (exp_delta < 0)
					as_ped->m_Expression = exp_view.m_PreviousEntry->m_Hash;
				else if (exp_delta > 0)
					as_ped->m_Expression = exp_view.m_NextEntry->m_Hash;

				float ui_scale = as_ped->m_Scale;
				if (FloatOption("Scale", ui_scale, 0.50, 1.50, 0.02, "Adjust the scale factor for the Actor"))
				{
					as_ped->ChangeScale(ui_scale);
				}
			}
			EndSubmenu();
		}

		if (BeginSubmenu("Props"sv))
		{
			auto editing_obj = MapEditor::GetEditingEntity(MapEntity::Type::OBJECT);
			if (editing_obj)
			{
				auto sel_model_hash = editing_obj->m_ModelHash;
				bool model_updated = false;

				auto cat_view = CategoryUtils::GetCategoryView(g_ObjectCategories, sel_model_hash);

				if (!cat_view.m_CurrentEntry)
				{
					LOG(WARNING) << "Failed to get category view of object with hash " << HEX(sel_model_hash);
					sel_model_hash = "p_chickenfence01x"_J;
					cat_view = CategoryUtils::GetCategoryView(g_ObjectCategories, sel_model_hash);
				}

				auto delta = ListOption("Category",
				    cat_view.m_CurrentEntry->first,
				    cat_view.m_PreviousEntry ? std::optional(cat_view.m_PreviousEntry->first) : std::nullopt,
				    cat_view.m_NextEntry ? std::optional(cat_view.m_NextEntry->first) : std::nullopt,
				    "Sets the category from which the Prop can be chosen");

				if (delta < 0)
				{
					cat_view.m_CurrentEntry = cat_view.m_PreviousEntry; // surely there's a better way to write this
					sel_model_hash = cat_view.m_CurrentEntry->second[0].m_Hash;
					model_updated = true;
				}
				else if (delta > 0)
				{
					cat_view.m_CurrentEntry = cat_view.m_NextEntry;
					sel_model_hash = cat_view.m_CurrentEntry->second[0].m_Hash;
					model_updated = true;
				}
				
				auto list_view = CategoryUtils::GetListView(cat_view.m_CurrentEntry->second, sel_model_hash);

				auto list_delta = ListOption("Type",
				    list_view.m_CurrentEntry->m_FriendlyName,
				    list_view.m_PreviousEntry ? std::optional(list_view.m_PreviousEntry->m_FriendlyName) : std::nullopt,
				    list_view.m_NextEntry ? std::optional(list_view.m_NextEntry->m_FriendlyName) : std::nullopt,
				    "Sets the Prop's type from the chosen category");
				
				if (list_delta < 0)
				{
					sel_model_hash = list_view.m_PreviousEntry->m_Hash;
					model_updated = true;
				}
				else if (list_delta > 0)
				{
					sel_model_hash = list_view.m_NextEntry->m_Hash;
					model_updated = true;
				}

				if (model_updated)
				{
					editing_obj->ChangeModel(sel_model_hash);
				}
			}
			EndSubmenu();
		}

		if (BeginSubmenu("Vehicles"sv))
		{
			auto editing_veh = MapEditor::GetEditingEntity(MapEntity::Type::VEHICLE);
			if (editing_veh)
			{
				auto sel_model_hash = editing_veh->m_ModelHash;
				bool model_updated = false;

				auto cat_view = CategoryUtils::GetCategoryView(g_VehicleCategories, sel_model_hash);

				if (!cat_view.m_CurrentEntry)
				{
					LOG(WARNING) << "Failed to get category view of vehicle with hash " << HEX(sel_model_hash);
					sel_model_hash = "wagoncircus01x"_J;
					cat_view = CategoryUtils::GetCategoryView(g_VehicleCategories, sel_model_hash);
				}

				auto delta = ListOption("Category",
				    cat_view.m_CurrentEntry->first,
				    cat_view.m_PreviousEntry ? std::optional(cat_view.m_PreviousEntry->first) : std::nullopt,
				    cat_view.m_NextEntry ? std::optional(cat_view.m_NextEntry->first) : std::nullopt,
				    "Sets the category from which the Vehicle can be chosen");

				if (delta < 0)
				{
					cat_view.m_CurrentEntry = cat_view.m_PreviousEntry; // surely there's a better way to write this
					sel_model_hash = cat_view.m_CurrentEntry->second[0].m_Hash;
					model_updated = true;
				}
				else if (delta > 0)
				{
					cat_view.m_CurrentEntry = cat_view.m_NextEntry;
					sel_model_hash = cat_view.m_CurrentEntry->second[0].m_Hash;
					model_updated = true;
				}
				
				auto list_view = CategoryUtils::GetListView(cat_view.m_CurrentEntry->second, sel_model_hash);

				auto list_delta = ListOption("Type",
				    list_view.m_CurrentEntry->m_FriendlyName,
				    list_view.m_PreviousEntry ? std::optional(list_view.m_PreviousEntry->m_FriendlyName) : std::nullopt,
				    list_view.m_NextEntry ? std::optional(list_view.m_NextEntry->m_FriendlyName) : std::nullopt,
				    "Sets the Vehicle's type from the chosen category");
				
				if (list_delta < 0)
				{
					sel_model_hash = list_view.m_PreviousEntry->m_Hash;
					model_updated = true;
				}
				else if (list_delta > 0)
				{
					sel_model_hash = list_view.m_NextEntry->m_Hash;
					model_updated = true;
				}

				if (model_updated)
				{
					editing_veh->ChangeModel(sel_model_hash);
				}
			}
			EndSubmenu();
		}
	}

	void MapEditorMenu::Setup()
	{
		
	}

	void MapEditorMenu::Update(MapControls& controls)
	{
		if (controls.GetDpadAccept().IsPressed(MapControl::Subsystem::UI))
			EnterPressed();
		if (controls.GetDpadCancel().IsPressed(MapControl::Subsystem::UI))
			BackPressed();
		if (controls.GetDpadUp().IsPressed(MapControl::Subsystem::UI))
			UpPressed();
		if (controls.GetDpadDown().IsPressed(MapControl::Subsystem::UI))
			DownPressed();
		if (controls.GetDpadLeft().IsPressed(MapControl::Subsystem::UI))
			LeftPressed();
		if (controls.GetDpadRight().IsPressed(MapControl::Subsystem::UI))
			RightPressed();

		Render();

		// TODO: this isn't right (should trigger on regular button hovers as well)
		if (IsSubmenuButtonHovered())
			controls.GetDpadAccept().SetExclusive(MapControl::Subsystem::UI); // prevent item selection when hovering over a submenu button

		if (!GetSubmenuType(GetView().m_Submenu))
			MapEditor::ClearEditingEntity();
	}

	void MapEditorMenu::Destroy()
	{
		ExitAllSubmenus();
	}

	NativeMenu::Submenu MapEditorMenu::GetDefaultSubmenu(MapEntity::Type type)
	{
		if (auto it = sm_SubmenusByType.find(type); it != sm_SubmenusByType.end())
		{
			return it->second[0];
		}

		LOG(WARNING) << "MapEditorMenu::GetDefaultSubmenu: unknown entity type " << (int)type << " passed in. Returning main menu";
		return "Mission Creator"sv;
	}

	std::optional<MapEntity::Type> MapEditorMenu::GetSubmenuType(const Submenu& menu)
	{
		for (auto& [type, entries] : sm_SubmenusByType)
		{
			for (auto& entry : entries)
			{
				if (entry == menu)
					return type;
			}
		}

		return std::nullopt;
	}

	void MapEditorMenu::OnItemSelected(MapEntity::Type type)
	{
		auto cur_type = GetSubmenuType(GetView().m_Submenu);
		if (cur_type && *cur_type == type)
			return; // do nothing, we're already in the right submenu for our entity type

		auto default_sub = GetDefaultSubmenu(type);
		ExitAllSubmenus();
		EnterSubmenu("Placement"sv);
		EnterSubmenu(default_sub);
	}
}