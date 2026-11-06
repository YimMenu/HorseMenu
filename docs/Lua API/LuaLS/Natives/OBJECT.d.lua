---@meta

---@class OBJECT
OBJECT = {}

---@param ModelIndex integer
---@param VecNewCoorsX number
---@param VecNewCoorsY number
---@param VecNewCoorsZ number
---@param RegisterAsNetworkObject boolean
---@param ScriptHostObject boolean
---@param ForceToBeObject boolean
---@param p7 boolean
---@param p8 boolean
---@return integer
function OBJECT.CREATE_OBJECT(ModelIndex, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, RegisterAsNetworkObject, ScriptHostObject, ForceToBeObject, p7, p8) end

---@param ModelIndex integer
---@param VecNewCoorsX number
---@param VecNewCoorsY number
---@param VecNewCoorsZ number
---@param RegisterAsNetworkObject boolean
---@param ScriptHostObject boolean
---@param ForceToBeObject boolean
---@param p7 boolean
---@return integer
function OBJECT.CREATE_OBJECT_NO_OFFSET(ModelIndex, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, RegisterAsNetworkObject, ScriptHostObject, ForceToBeObject, p7) end

---@param ObjectIndex integer
---@return integer
function OBJECT.DELETE_OBJECT(ObjectIndex) end

---@param ObjectIndex integer
---@param p1 boolean
---@return boolean
function OBJECT.PLACE_OBJECT_ON_GROUND_PROPERLY(ObjectIndex, p1) end

---@param ObjectID integer
---@param VecDestCoorstX number
---@param VecDestCoorstY number
---@param VecDestCoorstZ number
---@param VecIncrementX number
---@param VecIncrementY number
---@param VecIncrementZ number
---@param StopOnCollision boolean
---@return boolean
function OBJECT.SLIDE_OBJECT(ObjectID, VecDestCoorstX, VecDestCoorstY, VecDestCoorstZ, VecIncrementX, VecIncrementY, VecIncrementZ, StopOnCollision) end

---@param ObjectID integer
---@param Targettable boolean
function OBJECT.SET_OBJECT_TARGETTABLE(ObjectID, Targettable) end

---@param object integer
---@param targettable boolean
function OBJECT._SET_OBJECT_TARGETTABLE_2(object, targettable) end

---@param object integer
---@param p1 boolean
---@param p2 boolean
function OBJECT._SET_OBJECT_TARGETTABLE_FOCUS(object, p1, p2) end

---@param p0 any
---@param p1 any
function OBJECT._0xF6E88489B4E6EBE5(p0, p1) end

---@param p0 any
---@param p1 any
function OBJECT._0xE157A8A336C7F04A(p0, p1) end

---@param p0 any
---@param p1 any
function OBJECT._0x46CBCF0E98A4E156(p0, p1) end

---@param scrVecCentreCoorsX number
---@param scrVecCentreCoorsY number
---@param scrVecCentreCoorsZ number
---@param Radius number
---@param ObjectModelHashKey integer
---@param RegisterAsScriptObject boolean
---@param ScriptHostObject boolean
---@param RegisterAsNetworkObject boolean
---@return integer
function OBJECT.GET_CLOSEST_OBJECT_OF_TYPE(scrVecCentreCoorsX, scrVecCentreCoorsY, scrVecCentreCoorsZ, Radius, ObjectModelHashKey, RegisterAsScriptObject, ScriptHostObject, RegisterAsNetworkObject) end

---@param ObjectID integer
---@return boolean
function OBJECT.HAS_OBJECT_BEEN_BROKEN(ObjectID) end

---@param scrVecCoorsX number
---@param scrVecCoorsY number
---@param scrVecCoorsZ number
---@param Radius number
---@param model integer
---@param SearchFlags integer
---@return boolean
function OBJECT.HAS_CLOSEST_OBJECT_OF_TYPE_BEEN_BROKEN(scrVecCoorsX, scrVecCoorsY, scrVecCoorsZ, Radius, model, SearchFlags) end

---@param vPosX number
---@param vPosY number
---@param vPosZ number
---@param fHeading number
---@param vOffsetX number
---@param vOffsetY number
---@param vOffsetZ number
---@return Vector3
function OBJECT.GET_OFFSET_FROM_COORD_AND_HEADING_IN_WORLD_COORDS(vPosX, vPosY, vPosZ, fHeading, vOffsetX, vOffsetY, vOffsetZ) end

