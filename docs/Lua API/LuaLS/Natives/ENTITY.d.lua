---@meta

---@class ENTITY
ENTITY = {}

---@param EntityIndex integer
---@return boolean
function ENTITY.DOES_ENTITY_EXIST(EntityIndex) end

---@param EntityIndex integer
---@param bDeadCheck boolean
---@return boolean
function ENTITY.DOES_ENTITY_BELONG_TO_THIS_SCRIPT(EntityIndex, bDeadCheck) end

---@param EntityIndex integer
---@return boolean
function ENTITY.DOES_ENTITY_HAVE_DRAWABLE(EntityIndex) end

---@param EntityIndex integer
---@return boolean
function ENTITY.DOES_ENTITY_HAVE_PHYSICS(EntityIndex) end

---@param EntityIndex integer
---@return boolean
function ENTITY.HAS_ENTITY_BEEN_DAMAGED_BY_ANY_OBJECT(EntityIndex) end

---@param EntityIndex integer
---@return boolean
function ENTITY.HAS_ENTITY_BEEN_DAMAGED_BY_ANY_PED(EntityIndex) end

---@param EntityIndex integer
---@return boolean
function ENTITY.HAS_ENTITY_BEEN_DAMAGED_BY_ANY_VEHICLE(EntityIndex) end

---@param EntityIndex integer
---@param DamagerIndex integer
---@param p2 boolean
---@param p3 boolean
---@return boolean
function ENTITY.HAS_ENTITY_BEEN_DAMAGED_BY_ENTITY(EntityIndex, DamagerIndex, p2, p3) end

---@param entity1 integer
---@param entity2 integer
---@param p2 any
---@param p3 any
---@return boolean
function ENTITY._0x3EC28DA1FFAC9DDD(entity1, entity2, p2, p3) end

---@param entity integer
---@return integer
function ENTITY._0xAF72EC7E1B54539B(entity) end

---@param FirstEntityIndex integer
---@param SecondEntityIndex integer
---@param LOSFlags integer
---@return boolean
function ENTITY.HAS_ENTITY_CLEAR_LOS_TO_ENTITY(FirstEntityIndex, SecondEntityIndex, LOSFlags) end

---@param entity integer
---@param x number
---@param y number
---@param z number
---@param flags integer
---@return boolean
function ENTITY.HAS_ENTITY_CLEAR_LOS_TO_COORD(entity, x, y, z, flags) end

---@param FirstEntityIndex integer
---@param SecondEntityIndex integer
---@param traceType integer
---@return boolean
function ENTITY.HAS_ENTITY_CLEAR_LOS_TO_ENTITY_IN_FRONT(FirstEntityIndex, SecondEntityIndex, traceType) end

---@param EntityIndex integer
---@return boolean
function ENTITY.HAS_ENTITY_COLLIDED_WITH_ANYTHING(EntityIndex) end

---@param vehicle integer
---@return number
function ENTITY._0x6D58167F62238284(vehicle) end

---@param p0 any
---@param p1 any
---@return number
function ENTITY._0xDFC2B226D56D85F6(p0, p1) end

---@param pAnimDictName any
---@param pAnimName any
---@return number
function ENTITY.GET_ANIM_DURATION(pAnimDictName, pAnimName) end

---@param EntityIndex integer
---@return integer
function ENTITY.GET_ENTITY_ATTACHED_TO(EntityIndex) end

---@param EntityIndex integer
---@param DoDeadCheck boolean
---@param realCoords boolean
---@return Vector3
function ENTITY.GET_ENTITY_COORDS(EntityIndex, DoDeadCheck, realCoords) end

---@param EntityIndex integer
---@return Vector3
function ENTITY.GET_ENTITY_FORWARD_VECTOR(EntityIndex) end

---@param EntityIndex integer
---@return number
function ENTITY.GET_ENTITY_FORWARD_X(EntityIndex) end

---@param EntityIndex integer
---@return number
function ENTITY.GET_ENTITY_FORWARD_Y(EntityIndex) end

---@param entity integer
---@return Vector3
function ENTITY._GET_ENTITY_FORWARD_VECTOR_YX(entity) end

---@param EntityIndex integer
---@return number
function ENTITY.GET_ENTITY_HEADING(EntityIndex) end

---@param EntityIndex integer
---@return integer
function ENTITY.GET_ENTITY_HEALTH(EntityIndex) end

---@param entity integer
---@return number
function ENTITY._GET_ENTITY_HEALTH_FLOAT(entity) end

---@param entity integer
---@param amount number
---@param entity2 integer
---@param weaponHash integer
---@return boolean
function ENTITY._CHANGE_ENTITY_HEALTH(entity, amount, entity2, weaponHash) end

---@param EntityIndex integer
---@param p1 boolean
---@return integer
function ENTITY.GET_ENTITY_MAX_HEALTH(EntityIndex, p1) end

---@param EntityIndex integer
---@param Health integer
function ENTITY.SET_ENTITY_MAX_HEALTH(EntityIndex, Health) end

---@param EntityIndex integer
---@param PositionX number
---@param PositionY number
---@param PositionZ number
---@param IsWorldPos boolean
---@param WantWorldResult boolean
---@return number
function ENTITY.GET_ENTITY_HEIGHT(EntityIndex, PositionX, PositionY, PositionZ, IsWorldPos, WantWorldResult) end

---@param EntityIndex integer
---@return number
function ENTITY.GET_ENTITY_HEIGHT_ABOVE_GROUND(EntityIndex) end

---@param entity integer
---@param minimum Vector3
---@param maximum Vector3
---@return Vector3
---@return Vector3
function ENTITY._GET_ENTITY_WORLD_POSITION_OF_DIMENSIONS(entity, minimum, maximum) end

---@param EntityIndex integer
---@param vFront Vector3
---@param vSide Vector3
---@param vUp Vector3
---@param vPos Vector3
---@return Vector3
---@return Vector3
---@return Vector3
---@return Vector3
function ENTITY.GET_ENTITY_MATRIX(EntityIndex, vFront, vSide, vUp, vPos) end

