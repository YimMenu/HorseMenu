---@meta

---@class GRAPHICS
GRAPHICS = {}

function GRAPHICS.FREE_MEMORY_FOR_MISSION_CREATOR_PHOTO() end

---@param szContentID any
---@param nFileID integer
---@param nFileVersion integer
---@param nLanguage integer
---@return boolean
function GRAPHICS.LOAD_MISSION_CREATOR_PHOTO(szContentID, nFileID, nFileVersion, nLanguage) end

---@param szContentID any
---@return integer
function GRAPHICS.GET_STATUS_OF_LOAD_MISSION_CREATOR_PHOTO(szContentID) end

---@return boolean
function GRAPHICS.BEGIN_TAKE_HIGH_QUALITY_PHOTO() end

---@return integer
function GRAPHICS.GET_STATUS_OF_TAKE_HIGH_QUALITY_PHOTO() end

function GRAPHICS.FREE_MEMORY_FOR_HIGH_QUALITY_PHOTO() end

---@param p0 boolean
function GRAPHICS._SET_PHOTO_SELF_STAT(p0) end

---@param p0 integer
function GRAPHICS._SET_PHOTO_STUDIO_STAT(p0) end

---@param posseId any
function GRAPHICS._SET_POSSE_ID_FOR_PHOTO(posseId) end

---@param p0 boolean
---@param p1 boolean
function GRAPHICS._0x9F6D859C80708B26(p0, p1) end

---@return boolean
function GRAPHICS.IS_PHOTO_FRAME() end

---@param p0 boolean
function GRAPHICS._SET_PHOTO_IN_PHOTOMODE_STAT(p0) end

---@param p0 integer
function GRAPHICS._SET_PHOTO_OVERLAY_EFFECT_STAT(p0) end

---@param p0 any
function GRAPHICS._0x0D5B19C34068FEE7(p0) end

---@param player integer
function GRAPHICS._SET_PLAYER_APPEAR_IN_PHOTO(player) end

---@param p0 any
function GRAPHICS._SET_REGION_PHOTO_TAKEN_STAT(p0) end

---@param p0 any
function GRAPHICS._SET_DISTRICT_PHOTO_TAKEN_STAT(p0) end

---@param p0 any
function GRAPHICS._SET_STATE_PHOTO_TAKEN_STAT(p0) end

---@param PhotoSlotIndex integer
---@return boolean
function GRAPHICS.SAVE_HIGH_QUALITY_PHOTO(PhotoSlotIndex) end

---@return integer
function GRAPHICS.GET_STATUS_OF_SAVE_HIGH_QUALITY_PHOTO() end

---@param qualitySetting integer
---@return boolean
function GRAPHICS.BEGIN_CREATE_LOW_QUALITY_COPY_OF_PHOTO(qualitySetting) end

---@param qualitySetting integer
---@return integer
function GRAPHICS.GET_STATUS_OF_CREATE_LOW_QUALITY_COPY_OF_PHOTO(qualitySetting) end

function GRAPHICS.FREE_MEMORY_FOR_LOW_QUALITY_PHOTO() end

---@param bDraw boolean
---@param PhotoRotation integer
function GRAPHICS.DRAW_LOW_QUALITY_PHOTO_TO_PHONE(bDraw, PhotoRotation) end

---@return integer
function GRAPHICS._GET_MAX_NUMBER_OF_LOCAL_PHOTOS() end

---@return integer
function GRAPHICS._GET_CURRENT_NUMBER_OF_LOCAL_PHOTOS() end

---@return boolean
function GRAPHICS.QUEUE_OPERATION_TO_CREATE_SORTED_LIST_OF_PHOTOS() end

---@return integer
function GRAPHICS.GET_STATUS_OF_SORTED_LIST_OPERATION() end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param R integer
---@param G integer
---@param B integer
---@param Range number
---@param Intensity number
function GRAPHICS.DRAW_LIGHT_WITH_RANGE(VecCoorsX, VecCoorsY, VecCoorsZ, R, G, B, Range, Intensity) end

---@param EntityIndex integer
function GRAPHICS.UPDATE_LIGHTS_ON_ENTITY(EntityIndex) end

---@param entity integer
---@param red integer
---@param green integer
---@param blue integer
function GRAPHICS._SET_LIGHTS_COLOR_FOR_ENTITY(entity, red, green, blue) end

---@param entity integer
---@param intensity number
function GRAPHICS._SET_LIGHTS_INTENSITY_FOR_ENTITY(entity, intensity) end

---@param entity integer
---@param type integer
function GRAPHICS._SET_LIGHTS_TYPE_FOR_ENTITY(entity, type) end

---@param type integer
---@param posX number
---@param posY number
---@param posZ number
---@param dirX number
---@param dirY number
---@param dirZ number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param scaleX number
---@param scaleY number
---@param scaleZ number
---@param red integer
---@param green integer
---@param blue integer
---@param alpha integer
---@param bobUpAndDown boolean
---@param faceCamera boolean
---@param p19 integer
---@param rotate boolean
---@param textureDict any
---@param textureName any
---@param drawOnEnts boolean
function GRAPHICS._DRAW_MARKER(type, posX, posY, posZ, dirX, dirY, dirZ, rotX, rotY, rotZ, scaleX, scaleY, scaleZ, red, green, blue, alpha, bobUpAndDown, faceCamera, p19, rotate, textureDict, textureName, drawOnEnts) end

