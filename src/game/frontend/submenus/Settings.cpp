#include "settings.hpp"

#include "core/commands/Commands.hpp"
#include "core/commands/HotkeySystem.hpp"
#include "core/commands/LoopedCommand.hpp"
#include "game/backend/Self.hpp"
#include "game/features/Features.hpp"
#include "game/frontend/items/Items.hpp"
#include "game/frontend/Menu.hpp"
#include "Lua/LuaMgr.hpp"


namespace
{
	using namespace Terminus::LuaJIT;

	static std::shared_ptr<LuaModule> selectedModule{nullptr};
	static std::shared_ptr<LuaModule> dragSourcePtr{nullptr};
	static std::string selectedDisabledPath{};
	static std::string dragSourceStr{};

	static bool shouldDrawProperties = false;

	static void DrawLuaScripts()
	{
		auto& modules         = LuaManager::GetModules();
		auto& disabledModules = LuaManager::GetDisabledModules();

		if (ImGui::Button("Reload All"))
			LuaManager::ReloadAllModules();
		ImGui::Spacing();

		auto region = ImGui::GetContentRegionAvail();

		ImGui::BeginChild("##enabledScripts", ImVec2(region.x * 0.5, 0), ImGuiChildFlags_Borders);
		ImGui::Text("Enabled Scripts");
		ImGui::Separator();

		for (auto& m : modules)
		{
			auto pathName = m->GetRoot().string();

			ImGui::PushID(&m);
			ImGui::BeginDisabled(dragSourcePtr && m == dragSourcePtr);
			bool isBroken = m->GetLoadState() == LuaModule::SUSPENDED;

			if (isBroken)
			{
				ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.9, 0, 0, 1.0));
				ImGui::PushStyleColor(ImGuiCol_TextDisabled, ImVec4(0.9, 0, 0, 0.5));
			}
			ImGui::Selectable(m->GetName().data(), (selectedModule && m == selectedModule));

			if (isBroken && ImGui::IsItemHovered())
			{
				ImGui::PopStyleColor(2);
				std::string err = m->GetErrorMsg();
				ImGui::SetTooltip(
				    std::format("Unloaded due to a malfunction: '{}'", err.empty() ? "Unknown error." : err).c_str());
			}

			ImGui::EndDisabled();
			ImGui::PopID();
			if (ImGui::IsItemHovered())
				ImGui::SetTooltip("Right click to open the context menu or drag to move to the disabled list.");

			if (ImGui::IsItemClicked(ImGuiMouseButton_Right))
			{
				selectedModule = m;
				ImGui::OpenPopup(pathName.c_str());
			}

