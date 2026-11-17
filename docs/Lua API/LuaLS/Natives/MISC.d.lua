---@meta

---@class MISC
MISC = {}

---@param stackSize integer
---@return integer
function MISC.GET_NUMBER_OF_FREE_STACKS_OF_THIS_SIZE(stackSize) end

---@return integer
function MISC._GET_NUMBER_OF_INSTRUCTIONS() end

---@return integer
function MISC._GET_MAX_NUM_INSTRUCTIONS() end

---@return boolean
function MISC.IS_MAG_DEMO_1_ACTIVE() end

---@param NewSeed integer
function MISC.SET_RANDOM_SEED(NewSeed) end

---@param fNewTimeScale number
function MISC.SET_TIME_SCALE(fNewTimeScale) end

---@param MissionFlagValue boolean
function MISC.SET_MISSION_FLAG(MissionFlagValue) end

---@return boolean
function MISC.GET_MISSION_FLAG() end

---@param p0 any
function MISC._0x5801BE2DF2AF07EC(p0) end

---@param bThisScriptIsARandomEvent boolean
function MISC.SET_RANDOM_EVENT_FLAG(bThisScriptIsARandomEvent) end

---@return boolean
function MISC.GET_RANDOM_EVENT_FLAG() end

---@param p0 any
function MISC._0x9BF2C0C568C61641(p0) end

---@param CaptionString any
---@param CondensedCaptionString any
function MISC.ACTIVITY_FEED_CREATE(CaptionString, CondensedCaptionString) end

---@param SubString any
function MISC.ACTIVITY_FEED_ADD_SUBSTRING_TO_CAPTION(SubString) end

---@param p0 any
function MISC._0xFF252E2BAFB7330F(p0) end

---@param commandLineString any
---@param labelString any
function MISC.ACTIVITY_FEED_ACTION_START_WITH_COMMAND_LINE(commandLineString, labelString) end

---@param commandLineString any
function MISC.ACTIVITY_FEED_ACTION_START_WITH_COMMAND_LINE_ADD(commandLineString) end

---@param p0 any
---@return any
function MISC._0xAF530E56505D1BD6(p0) end

function MISC.ACTIVITY_FEED_POST() end

---@return string
function MISC._0xF81C53561D15F330() end

---@param name any
function MISC._0x1096603B519C905F(name) end

---@param p0 integer
function MISC._0xCC3EDC5614B03F61(p0) end

---@param ContentIdString any
function MISC.INFORM_CODE_OF_CONTENT_ID_OF_CURRENT_UGC_MISSION(ContentIdString) end

---@param p0 any
function MISC._0xDA4D8EB04E8E2928(p0) end

---@param p0 any
function MISC._0xB08C4FA25BC29DB9(p0) end

---@return integer
function MISC._GET_PREV_WEATHER_TYPE_HASH_NAME() end

---@return integer
function MISC._GET_NEXT_WEATHER_TYPE_HASH_NAME() end

---@param p0 any
function MISC._0x0730E518486DEEC3(p0) end

---@param weatherType integer
---@param p1 boolean
---@param p2 boolean
---@param transition boolean
---@param transitionTime number
---@param p5 boolean
function MISC.SET_WEATHER_TYPE(weatherType, p1, p2, transition, transitionTime, p5) end

---@param weatherType integer
---@param p1 integer
---@param p2 integer
---@param p3 integer
---@param p4 boolean
function MISC._SET_WEATHER_TYPE_2(weatherType, p1, p2, p3, p4) end

---@return integer
function MISC._GET_RANDOM_WEATHER_TYPE_INDEX() end

---@return integer
function MISC._GET_RANDOM_WEATHER_TYPE() end

---@param p0 boolean
---@param p1 boolean
function MISC.SET_RANDOM_WEATHER_TYPE(p0, p1) end

function MISC.CLEAR_WEATHER_TYPE_PERSIST() end

---@param milliseconds integer
function MISC._CLEAR_WEATHER_TYPE_PERSIST_OVERTIME(milliseconds) end

---@param prevTypeHashName integer
---@param nextTypeHashName integer
---@param interpVal number
---@return integer
---@return integer
---@return number
function MISC.GET_CURR_WEATHER_STATE(prevTypeHashName, nextTypeHashName, interpVal) end

---@param prevTypeHashName integer
---@param nextTypeHashName integer
---@param interpVal number
---@param enabled boolean
function MISC.SET_CURR_WEATHER_STATE(prevTypeHashName, nextTypeHashName, interpVal, enabled) end

---@param toggle boolean
function MISC._SET_WEATHER_TYPE_FROZEN(toggle) end

---@param weather integer
---@param p1 integer
---@return integer
---@return integer
function MISC._GET_FORCED_WEATHER(weather, p1) end

---@param weatherType integer
function MISC._0x2916B30DC6C41179(weatherType) end

---@param weatherType integer
function MISC._0xD3F943B88F55376A(weatherType) end

function MISC._0x243CEDE8F916B994() end

---@param weatherType integer
function MISC._SET_OVERRIDE_WEATHER(weatherType) end

function MISC.CLEAR_OVERRIDE_WEATHER() end

---@param weatherType any
---@param variation any
function MISC._SET_WEATHER_VARIATION(weatherType, variation) end

