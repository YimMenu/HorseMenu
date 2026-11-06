#include "NativeBinding.hpp"
#include "game/rdr/Natives.hpp"

namespace Terminus::LuaJIT::Natives
{
	static void LUA_NATIVE_HUD__ENABLE_REDUCED_MENU_TIME_SCALE()
	{
		HUD::_ENABLE_REDUCED_MENU_TIME_SCALE();
	}

	static void LUA_NATIVE_HUD__DISABLE_REDUCED_MENU_TIME_SCALE()
	{
		HUD::_DISABLE_REDUCED_MENU_TIME_SCALE();
	}

	static void LUA_NATIVE_HUD__ENABLE_HUD_CONTEXT_THIS_FRAME(Hash component)
	{
		HUD::_ENABLE_HUD_CONTEXT_THIS_FRAME(component);
	}

	static void LUA_NATIVE_HUD__ENABLE_HUD_CONTEXT(Hash component)
	{
		HUD::_ENABLE_HUD_CONTEXT(component);
	}

	static void LUA_NATIVE_HUD__DISABLE_HUD_CONTEXT(Hash component)
	{
		HUD::_DISABLE_HUD_CONTEXT(component);
	}

	static int LUA_NATIVE_HUD__0x7EC0D68233E391AC(int p0)
	{
		auto retval = HUD::_0x7EC0D68233E391AC(p0);
		return retval;
	}

