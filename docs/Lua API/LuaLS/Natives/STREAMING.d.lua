---@meta

---@class STREAMING
STREAMING = {}

---@param ModelIndex integer
---@param p1 boolean
function STREAMING.REQUEST_MODEL(ModelIndex, p1) end

---@param ModelIndex integer
---@return boolean
function STREAMING.HAS_MODEL_LOADED(ModelIndex) end

---@param ModelIndex integer
function STREAMING.SET_MODEL_AS_NO_LONGER_NEEDED(ModelIndex) end

---@param ModelIndex integer
---@return boolean
function STREAMING.IS_MODEL_IN_CDIMAGE(ModelIndex) end

---@param modelHash integer
---@return boolean
function STREAMING.IS_MODEL_VALID(modelHash) end

---@param model integer
---@return boolean
function STREAMING.IS_MODEL_A_PED(model) end

---@param ModelHashKey integer
---@return boolean
function STREAMING.IS_MODEL_A_VEHICLE(ModelHashKey) end

---@param model integer
---@return boolean
function STREAMING._IS_MODEL_AN_OBJECT(model) end

---@param x number
---@param y number
---@param z number
---@return boolean
function STREAMING._HAS_COLLISION_LOADED_AT_COORD(x, y, z) end

function STREAMING._0x80B3E0597366ADF1() end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
function STREAMING.REQUEST_COLLISION_AT_COORD(VecCoorsX, VecCoorsY, VecCoorsZ) end

---@param x number
---@param y number
---@param z number
function STREAMING._REQUEST_METADATA_AT_COORD(x, y, z) end

---@param ModelIndex integer
function STREAMING.REQUEST_COLLISION_FOR_MODEL(ModelIndex) end

---@param ModelIndex integer
---@return boolean
function STREAMING.HAS_COLLISION_FOR_MODEL_LOADED(ModelIndex) end

---@param VecX number
---@param VecY number
---@param VecZ number
function STREAMING.REQUEST_ADDITIONAL_COLLISION_AT_COORD(VecX, VecY, VecZ) end

---@param animSetName any
---@return boolean
function STREAMING.DOES_ANIM_DICT_EXIST(animSetName) end

---@param animDictionaryName any
function STREAMING.REQUEST_ANIM_DICT(animDictionaryName) end

---@param animDictionaryName any
---@return boolean
function STREAMING.HAS_ANIM_DICT_LOADED(animDictionaryName) end

---@param animDictionaryName any
function STREAMING.REMOVE_ANIM_DICT(animDictionaryName) end

---@param name any
function STREAMING.REQUEST_MOVE_NETWORK_DEF(name) end

---@param name any
---@return boolean
function STREAMING.HAS_MOVE_NETWORK_DEF_LOADED(name) end

---@param name any
function STREAMING.REMOVE_MOVE_NETWORK_DEF(name) end

---@param animSetName any
function STREAMING.REQUEST_CLIP_SET(animSetName) end

---@param animSetName any
---@return boolean
function STREAMING.HAS_CLIP_SET_LOADED(animSetName) end

---@param animSetName any
function STREAMING.REMOVE_CLIP_SET(animSetName) end

---@param clipSetHash integer
function STREAMING._REQUEST_CLIP_SET_BY_HASH(clipSetHash) end

---@param p0 any
function STREAMING._0x03DDBF2D73799F9E(p0) end

---@param p0 any
---@return any
function STREAMING._0x85B8F04555AB49B8(p0) end

---@param p0 any
function STREAMING._0x9F348DE670423460(p0) end

---@param p0 any
---@return any
function STREAMING._0x5288B7F0690F7C1F(p0) end

---@param scenarioType integer
---@param p1 integer
---@param p2 any
---@param p3 any
---@return integer
function STREAMING._REQUEST_SCENARIO_TYPE(scenarioType, p1, p2, p3) end

---@param scenarioType integer
---@param p1 boolean
---@return boolean
function STREAMING._HAS_SCENARIO_TYPE_LOADED(scenarioType, p1) end

---@param scenarioType integer
---@return any
function STREAMING._REMOVE_SCENARIO_ASSET(scenarioType) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function STREAMING._0xB223249B7798EEED(p0, p1, p2, p3) end