---@param weatherType any
---@param p1 boolean
function MISC._CLEAR_WEATHER_VARIATION(weatherType, p1) end

---@param value number
function MISC.WATER_OVERRIDE_SET_SHOREWAVEAMPLITUDE(value) end

---@param value number
function MISC.WATER_OVERRIDE_SET_OCEANWAVEMAXAMPLITUDE(value) end

---@param x number
---@param y number
---@param z number
---@return number
function MISC._GET_TEMPERATURE_AT_COORDS(x, y, z) end

---@param WindSpeed number
function MISC.SET_WIND_SPEED(WindSpeed) end

---@return number
function MISC.GET_WIND_SPEED() end

---@param WindDir number
function MISC.SET_WIND_DIRECTION(WindDir) end

---@return Vector3
function MISC.GET_WIND_DIRECTION() end

---@param RainVal number
function MISC.SET_RAIN(RainVal) end

---@return number
function MISC.GET_RAIN_LEVEL() end

---@param p0 number
function MISC._0x745808BB01CEC6B9(p0) end

---@param level number
function MISC._SET_SNOW_LEVEL(level) end

---@return number
function MISC.GET_SNOW_LEVEL() end

function MISC.FORCE_LIGHTNING_FLASH() end

---@param x number
---@param y number
---@param z number
---@param p3 number
function MISC._FORCE_LIGHTNING_FLASH_AT_COORDS(x, y, z, p3) end

---@param p0 any
function MISC._0xA9342743B634A462(p0) end

---@return integer
function MISC.GET_GAME_TIMER() end

---@return integer
function MISC._GET_GAME_TIMER_NON_SCALED_CLIPPED() end

---@return integer
function MISC.GET_SYSTEM_TIME() end

---@return integer
function MISC.GET_NUMBER_OF_MICROSECONDS_SINCE_LAST_CALL() end

---@return integer
function MISC.GET_SCRIPT_TIME_WITHIN_FRAME_IN_MICROSECONDS() end

function MISC.RESET_SCRIPT_TIME_WITHIN_FRAME() end

---@return number
function MISC.GET_FRAME_TIME() end

---@return number
function MISC.GET_SYSTEM_TIME_STEP() end

---@return integer
function MISC.GET_FRAME_COUNT() end

---@param p0 integer
---@param p1 number
function MISC._0x6BED40493A1AFDB8(p0, p1) end

---@param value integer
---@return number
function MISC._READ_INT_AS_FLOAT(value) end

---@param MinFloat number
---@param MaxFloat number
---@return number
function MISC.GET_RANDOM_FLOAT_IN_RANGE(MinFloat, MaxFloat) end

---@param MinInt integer
---@param MaxInt integer
---@return integer
function MISC.GET_RANDOM_INT_IN_RANGE(MinInt, MaxInt) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param ReturnZ number
---@param p4 boolean
---@return boolean
---@return number
function MISC.GET_GROUND_Z_FOR_3D_COORD(VecCoorsX, VecCoorsY, VecCoorsZ, ReturnZ, p4) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param ReturnZ number
---@param ReturnNormal Vector3
---@return boolean
---@return number
---@return Vector3
function MISC.GET_GROUND_Z_AND_NORMAL_FOR_3D_COORD(VecCoorsX, VecCoorsY, VecCoorsZ, ReturnZ, ReturnNormal) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@return any
function MISC._0xBBE5B63EFFB08E68(p0, p1, p2, p3, p4, p5, p6) end

---@param X number
---@return number
function MISC.ASIN(X) end

---@param X number
---@return number
function MISC.ACOS(X) end

---@param X number
---@return number
function MISC.TAN(X) end

---@param X number
---@return number
function MISC.ATAN(X) end

---@param Y number
---@param X number
---@return number
function MISC.ATAN2(Y, X) end

---@param VecFirstCoorsX number
---@param VecFirstCoorsY number
---@param VecFirstCoorsZ number
---@param VecSecondCoorsX number
---@param VecSecondCoorsY number
---@param VecSecondCoorsZ number
---@param bCheck3d boolean
---@return number
function MISC.GET_DISTANCE_BETWEEN_COORDS(VecFirstCoorsX, VecFirstCoorsY, VecFirstCoorsZ, VecSecondCoorsX, VecSecondCoorsY, VecSecondCoorsZ, bCheck3d) end

---@param X1 number
---@param Y1 number
---@param X2 number
---@param Y2 number
---@return number
function MISC.GET_ANGLE_BETWEEN_2D_VECTORS(X1, Y1, X2, Y2) end

---@param VecX number
---@param VecY number
---@return number
function MISC.GET_HEADING_FROM_VECTOR_2D(VecX, VecY) end

---@param rPointToTestX number
---@param rPointToTestY number
---@param rPointToTestZ number
---@param vStartX number
---@param vStartY number
---@param vStartZ number
---@param vEndX number
---@param vEndY number
---@param vEndZ number
---@param bClampToLine boolean
---@return Vector3
function MISC.GET_CLOSEST_POINT_ON_LINE(rPointToTestX, rPointToTestY, rPointToTestZ, vStartX, vStartY, vStartZ, vEndX, vEndY, vEndZ, bClampToLine) end