---@param doorHash integer
---@param p1 boolean
---@param p2 boolean
---@param p3 boolean
---@param threadId integer
---@param p5 integer
---@param p6 boolean
function OBJECT._ADD_DOOR_TO_SYSTEM_NEW(doorHash, p1, p2, p3, threadId, p5, p6) end

---@param doorHash integer
---@return boolean
function OBJECT._IS_DOOR_REGISTERED_WITH_NETWORK(doorHash) end

---@param doorEnumHash integer
function OBJECT.REMOVE_DOOR_FROM_SYSTEM(doorEnumHash) end

---@param doorEnumHash integer
---@param state integer
function OBJECT.DOOR_SYSTEM_SET_DOOR_STATE(doorEnumHash, state) end

---@param doorEnumHash integer
---@return integer
function OBJECT.DOOR_SYSTEM_GET_DOOR_STATE(doorEnumHash) end

---@param doorEnumHash integer
---@param fAutomaticRate number
function OBJECT.DOOR_SYSTEM_SET_AUTOMATIC_RATE(doorEnumHash, fAutomaticRate) end

---@param doorEnumHash integer
---@param fAutomaticDistance number
function OBJECT.DOOR_SYSTEM_SET_AUTOMATIC_DISTANCE(doorEnumHash, fAutomaticDistance) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function OBJECT._0xB3B1546D23DF8DE1(p0, p1, p2, p3, p4) end

---@param doorEnumHash integer
---@param fOpenRatio number
---@param forceUpdate boolean
function OBJECT.DOOR_SYSTEM_SET_OPEN_RATIO(doorEnumHash, fOpenRatio, forceUpdate) end

---@param p0 any
---@param p1 any
function OBJECT._0x3A77DAE8B4FD7586(p0, p1) end

---@param doorHash integer
---@param p1 boolean
function OBJECT._DOOR_SYSTEM_SET_ABLE_TO_CHANGE_OPEN_RATIO_WHILE_LOCKED(doorHash, p1) end

---@param doorHash integer
---@return boolean
function OBJECT._IS_DOOR_REGISTERED_WITH_OWNER(doorHash) end

---@param doorHash integer
function OBJECT._DOOR_SYSTEM_CHANGE_SCRIPT_OWNER(doorHash) end

---@param doorHash integer
---@return number
function OBJECT._DOOR_SYSTEM_GET_AUTOMATIC_RATE(doorHash) end

---@param p0 any
---@param p1 any
---@return any
function OBJECT._0x6E2AA80BB0C03728(p0, p1) end

---@param doorHash integer
---@param disable boolean
function OBJECT._DOOR_SYSTEM_SET_AUTOMATIC_STATE(doorHash, disable) end

---@param doorEnumHash integer
---@return number
function OBJECT.DOOR_SYSTEM_GET_OPEN_RATIO(doorEnumHash) end

---@param p0 any
---@param p1 any
function OBJECT._0x7F458B543006C8FE(p0, p1) end

---@param p0 any
---@return any
function OBJECT._0xACD4F9831DFAD7F5(p0) end

---@param p0 any
function OBJECT._0x0C0A373D181BF900(p0) end

---@param p0 any
---@param p1 any
function OBJECT._0xA93F925F1942E434(p0, p1) end

---@param p0 any
---@return any
function OBJECT._0x4D8611DFE1126478(p0) end

---@param p0 any
---@param p1 any
function OBJECT._0x57C242543B7B8FB9(p0, p1) end

---@param p0 any
---@param p1 any
function OBJECT._0x4AE07EBA3462C5D5(p0, p1) end

---@param p0 any
---@param p1 any
function OBJECT._0x22031584496CFB70(p0, p1) end

---@param p0 any
---@param p1 any
function OBJECT._0xC07B91B996C1DE89(p0, p1) end

---@param doorEnumHash integer
---@return boolean
function OBJECT.IS_DOOR_REGISTERED_WITH_SYSTEM(doorEnumHash) end

---@param doorEnumHash integer
---@return boolean
function OBJECT.IS_DOOR_CLOSED(doorEnumHash) end

---@param object integer
---@param p1 integer
---@return any
function OBJECT._0x0943113E02322164(object, p1) end

---@param p0 any
---@return any
function OBJECT._0x614D0B4533F842D3(p0) end

---@param doorHash integer
---@param p1 boolean
function OBJECT._DOOR_SYSTEM_FORCE_SHUT(doorHash, p1) end

---@param p0 any
---@return any
function OBJECT._0xEBA314768FB35D58(p0) end

