#include "game/frontend/menu/Menu.hpp"
#include "game/frontend/fonts/Fonts.hpp"

#include "core/renderer/Renderer.hpp"
#include "game/frontend/menu/self/Self.hpp"
#include "game/frontend/menu/settings/Settings.hpp"


namespace YimMenu
{
	void Menu::Init()
	{
		static auto SelfSubmenu = std::make_shared<Self>();
		SelfSubmenu->LoadSubmenus(); //Loads mini submenus into memory.

		static auto SettingsSubmenu = std::make_shared<Settings>();
		SettingsSubmenu->LoadSubmenus(); //Loads mini submenus into memory.

		Renderer::AddRendererCallBack(
		    [&] {
			      ImGui::PushFont(Menu::Font::m_DefaultFont);

			    if (!GUI::IsOpen())
				    return;

			    //Think this add HTML&PHP with no CSS. Lol just for testing.

		
				ImGui::PushStyleColor(ImGuiCol_WindowBg, ImU32(ImColor(15, 15, 15)));
			    ImGui::SetNextWindowSize(ImVec2(610, 610 /*add auto resize*/), ImGuiCond_Once);
			    if (ImGui::Begin("HorseMenu", nullptr, ImGuiWindowFlags_NoDecoration))
			    {
				    const auto& Pos = ImGui::GetCursorPos();

				    if (ImGui::Button("Unload", ImVec2(120, 0)))
					    g_Running = false;

				    if (!g_SubmenuHandler.GetActiveSubmenu())
					    g_SubmenuHandler.SetActiveSubmenu(SelfSubmenu);

				    if (ImGui::BeginChild("##submenus", ImVec2(120, ImGui::GetContentRegionAvail().y - 20), true))
				    {
					    //Arguably the only place this file should be edited at for more menus

					    g_SubmenuHandler.SubmenuOption("L" /*Logo Font*/, "Self", SelfSubmenu); //Ideally with the logo you'd have them squares that fit perfectly.
					    g_SubmenuHandler.SubmenuOption("L" /*Logo Font*/, "Settings", SettingsSubmenu);
				    }
				    ImGui::EndChild(); //Good practice to call endchild after the brackets

					ImGui::Text("HorseMenu");

				    ImGui::SetCursorPos(ImVec2(Pos.x + 130, Pos.y));

				    if (ImGui::BeginChild("##minisubmenus", ImVec2(0, 50), true, ImGuiWindowFlags_NoScrollbar))
				    {
					    g_SubmenuHandler.RenderSubmenuCategories();
				    }
				    ImGui::EndChild();

				    ImGui::SetCursorPos(ImVec2(Pos.x + 130, Pos.y + 60));

				    if (ImGui::BeginChild("##options", ImVec2(0, 0), true))
				    {
					    ImGui::PushFont(Menu::Font::m_OptionsFont);

					    auto ActiveSubmenu = g_SubmenuHandler.GetActiveSubmenu();

					    if (ActiveSubmenu && g_SubmenuHandler.GetActiveSubmenuDefaultMiniSubmenu() && !g_SubmenuHandler.GetActiveSubmenuActiveMiniSubmenu())
						    ActiveSubmenu.get()->SetActiveMiniSubmenu(ActiveSubmenu.get()->m_DefaultMiniSubmenu);

					    g_SubmenuHandler.RenderActiveSubmenu();

						ImGui::PopFont();
				    }
				    ImGui::EndChild();

				    ImGui::End();
			    }
			    ImGui::PopStyleColor();

				ImGui::PopFont();
		    },
		    -1);
	}

	void Menu::Style()
	{
		ImGuiStyle& style                            = ImGui::GetStyle();
		style.Colors[ImGuiCol_Text]                  = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
		style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
		style.Colors[ImGuiCol_ChildBg]               = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
		style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
		style.Colors[ImGuiCol_Border]                = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
		style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
		style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
		style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
		style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
		style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
		style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
		style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
		style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
		style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
		style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
		style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
		style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.08f, 0.50f, 0.72f, 1.00f);
		style.Colors[ImGuiCol_Button]                = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
		style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
		style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
		style.Colors[ImGuiCol_Header]                = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
		style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
		style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
		style.Colors[ImGuiCol_Separator]             = style.Colors[ImGuiCol_Border];
		style.Colors[ImGuiCol_SeparatorHovered]      = ImVec4(0.41f, 0.42f, 0.44f, 1.00f);
		style.Colors[ImGuiCol_SeparatorActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
		style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.29f, 0.30f, 0.31f, 0.67f);
		style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
		style.Colors[ImGuiCol_Tab]                   = ImVec4(0.08f, 0.08f, 0.09f, 0.83f);
		style.Colors[ImGuiCol_TabHovered]            = ImVec4(0.33f, 0.34f, 0.36f, 0.83f);
		style.Colors[ImGuiCol_TabActive]             = ImVec4(0.23f, 0.23f, 0.24f, 1.00f);
		style.Colors[ImGuiCol_TabUnfocused]          = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
		style.Colors[ImGuiCol_TabUnfocusedActive]    = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
		style.Colors[ImGuiCol_PlotLines]             = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
		style.Colors[ImGuiCol_DragDropTarget]        = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
		style.Colors[ImGuiCol_NavHighlight]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		style.Colors[ImGuiCol_NavWindowingDimBg]     = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		style.Colors[ImGuiCol_ModalWindowDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
		style.GrabRounding = style.FrameRounding =  style.ChildRounding = style.WindowRounding =  2.3f;
	}

	void Menu::Fonts()
	{
		auto& IO = ImGui::GetIO();
		ImFontConfig FontCfg{};
		FontCfg.FontDataOwnedByAtlas  = false;

		Menu::Font::m_DefaultFont = IO.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Fonts::MainFont), sizeof(Fonts::MainFont), Menu::Font::m_DefaultFontSize, &FontCfg);
		Menu::Font::m_OptionsFont = IO.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Fonts::MainFont), sizeof(Fonts::MainFont), Menu::Font::m_OptionsFontSize, &FontCfg);
		Menu::Font::m_ChildTitleFont = IO.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Fonts::MainFont), sizeof(Fonts::MainFont), Menu::Font::m_ChildTitleFontSize, &FontCfg);
	}
}