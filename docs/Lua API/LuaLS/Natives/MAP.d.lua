---@meta

---@class MAP
MAP = {}

---@param entityIndex integer
---@return integer
function MAP.GET_BLIP_FROM_ENTITY(entityIndex) end

---@return integer
function MAP.GET_MAIN_PLAYER_BLIP_ID() end

---@param styleHash integer
---@return integer
function MAP._BLIP_ADD_FOR_STYLE(styleHash) end

---@param blipHash integer
---@param x number
---@param y number
---@param z number
---@return integer
function MAP.BLIP_ADD_FOR_COORDS(blipHash, x, y, z) end

---@param blipHash integer
---@param entity integer
---@return integer
function MAP.BLIP_ADD_FOR_ENTITY(blipHash, entity) end

---@param blipHash integer
---@param pickup integer
---@return integer
function MAP.BLIP_ADD_FOR_PICKUP_PLACEMENT(blipHash, pickup) end

---@param blipHash integer
---@param x number
---@param y number
---@param z number
---@param radius number
---@return integer
function MAP.BLIP_ADD_FOR_RADIUS(blipHash, x, y, z, radius) end

---@param blipHash integer
---@param x number
---@param y number
---@param z number
---@param scaleX number
---@param scaleY number
---@param scaleZ number
---@param p7 integer
---@return integer
function MAP._BLIP_ADD_FOR_AREA(blipHash, x, y, z, scaleX, scaleY, scaleZ, p7) end

---@param blipHash integer
---@param volume integer
---@return integer
function MAP._BLIP_ADD_FOR_VOLUME(blipHash, volume) end

---@param blip integer
---@param styleHash integer
---@return boolean
function MAP._BLIP_SET_STYLE(blip, styleHash) end

---@param blip integer
---@param styleHash integer
---@return boolean
function MAP._BLIP_ADD_STYLE(blip, styleHash) end

---@param blip integer
---@param modifierHash integer
---@return boolean
function MAP.BLIP_ADD_MODIFIER(blip, modifierHash) end

---@param blip integer
---@param modifierHash integer
---@return boolean
function MAP.BLIP_REMOVE_MODIFIER(blip, modifierHash) end

---@param blip integer
function MAP._0x250C75EB1728CC0D(blip) end

---@param blip integer
---@param blipType integer
---@param blipHash integer
function MAP.SET_BLIP_FLASH_TIMER(blip, blipType, blipHash) end

---@param blip integer
---@param p1 integer
---@param p2 integer
---@return boolean
---@return integer
---@return integer
function MAP.SET_BLIP_FLASHES(blip, p1, p2) end

---@param typeHash integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
function MAP.TRIGGER_SONAR_BLIP(typeHash, VecCoorsX, VecCoorsY, VecCoorsZ) end

---@param typeHash integer
---@param entity integer
function MAP._TRIGGER_SONAR_BLIP_ON_ENTITY(typeHash, entity) end

---@param bSet boolean
function MAP.ALLOW_SONAR_BLIPS(bSet) end

---@param BlipIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
function MAP.SET_BLIP_COORDS(BlipIndex, VecCoorsX, VecCoorsY, VecCoorsZ) end

---@param BlipIndex integer
---@return Vector3
function MAP.GET_BLIP_COORDS(BlipIndex) end

---@param blip integer
---@param hash integer
---@param p2 boolean
function MAP.SET_BLIP_SPRITE(blip, hash, p2) end

---@param p0 any
---@return any
function MAP._0x01B928CA2E198B01(p0) end

---@param blip integer
---@param pTextLabel any
function MAP.SET_BLIP_NAME_FROM_TEXT_FILE(blip, pTextLabel) end

---@param blip integer
---@param name any
function MAP._SET_BLIP_NAME(blip, name) end

---@param blip integer
---@param PlayerIndex integer
function MAP.SET_BLIP_NAME_TO_PLAYER_NAME(blip, PlayerIndex) end

---@param blipIndex integer
---@param iDegrees integer
function MAP.SET_BLIP_ROTATION(blipIndex, iDegrees) end

---@param blip integer
---@param scale number
function MAP.SET_BLIP_SCALE(blip, scale) end

---@param BlipId integer
---@return integer
function MAP.REMOVE_BLIP(BlipId) end

---@param blipIndex integer
---@return boolean
function MAP.DOES_BLIP_EXIST(blipIndex) end

---@param entity integer
---@return boolean
function MAP._DOES_ENTITY_HAVE_BLIP(entity) end

---@param ZoomValue integer
function MAP.SET_RADAR_ZOOM(ZoomValue) end

---@param blip integer
function MAP._ABANDON_BLIP(blip) end

---@param blip integer
---@return boolean
function MAP._IS_BLIP_ATTACHED_TO_ANY_ENTITY(blip) end

---@param BlipIndex integer
---@return boolean
function MAP.IS_BLIP_ON_MINIMAP(BlipIndex) end

---@return any
function MAP.FORCE_SONAR_BLIPS_THIS_FRAME() end

---@param iFlags integer
---@param fBlippedRouteDisplayDistance number
function MAP.SET_GPS_FLAGS(iFlags, fBlippedRouteDisplayDistance) end

function MAP.CLEAR_GPS_FLAGS() end

---@param bOn boolean
---@param iRouteWidthMiniMap integer
---@param iRouteWidthPauseMap integer
function MAP.SET_GPS_CUSTOM_ROUTE_RENDER(bOn, iRouteWidthMiniMap, iRouteWidthPauseMap) end