---@param p0 any
function OBJECT._0x5230BF34EB0EC645(p0) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param Radius number
---@param ModelIndex integer
---@param checkPhysicsExists boolean
---@return boolean
function OBJECT.DOES_OBJECT_OF_TYPE_EXIST_AT_COORDS(VecCoorsX, VecCoorsY, VecCoorsZ, Radius, ModelIndex, checkPhysicsExists) end

---@param VecPointX number
---@param VecPointY number
---@param VecPointZ number
---@param VecCoors1X number
---@param VecCoors1Y number
---@param VecCoors1Z number
---@param VecCoors2X number
---@param VecCoors2Y number
---@param VecCoors2Z number
---@param DistanceP1toP4 number
---@param HighlightArea boolean
---@param bCheck3D boolean
---@return boolean
function OBJECT.IS_POINT_IN_ANGLED_AREA(VecPointX, VecPointY, VecPointZ, VecCoors1X, VecCoors1Y, VecCoors1Z, VecCoors2X, VecCoors2Y, VecCoors2Z, DistanceP1toP4, HighlightArea, bCheck3D) end

---@param ObjectID integer
---@param AllowFlag boolean
function OBJECT.SET_OBJECT_ALLOW_LOW_LOD_BUOYANCY(ObjectID, AllowFlag) end

---@param ObjectIndex integer
---@param fMass number
---@param fGravityFactor number
---@param TranslationalDampingX number
---@param TranslationalDampingY number
---@param TranslationalDampingZ number
---@param RotationalDampingX number
---@param RotationalDampingY number
---@param RotationalDampingZ number
---@param fCollisionMargin number
---@param fMaxAngularSpeed number
---@param fBuoyancyFactor number
function OBJECT.SET_OBJECT_PHYSICS_PARAMS(ObjectIndex, fMass, fGravityFactor, TranslationalDampingX, TranslationalDampingY, TranslationalDampingZ, RotationalDampingX, RotationalDampingY, RotationalDampingZ, fCollisionMargin, fMaxAngularSpeed, fBuoyancyFactor) end

---@param ObjectIndex integer
---@param HealthPercentageByMass boolean
---@return number
function OBJECT.GET_OBJECT_FRAGMENT_DAMAGE_HEALTH(ObjectIndex, HealthPercentageByMass) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function OBJECT._0x235C863DA77BD88D(p0, p1, p2) end

---@param ObjectIndex integer
---@param bActivatePhysicsWhenUnfrozen boolean
function OBJECT.SET_ACTIVATE_OBJECT_PHYSICS_AS_SOON_AS_IT_IS_UNFROZEN(ObjectIndex, bActivatePhysicsWhenUnfrozen) end

---@param ObjectIndex integer
---@param Component integer
---@param Disappear boolean
function OBJECT.BREAK_OBJECT_FRAGMENT_CHILD(ObjectIndex, Component, Disappear) end

---@param object integer
function OBJECT.BREAK_ALL_OBJECT_FRAGMENT_BONES(object) end

---@param p0 any
---@param p1 any
function OBJECT._0xAAACF33CBF9B990A(p0, p1) end

---@param object integer
---@param bone integer
function OBJECT._DAMAGE_BONE_ON_PROP(object, bone) end

---@param ObjectIndex integer
function OBJECT.FIX_OBJECT_FRAGMENT(ObjectIndex) end

---@param p0 any
---@return any
function OBJECT._0x58DE624FA7FB0E7F(p0) end

---@param p0 any
function OBJECT._0x491439AEF410A2FC(p0) end

---@param object integer
---@param scale number
function OBJECT._SET_OBJECT_BREAK_SCALE(object, scale) end

---@param p0 any
---@param p1 any
function OBJECT._0xCEAB54F4632C6EF6(p0, p1) end

---@param ObjectID integer
function OBJECT.TRACK_OBJECT_VISIBILITY(ObjectID) end

---@param ObjectID integer
---@return boolean
function OBJECT.IS_OBJECT_VISIBLE(ObjectID) end

---@param ObjectIndex integer
---@param bTakesDamage boolean
function OBJECT.SET_OBJECT_TAKES_DAMAGE_FROM_COLLIDING_WITH_BUILDINGS(ObjectIndex, bTakesDamage) end

---@param enabled boolean
function OBJECT.ALLOW_DAMAGE_EVENTS_FOR_NON_NETWORKED_OBJECTS(enabled) end

---@param p0 any
---@param p1 any
function OBJECT._0x6579860A5558524A(p0, p1) end