---@param vscrPntAX number
---@param vscrPntAY number
---@param vscrPntAZ number
---@param vscrPntBX number
---@param vscrPntBY number
---@param vscrPntBZ number
---@param vscrPntOnPlaneX number
---@param vscrPntOnPlaneY number
---@param vscrPntOnPlaneZ number
---@param vscrNormalX number
---@param vscrNormalY number
---@param vscrNormalZ number
---@param fTValue number
---@return boolean
---@return number
function MISC.GET_LINE_PLANE_INTERSECTION(vscrPntAX, vscrPntAY, vscrPntAZ, vscrPntBX, vscrPntBY, vscrPntBZ, vscrPntOnPlaneX, vscrPntOnPlaneY, vscrPntOnPlaneZ, vscrNormalX, vscrNormalY, vscrNormalZ, fTValue) end

---@param Variable integer
---@param BitIndex integer
---@return integer
function MISC.SET_BIT(Variable, BitIndex) end

---@param Variable integer
---@param BitIndex integer
---@return integer
function MISC.CLEAR_BIT(Variable, BitIndex) end

---@param bitFlags integer
---@param flag integer
---@return boolean
function MISC._IS_BIT_FLAG_SET(bitFlags, flag) end

---@param bitFlags integer
---@return boolean
function MISC._IS_ANY_BIT_FLAG_SET(bitFlags) end

---@param bitFlags integer
---@return integer
function MISC._COUNT_BIT_FLAGS(bitFlags) end

---@param bitFlags integer
---@param flag integer
function MISC._SET_BIT_FLAG(bitFlags, flag) end

---@param bitFlags integer
---@param flag integer
function MISC._CLEAR_BIT_FLAG(bitFlags, flag) end

---@param bitFlags integer
function MISC._CLEAR_ALL_BIT_FLAGS(bitFlags) end

---@param InputString any
---@return integer
function MISC.GET_HASH_KEY(InputString) end

---@param t number
---@param b number
---@param d number
---@param easingCurveType integer
---@return number
function MISC._GET_EASING_CURVE_VALUE(t, b, d, easingCurveType) end

---@param VecCenterCoorsX number
---@param VecCenterCoorsY number
---@param VecCenterCoorsZ number
---@param radius number
---@param bBuildingFlag boolean
---@param bVehicleFlag boolean
---@param bPedFlag boolean
---@param bObjectFlag boolean
---@param bDummyFlag boolean
---@param ExcludeEntityIndex integer
---@param bCheckAlive boolean
---@return boolean
function MISC.IS_POSITION_OCCUPIED(VecCenterCoorsX, VecCenterCoorsY, VecCenterCoorsZ, radius, bBuildingFlag, bVehicleFlag, bPedFlag, bObjectFlag, bDummyFlag, ExcludeEntityIndex, bCheckAlive) end

---@param VecCentreCoorsX number
---@param VecCentreCoorsY number
---@param VecCentreCoorsZ number
---@param Radius number
---@param iFlags integer
function MISC.CLEAR_AREA(VecCentreCoorsX, VecCentreCoorsY, VecCentreCoorsZ, Radius, iFlags) end

---@param volume integer
---@param flag integer
function MISC._CLEAR_VOLUME_AREA(volume, flag) end

---@param vecAngledAreaPoint1X number
---@param vecAngledAreaPoint1Y number
---@param vecAngledAreaPoint1Z number
---@param vecAngledAreaPoint2X number
---@param vecAngledAreaPoint2Y number
---@param vecAngledAreaPoint2Z number
---@param DistanceOfOppositeFace number
---@param iFlags integer
function MISC.CLEAR_ANGLED_AREA_OF_VEHICLES(vecAngledAreaPoint1X, vecAngledAreaPoint1Y, vecAngledAreaPoint1Z, vecAngledAreaPoint2X, vecAngledAreaPoint2Y, vecAngledAreaPoint2Z, DistanceOfOppositeFace, iFlags) end

---@param bActive boolean
function MISC.SET_CREDITS_ACTIVE(bActive) end

function MISC.NETWORK_SET_SCRIPT_IS_SAFE_FOR_NETWORK_GAME() end

---@param bPaused boolean
function MISC.PAUSE_DEATH_ARREST_RESTART(bPaused) end

---@param bIgnore boolean
function MISC.IGNORE_NEXT_RESTART(bIgnore) end

---@param bDoFade boolean
function MISC.SET_FADE_IN_AFTER_DEATH_ARREST(bDoFade) end

---@param bFadeIn boolean
function MISC.SET_FADE_IN_AFTER_LOAD(bFadeIn) end

---@param bOverride boolean
---@param vecCoordsX number
---@param vecCoordsY number
---@param vecCoordsZ number
---@param fHeading number
---@param bIsAnAutosave boolean
---@param vecReturnCoords Vector3
---@param fReturnHeading number
---@return boolean
---@return Vector3
---@return number
function MISC.OVERRIDE_SAVE_HOUSE(bOverride, vecCoordsX, vecCoordsY, vecCoordsZ, fHeading, bIsAnAutosave, vecReturnCoords, fReturnHeading) end

