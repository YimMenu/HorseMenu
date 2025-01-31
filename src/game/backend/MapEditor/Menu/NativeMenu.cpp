#include "NativeMenu.hpp"
#include "NativeDrawing.hpp"

namespace YimMenu
{
	constexpr float HEADER_WIDTH  = 0.225f;
	constexpr float HEADER_HEIGHT = 0.105f;
	constexpr float SUBHEADER_HEIGHT = 0.034722f;
	constexpr float SUBHEADER_TEXT_WIDTH_COEFFICIENT = 57.6f;
	constexpr float SUBHEADER_TEXT_HEIGHT_COEFFICIENT = 8.3333f;
	constexpr float OPTION_HEIGHT = SUBHEADER_HEIGHT;

	static void DrawSubHeader(float x, float y, std::string_view text)
	{
		std::string caps_text(text);
		std::transform(caps_text.begin(), caps_text.end(), caps_text.begin(), ::toupper);
		caps_text.append("<skibidi>");
		NativeUI::DrawRect(x, y, HEADER_WIDTH, SUBHEADER_HEIGHT, ImGui::Colors::Black);
		NativeUI::DrawTextAt(caps_text, x + (HEADER_WIDTH / SUBHEADER_TEXT_WIDTH_COEFFICIENT), y + (SUBHEADER_HEIGHT / SUBHEADER_TEXT_HEIGHT_COEFFICIENT), ImGui::Colors::White, 25, NativeUI::Font::ARIAL);
	}

	void NativeMenu::UpdateInputs()
	{
		if (std::chrono::system_clock::now() < m_NextInputTime)
		{
			ClearInputs();
			return;
		}

		if (m_EnterPressed || m_BackPressed || m_UpPressed || m_DownPressed || m_LeftPressed || m_RightPressed)
		{
			m_NextInputTime = std::chrono::system_clock::now() + 120ms;

			if (m_EnterPressed)
			{
				NativeUI::PlaySoundFrontend("HUD_PLAYER_MENU", "SELECT");
				HandleItemPress();
			}
			else if (m_BackPressed)
			{
				NativeUI::PlaySoundFrontend("HUD_PLAYER_MENU", "BACK");
				HandleBackPress();
			}
			else
			{
				if (m_UpPressed)
				{
					NativeUI::PlaySoundFrontend("HUD_PLAYER_MENU", "NAV_UP");
					m_View.m_Item--;
					UpdateScreenPositioning();
				}

				if (m_DownPressed)
				{
					NativeUI::PlaySoundFrontend("HUD_PLAYER_MENU", "NAV_DOWN");
					m_View.m_Item++;
					UpdateScreenPositioning();
				}

				if (m_LeftPressed)
				{
					NativeUI::PlaySoundFrontend("HUD_PLAYER_MENU", "NAV_LEFT");
					m_ItemDelta = -1;
					InvalidateMaxItems(); // we invalidate this on input because say the model switcher may add additional fields etc.
				}

				if (m_RightPressed)
				{
					NativeUI::PlaySoundFrontend("HUD_PLAYER_MENU", "NAV_RIGHT");
					m_ItemDelta = 1;
					InvalidateMaxItems();
				}
			}
		}

		ClearInputs();
	}

	void NativeMenu::ClearInputs()
	{
		m_EnterPressed = false;
		m_BackPressed  = false;
		m_UpPressed    = false;
		m_DownPressed  = false;
		m_LeftPressed  = false;
		m_RightPressed = false;
	}

	void NativeMenu::HandleItemPress()
	{
		if (m_HoveredOverSubmenu)
		{
			PushSubmenu(*m_HoveredOverSubmenu);
		}
		else
		{
			m_ItemClicked = true;
		}

		InvalidateMaxItems();
	}

	void NativeMenu::PushSubmenu(const Submenu& menu)
	{
		m_SubmenuStack.push(m_View);
		m_View.m_Submenu = menu;
		m_View.m_Item = 0;
		m_View.m_Screen = 0;
		m_SubmenuDataJustUpdated = true;
	}

	void NativeMenu::PopSubmenu()
	{
		if (!m_SubmenuStack.empty())
		{
			m_View = m_SubmenuStack.top();
			m_SubmenuStack.pop();
			InvalidateMaxItems();
			UpdateScreenPositioning();
		}
	}

	void NativeMenu::HandleBackPress()
	{
		PopSubmenu();
	}

	void NativeMenu::UpdateScreenPositioning()
	{
		if (m_View.m_Item < 0)
			m_View.m_Item = GetMaxItems() - 1;
		if (m_View.m_Item >= GetMaxItems())
			m_View.m_Item = 0;
		if (m_View.m_Item >= m_View.m_Screen + m_ItemsOnScreen || m_View.m_Item < m_View.m_Screen)
			m_View.m_Screen = m_View.m_Item;
	}

	int NativeMenu::GetMaxItems()
	{
		if (m_CachedMaxItems)
			return *m_CachedMaxItems; // reuse cached value to avoid calling UpdateView twice every time
		else
		{
			ClearVariablesPreRun();
			m_DryRun = true;
			UpdateView();
			m_DryRun = false;
			ClearVariablesPostRun();
			m_CachedMaxItems = m_RunningMaxItems;
			return *m_CachedMaxItems;
		}
	}

