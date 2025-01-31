#include "NativeDrawing.hpp"
#include "game/rdr/Natives.hpp"
#include "game/pointers/Pointers.hpp"
#include "game/backend/ScriptMgr.hpp"
#include "game/rdr/Scripts.hpp"
#include "util/Joaat.hpp"

#include <script/types.hpp>
#include <script/scrThread.hpp>

namespace
{
	constexpr auto g_FontNames = std::to_array({"util", "catalog5", "body1", "body", "Debug_REG", "catalog4", "chalk", "catalog1", "ledger", "title", "wantedPostersGeneric", "gtaCash", "gamername", "handwritten"});
}

namespace YimMenu::NativeUI
{
	void DrawTextAt(std::string_view text, float x, float y, ImColor color, int size, Font font, Alignment align)
	{
		// https://github.com/Halen84/RDR2-Native-Menu-Base/blob/master/src/NativeMenuBase/UI/Drawing.cpp#L255
		// https://github.com/ethylamine/PS4-RDR-2-Menu-Base/blob/main/gtaPayload/source/menu.cpp#L102

		UIDEBUG::_BG_SET_TEXT_COLOR(color.Value.x * 255, color.Value.y * 255, color.Value.z * 255, color.Value.w * 255);
		auto right_margin = align == Alignment::RIGHT ? ((int)(*Pointers.ScreenResX) - (int)(x * *Pointers.ScreenResX)) : 0; 
		auto align_str    = align == Alignment::LEFT ? "Left" : (align == Alignment::CENTER ? "Center" : "Right");

		if (align == Alignment::RIGHT)
			x = 0.0f;
		else if (align == Alignment::CENTER)
		{
			x = -1.0f + (x * 2.0f); // what is this supposed to do anyway?
		}

		auto old_flags = *Pointers.ScriptUIDrawFlags;
		*Pointers.ScriptUIDrawFlags = 4;
		UIDEBUG::_BG_DISPLAY_TEXT(MISC::VAR_STRING(10, reinterpret_cast<const char*>("LITERAL_STRING"), std::format(
			"<TEXTFORMAT RIGHTMARGIN='{}'><P ALIGN='{}'><FONT FACE='${}' LETTERSPACING='{}' SIZE='{}'>~s~{}</FONT></P><TEXTFORMAT>", 
			right_margin,
			align_str,
			g_FontNames[static_cast<int>(font)],
			0,
			size,
			text
		).c_str()), x, y);
		*Pointers.ScriptUIDrawFlags = old_flags;
	}

	void DrawRect(float x, float y, float width, float height, ImColor color)
	{
		auto old_flags = *Pointers.ScriptUIDrawFlags;
		*Pointers.ScriptUIDrawFlags = 4;
		GRAPHICS::DRAW_RECT(x + (width / 2), y + (height / 2), width, height, color.Value.x * 255, color.Value.y * 255, color.Value.z * 255, color.Value.w * 255, false, true);
		*Pointers.ScriptUIDrawFlags = old_flags;
	}

	void DrawSprite(std::string_view dict, std::string_view name, float x, float y, float width, float height, float heading, ImColor color, bool centered)
	{
		if (!centered)
		{
			x += width * 0.5f;
			y += height * 0.5f;
		}

		auto old_flags = *Pointers.ScriptUIDrawFlags;
		*Pointers.ScriptUIDrawFlags = 4;
		GRAPHICS::DRAW_SPRITE(dict.data(),
		    name.data(),
		    x,
		    y,
		    width,
		    height,
		    heading,
		    color.Value.x * 255,
		    color.Value.y * 255,
		    color.Value.z * 255,
		    color.Value.w * 255,
		    false);
		*Pointers.ScriptUIDrawFlags = old_flags;
	}

	void DrawLargeHeader(float x, float y, float width, float height, std::string_view text, ImColor background_color, ImColor text_color)
	{
		float text_x = x + 0.01;
		float text_y = y + (height / 2) - 0.027;

		DrawRect(x, y, width, height, background_color);
		DrawTextAt(text, text_x, text_y, text_color, 46, Font::DREAMERSCRIPT);
	}

	void PlaySoundFrontend(std::string_view ref, std::string_view name)
	{
		AUDIO::_STOP_SOUND_WITH_NAME(name.data(), ref.data());
		AUDIO::PLAY_SOUND_FRONTEND(name.data(), ref.data(), true, 0);
	}