			if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_SourceAllowNullID))
			{
				dragSourcePtr = m;
				ImGui::SetDragDropPayload("ENABLED_MODULE", &m, sizeof(m));
				ImGui::Selectable(m->GetName().data(), true);
				ImGui::SetMouseCursor(ImGuiMouseCursor_Hand);
				ImGui::EndDragDropSource();
			}
			else
				dragSourcePtr = nullptr;

			if (ImGui::BeginPopup(pathName.c_str()))
			{
				if (ImGui::MenuItem("Reload"))
					m->Reload();

				if (ImGui::MenuItem("Disable"))
					m->Disable();

				if (ImGui::MenuItem("Properties"))
					shouldDrawProperties = true;

				ImGui::EndPopup();
			}
		}
		ImGui::EndChild();

		if (shouldDrawProperties && selectedModule)
		{
			shouldDrawProperties = false;
			ImGui::OpenPopup(selectedModule->GetName().data());
		}

		bool isOpen = true;
		ImGui::SetNextWindowSizeConstraints(ImVec2(200, 100), ImVec2(400, 800));
		if (selectedModule && ImGui::BeginPopupModal(selectedModule->GetName().data(), &isOpen, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_AlwaysAutoResize))
		{
			if (ImGui::BeginTable("##scriptInfo", 2, ImGuiTableFlags_BordersOuter | ImGuiTableFlags_BordersInner | ImGuiTableFlags_RowBg))
			{
				auto meta = selectedModule->GetMetadata();
				ImGui::TableSetupColumn("#k", ImGuiTableColumnFlags_WidthFixed);
				ImGui::TableSetupColumn("#v", ImGuiTableColumnFlags_WidthStretch);
				ImGui::PushFont(Terminus::Menu::Font::g_OptionsFont);

				ImGui::TableNextRow();
				ImGui::TableSetColumnIndex(0);
				ImGui::Text("Author");
				ImGui::TableSetColumnIndex(1);
				ImGui::TextWrapped(meta.m_Author.c_str());

				ImGui::TableNextRow();
				ImGui::TableSetColumnIndex(0);
				ImGui::Text("Version");
				ImGui::TableSetColumnIndex(1);
				ImGui::TextWrapped(meta.m_Version.c_str());

				ImGui::TableNextRow();
				ImGui::TableSetColumnIndex(0);
				ImGui::Text("Description");
				ImGui::TableSetColumnIndex(1);
				ImGui::TextWrapped(meta.m_Description.c_str());

				ImGui::PopFont();
				ImGui::EndTable();
			}
			ImGui::EndPopup();
		}

		if (ImGui::BeginDragDropTarget())
		{
			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("DISABLED_MODULE"))
			{
				const char* droppedPath = static_cast<const char*>(payload->Data);
				LuaManager::EnableModule(droppedPath);
				dragSourceStr = "";
			}
			ImGui::EndDragDropTarget();
		}

		ImGui::SameLine();
		ImGui::BeginChild("##disabledScripts", ImVec2(), ImGuiChildFlags_Borders);
		ImGui::Text("Disabled Scripts");
		ImGui::Separator();
		for (auto& m : disabledModules)
		{
			auto pathName = m.m_Path.string();

			ImGui::PushID(&m);
			ImGui::BeginDisabled(pathName == dragSourceStr);
			if (ImGui::Selectable(m.m_Name.c_str(), pathName == selectedDisabledPath))
				selectedDisabledPath = pathName;
			ImGui::EndDisabled();
			ImGui::PopID();
			if (ImGui::IsItemHovered())
				ImGui::SetTooltip("Right click to open the context menu or drag to move to the enabled modules list.");

			if (ImGui::IsItemClicked(ImGuiMouseButton_Right))
			{
				selectedDisabledPath = pathName;
				ImGui::OpenPopup(pathName.c_str());
			}

			if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_SourceAllowNullID))
			{
				dragSourceStr = pathName;
				ImGui::SetDragDropPayload("DISABLED_MODULE", pathName.c_str(), pathName.size() + 1);
				ImGui::Selectable(m.m_Name.c_str(), true);
				ImGui::EndDragDropSource();
			}
			else
				dragSourceStr = "";

			if (ImGui::BeginPopup(pathName.c_str()))
			{
				if (ImGui::MenuItem("Enable"))
					LuaManager::EnableModule(pathName);

				ImGui::EndPopup();
			}
		}
		ImGui::EndChild();
		if (ImGui::BeginDragDropTarget())
		{
			if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("ENABLED_MODULE"))
			{
				LuaModule* droppedModule = *static_cast<LuaModule**>(payload->Data);
				droppedModule->Disable();
				dragSourcePtr = nullptr;
			}
			ImGui::EndDragDropTarget();
		}
	}
}

namespace Terminus::Submenus
{
	// TODO: refactor this
	static void Hotkeys()
	{
		ImGui::BulletText("Hold the command name clicked to change its hotkey");
		ImGui::BulletText("Press any registered key to remove");

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		for (auto& [Hash, Command] : Commands::GetCommands())
		{
			ImGui::PushID(Hash);

			if (g_HotkeySystem.m_CommandHotkeys.find(Hash) != g_HotkeySystem.m_CommandHotkeys.end())
				HotkeySetter(Hash).Draw();

			ImGui::Spacing();

			ImGui::PopID();
		}
	};