---@param p0 any
---@return any
function STREAMING._0xA0AE7653E8181725(p0) end

---@param p0 any
---@return any
function STREAMING._0x66BC28E50E85270E(p0) end

---@param iplHash integer
---@param position Vector3
---@param radius number
---@return boolean
---@return Vector3
---@return number
function STREAMING._GET_IPL_BOUNDING_SPHERE(iplHash, position, radius) end

---@param iplHash integer
function STREAMING.REQUEST_IPL_HASH(iplHash) end

---@param iplHash integer
function STREAMING.REQUEST_IPL_BY_HASH(iplHash) end

---@param iplHash integer
function STREAMING.REMOVE_IPL_HASH(iplHash) end

---@param iplHash integer
function STREAMING.REMOVE_IPL_BY_HASH(iplHash) end

---@param iplHash integer
---@return boolean
function STREAMING.IS_IPL_ACTIVE_HASH(iplHash) end

---@param iplHash integer
---@return boolean
function STREAMING.IS_IPL_ACTIVE_BY_HASH(iplHash) end

---@param iplHash integer
---@param x number
---@param y number
---@param z number
---@return boolean
function STREAMING._IS_POSITION_INSIDE_IPL_STREAMING_EXTENTS(iplHash, x, y, z) end

function STREAMING._0xDEEE1F265B7ECEF5() end

---@param bAllowPause boolean
function STREAMING.SET_GAME_PAUSES_FOR_STREAMING(bAllowPause) end

---@return integer
function STREAMING.GET_NUMBER_OF_STREAMING_REQUESTS() end

function STREAMING.REQUEST_PTFX_ASSET() end

---@return boolean
function STREAMING.HAS_PTFX_ASSET_LOADED() end

function STREAMING.REMOVE_PTFX_ASSET() end

---@param fxNameHash integer
function STREAMING.REQUEST_NAMED_PTFX_ASSET(fxNameHash) end

---@param fxNameHash integer
---@return boolean
function STREAMING.HAS_NAMED_PTFX_ASSET_LOADED(fxNameHash) end

---@param fxNameHash integer
function STREAMING.REMOVE_NAMED_PTFX_ASSET(fxNameHash) end

---@param fBudgetMultiplier number
function STREAMING.SET_POPULATION_BUDGET_MULTIPLIER(fBudgetMultiplier) end

---@return number
function STREAMING.GET_POPULATION_BUDGET_MULTIPLIER() end

---@return any
function STREAMING._0x071769BCB24379E5() end

function STREAMING.CLEAR_FOCUS() end

---@param posX number
---@param posY number
---@param posZ number
---@param velX number
---@param velY number
---@param velZ number
function STREAMING.SET_FOCUS_POS_AND_VEL(posX, posY, posZ, velX, velY, velZ) end

---@param entityIndex integer
function STREAMING.SET_FOCUS_ENTITY(entityIndex) end

---@param entityIndex integer
---@return boolean
function STREAMING.IS_ENTITY_FOCUS(entityIndex) end

---@param boxName any
---@param bEnabled boolean
function STREAMING.SET_MAPDATACULLBOX_ENABLED(boxName, bEnabled) end

---@param bCulled boolean
function STREAMING.SET_ALL_MAPDATA_CULLED(bCulled) end

---@param p0 any
function STREAMING._0xF01D21DF39554115(p0) end

---@param posX number
---@param posY number
---@param posZ number
---@param offsetX number
---@param offsetY number
---@param offsetZ number
---@param radius number
---@param p7 integer
---@return boolean
function STREAMING.LOAD_SCENE_START(posX, posY, posZ, offsetX, offsetY, offsetZ, radius, p7) end

---@param x number
---@param y number
---@param z number
---@param radius number
---@param p4 any
---@return boolean
function STREAMING.LOAD_SCENE_START_SPHERE(x, y, z, radius, p4) end

function STREAMING.LOAD_SCENE_STOP() end

---@return boolean
function STREAMING.IS_LOAD_SCENE_ACTIVE() end

---@return boolean
function STREAMING.IS_LOAD_SCENE_LOADED() end

