#include "ColorCustomization.hpp"
#include <imgui.h>

namespace YimMenu::ColorCustomization
{
	// Default colors from Menu::SetupStyle()
	ColorCommand _MenuWindowBg("menu_window_bg", "Window Background", "Changes the window background color", ImVec4{0.13f, 0.14f, 0.15f, 1.00f});
	ColorCommand _MenuChildBg("menu_child_bg", "Panel Background", "Changes the panel background color", ImVec4{0.13f, 0.14f, 0.15f, 1.00f});
	ColorCommand _MenuTextColor("menu_text_color", "Text Color", "Changes the text color", ImVec4{1.00f, 1.00f, 1.00f, 1.00f});
	ColorCommand _MenuButtonColor("menu_button_color", "Button Color", "Changes the button color", ImVec4{0.25f, 0.25f, 0.25f, 1.00f});
	ColorCommand _MenuButtonHovered("menu_button_hovered", "Button Hovered", "Changes the button hover color", ImVec4{0.38f, 0.38f, 0.38f, 1.00f});
	ColorCommand _MenuButtonActive("menu_button_active", "Button Active", "Changes the button active color", ImVec4{0.67f, 0.67f, 0.67f, 0.39f});
	ColorCommand _MenuBorderColor("menu_border_color", "Border Color", "Changes the border color", ImVec4{0.43f, 0.43f, 0.50f, 0.50f});

	void ApplyMenuColors()
	{
		auto& style = ImGui::GetStyle();
		style.Colors[ImGuiCol_WindowBg] = _MenuWindowBg.GetState();
		style.Colors[ImGuiCol_ChildBg] = _MenuChildBg.GetState();
		style.Colors[ImGuiCol_Text] = _MenuTextColor.GetState();
		style.Colors[ImGuiCol_Button] = _MenuButtonColor.GetState();
		style.Colors[ImGuiCol_ButtonHovered] = _MenuButtonHovered.GetState();
		style.Colors[ImGuiCol_ButtonActive] = _MenuButtonActive.GetState();
		style.Colors[ImGuiCol_Border] = _MenuBorderColor.GetState();
	}

	void ResetToDefaultColors()
	{
		_MenuWindowBg.SetState(ImVec4{0.13f, 0.14f, 0.15f, 1.00f});
		_MenuChildBg.SetState(ImVec4{0.13f, 0.14f, 0.15f, 1.00f});
		_MenuTextColor.SetState(ImVec4{1.00f, 1.00f, 1.00f, 1.00f});
		_MenuButtonColor.SetState(ImVec4{0.25f, 0.25f, 0.25f, 1.00f});
		_MenuButtonHovered.SetState(ImVec4{0.38f, 0.38f, 0.38f, 1.00f});
		_MenuButtonActive.SetState(ImVec4{0.67f, 0.67f, 0.67f, 0.39f});
		_MenuBorderColor.SetState(ImVec4{0.43f, 0.43f, 0.50f, 0.50f});
	}

	void DrawColorSettings()
	{
		if (ImGui::Button("Reset to Default Colors", ImVec2(-1, 0)))
		{
			ResetToDefaultColors();
		}

		// Create two columns with headers at the same level
		ImGui::Columns(2, "ColorColumns", false);

		// Left column header
		ImGui::Text("Window & Background");

		ImVec4 windowBg = _MenuWindowBg.GetState();
		if (ImGui::ColorEdit4("Window Background", &windowBg.x, ImGuiColorEditFlags_NoInputs))
			_MenuWindowBg.SetState(windowBg);

		ImVec4 childBg = _MenuChildBg.GetState();
		if (ImGui::ColorEdit4("Panel Background", &childBg.x, ImGuiColorEditFlags_NoInputs))
			_MenuChildBg.SetState(childBg);

		ImVec4 textColor = _MenuTextColor.GetState();
		if (ImGui::ColorEdit4("Text Color", &textColor.x, ImGuiColorEditFlags_NoInputs))
			_MenuTextColor.SetState(textColor);

		ImVec4 borderColor = _MenuBorderColor.GetState();
		if (ImGui::ColorEdit4("Border Color", &borderColor.x, ImGuiColorEditFlags_NoInputs))
			_MenuBorderColor.SetState(borderColor);

		// Move to right column
		ImGui::NextColumn();

		// Right column header - this will be at the same level as left header
		ImGui::Text("Button Colors");

		ImVec4 buttonColor = _MenuButtonColor.GetState();
		if (ImGui::ColorEdit4("Button Normal", &buttonColor.x, ImGuiColorEditFlags_NoInputs))
			_MenuButtonColor.SetState(buttonColor);

		ImVec4 buttonHovered = _MenuButtonHovered.GetState();
		if (ImGui::ColorEdit4("Button Hover", &buttonHovered.x, ImGuiColorEditFlags_NoInputs))
			_MenuButtonHovered.SetState(buttonHovered);

		ImVec4 buttonActive = _MenuButtonActive.GetState();
		if (ImGui::ColorEdit4("Button Active", &buttonActive.x, ImGuiColorEditFlags_NoInputs))
			_MenuButtonActive.SetState(buttonActive);

		ImGui::Columns(1); // Reset to single column
	}
}