#pragma once
#include "core/frontend/widgets/imgui_colors.h"

namespace YimMenu::NativeUI
{
	enum class Font
	{
		ARIAL,
		CABRITO,
		DROIDSERIF,
		HAPNA,
		HELVETICA,
		CATALOGUE,
		CHALK,
		GOTHICA,
		LEDGER,
		LINO,
		TURRI,
		REDEMPTION,
		GAMERTAG,
		DREAMERSCRIPT
	};

	enum class Alignment
	{
		LEFT,
		CENTER,
		RIGHT
	};

	// god I miss GTA's native UI
	// it's all crazy XML now
	void DrawTextAt(std::string_view text, float x, float y, ImColor color, int size = 20, Font font = Font::HELVETICA, Alignment align = Alignment::LEFT);
	void DrawRect(float x, float y, float width, float height, ImColor color); // from the edges, not from the center
	void DrawSprite(std::string_view dict, std::string_view name, float x, float y, float width, float height, float heading, ImColor color, bool centered = true);
	void DrawLargeHeader(float x, float y, float width, float height, std::string_view text, ImColor background_color, ImColor text_color);

	// technically not for drawing stuff but still useful
	void PlaySoundFrontend(std::string_view ref, std::string_view name); // the args are swapped because it makes more sense for the ref to come first

	// alert messages (these will block the thread until the user accepts/dismisses them)
	// use only when necessary
	bool ShowAlertMessage(std::string_view title, std::string_view message, std::uint32_t accept_prompt, std::uint32_t decline_prompt = 0, std::string_view sound_ref = "", std::string_view sound_name = ""); // true = accept, false = cancel

	// text input (also blocks the thread)
	bool ShowTextBox(std::string_view title, char* buf, int max_length);

	// screen procs
	void FadeScreenOut(int dur_in_ms); // does nothing when the screen is already faded out
	void FadeScreenIn(int dur_in_ms); // this will force the screen to fade out if it isn't already

	// misc
	void DisableBountyBoard(); // call this every tick
}