---@param EntityIndex integer
---@return integer
function ENTITY.GET_ENTITY_MODEL(EntityIndex) end

---@param ped integer
---@return integer
function ENTITY._GET_PED_ANIMAL_TYPE(ped) end

---@param entity integer
---@return boolean
function ENTITY.GET_IS_ANIMAL(entity) end

---@param entity integer
---@return boolean
function ENTITY._GET_IS_BIRD(entity) end

---@param entity integer
---@return boolean
function ENTITY._GET_IS_PREDATOR(entity) end

---@param EntityIndex integer
---@param VecWorldCoorsX number
---@param VecWorldCoorsY number
---@param VecWorldCoorsZ number
---@return Vector3
function ENTITY.GET_OFFSET_FROM_ENTITY_GIVEN_WORLD_COORDS(EntityIndex, VecWorldCoorsX, VecWorldCoorsY, VecWorldCoorsZ) end

---@param EntityIndex integer
---@param VecNewCoorsX number
---@param VecNewCoorsY number
---@param VecNewCoorsZ number
---@return Vector3
function ENTITY.GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(EntityIndex, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ) end

---@param EntityIndex integer
---@return number
function ENTITY.GET_ENTITY_PITCH(EntityIndex) end

---@param EntityIndex integer
---@return number
function ENTITY.GET_ENTITY_ROLL(EntityIndex) end

---@param EntityIndex integer
---@param RotOrder integer
---@return Vector3
function ENTITY.GET_ENTITY_ROTATION(EntityIndex, RotOrder) end

---@param entity integer
---@param argStruct integer
---@return integer
function ENTITY._GET_ENTITY_SCRIPT(entity, argStruct) end

---@param EntityIndex integer
---@return number
function ENTITY.GET_ENTITY_SPEED(EntityIndex) end

---@param EntityIndex integer
---@param bLocalResult boolean
---@return Vector3
function ENTITY.GET_ENTITY_SPEED_VECTOR(EntityIndex, bLocalResult) end

---@param EntityIndex integer
---@return number
function ENTITY.GET_ENTITY_UPRIGHT_VALUE(EntityIndex) end

---@param EntityIndex integer
---@param p1 integer
---@return Vector3
function ENTITY.GET_ENTITY_VELOCITY(EntityIndex, p1) end

---@param EntityIndex integer
---@return integer
function ENTITY.GET_OBJECT_INDEX_FROM_ENTITY_INDEX(EntityIndex) end

---@param EntityIndex integer
---@return integer
function ENTITY.GET_PED_INDEX_FROM_ENTITY_INDEX(EntityIndex) end

---@param EntityIndex integer
---@return integer
function ENTITY.GET_VEHICLE_INDEX_FROM_ENTITY_INDEX(EntityIndex) end

---@param EntityIndex integer
---@param iBoneIdx integer
---@return Vector3
function ENTITY.GET_WORLD_POSITION_OF_ENTITY_BONE(EntityIndex, iBoneIdx) end

---@param entity integer
---@param boneIndex integer
---@return Vector3
function ENTITY._0x5E214112806591EA(entity, boneIndex) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return Vector3
function ENTITY._0x3AB3A77672F6473F(p0, p1, p2, p3) end

---@param entityIndex integer
---@param playerPedToIgnore integer
---@param flags integer
---@return integer
function ENTITY.GET_NEAREST_PLAYER_TO_ENTITY(entityIndex, playerPedToIgnore, flags) end

---@param entityIndex integer
---@param team integer
---@param playerPedToIgnore integer
---@param flags integer
---@return integer
function ENTITY.GET_NEAREST_PLAYER_TO_ENTITY_ON_TEAM(entityIndex, team, playerPedToIgnore, flags) end

---@param entity integer
---@return integer
function ENTITY.GET_NEAREST_PARTICIPANT_TO_ENTITY(entity) end

---@param entity integer
---@param p1 boolean
---@return boolean
function ENTITY.PLACE_ENTITY_ON_GROUND_PROPERLY(entity, p1) end

---@param EntityIndex integer
---@return integer
function ENTITY.GET_ENTITY_TYPE(EntityIndex) end

---@param EntityIndex integer
---@return integer
function ENTITY.GET_ENTITY_POPULATION_TYPE(EntityIndex) end

---@param obj integer
---@return boolean
function ENTITY.IS_AN_ENTITY(obj) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_A_PED(EntityIndex) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_A_MISSION_ENTITY(EntityIndex) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_A_VEHICLE(EntityIndex) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_AN_OBJECT(EntityIndex) end

---@param EntityIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param VecLocDimensionsX number
---@param VecLocDimensionsY number
---@param VecLocDimensionsZ number
---@param HighlightArea boolean
---@param Do3dCheck boolean
---@param TM_MODE integer
---@return boolean
function ENTITY.IS_ENTITY_AT_COORD(EntityIndex, VecCoorsX, VecCoorsY, VecCoorsZ, VecLocDimensionsX, VecLocDimensionsY, VecLocDimensionsZ, HighlightArea, Do3dCheck, TM_MODE) end

---@param EntityIndex integer
---@param TargetEntityIndex integer
---@param VecLocDimensionsX number
---@param VecLocDimensionsY number
---@param VecLocDimensionsZ number
---@param HighlightArea boolean
---@param Do3dCheck boolean
---@param TM_MODE integer
---@return boolean
function ENTITY.IS_ENTITY_AT_ENTITY(EntityIndex, TargetEntityIndex, VecLocDimensionsX, VecLocDimensionsY, VecLocDimensionsZ, HighlightArea, Do3dCheck, TM_MODE) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_ATTACHED(EntityIndex) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_ATTACHED_TO_ANY_OBJECT(EntityIndex) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_ATTACHED_TO_ANY_PED(EntityIndex) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_ATTACHED_TO_ANY_VEHICLE(EntityIndex) end

