#include "GUI.hpp"
#include "Menu.hpp"
#include "ESP.hpp"
#include "ContextMenu.hpp"
#include "Overlay.hpp"
#include "core/renderer/Renderer.hpp"
#include "core/frontend/Notifications.hpp"
#include "game/frontend/ChatDisplay.hpp"

namespace YimMenu
{
	GUI::GUI() :
	    m_IsOpen(false)
	{
		Menu::SetupFonts();
		Menu::SetupStyle();
		Menu::Init();

		Renderer::AddWindowProcedureCallback([this](HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
			GUI::WndProc(hwnd, msg, wparam, lparam);
		});

		Renderer::AddRendererCallBack(
		    [&] {
			    Notifications::Draw();
		    },
		    -2);
		Renderer::AddRendererCallBack(
		    [&] {
			    ESP::Draw();
		    },
		    -3);

		Renderer::AddRendererCallBack(
		    [&] {
			    ContextMenu::DrawContextMenu();
		    },
		    -4);
		Renderer::AddRendererCallBack(
		    [&] {
			    ChatDisplay::Draw();
		    },
		    -5);
		Renderer::AddRendererCallBack(
		    [&] {
			    Overlay::Draw();
		    },
		    -6);
	}

	GUI::~GUI()
	{
	}

	void GUI::ToggleMouse()
	{
		auto& io           = ImGui::GetIO();
		io.MouseDrawCursor = GUI::IsOpen();
		GUI::IsOpen() ? io.ConfigFlags &= ~ImGuiConfigFlags_NoMouse : io.ConfigFlags |= ImGuiConfigFlags_NoMouse;
	}

	void GUI::WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		if (msg == WM_KEYUP && wparam == VK_INSERT)
		{
			// Persist and restore the cursor position between menu instances
			static POINT CursorCoords{};
			if (m_IsOpen)
			{
				GetCursorPos(&CursorCoords);
			}
			else if (CursorCoords.x + CursorCoords.y)
			{
				SetCursorPos(CursorCoords.x, CursorCoords.y);
			}
			Toggle();
			ToggleMouse();
		}
	}
}