---@meta

---@class ANIMSCENE
ANIMSCENE = {}

---@param animDict any
---@param flags integer
---@param playbackListName any
---@param p3 boolean
---@param p4 boolean
---@return integer
function ANIMSCENE._CREATE_ANIM_SCENE(animDict, flags, playbackListName, p3, p4) end

---@param animScene integer
function ANIMSCENE._DELETE_ANIM_SCENE(animScene) end

---@param animScene integer
function ANIMSCENE.TRIGGER_ANIM_SCENE_SKIP(animScene) end

---@param animScene integer
---@return boolean
function ANIMSCENE._0x4B85B3CF91972222(animScene) end

---@param animScene integer
function ANIMSCENE._CLEAR_ANIM_SCENE_WAS_SKIPPED(animScene) end

---@param animScene integer
---@return boolean
function ANIMSCENE.DOES_ANIM_SCENE_EXIST(animScene) end

---@param animScene integer
---@param entityId any
---@return boolean
function ANIMSCENE._DOES_ENTITY_WITH_ID_EXIST_IN_ANIM_SCENE(animScene, entityId) end

---@param animScene integer
---@param entityName any
---@return boolean
function ANIMSCENE._DOES_ANIM_SCENE_OWNERSHIP_OF_ENTITY_EXIST(animScene, entityName) end

---@param animScene integer
function ANIMSCENE.LOAD_ANIM_SCENE(animScene) end

---@param animScene integer
---@param p1 boolean
---@param p2 boolean
---@return boolean
function ANIMSCENE.IS_ANIM_SCENE_LOADED(animScene, p1, p2) end

---@param animScene integer
---@param p1 boolean
---@return boolean
function ANIMSCENE._IS_ANIM_SCENE_LOADING(animScene, p1) end

---@param animScene integer
---@param p1 boolean
---@return boolean
function ANIMSCENE._IS_ANIM_SCENE_METADATA_ASSET_IN_RANGE_LOADING(animScene, p1) end

---@param animScene integer
---@param p1 boolean
---@return boolean
function ANIMSCENE.IS_ANIM_SCENE_METADATA_LOADED(animScene, p1) end

---@param animScene integer
---@param phaseName any
---@return integer
function ANIMSCENE._GET_ANIM_SCENE_PLAYBACK_LIST_PHASE_AUDIO_LOAD_STRESS(animScene, phaseName) end

---@param animScene integer
function ANIMSCENE.START_ANIM_SCENE(animScene) end

---@param animScene integer
---@param playbackListName any
function ANIMSCENE.RESET_ANIM_SCENE(animScene, playbackListName) end

---@param animScene integer
---@param p1 boolean
function ANIMSCENE.ABORT_ANIM_SCENE(animScene, p1) end

---@param animScene integer
function ANIMSCENE.RESUME_ANIM_SCENE_FROM_LAST_CHECKPOINT(animScene) end

---@param animScene integer
---@param p1 boolean
---@return boolean
function ANIMSCENE.IS_ANIM_SCENE_RUNNING(animScene, p1) end

---@param animScene integer
---@param p1 boolean
---@return boolean
function ANIMSCENE.IS_ANIM_SCENE_FINISHED(animScene, p1) end

---@param animScene integer
---@return boolean
function ANIMSCENE.IS_ANIM_SCENE_EXITING_THIS_FRAME(animScene) end

---@param animScene integer
---@param p1 boolean
---@return boolean
function ANIMSCENE.HAS_ANIM_SCENE_EXITED(animScene, p1) end

---@param animScene integer
---@param p1 boolean
---@return boolean
function ANIMSCENE._0x73616E64696C132E(animScene, p1) end

---@param animScene integer
---@param sectionName any
---@param p2 boolean
---@return boolean
function ANIMSCENE.IS_ANIM_SCENE_IN_SECTION(animScene, sectionName, p2) end

---@param animScene integer
---@return boolean
function ANIMSCENE._IS_ANIM_SCENE_SKIPPABLE(animScene) end

---@param animScene integer
---@return boolean
function ANIMSCENE._IS_ANIM_SCENE_ABORTED(animScene) end

---@param animScene integer
---@return boolean
function ANIMSCENE._0xD70C7A30412F8FA0(animScene) end

---@param animScene integer
---@return boolean
function ANIMSCENE._0x9AAE3C1148A09BCA(animScene) end

---@param animScene integer
---@return boolean
function ANIMSCENE._0xA96619FE85159ED2(animScene) end

---@param animScene integer
---@param p1 number
function ANIMSCENE.FADE_ANIM_SCENE_AUDIO_IN(animScene, p1) end

---@param animScene integer
---@param p1 number
function ANIMSCENE.FADE_ANIM_SCENE_AUDIO_OUT(animScene, p1) end

---@param p0 boolean
---@param p1 boolean
function ANIMSCENE.BLOCK_ANIM_SCENE_FADING_NEXT_FRAME(p0, p1) end

---@param animScene integer
---@param posX number
---@param posY number
---@param posZ number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param order integer
function ANIMSCENE.SET_ANIM_SCENE_ORIGIN(animScene, posX, posY, posZ, rotX, rotY, rotZ, order) end