function MAP.CLEAR_GPS_CUSTOM_ROUTE() end

---@param colorNameHash integer
---@param bOnFoot boolean
---@param inVehicle boolean
function MAP.START_GPS_MULTI_ROUTE(colorNameHash, bOnFoot, inVehicle) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param p3 boolean
function MAP.ADD_POINT_TO_GPS_MULTI_ROUTE(VecCoorsX, VecCoorsY, VecCoorsZ, p3) end

---@param bOn boolean
function MAP.SET_GPS_MULTI_ROUTE_RENDER(bOn) end

function MAP.CLEAR_GPS_MULTI_ROUTE() end

---@param waypointRecording any
---@param point integer
---@param numPoints integer
---@param colorNameHash integer
---@param p4 boolean
---@param p5 boolean
function MAP._START_GPS_CUSTOM_ROUTE_FROM_WAYPOINT_RECORDING_ROUTE(waypointRecording, point, numPoints, colorNameHash, p4, p5) end

function MAP.CLEAR_GPS_PLAYER_WAYPOINT() end

---@param p0 any
function MAP._0xD3F58E9316B7FC2A(p0) end

function MAP.SET_WAYPOINT_OFF() end

---@return boolean
function MAP.IS_WAYPOINT_ACTIVE() end

---@return Vector3
function MAP._GET_WAYPOINT_COORDS() end

---@param p0 any
---@param p1 any
---@return boolean
function MAP._0xF08E42BFA46BDFF8(p0, p1) end

function MAP._HIDE_ACTIVE_POINTS_OF_INTEREST() end

function MAP._SHOW_ACTIVE_POINTS_OF_INTEREST() end

---@return any
function MAP._0xF47A1EB2A538A3A3() end

---@param x number
---@param y number
---@param z number
---@param outPosition Vector3
---@return boolean
---@return Vector3
function MAP._FIND_CLOSEST_GPS_POSITION(x, y, z, outPosition) end

---@param bDisplayRadarFlag boolean
function MAP.DISPLAY_RADAR(bDisplayRadarFlag) end

---@param configHash integer
---@param p1 integer
function MAP._SET_RADAR_CONFIG_TYPE(configHash, p1) end

---@param minimapProp integer
---@param x number
---@param y number
---@param rotation number
---@param p4 integer
function MAP._ADD_PROP_TO_MINIMAP(minimapProp, x, y, rotation, p4) end

---@param minimapProp integer
function MAP._REMOVE_PROP_FROM_MINIMAP(minimapProp) end

function MAP.SET_RADAR_AS_EXTERIOR_THIS_FRAME() end

---@param bHideFow boolean
function MAP.SET_MINIMAP_HIDE_FOW(bHideFow) end

---@param toggle boolean
---@param p1 integer
function MAP._SET_FOW_UPDATE_PLAYER_OVERRIDE(toggle, p1) end

---@param scale number
---@param p1 integer
function MAP._SET_MINIMAP_FOW_OVERRIDE_REVEAL_SCALE(scale, p1) end

---@param toggle boolean
---@param p1 integer
function MAP._SET_MINIMAP_FOW_SHOULD_UPDATE(toggle, p1) end

---@param worldPOSX number
---@param worldPOSY number
---@param worldPOSZ number
---@param p3 integer
function MAP.SET_MINIMAP_FOW_REVEAL_COORDINATE(worldPOSX, worldPOSY, worldPOSZ, p3) end

---@param volume integer
---@param p1 integer
function MAP.SET_MINIMAP_FOW_REVEAL_VOLUME(volume, p1) end

---@param hash integer
function MAP.RESET_MINIMAP_FOW(hash) end

---@param hash integer
function MAP._REVEAL_MINIMAP_FOW(hash) end

---@param zone integer
function MAP._SET_MINIMAP_ZONE(zone) end

---@param iAngle integer
function MAP.LOCK_MINIMAP_ANGLE(iAngle) end

function MAP.UNLOCK_MINIMAP_ANGLE() end

---@param regionHash integer
---@param styleHash integer
function MAP._MAP_ENABLE_REGION_BLIP(regionHash, styleHash) end

---@param regionHash integer
function MAP._MAP_DISABLE_REGION_BLIP(regionHash) end

---@param regionHash integer
---@param styleHash integer
---@return boolean
function MAP._MAP_IS_REGION_HIGHLIGHTED_WITH_STYLE(regionHash, styleHash) end

---@param discoveryHash integer
function MAP._MAP_DISCOVER_REGION(discoveryHash) end

---@param discoveryHash integer
function MAP._MAP_DISCOVERY_SET_ENABLED(discoveryHash) end

---@param discoveryHash integer
---@return boolean
function MAP._MAP_IS_DISCOVERY_ACTIVE(discoveryHash) end

---@param x number
---@param y number
---@param z number
---@param radius number
function MAP._SET_PAUSEMAP_COORDS_WITH_RADIUS(x, y, z, radius) end

function MAP._0x7C9F4CDF402CA82A() end

---@param entity integer
---@param p1 any
function MAP._0x44813684F72B563C(entity, p1) end

---@param entity integer
---@param p1 any
function MAP._0x97F6F158CC5B5CA2(entity, p1) end

---@param p0 any
---@param p1 any
function MAP._0xBB68D4D3CA3DE402(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function MAP._0x3CB8859F04763C78(p0, p1) end

---@param entity integer
---@param blip integer
function MAP._0x7563CBCA99253D1A(entity, blip) end

---@param p0 any
function MAP._0x1726963E6049DB53(p0) end