---@param p0 any
---@param p1 any
function OBJECT._0xDFA1237F5228263F(p0, p1) end

---@param object integer
---@return number
function OBJECT._GET_LIGHT_INTENSITY_FROM_OBJECT(object) end

---@param object integer
---@param lightIntensity number
function OBJECT._SET_LIGHT_INTENSITY_FOR_OBJECT(object, lightIntensity) end

---@param object integer
---@param value number
function OBJECT._SET_LIGHT_TRANSLUCENCY_FOR_OBJECT(object, value) end

---@param object integer
---@param disable boolean
function OBJECT._SET_LIGHT_SCATTERING_DISABLED_FOR_OBJECT(object, disable) end

---@param p0 any
---@param p1 any
function OBJECT._0x7FCD49388BC9B775(p0, p1) end

---@param p0 any
---@return any
function OBJECT._0xFA99E8E575F2FEF8(p0) end

---@param PosX number
---@param PosY number
---@param PosZ number
---@param fRadius number
---@param RayfireName any
---@return integer
function OBJECT.GET_RAYFIRE_MAP_OBJECT(PosX, PosY, PosZ, fRadius, RayfireName) end

---@param RayFireObject integer
---@param state integer
function OBJECT.SET_STATE_OF_RAYFIRE_MAP_OBJECT(RayFireObject, state) end

---@param RayFireObject integer
---@return integer
function OBJECT.GET_STATE_OF_RAYFIRE_MAP_OBJECT(RayFireObject) end

---@param RayFireObject integer
---@return boolean
function OBJECT.DOES_RAYFIRE_MAP_OBJECT_EXIST(RayFireObject) end

---@param RayFireObject integer
---@return number
function OBJECT.GET_RAYFIRE_MAP_OBJECT_ANIM_PHASE(RayFireObject) end

---@param Type integer
---@param VecNewCoorsX number
---@param VecNewCoorsY number
---@param VecNewCoorsZ number
---@param PlacementFlags integer
---@param Amount integer
---@param ScriptHostObject boolean
---@param CustomModel integer
---@param p8 integer
---@param p9 number
---@param p10 any
---@return integer
function OBJECT.CREATE_PICKUP(Type, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, PlacementFlags, Amount, ScriptHostObject, CustomModel, p8, p9, p10) end

---@param Type integer
---@param CoorsX number
---@param CoorsY number
---@param CoorsZ number
---@param OrientationX number
---@param OrientationY number
---@param OrientationZ number
---@param PlacementFlags integer
---@param Amount integer
---@param RotOrder integer
---@param ScriptHostObject boolean
---@param CustomModel integer
---@param p12 integer
---@param p13 number
---@param p14 any
---@return integer
function OBJECT.CREATE_PICKUP_ROTATE(Type, CoorsX, CoorsY, CoorsZ, OrientationX, OrientationY, OrientationZ, PlacementFlags, Amount, RotOrder, ScriptHostObject, CustomModel, p12, p13, p14) end

---@param Type integer
---@param VecNewCoorsX number
---@param VecNewCoorsY number
---@param VecNewCoorsZ number
---@param PlacementFlags integer
---@param Amount integer
---@param CustomModel integer
---@param bCreateAsScriptObject boolean
---@param ScriptHostObject boolean
---@param p9 integer
---@param p10 number
---@return integer
function OBJECT.CREATE_AMBIENT_PICKUP(Type, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, PlacementFlags, Amount, CustomModel, bCreateAsScriptObject, ScriptHostObject, p9, p10) end

---@param Type integer
---@param VecNewCoorsX number
---@param VecNewCoorsY number
---@param VecNewCoorsZ number
---@param SnapToGround boolean
---@param CustomModel integer
---@return integer
function OBJECT.CREATE_PORTABLE_PICKUP(Type, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, SnapToGround, CustomModel) end

---@param PickupID integer
---@param PedID integer
function OBJECT.ATTACH_PORTABLE_PICKUP_TO_PED(PickupID, PedID) end

---@param PickupID integer
function OBJECT.DETACH_PORTABLE_PICKUP_FROM_PED(PickupID) end

---@param pickupObject integer
---@param toggle boolean
function OBJECT._HIDE_PICKUP_OBJECT(pickupObject, toggle) end

---@param modelName integer
---@param MaxPickups integer
function OBJECT.SET_MAX_NUM_PORTABLE_PICKUPS_CARRIED_BY_PLAYER(modelName, MaxPickups) end

---@param p0 any
---@return any
function OBJECT._0x3E2616E7EA539480(p0) end