---@param EntityIndex1 integer
---@param EntityIndex2 integer
---@return boolean
function ENTITY.IS_ENTITY_ATTACHED_TO_ENTITY(EntityIndex1, EntityIndex2) end

---@param entity integer
---@return boolean
function ENTITY._IS_ENTITY_OWNED_BY_PERSISTENCE_SYSTEM(entity) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_DEAD(EntityIndex) end

---@param EntityIndex integer
---@param p1 any
---@return boolean
function ENTITY.IS_ENTITY_IN_AIR(EntityIndex, p1) end

---@param EntityIndex integer
---@param VecCoors1X number
---@param VecCoors1Y number
---@param VecCoors1Z number
---@param VecCoors2X number
---@param VecCoors2Y number
---@param VecCoors2Z number
---@param AreaWidth number
---@param HighlightArea boolean
---@param Do3dCheck boolean
---@param TM_MODE integer
---@return boolean
function ENTITY.IS_ENTITY_IN_ANGLED_AREA(EntityIndex, VecCoors1X, VecCoors1Y, VecCoors1Z, VecCoors2X, VecCoors2Y, VecCoors2Z, AreaWidth, HighlightArea, Do3dCheck, TM_MODE) end

---@param EntityIndex integer
---@param VecCoors1X number
---@param VecCoors1Y number
---@param VecCoors1Z number
---@param VecCoors2X number
---@param VecCoors2Y number
---@param VecCoors2Z number
---@param HighlightArea boolean
---@param Do3dCheck boolean
---@param TM_MODE integer
---@return boolean
function ENTITY.IS_ENTITY_IN_AREA(EntityIndex, VecCoors1X, VecCoors1Y, VecCoors1Z, VecCoors2X, VecCoors2Y, VecCoors2Z, HighlightArea, Do3dCheck, TM_MODE) end

---@param entity integer
---@param volume integer
---@param p2 boolean
---@param p3 integer
---@return boolean
function ENTITY.IS_ENTITY_IN_VOLUME(entity, volume, p2, p3) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_IN_WATER(EntityIndex) end

---@param entity integer
---@param p1 boolean
---@return boolean
function ENTITY._IS_ENTITY_UNDERWATER(entity, p1) end

---@param EntityIndex integer
---@return number
function ENTITY.GET_ENTITY_SUBMERGED_LEVEL(EntityIndex) end

---@param EntityIndex integer
---@param FlagValue boolean
function ENTITY.SET_ENTITY_REQUIRES_MORE_EXPENSIVE_RIVER_CHECK(EntityIndex, FlagValue) end

---@param p0 any
---@param p1 any
function ENTITY._0x7A49D40DE437BC8D(p0, p1) end

---@param p0 any
---@param p1 any
function ENTITY._0x978AA2323ED32209(p0, p1) end