---@param typeHash integer
---@param posX1 number
---@param posY1 number
---@param posZ1 number
---@param posX2 number
---@param posY2 number
---@param posZ2 number
---@param radius number
---@param red integer
---@param green integer
---@param blue integer
---@param alpha integer
---@param reserved integer
---@return integer
function GRAPHICS.CREATE_CHECKPOINT_WITH_NAMEHASH(typeHash, posX1, posY1, posZ1, posX2, posY2, posZ2, radius, red, green, blue, alpha, reserved) end

---@param checkpoint integer
---@return boolean
function GRAPHICS._DOES_CHECKPOINT_HAVE_FX(checkpoint) end

---@param UniqueCheckpointIndex integer
---@param colR integer
---@param colG integer
---@param colB integer
---@param colA integer
function GRAPHICS.SET_CHECKPOINT_RGBA(UniqueCheckpointIndex, colR, colG, colB, colA) end

---@param UniqueCheckpointIndex integer
---@param colR integer
---@param colG integer
---@param colB integer
---@param colA integer
function GRAPHICS.SET_CHECKPOINT_RGBA2(UniqueCheckpointIndex, colR, colG, colB, colA) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function GRAPHICS._0xCC3B787E73E64160(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function GRAPHICS._0x171C18E994C1A395(p0, p1, p2, p3, p4) end

---@param UniqueCheckpointIndex integer
function GRAPHICS.DELETE_CHECKPOINT(UniqueCheckpointIndex) end

---@param CentreX number
---@param CentreY number
---@param Width number
---@param Height number
---@param R integer
---@param G integer
---@param B integer
---@param A integer
---@param bStereo boolean
---@param p9 boolean
function GRAPHICS.DRAW_RECT(CentreX, CentreY, Width, Height, R, G, B, A, bStereo, p9) end

---@param bValue boolean
function GRAPHICS.SET_SCRIPT_GFX_DRAW_BEHIND_PAUSEMENU(bValue) end

---@param iDrawOrder integer
function GRAPHICS.SET_SCRIPT_GFX_DRAW_ORDER(iDrawOrder) end

---@param pTextureDictionaryName any
---@param pTextureName any
---@param CentreX number
---@param CentreY number
---@param Width number
---@param Height number
---@param Rotation number
---@param R integer
---@param G integer
---@param B integer
---@param A integer
---@param DoStereorize boolean
function GRAPHICS.DRAW_SPRITE(pTextureDictionaryName, pTextureName, CentreX, CentreY, Width, Height, Rotation, R, G, B, A, DoStereorize) end

---@param entity integer
function GRAPHICS.ATTACH_TV_AUDIO_TO_ENTITY(entity) end

---@param frontend boolean
function GRAPHICS.SET_TV_AUDIO_FRONTEND(frontend) end

---@param X integer
---@param Y integer
---@return integer
---@return integer
function GRAPHICS.GET_SCREEN_RESOLUTION(X, Y) end

---@param p0 any
---@param p1 any
function GRAPHICS._0xA04EF43030593ABC(p0, p1) end

function GRAPHICS._0xA21AF60C9F99CCC5() end

---@return any
function GRAPHICS._0xC28F62AC9774FC1B() end

---@param p0 any
function GRAPHICS._0xEB48CE48EEC41FD4(p0) end

---@param vWorldPosX number
---@param vWorldPosY number
---@param vWorldPosZ number
---@param fXpos number
---@param Ypos number
---@return boolean
---@return number
---@return number
function GRAPHICS.GET_SCREEN_COORD_FROM_WORLD_COORD(vWorldPosX, vWorldPosY, vWorldPosZ, fXpos, Ypos) end

---@param txdHash integer
---@param dict integer
---@return boolean
function GRAPHICS._IS_TEXTURE_IN_DICT(txdHash, dict) end

---@param bState boolean
function GRAPHICS.SET_ARTIFICIAL_LIGHTS_STATE(bState) end

function GRAPHICS.DISABLE_HDTEX_THIS_FRAME() end

---@param p0 boolean
function GRAPHICS._0x1A9F09AB458D49C6(p0) end

---@return integer
function GRAPHICS.CREATE_TRACKED_POINT() end

---@param queryIdx integer
---@param centerX number
---@param centerY number
---@param centerZ number
---@param radius number
function GRAPHICS.SET_TRACKED_POINT_INFO(queryIdx, centerX, centerY, centerZ, radius) end

---@param queryIdx integer
---@return boolean
function GRAPHICS.IS_TRACKED_POINT_VISIBLE(queryIdx) end

---@param iTrackedPoint integer
---@return integer
function GRAPHICS._0xDFE332A5DA6FE7C9(iTrackedPoint) end

---@param queryIdx integer
function GRAPHICS.DESTROY_TRACKED_POINT(queryIdx) end

---@param point integer
---@return boolean
function GRAPHICS._IS_TRACKED_POINT_VALID(point) end

---@param centerX number
---@param centerY number
---@param centerZ number
---@param radius number
---@param p4 integer
---@return integer
function GRAPHICS.SET_GRASS_CULL_SPHERE(centerX, centerY, centerZ, radius, p4) end

---@param handle integer
function GRAPHICS.REMOVE_GRASS_CULL_SPHERE(handle) end

---@param volume integer
---@param p1 integer
---@param flags integer
---@param p3 integer
---@return integer
function GRAPHICS._ADD_VEG_MODIFIER_ZONE(volume, p1, flags, p3) end

---@param x number
---@param y number
---@param z number
---@param radius number
---@param modType integer
---@param flags integer
---@param p6 integer
---@return integer
function GRAPHICS.ADD_VEG_MODIFIER_SPHERE(x, y, z, radius, modType, flags, p6) end

---@param vegModifierHandle integer
---@param p1 integer
function GRAPHICS.REMOVE_VEG_MODIFIER_SPHERE(vegModifierHandle, p1) end

---@param p0 integer
function GRAPHICS._ENABLE_STATIC_VEG_MODIFIER(p0) end

---@param p0 integer
function GRAPHICS._DISABLE_STATIC_VEG_MODIFIER(p0) end

---@param p0 integer
---@return boolean
function GRAPHICS._IS_STATIC_VEG_MODIFIER_ENABLED(p0) end

function GRAPHICS._0xEC3F7F24EEEB3BA3() end

---@param p0 any
function GRAPHICS._0x9F158A49B0D84C3C(p0) end

function GRAPHICS._0x910E260AEAD855DE() end

---@param slots integer
---@return boolean
function GRAPHICS._CREATE_SWATCH_TEXTURE_DICT(slots) end

function GRAPHICS._DESTROY_SWATCH_TEXTURE_DICT() end

---@param slot integer
---@param p1 any
function GRAPHICS._GENERATE_SWATCH_TEXTURE_DIRECTLY(slot, p1) end

---@param slotId integer
---@param componentHash integer
---@param metapedType integer
---@param p3 boolean
function GRAPHICS._GENERATE_SWATCH_TEXTURE(slotId, componentHash, metapedType, p3) end

---@param cascadeIndex integer
---@param bEnabled boolean
---@param x number
---@param y number
---@param z number
---@param radiusScale number
---@param interpolateToDisabled boolean
---@param interpolationTime number
function GRAPHICS.CASCADE_SHADOWS_SET_CASCADE_BOUNDS(cascadeIndex, bEnabled, x, y, z, radiusScale, interpolateToDisabled, interpolationTime) end

---@param scale boolean
function GRAPHICS.CASCADE_SHADOWS_ENABLE_ENTITY_TRACKER(scale) end

---@param typeStr any
function GRAPHICS.CASCADE_SHADOWS_SET_SHADOW_SAMPLE_TYPE(typeStr) end

function GRAPHICS.CASCADE_SHADOWS_CLEAR_SHADOW_SAMPLE_TYPE() end

---@param p0 any
function GRAPHICS._0x503941F65DBA24EC(p0) end

function GRAPHICS._0x815653A42C5ABE76() end

---@param p0 any
function GRAPHICS._0xFF8018C778349234(p0) end

---@param numFrames integer
function GRAPHICS.RESET_ADAPTATION(numFrames) end

---@param on boolean
function GRAPHICS.TOGGLE_PAUSED_RENDERPHASES(on) end

---@return boolean
function GRAPHICS.GET_TOGGLE_PAUSED_RENDERPHASES_STATUS() end

function GRAPHICS.RESET_PAUSED_RENDERPHASES() end

---@param enableOverride boolean
---@param enableDOF boolean
---@param dofNearStart number
---@param dofNearEnd number
---@param dofFarStart number
---@param dofFarEnd number
function GRAPHICS.SET_HIDOF_OVERRIDE(enableOverride, enableDOF, dofNearStart, dofNearEnd, dofFarStart, dofFarEnd) end

---@param component any
function GRAPHICS._0x21F00E08CBB5F37B(component) end

function GRAPHICS._0x5AC6E0FA028369DE() end

---@param p0 boolean
---@return boolean
function GRAPHICS._0xEC3D8C228FE553D7(p0) end

---@param p0 any
function GRAPHICS._0xF5793BB386E1FF9C(p0) end

---@param p0 any
function GRAPHICS._0x5CD6A2CCE5087161(p0) end

---@param p0 any
function GRAPHICS._0xC8D0611D9A0CF5D3(p0) end

---@return number
function GRAPHICS._GET_PHOTO_MODE_EXPOSURE() end

---@param p0 any
function GRAPHICS._0x62B9F9A1272AED80(p0) end

---@return number
function GRAPHICS._GET_PHOTO_MODE_CONTRAST() end

function GRAPHICS._0x9229ED770975BD9E() end

---@param fxName any
---@param vecPositionX number
---@param vecPositionY number
---@param vecPositionZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
---@param scale number
---@param invertAxisX boolean
---@param invertAxisY boolean
---@param invertAxisZ boolean
---@return boolean
function GRAPHICS.START_PARTICLE_FX_NON_LOOPED_AT_COORD(fxName, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ) end

---@param fxName any
---@param vecPositionX number
---@param vecPositionY number
---@param vecPositionZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
---@param scale number
---@param invertAxisX boolean
---@param invertAxisY boolean
---@param invertAxisZ boolean
---@return boolean
function GRAPHICS.START_NETWORKED_PARTICLE_FX_NON_LOOPED_AT_COORD(fxName, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ) end

---@param fxName any
---@param pedIndex integer
---@param vecPositionX number
---@param vecPositionY number
---@param vecPositionZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
---@param boneTag integer
---@param scale number
---@param invertAxisX boolean
---@param invertAxisY boolean
---@param invertAxisZ boolean
---@return boolean
function GRAPHICS.START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE(fxName, pedIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, boneTag, scale, invertAxisX, invertAxisY, invertAxisZ) end

---@param fxName any
---@param entityIndex integer
---@param vecPositionX number
---@param vecPositionY number
---@param vecPositionZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
---@param scale number
---@param invertAxisX boolean
---@param invertAxisY boolean
---@param invertAxisZ boolean
---@return boolean
function GRAPHICS.START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(fxName, entityIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ) end

---@param fxName any
---@param entityIndex integer
---@param vecPositionX number
---@param vecPositionY number
---@param vecPositionZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
---@param scale number
---@param invertAxisX boolean
---@param invertAxisY boolean
---@param invertAxisZ boolean
---@return boolean
function GRAPHICS.START_NETWORKED_PARTICLE_FX_NON_LOOPED_ON_ENTITY(fxName, entityIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ) end

---@param effectName any
---@param ped integer
---@param offsetX number
---@param offsetY number
---@param offsetZ number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param boneIndex integer
---@param scale number
---@param axisX boolean
---@param axisY boolean
---@param axisZ boolean
---@return boolean
function GRAPHICS._START_PARTICLE_FX_NON_LOOPED_ON_PED_BONE_2(effectName, ped, offsetX, offsetY, offsetZ, rotX, rotY, rotZ, boneIndex, scale, axisX, axisY, axisZ) end

---@param colR number
---@param colG number
---@param colB number
function GRAPHICS.SET_PARTICLE_FX_NON_LOOPED_COLOUR(colR, colG, colB) end

---@param colA number
function GRAPHICS.SET_PARTICLE_FX_NON_LOOPED_ALPHA(colA) end

---@param p0 number
---@param p1 number
---@param p2 number
function GRAPHICS._SET_PARTICLE_FX_NON_LOOPED_EMITTER_SCALE(p0, p1, p2) end

---@param fxName any
---@param vecPositionX number
---@param vecPositionY number
---@param vecPositionZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
---@param scale number
---@param invertAxisX boolean
---@param invertAxisY boolean
---@param invertAxisZ boolean
---@param localOnly boolean
---@return integer
function GRAPHICS.START_PARTICLE_FX_LOOPED_AT_COORD(fxName, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ, localOnly) end

---@param fxName any
---@param pedIndex integer
---@param vecPositionX number
---@param vecPositionY number
---@param vecPositionZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
---@param boneTag integer
---@param scale number
---@param invertAxisX boolean
---@param invertAxisY boolean
---@param invertAxisZ boolean
---@return integer
function GRAPHICS.START_PARTICLE_FX_LOOPED_ON_PED_BONE(fxName, pedIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, boneTag, scale, invertAxisX, invertAxisY, invertAxisZ) end

---@param fxName any
---@param entityIndex integer
---@param vecPositionX number
---@param vecPositionY number
---@param vecPositionZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
---@param scale number
---@param invertAxisX boolean
---@param invertAxisY boolean
---@param invertAxisZ boolean
---@return integer
function GRAPHICS.START_PARTICLE_FX_LOOPED_ON_ENTITY(fxName, entityIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ) end

---@param fxName any
---@param entityIndex integer
---@param vecPositionX number
---@param vecPositionY number
---@param vecPositionZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
---@param boneIndex integer
---@param scale number
---@param invertAxisX boolean
---@param invertAxisY boolean
---@param invertAxisZ boolean
---@return integer
function GRAPHICS.START_PARTICLE_FX_LOOPED_ON_ENTITY_BONE(fxName, entityIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, boneIndex, scale, invertAxisX, invertAxisY, invertAxisZ) end

---@param fxName any
---@param entityIndex integer
---@param vecPositionX number
---@param vecPositionY number
---@param vecPositionZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
---@param scale number
---@param invertAxisX boolean
---@param invertAxisY boolean
---@param invertAxisZ boolean
---@return integer
function GRAPHICS.START_NETWORKED_PARTICLE_FX_LOOPED_ON_ENTITY(fxName, entityIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, scale, invertAxisX, invertAxisY, invertAxisZ) end

---@param fxName any
---@param entityIndex integer
---@param vecPositionX number
---@param vecPositionY number
---@param vecPositionZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
---@param boneIndex integer
---@param scale number
---@param invertAxisX boolean
---@param invertAxisY boolean
---@param invertAxisZ boolean
---@return integer
function GRAPHICS.START_NETWORKED_PARTICLE_FX_LOOPED_ON_ENTITY_BONE(fxName, entityIndex, vecPositionX, vecPositionY, vecPositionZ, vecRotationX, vecRotationY, vecRotationZ, boneIndex, scale, invertAxisX, invertAxisY, invertAxisZ) end

---@param ptfxId integer
---@param localOnly boolean
function GRAPHICS.STOP_PARTICLE_FX_LOOPED(ptfxId, localOnly) end

---@param ptfxId integer
---@return boolean
function GRAPHICS.DOES_PARTICLE_FX_LOOPED_EXIST(ptfxId) end

---@param ptfxId integer
---@param positionX number
---@param positionY number
---@param positionZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
function GRAPHICS.SET_PARTICLE_FX_LOOPED_OFFSETS(ptfxId, positionX, positionY, positionZ, vecRotationX, vecRotationY, vecRotationZ) end

---@param ptfxId integer
---@param evoName any
---@param evoVal number
---@param localOnly boolean
function GRAPHICS.SET_PARTICLE_FX_LOOPED_EVOLUTION(ptfxId, evoName, evoVal, localOnly) end

---@param ptfxId integer
---@param colR number
---@param colG number
---@param colB number
---@param localOnly boolean
function GRAPHICS.SET_PARTICLE_FX_LOOPED_COLOUR(ptfxId, colR, colG, colB, localOnly) end

---@param ptfxId integer
---@param colA number
function GRAPHICS.SET_PARTICLE_FX_LOOPED_ALPHA(ptfxId, colA) end

---@param ptfxId integer
---@param scale number
function GRAPHICS.SET_PARTICLE_FX_LOOPED_SCALE(ptfxId, scale) end

---@param ptfxId integer
---@param farClipDist number
function GRAPHICS.SET_PARTICLE_FX_LOOPED_FAR_CLIP_DIST(ptfxId, farClipDist) end

---@param ptfxHandle integer
---@param scalar number
function GRAPHICS._SET_PARTICLE_FX_LOOPED_UPDATE_DISTANT_SMOKE(ptfxHandle, scalar) end

---@param ptfxId integer
---@param localOnly boolean
function GRAPHICS.REMOVE_PARTICLE_FX(ptfxId, localOnly) end

---@param entityIndex integer
function GRAPHICS.REMOVE_PARTICLE_FX_FROM_ENTITY(entityIndex) end

---@param posX number
---@param posY number
---@param posZ number
---@param range number
function GRAPHICS.REMOVE_PARTICLE_FX_IN_RANGE(posX, posY, posZ, range) end

---@param ptFxAssetName any
function GRAPHICS.USE_PARTICLE_FX_ASSET(ptFxAssetName) end

---@param ptFxToOverride any
---@param ptFxToUseInstead any
function GRAPHICS.SET_PARTICLE_FX_OVERRIDE(ptFxToOverride, ptFxToUseInstead) end

---@param ptFxToOverride any
function GRAPHICS.RESET_PARTICLE_FX_OVERRIDE(ptFxToOverride) end

---@param entity integer
---@param p1 any
---@param p2 any
---@param p3 number
function GRAPHICS._0x4FB67D172C4476F3(entity, p1, p2, p3) end

---@param entity integer
---@param p1 any
---@param r number
---@param g number
---@param b number
function GRAPHICS.SET_PARTICLE_FX_AMBIENT_COLOUR(entity, p1, r, g, b) end

---@param p0 number
function GRAPHICS._0xD1472AFF30C103D6(p0) end

---@param scale number
function GRAPHICS.SET_PARTICLE_FX_BULLET_IMPACT_SCALE(scale) end

---@param scale number
function GRAPHICS.SET_PARTICLE_FX_BULLET_IMPACT_LODRANGE_SCALE(scale) end

---@param enabled boolean
function GRAPHICS._SET_SNIPER_GLINTS_ENABLED(enabled) end

---@param scale number
function GRAPHICS.SET_PARTICLE_FX_FOOT_LODRANGE_SCALE(scale) end

function GRAPHICS._0x4046493D2EEACA0E() end

---@param object integer
---@param toggle boolean
function GRAPHICS.SET_PICKUP_LIGHT(object, toggle) end

---@param pickupObject integer
---@param toggle boolean
function GRAPHICS._BLOCK_PICKUP_OBJECT_LIGHT(pickupObject, toggle) end

---@param pickup integer
---@param toggle boolean
function GRAPHICS.BLOCK_PICKUP_PLACEMENT_LIGHT(pickup, toggle) end

---@param pickupObject integer
---@param allow boolean
function GRAPHICS.ALLOW_PICKUP_LIGHT_SYNC(pickupObject, allow) end

---@param object integer
---@param toggle boolean
function GRAPHICS._SET_PEARLESCENT_FX_ENABLED(object, toggle) end

---@param posX number
---@param posY number
---@param posZ number
---@param range number
function GRAPHICS.REMOVE_DECALS_IN_RANGE(posX, posY, posZ, range) end

---@param ObjectIndex integer
function GRAPHICS.REMOVE_DECALS_FROM_OBJECT(ObjectIndex) end

---@param p0 any
---@param posX number
---@param posY number
---@param posZ number
---@param dirX number
---@param dirY number
---@param dirZ number
---@param sideX number
---@param sideY number
---@param sideZ number
---@param p10 any
---@param width number
---@param height number
---@param colR number
---@param colG number
---@param colB number
---@param colA number
---@param life number
---@param isLongRange boolean
---@param isDynamic boolean
---@param useComplexColn boolean
---@param p21 any
---@return integer
function GRAPHICS.ADD_DECAL(p0, posX, posY, posZ, dirX, dirY, dirZ, sideX, sideY, sideZ, p10, width, height, colR, colG, colB, colA, life, isLongRange, isDynamic, useComplexColn, p21) end

---@param x number
---@param y number
---@param z number
---@param unused boolean
function GRAPHICS._ADD_BLOOD_POOL(x, y, z, unused) end

---@param x number
---@param y number
---@param z number
---@param p3 number
---@param size number
---@param p5 number
---@param permanent boolean
---@param p7 number
---@param p8 boolean
function GRAPHICS._ADD_BLOOD_POOL_2(x, y, z, p3, size, p5, permanent, p7, p8) end

---@param ped integer
function GRAPHICS._ADD_BLOOD_POOLS_FOR_PED(ped) end

---@param ped integer
---@param p1 number
---@param size number
---@param p3 number
function GRAPHICS._ADD_BLOOD_POOLS_FOR_PED_WITH_PARAMS(ped, p1, size, p3) end

---@param p0 any
---@param width number
function GRAPHICS.START_PETROL_TRAIL_DECALS(p0, width) end

---@param posX number
---@param posY number
---@param posZ number
---@param alphaMult number
function GRAPHICS.ADD_PETROL_TRAIL_DECAL_INFO(posX, posY, posZ, alphaMult) end

function GRAPHICS.END_PETROL_TRAIL_DECALS() end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@return any
function GRAPHICS._0xE63D68F455CA0B47(p0, p1, p2, p3, p4, p5, p6) end

---@param decalId integer
function GRAPHICS.REMOVE_DECAL(decalId) end

---@param decalId integer
---@return boolean
function GRAPHICS.IS_DECAL_ALIVE(decalId) end

function GRAPHICS.SET_DISABLE_PETROL_DECALS_IGNITING_THIS_FRAME() end

function GRAPHICS._0xB032C085D9A03907() end

---@param p0 boolean
function GRAPHICS._0xFB680A9B33D0EDBE(p0) end

---@param p0 number
function GRAPHICS._0x41F88A85A579A61D(p0) end

---@param waypointRecording any
---@param p1 number
function GRAPHICS._BLOOD_TRAIL_FOR_WAYPOINT(waypointRecording, p1) end

---@param x number
---@param y number
---@param z number
function GRAPHICS._ADD_BLOOD_TRAIL_POINT(x, y, z) end

function GRAPHICS._0x812C1563185C6FB2() end

---@param p0 any
function GRAPHICS._0x4BD66B4E3427689B(p0) end

---@param x number
---@param y number
---@param z number
function GRAPHICS._ADD_BLOOD_TRAIL_SPLAT(x, y, z) end

function GRAPHICS._0xF2F543D48F319A3A() end

function GRAPHICS._0x1460B644397453EB() end

---@param disable boolean
function GRAPHICS._DISABLE_FAR_ARTIFICIAL_LIGHTS(disable) end

---@param p0 boolean
function GRAPHICS._0x453D16D41FC51D3E(p0) end

---@param entity integer
function GRAPHICS._0xC06F2F45A73EABCD(entity) end

---@param ModifierName any
function GRAPHICS.SET_TIMECYCLE_MODIFIER(ModifierName) end

---@param strength number
function GRAPHICS.SET_TIMECYCLE_MODIFIER_STRENGTH(strength) end

---@param ModifierName any
---@param time number
function GRAPHICS.SET_TRANSITION_TIMECYCLE_MODIFIER(ModifierName, time) end

---@param time number
function GRAPHICS.SET_TRANSITION_OUT_OF_TIMECYCLE_MODIFIER(time) end

function GRAPHICS.CLEAR_TIMECYCLE_MODIFIER() end

---@return integer
function GRAPHICS.GET_TIMECYCLE_MODIFIER_INDEX() end

---@return integer
function GRAPHICS.GET_TIMECYCLE_TRANSITION_MODIFIER_INDEX() end

---@param p0 any
function GRAPHICS._0x67B0778C62E74423(p0) end

---@param p0 any
function GRAPHICS._0x6C03118E9E5C1A14(p0) end

---@return number
function GRAPHICS._GET_MODIFIED_VISIBILITY_DISTANCE() end

---@param value number
function GRAPHICS.ENABLE_MOON_CYCLE_OVERRIDE(value) end

---@param iChannel integer
function GRAPHICS.SET_TV_CHANNEL(iChannel) end

---@return integer
function GRAPHICS.GET_TV_CHANNEL() end

---@param vol number
function GRAPHICS.SET_TV_VOLUME(vol) end

---@param CentreX number
---@param CentreY number
---@param Width number
---@param Height number
---@param Rotation number
---@param R integer
---@param G integer
---@param B integer
---@param A integer
function GRAPHICS.DRAW_TV_CHANNEL(CentreX, CentreY, Width, Height, Rotation, R, G, B, A) end

---@param iChannel integer
---@param playlistName any
---@param startFromNow boolean
function GRAPHICS.SET_TV_CHANNEL_PLAYLIST(iChannel, playlistName, startFromNow) end

---@param nameHash integer
---@return boolean
function GRAPHICS.IS_TVSHOW_CURRENTLY_PLAYING(nameHash) end

---@return any
function GRAPHICS._0x5C674EB487891F6B() end

---@param bOnOff boolean
function GRAPHICS.ENABLE_MOVIE_SUBTITLES(bOnOff) end

function GRAPHICS._0x32DE2BFFDA43E62A() end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function GRAPHICS._0xD543487A1F12828F(p0, p1, p2, p3) end

---@param p0 any
function GRAPHICS._0xD9BC98B55BCFAA9B(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function GRAPHICS._0x48FE0DB54045B975(p0, p1, p2, p3, p4, p5, p6) end

---@param p0 any
---@param p1 any
---@param p2 any
function GRAPHICS._0x735762E8D7573E42(p0, p1, p2) end

function GRAPHICS._0x981C7D863980FA51() end

---@param effectName any
function GRAPHICS._ANIMPOSTFX_PRELOAD_POSTFX(effectName) end

---@param effectName any
---@return boolean
function GRAPHICS._ANIMPOSTFX_HAS_LOADED(effectName) end

---@param effectName any
function GRAPHICS._ANIMPOSTFX_SET_TO_UNLOAD(effectName) end

---@param effectName any
function GRAPHICS.ANIMPOSTFX_PLAY(effectName) end

---@param effectName any
---@param duration integer
function GRAPHICS._ANIMPOSTFX_PLAY_TIMED(effectName, duration) end

---@param effectName any
function GRAPHICS.ANIMPOSTFX_STOP(effectName) end

---@param effectName any
---@param effectName2 any
---@param p2 any
---@param p3 any
function GRAPHICS._0x26DD2FB0A88CC412(effectName, effectName2, p2, p3) end

---@param effectName any
function GRAPHICS._ANIMPOSTFX_CLEAR_EFFECT(effectName) end

---@param effectName any
---@return boolean
function GRAPHICS.ANIMPOSTFX_IS_RUNNING(effectName) end

---@param effectName any
---@return boolean
function GRAPHICS._ANIMPOSTFX_IS_TAG_PLAYING(effectName) end

function GRAPHICS.ANIMPOSTFX_STOP_ALL() end

---@param effectName any
function GRAPHICS._ANIMPOSTFX_STOP_TAG(effectName) end

---@param effectName any
---@param strength number
function GRAPHICS._ANIMPOSTFX_SET_STRENGTH(effectName, strength) end

---@param effectName any
---@param p1 integer
---@param potency number
function GRAPHICS._ANIMPOSTFX_SET_POTENCY(effectName, p1, potency) end

---@param effectName any
---@param p1 integer
---@param red integer
---@param green integer
---@param blue integer
---@param alpha integer
function GRAPHICS._ANIMPOSTFX_SET_POSTFX_COLOR(effectName, p1, red, green, blue, alpha) end

---@param effectName any
---@return boolean
function GRAPHICS._0xB958D97A0DFAA0C2(effectName) end

---@param effectName any
function GRAPHICS._0xA201A3D0AC087C37(effectName) end

---@param effectName any
---@param p1 integer
---@param p2 boolean
---@param p3 boolean
---@return boolean
---@return boolean
function GRAPHICS._0xFBF161FCFEC8589E(effectName, p1, p2, p3) end

---@param effectName any
---@return integer
function GRAPHICS._ANIMPOSTFX_GET_STACKHASH(effectName) end

---@param effectNameHash integer
function GRAPHICS._ANIMPOSTFX_PRELOAD_POSTFX_BY_STACKHASH(effectNameHash) end

---@param effectNameHash integer
---@return boolean
function GRAPHICS.ANIMPOSTFX_IS_PRELOADING_BY_STACKHASH(effectNameHash) end

---@param effectNameHash integer
function GRAPHICS._0x38D9D50F2085E9B3(effectNameHash) end

---@param effectNameHash integer
function GRAPHICS._ANIMPOSTFX_PLAY_TAG(effectNameHash) end

---@param effectNameHash integer
function GRAPHICS._0xC76FC4C2FC5F4405(effectNameHash) end

---@param effectNameHash integer
function GRAPHICS._ANIMPOSTFX_STOP_STACKHASH_POSTFX(effectNameHash) end

---@param effectNameHash integer
---@return boolean
function GRAPHICS._ANIMPOSTFX_IS_STACKHASH_PLAYING(effectNameHash) end

---@param effectNameHash integer
---@return boolean
function GRAPHICS._0xE75CDDEBF618C8FF(effectNameHash) end

---@param effectNameHash integer
function GRAPHICS._0x71845905BCCDE781(effectNameHash) end

---@param effectNameHash integer
---@param p1 integer
---@param p2 boolean
---@param p3 boolean
---@return boolean
---@return boolean
function GRAPHICS.ANIMPOSTFX_HAS_EVENT_TRIGGERED_BY_STACKHASH(effectNameHash, p1, p2, p3) end

---@return boolean
function GRAPHICS._0xFF584F097C17FA8F() end

---@return boolean
function GRAPHICS._0x3DA7A10583A4BEC0() end

---@return any
function GRAPHICS._0xC37792A3F9C90771() end

---@param p0 any
---@param p1 any
function GRAPHICS._0xA0F4D12D6042F6D5(p0, p1) end

---@param p0 any
function GRAPHICS._0x8996FA6AD9FE4E90(p0) end

---@param vehicle integer
---@param toggle boolean
function GRAPHICS._SET_ENTITY_RENDER_GUARMA_SHIP(vehicle, toggle) end

---@return boolean
function GRAPHICS.PEDSHOT_IS_AVAILABLE() end

---@param p0 any
---@return boolean
function GRAPHICS._0xFD05B1DDE83749FA(p0) end

function GRAPHICS._PEDSHOT_FINISH_CLEANUP_DATA() end

function GRAPHICS._PEDSHOT_PREVIOUS_PERSONA_PHOTO_DATA_CLEANUP() end

function GRAPHICS._PEDSHOT_INIT_CLEANUP_DATA() end

---@param texture any
---@param ped integer
---@param playerSlot integer
---@return boolean
function GRAPHICS._PEDSHOT_GENERATE_PERSONA_PHOTO(texture, ped, playerSlot) end

---@param personaPhotoLocalCacheType integer
function GRAPHICS._PEDSHOT_SET_PERSONA_PHOTO_TYPE(personaPhotoLocalCacheType) end

---@param personaPhotoLocalCacheType integer
function GRAPHICS._0xA1A86055792FB249(personaPhotoLocalCacheType) end

---@param p0 any
---@param x number
---@param y number
---@param z number
---@param p4 number
---@param p5 number
---@param heading number
---@return boolean
function GRAPHICS._0x402E1A61D2587FCD(p0, x, y, z, p4, p5, heading) end

---@param p0 any
---@return any
function GRAPHICS._0x5C9C3A466B3296A8(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function GRAPHICS._0xA15CCAB8AD038291(p0, p1, p2, p3) end

---@return any
function GRAPHICS._0x285438C26C732F9D() end

---@param proxyInteriorIndex integer
---@param state boolean
function GRAPHICS._SET_PROXY_INTERIOR_INDEX_ARTIFICIAL_LIGHTS_STATE(proxyInteriorIndex, state) end

---@param proxyInteriorIndex integer
---@return boolean
function GRAPHICS._IS_PROXY_INTERIOR_INDEX_ARTIFICIAL_LIGHTS_ENABLED(proxyInteriorIndex) end

---@param interiorId integer
---@return integer
function GRAPHICS._GET_PROXY_INTERIOR_INDEX(interiorId) end

function GRAPHICS._0x9D1B0B5066205692() end

---@param p0 any
---@param p1 any
function GRAPHICS._0xC489FE31AC726512(p0, p1) end

---@param x number
---@param y number
---@param p2 integer
function GRAPHICS._SET_CLOUD_LAYER(x, y, p2) end

---@param x number
---@param y number
---@param z number
function GRAPHICS._SET_CLOUD_NOISE(x, y, z) end

---@param x number
---@param y number
---@param z number
function GRAPHICS._SET_CLOUD_POSITION(x, y, z) end

---@param height number
function GRAPHICS._SET_CLOUD_HEIGHT(height) end

---@param p0 any
---@param p1 any
function GRAPHICS._0x085C5B61A0114F32(p0, p1) end

---@param p0 any
---@param p1 any
function GRAPHICS._0x1FF8731BE1DFC0C0(p0, p1) end

---@return any
function GRAPHICS._0xFC9B53C072F418E0() end

---@param p0 any
function GRAPHICS._0x94B261F1F35293E1(p0) end

function GRAPHICS.ENABLE_ENTITYMASK() end

function GRAPHICS.DISABLE_ENTITYMASK() end

---@param entity integer
---@param mask integer
function GRAPHICS._ADD_ENTITY_TO_ENTITY_MASK(entity, mask) end

---@param entity integer
---@param mask integer
---@param intensity number
function GRAPHICS._ADD_ENTITY_TO_ENTITY_MASK_WITH_INTENSITY(entity, mask, intensity) end

---@param entity integer
function GRAPHICS._REMOVE_ENTITY_FROM_ENTITY_MASK(entity) end

---@param entity integer
---@param layer0 number
---@param layer1 number
---@param layer2 number
---@param layer3 number
---@return boolean
---@return number
---@return number
---@return number
---@return number
function GRAPHICS._GET_ENTITY_MASK_LAYERS(entity, layer0, layer1, layer2, layer3) end

---@param entity integer
---@param layer0 number
---@param layer1 number
---@param layer2 number
---@param layer3 number
---@return number
---@return number
---@return number
---@return number
function GRAPHICS._SET_ENTITY_MASK_LAYERS(entity, layer0, layer1, layer2, layer3) end

---@param p0 number
---@param p1 number
---@param p2 number
function GRAPHICS._SET_ENTITY_AURA(p0, p1, p2) end

function GRAPHICS._RESET_ENTITY_AURA() end

---@param type integer
function GRAPHICS._SET_SNOW_COVERAGE_TYPE(type) end

---@param p0 any
function GRAPHICS._0x519928DF02EB5101(p0) end

function GRAPHICS._0x1C6306E5BC25C29C() end
