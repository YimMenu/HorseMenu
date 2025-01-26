#pragma once
#include "util/Joaat.hpp"

// NOTE TO ANYONE WHO STUMBLES ACROSS THIS CODE:
// Using NativeUI for the map editor was a mistake. ImGui (or hell, even CEF) is far easier to set up and use. Please do not waste your time like I did
// You're never supposed to use natives to draw GUIs in RDR, the game UI is managed using a complicated framework consisting of scaleforms,
// state machines, and databinds. Most of the raw draw primitives are stripped and the ones that remain are riddled with bugs requiring
// raw pointers and cursed HTML code to fix. Heed this warning lest demons fly out of your mod menu's nose

namespace YimMenu
{
	// A basic menu draw class that draws menu items
	// Loosely based on the YimScript renderer
	class NativeMenu
	{
	public:
		struct Submenu
		{
			std::string m_Name;
			std::uint32_t m_Hash;

			constexpr Submenu(std::string_view name) :
			    m_Name(name),
			    m_Hash(Joaat(name))
			{
			}

			constexpr Submenu(const Submenu& other) :
			    m_Name(other.m_Name),
			    m_Hash(other.m_Hash)
			{
			}

			constexpr Submenu() :
			    m_Name(""),
			    m_Hash(0)
			{
			}

			constexpr bool operator==(const Submenu& other)
			{
				return m_Hash == other.m_Hash;
			}

			constexpr bool operator!=(const Submenu& other)
			{
				return m_Hash != other.m_Hash;
			}
		};

		struct View
		{
			Submenu m_Submenu;
			std::int32_t m_Item;
			std::uint32_t m_Screen;
		};

	private:
		// inputs
		Submenu m_InitialSubmenu;
		std::string m_MenuName;
		float m_MenuX;
		float m_MenuY;
		std::uint32_t m_ItemsOnScreen;

		// view
		View m_View{};
		std::stack<View> m_SubmenuStack{};
		bool m_SubmenuDataJustUpdated = false;

		// define vars
		std::uint32_t m_CurPosDef = 0;
		std::optional<Submenu> m_HoveredOverSubmenu = std::nullopt;
		float m_CurrentY = 0.0f;
		std::string m_CurrentHelpText{};

		// raw inputs
		bool m_EnterPressed = false;
		bool m_BackPressed  = false;
		bool m_UpPressed    = false;
		bool m_DownPressed  = false;
		bool m_LeftPressed  = false;
		bool m_RightPressed = false;

		// processed inputs
		std::chrono::system_clock::time_point m_NextInputTime{};
		bool m_ItemClicked = false;
		int m_ItemDelta = 0;

		// max items
		int m_RunningMaxItems{};
		std::optional<int> m_CachedMaxItems = std::nullopt; // this is probably bad design
		bool m_DryRun = false;

		// item disabled state
		bool m_Disabled = false;
		int m_ItemsDisabled = 0;
		std::string m_DisabledReason{};

		void UpdateInputs();
		void ClearInputs();
		void HandleItemPress();
		void PushSubmenu(const Submenu& menu);
		void PopSubmenu();
		void HandleBackPress();
		void UpdateScreenPositioning(); 
		int GetMaxItems();
		void InvalidateMaxItems();
		void ClearVariablesPreRun();
		void ClearVariablesPostRun();
		bool IsItemSelected() const;
		bool ShouldRenderItem() const;
		void DrawOption(std::string_view left, std::string_view right = "");
		void NextOption(std::string_view help_text);

	public:
		NativeMenu(std::string_view name, float x, float y, const Submenu& initial_submenu, std::uint32_t num_items_on_screen = 12);

		// Get/set views (should we even have SetView public?)
		const View& GetView() const { return m_View; }
		void SetView(const View& view) { m_View = view; }

		// The main update function. This may be called multiple times per frame as needed
		virtual void UpdateView() = 0;

		// Call this every frame. Eventually calls UpdateView
		void Render();

		// Functions meant to be called inside UpdateView
		bool BeginSubmenu(const Submenu& submenu);
		bool BeginSubmenu(std::string_view text) { return BeginSubmenu(Submenu(text)); }
		void EndSubmenu(); // does nothing (for now)
		void BeginDisabled(bool should_disable = true, std::string_view why = ""); // this cannot be stacked (yet)
		void EndDisabled();
		bool Button(std::string_view text, std::string_view help_text = "");
		void SubmenuButton(std::string_view text, const Submenu& submenu_name, std::string_view help_text = "");
		bool Checkbox(std::string_view text, bool& value, std::string_view help_text = "");
		int ListOption(std::string_view text, std::string_view current, std::optional<std::string_view> left, std::optional<std::string_view> right, std::string_view help_text = ""); // -1 = left pressed, 0 = nothing pressed, 1 = right pressed
		bool IntOption(std::string_view text, int& value, int min, int max, int step, std::string_view help_text = "");
		// to minimize floating point weirdness, this function has many constraints
		// 1) step < 1
		// 2) step > 0.0001
		// 3) min % step == 0 && max % step == 0
		bool FloatOption(std::string_view text, float& value, float min, float max, float step, std::string_view help_text = "");
		bool TextOption(std::string_view text, char* buffer, int buf_len, std::string_view help_text = ""); // this will open a keyboard and block the thread

		// Control funcs (must be called before Render())
		void EnterPressed() { m_EnterPressed = true; }
		void BackPressed() { m_BackPressed = true; }
		void UpPressed() { m_UpPressed = true; }
		void DownPressed() { m_DownPressed = true; }
		void LeftPressed() { m_LeftPressed = true; }
		void RightPressed() { m_RightPressed = true; }

		// Functions to query what we've selected
		bool IsSubmenuButtonHovered(); // only updated after a call to Render

		// Enter submenus programatically
		void EnterSubmenu(const Submenu& name, bool reset_stack = true); // should be ideally called before Render
		void ExitAllSubmenus();
		bool DidJustEnterSubmenu();
	};
}