---@param animScene integer
---@param position Vector3
---@param rotation Vector3
---@param order integer
---@return Vector3
---@return Vector3
function ANIMSCENE.GET_ANIM_SCENE_ORIGIN(animScene, position, rotation, order) end

---@param animScene integer
---@param toggle boolean
function ANIMSCENE.SET_ANIM_SCENE_PAUSED(animScene, toggle) end

---@param animScene integer
---@return boolean
function ANIMSCENE._IS_ANIM_SCENE_PAUSED(animScene) end

---@param animScene integer
---@param rate number
function ANIMSCENE.SET_ANIM_SCENE_RATE(animScene, rate) end

---@param animScene integer
---@return number
function ANIMSCENE._GET_ANIM_SCENE_RATE(animScene) end

---@param animScene integer
---@return number
function ANIMSCENE.GET_ANIM_SCENE_PHASE(animScene) end

---@param animScene integer
---@return number
function ANIMSCENE._GET_ANIM_SCENE_TIME(animScene) end

---@param animScene integer
---@return number
function ANIMSCENE._GET_ANIM_SCENE_DURATION(animScene) end

---@param animScene integer
---@param entityName any
---@param entity integer
---@param flags integer
function ANIMSCENE.SET_ANIM_SCENE_ENTITY(animScene, entityName, entity, flags) end

---@param animScene integer
---@param entityName any
---@param entity integer
function ANIMSCENE.REMOVE_ANIM_SCENE_ENTITY(animScene, entityName, entity) end

---@param animScene integer
---@param entityName any
---@return boolean
function ANIMSCENE.IS_ENTITY_EXITING_ANIM_SCENE_THIS_FRAME(animScene, entityName) end

---@param animScene integer
---@param entityName any
---@param p2 any
---@param p3 any
---@return boolean
function ANIMSCENE.COULD_ANIM_SCENE_ENTITY_REACH_EXIT_NEXT_FRAME(animScene, entityName, p2, p3) end

---@param animScene integer
---@param entityName any
---@return boolean
function ANIMSCENE.HAS_ENTITY_EXITED_ANIM_SCENE(animScene, entityName) end

---@param animScene integer
---@param entityName any
---@return boolean
function ANIMSCENE._HAS_ENTITY_ENTERED_ANIM_SCENE(animScene, entityName) end

---@param animScene integer
---@param name any
---@param isNetwork boolean
---@return integer
function ANIMSCENE._GET_ANIM_SCENE_PED(animScene, name, isNetwork) end

---@param animScene integer
---@param name any
---@param isNetwork boolean
---@return integer
function ANIMSCENE._GET_ANIM_SCENE_OBJECT(animScene, name, isNetwork) end

---@param animScene integer
---@param name any
---@param isNetwork boolean
---@return integer
function ANIMSCENE._GET_ANIM_SCENE_VEHICLE(animScene, name, isNetwork) end

---@param animScene integer
---@param name any
---@param value boolean
---@param p3 boolean
function ANIMSCENE.SET_ANIM_SCENE_BOOL(animScene, name, value, p3) end

---@param animScene integer
---@param name any
---@return boolean
function ANIMSCENE.GET_ANIM_SCENE_BOOL(animScene, name) end

---@param animScene integer
---@param name any
---@param value number
---@param p3 boolean
---@param p4 boolean
function ANIMSCENE.SET_ANIM_SCENE_FLOAT(animScene, name, value, p3, p4) end

---@param animScene integer
---@param name any
---@return number
function ANIMSCENE.GET_ANIM_SCENE_FLOAT(animScene, name) end

---@param animScene integer
---@param name any
---@param value integer
---@param p3 boolean
function ANIMSCENE.SET_ANIM_SCENE_INT(animScene, name, value, p3) end

---@param animScene integer
---@param name any
---@return integer
function ANIMSCENE.GET_ANIM_SCENE_INT(animScene, name) end

---@param animScene integer
---@param entityName any
---@param matrix Vector3
---@param p3 boolean
---@param playbackListName any
---@param p5 integer
---@return boolean
---@return Vector3
function ANIMSCENE.GET_ANIM_SCENE_ENTITY_LOCATION_DATA(animScene, entityName, matrix, p3, playbackListName, p5) end

---@param entity integer
---@param animScene integer
---@return boolean
function ANIMSCENE.IS_ENTITY_PLAYING_ANIM_SCENE(entity, animScene) end

---@param animScene integer
---@param entity integer
---@param p2 integer
function ANIMSCENE.ATTACH_ANIM_SCENE_TO_ENTITY(animScene, entity, p2) end

---@param animScene integer
---@param entity integer
---@param p2 integer
function ANIMSCENE.ATTACH_ANIM_SCENE_TO_ENTITY_PRESERVING_LOCATION(animScene, entity, p2) end

---@param animScene integer
function ANIMSCENE.DETACH_ANIM_SCENE(animScene) end

---@param animScene integer
function ANIMSCENE.DETACH_ANIM_SCENE_PRESERVING_LOCATION(animScene) end