	void NativeMenu::InvalidateMaxItems()
	{
		m_CachedMaxItems = std::nullopt;
	}

	void NativeMenu::ClearVariablesPreRun()
	{
		m_CurrentHelpText = "";
		m_HoveredOverSubmenu = std::nullopt;
		m_RunningMaxItems = 0;
		m_Disabled = false;
	}

	void NativeMenu::ClearVariablesPostRun()
	{
		m_ItemClicked = false;
		m_ItemDelta = 0;
		m_CurPosDef = 0;
		m_SubmenuDataJustUpdated = false;
	}

	bool NativeMenu::IsItemSelected() const
	{
		return m_CurPosDef == m_View.m_Item && !m_Disabled;
	}

	bool NativeMenu::ShouldRenderItem() const
	{
		if (m_DryRun)
			return false;

		if (m_CurPosDef < m_View.m_Screen || m_CurPosDef >= m_View.m_Screen + m_ItemsOnScreen)
			return false;
		
		return true;
	}

	void NativeMenu::DrawOption(std::string_view left, std::string_view right)
	{
		if (!ShouldRenderItem())
			return;

		bool selected = m_CurPosDef == m_View.m_Item;
		auto text_color = m_Disabled ? ImGui::Colors::DisabledText : (selected ? ImGui::Colors::Black : ImGui::Colors::White);
		auto background_color = selected ? ImGui::Colors::White : ImGui::Colors::IngameBg; // TODO: port GTA's CommonMenu gradient bg

		NativeUI::DrawRect(m_MenuX, m_CurrentY, HEADER_WIDTH, OPTION_HEIGHT, background_color);
		NativeUI::DrawTextAt(left, m_MenuX + (HEADER_WIDTH / SUBHEADER_TEXT_WIDTH_COEFFICIENT), m_CurrentY + (SUBHEADER_HEIGHT / SUBHEADER_TEXT_HEIGHT_COEFFICIENT), text_color, 25, NativeUI::Font::ARIAL);

		if (!right.empty())
			NativeUI::DrawTextAt(right, m_MenuX + (HEADER_WIDTH * 0.982638f), m_CurrentY + (SUBHEADER_HEIGHT / SUBHEADER_TEXT_HEIGHT_COEFFICIENT), text_color, 25, NativeUI::Font::ARIAL, NativeUI::Alignment::RIGHT);

		m_CurrentY += OPTION_HEIGHT;
	}

	void NativeMenu::NextOption(std::string_view help_text)
	{
		if (IsItemSelected())
			m_CurrentHelpText = help_text;
		m_CurPosDef++;
		m_RunningMaxItems++;
		if (m_Disabled)
			m_ItemsDisabled++;
	}

	NativeMenu::NativeMenu(std::string_view name, float x, float y, const Submenu& initial_submenu, std::uint32_t num_items_on_screen) :
	    m_MenuName(name),
	    m_MenuX(x),
	    m_MenuY(y),
	    m_ItemsOnScreen(num_items_on_screen),
	    m_InitialSubmenu(initial_submenu)
	{
		m_View.m_Submenu = m_InitialSubmenu;
	}

	void NativeMenu::Render()
	{
		UpdateInputs();

		NativeUI::DisableBountyBoard();

		// begin rendering by setting cursor to menu start pos
		m_CurrentY = m_MenuY;

		// header
		NativeUI::DrawLargeHeader(m_MenuX, m_MenuY, HEADER_WIDTH, HEADER_HEIGHT, m_MenuName, ImGui::Colors::Freemode, ImGui::Colors::White); m_CurrentY += HEADER_HEIGHT;
		DrawSubHeader(m_MenuX, m_CurrentY, m_View.m_Submenu.m_Name); m_CurrentY += SUBHEADER_HEIGHT;

		// content
		ClearVariablesPreRun();
		UpdateView();
		ClearVariablesPostRun();

		// end
		
		// TODO: the help text cannot be drawn due to fundamental game engine restrictions
		// since it is impossible to get the wrapped line count of a text command
		// and all infrastructure to implement that manually have also been removed from RDR
		// if we really want some help text, it would not be able to wrap, i.e. it has to be under 40 characters
	}

	bool NativeMenu::BeginSubmenu(const Submenu& submenu)
	{
		return m_View.m_Submenu == submenu;
	}

	void NativeMenu::EndSubmenu()
	{
	}

	void NativeMenu::BeginDisabled(bool should_disable, std::string_view why)
	{
		if (m_Disabled || !should_disable)
			return;

		m_DisabledReason = why;
		m_Disabled = true;
		m_ItemsDisabled = 0;
	}

	void NativeMenu::EndDisabled()
	{
		if (!m_Disabled)
			return;

		if (m_View.m_Item < m_CurPosDef && m_View.m_Item >= m_CurPosDef - m_ItemsDisabled)
			m_CurrentHelpText = m_DisabledReason;
		m_Disabled = false;
	}