---@return boolean
function STREAMING.IS_RENDERED_SCENE_LOADED() end

---@return boolean
function STREAMING.IS_PLAYER_SWITCH_IN_PROGRESS() end

function STREAMING.SET_SCENE_STREAMING_TRACKS_CAM_POS_THIS_FRAME() end

---@param iplGroupBefore any
---@param iplGroupAfter any
function STREAMING.IPL_GROUP_SWAP_START(iplGroupBefore, iplGroupAfter) end

function STREAMING.IPL_GROUP_SWAP_CANCEL() end

---@return boolean
function STREAMING.IPL_GROUP_SWAP_IS_READY() end

function STREAMING.IPL_GROUP_SWAP_FINISH() end

---@return boolean
function STREAMING.IPL_GROUP_SWAP_IS_ACTIVE() end

---@param cutsceneName any
function STREAMING.PREFETCH_SRL(cutsceneName) end

function STREAMING._0xAE00387E53B1E9FC() end

function STREAMING._0xEF1A8A484118735E() end

function STREAMING._0xD9F2FF4AF394D926() end

---@return boolean
function STREAMING.IS_SRL_LOADED() end

function STREAMING.BEGIN_SRL() end

function STREAMING.END_SRL() end

---@param time number
function STREAMING.SET_SRL_TIME(time) end

---@param prestreamMap integer
---@param prestreamAssets integer
---@param playbackMap integer
---@param playbackAssets integer
function STREAMING.SET_SRL_READAHEAD_TIMES(prestreamMap, prestreamAssets, playbackMap, playbackAssets) end

---@param enableLongJumpMode boolean
function STREAMING.SET_SRL_LONG_JUMP_MODE(enableLongJumpMode) end

---@param positionX number
---@param positionY number
---@param positionZ number
---@param radius number
function STREAMING.SET_HD_AREA(positionX, positionY, positionZ, radius) end

function STREAMING.CLEAR_HD_AREA() end

function STREAMING._0x09FBF15D73EFC900() end

---@param p0 any
function STREAMING._0xF11D7CB962FCD747(p0) end

function STREAMING._0xB9B9E47EDB9D63DB() end

---@param p0 any
---@param p1 any
---@param p2 any
function STREAMING._0xBE8DAA9D8D01DA6A(p0, p1, p2) end

---@param p0 any
---@return any
function STREAMING._0x53764309C4618087(p0) end

---@param p0 integer
function STREAMING._0x032A14D082A9B269(p0) end

---@param p0 any
function STREAMING._0xAFA87A7D41EE346A(p0) end

function STREAMING._0x6A6E79FBE8678C98() end

---@param p0 any
function STREAMING._0xCC61D8D6C19D9F14(p0) end

---@return any
function STREAMING._0xDA7FDEFF4DE86839() end

---@return any
function STREAMING._0x5D5E2102B174B8D2() end

---@return any
function STREAMING._0x7B8C2B846C05E5AD() end

function STREAMING._0x62D5F0588915B277() end

---@return any
function STREAMING._0x2F4D53023F826FF0() end

---@return any
function STREAMING._0xDABFE48BA0D457AA() end

---@return any
function STREAMING._0xE5B76E5B56CD77DD() end

---@return any
function STREAMING._0x27AF48C62B281341() end

---@return any
function STREAMING._0x99F92061EFE908BA() end

---@param p0 any
---@param p1 any
---@return any
function STREAMING._0x05DD384F39DE1C8C(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function STREAMING._0x198B85CC3C7A4593(p0, p1) end

---@param p0 any
---@return any
function STREAMING._0x2A6D1DAAB9EBB262(p0) end

---@param p0 any
---@param p1 any
function STREAMING._0x07559B29950301FF(p0, p1) end

---@param p0 any
---@return any
function STREAMING._0xD6E39DC5D46DF4AB(p0) end

---@param p0 any
---@return any
function STREAMING._0x8D56BDA343D9519F(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
function STREAMING._0xD840C130D7AACFA5(p0, p1, p2) end

---@param p0 any
function STREAMING._0x2E24C27B112B5B12(p0) end

---@param toggle boolean
function STREAMING._SET_GUARMA_WORLDHORIZON_ACTIVE(toggle) end