	bool ShowAlertMessage(std::string_view title, std::string_view message, std::uint32_t accept_prompt, std::uint32_t decline_prompt, std::string_view sound_ref, std::string_view sound_name)
	{
		// TODO: move these into RDR-Classes
		struct UI_STICKY_FEED_CONTEXT_BUTTON
		{
			SCR_HASH ActionHash = 0;
			uint64_t PAD_0001[2]; // unused
			SCR_BOOL PAD_0003 = FALSE; // not sure what this does
		};
		static_assert(sizeof(UI_STICKY_FEED_CONTEXT_BUTTON) == 4 * 8);

		struct UI_STICKY_FEED_CONTEXT
		{
			const char*                   SoundRef = "";
			const char*                   SoundName = "";
			SCR_INT                       PAD_0002 = 0; // read as a word by code
			UI_STICKY_FEED_CONTEXT_BUTTON AcceptButton{};
			UI_STICKY_FEED_CONTEXT_BUTTON BackButton{};
			UI_STICKY_FEED_CONTEXT_BUTTON OptionButton{};
			UI_STICKY_FEED_CONTEXT_BUTTON OptionAltButton{};
		};
		static_assert(sizeof(UI_STICKY_FEED_CONTEXT) == 19 * 8);

		struct UI_STICKY_FEED_MESSAGE
		{
			SCR_INT     PAD_0000 = 0;
			SCR_INT     PAD_0001 = 0; // unused
			const char* Title;
			const char* Message;
		};
		static_assert(sizeof(UI_STICKY_FEED_MESSAGE) == 4 * 8);

		// from the NativeDB
		struct UI_SCRIPT_EVENT
		{
			SCR_HASH EventType; // https://alloc8or.re/rdr3/doc/enums/eUIScriptEventType.txt
			SCR_INT  IntParam;
			SCR_HASH HashParam;
			SCR_HASH DatastoreParam;
		};
		static_assert(sizeof(UI_SCRIPT_EVENT) == 4 * 8);

		UI_STICKY_FEED_CONTEXT ctx;
		ctx.SoundRef = sound_ref.data();
		ctx.SoundName = sound_name.data();
		ctx.AcceptButton.ActionHash = accept_prompt;
		ctx.BackButton.ActionHash = decline_prompt;

		UI_STICKY_FEED_MESSAGE msg;
		msg.Title = MISC::VAR_STRING(10, "LITERAL_STRING"sv.data(), title.data());
		msg.Message = MISC::VAR_STRING(10, "LITERAL_STRING"sv.data(), message.data());

		auto message_handle = UISTICKYFEED::_UI_STICKY_FEED_CREATE_WARNING_MESSAGE(&ctx, &msg, true); // passing true here will copy the message string over to the scaleform, or else 
																									  // it would assume the string is static for the duration of the script
		bool action_result = false;

		while (message_handle != 0)
		{
			ScriptMgr::Yield();
			while (UIEVENTS::EVENTS_UI_IS_PENDING("WARNING_FEED"_J))
			{
				UI_SCRIPT_EVENT event_data{};
				if (UIEVENTS::EVENTS_UI_PEEK_MESSAGE("WARNING_FEED"_J, &event_data) && event_data.IntParam == message_handle)
				{
					if (event_data.EventType == "ITEM_SELECTED"_J)
					{
						if (accept_prompt && event_data.HashParam == "UI_STICKY_FEED_BUTTON_TYPE_ACCEPT"_J)
						{
							action_result = true;
							UISTICKYFEED::_UI_STICKY_FEED_CLEAR_MESSAGE(message_handle);
							message_handle = 0;
						}
						else if (decline_prompt && event_data.HashParam == "UI_STICKY_FEED_BUTTON_TYPE_BACK"_J)
						{
							UISTICKYFEED::_UI_STICKY_FEED_CLEAR_MESSAGE(message_handle);
							message_handle = 0;
						}
					}
					else if (event_data.EventType == "STICKY_FEED_CLEARED"_J)
					{
						message_handle = 0;
					}
				}

				UIEVENTS::EVENTS_UI_POP_MESSAGE("WARNING_FEED"_J);
			}
		}

		return action_result;
	}

	bool ShowTextBox(std::string_view title, char* buf, int max_length)
	{
		int font_flags = 256;
		if (LOCALIZATION::_DOES_CURRENT_LANGUAGE_SUPPORT_CONDENSED_STYLE())
			font_flags |= 64;
		MISC::NEXT_ONSCREEN_KEYBOARD_RESULT_WILL_DISPLAY_USING_THESE_FONTS(font_flags);
		MISC::DISPLAY_ONSCREEN_KEYBOARD(0, title.data(), nullptr, buf, nullptr, nullptr, nullptr, max_length); // note to pasters: make sure you have the GetTextLabel hook or the keyboard title won't show up

		while (true)
		{
			ScriptMgr::Yield();
			int update_res = MISC::UPDATE_ONSCREEN_KEYBOARD();

			if (update_res == 1)
			{
				strncpy(buf, MISC::GET_ONSCREEN_KEYBOARD_RESULT(), max_length);
				return true;
			}
			else if (update_res == 2 || update_res == 3)
			{
				MISC::CANCEL_ONSCREEN_KEYBOARD();
				return false;
			}
		}
	}

	void FadeScreenOut(int dur_in_ms)
	{
		CAM::DO_SCREEN_FADE_OUT(dur_in_ms);
	}

	void FadeScreenIn(int dur_in_ms)
	{
		if (CAM::IS_SCREEN_FADED_IN())
			FadeScreenOut(0);

		CAM::DO_SCREEN_FADE_IN(dur_in_ms);
	}

	void DisableBountyBoard()
	{
		if (*Pointers.IsSessionStarted)
		{
			// TODO this is an incredibly dumb idea
			// need to reverse CScriptHandler eventually

			constexpr auto bad_ui_state_machines = std::to_array({-1436556974, 255164800, 1546991729, -470163491});

			for (auto machine : bad_ui_state_machines)
			{
				if (UISTATEMACHINE::UI_STATE_MACHINE_EXISTS(machine))
				{
					for (auto& thread : *Pointers.ScriptThreads)
					{
						if (thread->m_Handler)
						{
							Scripts::RunAsScript(thread, [machine] {
								UISTATEMACHINE::UI_STATE_MACHINE_DESTROY(machine);
							});
						}
					}
				}
			}
		}
	}
}