---@param VecStartCoorsX number
---@param VecStartCoorsY number
---@param VecStartCoorsZ number
---@param VecEndCoorsX number
---@param VecEndCoorsY number
---@param VecEndCoorsZ number
---@param DamageCaused integer
---@param bPerfectAccuracy boolean
---@param Weapon integer
---@param PedIndex integer
---@param isAudible boolean
---@param isInvisible boolean
---@param InitialVelocity number
---@param p13 boolean
function MISC.SHOOT_SINGLE_BULLET_BETWEEN_COORDS(VecStartCoorsX, VecStartCoorsY, VecStartCoorsZ, VecEndCoorsX, VecEndCoorsY, VecEndCoorsZ, DamageCaused, bPerfectAccuracy, Weapon, PedIndex, isAudible, isInvisible, InitialVelocity, p13) end

---@param args integer
function MISC.FIRE_SINGLE_BULLET(args) end

---@param ModelHashKey integer
---@param returnMin Vector3
---@param returnMax Vector3
---@return Vector3
---@return Vector3
function MISC.GET_MODEL_DIMENSIONS(ModelHashKey, returnMin, returnMax) end

---@param address integer
---@param offset integer
---@return boolean
function MISC.IS_BIT_SET(address, offset) end

---@param p0 any
function MISC._0x0A487CC74A517FB5(p0) end

---@return boolean
function MISC.IS_MINIGAME_IN_PROGRESS() end

---@return boolean
function MISC.SHOULD_USE_METRIC_MEASUREMENTS() end

---@return boolean
function MISC._SHOULD_USE_METRIC_MEASUREMENTS_2() end

---@return boolean
function MISC._SHOULD_USE_METRIC_TEMPERATURE() end

---@return boolean
function MISC._SHOULD_USE_METRIC_WEIGHT() end

---@return boolean
function MISC._SHOULD_USE_24_HOUR_CLOCK() end

---@param String1 any
---@param String2 any
---@param bCaseSensitive boolean
---@param numberOfCharactersToCompare integer
---@return integer
function MISC.COMPARE_STRINGS(String1, String2, bCaseSensitive, numberOfCharactersToCompare) end

---@param n integer
---@return integer
function MISC.ABSI(n) end

---@param n number
---@return number
function MISC.ABSF(n) end

---@param VecMinCoorsX number
---@param VecMinCoorsY number
---@param VecMinCoorsZ number
---@param VecMaxCoorsX number
---@param VecMaxCoorsY number
---@param VecMaxCoorsZ number
---@param bIsPlayer boolean
---@return boolean
function MISC.IS_PROJECTILE_IN_AREA(VecMinCoorsX, VecMinCoorsY, VecMinCoorsZ, VecMaxCoorsX, VecMaxCoorsY, VecMaxCoorsZ, bIsPlayer) end

---@param VecMinCoorsX number
---@param VecMinCoorsY number
---@param VecMinCoorsZ number
---@param VecMaxCoorsX number
---@param VecMaxCoorsY number
---@param VecMaxCoorsZ number
---@param WeaponType integer
---@param bIsPlayer boolean
---@return boolean
function MISC.IS_PROJECTILE_TYPE_IN_AREA(VecMinCoorsX, VecMinCoorsY, VecMinCoorsZ, VecMaxCoorsX, VecMaxCoorsY, VecMaxCoorsZ, WeaponType, bIsPlayer) end

---@param vecAngledAreaPoint1X number
---@param vecAngledAreaPoint1Y number
---@param vecAngledAreaPoint1Z number
---@param vecAngledAreaPoint2X number
---@param vecAngledAreaPoint2Y number
---@param vecAngledAreaPoint2Z number
---@param DistanceOfOppositeFace number
---@param WeaponType integer
---@param bIsPlayer boolean
---@return boolean
function MISC.IS_PROJECTILE_TYPE_IN_ANGLED_AREA(vecAngledAreaPoint1X, vecAngledAreaPoint1Y, vecAngledAreaPoint1Z, vecAngledAreaPoint2X, vecAngledAreaPoint2Y, vecAngledAreaPoint2Z, DistanceOfOppositeFace, WeaponType, bIsPlayer) end

---@param vecCoorsX number
---@param vecCoorsY number
---@param vecCoorsZ number
---@param WeaponType integer
---@param distance number
---@param bIsPlayer boolean
---@return boolean
function MISC.IS_PROJECTILE_TYPE_WITHIN_DISTANCE(vecCoorsX, vecCoorsY, vecCoorsZ, WeaponType, distance, bIsPlayer) end

---@param ped integer
---@param WeaponType integer
---@param distance number
---@param positionOut Vector3
---@param needsToBeStationary boolean
---@param mustBeOwnedByThisPed boolean
---@return boolean
---@return Vector3
function MISC.GET_COORDS_OF_PROJECTILE_TYPE_WITHIN_DISTANCE(ped, WeaponType, distance, positionOut, needsToBeStationary, mustBeOwnedByThisPed) end

---@param ped integer
---@param WeaponType integer
---@param distance number
---@param positionOut Vector3
---@param EntityIndex integer
---@param needsToBeStationary boolean
---@param mustBeOwnedByThisPed boolean
---@return boolean
---@return Vector3
---@return integer
function MISC.GET_PROJECTILE_OF_PROJECTILE_TYPE_WITHIN_DISTANCE(ped, WeaponType, distance, positionOut, EntityIndex, needsToBeStationary, mustBeOwnedByThisPed) end