	bool NativeMenu::Button(std::string_view text, std::string_view help_text)
	{
		bool clicked = IsItemSelected() && m_ItemClicked;
		DrawOption(text);
		NextOption(help_text);
		return clicked;
	}

	void NativeMenu::SubmenuButton(std::string_view text, const Submenu& submenu, std::string_view help_text)
	{		
		if (IsItemSelected())
			m_HoveredOverSubmenu = submenu;
		DrawOption(text);
		NextOption(help_text);
	}

	bool NativeMenu::Checkbox(std::string_view text, bool& value, std::string_view help_text)
	{
		bool clicked = IsItemSelected() && m_ItemClicked;
		if (clicked)
			value = !value;
		DrawOption(text);
		NextOption(help_text);
		return clicked;
	}

	int NativeMenu::ListOption(std::string_view text, std::string_view current, std::optional<std::string_view> left, std::optional<std::string_view> right, std::string_view help_text)
	{
		auto delta = m_ItemDelta;
		bool selected = IsItemSelected();
		bool can_go_left = selected && left.has_value();
		bool can_go_right = selected && right.has_value();

		if (delta < 0 && !can_go_left)
			delta = 0;
		else if (delta > 0 && !can_go_right)
			delta = 0;

		auto current_value_now = (delta < 0) ? *left : ((delta > 0) ? *right : current);
		auto formatted_value = std::format("{}{}{}", can_go_left ? "&lt;" : "", current_value_now, can_go_right ? "&gt;" : ""); // TODO: this is very bad for so many reasons
		DrawOption(text, formatted_value);
		NextOption(help_text);
		return delta;
	}

	bool NativeMenu::IntOption(std::string_view text, int& value, int min, int max, int step, std::string_view help_text)
	{
		auto mod = m_ItemDelta * step;
		bool selected = IsItemSelected();
		bool can_go_left = selected && value > min;
		bool can_go_right = selected && value < max;

		if (mod < 0 && !can_go_left)
			mod = 0;
		else if (mod > 0 && !can_go_right)
			mod = 0;

		if (value + mod > max)
			mod = value - max;
		else if (value + mod < min)
			mod = min - value;

		value += mod;

		// recalculate (this we can't do for ListOption(), which is bad)
		can_go_left = selected && value > min;
		can_go_right = selected && value < max;

		auto formatted_value = std::format("{}{}{}", can_go_left ? "&lt;" : "", value, can_go_right ? "&gt;" : "");
		DrawOption(text, formatted_value);
		NextOption(help_text);
		return mod != 0;
	}

	bool NativeMenu::FloatOption(std::string_view text, float& value, float min, float max, float step, std::string_view help_text)
	{
		double mod        = m_ItemDelta * step;
		bool selected     = IsItemSelected();
		bool can_go_left  = selected && value > min;
		bool can_go_right = selected && value < max;

		if (mod < 0 && !can_go_left)
			mod = 0;
		else if (mod > 0 && !can_go_right)
			mod = 0;

		if (value + mod > max) 
		{
			value = max;
		}
		else if (value + mod < min)
		{
			value = min;
		}
		else if (mod != 0.0f)
		{
			int divisor = 100'000; // TODO 
			int value_as_int = (int)(value * divisor);
			int mod_as_int = (int)(mod * divisor);
			value = (float)(((double)(value_as_int + mod_as_int)) / divisor);
		}

		can_go_left  = selected && value > min;
		can_go_right = selected && value < max;

		auto formatted_value = std::format("{}{}{}", can_go_left ? "&lt;" : "", value, can_go_right ? "&gt;" : "");
		DrawOption(text, formatted_value);
		NextOption(help_text);
		return mod != 0;
	}

	bool NativeMenu::TextOption(std::string_view text, char* buffer, int buf_len, std::string_view help_text)
	{
		bool clicked = m_ItemClicked && IsItemSelected();

		if (clicked)
		{
			clicked = NativeUI::ShowTextBox(text, buffer, buf_len);
		}

		std::string small_str = buffer;
		if (small_str.length() > 26)
		{
			small_str.erase(23, std::string::npos);
			small_str.resize(26, '.');
		}

		DrawOption(text, small_str);
		NextOption(help_text);
		return clicked;
	}

	bool NativeMenu::IsSubmenuButtonHovered()
	{
		return m_HoveredOverSubmenu.has_value();
	}

	void NativeMenu::EnterSubmenu(const Submenu& submenu, bool reset_stack)
	{
		if (reset_stack)
		{
			m_SubmenuStack = {};
			m_View = {};
			m_View.m_Submenu = m_InitialSubmenu;
			PushSubmenu(submenu);
		}
		else
		{
			PushSubmenu(submenu);
		}
		InvalidateMaxItems();
	}

	void NativeMenu::ExitAllSubmenus()
	{
		m_SubmenuStack = {};
		m_View = {};
		m_View.m_Submenu = m_InitialSubmenu;
		m_SubmenuDataJustUpdated = true;
		InvalidateMaxItems();
	}

	bool NativeMenu::DidJustEnterSubmenu()
	{
		return m_SubmenuDataJustUpdated;
	}
}