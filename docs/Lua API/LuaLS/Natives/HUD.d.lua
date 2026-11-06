---@meta

---@class HUD
HUD = {}

function HUD._ENABLE_REDUCED_MENU_TIME_SCALE() end

function HUD._DISABLE_REDUCED_MENU_TIME_SCALE() end

---@param component integer
function HUD._ENABLE_HUD_CONTEXT_THIS_FRAME(component) end

---@param component integer
function HUD._ENABLE_HUD_CONTEXT(component) end

---@param component integer
function HUD._DISABLE_HUD_CONTEXT(component) end

---@param p0 integer
---@return integer
function HUD._0x7EC0D68233E391AC(p0) end

---@param text any
function HUD._BUSYSPINNER_SET_TEXT(text) end

function HUD.BUSYSPINNER_OFF() end

---@return boolean
function HUD.BUSYSPINNER_IS_ON() end

---@param pText any
---@param startPoint integer
---@param endPoint integer
---@return string
function HUD.GET_CHARACTER_FROM_AUDIO_CONVERSATION_FILENAME(pText, startPoint, endPoint) end

---@param pTextLabelOfAudioConversation any
---@return string
function HUD.GET_FILENAME_FOR_AUDIO_CONVERSATION(pTextLabelOfAudioConversation) end

function HUD.CLEAR_ALL_HELP_MESSAGES() end

---@param textBlock any
---@return boolean
function HUD.TEXT_BLOCK_IS_LOADED(textBlock) end

---@param textBlock any
---@return boolean
function HUD._TEXT_BLOCK_IS_STREAMED(textBlock) end

---@param textBlock any
function HUD.TEXT_BLOCK_REQUEST(textBlock) end

---@param textBlock any
function HUD._TEXT_BLOCK_DELETE(textBlock) end

---@param textDatabase any
---@return boolean
function HUD._DOES_TEXT_BLOCK_EXIST(textDatabase) end

---@param pTextLabel any
---@return boolean
function HUD.DOES_TEXT_LABEL_EXIST(pTextLabel) end

---@param label any
---@return string
function HUD._GET_LABEL_TEXT_2(label) end

---@param text any
---@param length integer
---@return string
function HUD._GET_TEXT_SUBSTRING_2(text, length) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function HUD._0x806862E5D266CF38(p0, p1, p2) end

---@param pLiteralString any
---@return integer
function HUD.GET_LENGTH_OF_LITERAL_STRING(pLiteralString) end

---@param pLiteralString any
---@return integer
function HUD.GET_LENGTH_OF_LITERAL_STRING_IN_BYTES(pLiteralString) end

---@param labelHash integer
---@return string
function HUD.GET_STRING_FROM_HASH_KEY(labelHash) end

---@return boolean
function HUD.IS_RADAR_PREFERENCE_SWITCHED_ON() end

---@return boolean
function HUD.IS_SUBTITLE_PREFERENCE_SWITCHED_ON() end

---@param bDisplayHudFlag boolean
function HUD.DISPLAY_HUD(bDisplayHudFlag) end

---@return boolean
function HUD.IS_HUD_HIDDEN() end

---@return boolean
function HUD.IS_RADAR_HIDDEN() end

---@return boolean
function HUD.IS_RADAR_HIDDEN_BY_SCRIPT() end

---@param colorNameHash integer
---@param red integer
---@param green integer
---@param blue integer
---@param alpha integer
---@return integer
---@return integer
---@return integer
---@return integer
function HUD._GET_COLOR_FROM_NAME(colorNameHash, red, green, blue, alpha) end

---@param text any
---@param xPos number
---@param yPos number
function HUD._DISPLAY_TEXT(text, xPos, yPos) end

---@param r integer
---@param g integer
---@param b integer
---@param a integer
function HUD._SET_TEXT_COLOR(r, g, b, a) end

---@param RenderIndex integer
function HUD.SET_TEXT_RENDER_ID(RenderIndex) end