---@param VecPos1X number
---@param VecPos1Y number
---@param VecPos1Z number
---@param VecPos2X number
---@param VecPos2Y number
---@param VecPos2Z number
---@param AreaWidth number
---@param bIsPlayer boolean
---@return boolean
function MISC.IS_BULLET_IN_ANGLED_AREA(VecPos1X, VecPos1Y, VecPos1Z, VecPos2X, VecPos2Y, VecPos2Z, AreaWidth, bIsPlayer) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param Radius number
---@param bIsPlayer boolean
---@return boolean
function MISC.IS_BULLET_IN_AREA(VecCoorsX, VecCoorsY, VecCoorsZ, Radius, bIsPlayer) end

---@param VecMinCoorsX number
---@param VecMinCoorsY number
---@param VecMinCoorsZ number
---@param VecMaxCoorsX number
---@param VecMaxCoorsY number
---@param VecMaxCoorsZ number
---@param bIsPlayer boolean
---@return boolean
function MISC.IS_BULLET_IN_BOX(VecMinCoorsX, VecMinCoorsY, VecMinCoorsZ, VecMaxCoorsX, VecMaxCoorsY, VecMaxCoorsZ, bIsPlayer) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param Radius number
---@param bIsPlayer boolean
---@param bEntryOnly boolean
---@return boolean
function MISC.HAS_BULLET_IMPACTED_IN_AREA(VecCoorsX, VecCoorsY, VecCoorsZ, Radius, bIsPlayer, bEntryOnly) end

---@param VecMinCoorsX number
---@param VecMinCoorsY number
---@param VecMinCoorsZ number
---@param VecMaxCoorsX number
---@param VecMaxCoorsY number
---@param VecMaxCoorsZ number
---@param bIsPlayer boolean
---@param bEntryOnly boolean
---@return boolean
function MISC.HAS_BULLET_IMPACTED_IN_BOX(VecMinCoorsX, VecMinCoorsY, VecMinCoorsZ, VecMaxCoorsX, VecMaxCoorsY, VecMaxCoorsZ, bIsPlayer, bEntryOnly) end