---@param CanCollect boolean
function OBJECT.SET_LOCAL_PLAYER_CAN_COLLECT_PORTABLE_PICKUPS(CanCollect) end

---@param VecInCoorsX number
---@param VecInCoorsY number
---@param VecInCoorsZ number
---@param minDist number
---@param maxDist number
---@param p5 any
---@return Vector3
function OBJECT.GET_SAFE_PICKUP_COORDS(VecInCoorsX, VecInCoorsY, VecInCoorsZ, minDist, maxDist, p5) end

---@param PickupID integer
---@return Vector3
function OBJECT.GET_PICKUP_COORDS(PickupID) end

---@param Type integer
function OBJECT.REMOVE_ALL_PICKUPS_OF_TYPE(Type) end

---@param PickupID integer
---@return boolean
function OBJECT.HAS_PICKUP_BEEN_COLLECTED(PickupID) end

---@param PickupID integer
function OBJECT.REMOVE_PICKUP(PickupID) end

---@param pickupObject integer
function OBJECT.SET_PICKUP_DO_NOT_AUTO_PLACE_ON_GROUND(pickupObject) end

---@param PickupID integer
---@return boolean
function OBJECT.DOES_PICKUP_EXIST(PickupID) end

---@param PickupID integer
---@return boolean
function OBJECT.DOES_PICKUP_OBJECT_EXIST(PickupID) end

---@param PickupID integer
---@return integer
function OBJECT.GET_PICKUP_OBJECT(PickupID) end

---@param ObjectID integer
---@return boolean
function OBJECT.IS_OBJECT_A_PORTABLE_PICKUP(ObjectID) end

---@param pickupHash integer
---@return boolean
function OBJECT._IS_PICKUP_TYPE_VALID(pickupHash) end

---@param PickupType integer
---@param VecCoordsX number
---@param VecCoordsY number
---@param VecCoordsZ number
---@param Radius number
---@return boolean
function OBJECT.DOES_PICKUP_OF_TYPE_EXIST_IN_AREA(PickupType, VecCoordsX, VecCoordsY, VecCoordsZ, Radius) end

---@param PickupID integer
---@param RegenTime integer
function OBJECT.SET_PICKUP_REGENERATION_TIME(PickupID, RegenTime) end

---@param PickupID integer
function OBJECT.FORCE_PICKUP_REGENERATE(PickupID) end

---@param player integer
---@param pickupHash integer
---@param isUsable boolean
function OBJECT._SET_NETWORK_PICKUP_USABLE_FOR_PLAYER(player, pickupHash, isUsable) end

---@param CustomModel integer
---@param Allow boolean
function OBJECT.SET_LOCAL_PLAYER_PERMITTED_TO_COLLECT_PICKUPS_WITH_MODEL(CustomModel, Allow) end

---@param p0 any
---@param p1 any
function OBJECT.BLOCK_PICKUP_FROM_PLAYER_COLLECTION(p0, p1) end

---@param p0 any
---@param p1 any
function OBJECT.SET_PICKUP_NOT_LOOTABLE(p0, p1) end

---@param p0 boolean
function OBJECT._0x1F5E07E14A86FAFC(p0) end

---@param PickupID integer
---@param Team integer
---@param bSet boolean
function OBJECT.SET_TEAM_PICKUP_OBJECT(PickupID, Team, bSet) end

---@param p0 any
---@param p1 any
---@return any
function OBJECT._0x9F52AD67D1A91BAD(p0, p1) end

---@param PickupID integer
---@param bPrevent boolean
---@param bLocalOnly boolean
function OBJECT.PREVENT_COLLECTION_OF_PORTABLE_PICKUP(PickupID, bPrevent, bLocalOnly) end

---@param multiplier number
function OBJECT.SET_PICKUP_GENERATION_RANGE_MULTIPLIER(multiplier) end

---@param PickupID integer
---@param bSet boolean
function OBJECT.SET_PICKUP_UNCOLLECTABLE(PickupID, bSet) end

---@param PickupID integer
---@param bSet boolean
function OBJECT.SET_PICKUP_HIDDEN_WHEN_UNCOLLECTABLE(PickupID, bSet) end

---@param lifetime integer
function OBJECT._SET_AMBIENT_PICKUP_LIFETIME(lifetime) end

---@param p0 any
---@param p1 any
function OBJECT.SET_PICKUP_PARTICLE_FX_SPAWN(p0, p1) end