---@param p0 any
---@param p1 any
function ENTITY._0x002AAC783ED323ED(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function ENTITY._0x007AAC783ED323ED(p0, p1, p2) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_ON_SCREEN(EntityIndex) end

---@param EntityIndex integer
---@param AnimDictName any
---@param AnimName any
---@param type integer
---@return boolean
function ENTITY.IS_ENTITY_PLAYING_ANIM(EntityIndex, AnimDictName, AnimName, type) end

---@param entity integer
---@param p1 integer
---@return boolean
function ENTITY._IS_ENTITY_PLAYING_ANY_ANIM(entity, p1) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_STATIC(EntityIndex) end

---@param FirstEntityIndex integer
---@param SecondEntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_TOUCHING_ENTITY(FirstEntityIndex, SecondEntityIndex) end

---@param EntityIndex integer
---@param ModelHashKey integer
---@return boolean
function ENTITY.IS_ENTITY_TOUCHING_MODEL(EntityIndex, ModelHashKey) end

---@param EntityIndex integer
---@param fAngleToVerticalLimit number
---@return boolean
function ENTITY.IS_ENTITY_UPRIGHT(EntityIndex, fAngleToVerticalLimit) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_UPSIDEDOWN(EntityIndex) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_VISIBLE(EntityIndex) end

---@param entity integer
---@param toggle boolean
function ENTITY._0xFF9965C47FA404DA(entity, toggle) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_VISIBLE_TO_SCRIPT(EntityIndex) end

---@param p0 any
function ENTITY._0x3F08C6163A4AB1D6(p0) end

---@param p0 any
function ENTITY._0x0DB41D59E0F1502B(p0) end

---@param entity integer
---@return boolean
function ENTITY._IS_TRACKED_ENTITY_VISIBLE(entity) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_OCCLUDED(EntityIndex) end

---@param ModelHashKey integer
---@param CoordsX number
---@param CoordsY number
---@param CoordsZ number
---@param bAssertIfModelIsntLoaded boolean
---@return boolean
function ENTITY.WOULD_ENTITY_BE_OCCLUDED(ModelHashKey, CoordsX, CoordsY, CoordsZ, bAssertIfModelIsntLoaded) end

---@param EntityIndex integer
---@return boolean
function ENTITY.IS_ENTITY_WAITING_FOR_WORLD_COLLISION(EntityIndex) end

---@param entity integer
---@return boolean
function ENTITY._IS_ENTITY_ON_TRAIN_TRACK(entity) end

---@param entity integer
---@param p1 integer
function ENTITY._0xCDB682BB47C02F0A(entity, p1) end

---@param p0 any
---@param p1 any
function ENTITY._0xE19035EB65AB2932(p0, p1) end

---@param entity integer
---@param lootTable integer
---@return boolean
function ENTITY.SCRIPT_OVERRIDE_ENTITY_LOOT_TABLE_PERMANENT(entity, lootTable) end

---@param entity integer
---@param lootTable integer
---@return boolean
---@return integer
function ENTITY._GET_SCRIPT_OVERRIDE_ENTITY_LOOT_TABLE_PERMANENT(entity, lootTable) end

---@param mount integer
---@param argStruct integer
---@param visiblelootslotrequestType integer
---@param flag integer
---@param p4 integer
---@param p5 boolean
---@return boolean
function ENTITY._REQUEST_ENTITY_LOOT_LIST(mount, argStruct, visiblelootslotrequestType, flag, p4, p5) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function ENTITY._0xE31FC20319874CB3(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function ENTITY._0x582F73ACFE969571(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@return any
function ENTITY._0xBA2A089E60ED1163(p0, p1, p2, p3, p4) end

---@param entity integer
---@return integer
function ENTITY.GET_CARRIABLE_ENTITY_STATE(entity) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function ENTITY._0xD46BF94C4C66FAB0(p0, p1, p2, p3) end

---@param entity integer
---@param index integer
---@return integer
function ENTITY._GET_OPTIMAL_CARRY_CONFIG(entity, index) end

---@param p0 any
---@return any
function ENTITY._0xD21C7418C590BB40(p0) end

---@param entity integer
---@return integer
function ENTITY._GET_ENTITY_CARRY_CONFIG(entity) end

---@param model integer
---@return boolean
function ENTITY._IS_CARRIABLE_MODEL(model) end

---@param entity integer
---@return integer
function ENTITY._GET_CARRIABLE_FROM_ENTITY(entity) end

---@param entity integer
---@param type integer
function ENTITY._SET_ENTITY_CARCASS_TYPE(entity, type) end

---@param p0 any
---@return any
function ENTITY._0x2A77EF9BEC8518F4(p0) end

---@param entity integer
---@return integer
function ENTITY._DELETE_CARRIABLE(entity) end

---@param entity integer
---@return boolean
function ENTITY._IS_ENTITY_FULLY_LOOTED(entity) end

---@param entity integer
---@param looted boolean
function ENTITY._SET_ENTITY_FULLY_LOOTED(entity, looted) end

---@param ped integer
---@return integer
function ENTITY._0xEF2D9ED7CE684F08(ped) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function ENTITY._0x0CCEFC6C2C95DA2A(p0, p1, p2, p3) end

---@param p0 integer
---@param entity integer
---@param p2 integer
---@param ped integer
---@param p4 any
---@param p5 integer
---@return boolean
---@return integer
function ENTITY._0x383F64263F946E45(p0, entity, p2, ped, p4, p5) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@return any
function ENTITY._0x8E10DF0FFA63FB65(p0, p1, p2, p3, p4) end

---@param entity integer
---@param flagId integer
---@return boolean
function ENTITY._GET_ENTITY_CARRYING_FLAG(entity, flagId) end

---@param entity integer
---@param flagId integer
---@param value boolean
function ENTITY._SET_ENTITY_CARRYING_FLAG(entity, flagId, value) end

---@param ped integer
---@param p1 integer
---@param p2 boolean
function ENTITY._0xC3ABCFBC7D74AFA5(ped, p1, p2) end

---@param entity integer
function ENTITY._0x371D179701D9C082(entity) end

---@param entity integer
---@param p1 boolean
function ENTITY._0xA48E4801DEBDF7E4(entity, p1) end

---@param entity integer
---@return boolean
function ENTITY._GET_IS_CARRIABLE_PELT(entity) end

---@param p0 any
---@return any
function ENTITY._0xF59FDE7B4D31A630(p0) end

---@param p0 any
---@param p1 any
---@return any
function ENTITY._0x120376C23F019C6C(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@return any
function ENTITY._0x5744562E973E33CD(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function ENTITY._0xDD03FC2089AD093C(p0, p1, p2, p3) end

---@param p0 any
---@return any
function ENTITY._0xB16C780C51E51E2B(p0) end

---@param entity integer
---@param p1 any
function ENTITY._0xEF259AA1E097E0AD(entity, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function ENTITY._0xBD94CECFB2D65119(p0, p1, p2, p3, p4, p5) end

---@param entity integer
---@param radius number
function ENTITY._SET_ENTITY_CUSTOM_PICKUP_RADIUS(entity, radius) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function ENTITY._0xE75EEA8DB59A9F39(p0, p1, p2, p3, p4, p5) end

---@param p0 any
---@param p1 any
---@return any
function ENTITY._0x188736456D1DEDE6(p0, p1) end

---@param p0 any
---@param p1 any
function ENTITY._0xC6A1A3D63F122DE7(p0, p1) end

---@param EntityIndex integer
---@param ApplyType integer
---@param vForceX number
---@param vForceY number
---@param vForceZ number
---@param Component integer
---@param LocalForce boolean
---@param ScaleByMass boolean
---@param applyToChildren boolean
function ENTITY.APPLY_FORCE_TO_ENTITY_CENTER_OF_MASS(EntityIndex, ApplyType, vForceX, vForceY, vForceZ, Component, LocalForce, ScaleByMass, applyToChildren) end

---@param EntityIndex integer
---@param ApplyType integer
---@param vForceX number
---@param vForceY number
---@param vForceZ number
---@param vOffsetX number
---@param vOffsetY number
---@param vOffsetZ number
---@param Component integer
---@param LocalForce boolean
---@param LocalOffset boolean
---@param ScaleByMass boolean
---@param triggerAudio boolean
---@param ScaleByTimeWarp boolean
function ENTITY.APPLY_FORCE_TO_ENTITY(EntityIndex, ApplyType, vForceX, vForceY, vForceZ, vOffsetX, vOffsetY, vOffsetZ, Component, LocalForce, LocalOffset, ScaleByMass, triggerAudio, ScaleByTimeWarp) end

---@param FirstEntityIndex integer
---@param SecondEntityIndex integer
---@param SecondEntityBoneIndex integer
---@param vecOffsetX number
---@param vecOffsetY number
---@param vecOffsetZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
---@param p9 boolean
---@param useSoftPinning boolean
---@param collision boolean
---@param isPed boolean
---@param RotOrder integer
---@param bAttachOffsetIsRelative boolean
---@param p15 boolean
---@param p16 boolean
function ENTITY.ATTACH_ENTITY_TO_ENTITY(FirstEntityIndex, SecondEntityIndex, SecondEntityBoneIndex, vecOffsetX, vecOffsetY, vecOffsetZ, vecRotationX, vecRotationY, vecRotationZ, p9, useSoftPinning, collision, isPed, RotOrder, bAttachOffsetIsRelative, p15, p16) end

---@param FirstEntityIndex integer
---@param SecondEntityIndex integer
---@param FirstEntityBoneIndex integer
---@param SecondEntityBoneIndex integer
---@param SecondEntityOffsetX number
---@param SecondEntityOffsetY number
---@param SecondEntityOffsetZ number
---@param FirstEntityOffsetX number
---@param FirstEntityOffsetY number
---@param FirstEntityOffsetZ number
---@param vecRotationX number
---@param vecRotationY number
---@param vecRotationZ number
---@param PhysicalStrength number
---@param p14 boolean
---@param p15 boolean
---@param p16 boolean
---@param p17 boolean
---@param RotOrder integer
---@param p19 boolean
---@param p20 number
---@param p21 number
function ENTITY.ATTACH_ENTITY_TO_ENTITY_PHYSICALLY(FirstEntityIndex, SecondEntityIndex, FirstEntityBoneIndex, SecondEntityBoneIndex, SecondEntityOffsetX, SecondEntityOffsetY, SecondEntityOffsetZ, FirstEntityOffsetX, FirstEntityOffsetY, FirstEntityOffsetZ, vecRotationX, vecRotationY, vecRotationZ, PhysicalStrength, p14, p15, p16, p17, RotOrder, p19, p20, p21) end

---@param entity integer
---@param x number
---@param y number
---@param z number
---@param offsetx number
---@param offsety number
---@param offsetz number
---@param timer number
---@param p8 boolean
---@param p9 integer
---@param p10 integer
---@param p11 integer
---@param p12 integer
---@param p13 integer
---@param p14 integer
function ENTITY._ATTACH_ENTITY_TO_COORDS_PHYSICALLY(entity, x, y, z, offsetx, offsety, offsetz, timer, p8, p9, p10, p11, p12, p13, p14) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
---@param p9 any
---@param p10 any
---@param p11 any
---@param p12 any
---@param p13 any
---@param p14 any
---@param p15 any
function ENTITY._0x445D7D8EA66E373E(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function ENTITY._0x16908E859C3AB698(p0, p1, p2, p3, p4) end

---@param EntityIndex integer
---@param BoneName any
---@return integer
function ENTITY.GET_ENTITY_BONE_INDEX_BY_NAME(EntityIndex, BoneName) end

---@param EntityIndex integer
function ENTITY.CLEAR_ENTITY_LAST_DAMAGE_ENTITY(EntityIndex) end

---@param EntityIndex integer
---@return integer
function ENTITY.DELETE_ENTITY(EntityIndex) end

---@param entity integer
---@return integer
function ENTITY._DELETE_ENTITY_2(entity) end

---@param EntityIndex integer
---@param ApplyVelocity boolean
---@param bNoCollisionUntilClear boolean
function ENTITY.DETACH_ENTITY(EntityIndex, ApplyVelocity, bNoCollisionUntilClear) end

---@param entity integer
---@return boolean
function ENTITY._IS_ENTITY_FROZEN(entity) end

---@param EntityIndex integer
---@param FrozenByScriptFlag boolean
function ENTITY.FREEZE_ENTITY_POSITION(EntityIndex, FrozenByScriptFlag) end

---@param EntityIndex integer
---@param ShouldFreeze boolean
function ENTITY.SET_ENTITY_SHOULD_FREEZE_WAITING_ON_COLLISION(EntityIndex, ShouldFreeze) end

---@param EntityIndex integer
---@param ScriptHostObject boolean
---@param GrabFromOtherScript boolean
function ENTITY.SET_ENTITY_AS_MISSION_ENTITY(EntityIndex, ScriptHostObject, GrabFromOtherScript) end

---@param EntityIndex integer
---@return integer
function ENTITY.SET_ENTITY_AS_NO_LONGER_NEEDED(EntityIndex) end

---@param PedIndex integer
---@return integer
function ENTITY.SET_PED_AS_NO_LONGER_NEEDED(PedIndex) end

---@param VehicleIndex integer
---@return integer
function ENTITY.SET_VEHICLE_AS_NO_LONGER_NEEDED(VehicleIndex) end

---@param ObjectIndex integer
---@return integer
function ENTITY.SET_OBJECT_AS_NO_LONGER_NEEDED(ObjectIndex) end

function ENTITY._0x20FAEE47427A4497() end

---@param entity integer
---@return boolean
function ENTITY._DOES_THREAD_OWN_THIS_ENTITY(entity) end

---@param p0 any
---@param p1 any
function ENTITY._0x56E0735D6273B227(p0, p1) end

---@param entity integer
---@param p1 number
function ENTITY._0xC0EDEF16D90661EE(entity, p1) end

---@param p0 any
function ENTITY._0x0FD7D7C232876E72(p0) end

function ENTITY._0x0939E773925C4719() end

---@param EntityIndex integer
---@param CanBeDamagedFlag boolean
function ENTITY.SET_ENTITY_CAN_BE_DAMAGED(EntityIndex, CanBeDamagedFlag) end

---@param entity integer
---@return boolean
function ENTITY._GET_ENTITY_CAN_BE_DAMAGED(entity) end

---@param EntityIndex integer
---@param AllowDamagedByRelGroup boolean
---@param relGroup integer
function ENTITY.SET_ENTITY_CAN_BE_DAMAGED_BY_RELATIONSHIP_GROUP(EntityIndex, AllowDamagedByRelGroup, relGroup) end

---@param p0 any
---@param p1 any
function ENTITY._0xFF83AF534156B399(p0, p1) end

---@param EntityIndex integer
---@param TargettableWithNoLos boolean
function ENTITY.SET_ENTITY_CAN_BE_TARGETED_WITHOUT_LOS(EntityIndex, TargettableWithNoLos) end

---@param EntityIndex integer
---@return boolean
function ENTITY.GET_ENTITY_COLLISION_DISABLED(EntityIndex) end

---@param EntityIndex integer
---@param UsesCollisionsFlag boolean
---@param KeepDisabledSimulatingFlag boolean
function ENTITY.SET_ENTITY_COLLISION(EntityIndex, UsesCollisionsFlag, KeepDisabledSimulatingFlag) end

---@param EntityIndex integer
---@param UsesCollisionsFlag boolean
---@param KeepDisabledSimulatingFlag boolean
function ENTITY.SET_ENTITY_COMPLETELY_DISABLE_COLLISION(EntityIndex, UsesCollisionsFlag, KeepDisabledSimulatingFlag) end

---@param EntityIndex integer
---@param VecNewCoorsX number
---@param VecNewCoorsY number
---@param VecNewCoorsZ number
---@param DoDeadCheck boolean
---@param KeepTasks boolean
---@param KeepIK boolean
---@param DoWarp boolean
function ENTITY.SET_ENTITY_COORDS(EntityIndex, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, DoDeadCheck, KeepTasks, KeepIK, DoWarp) end

---@param EntityIndex integer
---@param VecNewCoorsX number
---@param VecNewCoorsY number
---@param VecNewCoorsZ number
---@param KeepTasks boolean
---@param KeepIK boolean
---@param DoWarp boolean
function ENTITY.SET_ENTITY_COORDS_NO_OFFSET(EntityIndex, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, KeepTasks, KeepIK, DoWarp) end

---@param EntityIndex integer
---@param IsDynamic boolean
function ENTITY.SET_ENTITY_DYNAMIC(EntityIndex, IsDynamic) end

---@param EntityIndex integer
---@param NewHeading number
function ENTITY.SET_ENTITY_HEADING(EntityIndex, NewHeading) end

---@param entity integer
---@param xPos number
---@param yPos number
---@param zPos number
---@param heading number
---@param xAxis boolean
---@param yAxis boolean
---@param zAxis boolean
function ENTITY._SET_ENTITY_COORDS_AND_HEADING(entity, xPos, yPos, zPos, heading, xAxis, yAxis, zAxis) end

---@param entity integer
---@param xPos number
---@param yPos number
---@param zPos number
---@param heading number
---@param p5 boolean
---@param p6 boolean
function ENTITY._SET_ENTITY_COORDS_AND_HEADING_NO_OFFSET(entity, xPos, yPos, zPos, heading, p5, p6) end

---@param entity integer
---@param healthAmount integer
---@param entityKilledBy integer
function ENTITY.SET_ENTITY_HEALTH(entity, healthAmount, entityKilledBy) end

---@param EntityIndex integer
---@param bInvincible boolean
function ENTITY.SET_ENTITY_INVINCIBLE(EntityIndex, bInvincible) end

---@param entity integer
---@param p1 number
---@param p2 number
---@param p3 number
function ENTITY._0xAF7F3099B9FEB535(entity, p1, p2, p3) end

---@param EntityIndex integer
---@param bHighPriority boolean
---@param fTargetableDistance number
function ENTITY.SET_ENTITY_IS_TARGET_PRIORITY(EntityIndex, bHighPriority, fTargetableDistance) end

---@param p0 any
---@param p1 any
---@param p2 any
function ENTITY._0xB38A29CCD5447783(p0, p1, p2) end

---@param entity integer
---@param tier integer
---@param p2 boolean
function ENTITY._SET_ENTITY_THREAT_TIER(entity, tier, p2) end

---@param entity integer
---@return integer
function ENTITY._GET_ENTITY_THREAT_TIER(entity) end

---@param p0 any
---@param p1 any
function ENTITY._0x2D40BCBFE9305DEA(p0, p1) end

---@param entity integer
---@param enabled boolean
function ENTITY._SET_ENTITY_LIGHTS_ENABLED(entity, enabled) end

---@param EntityIndex integer
---@param LoadCollisionFlag boolean
function ENTITY.SET_ENTITY_LOAD_COLLISION_FLAG(EntityIndex, LoadCollisionFlag) end

---@param EntityIndex integer
---@return boolean
function ENTITY.HAS_COLLISION_LOADED_AROUND_ENTITY(EntityIndex) end

---@param xPos number
---@param yPos number
---@param zPos number
---@return boolean
function ENTITY.HAS_COLLISION_LOADED_AROUND_POSITION(xPos, yPos, zPos) end

---@param EntityIndex integer
---@param OnlyDamagedByPlayer boolean
function ENTITY.SET_ENTITY_ONLY_DAMAGED_BY_PLAYER(EntityIndex, OnlyDamagedByPlayer) end

---@param EntityIndex integer
---@param OnlyDamagedByRelGroup boolean
---@param relGroup integer
function ENTITY.SET_ENTITY_ONLY_DAMAGED_BY_RELATIONSHIP_GROUP(EntityIndex, OnlyDamagedByRelGroup, relGroup) end

---@param EntityIndex integer
---@param proofsBitset integer
---@param specialFlag boolean
function ENTITY.SET_ENTITY_PROOFS(EntityIndex, proofsBitset, specialFlag) end

---@param entity integer
---@return integer
function ENTITY._GET_ENTITY_PROOFS(entity) end

---@param EntityIndex integer
---@param NewX number
---@param NewY number
---@param NewZ number
---@param NewW number
function ENTITY.SET_ENTITY_QUATERNION(EntityIndex, NewX, NewY, NewZ, NewW) end

---@param EntityIndex integer
---@param VecNewRotationX number
---@param VecNewRotationY number
---@param VecNewRotationZ number
---@param RotOrder integer
---@param DoDeadCheck boolean
function ENTITY.SET_ENTITY_ROTATION(EntityIndex, VecNewRotationX, VecNewRotationY, VecNewRotationZ, RotOrder, DoDeadCheck) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
function ENTITY._0xD45BB89B53FC0CFD(p0, p1, p2, p3, p4, p5, p6, p7) end

---@param EntityIndex integer
---@param VisibleFlag boolean
function ENTITY.SET_ENTITY_VISIBLE(EntityIndex, VisibleFlag) end

---@param entity integer
---@param p1 boolean
function ENTITY._0x80FDEB3A9E9AA578(entity, p1) end

---@param entity integer
function ENTITY._0x9C6906EF8CB20C5F(entity) end

---@param EntityIndex integer
---@param VecVelocityComponenttX number
---@param VecVelocityComponenttY number
---@param VecVelocityComponenttZ number
function ENTITY.SET_ENTITY_VELOCITY(EntityIndex, VecVelocityComponenttX, VecVelocityComponenttY, VecVelocityComponenttZ) end

---@param EntityIndex integer
---@param bHasGravity boolean
function ENTITY.SET_ENTITY_HAS_GRAVITY(EntityIndex, bHasGravity) end

---@param entityIndex integer
---@param lodDist integer
function ENTITY.SET_ENTITY_LOD_DIST(entityIndex, lodDist) end

---@param entityIndex integer
---@return integer
function ENTITY.GET_ENTITY_LOD_DIST(entityIndex) end

---@param entityIndex integer
---@param alpha_param integer
---@param bUseSmoothAlpha boolean
function ENTITY.SET_ENTITY_ALPHA(entityIndex, alpha_param, bUseSmoothAlpha) end

---@param entityIndex integer
---@return integer
function ENTITY.GET_ENTITY_ALPHA(entityIndex) end

---@param entityIndex integer
function ENTITY.RESET_ENTITY_ALPHA(entityIndex) end

---@param entity integer
function ENTITY._SET_ENTITY_FADE_IN(entity) end

---@param entityIndex integer
---@param bAlwaysPreRender boolean
function ENTITY.SET_ENTITY_ALWAYS_PRERENDER(entityIndex, bAlwaysPreRender) end

---@param entityIndex integer
---@param bRenderScorched boolean
function ENTITY.SET_ENTITY_RENDER_SCORCHED(entityIndex, bRenderScorched) end

---@param entity integer
---@return any
function ENTITY._0x37B01666BAE8F7EF(entity) end

---@param p0 any
---@param p1 any
function ENTITY._0xA9E6D8F2DDFC4DB9(p0, p1) end

---@param posX number
---@param posY number
---@param posZ number
---@param radius number
---@param oldModelHash integer
---@param newModelHash integer
---@param bSurviveMapReload boolean
function ENTITY.CREATE_MODEL_SWAP(posX, posY, posZ, radius, oldModelHash, newModelHash, bSurviveMapReload) end

---@param posX number
---@param posY number
---@param posZ number
---@param radius number
---@param oldModelHash integer
---@param newModelHash integer
---@param bLazy boolean
function ENTITY.REMOVE_MODEL_SWAP(posX, posY, posZ, radius, oldModelHash, newModelHash, bLazy) end

---@param posX number
---@param posY number
---@param posZ number
---@param radius number
---@param modelHash integer
---@param bSurviveMapReload boolean
function ENTITY.CREATE_MODEL_HIDE(posX, posY, posZ, radius, modelHash, bSurviveMapReload) end

---@param posX number
---@param posY number
---@param posZ number
---@param radius number
---@param modelHash integer
---@param bSurviveMapReload boolean
function ENTITY.CREATE_MODEL_HIDE_EXCLUDING_SCRIPT_OBJECTS(posX, posY, posZ, radius, modelHash, bSurviveMapReload) end

---@param posX number
---@param posY number
---@param posZ number
---@param radius number
---@param modelHash integer
---@param bLazy boolean
function ENTITY.REMOVE_MODEL_HIDE(posX, posY, posZ, radius, modelHash, bLazy) end

---@param p0 any
---@return any
function ENTITY._0xD4636C2EDB0DEA8A(p0) end

---@param posX number
---@param posY number
---@param posZ number
---@param radius number
---@param modelHash integer
---@param bSurviveMapReload boolean
function ENTITY.CREATE_FORCED_OBJECT(posX, posY, posZ, radius, modelHash, bSurviveMapReload) end

---@param posX number
---@param posY number
---@param posZ number
---@param radius number
---@param modelHash integer
function ENTITY.REMOVE_FORCED_OBJECT(posX, posY, posZ, radius, modelHash) end

---@param entityIndex integer
---@param secondEntityIndex integer
---@param bReactivateWhenNoCollision boolean
function ENTITY.SET_ENTITY_NO_COLLISION_ENTITY(entityIndex, secondEntityIndex, bReactivateWhenNoCollision) end

---@param entityIndex integer
---@param bEnableMotionBlur boolean
function ENTITY.SET_ENTITY_MOTION_BLUR(entityIndex, bEnableMotionBlur) end

---@param entityIndex integer
---@param bCanAutoVault boolean
function ENTITY.SET_CAN_AUTO_VAULT_ON_ENTITY(entityIndex, bCanAutoVault) end

---@param entityIndex integer
---@param bCanClimb boolean
function ENTITY.SET_CAN_CLIMB_ON_ENTITY(entityIndex, bCanClimb) end

---@param entityIndex integer
---@param bNoWeaponDecals boolean
function ENTITY.SET_ENTITY_NOWEAPONDECALS(entityIndex, bNoWeaponDecals) end

---@param x number
---@param y number
---@param z number
---@param radius number
---@param itemSet integer
---@param p5 integer
---@return integer
function ENTITY._GET_ENTITIES_NEAR_POINT(x, y, z, radius, itemSet, p5) end

---@param volume integer
---@param itemSet integer
---@param entityType integer
---@param p3 any
---@param p4 integer
---@param p5 any
---@return integer
function ENTITY.GET_MATCHING_ENTITIES(volume, itemSet, entityType, p3, p4, p5) end

---@param volume integer
---@param itemSet integer
---@param entityType integer
---@return integer
function ENTITY._GET_ENTITIES_IN_VOLUME(volume, itemSet, entityType) end

---@param modelHash integer
---@return integer
function ENTITY._SEARCH_BUILDING_POOL_FOR_ENTITY_WITH_THIS_MODEL(modelHash) end

---@param p0 any
---@return any
function ENTITY._0xC2E71D7E0A7B4C89(p0) end

---@param p0 any
---@param p1 any
function ENTITY._0x6C31B06E91518269(p0, p1) end

---@param p0 any
---@param p1 any
function ENTITY._0x119A5714578F4E05(p0, p1) end

---@param doorHash integer
---@param p1 integer
---@return integer
function ENTITY._GET_ENTITY_BY_DOORHASH(doorHash, p1) end

---@param pAnimDictName any
---@param pAnimName any
---@param pEventName any
---@param ReturnStartPhase number
---@param ReturnEndPhase number
---@return boolean
---@return number
---@return number
function ENTITY.FIND_ANIM_EVENT_PHASE(pAnimDictName, pAnimName, pEventName, ReturnStartPhase, ReturnEndPhase) end

---@param EntityIndex integer
---@param p1 boolean
function ENTITY.FORCE_ENTITY_AI_AND_ANIMATION_UPDATE(EntityIndex, p1) end

---@param entity integer
---@param animDict any
---@param animName any
---@return number
function ENTITY._GET_ENTITY_ANIM_CURRENT_TIME(entity, animDict, animName) end

---@param entity integer
---@param animDict any
---@param animClip any
---@return number
function ENTITY._0x8E46E18AA828334F(entity, animDict, animClip) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function ENTITY._0xDF8E49EA89A01DB1(p0, p1, p2) end

---@param EntityIndex integer
---@param EventHash integer
---@return boolean
function ENTITY.HAS_ANIM_EVENT_FIRED(EntityIndex, EventHash) end

---@param EntityIndex integer
---@param pAnimDictName any
---@param pAnimName any
---@param animType integer
---@return boolean
function ENTITY.HAS_ENTITY_ANIM_FINISHED(EntityIndex, pAnimDictName, pAnimName, animType) end

---@param EntityIndex integer
---@param AnimName any
---@param AnimDictName any
---@param BlendDelta number
---@param Loop boolean
---@param HoldLastFrame boolean
---@param DriveToPose boolean
---@param StartPhase number
---@param AnimFlags integer
---@return boolean
function ENTITY.PLAY_ENTITY_ANIM(EntityIndex, AnimName, AnimDictName, BlendDelta, Loop, HoldLastFrame, DriveToPose, StartPhase, AnimFlags) end

---@param entity integer
---@param animDict any
---@param animName any
---@param time number
function ENTITY._SET_ENTITY_ANIM_CURRENT_TIME(entity, animDict, animName, time) end

---@param entity integer
---@param animDict any
---@param animName any
---@param speedMultiplier number
function ENTITY._SET_ENTITY_ANIM_SPEED(entity, animDict, animName, speedMultiplier) end

---@param EntityIndex integer
---@param AnimName any
---@param AnimDictName any
---@param BlendDelta number
---@return boolean
function ENTITY.STOP_ENTITY_ANIM(EntityIndex, AnimName, AnimDictName, BlendDelta) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function ENTITY._0x669655FFB29EF1A9(p0, p1, p2, p3) end

---@param entity integer
function ENTITY._ADD_ENTITY_TRACKING_TRAILS(entity) end

---@param entity integer
function ENTITY._0x5826EFD6D73C4DE5(entity) end

---@param entity integer
---@param pause boolean
function ENTITY._PAUSE_ENTITY_TRACKING(entity, pause) end

---@param p0 any
---@param waypointRecord any
---@param bUseSnowOffset boolean
---@param p3 number
---@param p4 number
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
---@param p9 any
---@param p10 any
---@param bInit boolean
---@return any
function ENTITY._CREATE_FOOTPATH_TRAIL(p0, waypointRecord, bUseSnowOffset, p3, p4, p5, p6, p7, p8, p9, p10, bInit) end

---@param p0 any
---@param p1 any
---@param p2 any
function ENTITY._0xC76E94A78127412B(p0, p1, p2) end

---@param p0 any
function ENTITY._0x7F20092547B4DDEA(p0) end

---@param p0 any
function ENTITY._0xF41E2979D5BC5370(p0) end

---@param p0 any
---@return any
function ENTITY._0xAAACB74442C1BED3(p0) end

---@param modelHash integer
---@param x number
---@param y number
---@param z number
---@param flags integer
---@return any
function ENTITY.PIN_CLOSEST_MAP_ENTITY(modelHash, x, y, z, flags) end

---@param entity integer
function ENTITY._UNPIN_MAP_ENTITY(entity) end

---@param p0 any
---@return boolean
function ENTITY.IS_MAP_ENTITY_PINNED(p0) end

---@param p0 any
---@return integer
function ENTITY._GET_PINNED_MAP_ENTITY(p0) end

---@param p0 any
function ENTITY._0xEAB3D91D30A344F1(p0) end

---@param p0 any
function ENTITY._0x37CEB637BA3B1A47(p0) end

---@param p0 any
---@param p1 any
---@return any
function ENTITY._0x350E9211074955AF(p0, p1) end

---@param ped integer
function ENTITY._0x898586729DB5221D(ped) end

---@param p0 any
---@param p1 any
function ENTITY._0xE9E7A0BAC7F57746(p0, p1) end