---@param name any
---@param delay boolean
---@return boolean
function HUD.REGISTER_NAMED_RENDERTARGET(name, delay) end

---@param name any
---@return boolean
function HUD.IS_NAMED_RENDERTARGET_REGISTERED(name) end

---@param name any
---@return boolean
function HUD.RELEASE_NAMED_RENDERTARGET(name) end

---@param ModelHash integer
function HUD.LINK_NAMED_RENDERTARGET(ModelHash) end

---@param name any
---@return integer
function HUD.GET_NAMED_RENDERTARGET_RENDER_ID(name) end

---@param ModelHash integer
---@return boolean
function HUD.IS_NAMED_RENDERTARGET_LINKED(ModelHash) end

---@param p0 any
---@param p1 any
function HUD._0x9D37EB5003E0F2CF(p0, p1) end

function HUD.HIDE_LOADING_ON_FADE_THIS_FRAME() end

---@param p0 any
---@param p1 any
function HUD._0x052D4AC0922AF91A(p0, p1) end

function HUD.HIDE_HUD_AND_RADAR_THIS_FRAME() end

---@param p0 any
---@param p1 any
function HUD._0x8A59D44189AF2BC5(p0, p1) end

function HUD._0x160825DADF1B04B3() end

---@return any
function HUD._0x9C409BBC492CB5B1() end

---@param p0 any
---@return any
function HUD._0x0501D52D24EA8934(p0) end

---@param p0 any
---@param p1 any
---@return any
function HUD._0x100157D6D7FE32CA(p0, p1) end

---@param p0 any
---@return any
function HUD._0x28AE29D909C8FDCE(p0) end

function HUD._0x2F7BB105144ACF30() end

function HUD._0xBFFF81E12A745A5F() end

---@param bActive boolean
---@param pTextLabel any
function HUD.SET_MISSION_NAME(bActive, pTextLabel) end

---@param bActive boolean
---@param pMissionName any
function HUD.SET_MISSION_NAME_FOR_UGC_MISSION(bActive, pMissionName) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function HUD._0xCE0D2F5586627CCE(p0, p1, p2, p3, p4) end

---@param vWorldPosX number
---@param vWorldPosY number
---@param vWorldPosZ number
---@param fScreenPosX number
---@param fScreenPosY number
---@return integer
---@return number
---@return number
function HUD.GET_HUD_SCREEN_POSITION_FROM_WORLD_POSITION(vWorldPosX, vWorldPosY, vWorldPosZ, fScreenPosX, fScreenPosY) end

function HUD._HIDE_HUD_THIS_FRAME() end

function HUD.DISABLE_FRONTEND_THIS_FRAME() end

function HUD._0x5651516D947ABC53() end

function HUD.ALLOW_PAUSE_WHEN_NOT_IN_STATE_OF_PLAY_THIS_FRAME() end

---@param bActive boolean
function HUD.SET_FRONTEND_ACTIVE(bActive) end

---@return boolean
function HUD.IS_PAUSE_MENU_ACTIVE() end

---@param state boolean
function HUD._SHOW_PLAYER_CORES(state) end

---@param state boolean
function HUD._SHOW_HORSE_CORES(state) end

---@param p0 any
function HUD._0x3FE4FB41EF7D2196(p0) end

---@param p0 any
function HUD._JOURNAL_WRITE_ENTRY(p0) end

---@param p0 any
---@return any
function HUD._JOURNAL_CAN_WRITE_ENTRY(p0) end

---@return any
function HUD._JOURNAL_GET_ENTRY_COUNT() end

---@param p0 any
---@return any
function HUD._JOURNAL_GET_ENTRY_AT_INDEX(p0) end

---@param p0 any
---@return any
function HUD._JOURNAL_GET_GRIME_AT_INDEX(p0) end