---@param animScene integer
function ANIMSCENE.TAKE_OWNERSHIP_OF_ANIM_SCENE(animScene) end

---@param animScene integer
---@return boolean
function ANIMSCENE.CHECK_OWNERSHIP_OF_ANIM_SCENE(animScene) end

---@param animScene integer
---@param playbackListName any
function ANIMSCENE.SET_ANIM_SCENE_PLAYBACK_LIST(animScene, playbackListName) end

---@param animScene integer
---@param phaseName any
---@return boolean
function ANIMSCENE._0x1C5D33A4293E6DDE(animScene, phaseName) end

---@param animScene integer
---@param playbackListName any
---@return boolean
function ANIMSCENE._DOES_ANIM_SCENE_PLAY_LIST_EXIST(animScene, playbackListName) end

---@param animScene integer
---@param playlistName any
---@param p2 boolean
function ANIMSCENE.SET_ANIM_SCENE_PLAY_LIST(animScene, playlistName, p2) end

---@param animScene integer
---@param phaseName any
---@return boolean
function ANIMSCENE._IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_ACTIVE(animScene, phaseName) end

---@param animScene integer
---@param playlistName any
---@return boolean
function ANIMSCENE.REQUEST_ANIM_SCENE_PLAY_LIST(animScene, playlistName) end

---@param animScene integer
---@param playlistName any
---@return boolean
function ANIMSCENE._RELEASE_ANIM_SCENE_PLAY_LIST(animScene, playlistName) end

---@param animScene integer
---@return integer
function ANIMSCENE._GET_ANIM_SCENE_DICT(animScene) end

---@param animScene integer
---@param p1 any
---@return boolean
function ANIMSCENE._0x1407F5115FB9583E(animScene, p1) end

---@param animScene integer
---@param phaseName any
---@return boolean
function ANIMSCENE._IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_LOADED(animScene, phaseName) end

---@param animScene integer
---@param phaseName any
---@return boolean
function ANIMSCENE._IS_ANIM_SCENE_PLAYBACK_LIST_PHASE_LOADING(animScene, phaseName) end

function ANIMSCENE._0x1AD896BF43619551() end

---@param animScene integer
---@return integer
function ANIMSCENE.GET_ANIM_SCENE_CURRENT_ACTIVE_CAMERA_COUNT(animScene) end

---@param p0 any
---@return boolean
function ANIMSCENE._0x5D7BFDA2290B4E39(p0) end

---@param mgmFilename any
---@return boolean
function ANIMSCENE._IS_MGM_SYSTEM_LOADED(mgmFilename) end

---@param mgmFilename any
---@return boolean
function ANIMSCENE._LOAD_MGM_ASSETS(mgmFilename) end

---@param mgmFilename any
---@return integer
function ANIMSCENE._CREATE_MGM_SYSTEM(mgmFilename) end

---@param mgmHandle integer
function ANIMSCENE._DELETE_MGM_SYSTEM(mgmHandle) end

---@param mgmHandle integer
---@param ped integer
function ANIMSCENE._0xB1A196BAFE650402(mgmHandle, ped) end

---@param mgmHandle integer
---@param ped integer
function ANIMSCENE._0xAE6DE22DE0ED4554(mgmHandle, ped) end

---@param mgmEventHandle integer
---@param p1 any
---@param seatId integer
---@param p3 integer
---@param p4 boolean
---@return boolean
function ANIMSCENE._0x61B2AAEF645DDAF0(mgmEventHandle, p1, seatId, p3, p4) end

---@param mgmEventHandle integer
---@param p1 any
---@param seatId any
---@param p3 integer
---@param p4 number
function ANIMSCENE._SET_MGM_EVENT(mgmEventHandle, p1, seatId, p3, p4) end

---@param mgmHandle integer
---@param ped integer
---@param secondaryVoiceString any
function ANIMSCENE._0x3641FCD53E59B335(mgmHandle, ped, secondaryVoiceString) end

---@param ped integer
---@param archetype any
function ANIMSCENE._SET_BREAKOUT_ARCHETYPE(ped, archetype) end

---@param ped integer
function ANIMSCENE._CLEAR_BREAKOUT_ARCHETYPE(ped) end

---@param ped integer
---@return boolean
function ANIMSCENE._0x3B393716C3FD8237(ped) end

function ANIMSCENE._0xE12D7B4B959644CD() end

---@param entity integer
---@param p1 boolean
function ANIMSCENE._0xC1193521E3B9FADD(entity, p1) end

function ANIMSCENE._REQUEST_PHOTO_MODE_FREEZE() end

function ANIMSCENE._REQUEST_PHOTO_MODE_DEFREEZE() end

---@return boolean
function ANIMSCENE._0x2DB524750DC41ED4() end

---@return boolean
function ANIMSCENE._0xEA41D44A8D42057B() end

---@param toggle boolean
function ANIMSCENE._PAUSE_SCRIPT_THREADS(toggle) end

---@param p0 boolean
function ANIMSCENE._0xCDCD7B2D49AEE73A(p0) end

---@param animScene integer
---@return boolean
function ANIMSCENE.WAS_ANIM_SCENE_SKIPPED(animScene) end