---@param entity integer
---@param p1 integer
---@param p2 integer
---@return any
function MISC._0x7A76104CC2CC69E8(entity, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@return any
function MISC._0xDC416CA762BC4F43(p0, p1, p2, p3, p4, p5) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function MISC._0x970339EFA4FDE518(p0, p1, p2) end

---@return boolean
function MISC.IS_ORBIS_VERSION() end

---@return boolean
function MISC.IS_DURANGO_VERSION() end

---@return boolean
function MISC.IS_PC_VERSION() end

---@return boolean
function MISC.IS_STADIA_VERSION() end

---@param StringToTest any
---@return boolean
function MISC.IS_STRING_NULL(StringToTest) end

---@param StringToTest any
---@return boolean
function MISC.IS_STRING_NULL_OR_EMPTY(StringToTest) end

---@param string any
---@return boolean
function MISC.IS_STRING_NULL_OR_EMPTY_OR_SPACES(string) end

---@param String1 any
---@param String2 any
---@return boolean
function MISC.ARE_STRINGS_EQUAL(String1, String2) end

---@param string1 any
---@param string2 any
---@return boolean
function MISC._DOES_STRING_EXIST_IN_STRING(string1, string2) end

function MISC._0x3C3C7B1B5EC08764() end

---@param p0 any
---@param p1 any
---@return any
function MISC._0x94E8CA3DEE952789(p0, p1) end

---@param p0 any
---@return any
function MISC._0x5B4A8121A47D844D(p0) end

---@param StringToConvert any
---@param ReturnInteger integer
---@return boolean
---@return integer
function MISC.STRING_TO_INT(StringToConvert, ReturnInteger) end

---@param value integer
---@param format any
---@param buffer string
---@return string
function MISC._INT_TO_STRING(value, format, buffer) end

---@param p0 any
function MISC._0x74ACA66484CEBAF0(p0) end

---@param p0 any
function MISC._0x49C44FE78A135A1D(p0) end

---@param p0 any
function MISC._0xF650DCF5D6F312C1(p0) end

---@param value number
---@param digits integer
---@return string
function MISC._GET_STRING_FROM_FLOAT(value, digits) end

---@param x number
---@param y number
---@param z number
---@return string
function MISC._GET_STRING_FROM_VECTOR(x, y, z) end

---@param value boolean
---@return string
function MISC._GET_STRING_FROM_BOOL(value) end

---@param rgb integer
---@return string
function MISC._CREATE_COLOR_STRING(rgb) end

---@param VariableToChange integer
---@param StartBit integer
---@param EndBit integer
---@param NewValue integer
---@return integer
function MISC.SET_BITS_IN_RANGE(VariableToChange, StartBit, EndBit, NewValue) end

---@param VariableToRead integer
---@param StartBit integer
---@param EndBit integer
---@return integer
function MISC.GET_BITS_IN_RANGE(VariableToRead, StartBit, EndBit) end

---@param bDoPause boolean
function MISC.SET_GAME_PAUSED(bDoPause) end

---@param bScriptCanBePaused boolean
function MISC.SET_THIS_SCRIPT_CAN_BE_PAUSED(bScriptCanBePaused) end

---@param bCanRemoveBlipsCreatedByOtherScripts boolean
function MISC.SET_THIS_SCRIPT_CAN_REMOVE_BLIPS_CREATED_BY_ANY_SCRIPT(bCanRemoveBlipsCreatedByOtherScripts) end

---@param cheatId integer
function MISC.SET_CHEAT_ACTIVE(cheatId) end

function MISC._0xB711EB4BC8D06013() end

function MISC.POPULATE_NOW() end

---@return boolean
function MISC.IS_GAME_SESSION_STATE_MACHINE_IDLE() end

---@param p0 integer
---@return boolean
function MISC._QUEUE_SAVEGAME_OPERATION(p0) end

---@param p0 integer
---@return integer
function MISC._GET_STATUS_OF_SAVEGAME_OPERATION(p0) end

---@param p0 any
---@return any
function MISC._0x6C7B68D3CE60E8DE(p0) end

---@param p0 any
---@return any
function MISC._0x627B68D9CE6EE8DE(p0) end

---@param p0 any
---@return any
function MISC._0x7CF96F1250EF3221(p0) end

---@param DestStruct integer
---@param SourceStruct integer
---@param Size integer
function MISC.COPY_SCRIPT_STRUCT(DestStruct, SourceStruct, Size) end

---@param dispatchType integer
---@param bEnable boolean
function MISC.ENABLE_DISPATCH_SERVICE(dispatchType, bEnable) end

---@param dispatchType integer
---@param bBlock boolean
function MISC.BLOCK_DISPATCH_SERVICE_RESOURCE_CREATION(dispatchType, bBlock) end

---@param dispatchType integer
---@param vLocationX number
---@param vLocationY number
---@param vLocationZ number
---@param iNumUnits integer
---@param fTime number
---@param incidentIndex integer
---@param iOverrideRelGroupHash integer
---@param assassinsLevel integer
---@return boolean
---@return integer
function MISC.CREATE_INCIDENT(dispatchType, vLocationX, vLocationY, vLocationZ, iNumUnits, fTime, incidentIndex, iOverrideRelGroupHash, assassinsLevel) end

---@param dispatchService integer
---@param x number
---@param y number
---@param z number
---@param itemSet integer
---@param radius number
---@param outIncidentID integer
---@return boolean
---@return integer
function MISC._CREATE_INCIDENT_WITH_ENTITIES(dispatchService, x, y, z, itemSet, radius, outIncidentID) end

---@param incidentIndex integer
function MISC.DELETE_INCIDENT(incidentIndex) end

---@param incidentIndex integer
---@return boolean
function MISC.IS_INCIDENT_VALID(incidentIndex) end

---@param incidentId integer
function MISC._SET_INCIDENT_UNK(incidentId) end

---@param minWSX number
---@param minWSY number
---@param minWSZ number
---@param maxWSX number
---@param maxWSY number
---@param maxWSZ number
---@param pedDensity number
---@param trafficDensity number
---@param localOnly boolean
---@param bCameraGlobalMultiplier boolean
---@return integer
function MISC.ADD_POP_MULTIPLIER_AREA(minWSX, minWSY, minWSZ, maxWSX, maxWSY, maxWSZ, pedDensity, trafficDensity, localOnly, bCameraGlobalMultiplier) end

---@param index integer
---@return boolean
function MISC.DOES_POP_MULTIPLIER_AREA_EXIST(index) end

---@param index integer
---@param localOnly boolean
function MISC.REMOVE_POP_MULTIPLIER_AREA(index, localOnly) end

---@param volume integer
---@param pedDensity number
---@param vehicleDensity number
---@param p3 boolean
---@param p4 boolean
---@return integer
function MISC._ADD_POP_MULTIPLIER_VOLUME(volume, pedDensity, vehicleDensity, p3, p4) end

---@param volume integer
---@return boolean
function MISC._DOES_POP_MULTIPLIER_AREA_EXIST_FOR_VOLUME(volume) end

---@param volume integer
---@param p1 integer
function MISC._REMOVE_POP_MULTIPLIER_AREA_FOR_VOLUME(volume, p1) end

function MISC._0xF569E33FB72ED28E() end

function MISC.RESET_DISPATCH_IDEAL_SPAWN_DISTANCE() end

---@param fIdealSpawnDistance number
function MISC.SET_DISPATCH_IDEAL_SPAWN_DISTANCE(fIdealSpawnDistance) end

function MISC._RESET_DISPATCH_MIN_SPAWN_DISTANCE() end

---@param minSpawnDistance number
function MISC._SET_DISPATCH_MIN_SPAWN_DISTANCE(minSpawnDistance) end

function MISC._RESET_DISPATCH_MAX_SPAWN_DISTANCE() end

---@param maxSpawnDistance number
function MISC._SET_DISPATCH_MAX_SPAWN_DISTANCE(maxSpawnDistance) end

function MISC._0x4B0501A468B749F8() end

---@param p0 any
---@param p1 any
---@param p2 any
function MISC._0x6BCF7B5CD338281A(p0, p1, p2) end

---@param volume integer
---@return any
function MISC._ADD_DISPATCH_SPAWN_BLOCKING_AREA(volume) end

---@param iIndex integer
function MISC.REMOVE_DISPATCH_SPAWN_BLOCKING_AREA(iIndex) end

function MISC.RESET_WANTED_RESPONSE_NUM_PEDS_TO_SPAWN() end

---@param vPositionX number
---@param vPositionY number
---@param vPositionZ number
---@param p3 integer
function MISC.ADD_TACTICAL_NAV_MESH_POINT(vPositionX, vPositionY, vPositionZ, p3) end

function MISC.CLEAR_TACTICAL_NAV_MESH_POINTS() end

---@param keyboardTypeFlag integer
---@param prompt any
---@param description any
---@param initialValue1 any
---@param initialValue2 any
---@param initialValue3 any
---@param initialValue4 any
---@param maxLength integer
function MISC.DISPLAY_ONSCREEN_KEYBOARD(keyboardTypeFlag, prompt, description, initialValue1, initialValue2, initialValue3, initialValue4, maxLength) end

---@return integer
function MISC.UPDATE_ONSCREEN_KEYBOARD() end

---@return string
function MISC.GET_ONSCREEN_KEYBOARD_RESULT() end

function MISC.CANCEL_ONSCREEN_KEYBOARD() end

---@param fontBitField integer
function MISC.NEXT_ONSCREEN_KEYBOARD_RESULT_WILL_DISPLAY_USING_THESE_FONTS(fontBitField) end

---@param iActionHash integer
---@param bEnable boolean
function MISC.ACTION_MANAGER_ENABLE_ACTION(iActionHash, bEnable) end

---@param hash integer
---@return boolean
function MISC.ACTION_MANAGER_IS_ACTION_ENABLED(hash) end

---@return integer
function MISC.GET_REAL_WORLD_TIME() end

---@param PedIndex integer
function MISC.SET_SUPER_JUMP_THIS_FRAME(PedIndex) end

---@param numCheckpoints integer
---@param numLaps integer
---@param numPlayers integer
---@param localPlayerIndex integer
function MISC.SCRIPT_RACE_INIT(numCheckpoints, numLaps, numPlayers, localPlayerIndex) end

function MISC.SCRIPT_RACE_SHUTDOWN() end

---@param pedIndex integer
---@param checkpoint integer
---@param lap integer
---@param time integer
function MISC.SCRIPT_RACE_PLAYER_HIT_CHECKPOINT(pedIndex, checkpoint, lap, time) end

---@param pedIndex integer
---@param time integer
---@param position integer
---@return boolean
---@return integer
---@return integer
function MISC.SCRIPT_RACE_GET_PLAYER_SPLIT_TIME(pedIndex, time, position) end

function MISC.START_END_USER_BENCHMARK() end

function MISC.STOP_END_USER_BENCHMARK() end

function MISC.RESET_END_USER_BENCHMARK() end

function MISC.SAVE_END_USER_BENCHMARK() end

---@return boolean
function MISC.UI_STARTED_END_USER_BENCHMARK() end

---@return integer
function MISC.GET_BENCHMARK_ITERATIONS() end

---@return integer
function MISC.GET_BENCHMARK_PASS() end

---@return any
function MISC._0xDC057B86FC157031() end

function MISC._0x9A252AA23D7098F2() end

---@param item integer
---@return boolean
function MISC._DOES_ITEM_HAVE_VALID_BASE(item) end

---@param handle integer
---@return integer
function MISC._GET_ITEM_TYPE(handle) end

---@param handle integer
---@return boolean
function MISC._IS_BASE_A_PERSISTENT_CHARACTER(handle) end

---@param handle integer
---@return boolean
function MISC._IS_BASE_A_COVER_POINT(handle) end

---@param entity integer
function MISC._0x553D67295DDD2309(entity) end

---@param item integer
---@return integer
function MISC._GET_VOLUME_FROM_INDEXED_ITEM(item) end

---@param item integer
---@return integer
function MISC._GET_ENTITY_FROM_ITEM(item) end

---@param item integer
---@return integer
function MISC._GET_PED_FROM_INDEXED_ITEM(item) end

---@param item integer
---@return integer
function MISC._GET_VEHICLE_FROM_INDEXED_ITEM(item) end

---@param item integer
---@return integer
function MISC._GET_OBJECT_FROM_INDEXED_ITEM(item) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@return any
function MISC._0x33982467B1E349EF(p0, p1, p2, p3, p4, p5, p6) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function MISC._0x8314FC2013ECE2DA(p0, p1, p2) end

function MISC._0x4D5C9CC7E7E23E09() end

---@param entity integer
---@param text any
---@param radius number
---@param p3 number
---@param flag integer
---@param p5 number
---@param p6 number
---@param prompt integer
---@param p8 boolean
---@param p9 integer
---@return boolean
function MISC.REGISTER_INTERACTION_LOCKON_PROMPT(entity, text, radius, p3, flag, p5, p6, prompt, p8, p9) end

---@param entity integer
---@return boolean
function MISC.UNREGISTER_INTERACTION_LOCKON_PROMPT(entity) end

function MISC._0xFC6ECB9170145ECE() end

---@return any
function MISC._0x35165C658077CD0B() end

---@param ped integer
---@return boolean
function MISC._0x4B101DBCC9482F2D(ped) end

---@return boolean
function MISC._IS_MISSION_CREATOR_ACTIVE() end

function MISC._0xA3A8926951471C82() end

---@param args integer
---@param aiMemoryType integer
function MISC._CREATE_AI_MEMORY(args, aiMemoryType) end

---@param args integer
---@param p1 integer
---@return boolean
function MISC._GET_AI_PED_DOES_HAVE_EVENT_MEMORY(args, p1) end

---@param ped integer
---@param p1 any
function MISC._0xEB946B9E579729AD(ped, p1) end

---@param enabled boolean
function MISC._SET_AI_MEMORY_REACTIONS_ENABLED(enabled) end

---@param p0 any
---@param p1 any
---@return any
function MISC._0x8DB104CCEBCD58C5(p0, p1) end

---@param p0 any
---@param p1 any
function MISC._0x68319452C5064ABA(p0, p1) end

---@param p0 any
---@param p1 any
function MISC._0xDE2C3B74D2B3705C(p0, p1) end

---@param p0 integer
function MISC._0x49F3241C28EBBFBC(p0) end

---@param data integer
function MISC._0x183672FE838A661B(data) end

---@param p0 integer
function MISC._0x38C0C9CAE1544500(p0) end

---@param p0 any
function MISC._0x154340E87D8CC178(p0) end

---@param p0 any
function MISC._0x94FCADCF9F0C368E(p0) end

---@param p0 integer
---@return boolean
function MISC._0x0D0AE5081F88CFE1(p0) end

---@param p0 any
---@param p1 any
function MISC._0xAF3A84C7DE6A1DC5(p0, p1) end

---@param ped integer
---@param p1 boolean
---@param p2 boolean
---@param lootTableKey integer
---@param p4 integer
---@param p5 any
function MISC._LOOT_TABLES_GET_INFO(ped, p1, p2, lootTableKey, p4, p5) end

---@param p0 any
---@return any
function MISC._0xB1F6665AA54DCD5C(p0) end

---@param p0 any
---@param p1 any
---@return any
function MISC._0x8BB99B85444544D9(p0, p1) end

---@param p0 any
---@return any
function MISC._0x6F02B5E50511721E(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function MISC._0xCC1BAF72D571DB8D(p0, p1, p2) end

---@param ped integer
---@return boolean
function MISC._IS_PED_DECOMPOSED(ped) end

---@param ped integer
---@param toggle boolean
function MISC.SET_PED_DECOMPOSED(ped, toggle) end

---@param p0 any
---@param p1 any
function MISC._0xAB26DEEE120FD3FD(p0, p1) end

---@param compositeId integer
---@param p1 boolean
function MISC._0x082C043C7AFC3747(compositeId, p1) end

---@param compositeId integer
---@param p1 boolean
function MISC.DISABLE_LOOTING_COMPOSITE_LOOTABLE_THIS_FRAME(compositeId, p1) end

---@param p0 any
---@param p1 any
function MISC._0xBB282CF5D2333FB8(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function MISC._0xAD44856A1CD29635(p0, p1, p2) end

---@param p0 any
---@return any
function MISC._0x38C2BF94D15F464D(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
function MISC._0x3A87FDA8F1B6CDFB(p0, p1, p2) end

---@param p0 any
---@param p1 any
function MISC._0x4647842FE8F31C1E(p0, p1) end

---@param ped integer
---@param eventName any
---@return boolean
function MISC._GET_LOOTING_EVENT_HAS_FIRED(ped, eventName) end

---@param ped integer
---@param item any
function MISC._SET_LOOT_PELT_SATCHEL_ITEM(ped, item) end

---@param p0 any
---@param p1 any
function MISC._0x96282005C5C6801F(p0, p1) end

---@param p0 any
---@param p1 any
function MISC._0xF63FA29D4A9ACA86(p0, p1) end

---@param p0 any
---@param p1 any
function MISC._0x8C0F6A3D7236DEEB(p0, p1) end

---@param p0 any
---@param p1 any
function MISC._0x7FA58CED69405F9A(p0, p1) end

---@param p0 any
function MISC._0xA08111B053D84B4D(p0) end

---@param index integer
---@return boolean
function MISC._IS_GLOBAL_BLOCK_VALID(index) end

---@param index integer
---@param toggle boolean
function MISC._SET_GLOBAL_BLOCK_IS_LOADED(index, toggle) end

---@param transitionMode integer
---@return boolean
function MISC.GAME_FRAMEWORK_MANAGER_INIT(transitionMode) end

function MISC._GAME_FRAMEWORK_MANAGER_SHUTDOWN() end

---@return integer
function MISC._GAME_FRAMEWORK_MANAGER_GET_MODE() end

---@return boolean
function MISC._IS_PLAYER_OWNING_STANDALONE_SP() end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function MISC._0x0358B8A41916C613(p0, p1, p2, p3) end

function MISC._SET_GAME_LOGIC_PAUSED() end

function MISC.STOP_CURRENT_LOADING_PROGRESS_TIMER() end

function MISC._0xDBDA48EC456ED908() end