	static void LUA_NATIVE_HUD__BUSYSPINNER_SET_TEXT(sol::stack_object text)
	{
		HUD::_BUSYSPINNER_SET_TEXT(text.is<const char*>() ? text.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_HUD_BUSYSPINNER_OFF()
	{
		HUD::BUSYSPINNER_OFF();
	}

	static bool LUA_NATIVE_HUD_BUSYSPINNER_IS_ON()
	{
		auto retval = (bool)HUD::BUSYSPINNER_IS_ON();
		return retval;
	}

	static const char* LUA_NATIVE_HUD_GET_CHARACTER_FROM_AUDIO_CONVERSATION_FILENAME(sol::stack_object pText, int startPoint, int endPoint)
	{
		auto retval = HUD::GET_CHARACTER_FROM_AUDIO_CONVERSATION_FILENAME(pText.is<const char*>() ? pText.as<const char*>() : nullptr, startPoint, endPoint);
		return retval;
	}

	static const char* LUA_NATIVE_HUD_GET_FILENAME_FOR_AUDIO_CONVERSATION(sol::stack_object pTextLabelOfAudioConversation)
	{
		auto retval = HUD::GET_FILENAME_FOR_AUDIO_CONVERSATION(pTextLabelOfAudioConversation.is<const char*>() ? pTextLabelOfAudioConversation.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_HUD_CLEAR_ALL_HELP_MESSAGES()
	{
		HUD::CLEAR_ALL_HELP_MESSAGES();
	}

	static bool LUA_NATIVE_HUD_TEXT_BLOCK_IS_LOADED(sol::stack_object textBlock)
	{
		auto retval = (bool)HUD::TEXT_BLOCK_IS_LOADED(textBlock.is<const char*>() ? textBlock.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_HUD__TEXT_BLOCK_IS_STREAMED(sol::stack_object textBlock)
	{
		auto retval = (bool)HUD::_TEXT_BLOCK_IS_STREAMED(textBlock.is<const char*>() ? textBlock.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_HUD_TEXT_BLOCK_REQUEST(sol::stack_object textBlock)
	{
		HUD::TEXT_BLOCK_REQUEST(textBlock.is<const char*>() ? textBlock.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_HUD__TEXT_BLOCK_DELETE(sol::stack_object textBlock)
	{
		HUD::_TEXT_BLOCK_DELETE(textBlock.is<const char*>() ? textBlock.as<const char*>() : nullptr);
	}

	static bool LUA_NATIVE_HUD__DOES_TEXT_BLOCK_EXIST(sol::stack_object textDatabase)
	{
		auto retval = (bool)HUD::_DOES_TEXT_BLOCK_EXIST(textDatabase.is<const char*>() ? textDatabase.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_HUD_DOES_TEXT_LABEL_EXIST(sol::stack_object pTextLabel)
	{
		auto retval = (bool)HUD::DOES_TEXT_LABEL_EXIST(pTextLabel.is<const char*>() ? pTextLabel.as<const char*>() : nullptr);
		return retval;
	}

	static const char* LUA_NATIVE_HUD__GET_LABEL_TEXT_2(sol::stack_object label)
	{
		auto retval = HUD::_GET_LABEL_TEXT_2(label.is<const char*>() ? label.as<const char*>() : nullptr);
		return retval;
	}

	static const char* LUA_NATIVE_HUD__GET_TEXT_SUBSTRING_2(sol::stack_object text, int length)
	{
		auto retval = HUD::_GET_TEXT_SUBSTRING_2(text.is<const char*>() ? text.as<const char*>() : nullptr, length);
		return retval;
	}

	static Any LUA_NATIVE_HUD__0x806862E5D266CF38(Any p0, Any p1, Any p2)
	{
		auto retval = HUD::_0x806862E5D266CF38(p0, p1, p2);
		return retval;
	}

	static int LUA_NATIVE_HUD_GET_LENGTH_OF_LITERAL_STRING(sol::stack_object pLiteralString)
	{
		auto retval = HUD::GET_LENGTH_OF_LITERAL_STRING(pLiteralString.is<const char*>() ? pLiteralString.as<const char*>() : nullptr);
		return retval;
	}

	static int LUA_NATIVE_HUD_GET_LENGTH_OF_LITERAL_STRING_IN_BYTES(sol::stack_object pLiteralString)
	{
		auto retval = HUD::GET_LENGTH_OF_LITERAL_STRING_IN_BYTES(pLiteralString.is<const char*>() ? pLiteralString.as<const char*>() : nullptr);
		return retval;
	}

	static const char* LUA_NATIVE_HUD_GET_STRING_FROM_HASH_KEY(Hash labelHash)
	{
		auto retval = HUD::GET_STRING_FROM_HASH_KEY(labelHash);
		return retval;
	}

	static bool LUA_NATIVE_HUD_IS_RADAR_PREFERENCE_SWITCHED_ON()
	{
		auto retval = (bool)HUD::IS_RADAR_PREFERENCE_SWITCHED_ON();
		return retval;
	}

	static bool LUA_NATIVE_HUD_IS_SUBTITLE_PREFERENCE_SWITCHED_ON()
	{
		auto retval = (bool)HUD::IS_SUBTITLE_PREFERENCE_SWITCHED_ON();
		return retval;
	}

	static void LUA_NATIVE_HUD_DISPLAY_HUD(bool bDisplayHudFlag)
	{
		HUD::DISPLAY_HUD(bDisplayHudFlag);
	}

	static bool LUA_NATIVE_HUD_IS_HUD_HIDDEN()
	{
		auto retval = (bool)HUD::IS_HUD_HIDDEN();
		return retval;
	}

	static bool LUA_NATIVE_HUD_IS_RADAR_HIDDEN()
	{
		auto retval = (bool)HUD::IS_RADAR_HIDDEN();
		return retval;
	}

	static bool LUA_NATIVE_HUD_IS_RADAR_HIDDEN_BY_SCRIPT()
	{
		auto retval = (bool)HUD::IS_RADAR_HIDDEN_BY_SCRIPT();
		return retval;
	}

	static std::tuple<int, int, int, int> LUA_NATIVE_HUD__GET_COLOR_FROM_NAME(Hash colorNameHash, int red, int green, int blue, int alpha)
	{
		std::tuple<int, int, int, int> return_values;
		HUD::_GET_COLOR_FROM_NAME(colorNameHash, &red, &green, &blue, &alpha);
		std::get<0>(return_values) = red;
		std::get<1>(return_values) = green;
		std::get<2>(return_values) = blue;
		std::get<3>(return_values) = alpha;

		return return_values;
	}

	static void LUA_NATIVE_HUD__DISPLAY_TEXT(sol::stack_object text, float xPos, float yPos)
	{
		HUD::_DISPLAY_TEXT(text.is<const char*>() ? text.as<const char*>() : nullptr, xPos, yPos);
	}

	static void LUA_NATIVE_HUD__SET_TEXT_COLOR(int r, int g, int b, int a)
	{
		HUD::_SET_TEXT_COLOR(r, g, b, a);
	}

	static void LUA_NATIVE_HUD_SET_TEXT_RENDER_ID(int RenderIndex)
	{
		HUD::SET_TEXT_RENDER_ID(RenderIndex);
	}

	static bool LUA_NATIVE_HUD_REGISTER_NAMED_RENDERTARGET(sol::stack_object name, bool delay)
	{
		auto retval = (bool)HUD::REGISTER_NAMED_RENDERTARGET(name.is<const char*>() ? name.as<const char*>() : nullptr, delay);
		return retval;
	}

	static bool LUA_NATIVE_HUD_IS_NAMED_RENDERTARGET_REGISTERED(sol::stack_object name)
	{
		auto retval = (bool)HUD::IS_NAMED_RENDERTARGET_REGISTERED(name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_HUD_RELEASE_NAMED_RENDERTARGET(sol::stack_object name)
	{
		auto retval = (bool)HUD::RELEASE_NAMED_RENDERTARGET(name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_HUD_LINK_NAMED_RENDERTARGET(Hash ModelHash)
	{
		HUD::LINK_NAMED_RENDERTARGET(ModelHash);
	}

	static int LUA_NATIVE_HUD_GET_NAMED_RENDERTARGET_RENDER_ID(sol::stack_object name)
	{
		auto retval = HUD::GET_NAMED_RENDERTARGET_RENDER_ID(name.is<const char*>() ? name.as<const char*>() : nullptr);
		return retval;
	}

	static bool LUA_NATIVE_HUD_IS_NAMED_RENDERTARGET_LINKED(Hash ModelHash)
	{
		auto retval = (bool)HUD::IS_NAMED_RENDERTARGET_LINKED(ModelHash);
		return retval;
	}

	static void LUA_NATIVE_HUD__0x9D37EB5003E0F2CF(Any p0, Any p1)
	{
		HUD::_0x9D37EB5003E0F2CF(p0, p1);
	}

	static void LUA_NATIVE_HUD_HIDE_LOADING_ON_FADE_THIS_FRAME()
	{
		HUD::HIDE_LOADING_ON_FADE_THIS_FRAME();
	}

	static void LUA_NATIVE_HUD__0x052D4AC0922AF91A(Any p0, Any p1)
	{
		HUD::_0x052D4AC0922AF91A(p0, p1);
	}

	static void LUA_NATIVE_HUD_HIDE_HUD_AND_RADAR_THIS_FRAME()
	{
		HUD::HIDE_HUD_AND_RADAR_THIS_FRAME();
	}

	static void LUA_NATIVE_HUD__0x8A59D44189AF2BC5(Any p0, Any p1)
	{
		HUD::_0x8A59D44189AF2BC5(p0, p1);
	}

	static void LUA_NATIVE_HUD__0x160825DADF1B04B3()
	{
		HUD::_0x160825DADF1B04B3();
	}

	static Any LUA_NATIVE_HUD__0x9C409BBC492CB5B1()
	{
		auto retval = HUD::_0x9C409BBC492CB5B1();
		return retval;
	}

	static Any LUA_NATIVE_HUD__0x0501D52D24EA8934(Any p0)
	{
		auto retval = HUD::_0x0501D52D24EA8934(p0);
		return retval;
	}

	static Any LUA_NATIVE_HUD__0x100157D6D7FE32CA(Any p0, Any p1)
	{
		auto retval = HUD::_0x100157D6D7FE32CA(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_HUD__0x28AE29D909C8FDCE(Any p0)
	{
		auto retval = HUD::_0x28AE29D909C8FDCE(p0);
		return retval;
	}

	static void LUA_NATIVE_HUD__0x2F7BB105144ACF30()
	{
		HUD::_0x2F7BB105144ACF30();
	}

	static void LUA_NATIVE_HUD__0xBFFF81E12A745A5F()
	{
		HUD::_0xBFFF81E12A745A5F();
	}

	static void LUA_NATIVE_HUD_SET_MISSION_NAME(bool bActive, sol::stack_object pTextLabel)
	{
		HUD::SET_MISSION_NAME(bActive, pTextLabel.is<const char*>() ? pTextLabel.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_HUD_SET_MISSION_NAME_FOR_UGC_MISSION(bool bActive, sol::stack_object pMissionName)
	{
		HUD::SET_MISSION_NAME_FOR_UGC_MISSION(bActive, pMissionName.is<const char*>() ? pMissionName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_HUD__0xCE0D2F5586627CCE(Any p0, Any p1, Any p2, Any p3, Any p4)
	{
		HUD::_0xCE0D2F5586627CCE(p0, p1, p2, p3, p4);
	}

	static std::tuple<int, float, float> LUA_NATIVE_HUD_GET_HUD_SCREEN_POSITION_FROM_WORLD_POSITION(float vWorldPosX, float vWorldPosY, float vWorldPosZ, float fScreenPosX, float fScreenPosY)
	{
		std::tuple<int, float, float> return_values;
		std::get<0>(return_values) = HUD::GET_HUD_SCREEN_POSITION_FROM_WORLD_POSITION(vWorldPosX, vWorldPosY, vWorldPosZ, &fScreenPosX, &fScreenPosY);
		std::get<1>(return_values) = fScreenPosX;
		std::get<2>(return_values) = fScreenPosY;

		return return_values;
	}

	static void LUA_NATIVE_HUD__HIDE_HUD_THIS_FRAME()
	{
		HUD::_HIDE_HUD_THIS_FRAME();
	}

	static void LUA_NATIVE_HUD_DISABLE_FRONTEND_THIS_FRAME()
	{
		HUD::DISABLE_FRONTEND_THIS_FRAME();
	}

	static void LUA_NATIVE_HUD__0x5651516D947ABC53()
	{
		HUD::_0x5651516D947ABC53();
	}

	static void LUA_NATIVE_HUD_ALLOW_PAUSE_WHEN_NOT_IN_STATE_OF_PLAY_THIS_FRAME()
	{
		HUD::ALLOW_PAUSE_WHEN_NOT_IN_STATE_OF_PLAY_THIS_FRAME();
	}

	static void LUA_NATIVE_HUD_SET_FRONTEND_ACTIVE(bool bActive)
	{
		HUD::SET_FRONTEND_ACTIVE(bActive);
	}

	static bool LUA_NATIVE_HUD_IS_PAUSE_MENU_ACTIVE()
	{
		auto retval = (bool)HUD::IS_PAUSE_MENU_ACTIVE();
		return retval;
	}

	static void LUA_NATIVE_HUD__SHOW_PLAYER_CORES(bool state)
	{
		HUD::_SHOW_PLAYER_CORES(state);
	}

	static void LUA_NATIVE_HUD__SHOW_HORSE_CORES(bool state)
	{
		HUD::_SHOW_HORSE_CORES(state);
	}

	static void LUA_NATIVE_HUD__0x3FE4FB41EF7D2196(Any p0)
	{
		HUD::_0x3FE4FB41EF7D2196(p0);
	}

	static void LUA_NATIVE_HUD__JOURNAL_WRITE_ENTRY(Any p0)
	{
		HUD::_JOURNAL_WRITE_ENTRY(p0);
	}

	static Any LUA_NATIVE_HUD__JOURNAL_CAN_WRITE_ENTRY(Any p0)
	{
		auto retval = HUD::_JOURNAL_CAN_WRITE_ENTRY(p0);
		return retval;
	}

	static Any LUA_NATIVE_HUD__JOURNAL_GET_ENTRY_COUNT()
	{
		auto retval = HUD::_JOURNAL_GET_ENTRY_COUNT();
		return retval;
	}

	static Any LUA_NATIVE_HUD__JOURNAL_GET_ENTRY_AT_INDEX(Any p0)
	{
		auto retval = HUD::_JOURNAL_GET_ENTRY_AT_INDEX(p0);
		return retval;
	}

	static Any LUA_NATIVE_HUD__JOURNAL_GET_GRIME_AT_INDEX(Any p0)
	{
		auto retval = HUD::_JOURNAL_GET_GRIME_AT_INDEX(p0);
		return retval;
	}

	static Any LUA_NATIVE_HUD__JOURNAL_GET_ENTRY_INFO(Any p0, Any p1)
	{
		auto retval = HUD::_JOURNAL_GET_ENTRY_INFO(p0, p1);
		return retval;
	}

	static Any LUA_NATIVE_HUD__JOURNAL_GET_TEXTURE_WITH_LAYOUT(Any p0, Any p1, Any p2)
	{
		auto retval = HUD::_JOURNAL_GET_TEXTURE_WITH_LAYOUT(p0, p1, p2);
		return retval;
	}

	static void LUA_NATIVE_HUD__JOURNAL_MARK_READ(Any p0)
	{
		HUD::_JOURNAL_MARK_READ(p0);
	}

	static void LUA_NATIVE_HUD__JOURNAL_CLEAR_ALL_PROGRESS()
	{
		HUD::_JOURNAL_CLEAR_ALL_PROGRESS();
	}

	static Any LUA_NATIVE_HUD_UI_REQUEST_SCENE(Any p0, Any p1)
	{
		auto retval = HUD::UI_REQUEST_SCENE(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_HUD__0xF1E6979C0B779985(int uiscene)
	{
		HUD::_0xF1E6979C0B779985(uiscene);
	}

	static Any LUA_NATIVE_HUD_UI_GET_SCENE_UIOBJECT(Any p0)
	{
		auto retval = HUD::UI_GET_SCENE_UIOBJECT(p0);
		return retval;
	}

	static void LUA_NATIVE_HUD_UI_MOVIEVIEW_SET_RENDER_TARGET(Any p0, Any p1)
	{
		HUD::UI_MOVIEVIEW_SET_RENDER_TARGET(p0, p1);
	}

	static Prompt LUA_NATIVE_HUD__UI_PROMPT_CREATE(Hash inputHash, sol::stack_object labelName, Any p2, Any p3, Any p4, int p5)
	{
		auto retval = HUD::_UI_PROMPT_CREATE(inputHash, labelName.is<const char*>() ? labelName.as<const char*>() : nullptr, p2, p3, p4, p5);
		return retval;
	}

	static Prompt LUA_NATIVE_HUD__UI_PROMPT_REGISTER_BEGIN()
	{
		auto retval = HUD::_UI_PROMPT_REGISTER_BEGIN();
		return retval;
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_REGISTER_END(Prompt prompt)
	{
		HUD::_UI_PROMPT_REGISTER_END(prompt);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_PRIORITY(Prompt prompt, int priority)
	{
		HUD::_UI_PROMPT_SET_PRIORITY(prompt, priority);
	}

	static Any LUA_NATIVE_HUD__UI_PROMPT_SET_CONTROL_ACTION(Prompt prompt, Hash action)
	{
		auto retval = HUD::_UI_PROMPT_SET_CONTROL_ACTION(prompt, action);
		return retval;
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_ALLOWED_ACTION(Prompt prompt, Hash action)
	{
		HUD::_UI_PROMPT_SET_ALLOWED_ACTION(prompt, action);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_STANDARD_MODE(Prompt prompt, bool releaseMode)
	{
		HUD::_UI_PROMPT_SET_STANDARD_MODE(prompt, releaseMode);
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_HAS_STANDARD_MODE_COMPLETED(Prompt prompt, int p1)
	{
		auto retval = (bool)HUD::_UI_PROMPT_HAS_STANDARD_MODE_COMPLETED(prompt, p1);
		return retval;
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_PRESSED_TIMED_MODE(Prompt prompt, int depletionTimeMs)
	{
		HUD::_UI_PROMPT_SET_PRESSED_TIMED_MODE(prompt, depletionTimeMs);
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_HAS_PRESSED_TIMED_MODE_COMPLETED(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_HAS_PRESSED_TIMED_MODE_COMPLETED(prompt);
		return retval;
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_HAS_PRESSED_TIMED_MODE_FAILED(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_HAS_PRESSED_TIMED_MODE_FAILED(prompt);
		return retval;
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_HOLD_MODE(Prompt prompt, int holdTimeMs)
	{
		HUD::_UI_PROMPT_SET_HOLD_MODE(prompt, holdTimeMs);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_STANDARDIZED_HOLD_MODE(Prompt prompt, Hash timedEventHash)
	{
		HUD::_UI_PROMPT_SET_STANDARDIZED_HOLD_MODE(prompt, timedEventHash);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_HOLD_INDEFINITELY_MODE(Prompt prompt)
	{
		HUD::_UI_PROMPT_SET_HOLD_INDEFINITELY_MODE(prompt);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_HOLD_AUTO_FILL_MODE(Prompt prompt, int autoFillTimeMs, int holdTimeMs)
	{
		HUD::_UI_PROMPT_SET_HOLD_AUTO_FILL_MODE(prompt, autoFillTimeMs, holdTimeMs);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_HOLD_AUTO_FILL_WITH_DECAY_MODE(Prompt prompt, int autoFillTimeMs, int holdTimeMs)
	{
		HUD::_UI_PROMPT_SET_HOLD_AUTO_FILL_WITH_DECAY_MODE(prompt, autoFillTimeMs, holdTimeMs);
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_HAS_HOLD_AUTO_FILL_MODE(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_HAS_HOLD_AUTO_FILL_MODE(prompt);
		return retval;
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_HAS_HOLD_MODE(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_HAS_HOLD_MODE(prompt);
		return retval;
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_IS_HOLD_MODE_RUNNING(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_IS_HOLD_MODE_RUNNING(prompt);
		return retval;
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_HAS_HOLD_MODE_COMPLETED(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_HAS_HOLD_MODE_COMPLETED(prompt);
		return retval;
	}

	static float LUA_NATIVE_HUD__UI_PROMPT_GET_PROGRESS(Prompt prompt)
	{
		auto retval = HUD::_UI_PROMPT_GET_PROGRESS(prompt);
		return retval;
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_MODE(Prompt prompt, int mashes)
	{
		HUD::_UI_PROMPT_SET_MASH_MODE(prompt, mashes);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_INDEFINITELY_MODE(Prompt prompt)
	{
		HUD::_UI_PROMPT_SET_MASH_INDEFINITELY_MODE(prompt);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_WITH_RESISTANCE_MODE(Prompt prompt, int mashes, float p2, float p3)
	{
		HUD::_UI_PROMPT_SET_MASH_WITH_RESISTANCE_MODE(prompt, mashes, p2, p3);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_WITH_RESISTANCE_CAN_FAIL_MODE(Prompt prompt, int mashes, float p2, float p3)
	{
		HUD::_UI_PROMPT_SET_MASH_WITH_RESISTANCE_CAN_FAIL_MODE(prompt, mashes, p2, p3);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_AUTO_FILL_MODE(Prompt prompt, int autoFillTimeMs, int mashes)
	{
		HUD::_UI_PROMPT_SET_MASH_AUTO_FILL_MODE(prompt, autoFillTimeMs, mashes);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_MANUAL_MODE(Prompt prompt, float p1, float p2, float p3, Any p4)
	{
		HUD::_UI_PROMPT_SET_MASH_MANUAL_MODE(prompt, p1, p2, p3, p4);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_MANUAL_CAN_FAIL_MODE(Prompt prompt, float p1, float p2, float p3, Any p4)
	{
		HUD::_UI_PROMPT_SET_MASH_MANUAL_CAN_FAIL_MODE(prompt, p1, p2, p3, p4);
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_HAS_MANUAL_MASH_MODE(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_HAS_MANUAL_MASH_MODE(prompt);
		return retval;
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_HAS_MASH_MODE(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_HAS_MASH_MODE(prompt);
		return retval;
	}

	static Any LUA_NATIVE_HUD__0xB0E8599243B3F568(Any p0)
	{
		auto retval = HUD::_0xB0E8599243B3F568(p0);
		return retval;
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_HAS_MASH_MODE_COMPLETED(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_HAS_MASH_MODE_COMPLETED(prompt);
		return retval;
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_HAS_MASH_MODE_FAILED(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_HAS_MASH_MODE_FAILED(prompt);
		return retval;
	}

	static float LUA_NATIVE_HUD__UI_PROMPT_GET_MASH_MODE_PROGRESS(Prompt prompt)
	{
		auto retval = HUD::_UI_PROMPT_GET_MASH_MODE_PROGRESS(prompt);
		return retval;
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_MANUAL_MODE_INCREASE_PER_PRESS(Prompt prompt, float rate)
	{
		HUD::_UI_PROMPT_SET_MASH_MANUAL_MODE_INCREASE_PER_PRESS(prompt, rate);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_MANUAL_MODE_DECAY_SPEED(Prompt prompt, float speed)
	{
		HUD::_UI_PROMPT_SET_MASH_MANUAL_MODE_DECAY_SPEED(prompt, speed);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_MANUAL_MODE_PRESSED_GROWTH_SPEED(Prompt prompt, float speed)
	{
		HUD::_UI_PROMPT_SET_MASH_MANUAL_MODE_PRESSED_GROWTH_SPEED(prompt, speed);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_ROTATE_MODE(Prompt prompt, float p1, bool counterclockwise)
	{
		HUD::_UI_PROMPT_SET_ROTATE_MODE(prompt, p1, counterclockwise);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_TARGET_MODE(Prompt prompt, float p1, float p2, Any p3)
	{
		HUD::_UI_PROMPT_SET_TARGET_MODE(prompt, p1, p2, p3);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_TARGET_MODE_TARGET(Prompt prompt, float p1, float p2)
	{
		HUD::_UI_PROMPT_SET_TARGET_MODE_TARGET(prompt, p1, p2);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_TARGET_MODE_PROGRESS(Prompt prompt, float progress)
	{
		HUD::_UI_PROMPT_SET_TARGET_MODE_PROGRESS(prompt, progress);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_BEAT_MODE(Prompt prompt, bool toggle)
	{
		HUD::_UI_PROMPT_SET_BEAT_MODE(prompt, toggle);
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_WAS_BEAT_MODE_PRESSED_IN_TIME_WINDOW(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_WAS_BEAT_MODE_PRESSED_IN_TIME_WINDOW(prompt);
		return retval;
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_BEAT_MODE_GRAYED_OUT(Prompt prompt, Any p1)
	{
		HUD::_UI_PROMPT_SET_BEAT_MODE_GRAYED_OUT(prompt, p1);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_RESTART_MODES(Prompt prompt)
	{
		HUD::_UI_PROMPT_RESTART_MODES(prompt);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_SPINNER_SPEED(Prompt prompt, Any p1)
	{
		HUD::_UI_PROMPT_SET_SPINNER_SPEED(prompt, p1);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_SPINNER_POSITION(Prompt prompt, Any p1)
	{
		HUD::_UI_PROMPT_SET_SPINNER_POSITION(prompt, p1);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_URGENT_PULSING_ENABLED(Prompt prompt, bool toggle)
	{
		HUD::_UI_PROMPT_SET_URGENT_PULSING_ENABLED(prompt, toggle);
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_GET_URGENT_PULSING_ENABLED(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_GET_URGENT_PULSING_ENABLED(prompt);
		return retval;
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_TAG(Prompt prompt, Any p1)
	{
		HUD::_UI_PROMPT_SET_TAG(prompt, p1);
	}

	static int LUA_NATIVE_HUD__UI_PROMPT_GET_GROUP_ID_FOR_TARGET_ENTITY(Entity entity)
	{
		auto retval = HUD::_UI_PROMPT_GET_GROUP_ID_FOR_TARGET_ENTITY(entity);
		return retval;
	}

	static int LUA_NATIVE_HUD__UI_PROMPT_GET_GROUP_ID_FOR_SCENARIO_POINT(Any p0, int p1)
	{
		auto retval = HUD::_UI_PROMPT_GET_GROUP_ID_FOR_SCENARIO_POINT(p0, p1);
		return retval;
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_GROUP(Prompt prompt, int groupId, int tabIndex)
	{
		HUD::_UI_PROMPT_SET_GROUP(prompt, groupId, tabIndex);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_REMOVE_GROUP(Prompt prompt, Any p1)
	{
		HUD::_UI_PROMPT_REMOVE_GROUP(prompt, p1);
	}

	static Any LUA_NATIVE_HUD__UI_PROMPT_SET_ACTIVE_GROUP_THIS_FRAME(Hash hash, sol::stack_object name, int tabAmount, int tabDefaultIndex, int p4, Prompt prompt)
	{
		auto retval = HUD::_UI_PROMPT_SET_ACTIVE_GROUP_THIS_FRAME(hash, name.is<const char*>() ? name.as<const char*>() : nullptr, tabAmount, tabDefaultIndex, p4, prompt);
		return retval;
	}

	static int LUA_NATIVE_HUD__UI_PROMPT_GET_GROUP_ACTIVE_PAGE(Hash hash)
	{
		auto retval = HUD::_UI_PROMPT_GET_GROUP_ACTIVE_PAGE(hash);
		return retval;
	}

	static Any LUA_NATIVE_HUD__UI_PROMPT_SET_AMBIENT_GROUP_THIS_FRAME(Entity entity, float p1, int p2, int p3, Hash p4, sol::stack_object name, int p6)
	{
		auto retval = HUD::_UI_PROMPT_SET_AMBIENT_GROUP_THIS_FRAME(entity, p1, p2, p3, p4, name.is<const char*>() ? name.as<const char*>() : nullptr, p6);
		return retval;
	}

	static Any LUA_NATIVE_HUD__0x8B55B324A9123F6B(int groupId, Volume volume, sol::stack_object p2, Any p3, Any p4, Any p5)
	{
		auto retval = HUD::_0x8B55B324A9123F6B(groupId, volume, p2.is<const char*>() ? p2.as<const char*>() : nullptr, p3, p4, p5);
		return retval;
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_DOES_AMBIENT_GROUP_EXIST(Hash hash)
	{
		auto retval = (bool)HUD::_UI_PROMPT_DOES_AMBIENT_GROUP_EXIST(hash);
		return retval;
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_ADD_GROUP_LINK(Any p0, Prompt prompt, Any p2)
	{
		HUD::_UI_PROMPT_ADD_GROUP_LINK(p0, prompt, p2);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_ADD_GROUP_RETURN_LINK(Any p0, Prompt prompt)
	{
		HUD::_UI_PROMPT_ADD_GROUP_RETURN_LINK(p0, prompt);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_TRANSPORT_MODE(Prompt prompt, int mode)
	{
		HUD::_UI_PROMPT_SET_TRANSPORT_MODE(prompt, mode);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_DISABLE_PROMPTS_THIS_FRAME()
	{
		HUD::_UI_PROMPT_DISABLE_PROMPTS_THIS_FRAME();
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_DELETE(Prompt prompt)
	{
		HUD::_UI_PROMPT_DELETE(prompt);
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_IS_VALID(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_IS_VALID(prompt);
		return retval;
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_IS_ACTIVE(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_IS_ACTIVE(prompt);
		return retval;
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_VISIBLE(Prompt prompt, bool toggle)
	{
		HUD::_UI_PROMPT_SET_VISIBLE(prompt, toggle);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_ENABLED(Prompt prompt, bool toggle)
	{
		HUD::_UI_PROMPT_SET_ENABLED(prompt, toggle);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_TEXT(Prompt prompt, sol::stack_object text)
	{
		HUD::_UI_PROMPT_SET_TEXT(prompt, text.is<const char*>() ? text.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_ATTRIBUTE(Prompt prompt, int attribute, bool enabled)
	{
		HUD::_UI_PROMPT_SET_ATTRIBUTE(prompt, attribute, enabled);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_TYPE(Prompt prompt, int type)
	{
		HUD::_UI_PROMPT_SET_TYPE(prompt, type);
	}

	static void LUA_NATIVE_HUD__0x53CE46C01A089DA1(Prompt prompt, bool p1)
	{
		HUD::_0x53CE46C01A089DA1(prompt, p1);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_MANUAL_RESOLVED(Prompt prompt, Any p1)
	{
		HUD::_UI_PROMPT_SET_MANUAL_RESOLVED(prompt, p1);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_CONTEXT_SET_VOLUME(Prompt prompt, Volume volume)
	{
		HUD::_UI_PROMPT_CONTEXT_SET_VOLUME(prompt, volume);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_CONTEXT_SET_POINT(Prompt prompt, float x, float y, float z)
	{
		HUD::_UI_PROMPT_CONTEXT_SET_POINT(prompt, x, y, z);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_CONTEXT_SET_RADIUS(Prompt prompt, float radius)
	{
		HUD::_UI_PROMPT_CONTEXT_SET_RADIUS(prompt, radius);
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_IS_PRESSED(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_IS_PRESSED(prompt);
		return retval;
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_IS_JUST_PRESSED(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_IS_JUST_PRESSED(prompt);
		return retval;
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_IS_JUST_RELEASED(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_IS_JUST_RELEASED(prompt);
		return retval;
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_IS_RELEASED(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_IS_RELEASED(prompt);
		return retval;
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_ENABLE_PROMPT_TYPE_THIS_FRAME(int p0)
	{
		HUD::_UI_PROMPT_ENABLE_PROMPT_TYPE_THIS_FRAME(p0);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_DISABLE_PROMPT_TYPE_THIS_FRAME(int p0)
	{
		HUD::_UI_PROMPT_DISABLE_PROMPT_TYPE_THIS_FRAME(p0);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_FILTER_CLEAR()
	{
		HUD::_UI_PROMPT_FILTER_CLEAR();
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_PROMPT_PRIORITY_PREFERENCE(Ped ped)
	{
		HUD::_UI_PROMPT_SET_PROMPT_PRIORITY_PREFERENCE(ped);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_CLEAR_PROMPT_PRIORITY_PREFERENCE()
	{
		HUD::_UI_PROMPT_CLEAR_PROMPT_PRIORITY_PREFERENCE();
	}

	static bool LUA_NATIVE_HUD__UI_PROMPT_IS_ENABLED(Prompt prompt)
	{
		auto retval = (bool)HUD::_UI_PROMPT_IS_ENABLED(prompt);
		return retval;
	}

	static bool LUA_NATIVE_HUD_UI_PROMPT_IS_CONTROL_ACTION_ACTIVE(Hash controlAction)
	{
		auto retval = (bool)HUD::UI_PROMPT_IS_CONTROL_ACTION_ACTIVE(controlAction);
		return retval;
	}

	static Any LUA_NATIVE_HUD__0xD6BD313CFA41E57A(Any p0)
	{
		auto retval = HUD::_0xD6BD313CFA41E57A(p0);
		return retval;
	}

	static int LUA_NATIVE_HUD__UI_PROMPT_SET_REGISTER_HORIZONTAL_ORIENTATION()
	{
		auto retval = HUD::_UI_PROMPT_SET_REGISTER_HORIZONTAL_ORIENTATION();
		return retval;
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_CLEAR_HORIZONTAL_ORIENTATION(int id)
	{
		HUD::_UI_PROMPT_CLEAR_HORIZONTAL_ORIENTATION(id);
	}

	static void LUA_NATIVE_HUD__UI_PROMPT_SET_ORDERING_AS_INPUT_TYPE(Prompt prompt, Any p1)
	{
		HUD::_UI_PROMPT_SET_ORDERING_AS_INPUT_TYPE(prompt, p1);
	}

	static Any LUA_NATIVE_HUD__0x066725A9D52B3641()
	{
		auto retval = HUD::_0x066725A9D52B3641();
		return retval;
	}

	static void LUA_NATIVE_HUD__0x958278B97C4AFFD8(Any p0, Any p1)
	{
		HUD::_0x958278B97C4AFFD8(p0, p1);
	}

	static int LUA_NATIVE_HUD__CREATE_MP_GAMER_TAG(Player player, sol::stack_object username, bool pointedClanTag, bool isRockstarClan, sol::stack_object clanTag, int clanFlag)
	{
		auto retval = HUD::_CREATE_MP_GAMER_TAG(player, username.is<const char*>() ? username.as<const char*>() : nullptr, pointedClanTag, isRockstarClan, clanTag.is<const char*>() ? clanTag.as<const char*>() : nullptr, clanFlag);
		return retval;
	}

	static int LUA_NATIVE_HUD_CREATE_FAKE_MP_GAMER_TAG(Ped ped, sol::stack_object PlayerName, bool bCrewTypeIsPrivate, bool bCrewTagContainsRockstar, sol::stack_object CrewTag, int iCrewRank)
	{
		auto retval = HUD::CREATE_FAKE_MP_GAMER_TAG(ped, PlayerName.is<const char*>() ? PlayerName.as<const char*>() : nullptr, bCrewTypeIsPrivate, bCrewTagContainsRockstar, CrewTag.is<const char*>() ? CrewTag.as<const char*>() : nullptr, iCrewRank);
		return retval;
	}

	static int LUA_NATIVE_HUD__CREATE_MP_GAMER_TAG_ON_ENTITY(Entity entity, sol::stack_object text)
	{
		auto retval = HUD::_CREATE_MP_GAMER_TAG_ON_ENTITY(entity, text.is<const char*>() ? text.as<const char*>() : nullptr);
		return retval;
	}

	static void LUA_NATIVE_HUD_REMOVE_MP_GAMER_TAG(int iPlayerNum)
	{
		HUD::REMOVE_MP_GAMER_TAG(iPlayerNum);
	}

	static bool LUA_NATIVE_HUD_IS_MP_GAMER_TAG_ACTIVE(int iPlayerNum)
	{
		auto retval = (bool)HUD::IS_MP_GAMER_TAG_ACTIVE(iPlayerNum);
		return retval;
	}

	static bool LUA_NATIVE_HUD__IS_MP_GAMER_TAG_ACTIVE_ON_ENTITY(int gamerTagId, Entity entity)
	{
		auto retval = (bool)HUD::_IS_MP_GAMER_TAG_ACTIVE_ON_ENTITY(gamerTagId, entity);
		return retval;
	}

	static void LUA_NATIVE_HUD__SET_MP_GAMER_TAG_VISIBILITY(int gamerTagId, int visibility)
	{
		HUD::_SET_MP_GAMER_TAG_VISIBILITY(gamerTagId, visibility);
	}

	static void LUA_NATIVE_HUD__SET_MP_GAMER_TAG_TYPE(int gamerTagId, Hash type)
	{
		HUD::_SET_MP_GAMER_TAG_TYPE(gamerTagId, type);
	}

	static void LUA_NATIVE_HUD__SET_MP_GAMER_TAG_COLOUR(int gamerTagId, Hash colour)
	{
		HUD::_SET_MP_GAMER_TAG_COLOUR(gamerTagId, colour);
	}

	static void LUA_NATIVE_HUD__SET_MP_GAMER_TAG_UNK_ALLOW_LOCALIZED(int gamerTagId, bool allow)
	{
		HUD::_SET_MP_GAMER_TAG_UNK_ALLOW_LOCALIZED(gamerTagId, allow);
	}

	static void LUA_NATIVE_HUD_SET_MP_GAMER_TAG_NAME(int iPlayerNum, sol::stack_object PlayerName)
	{
		HUD::SET_MP_GAMER_TAG_NAME(iPlayerNum, PlayerName.is<const char*>() ? PlayerName.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_HUD__SET_MP_GAMER_TAG_NAME_POSSE(int gamerTagId, sol::stack_object text)
	{
		HUD::_SET_MP_GAMER_TAG_NAME_POSSE(gamerTagId, text.is<const char*>() ? text.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_HUD_SET_MP_GAMER_TAG_BIG_TEXT(int iPlayerNum, sol::stack_object BigText)
	{
		HUD::SET_MP_GAMER_TAG_BIG_TEXT(iPlayerNum, BigText.is<const char*>() ? BigText.as<const char*>() : nullptr);
	}

	static void LUA_NATIVE_HUD__SET_MP_GAMER_TAG_TOP_ICON(int gamerTagId, Hash icon)
	{
		HUD::_SET_MP_GAMER_TAG_TOP_ICON(gamerTagId, icon);
	}

	static void LUA_NATIVE_HUD__SET_MP_GAMER_TAG_SECONDARY_ICON(int gamerTagId, Hash icon)
	{
		HUD::_SET_MP_GAMER_TAG_SECONDARY_ICON(gamerTagId, icon);
	}

	static void LUA_NATIVE_HUD__MP_GAMER_TAG_ENABLE_REVIVE_TOP_ICON(int gamerTagId)
	{
		HUD::_MP_GAMER_TAG_ENABLE_REVIVE_TOP_ICON(gamerTagId);
	}

	static void LUA_NATIVE_HUD__MP_GAMER_TAG_DISABLE_REVIVE_TOP_ICON(int gamerTagId)
	{
		HUD::_MP_GAMER_TAG_DISABLE_REVIVE_TOP_ICON(gamerTagId);
	}

	void RegisterNatives_HUD(sol::state& L)
	{
		auto HUD = L["HUD"].get_or_create<sol::table>();
		HUD.set_function("_ENABLE_REDUCED_MENU_TIME_SCALE", LUA_NATIVE_HUD__ENABLE_REDUCED_MENU_TIME_SCALE);
		HUD.set_function("_DISABLE_REDUCED_MENU_TIME_SCALE", LUA_NATIVE_HUD__DISABLE_REDUCED_MENU_TIME_SCALE);
		HUD.set_function("_ENABLE_HUD_CONTEXT_THIS_FRAME", LUA_NATIVE_HUD__ENABLE_HUD_CONTEXT_THIS_FRAME);
		HUD.set_function("_ENABLE_HUD_CONTEXT", LUA_NATIVE_HUD__ENABLE_HUD_CONTEXT);
		HUD.set_function("_DISABLE_HUD_CONTEXT", LUA_NATIVE_HUD__DISABLE_HUD_CONTEXT);
		HUD.set_function("_0x7EC0D68233E391AC", LUA_NATIVE_HUD__0x7EC0D68233E391AC);
		HUD.set_function("_BUSYSPINNER_SET_TEXT", LUA_NATIVE_HUD__BUSYSPINNER_SET_TEXT);
		HUD.set_function("BUSYSPINNER_OFF", LUA_NATIVE_HUD_BUSYSPINNER_OFF);
		HUD.set_function("BUSYSPINNER_IS_ON", LUA_NATIVE_HUD_BUSYSPINNER_IS_ON);
		HUD.set_function("GET_CHARACTER_FROM_AUDIO_CONVERSATION_FILENAME", LUA_NATIVE_HUD_GET_CHARACTER_FROM_AUDIO_CONVERSATION_FILENAME);
		HUD.set_function("GET_FILENAME_FOR_AUDIO_CONVERSATION", LUA_NATIVE_HUD_GET_FILENAME_FOR_AUDIO_CONVERSATION);
		HUD.set_function("CLEAR_ALL_HELP_MESSAGES", LUA_NATIVE_HUD_CLEAR_ALL_HELP_MESSAGES);
		HUD.set_function("TEXT_BLOCK_IS_LOADED", LUA_NATIVE_HUD_TEXT_BLOCK_IS_LOADED);
		HUD.set_function("_TEXT_BLOCK_IS_STREAMED", LUA_NATIVE_HUD__TEXT_BLOCK_IS_STREAMED);
		HUD.set_function("TEXT_BLOCK_REQUEST", LUA_NATIVE_HUD_TEXT_BLOCK_REQUEST);
		HUD.set_function("_TEXT_BLOCK_DELETE", LUA_NATIVE_HUD__TEXT_BLOCK_DELETE);
		HUD.set_function("_DOES_TEXT_BLOCK_EXIST", LUA_NATIVE_HUD__DOES_TEXT_BLOCK_EXIST);
		HUD.set_function("DOES_TEXT_LABEL_EXIST", LUA_NATIVE_HUD_DOES_TEXT_LABEL_EXIST);
		HUD.set_function("_GET_LABEL_TEXT_2", LUA_NATIVE_HUD__GET_LABEL_TEXT_2);
		HUD.set_function("_GET_TEXT_SUBSTRING_2", LUA_NATIVE_HUD__GET_TEXT_SUBSTRING_2);
		HUD.set_function("_0x806862E5D266CF38", LUA_NATIVE_HUD__0x806862E5D266CF38);
		HUD.set_function("GET_LENGTH_OF_LITERAL_STRING", LUA_NATIVE_HUD_GET_LENGTH_OF_LITERAL_STRING);
		HUD.set_function("GET_LENGTH_OF_LITERAL_STRING_IN_BYTES", LUA_NATIVE_HUD_GET_LENGTH_OF_LITERAL_STRING_IN_BYTES);
		HUD.set_function("GET_STRING_FROM_HASH_KEY", LUA_NATIVE_HUD_GET_STRING_FROM_HASH_KEY);
		HUD.set_function("IS_RADAR_PREFERENCE_SWITCHED_ON", LUA_NATIVE_HUD_IS_RADAR_PREFERENCE_SWITCHED_ON);
		HUD.set_function("IS_SUBTITLE_PREFERENCE_SWITCHED_ON", LUA_NATIVE_HUD_IS_SUBTITLE_PREFERENCE_SWITCHED_ON);
		HUD.set_function("DISPLAY_HUD", LUA_NATIVE_HUD_DISPLAY_HUD);
		HUD.set_function("IS_HUD_HIDDEN", LUA_NATIVE_HUD_IS_HUD_HIDDEN);
		HUD.set_function("IS_RADAR_HIDDEN", LUA_NATIVE_HUD_IS_RADAR_HIDDEN);
		HUD.set_function("IS_RADAR_HIDDEN_BY_SCRIPT", LUA_NATIVE_HUD_IS_RADAR_HIDDEN_BY_SCRIPT);
		HUD.set_function("_GET_COLOR_FROM_NAME", LUA_NATIVE_HUD__GET_COLOR_FROM_NAME);
		HUD.set_function("_DISPLAY_TEXT", LUA_NATIVE_HUD__DISPLAY_TEXT);
		HUD.set_function("_SET_TEXT_COLOR", LUA_NATIVE_HUD__SET_TEXT_COLOR);
		HUD.set_function("SET_TEXT_RENDER_ID", LUA_NATIVE_HUD_SET_TEXT_RENDER_ID);
		HUD.set_function("REGISTER_NAMED_RENDERTARGET", LUA_NATIVE_HUD_REGISTER_NAMED_RENDERTARGET);
		HUD.set_function("IS_NAMED_RENDERTARGET_REGISTERED", LUA_NATIVE_HUD_IS_NAMED_RENDERTARGET_REGISTERED);
		HUD.set_function("RELEASE_NAMED_RENDERTARGET", LUA_NATIVE_HUD_RELEASE_NAMED_RENDERTARGET);
		HUD.set_function("LINK_NAMED_RENDERTARGET", LUA_NATIVE_HUD_LINK_NAMED_RENDERTARGET);
		HUD.set_function("GET_NAMED_RENDERTARGET_RENDER_ID", LUA_NATIVE_HUD_GET_NAMED_RENDERTARGET_RENDER_ID);
		HUD.set_function("IS_NAMED_RENDERTARGET_LINKED", LUA_NATIVE_HUD_IS_NAMED_RENDERTARGET_LINKED);
		HUD.set_function("_0x9D37EB5003E0F2CF", LUA_NATIVE_HUD__0x9D37EB5003E0F2CF);
		HUD.set_function("HIDE_LOADING_ON_FADE_THIS_FRAME", LUA_NATIVE_HUD_HIDE_LOADING_ON_FADE_THIS_FRAME);
		HUD.set_function("_0x052D4AC0922AF91A", LUA_NATIVE_HUD__0x052D4AC0922AF91A);
		HUD.set_function("HIDE_HUD_AND_RADAR_THIS_FRAME", LUA_NATIVE_HUD_HIDE_HUD_AND_RADAR_THIS_FRAME);
		HUD.set_function("_0x8A59D44189AF2BC5", LUA_NATIVE_HUD__0x8A59D44189AF2BC5);
		HUD.set_function("_0x160825DADF1B04B3", LUA_NATIVE_HUD__0x160825DADF1B04B3);
		HUD.set_function("_0x9C409BBC492CB5B1", LUA_NATIVE_HUD__0x9C409BBC492CB5B1);
		HUD.set_function("_0x0501D52D24EA8934", LUA_NATIVE_HUD__0x0501D52D24EA8934);
		HUD.set_function("_0x100157D6D7FE32CA", LUA_NATIVE_HUD__0x100157D6D7FE32CA);
		HUD.set_function("_0x28AE29D909C8FDCE", LUA_NATIVE_HUD__0x28AE29D909C8FDCE);
		HUD.set_function("_0x2F7BB105144ACF30", LUA_NATIVE_HUD__0x2F7BB105144ACF30);
		HUD.set_function("_0xBFFF81E12A745A5F", LUA_NATIVE_HUD__0xBFFF81E12A745A5F);
		HUD.set_function("SET_MISSION_NAME", LUA_NATIVE_HUD_SET_MISSION_NAME);
		HUD.set_function("SET_MISSION_NAME_FOR_UGC_MISSION", LUA_NATIVE_HUD_SET_MISSION_NAME_FOR_UGC_MISSION);
		HUD.set_function("_0xCE0D2F5586627CCE", LUA_NATIVE_HUD__0xCE0D2F5586627CCE);
		HUD.set_function("GET_HUD_SCREEN_POSITION_FROM_WORLD_POSITION", LUA_NATIVE_HUD_GET_HUD_SCREEN_POSITION_FROM_WORLD_POSITION);
		HUD.set_function("_HIDE_HUD_THIS_FRAME", LUA_NATIVE_HUD__HIDE_HUD_THIS_FRAME);
		HUD.set_function("DISABLE_FRONTEND_THIS_FRAME", LUA_NATIVE_HUD_DISABLE_FRONTEND_THIS_FRAME);
		HUD.set_function("_0x5651516D947ABC53", LUA_NATIVE_HUD__0x5651516D947ABC53);
		HUD.set_function("ALLOW_PAUSE_WHEN_NOT_IN_STATE_OF_PLAY_THIS_FRAME", LUA_NATIVE_HUD_ALLOW_PAUSE_WHEN_NOT_IN_STATE_OF_PLAY_THIS_FRAME);
		HUD.set_function("SET_FRONTEND_ACTIVE", LUA_NATIVE_HUD_SET_FRONTEND_ACTIVE);
		HUD.set_function("IS_PAUSE_MENU_ACTIVE", LUA_NATIVE_HUD_IS_PAUSE_MENU_ACTIVE);
		HUD.set_function("_SHOW_PLAYER_CORES", LUA_NATIVE_HUD__SHOW_PLAYER_CORES);
		HUD.set_function("_SHOW_HORSE_CORES", LUA_NATIVE_HUD__SHOW_HORSE_CORES);
		HUD.set_function("_0x3FE4FB41EF7D2196", LUA_NATIVE_HUD__0x3FE4FB41EF7D2196);
		HUD.set_function("_JOURNAL_WRITE_ENTRY", LUA_NATIVE_HUD__JOURNAL_WRITE_ENTRY);
		HUD.set_function("_JOURNAL_CAN_WRITE_ENTRY", LUA_NATIVE_HUD__JOURNAL_CAN_WRITE_ENTRY);
		HUD.set_function("_JOURNAL_GET_ENTRY_COUNT", LUA_NATIVE_HUD__JOURNAL_GET_ENTRY_COUNT);
		HUD.set_function("_JOURNAL_GET_ENTRY_AT_INDEX", LUA_NATIVE_HUD__JOURNAL_GET_ENTRY_AT_INDEX);
		HUD.set_function("_JOURNAL_GET_GRIME_AT_INDEX", LUA_NATIVE_HUD__JOURNAL_GET_GRIME_AT_INDEX);
		HUD.set_function("_JOURNAL_GET_ENTRY_INFO", LUA_NATIVE_HUD__JOURNAL_GET_ENTRY_INFO);
		HUD.set_function("_JOURNAL_GET_TEXTURE_WITH_LAYOUT", LUA_NATIVE_HUD__JOURNAL_GET_TEXTURE_WITH_LAYOUT);
		HUD.set_function("_JOURNAL_MARK_READ", LUA_NATIVE_HUD__JOURNAL_MARK_READ);
		HUD.set_function("_JOURNAL_CLEAR_ALL_PROGRESS", LUA_NATIVE_HUD__JOURNAL_CLEAR_ALL_PROGRESS);
		HUD.set_function("UI_REQUEST_SCENE", LUA_NATIVE_HUD_UI_REQUEST_SCENE);
		HUD.set_function("_0xF1E6979C0B779985", LUA_NATIVE_HUD__0xF1E6979C0B779985);
		HUD.set_function("UI_GET_SCENE_UIOBJECT", LUA_NATIVE_HUD_UI_GET_SCENE_UIOBJECT);
		HUD.set_function("UI_MOVIEVIEW_SET_RENDER_TARGET", LUA_NATIVE_HUD_UI_MOVIEVIEW_SET_RENDER_TARGET);
		HUD.set_function("_UI_PROMPT_CREATE", LUA_NATIVE_HUD__UI_PROMPT_CREATE);
		HUD.set_function("_UI_PROMPT_REGISTER_BEGIN", LUA_NATIVE_HUD__UI_PROMPT_REGISTER_BEGIN);
		HUD.set_function("_UI_PROMPT_REGISTER_END", LUA_NATIVE_HUD__UI_PROMPT_REGISTER_END);
		HUD.set_function("_UI_PROMPT_SET_PRIORITY", LUA_NATIVE_HUD__UI_PROMPT_SET_PRIORITY);
		HUD.set_function("_UI_PROMPT_SET_CONTROL_ACTION", LUA_NATIVE_HUD__UI_PROMPT_SET_CONTROL_ACTION);
		HUD.set_function("_UI_PROMPT_SET_ALLOWED_ACTION", LUA_NATIVE_HUD__UI_PROMPT_SET_ALLOWED_ACTION);
		HUD.set_function("_UI_PROMPT_SET_STANDARD_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_STANDARD_MODE);
		HUD.set_function("_UI_PROMPT_HAS_STANDARD_MODE_COMPLETED", LUA_NATIVE_HUD__UI_PROMPT_HAS_STANDARD_MODE_COMPLETED);
		HUD.set_function("_UI_PROMPT_SET_PRESSED_TIMED_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_PRESSED_TIMED_MODE);
		HUD.set_function("_UI_PROMPT_HAS_PRESSED_TIMED_MODE_COMPLETED", LUA_NATIVE_HUD__UI_PROMPT_HAS_PRESSED_TIMED_MODE_COMPLETED);
		HUD.set_function("_UI_PROMPT_HAS_PRESSED_TIMED_MODE_FAILED", LUA_NATIVE_HUD__UI_PROMPT_HAS_PRESSED_TIMED_MODE_FAILED);
		HUD.set_function("_UI_PROMPT_SET_HOLD_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_HOLD_MODE);
		HUD.set_function("_UI_PROMPT_SET_STANDARDIZED_HOLD_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_STANDARDIZED_HOLD_MODE);
		HUD.set_function("_UI_PROMPT_SET_HOLD_INDEFINITELY_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_HOLD_INDEFINITELY_MODE);
		HUD.set_function("_UI_PROMPT_SET_HOLD_AUTO_FILL_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_HOLD_AUTO_FILL_MODE);
		HUD.set_function("_UI_PROMPT_SET_HOLD_AUTO_FILL_WITH_DECAY_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_HOLD_AUTO_FILL_WITH_DECAY_MODE);
		HUD.set_function("_UI_PROMPT_HAS_HOLD_AUTO_FILL_MODE", LUA_NATIVE_HUD__UI_PROMPT_HAS_HOLD_AUTO_FILL_MODE);
		HUD.set_function("_UI_PROMPT_HAS_HOLD_MODE", LUA_NATIVE_HUD__UI_PROMPT_HAS_HOLD_MODE);
		HUD.set_function("_UI_PROMPT_IS_HOLD_MODE_RUNNING", LUA_NATIVE_HUD__UI_PROMPT_IS_HOLD_MODE_RUNNING);
		HUD.set_function("_UI_PROMPT_HAS_HOLD_MODE_COMPLETED", LUA_NATIVE_HUD__UI_PROMPT_HAS_HOLD_MODE_COMPLETED);
		HUD.set_function("_UI_PROMPT_GET_PROGRESS", LUA_NATIVE_HUD__UI_PROMPT_GET_PROGRESS);
		HUD.set_function("_UI_PROMPT_SET_MASH_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_MODE);
		HUD.set_function("_UI_PROMPT_SET_MASH_INDEFINITELY_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_INDEFINITELY_MODE);
		HUD.set_function("_UI_PROMPT_SET_MASH_WITH_RESISTANCE_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_WITH_RESISTANCE_MODE);
		HUD.set_function("_UI_PROMPT_SET_MASH_WITH_RESISTANCE_CAN_FAIL_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_WITH_RESISTANCE_CAN_FAIL_MODE);
		HUD.set_function("_UI_PROMPT_SET_MASH_AUTO_FILL_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_AUTO_FILL_MODE);
		HUD.set_function("_UI_PROMPT_SET_MASH_MANUAL_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_MANUAL_MODE);
		HUD.set_function("_UI_PROMPT_SET_MASH_MANUAL_CAN_FAIL_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_MANUAL_CAN_FAIL_MODE);
		HUD.set_function("_UI_PROMPT_HAS_MANUAL_MASH_MODE", LUA_NATIVE_HUD__UI_PROMPT_HAS_MANUAL_MASH_MODE);
		HUD.set_function("_UI_PROMPT_HAS_MASH_MODE", LUA_NATIVE_HUD__UI_PROMPT_HAS_MASH_MODE);
		HUD.set_function("_0xB0E8599243B3F568", LUA_NATIVE_HUD__0xB0E8599243B3F568);
		HUD.set_function("_UI_PROMPT_HAS_MASH_MODE_COMPLETED", LUA_NATIVE_HUD__UI_PROMPT_HAS_MASH_MODE_COMPLETED);
		HUD.set_function("_UI_PROMPT_HAS_MASH_MODE_FAILED", LUA_NATIVE_HUD__UI_PROMPT_HAS_MASH_MODE_FAILED);
		HUD.set_function("_UI_PROMPT_GET_MASH_MODE_PROGRESS", LUA_NATIVE_HUD__UI_PROMPT_GET_MASH_MODE_PROGRESS);
		HUD.set_function("_UI_PROMPT_SET_MASH_MANUAL_MODE_INCREASE_PER_PRESS", LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_MANUAL_MODE_INCREASE_PER_PRESS);
		HUD.set_function("_UI_PROMPT_SET_MASH_MANUAL_MODE_DECAY_SPEED", LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_MANUAL_MODE_DECAY_SPEED);
		HUD.set_function("_UI_PROMPT_SET_MASH_MANUAL_MODE_PRESSED_GROWTH_SPEED", LUA_NATIVE_HUD__UI_PROMPT_SET_MASH_MANUAL_MODE_PRESSED_GROWTH_SPEED);
		HUD.set_function("_UI_PROMPT_SET_ROTATE_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_ROTATE_MODE);
		HUD.set_function("_UI_PROMPT_SET_TARGET_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_TARGET_MODE);
		HUD.set_function("_UI_PROMPT_SET_TARGET_MODE_TARGET", LUA_NATIVE_HUD__UI_PROMPT_SET_TARGET_MODE_TARGET);
		HUD.set_function("_UI_PROMPT_SET_TARGET_MODE_PROGRESS", LUA_NATIVE_HUD__UI_PROMPT_SET_TARGET_MODE_PROGRESS);
		HUD.set_function("_UI_PROMPT_SET_BEAT_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_BEAT_MODE);
		HUD.set_function("_UI_PROMPT_WAS_BEAT_MODE_PRESSED_IN_TIME_WINDOW", LUA_NATIVE_HUD__UI_PROMPT_WAS_BEAT_MODE_PRESSED_IN_TIME_WINDOW);
		HUD.set_function("_UI_PROMPT_SET_BEAT_MODE_GRAYED_OUT", LUA_NATIVE_HUD__UI_PROMPT_SET_BEAT_MODE_GRAYED_OUT);
		HUD.set_function("_UI_PROMPT_RESTART_MODES", LUA_NATIVE_HUD__UI_PROMPT_RESTART_MODES);
		HUD.set_function("_UI_PROMPT_SET_SPINNER_SPEED", LUA_NATIVE_HUD__UI_PROMPT_SET_SPINNER_SPEED);
		HUD.set_function("_UI_PROMPT_SET_SPINNER_POSITION", LUA_NATIVE_HUD__UI_PROMPT_SET_SPINNER_POSITION);
		HUD.set_function("_UI_PROMPT_SET_URGENT_PULSING_ENABLED", LUA_NATIVE_HUD__UI_PROMPT_SET_URGENT_PULSING_ENABLED);
		HUD.set_function("_UI_PROMPT_GET_URGENT_PULSING_ENABLED", LUA_NATIVE_HUD__UI_PROMPT_GET_URGENT_PULSING_ENABLED);
		HUD.set_function("_UI_PROMPT_SET_TAG", LUA_NATIVE_HUD__UI_PROMPT_SET_TAG);
		HUD.set_function("_UI_PROMPT_GET_GROUP_ID_FOR_TARGET_ENTITY", LUA_NATIVE_HUD__UI_PROMPT_GET_GROUP_ID_FOR_TARGET_ENTITY);
		HUD.set_function("_UI_PROMPT_GET_GROUP_ID_FOR_SCENARIO_POINT", LUA_NATIVE_HUD__UI_PROMPT_GET_GROUP_ID_FOR_SCENARIO_POINT);
		HUD.set_function("_UI_PROMPT_SET_GROUP", LUA_NATIVE_HUD__UI_PROMPT_SET_GROUP);
		HUD.set_function("_UI_PROMPT_REMOVE_GROUP", LUA_NATIVE_HUD__UI_PROMPT_REMOVE_GROUP);
		HUD.set_function("_UI_PROMPT_SET_ACTIVE_GROUP_THIS_FRAME", LUA_NATIVE_HUD__UI_PROMPT_SET_ACTIVE_GROUP_THIS_FRAME);
		HUD.set_function("_UI_PROMPT_GET_GROUP_ACTIVE_PAGE", LUA_NATIVE_HUD__UI_PROMPT_GET_GROUP_ACTIVE_PAGE);
		HUD.set_function("_UI_PROMPT_SET_AMBIENT_GROUP_THIS_FRAME", LUA_NATIVE_HUD__UI_PROMPT_SET_AMBIENT_GROUP_THIS_FRAME);
		HUD.set_function("_0x8B55B324A9123F6B", LUA_NATIVE_HUD__0x8B55B324A9123F6B);
		HUD.set_function("_UI_PROMPT_DOES_AMBIENT_GROUP_EXIST", LUA_NATIVE_HUD__UI_PROMPT_DOES_AMBIENT_GROUP_EXIST);
		HUD.set_function("_UI_PROMPT_ADD_GROUP_LINK", LUA_NATIVE_HUD__UI_PROMPT_ADD_GROUP_LINK);
		HUD.set_function("_UI_PROMPT_ADD_GROUP_RETURN_LINK", LUA_NATIVE_HUD__UI_PROMPT_ADD_GROUP_RETURN_LINK);
		HUD.set_function("_UI_PROMPT_SET_TRANSPORT_MODE", LUA_NATIVE_HUD__UI_PROMPT_SET_TRANSPORT_MODE);
		HUD.set_function("_UI_PROMPT_DISABLE_PROMPTS_THIS_FRAME", LUA_NATIVE_HUD__UI_PROMPT_DISABLE_PROMPTS_THIS_FRAME);
		HUD.set_function("_UI_PROMPT_DELETE", LUA_NATIVE_HUD__UI_PROMPT_DELETE);
		HUD.set_function("_UI_PROMPT_IS_VALID", LUA_NATIVE_HUD__UI_PROMPT_IS_VALID);
		HUD.set_function("_UI_PROMPT_IS_ACTIVE", LUA_NATIVE_HUD__UI_PROMPT_IS_ACTIVE);
		HUD.set_function("_UI_PROMPT_SET_VISIBLE", LUA_NATIVE_HUD__UI_PROMPT_SET_VISIBLE);
		HUD.set_function("_UI_PROMPT_SET_ENABLED", LUA_NATIVE_HUD__UI_PROMPT_SET_ENABLED);
		HUD.set_function("_UI_PROMPT_SET_TEXT", LUA_NATIVE_HUD__UI_PROMPT_SET_TEXT);
		HUD.set_function("_UI_PROMPT_SET_ATTRIBUTE", LUA_NATIVE_HUD__UI_PROMPT_SET_ATTRIBUTE);
		HUD.set_function("_UI_PROMPT_SET_TYPE", LUA_NATIVE_HUD__UI_PROMPT_SET_TYPE);
		HUD.set_function("_0x53CE46C01A089DA1", LUA_NATIVE_HUD__0x53CE46C01A089DA1);
		HUD.set_function("_UI_PROMPT_SET_MANUAL_RESOLVED", LUA_NATIVE_HUD__UI_PROMPT_SET_MANUAL_RESOLVED);
		HUD.set_function("_UI_PROMPT_CONTEXT_SET_VOLUME", LUA_NATIVE_HUD__UI_PROMPT_CONTEXT_SET_VOLUME);
		HUD.set_function("_UI_PROMPT_CONTEXT_SET_POINT", LUA_NATIVE_HUD__UI_PROMPT_CONTEXT_SET_POINT);
		HUD.set_function("_UI_PROMPT_CONTEXT_SET_RADIUS", LUA_NATIVE_HUD__UI_PROMPT_CONTEXT_SET_RADIUS);
		HUD.set_function("_UI_PROMPT_IS_PRESSED", LUA_NATIVE_HUD__UI_PROMPT_IS_PRESSED);
		HUD.set_function("_UI_PROMPT_IS_JUST_PRESSED", LUA_NATIVE_HUD__UI_PROMPT_IS_JUST_PRESSED);
		HUD.set_function("_UI_PROMPT_IS_JUST_RELEASED", LUA_NATIVE_HUD__UI_PROMPT_IS_JUST_RELEASED);
		HUD.set_function("_UI_PROMPT_IS_RELEASED", LUA_NATIVE_HUD__UI_PROMPT_IS_RELEASED);
		HUD.set_function("_UI_PROMPT_ENABLE_PROMPT_TYPE_THIS_FRAME", LUA_NATIVE_HUD__UI_PROMPT_ENABLE_PROMPT_TYPE_THIS_FRAME);
		HUD.set_function("_UI_PROMPT_DISABLE_PROMPT_TYPE_THIS_FRAME", LUA_NATIVE_HUD__UI_PROMPT_DISABLE_PROMPT_TYPE_THIS_FRAME);
		HUD.set_function("_UI_PROMPT_FILTER_CLEAR", LUA_NATIVE_HUD__UI_PROMPT_FILTER_CLEAR);
		HUD.set_function("_UI_PROMPT_SET_PROMPT_PRIORITY_PREFERENCE", LUA_NATIVE_HUD__UI_PROMPT_SET_PROMPT_PRIORITY_PREFERENCE);
		HUD.set_function("_UI_PROMPT_CLEAR_PROMPT_PRIORITY_PREFERENCE", LUA_NATIVE_HUD__UI_PROMPT_CLEAR_PROMPT_PRIORITY_PREFERENCE);
		HUD.set_function("_UI_PROMPT_IS_ENABLED", LUA_NATIVE_HUD__UI_PROMPT_IS_ENABLED);
		HUD.set_function("UI_PROMPT_IS_CONTROL_ACTION_ACTIVE", LUA_NATIVE_HUD_UI_PROMPT_IS_CONTROL_ACTION_ACTIVE);
		HUD.set_function("_0xD6BD313CFA41E57A", LUA_NATIVE_HUD__0xD6BD313CFA41E57A);
		HUD.set_function("_UI_PROMPT_SET_REGISTER_HORIZONTAL_ORIENTATION", LUA_NATIVE_HUD__UI_PROMPT_SET_REGISTER_HORIZONTAL_ORIENTATION);
		HUD.set_function("_UI_PROMPT_CLEAR_HORIZONTAL_ORIENTATION", LUA_NATIVE_HUD__UI_PROMPT_CLEAR_HORIZONTAL_ORIENTATION);
		HUD.set_function("_UI_PROMPT_SET_ORDERING_AS_INPUT_TYPE", LUA_NATIVE_HUD__UI_PROMPT_SET_ORDERING_AS_INPUT_TYPE);
		HUD.set_function("_0x066725A9D52B3641", LUA_NATIVE_HUD__0x066725A9D52B3641);
		HUD.set_function("_0x958278B97C4AFFD8", LUA_NATIVE_HUD__0x958278B97C4AFFD8);
		HUD.set_function("_CREATE_MP_GAMER_TAG", LUA_NATIVE_HUD__CREATE_MP_GAMER_TAG);
		HUD.set_function("CREATE_FAKE_MP_GAMER_TAG", LUA_NATIVE_HUD_CREATE_FAKE_MP_GAMER_TAG);
		HUD.set_function("_CREATE_MP_GAMER_TAG_ON_ENTITY", LUA_NATIVE_HUD__CREATE_MP_GAMER_TAG_ON_ENTITY);
		HUD.set_function("REMOVE_MP_GAMER_TAG", LUA_NATIVE_HUD_REMOVE_MP_GAMER_TAG);
		HUD.set_function("IS_MP_GAMER_TAG_ACTIVE", LUA_NATIVE_HUD_IS_MP_GAMER_TAG_ACTIVE);
		HUD.set_function("_IS_MP_GAMER_TAG_ACTIVE_ON_ENTITY", LUA_NATIVE_HUD__IS_MP_GAMER_TAG_ACTIVE_ON_ENTITY);
		HUD.set_function("_SET_MP_GAMER_TAG_VISIBILITY", LUA_NATIVE_HUD__SET_MP_GAMER_TAG_VISIBILITY);
		HUD.set_function("_SET_MP_GAMER_TAG_TYPE", LUA_NATIVE_HUD__SET_MP_GAMER_TAG_TYPE);
		HUD.set_function("_SET_MP_GAMER_TAG_COLOUR", LUA_NATIVE_HUD__SET_MP_GAMER_TAG_COLOUR);
		HUD.set_function("_SET_MP_GAMER_TAG_UNK_ALLOW_LOCALIZED", LUA_NATIVE_HUD__SET_MP_GAMER_TAG_UNK_ALLOW_LOCALIZED);
		HUD.set_function("SET_MP_GAMER_TAG_NAME", LUA_NATIVE_HUD_SET_MP_GAMER_TAG_NAME);
		HUD.set_function("_SET_MP_GAMER_TAG_NAME_POSSE", LUA_NATIVE_HUD__SET_MP_GAMER_TAG_NAME_POSSE);
		HUD.set_function("SET_MP_GAMER_TAG_BIG_TEXT", LUA_NATIVE_HUD_SET_MP_GAMER_TAG_BIG_TEXT);
		HUD.set_function("_SET_MP_GAMER_TAG_TOP_ICON", LUA_NATIVE_HUD__SET_MP_GAMER_TAG_TOP_ICON);
		HUD.set_function("_SET_MP_GAMER_TAG_SECONDARY_ICON", LUA_NATIVE_HUD__SET_MP_GAMER_TAG_SECONDARY_ICON);
		HUD.set_function("_MP_GAMER_TAG_ENABLE_REVIVE_TOP_ICON", LUA_NATIVE_HUD__MP_GAMER_TAG_ENABLE_REVIVE_TOP_ICON);
		HUD.set_function("_MP_GAMER_TAG_DISABLE_REVIVE_TOP_ICON", LUA_NATIVE_HUD__MP_GAMER_TAG_DISABLE_REVIVE_TOP_ICON);
	}
}