	Settings::Settings() :
	    Submenu::Submenu("Settings")
	{
		auto hotkeys           = std::make_shared<Category>("Hotkeys");
		auto gui               = std::make_shared<Category>("GUI");
		auto protections       = std::make_shared<Category>("Protection");
		auto luaScripts        = std::make_shared<Category>("Lua Scripts");

		auto syncGroup         = std::make_shared<Group>("Sync");
		auto networkEventGroup = std::make_shared<Group>("Network Events");
		auto scriptEventGroup  = std::make_shared<Group>("Script Events");
		auto playerEsp         = std::make_shared<Group>("Player ESP", 10);
		auto pedEsp            = std::make_shared<Group>("Ped ESP", 10);
		auto overlay           = std::make_shared<Group>("Overlay");
		auto context           = std::make_shared<Group>("Context Menu");
		auto misc              = std::make_shared<Group>("Misc");

		hotkeys->AddItem(std::make_shared<ImGuiItem>(Hotkeys));
		luaScripts->AddItem(std::make_shared<ImGuiItem>(DrawLuaScripts));

		// Players
		playerEsp->AddItem(std::make_shared<BoolCommandItem>("espdrawplayers"_J));
		playerEsp->AddItem(std::make_shared<ConditionalItem>("espdrawplayers"_J, std::make_shared<BoolCommandItem>("espdrawdeadplayers"_J)));

		playerEsp->AddItem(std::make_shared<ConditionalItem>("espdrawplayers"_J, std::make_shared<BoolCommandItem>("espnameplayers"_J, "Player Name")));
		playerEsp->AddItem(std::make_shared<ConditionalItem>("espdrawplayers"_J, std::make_shared<ColorCommandItem>("namecolorplayers"_J)));

		playerEsp->AddItem(std::make_shared<ConditionalItem>("espdrawplayers"_J, std::make_shared<BoolCommandItem>("espdistanceplayers"_J, "Player Distance")));
		//playerEsp->AddItem(std::make_shared<ConditionalItem>("espdrawplayers"_J, std::make_shared<ColorCommandItem>("distancecolorplayers"_J))); // TO DO

		playerEsp->AddItem(std::make_shared<ConditionalItem>("espdrawplayers"_J, std::make_shared<BoolCommandItem>("espskeletonplayers"_J, "Player Skeleton")));
		playerEsp->AddItem(std::make_shared<ConditionalItem>("espdrawplayers"_J, std::make_shared<ColorCommandItem>("skeletoncolorplayers"_J)));

		// Peds
		pedEsp->AddItem(std::make_shared<BoolCommandItem>("espdrawpeds"_J));
		pedEsp->AddItem(std::make_shared<ConditionalItem>("espdrawpeds"_J, std::make_shared<BoolCommandItem>("espdrawdeadpeds"_J)));

		pedEsp->AddItem(std::make_shared<ConditionalItem>("espdrawpeds"_J, std::make_shared<BoolCommandItem>("espmodelspeds"_J, "Ped Hashes")));
		pedEsp->AddItem(std::make_shared<ConditionalItem>("espdrawpeds"_J, std::make_shared<ColorCommandItem>("hashcolorpeds"_J)));

		pedEsp->AddItem(std::make_shared<ConditionalItem>("espdrawpeds"_J, std::make_shared<BoolCommandItem>("espnetinfopeds"_J, "Ped Net Info")));
		pedEsp->AddItem(std::make_shared<ConditionalItem>("espdrawpeds"_J, std::make_shared<BoolCommandItem>("espscriptinfopeds"_J, "Ped Script Info")));

		pedEsp->AddItem(std::make_shared<ConditionalItem>("espdrawpeds"_J, std::make_shared<BoolCommandItem>("espdistancepeds"_J, "Ped Distance")));
		//pedEsp->AddItem(std::make_shared<ConditionalItem>("espdrawpeds"_J, std::make_shared<ColorCommandItem>("distancecolorpeds"_J))); // TO DO

		pedEsp->AddItem(std::make_shared<ConditionalItem>("espdrawpeds"_J, std::make_shared<BoolCommandItem>("espskeletonpeds"_J, "Ped Skeleton")));
		pedEsp->AddItem(std::make_shared<ConditionalItem>("espdrawpeds"_J, std::make_shared<ColorCommandItem>("skeletoncolorpeds"_J)));

		pedEsp->AddItem(std::make_shared<ConditionalItem>("espdrawpeds"_J, std::make_shared<BoolCommandItem>("espskeletonhorse"_J, "Horse Skeleton")));
		pedEsp->AddItem(std::make_shared<ConditionalItem>("espdrawpeds"_J, std::make_shared<ColorCommandItem>("skeletoncolorhorse"_J)));

		overlay->AddItem(std::make_shared<BoolCommandItem>("overlay"_J));
		overlay->AddItem(std::make_shared<ConditionalItem>("overlay"_J, std::make_shared<BoolCommandItem>("overlayfps"_J)));

		context->AddItem(std::make_shared<BoolCommandItem>("ctxmenu"_J));
		context->AddItem(std::make_shared<ConditionalItem>("ctxmenu"_J, std::make_shared<BoolCommandItem>("ctxmenuplayers"_J, "Players")));
		context->AddItem(std::make_shared<ConditionalItem>("ctxmenu"_J, std::make_shared<BoolCommandItem>("ctxmenupeds"_J, "Peds")));
		context->AddItem(std::make_shared<ConditionalItem>("ctxmenu"_J, std::make_shared<BoolCommandItem>("ctxmenuvehicles"_J, "Vehicles")));
		context->AddItem(std::make_shared<ConditionalItem>("ctxmenu"_J, std::make_shared<BoolCommandItem>("ctxmenuobjects"_J, "Objects")));

		syncGroup->AddItem(std::make_shared<BoolCommandItem>("blockspectate"_J));
		syncGroup->AddItem(std::make_shared<BoolCommandItem>("blockspectatesession"_J));
		syncGroup->AddItem(std::make_shared<BoolCommandItem>("blockattach"_J));
		syncGroup->AddItem(std::make_shared<BoolCommandItem>("blockvehflood"_J));

		networkEventGroup->AddItem(std::make_shared<BoolCommandItem>("blockexplosions"_J));
		networkEventGroup->AddItem(std::make_shared<BoolCommandItem>("blockptfx"_J));
		networkEventGroup->AddItem(std::make_shared<BoolCommandItem>("blockclearpedtasks"_J));
		networkEventGroup->AddItem(std::make_shared<BoolCommandItem>("blockscriptcommand"_J));
		networkEventGroup->AddItem(std::make_shared<BoolCommandItem>("userelaycxns"_J));

		scriptEventGroup->AddItem(std::make_shared<BoolCommandItem>("blockhonormanipulation"_J));
		scriptEventGroup->AddItem(std::make_shared<BoolCommandItem>("blockdefensive"_J));
		scriptEventGroup->AddItem(std::make_shared<BoolCommandItem>("blockoffensive"_J));
		scriptEventGroup->AddItem(std::make_shared<BoolCommandItem>("blockpresscharges"_J));
		scriptEventGroup->AddItem(std::make_shared<BoolCommandItem>("blockstartparlay"_J));
		scriptEventGroup->AddItem(std::make_shared<BoolCommandItem>("blockendparlay"_J));
		scriptEventGroup->AddItem(std::make_shared<BoolCommandItem>("blocktickerspam"_J));
		scriptEventGroup->AddItem(std::make_shared<BoolCommandItem>("blockstableevents"_J));
		scriptEventGroup->AddItem(std::make_shared<BoolCommandItem>("blockkickfrommissionlobby"_J));

		gui->AddItem(playerEsp);
		gui->AddItem(pedEsp);
		gui->AddItem(overlay);
		gui->AddItem(context);
		gui->AddItem(misc);

		protections->AddItem(syncGroup);
		protections->AddItem(networkEventGroup);
		protections->AddItem(scriptEventGroup);

		AddCategory(std::move(hotkeys));
		AddCategory(std::move(gui));
		AddCategory(std::move(protections));
		AddCategory(std::move(luaScripts));
	}
}