---@param p0 any
---@param p1 any
function OBJECT.SET_PICKUP_PARTICLE_FX_HIGHLIGHT(p0, p1) end

---@param pickupFlag integer
---@param bClearPreviousFlags boolean
function OBJECT.SUPPRESS_PICKUP_REWARD_TYPE(pickupFlag, bClearPreviousFlags) end

---@param p0 any
---@return any
function OBJECT._0x20135AF9C10D2A3D(p0) end

---@param object integer
function OBJECT._SET_PICKUP_COLLECTABLE_ON_MOUNT(object) end

---@param p0 any
---@param p1 any
function OBJECT._0xDE116ECFFDD4B997(p0, p1) end

---@param ePickupType integer
---@return integer
function OBJECT.GET_WEAPON_TYPE_FROM_PICKUP_TYPE(ePickupType) end

---@param pickupHash integer
---@return integer
function OBJECT._GET_AMMO_TYPE_FROM_PICKUP_TYPE(pickupHash) end

---@param ObjectIndex integer
---@param TintIndex integer
function OBJECT.SET_OBJECT_TINT_INDEX(ObjectIndex, TintIndex) end

---@param object integer
---@return number
function OBJECT._GET_OBJECT_LIGHT_INTENSITY(object) end

---@param object integer
---@param opacity number
function OBJECT._SET_OBJECT_BURN_OPACITY(object, opacity) end

---@param object integer
---@param intensity number
function OBJECT._SET_OBJECT_BURN_INTENSITY(object, intensity) end

---@param object integer
---@param burnLevel number
---@param affectAsh boolean
function OBJECT._SET_OBJECT_BURN_LEVEL(object, burnLevel, affectAsh) end

---@param p0 any
function OBJECT._0x9A74A9CADFA8A598(p0) end

---@param object integer
function OBJECT._RESET_OBJECT_VELOCITY(object) end

---@param object integer
---@param speed number
---@param p2 number
function OBJECT._SET_OBJECT_BURN_SPEED(object, speed, p2) end

---@param p0 any
---@param p1 any
function OBJECT._0xCBFBD38F2E0A263B(p0, p1) end

---@param OldPickupType integer
---@return integer
function OBJECT.CONVERT_OLD_PICKUP_TYPE_TO_NEW(OldPickupType) end

---@param posX number
---@param posY number
---@param posZ number
---@param radius number
function OBJECT.SET_FORCE_OBJECT_THIS_FRAME(posX, posY, posZ, radius) end

---@param p0 any
---@param p1 any
---@return any
function OBJECT._0xD91E55B6C005EB09(p0, p1) end

---@param ObjectIndex integer
function OBJECT.ONLY_CLEAN_UP_OBJECT_WHEN_OUT_OF_RANGE(ObjectIndex) end

---@param object integer
---@param p1 any
function OBJECT._0xCAAF2BCCFEF37F77(object, p1) end

---@param p0 any
---@return any
function OBJECT._0x08C5825A2932EA7B(p0) end

---@param p0 any
---@param p1 any
---@return any
function OBJECT._0x7D4411D6736CD295(p0, p1) end

---@param p0 any
---@return any
function OBJECT._0x250EBB11E81A10BE(p0) end

---@param p0 any
---@return any
function OBJECT._0x2BF1953C0C21AC88(p0) end

---@param object integer
---@return boolean
function OBJECT.CREATE_OBJECT_SKELETON(object) end

---@param object integer
function OBJECT._MAKE_ITEM_CARRIABLE(object) end

---@param p0 any
---@param p1 any
function OBJECT._0xF65EDE5D02A7A760(p0, p1) end

---@param object integer
---@param p1 boolean
function OBJECT._SET_AUTO_JUMPABLE_BY_HORSE(object, p1) end

---@param object integer
---@param p1 boolean
function OBJECT._SET_NOT_JUMPABLE_BY_HORSE(object, p1) end

---@param object integer
---@param kickable boolean
function OBJECT._SET_OBJECT_KICKABLE(object, kickable) end

---@param object integer
---@param txdHash integer
---@param p2 any
---@param p3 any
function OBJECT.SET_CUSTOM_TEXTURES_ON_OBJECT(object, txdHash, p2, p3) end

---@param p0 any
---@param p1 any
function OBJECT._0xD503D6F0986D58BC(p0, p1) end

---@param p0 any
---@param p1 any
function OBJECT._0xAEE6C800E124CFE1(p0, p1) end

---@param object integer
---@param p1 any
function OBJECT._0x3DF1A0A58498E209(object, p1) end