---@param p0 any
---@param p1 any
---@return any
function HUD._JOURNAL_GET_ENTRY_INFO(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function HUD._JOURNAL_GET_TEXTURE_WITH_LAYOUT(p0, p1, p2) end

---@param p0 any
function HUD._JOURNAL_MARK_READ(p0) end

function HUD._JOURNAL_CLEAR_ALL_PROGRESS() end

---@param p0 any
---@param p1 any
---@return any
function HUD.UI_REQUEST_SCENE(p0, p1) end

---@param uiscene integer
function HUD._0xF1E6979C0B779985(uiscene) end

---@param p0 any
---@return any
function HUD.UI_GET_SCENE_UIOBJECT(p0) end

---@param p0 any
---@param p1 any
function HUD.UI_MOVIEVIEW_SET_RENDER_TARGET(p0, p1) end

---@param inputHash integer
---@param labelName any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 integer
---@return integer
function HUD._UI_PROMPT_CREATE(inputHash, labelName, p2, p3, p4, p5) end

---@return integer
function HUD._UI_PROMPT_REGISTER_BEGIN() end

---@param prompt integer
function HUD._UI_PROMPT_REGISTER_END(prompt) end

---@param prompt integer
---@param priority integer
function HUD._UI_PROMPT_SET_PRIORITY(prompt, priority) end

---@param prompt integer
---@param action integer
---@return any
function HUD._UI_PROMPT_SET_CONTROL_ACTION(prompt, action) end

---@param prompt integer
---@param action integer
function HUD._UI_PROMPT_SET_ALLOWED_ACTION(prompt, action) end

---@param prompt integer
---@param releaseMode boolean
function HUD._UI_PROMPT_SET_STANDARD_MODE(prompt, releaseMode) end

---@param prompt integer
---@param p1 integer
---@return boolean
function HUD._UI_PROMPT_HAS_STANDARD_MODE_COMPLETED(prompt, p1) end

---@param prompt integer
---@param depletionTimeMs integer
function HUD._UI_PROMPT_SET_PRESSED_TIMED_MODE(prompt, depletionTimeMs) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_HAS_PRESSED_TIMED_MODE_COMPLETED(prompt) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_HAS_PRESSED_TIMED_MODE_FAILED(prompt) end

---@param prompt integer
---@param holdTimeMs integer
function HUD._UI_PROMPT_SET_HOLD_MODE(prompt, holdTimeMs) end

---@param prompt integer
---@param timedEventHash integer
function HUD._UI_PROMPT_SET_STANDARDIZED_HOLD_MODE(prompt, timedEventHash) end

---@param prompt integer
function HUD._UI_PROMPT_SET_HOLD_INDEFINITELY_MODE(prompt) end

---@param prompt integer
---@param autoFillTimeMs integer
---@param holdTimeMs integer
function HUD._UI_PROMPT_SET_HOLD_AUTO_FILL_MODE(prompt, autoFillTimeMs, holdTimeMs) end

---@param prompt integer
---@param autoFillTimeMs integer
---@param holdTimeMs integer
function HUD._UI_PROMPT_SET_HOLD_AUTO_FILL_WITH_DECAY_MODE(prompt, autoFillTimeMs, holdTimeMs) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_HAS_HOLD_AUTO_FILL_MODE(prompt) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_HAS_HOLD_MODE(prompt) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_IS_HOLD_MODE_RUNNING(prompt) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_HAS_HOLD_MODE_COMPLETED(prompt) end

---@param prompt integer
---@return number
function HUD._UI_PROMPT_GET_PROGRESS(prompt) end

---@param prompt integer
---@param mashes integer
function HUD._UI_PROMPT_SET_MASH_MODE(prompt, mashes) end

---@param prompt integer
function HUD._UI_PROMPT_SET_MASH_INDEFINITELY_MODE(prompt) end

---@param prompt integer
---@param mashes integer
---@param p2 number
---@param p3 number
function HUD._UI_PROMPT_SET_MASH_WITH_RESISTANCE_MODE(prompt, mashes, p2, p3) end

---@param prompt integer
---@param mashes integer
---@param p2 number
---@param p3 number
function HUD._UI_PROMPT_SET_MASH_WITH_RESISTANCE_CAN_FAIL_MODE(prompt, mashes, p2, p3) end

---@param prompt integer
---@param autoFillTimeMs integer
---@param mashes integer
function HUD._UI_PROMPT_SET_MASH_AUTO_FILL_MODE(prompt, autoFillTimeMs, mashes) end

---@param prompt integer
---@param p1 number
---@param p2 number
---@param p3 number
---@param p4 any
function HUD._UI_PROMPT_SET_MASH_MANUAL_MODE(prompt, p1, p2, p3, p4) end

---@param prompt integer
---@param p1 number
---@param p2 number
---@param p3 number
---@param p4 any
function HUD._UI_PROMPT_SET_MASH_MANUAL_CAN_FAIL_MODE(prompt, p1, p2, p3, p4) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_HAS_MANUAL_MASH_MODE(prompt) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_HAS_MASH_MODE(prompt) end

---@param p0 any
---@return any
function HUD._0xB0E8599243B3F568(p0) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_HAS_MASH_MODE_COMPLETED(prompt) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_HAS_MASH_MODE_FAILED(prompt) end

---@param prompt integer
---@return number
function HUD._UI_PROMPT_GET_MASH_MODE_PROGRESS(prompt) end

---@param prompt integer
---@param rate number
function HUD._UI_PROMPT_SET_MASH_MANUAL_MODE_INCREASE_PER_PRESS(prompt, rate) end

---@param prompt integer
---@param speed number
function HUD._UI_PROMPT_SET_MASH_MANUAL_MODE_DECAY_SPEED(prompt, speed) end

---@param prompt integer
---@param speed number
function HUD._UI_PROMPT_SET_MASH_MANUAL_MODE_PRESSED_GROWTH_SPEED(prompt, speed) end

---@param prompt integer
---@param p1 number
---@param counterclockwise boolean
function HUD._UI_PROMPT_SET_ROTATE_MODE(prompt, p1, counterclockwise) end

---@param prompt integer
---@param p1 number
---@param p2 number
---@param p3 any
function HUD._UI_PROMPT_SET_TARGET_MODE(prompt, p1, p2, p3) end

---@param prompt integer
---@param p1 number
---@param p2 number
function HUD._UI_PROMPT_SET_TARGET_MODE_TARGET(prompt, p1, p2) end

---@param prompt integer
---@param progress number
function HUD._UI_PROMPT_SET_TARGET_MODE_PROGRESS(prompt, progress) end

---@param prompt integer
---@param toggle boolean
function HUD._UI_PROMPT_SET_BEAT_MODE(prompt, toggle) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_WAS_BEAT_MODE_PRESSED_IN_TIME_WINDOW(prompt) end

---@param prompt integer
---@param p1 any
function HUD._UI_PROMPT_SET_BEAT_MODE_GRAYED_OUT(prompt, p1) end

---@param prompt integer
function HUD._UI_PROMPT_RESTART_MODES(prompt) end

---@param prompt integer
---@param p1 any
function HUD._UI_PROMPT_SET_SPINNER_SPEED(prompt, p1) end

---@param prompt integer
---@param p1 any
function HUD._UI_PROMPT_SET_SPINNER_POSITION(prompt, p1) end

---@param prompt integer
---@param toggle boolean
function HUD._UI_PROMPT_SET_URGENT_PULSING_ENABLED(prompt, toggle) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_GET_URGENT_PULSING_ENABLED(prompt) end

---@param prompt integer
---@param p1 any
function HUD._UI_PROMPT_SET_TAG(prompt, p1) end

---@param entity integer
---@return integer
function HUD._UI_PROMPT_GET_GROUP_ID_FOR_TARGET_ENTITY(entity) end

---@param p0 any
---@param p1 integer
---@return integer
function HUD._UI_PROMPT_GET_GROUP_ID_FOR_SCENARIO_POINT(p0, p1) end

---@param prompt integer
---@param groupId integer
---@param tabIndex integer
function HUD._UI_PROMPT_SET_GROUP(prompt, groupId, tabIndex) end

---@param prompt integer
---@param p1 any
function HUD._UI_PROMPT_REMOVE_GROUP(prompt, p1) end

---@param hash integer
---@param name any
---@param tabAmount integer
---@param tabDefaultIndex integer
---@param p4 integer
---@param prompt integer
---@return any
function HUD._UI_PROMPT_SET_ACTIVE_GROUP_THIS_FRAME(hash, name, tabAmount, tabDefaultIndex, p4, prompt) end

---@param hash integer
---@return integer
function HUD._UI_PROMPT_GET_GROUP_ACTIVE_PAGE(hash) end

---@param entity integer
---@param p1 number
---@param p2 integer
---@param p3 integer
---@param p4 integer
---@param name any
---@param p6 integer
---@return any
function HUD._UI_PROMPT_SET_AMBIENT_GROUP_THIS_FRAME(entity, p1, p2, p3, p4, name, p6) end

---@param groupId integer
---@param volume integer
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@return any
function HUD._0x8B55B324A9123F6B(groupId, volume, p2, p3, p4, p5) end

---@param hash integer
---@return boolean
function HUD._UI_PROMPT_DOES_AMBIENT_GROUP_EXIST(hash) end

---@param p0 any
---@param prompt integer
---@param p2 any
function HUD._UI_PROMPT_ADD_GROUP_LINK(p0, prompt, p2) end

---@param p0 any
---@param prompt integer
function HUD._UI_PROMPT_ADD_GROUP_RETURN_LINK(p0, prompt) end

---@param prompt integer
---@param mode integer
function HUD._UI_PROMPT_SET_TRANSPORT_MODE(prompt, mode) end

function HUD._UI_PROMPT_DISABLE_PROMPTS_THIS_FRAME() end

---@param prompt integer
function HUD._UI_PROMPT_DELETE(prompt) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_IS_VALID(prompt) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_IS_ACTIVE(prompt) end

---@param prompt integer
---@param toggle boolean
function HUD._UI_PROMPT_SET_VISIBLE(prompt, toggle) end

---@param prompt integer
---@param toggle boolean
function HUD._UI_PROMPT_SET_ENABLED(prompt, toggle) end

---@param prompt integer
---@param text any
function HUD._UI_PROMPT_SET_TEXT(prompt, text) end

---@param prompt integer
---@param attribute integer
---@param enabled boolean
function HUD._UI_PROMPT_SET_ATTRIBUTE(prompt, attribute, enabled) end

---@param prompt integer
---@param type integer
function HUD._UI_PROMPT_SET_TYPE(prompt, type) end

---@param prompt integer
---@param p1 boolean
function HUD._0x53CE46C01A089DA1(prompt, p1) end

---@param prompt integer
---@param p1 any
function HUD._UI_PROMPT_SET_MANUAL_RESOLVED(prompt, p1) end

---@param prompt integer
---@param volume integer
function HUD._UI_PROMPT_CONTEXT_SET_VOLUME(prompt, volume) end

---@param prompt integer
---@param x number
---@param y number
---@param z number
function HUD._UI_PROMPT_CONTEXT_SET_POINT(prompt, x, y, z) end

---@param prompt integer
---@param radius number
function HUD._UI_PROMPT_CONTEXT_SET_RADIUS(prompt, radius) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_IS_PRESSED(prompt) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_IS_JUST_PRESSED(prompt) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_IS_JUST_RELEASED(prompt) end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_IS_RELEASED(prompt) end

---@param p0 integer
function HUD._UI_PROMPT_ENABLE_PROMPT_TYPE_THIS_FRAME(p0) end

---@param p0 integer
function HUD._UI_PROMPT_DISABLE_PROMPT_TYPE_THIS_FRAME(p0) end

function HUD._UI_PROMPT_FILTER_CLEAR() end

---@param ped integer
function HUD._UI_PROMPT_SET_PROMPT_PRIORITY_PREFERENCE(ped) end

function HUD._UI_PROMPT_CLEAR_PROMPT_PRIORITY_PREFERENCE() end

---@param prompt integer
---@return boolean
function HUD._UI_PROMPT_IS_ENABLED(prompt) end

---@param controlAction integer
---@return boolean
function HUD.UI_PROMPT_IS_CONTROL_ACTION_ACTIVE(controlAction) end

---@param p0 any
---@return any
function HUD._0xD6BD313CFA41E57A(p0) end

---@return integer
function HUD._UI_PROMPT_SET_REGISTER_HORIZONTAL_ORIENTATION() end

---@param id integer
function HUD._UI_PROMPT_CLEAR_HORIZONTAL_ORIENTATION(id) end

---@param prompt integer
---@param p1 any
function HUD._UI_PROMPT_SET_ORDERING_AS_INPUT_TYPE(prompt, p1) end

---@return any
function HUD._0x066725A9D52B3641() end

---@param p0 any
---@param p1 any
function HUD._0x958278B97C4AFFD8(p0, p1) end

---@param player integer
---@param username any
---@param pointedClanTag boolean
---@param isRockstarClan boolean
---@param clanTag any
---@param clanFlag integer
---@return integer
function HUD._CREATE_MP_GAMER_TAG(player, username, pointedClanTag, isRockstarClan, clanTag, clanFlag) end

---@param ped integer
---@param PlayerName any
---@param bCrewTypeIsPrivate boolean
---@param bCrewTagContainsRockstar boolean
---@param CrewTag any
---@param iCrewRank integer
---@return integer
function HUD.CREATE_FAKE_MP_GAMER_TAG(ped, PlayerName, bCrewTypeIsPrivate, bCrewTagContainsRockstar, CrewTag, iCrewRank) end

---@param entity integer
---@param text any
---@return integer
function HUD._CREATE_MP_GAMER_TAG_ON_ENTITY(entity, text) end

---@param iPlayerNum integer
function HUD.REMOVE_MP_GAMER_TAG(iPlayerNum) end

---@param iPlayerNum integer
---@return boolean
function HUD.IS_MP_GAMER_TAG_ACTIVE(iPlayerNum) end

---@param gamerTagId integer
---@param entity integer
---@return boolean
function HUD._IS_MP_GAMER_TAG_ACTIVE_ON_ENTITY(gamerTagId, entity) end

---@param gamerTagId integer
---@param visibility integer
function HUD._SET_MP_GAMER_TAG_VISIBILITY(gamerTagId, visibility) end

---@param gamerTagId integer
---@param type integer
function HUD._SET_MP_GAMER_TAG_TYPE(gamerTagId, type) end

---@param gamerTagId integer
---@param colour integer
function HUD._SET_MP_GAMER_TAG_COLOUR(gamerTagId, colour) end

---@param gamerTagId integer
---@param allow boolean
function HUD._SET_MP_GAMER_TAG_UNK_ALLOW_LOCALIZED(gamerTagId, allow) end

---@param iPlayerNum integer
---@param PlayerName any
function HUD.SET_MP_GAMER_TAG_NAME(iPlayerNum, PlayerName) end

---@param gamerTagId integer
---@param text any
function HUD._SET_MP_GAMER_TAG_NAME_POSSE(gamerTagId, text) end

---@param iPlayerNum integer
---@param BigText any
function HUD.SET_MP_GAMER_TAG_BIG_TEXT(iPlayerNum, BigText) end

---@param gamerTagId integer
---@param icon integer
function HUD._SET_MP_GAMER_TAG_TOP_ICON(gamerTagId, icon) end

---@param gamerTagId integer
---@param icon integer
function HUD._SET_MP_GAMER_TAG_SECONDARY_ICON(gamerTagId, icon) end

---@param gamerTagId integer
function HUD._MP_GAMER_TAG_ENABLE_REVIVE_TOP_ICON(gamerTagId) end

---@param gamerTagId integer
function HUD._MP_GAMER_TAG_DISABLE_REVIVE_TOP_ICON(gamerTagId) end
