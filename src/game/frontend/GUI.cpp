#include "GUI.hpp"

#include "core/renderer/Renderer.hpp"
#include "game/services/notification_service/NotificationService.hpp"
#include "menu/Menu.hpp"

namespace YimMenu
{
	GUI::GUI() :
	    m_IsOpen(false)
	{
		Menu::Fonts();
		Menu::Style();
		Menu::Init();

		Renderer::AddWindowProcedureCallback([this](HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
			GUI::WndProc(hwnd, msg, wparam, lparam);
		});

		Renderer::AddRendererCallBack(
		    [&] {
			    g_NotificationService.DrawTick();
		    },
		    -2);
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
			//Persist and restore the cursor position between menu instances.
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