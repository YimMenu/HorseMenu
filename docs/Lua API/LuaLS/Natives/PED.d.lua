---@meta

---@class PED
PED = {}

---@param PedModelHashKey integer
---@param VecNewCoorsX number
---@param VecNewCoorsY number
---@param VecNewCoorsZ number
---@param fPedHeading number
---@param RegisterAsNetworkObject boolean
---@param ScriptHostObject boolean
---@param p7 boolean
---@param p8 boolean
---@return integer
function PED.CREATE_PED(PedModelHashKey, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ, fPedHeading, RegisterAsNetworkObject, ScriptHostObject, p7, p8) end

---@param PedIndex integer
---@return integer
function PED.DELETE_PED(PedIndex) end

---@param ped integer
---@param p1 integer
function PED._SET_REMOVE_PED_NETWORKED(ped, p1) end

---@param ped integer
---@param p1 number
function PED._0x7C08E7CB8D951B70(ped, p1) end

---@param ped integer
---@param p1 number
---@param p2 number
---@param p3 integer
---@param p4 any
function PED._SET_PED_TO_BE_REMOVED(ped, p1, p2, p3, p4) end

---@param PedIndex integer
---@param bRegisterAsNetworkObject boolean
---@param bScriptHostObject boolean
---@param bLinkBlends boolean
---@return integer
function PED.CLONE_PED(PedIndex, bRegisterAsNetworkObject, bScriptHostObject, bLinkBlends) end

---@param PedIndexSource integer
---@param PedIndexTarget integer
function PED.CLONE_PED_TO_TARGET(PedIndexSource, PedIndexTarget) end

---@param PedIndex integer
---@param VehicleIndex integer
---@param ConsiderEnteringAsInVehicle boolean
---@return boolean
function PED.IS_PED_IN_VEHICLE(PedIndex, VehicleIndex, ConsiderEnteringAsInVehicle) end

---@param PedIndex integer
---@param VehicleModelHashKey integer
---@return boolean
function PED.IS_PED_IN_MODEL(PedIndex, VehicleModelHashKey) end

---@param PedIndex integer
---@param ConsiderEnteringAsInVehicle boolean
---@return boolean
function PED.IS_PED_IN_ANY_VEHICLE(PedIndex, ConsiderEnteringAsInVehicle) end

---@param x number
---@param y number
---@param z number
---@param p3 number
---@param p4 integer
---@param p5 any
function PED._0x9851DE7AEC10B4E1(x, y, z, p3, p4, p5) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_INJURED(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_FATALLY_INJURED(PedIndex) end

---@param PedIndex integer
---@param CheckMeleeDeathFlags boolean
---@return boolean
function PED.IS_PED_DEAD_OR_DYING(PedIndex, CheckMeleeDeathFlags) end

---@param ped integer
---@param bleedoutProfile integer
function PED._SET_PED_BLEEDOUT_PROFILE(ped, bleedoutProfile) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_AIMING_FROM_COVER(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_RELOADING(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_A_PLAYER(PedIndex) end

---@param ped integer
---@return boolean
function PED._IS_ANIMAL_CONTROLLED_BY_A_PLAYER(ped) end

---@param VehicleIndex integer
---@param PedModelHashKey integer
---@param Seat integer
---@param RegisterAsNetworkObject boolean
---@param ScriptHostObject boolean
---@param p5 boolean
---@return integer
function PED.CREATE_PED_INSIDE_VEHICLE(VehicleIndex, PedModelHashKey, Seat, RegisterAsNetworkObject, ScriptHostObject, p5) end

---@param PedIndex integer
---@param DesiredHeading number
function PED.SET_PED_DESIRED_HEADING(PedIndex, DesiredHeading) end

---@param PedIndex integer
function PED.FORCE_ALL_HEADING_VALUES_TO_ALIGN(PedIndex) end

---@param PedIndex1 integer
---@param PedIndex2 integer
---@param Degrees number
---@return boolean
function PED.IS_PED_FACING_PED(PedIndex1, PedIndex2, Degrees) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_IN_MELEE_COMBAT(PedIndex) end

---@param ped integer
---@param p1 integer
---@return any
function PED._0x6DB875AFC584FA32(ped, p1) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_STOPPED(PedIndex) end

---@param ped integer
---@return boolean
function PED.IS_PED_SITTING(ped) end

---@param ped integer
---@param p1 integer
---@return boolean
function PED._0x09D7AFD3716DA8E1(ped, p1) end

---@param player integer
---@param ped integer
---@param shotNearRecentlyTime integer
---@return boolean
function PED._0x9C81338B2E62CE0A(player, ped, shotNearRecentlyTime) end

---@param ped integer
---@param p1 number
---@return boolean
function PED._0xB7DBB2986B87E230(ped, p1) end

---@param ped integer
---@param p1 number
---@return boolean
function PED._0xD355E2F1BB41087E(ped, p1) end

---@param vMinX number
---@param vMinY number
---@param vMinZ number
---@param vMaxX number
---@param vMaxY number
---@param vMaxZ number
---@param HighlightArea boolean
---@param bDo3DCheck boolean
---@return boolean
function PED.IS_ANY_PED_SHOOTING_IN_AREA(vMinX, vMinY, vMinZ, vMaxX, vMaxY, vMaxZ, HighlightArea, bDo3DCheck) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_SHOOTING(PedIndex) end

---@param ped integer
---@return number
function PED.TIME_SINCE_PED_LAST_SHOT(ped) end

---@param PedIndex integer
---@param NewAccuracy integer
function PED.SET_PED_ACCURACY(PedIndex, NewAccuracy) end

---@param PedIndex integer
---@return integer
function PED.GET_PED_ACCURACY(PedIndex) end

---@param PedIndex integer
---@param PedModelHashKey integer
---@return boolean
function PED.IS_PED_MODEL(PedIndex, PedModelHashKey) end

---@param PedIndex integer
---@param wtWeapon integer
function PED.EXPLODE_PED_HEAD(PedIndex, wtWeapon) end

---@param PedIndex integer
---@param ArmourToAdd integer
function PED.ADD_ARMOUR_TO_PED(PedIndex, ArmourToAdd) end

---@param ped integer
---@param p1 integer
function PED._0x5CA20FBE49891BBD(ped, p1) end

---@param PedIndex integer
---@param VehicleIndex integer
---@param seat integer
function PED.SET_PED_INTO_VEHICLE(PedIndex, VehicleIndex, seat) end

---@param PedIndex integer
function PED.SET_PED_MOVE_ANIMS_BLEND_OUT(PedIndex) end

---@param ped integer
---@param p1 any
function PED._0x606D529DADA3C940(ped, p1) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_MALE(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_HUMAN(PedIndex) end

---@param PedIndex integer
---@param ConsiderEnteringAsInVehicle boolean
---@return integer
function PED.GET_VEHICLE_PED_IS_IN(PedIndex, ConsiderEnteringAsInVehicle) end

---@param PedIndex integer
function PED.RESET_PED_LAST_VEHICLE(PedIndex) end

---@param p0 boolean
function PED._0xC6136B40FFFB778B(p0) end

---@param ped integer
---@param clipset any
function PED._0x6E8B87139854022D(ped, clipset) end

---@return integer
function PED._GET_NUM_FREE_SLOTS_IN_PED_POOL() end

---@param numPeds integer
function PED._RESERVE_AMBIENT_PEDS(numPeds) end

---@param numPeds integer
function PED._RESERVE_AMBIENT_PEDS_TOTAL(numPeds) end

---@param numPeds integer
function PED._UNRESERVE_AMBIENT_PEDS(numPeds) end

---@return integer
function PED._GET_NUM_RESERVED_AMBIENT_PEDS_DESIRED() end

---@return integer
function PED._GET_NUM_RESERVED_AMBIENT_PEDS_READY() end

---@return boolean
function PED._ARE_ALL_AMBIENT_PED_RESERVATIONS_READY() end

---@param multiplier number
function PED._SET_SCENARIO_PED_RANGE_MULTIPLIER_THIS_FRAME(multiplier) end

---@param volume integer
function PED._0x9E3842E5DAD69F80(volume) end

---@param multiplier number
function PED._SET_AMBIENT_PED_DENSITY_MULTIPLIER_THIS_FRAME(multiplier) end

---@param multiplier number
function PED.SET_SCENARIO_PED_DENSITY_MULTIPLIER_THIS_FRAME(multiplier) end

---@param multiplier number
function PED._SET_AMBIENT_ANIMAL_DENSITY_MULTIPLIER_THIS_FRAME(multiplier) end

---@param multiplier number
function PED._SET_AMBIENT_HUMAN_DENSITY_MULTIPLIER_THIS_FRAME(multiplier) end

---@param multiplier number
function PED._SET_SCENARIO_ANIMAL_DENSITY_MULTIPLIER_THIS_FRAME(multiplier) end

---@param multiplier number
function PED._SET_SCENARIO_HUMAN_DENSITY_MULTIPLIER_THIS_FRAME(multiplier) end

---@param configHash integer
function PED._SET_SCENARIO_PED_DENSITY_THIS_FRAME(configHash) end

function PED.INSTANTLY_FILL_PED_POPULATION() end

function PED._0xBFA6B7731C3BAF02() end

---@return boolean
function PED.IS_INSTANTLY_FILL_PED_POPULATION_FINISHED() end

---@param MinX number
---@param MinY number
---@param MinZ number
---@param MaxX number
---@param MaxY number
---@param MaxZ number
function PED.SET_PED_NON_CREATION_AREA(MinX, MinY, MinZ, MaxX, MaxY, MaxZ) end

function PED.CLEAR_PED_NON_CREATION_AREA() end

---@param volume integer
---@param entity integer
---@param offsetX number
---@param offsetY number
---@param offsetZ number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param p8 integer
---@param p9 boolean
function PED._ATTACH_VOLUME_TO_ENTITY(volume, entity, offsetX, offsetY, offsetZ, rotX, rotY, rotZ, p8, p9) end

---@param volume integer
---@param entity integer
function PED._DETACH_VOLUME_FROM_ENTITY(volume, entity) end

---@param ped integer
---@param mount integer
---@param seatIndex integer
---@param p3 boolean
function PED.SET_PED_ONTO_MOUNT(ped, mount, seatIndex, p3) end

---@param ped integer
---@param p1 boolean
---@param p2 boolean
function PED._REMOVE_PED_FROM_MOUNT(ped, p1, p2) end

---@param mount integer
---@param modelHash integer
---@param index integer
---@param p3 boolean
---@param p4 boolean
---@param p5 boolean
---@param p6 boolean
---@return integer
function PED.CREATE_PED_ON_MOUNT(mount, modelHash, index, p3, p4, p5, p6) end

---@param mount integer
---@param seat integer
---@return boolean
function PED._IS_MOUNT_SEAT_FREE(mount, seat) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_ON_MOUNT(PedIndex) end

---@param ped integer
---@param p1 boolean
---@return boolean
function PED.IS_PED_FULLY_ON_MOUNT(ped, p1) end

---@param PedIndex integer
---@return integer
function PED.GET_MOUNT(PedIndex) end

---@param ped integer
---@return integer
function PED._GET_LAST_LED_MOUNT(ped) end

---@param ped integer
---@return integer
function PED._GET_LAST_MOUNT(ped) end

---@param ped1 integer
---@param ped2 integer
function PED._0xED1C764997A86D5A(ped1, ped2) end

---@param ped integer
---@param p1 boolean
function PED._0xB8AB265426CFE6DD(ped, p1) end

---@param mount integer
---@param player integer
---@return integer
function PED._0xE8D1CCB9375C101B(mount, player) end

---@param mount integer
---@param player integer
---@param dismountedTimestamp integer
function PED._0xA691C10054275290(mount, player, dismountedTimestamp) end

---@param player integer
---@param horseSlot integer
function PED._0x6734F0A6A52C371C(player, horseSlot) end

---@param ped integer
---@param p1 boolean
function PED._0x024EC9B649111915(ped, p1) end

---@param ped integer
---@param animal integer
---@param p2 boolean
function PED.SET_PED_OWNS_ANIMAL(ped, animal, p2) end

---@param animal integer
---@return integer
function PED._GET_ACTIVE_ANIMAL_OWNER(animal) end

---@param horse integer
---@param clear boolean
function PED._CLEAR_ACTIVE_ANIMAL_OWNER(horse, clear) end

---@param horse integer
---@return integer
function PED._GET_HORSE_TAMING_STATE(horse) end

---@param animal integer
---@param p2 number
function PED._0x54D3CD482742C482(animal, p2) end

---@param animal integer
---@param p2 number
function PED._0x5CB2EBB467BE3ED6(animal, p2) end

---@param animal integer
---@param p2 number
function PED._0x9F0F28B42C4EE80A(animal, p2) end

---@param ped integer
---@param bondingLevel integer
function PED._SET_MOUNT_BONDING_LEVEL(ped, bondingLevel) end

---@param ped integer
---@param toggle boolean
function PED._SET_MOUNT_SECURITY_ENABLED(ped, toggle) end

---@param ped integer
---@param p1 any
function PED._0x9B65444C07B782BF(ped, p1) end

---@param ped integer
---@param animal integer
---@return boolean
function PED.IS_ANIMAL_INTERACTION_POSSIBLE(ped, animal) end

---@param ped integer
---@return boolean
function PED._IS_ANIMAL_INTERACTION_RUNNING(ped) end

---@param ped integer
---@return integer
function PED._0x8BE24D74D74C6E9B(ped) end

---@param ped integer
---@return boolean
function PED._0x77243ED4F7CAAA55(ped) end

---@param PedIndex integer
---@param p1 boolean
---@return boolean
function PED.IS_PED_ON_VEHICLE(PedIndex, p1) end

---@param PedIndex integer
---@param VehicleIndex integer
---@return boolean
function PED.IS_PED_ON_SPECIFIC_VEHICLE(PedIndex, VehicleIndex) end

---@param ped integer
function PED._WARP_PED_OUT_OF_VEHICLE(ped) end

---@param PedIndex integer
---@param MoneyToSet integer
function PED.SET_PED_MONEY(PedIndex, MoneyToSet) end

---@param PedIndex integer
---@return integer
function PED.GET_PED_MONEY(PedIndex) end

---@param Block boolean
function PED.SET_BLOCKING_OF_NON_TEMPORARY_EVENTS_FOR_AMBIENT_PEDS_THIS_FRAME(Block) end

---@param ped integer
---@param p1 integer
function PED._0x34EDDD59364AD74A(ped, p1) end

---@param ped integer
function PED._0x2D976DBDC731DF80(ped) end

---@param PedIndex integer
---@param VehicleIndex integer
---@return boolean
function PED.IS_PED_SITTING_IN_VEHICLE(PedIndex, VehicleIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_SITTING_IN_ANY_VEHICLE(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_ON_FOOT(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_PLANTING_BOMB(PedIndex) end

---@param PedIndex integer
---@param minDist number
---@param maxDist number
---@return Vector3
function PED.GET_DEAD_PED_PICKUP_COORDS(PedIndex, minDist, maxDist) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_IN_ANY_BOAT(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_IN_ANY_HELI(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_IN_ANY_PLANE(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_IN_FLYING_VEHICLE(PedIndex) end

---@param ped integer
---@return boolean
function PED._0x256EDD55C6BE1482(ped) end

---@param PedIndex integer
---@param ReturnBoneTag integer
---@return boolean
---@return integer
function PED.GET_PED_LAST_DAMAGE_BONE(PedIndex, ReturnBoneTag) end

---@param PedIndex integer
function PED.CLEAR_PED_LAST_DAMAGE_BONE(PedIndex) end

---@param ped integer
---@return integer
function PED._GET_PED_DAMAGE_CLEANLINESS(ped) end

---@param ped integer
---@param damageCleanliness integer
function PED._SET_PED_DAMAGE_CLEANLINESS(ped, damageCleanliness) end

---@param ped integer
---@return boolean
function PED._GET_PED_DAMAGED(ped) end

---@param ped integer
---@param damaged boolean
function PED._SET_PED_DAMAGED(ped, damaged) end

---@param player integer
---@param modifier number
---@param p2 integer
---@param p3 integer
---@return any
function PED._SET_PLAYER_CURRENT_ANIMAL_DAMAGE_MODIFIER(player, modifier, p2, p3) end

---@param player integer
function PED._UPDATE_ANIMAL_DAMAGE_MODIFIER(player) end

---@param player integer
---@return number
function PED._GET_PLAYER_CURRENT_ANIMAL_DAMAGE_MODIFIER(player) end

---@param p0 integer
---@param model integer
---@param damageCleanliness integer
---@param p3 integer
---@return any
function PED._0xB29C553BA582D09E(p0, model, damageCleanliness, p3) end

---@param p0 integer
---@param ped integer
---@param damageCleanliness integer
---@param p3 integer
---@return boolean
function PED._0x101B45C5F56D970F(p0, ped, damageCleanliness, p3) end

---@param outInventoryItemArray integer
---@param ped integer
---@param damageCleanliness integer
---@param skinningQuality integer
---@return integer
function PED._COMPUTE_SATCHEL_ITEM_FOR_PED_CARCASS(outInventoryItemArray, ped, damageCleanliness, skinningQuality) end

---@param p0 any
---@param pedAttached integer
---@param damageCleanliness integer
---@return boolean
function PED.COMPUTE_SATCHEL_ITEM_FOR_PED_DAMAGE(p0, pedAttached, damageCleanliness) end

---@param Modifier number
function PED.SET_AI_WEAPON_DAMAGE_MODIFIER(Modifier) end

function PED.RESET_AI_WEAPON_DAMAGE_MODIFIER() end

---@param ped integer
---@param totalDamage number
function PED._SET_TOTAL_PED_DAMAGE_FROM_AI(ped, totalDamage) end

---@param ped integer
function PED._0xA6D6F03095C88F59(ped) end

---@param ped integer
---@return number
function PED._GET_TOTAL_PED_DAMAGE_FROM_AI(ped) end

---@param ped integer
---@param damageModifier number
function PED.SET_PED_TO_PLAYER_WEAPON_DAMAGE_MODIFIER(ped, damageModifier) end

---@param ped integer
---@return number
function PED.GET_PED_TO_PLAYER_WEAPON_DAMAGE_MODIFIER(ped) end

---@param horse integer
---@param modifier number
function PED._SET_CURRENT_DEFENSE_AGAINST_PLAYERS_MODIFIER(horse, modifier) end

---@param ped integer
---@return number
function PED._0x763FA8A9D76EE3A7(ped) end

---@param Modifier number
function PED.SET_AI_MELEE_WEAPON_DAMAGE_MODIFIER(Modifier) end

---@param ped integer
---@param modifier number
function PED._SET_ACCURACY_AGAINST_LOCAL_PLAYER_MODIFIER(ped, modifier) end

---@param ped integer
---@return number
function PED._GET_ACCURACY_AGAINST_LOCAL_PLAYER_MODIFIER(ped) end

---@param ped integer
---@param multiplier number
function PED._SET_PED_HEADSHOT_DAMAGE_MULTIPLIER(ped, multiplier) end

---@param ped integer
---@param p1 integer
---@param p2 boolean
function PED._0xDEE8D30AA5C2E28D(ped, p1, p2) end

---@param ped integer
---@param p1 integer
---@param p2 boolean
function PED._0xE1B3BE07D3AADDED(ped, p1, p2) end

---@param ped integer
---@param p1 integer
---@param p2 boolean
function PED._0x32CEDA9A0AB4CEF7(ped, p1, p2) end

---@param ped integer
---@param p1 integer
---@param p2 boolean
function PED._0x52A24D8A1DA89658(ped, p1, p2) end

---@param ped integer
---@param p1 integer
---@param p2 boolean
function PED._0x34B5CEAC180A5D6E(ped, p1, p2) end

---@param ped integer
---@param p1 integer
---@param p2 boolean
function PED._0x4F27603E44A8E4C0(ped, p1, p2) end

---@param ped integer
---@param p1 integer
---@param p2 number
function PED._0x3FDCC1F8C17E303E(ped, p1, p2) end

---@param ped integer
---@param p1 integer
---@param p2 number
function PED._0xE50C9816B3F22D8B(ped, p1, p2) end

---@param ped integer
---@param modifier number
function PED._SET_DEFENSE_MODIFIER_FOR_PED(ped, modifier) end

---@param ped integer
---@param healthAmount number
function PED._SET_MIN_PED_HEALTH_THRESHOLD(ped, healthAmount) end

---@param ped integer
---@param p1 boolean
function PED._0xC5B78E41DCF8227C(ped, p1) end

---@param PedIndex integer
---@param bAllowTargetted boolean
function PED.SET_PED_CAN_BE_TARGETTED(PedIndex, bAllowTargetted) end

---@param PedIndex integer
---@param team integer
---@param bAllowTargetted boolean
function PED.SET_PED_CAN_BE_TARGETTED_BY_TEAM(PedIndex, team, bAllowTargetted) end

---@param PedIndex integer
---@param PlayerIndex integer
---@param bAllowTargetted boolean
function PED.SET_PED_CAN_BE_TARGETTED_BY_PLAYER(PedIndex, PlayerIndex, bAllowTargetted) end

---@param ped integer
---@param player integer
---@param flag integer
---@param enable boolean
function PED._SET_INTERACTION_LOCKON_FLAG(ped, player, flag, enable) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_FALLING(PedIndex) end

---@param ped integer
---@return boolean
function PED._IS_PED_SLIDING(ped) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_JUMPING(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_CLIMBING(PedIndex) end

---@param ped integer
---@return boolean
function PED._IS_PED_CLIMBING_LADDER(ped) end

---@param ped integer
---@return boolean
function PED._0x577C60BA06D0EA64(ped) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_VAULTING(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_DIVING(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_OPENING_DOOR(PedIndex) end

---@param ped integer
---@return boolean
function PED._0x5C6C7C70CA302801(ped) end

---@param ped integer
---@return boolean
function PED._0xB91AB3BE7F655D49(ped) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_IN_ANY_TAXI(PedIndex) end

---@param PedIndex integer
---@param IdRange number
function PED.SET_PED_ID_RANGE(PedIndex, IdRange) end

---@param ped integer
---@return number
function PED._GET_PED_ID_RANGE(ped) end

---@param PedIndex integer
---@param bHighlyPerceptive boolean
function PED.SET_PED_HIGHLY_PERCEPTIVE(PedIndex, bHighlyPerceptive) end

---@param PedIndex integer
---@param duration number
function PED.SET_PED_INJURED_ON_GROUND_BEHAVIOUR(PedIndex, duration) end

---@param PedIndex integer
function PED.DISABLE_PED_INJURED_ON_GROUND_BEHAVIOUR(PedIndex) end

---@param ped integer
function PED._0x028E7B3BBA0BD2FC(ped) end

---@param ped integer
---@return boolean
function PED._0xFA8C10DCE0706D43(ped) end

---@param ped integer
---@param modifier number
function PED._SET_PED_ANIMAL_DETECTION_MODIFIER(ped, modifier) end

---@param ped integer
---@return number
function PED._0x2BA9D7BF629F920C(ped) end

---@param PedIndex integer
---@param SeeingRange number
function PED.SET_PED_SEEING_RANGE(PedIndex, SeeingRange) end

---@param ped integer
---@return number
function PED._0x900CA00CE703E1E2(ped) end

---@param PedIndex integer
---@param HearingRange number
function PED.SET_PED_HEARING_RANGE(PedIndex, HearingRange) end

---@param PedIndex integer
---@param fAngle number
function PED.SET_PED_VISUAL_FIELD_MIN_ANGLE(PedIndex, fAngle) end

---@param PedIndex integer
---@param fAngle number
function PED.SET_PED_VISUAL_FIELD_MAX_ANGLE(PedIndex, fAngle) end

---@param PedIndex integer
---@param fDistance number
function PED.SET_PED_VISUAL_FIELD_PERIPHERAL_RANGE(PedIndex, fDistance) end

---@param PedIndex integer
---@param fAngle number
function PED.SET_PED_VISUAL_FIELD_CENTER_ANGLE(PedIndex, fAngle) end

---@param ped integer
---@param p1 number
---@param p2 number
---@param p3 number
---@param p4 number
function PED._0x9AB33CB5834885B3(ped, p1, p2, p3, p4) end

---@param ped integer
---@param p1 number
function PED._0x899DFA0009AC93DE(ped, p1) end

---@param ped integer
---@param p1 number
---@param p2 number
---@param p3 number
---@param p4 number
function PED._0x3A5697B80FED5EBE(ped, p1, p2, p3, p4) end

---@param PedIndex integer
---@param bStealth boolean
---@param p2 any
---@param p3 any
function PED.SET_PED_STEALTH_MOVEMENT(PedIndex, bStealth, p2, p3) end

---@param PedIndex integer
---@return boolean
function PED.GET_PED_STEALTH_MOVEMENT(PedIndex) end

---@param ped integer
---@param state boolean
---@param p2 integer
---@param immediately boolean
function PED._SET_PED_CROUCH_MOVEMENT(ped, state, p2, immediately) end

---@param ped integer
---@return boolean
function PED.GET_PED_CROUCH_MOVEMENT(ped) end

---@param ped integer
---@return boolean
function PED.GET_PED_IS_DOING_COMBAT_ROLL(ped) end

---@param DefaultTaskType integer
---@return integer
function PED.CREATE_GROUP(DefaultTaskType) end

---@param PedIndex integer
---@param GroupUniqueID integer
---@param p2 boolean
function PED.SET_PED_AS_GROUP_LEADER(PedIndex, GroupUniqueID, p2) end

---@param PedIndex integer
---@param GroupUniqueID integer
function PED.SET_PED_AS_GROUP_MEMBER(PedIndex, GroupUniqueID) end

---@param PedIndex integer
---@param GroupUniqueID integer
---@param bEnabled boolean
function PED.SET_PED_CAN_TELEPORT_TO_GROUP_LEADER(PedIndex, GroupUniqueID, bEnabled) end

---@param UniqueGroupID integer
function PED.REMOVE_GROUP(UniqueGroupID) end

---@param PedIndex integer
function PED.REMOVE_PED_FROM_GROUP(PedIndex) end

---@param PedIndex integer
---@param UniqueGroupID integer
---@param p2 boolean
---@return boolean
function PED.IS_PED_GROUP_MEMBER(PedIndex, UniqueGroupID, p2) end

---@param ped integer
---@param groupId integer
---@return boolean
function PED._IS_PED_GROUP_LEADER(ped, groupId) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_HANGING_ON_TO_VEHICLE(PedIndex) end

---@param UniqueGroupID integer
---@param SeparationRange number
function PED.SET_GROUP_SEPARATION_RANGE(UniqueGroupID, SeparationRange) end

---@param groupId integer
---@param p1 integer
function PED._0x89E59DBD15E21177(groupId, p1) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_PRONE(PedIndex) end

---@param ped integer
---@return boolean
function PED._IS_PED_INVESTIGATING(ped) end

---@param PedIndex integer
---@param TargetPedIndex integer
---@return boolean
function PED.IS_PED_IN_COMBAT(PedIndex, TargetPedIndex) end

---@param PedIndex integer
---@param TargetPedIndex integer
---@return boolean
function PED.CAN_PED_IN_COMBAT_SEE_TARGET(PedIndex, TargetPedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_JACKING(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_BEING_JACKED(PedIndex) end

---@param PedIndex integer
---@param WeaponType integer
---@return boolean
function PED.IS_PED_BEING_STUNNED(PedIndex, WeaponType) end

---@param PedIndex integer
---@return integer
function PED.GET_PEDS_JACKER(PedIndex) end

---@param PedIndex integer
---@return integer
function PED.GET_JACK_TARGET(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_FLEEING(PedIndex) end

---@param PedIndex integer
---@param p1 boolean
---@param p2 boolean
---@return boolean
function PED.IS_PED_IN_COVER(PedIndex, p1, p2) end

---@param ped1 integer
---@param ped2 integer
---@param p2 number
---@return boolean
function PED._0x2DD4E0E26DFAD97D(ped1, ped2, p2) end

---@param ped integer
---@return boolean
function PED._PED_WAS_KILLED_BY_HEADSHOT(ped) end

---@param ped integer
---@return boolean
function PED._PED_DUELING_DID_PLAYER_HEADSHOT_OPPONENT(ped) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_IN_COVER_FACING_LEFT(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_GOING_INTO_COVER(PedIndex) end

---@param ped integer
---@return boolean
function PED.IS_PED_RESPONDING_TO_THREAT(ped) end

---@param ped integer
---@return integer
function PED._GET_ACTIVE_DYNAMIC_SCENARIO_2(ped) end

---@param ped integer
---@return integer
function PED._GET_ACTIVE_DYNAMIC_SCENARIO(ped) end

---@param ped integer
---@param object integer
---@param conditionalAnim any
---@param p3 any
---@param p4 any
---@param p5 boolean
---@return boolean
function PED._GIVE_PED_SCENARIO_PROP(ped, object, conditionalAnim, p3, p4, p5) end

---@param ped integer
---@param object integer
---@param conditionalAnim any
---@param scenarioType integer
---@param p4 integer
---@param p5 boolean
---@return boolean
function PED.GIVE_PED_HASH_SCENARIO_PROP(ped, object, conditionalAnim, scenarioType, p4, p5) end

---@param ped integer
---@param object integer
---@param p2 any
---@param p3 any
---@param p4 boolean
---@return boolean
function PED._GIVE_PED_SCENARIO_PROP_DYNAMIC(ped, object, p2, p3, p4) end

---@param ped integer
---@param object integer
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 boolean
---@return any
function PED._REQUEST_PROP_SCENARIO_PED(ped, object, p2, p3, p4, p5) end

---@param ped integer
---@param object integer
---@param p2 any
---@param scenarioType integer
---@param p4 any
---@param p5 boolean
---@return any
function PED._REQUEST_PED_FOR_SCENARIO_TYPE(ped, object, p2, scenarioType, p4, p5) end

---@param ped integer
---@param propName any
---@param detachProp boolean
---@return integer
function PED._GET_PED_REGISTER_PROP(ped, propName, detachProp) end

---@param PedIndex integer
---@return integer
function PED.GET_SEAT_PED_IS_TRYING_TO_ENTER(PedIndex) end

---@param PedIndex integer
---@return integer
function PED.GET_PED_SOURCE_OF_DEATH(PedIndex) end

---@param PedIndex integer
---@return integer
function PED.GET_PED_CAUSE_OF_DEATH(PedIndex) end

---@param PedIndex integer
---@return integer
function PED.GET_PED_TIME_OF_DEATH(PedIndex) end

---@param TargetIndex integer
---@param flag integer
---@return integer
function PED.COUNT_PEDS_IN_COMBAT_WITH_TARGET(TargetIndex, flag) end

---@param ped integer
---@param itemset integer
---@param flag integer
---@return integer
function PED._GET_PEDS_IN_COMBAT_WITH_TARGET(ped, itemset, flag) end

---@param TargetIndex integer
---@param vecSearchCenterX number
---@param vecSearchCenterY number
---@param vecSearchCenterZ number
---@param fSearchRadius number
---@param flag integer
---@return integer
function PED.COUNT_PEDS_IN_COMBAT_WITH_TARGET_WITHIN_RADIUS(TargetIndex, vecSearchCenterX, vecSearchCenterY, vecSearchCenterZ, fSearchRadius, flag) end

---@param ped integer
---@return integer
function PED.GET_CURRENT_TARGET_FOR_PED(ped) end

---@param PedIndex integer
---@param relGroup integer
function PED.SET_PED_RELATIONSHIP_GROUP_DEFAULT_HASH(PedIndex, relGroup) end

---@param modelHash integer
---@return integer
function PED._GET_DEFAULT_RELATIONSHIP_GROUP_HASH(modelHash) end

---@param PedIndex integer
---@param relGroup integer
function PED.SET_PED_RELATIONSHIP_GROUP_HASH(PedIndex, relGroup) end

---@param RelationshipType integer
---@param relGroup integer
---@param otherRelGroup integer
function PED.SET_RELATIONSHIP_BETWEEN_GROUPS(RelationshipType, relGroup, otherRelGroup) end

---@param RelationshipType integer
---@param relGroup integer
---@param otherRelGroup integer
function PED.CLEAR_RELATIONSHIP_BETWEEN_GROUPS(RelationshipType, relGroup, otherRelGroup) end

---@param sName any
---@param group integer
---@return boolean
---@return integer
function PED.ADD_RELATIONSHIP_GROUP(sName, group) end

---@param group integer
function PED.REMOVE_RELATIONSHIP_GROUP(group) end

---@param PedIndex integer
---@param SecondPedIndex integer
---@return integer
function PED.GET_RELATIONSHIP_BETWEEN_PEDS(PedIndex, SecondPedIndex) end

---@param PedIndex integer
---@return integer
function PED.GET_PED_RELATIONSHIP_GROUP_DEFAULT_HASH(PedIndex) end

---@param PedIndex integer
---@return integer
function PED.GET_PED_RELATIONSHIP_GROUP_HASH(PedIndex) end

---@param relGroupA integer
---@param relGroupB integer
---@return integer
function PED.GET_RELATIONSHIP_BETWEEN_GROUPS(relGroupA, relGroupB) end

---@param group integer
---@param p1 boolean
function PED._0xDC91F22F09BC6C2F(group, p1) end

---@param group integer
---@param p1 boolean
function PED._0x9629FAF6460D35CB(group, p1) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param p4 number
---@param relationshipGroup integer
function PED._0x4E68C7EF706DF35D(ped, x, y, z, p4, relationshipGroup) end

---@param ped integer
---@param p1 integer
---@param x number
---@param y number
---@param z number
---@param p5 number
---@param itemset integer
---@return integer
function PED._0x3ACCE14DFA6BA8C2(ped, p1, x, y, z, p5, itemset) end

---@param PedIndex integer
---@param Distance number
---@param MaximumNumber integer
function PED.SET_PED_TO_INFORM_RESPECTED_FRIENDS(PedIndex, Distance, MaximumNumber) end

---@param ped integer
---@return boolean
function PED._0x40C9155AF8BC13F3(ped) end

---@param shockingEvent integer
---@param x number
---@param y number
---@param z number
---@param p4 number
---@param p5 integer
---@return integer
---@return integer
function PED._0xF4860514AD354226(shockingEvent, x, y, z, p4, p5) end

---@param PedIndex integer
---@param EventType integer
---@return boolean
function PED.IS_PED_RESPONDING_TO_EVENT(PedIndex, EventType) end

---@param ped integer
---@param eventType integer
---@return integer
function PED._0x5E9FAF6C513347B4(ped, eventType) end

---@param ped integer
---@param eventType integer
---@return any
function PED._0x326F7951EF0D7F75(ped, eventType) end

---@param perscharModel integer
---@param p1 integer
---@return integer
function PED._0xE76687023D8C8505(perscharModel, p1) end

---@param ped integer
---@param eventType integer
---@param coords Vector3
---@return boolean
---@return Vector3
function PED._0xCB8F4C9343EBE240(ped, eventType, coords) end

---@param PedIndex integer
---@param FiringPatternHash integer
function PED.SET_PED_FIRING_PATTERN(PedIndex, FiringPatternHash) end

---@param ped integer
---@param patternHash integer
function PED._SET_PED_FIRING_PATTERN_2(ped, patternHash) end

---@param ped integer
---@param patternHash integer
function PED._SET_PED_FIRING_PATTERN_3(ped, patternHash) end

---@param PedIndex integer
---@param ShootRate integer
function PED.SET_PED_SHOOT_RATE(PedIndex, ShootRate) end

---@param ped integer
---@param p1 integer
---@param p2 integer
function PED._0x3C529A827998F9B3(ped, p1, p2) end

---@param ped integer
---@param p1 number
---@param p2 integer
function PED._0x1F44B7E283C09EDE(ped, p1, p2) end

---@param PedIndex integer
---@param combatAttribute integer
---@param fNewValue number
function PED.SET_COMBAT_FLOAT(PedIndex, combatAttribute, fNewValue) end

---@param PedIndex integer
---@param combatAttribute integer
---@return number
function PED.GET_COMBAT_FLOAT(PedIndex, combatAttribute) end

---@param UniqueGroupID integer
---@param ReturnHasLeader integer
---@param ReturnNumberOfFollowers integer
---@return integer
---@return integer
function PED.GET_GROUP_SIZE(UniqueGroupID, ReturnHasLeader, ReturnNumberOfFollowers) end

---@param UniqueGroupID integer
---@return boolean
function PED.DOES_GROUP_EXIST(UniqueGroupID) end

---@param groupId integer
---@return boolean
function PED._0x0455546F23FF08E4(groupId) end

---@param groupId integer
---@return boolean
function PED.IS_GROUP_LOCALLY_CONTROLLED(groupId) end

---@param PedIndex integer
---@return integer
function PED.GET_PED_GROUP_INDEX(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_IN_GROUP(PedIndex) end

---@param ped integer
---@return boolean
function PED._IS_PED_LEADING_ANY_GROUP(ped) end

---@param PedIndex integer
---@return integer
function PED.GET_PLAYER_PED_IS_FOLLOWING(PedIndex) end

---@param UniqueGroupID integer
---@param GroupFormation integer
function PED.SET_GROUP_FORMATION(UniqueGroupID, GroupFormation) end

---@param groupId integer
---@return integer
function PED._GET_GROUP_FORMATION(groupId) end

---@param UniqueGroupID integer
---@param Spacing number
---@param AdjustSpeedMinDist number
---@param AdjustSpeedMaxDist number
function PED.SET_GROUP_FORMATION_SPACING(UniqueGroupID, Spacing, AdjustSpeedMinDist, AdjustSpeedMaxDist) end

---@param UniqueGroupID integer
function PED.RESET_GROUP_FORMATION_DEFAULT_SPACING(UniqueGroupID) end

---@param groupId integer
---@param p1 number
---@return boolean
function PED._0xB05CC690CDE8A4A9(groupId, p1) end

---@param groupId integer
---@param x number
---@param y number
---@param z number
---@param position integer
function PED.ADD_CUSTOM_FORMATION_LOCATION(groupId, x, y, z, position) end

---@param groupId integer
---@param p1 number
---@param p2 number
---@param p3 number
---@return boolean
function PED.ADD_FORMATION_LOCATION(groupId, p1, p2, p3) end

---@param groupId integer
---@param radius number
---@return boolean
function PED.SET_FORMATION_POSITIONS_TARGET_RADIUS(groupId, radius) end

---@param groupId integer
---@param toggle boolean
function PED._SET_FORMATION_AUTO_ASSIGN_POSITION(groupId, toggle) end

---@param ped integer
---@param position integer
---@param toggle boolean
function PED._SET_PED_FORMATION_POSITION(ped, position, toggle) end

---@param groupId integer
---@param ped integer
---@return integer
function PED._0x8AF8E647D6B2A649(groupId, ped) end

---@param ped integer
function PED._0x87C2724A56F66020(ped) end

---@param groupId integer
---@param p1 boolean
function PED._0xD5BD1B5318A81994(groupId, p1) end

---@param ped integer
---@param p1 boolean
function PED._0x9BBEAF8B0C007F1E(ped, p1) end

---@param ped integer
---@param p1 boolean
function PED._0xC99F104BDF8C7F5A(ped, p1) end

---@param ped integer
---@param p1 number
function PED._0x02E741E19E39628C(ped, p1) end

---@param groupId integer
---@param p1 boolean
function PED._0x97C475212B327666(groupId, p1) end

---@param groupId integer
---@param p1 boolean
function PED._0x154B7E841AC7412F(groupId, p1) end

---@param groupId integer
---@param p1 boolean
function PED._0x8AFCCC0F18D70018(groupId, p1) end

---@param groupId integer
---@param p1 number
---@param p2 number
function PED._0xE1103300F3456DE7(groupId, p1, p2) end

---@param groupId integer
---@param p1 boolean
function PED._0xA8A95CECB1906EA2(groupId, p1) end

---@param groupId integer
---@param p1 number
---@param p2 number
---@param p3 number
---@param p4 number
function PED._0xDDFAD4DEAA7FA362(groupId, p1, p2, p3, p4) end

---@param groupId integer
---@param p1 number
---@param p2 number
---@param p3 number
---@param p4 number
function PED._0x966DE09688A1DE39(groupId, p1, p2, p3, p4) end

---@param groupId integer
---@param p1 integer
function PED._0x7E5185B979706210(groupId, p1) end

---@param groupId integer
---@param p1 boolean
function PED._0x40C3524D4ED83554(groupId, p1) end

---@param groupId integer
---@param p1 boolean
function PED._0x86FAFC18E3D4380C(groupId, p1) end

---@param groupId integer
---@param p1 boolean
function PED._0x07EA5B053FA60AC7(groupId, p1) end

---@param ped integer
---@param targetEntity integer
---@param p2 number
---@param p3 number
---@param p4 number
---@param p5 number
---@param p6 number
---@param p7 number
---@param p8 number
---@param p9 any
function PED._0xF9CBD46433E36713(ped, targetEntity, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param PedIndex integer
---@return integer
function PED.GET_VEHICLE_PED_IS_USING(PedIndex) end

---@param PedIndex integer
---@return integer
function PED.GET_VEHICLE_PED_IS_ENTERING(PedIndex) end

---@param horse integer
---@return integer
function PED._GET_VEHICLE_DRAFT_HORSE_IS_ATTACHED_TO(horse) end

---@param horse integer
---@return integer
function PED._GET_LAST_VEHICLE_DRAFT_HORSE_WAS_ATTACHED_TO(horse) end

---@param ped integer
---@return integer
function PED.GET_SEAT_PED_IS_USING(ped) end

---@param ped integer
---@return integer
function PED._GET_TRANSPORT_PED_IS_SEATED_ON(ped) end

---@param ped integer
---@return boolean
function PED.IS_PED_ENTERING_ANY_TRANSPORT(ped) end

---@param PedIndex integer
---@param isAffectedByGravity boolean
function PED.SET_PED_GRAVITY(PedIndex, isAffectedByGravity) end

---@param animal integer
---@param toggle boolean
function PED._0x96595B36D6A2279B(animal, toggle) end

---@param ped integer
---@param toggle boolean
function PED._SET_PED_IMMERSION_FLAG(ped, toggle) end

---@param animal integer
---@param p1 boolean
---@param p2 number
---@param p3 number
function PED._0xA90684ED185CCB4B(animal, p1, p2, p3) end

---@param ped integer
---@param enabled boolean
function PED._FAKE_SET_PED_LOCO_INJURED(ped, enabled) end

---@param ped integer
---@param pedKiller integer
---@param weapon integer
function PED._FORCE_PED_DEATH(ped, pedKiller, weapon) end

---@param PedIndex integer
---@param Damage integer
---@param DamageArmourFlag boolean
---@param boneId integer
---@param InstigatorIndex integer
function PED.APPLY_DAMAGE_TO_PED(PedIndex, Damage, DamageArmourFlag, boneId, InstigatorIndex) end

---@param ped integer
---@param p1 boolean
function PED._0xBAD2A311667A50D7(ped, p1) end

---@param PedIndex integer
---@return integer
function PED.GET_PED_TYPE(PedIndex) end

---@param PedIndex integer
---@param bSetRelationshipGroup boolean
function PED.SET_PED_AS_COP(PedIndex, bSetRelationshipGroup) end

---@param ped integer
---@param p1 boolean
function PED._0x405180B14DA5A935(ped, p1) end

---@param ped integer
---@param personality integer
function PED._SET_PED_INTERACTION_PERSONALITY(ped, personality) end

---@param ped integer
---@return integer
function PED._GET_PED_INTERACTION_PERSONALITY(ped) end

---@param ped integer
---@param personality integer
function PED._SET_PED_PERSONALITY(ped, personality) end

---@param ped integer
function PED._0x329772C47DBB2FBC(ped) end

---@param ped integer
---@param pedInDisputeWith integer
---@return boolean
function PED._GET_IS_PED_IN_DISPUTE_WITH_PED(ped, pedInDisputeWith) end

---@param ped integer
---@return boolean
function PED._0x94132D7C8D3575C4(ped) end

---@param ped integer
---@param speechParams integer
function PED._0x8AF46E5159A5B620(ped, speechParams) end

---@param ped integer
---@param p1 any
function PED._0x45FEA6D5539BD474(ped, p1) end

---@param ped integer
---@param speech any
function PED._SET_PED_INTERACTION_POSITIVE_RESPONSE(ped, speech) end

---@param ped integer
---@param p1 any
function PED._0xE37ACEE15AC50C7E(ped, p1) end

---@param ped integer
---@param speech any
function PED._SET_PED_INTERACTION_NEGATIVE_RESPONSE(ped, speech) end

---@param ped integer
---@param p1 any
function PED._0x41C23A8E6B344867(ped, p1) end

---@param ped integer
---@param player integer
---@return boolean
function PED.GET_IS_PED_RESPONDING_TO_POSITIVE_INTERACTION(ped, player) end

---@param ped integer
---@param player integer
---@return boolean
function PED.GET_IS_PED_RESPONDING_TO_NEGATIVE_INTERACTION(ped, player) end

---@param ped integer
function PED._0xA7DC9266ED6A4E51(ped) end

---@param ped integer
---@return any
function PED._0x89816B58C3466262(ped) end

---@param ped1 integer
---@param ped2 integer
function PED._0x97B06669AC569003(ped1, ped2) end

---@param ped integer
---@param p1 number
function PED._0x85F500F4E24CA43E(ped, p1) end

---@param ped integer
---@param p1 number
function PED._0x9B9B9FA0EA283E3D(ped, p1) end

---@param ped integer
---@param p1 number
function PED._0xEC60D1D225BC50AA(ped, p1) end

---@param ped integer
---@param p1 number
function PED._0x12F2D161BF4031FC(ped, p1) end

function PED._0x0ADA3EC589E1736E() end

---@param ped integer
---@param player integer
---@param trueUntilPlayerPocketsItem boolean
---@return boolean
function PED._GET_IS_PED_BEING_ROBBED(ped, player, trueUntilPlayerPocketsItem) end

---@param legendaryAnimal integer
---@return boolean
function PED._0xD55DB4466D00A258(legendaryAnimal) end

---@param PedIndex integer
---@param MaxHealth integer
function PED.SET_PED_MAX_HEALTH(PedIndex, MaxHealth) end

---@param PedIndex integer
---@return integer
function PED.GET_PED_MAX_HEALTH(PedIndex) end

---@param ped integer
---@param configHash integer
function PED._SET_PED_HEALTH_CONFIG(ped, configHash) end

---@param ped integer
function PED.INIT_PED_DEFAULT_HEALTH(ped) end

---@param PedIndex integer
---@param fMaxTime number
function PED.SET_PED_MAX_TIME_IN_WATER(PedIndex, fMaxTime) end

---@param PedIndex integer
---@param fMaxTime number
function PED.SET_PED_MAX_TIME_UNDERWATER(PedIndex, fMaxTime) end

---@param ped integer
---@param p1 boolean
---@param p2 boolean
---@param p3 boolean
function PED._0xAF041C10756C30FB(ped, p1, p2, p3) end

---@param ped1 integer
---@param ped2 integer
function PED._0x5AF24CA9C974E51A(ped1, ped2) end

---@param PedIndex integer
---@param CanBeKnockedOffFlag integer
function PED.SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PedIndex, CanBeKnockedOffFlag) end

---@param PedIndex integer
---@return boolean
function PED.CAN_KNOCK_PED_OFF_VEHICLE(PedIndex) end

---@param PedIndex integer
function PED.KNOCK_PED_OFF_VEHICLE(PedIndex) end

---@param UniqueGroupID integer
---@param MemberNumber integer
---@return integer
function PED.GET_PED_AS_GROUP_MEMBER(UniqueGroupID, MemberNumber) end

---@param UniqueGroupID integer
---@return integer
function PED.GET_PED_AS_GROUP_LEADER(UniqueGroupID) end

---@param PedIndex integer
---@param KeepTasksFlag boolean
function PED.SET_PED_KEEP_TASK(PedIndex, KeepTasksFlag) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_SWIMMING(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_SWIMMING_UNDER_WATER(PedIndex) end

---@param ped integer
---@return boolean
function PED._0xDC88D06719070C39(ped) end

---@param CreateRandomCopsFlag boolean
function PED.SET_CREATE_RANDOM_COPS(CreateRandomCopsFlag) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_IN_ANY_TRAIN(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_GETTING_INTO_A_VEHICLE(PedIndex) end

---@param ped1 integer
---@param ped2 integer
---@return boolean
function PED._0x550CB89DD7F4FA3D(ped1, ped2) end

---@param PedIndex integer
---@param bEnable boolean
---@param p2 boolean
function PED.SET_ENABLE_HANDCUFFS(PedIndex, bEnable, p2) end

---@param PedIndex integer
---@param bEnable boolean
function PED.SET_ENABLE_BOUND_ANKLES(PedIndex, bEnable) end

---@param ped integer
---@return boolean
function PED._0x8822F139408B8D0A(ped) end

---@param ped integer
---@param p1 boolean
function PED._0x8822F124788B8D0A(ped, p1) end

---@param PedIndex integer
function PED.RESET_PED_WEAPON_MOVEMENT_CLIPSET(PedIndex) end

---@param ped integer
---@param animName any
---@param p2 boolean
function PED._SET_PED_GETUP_ANIMATION(ped, animName, p2) end

---@param ped integer
function PED._0x88A95BB640FC186F(ped) end

---@param PedIndex integer
function PED.RESET_PED_IN_VEHICLE_CONTEXT(PedIndex) end

---@param vehicle integer
---@param p1 integer
function PED._0x878E8104FA27CDAE(vehicle, p1) end

---@param PedIndex integer
---@param GestureGroup any
---@param p2 integer
function PED.SET_PED_GESTURE_GROUP(PedIndex, GestureGroup, p2) end

---@param ped integer
---@param locomotionArchetype any
function PED._SET_PED_DESIRED_LOCO_FOR_MODEL(ped, locomotionArchetype) end

---@param ped integer
function PED._CLEAR_PED_DESIRED_LOCO_FOR_MODEL(ped) end

---@param ped integer
---@param locoMotionType any
function PED._SET_PED_DESIRED_LOCO_MOTION_TYPE(ped, locoMotionType) end

---@param ped integer
function PED._CLEAR_PED_DESIRED_LOCO_MOTION_TYPE(ped) end

---@param ped integer
function PED._0x2371C39D4F91C288(ped) end

---@param ped integer
---@param getUpType any
function PED._REQUEST_PED_GETUP_ANIMATION(ped, getUpType) end

---@param ped integer
---@param ped2 integer
function PED.PED_COWER_IN_PLACE(ped, ped2) end

---@param ped integer
---@param p1 number
---@param p2 number
---@param p3 number
---@param ped2 integer
---@param p5 number
function PED.PED_COWER_MOVE_TO_POINT(ped, p1, p2, p3, ped2, p5) end

---@param ped integer
function PED._0x16F798A05BB9E3B5(ped) end

---@param ped integer
---@param presetName any
---@param targetPed integer
---@param duration integer
---@param flag integer
function PED._PED_EMOTIONAL_PRESET_LOCO_MOTION(ped, presetName, targetPed, duration, flag) end

---@param ped integer
function PED._PED_CLEAR_LOCO_MOTION(ped) end

---@param ped integer
function PED._0x32CCAD8A981B53D3(ped) end

---@param ped integer
---@param enabled boolean
---@param drunknessLevel number
function PED._SET_PED_DRUNKNESS(ped, enabled, drunknessLevel) end

---@param ped integer
---@return boolean
function PED._IS_PED_DRUNK(ped) end

---@param ped integer
---@return number
function PED._GET_PED_DRUNKNESS(ped) end

---@param pAnimDictName any
---@param pAnimName any
---@param scenePositionX number
---@param scenePositionY number
---@param scenePositionZ number
---@param sceneOrientationX number
---@param sceneOrientationY number
---@param sceneOrientationZ number
---@param phase number
---@param RotOrder integer
---@return Vector3
function PED.GET_ANIM_INITIAL_OFFSET_POSITION(pAnimDictName, pAnimName, scenePositionX, scenePositionY, scenePositionZ, sceneOrientationX, sceneOrientationY, sceneOrientationZ, phase, RotOrder) end

---@param pAnimDictName any
---@param pAnimName any
---@param scenePositionX number
---@param scenePositionY number
---@param scenePositionZ number
---@param sceneOrientationX number
---@param sceneOrientationY number
---@param sceneOrientationZ number
---@param phase number
---@param RotOrder integer
---@return Vector3
function PED.GET_ANIM_INITIAL_OFFSET_ROTATION(pAnimDictName, pAnimName, scenePositionX, scenePositionY, scenePositionZ, sceneOrientationX, sceneOrientationY, sceneOrientationZ, phase, RotOrder) end

---@param PedIndex integer
---@param race integer
function PED.SET_PED_RANDOM_COMPONENT_VARIATION(PedIndex, race) end

---@param PedIndex integer
---@param bDamaged boolean
---@param bHats boolean
---@param bGlasses boolean
---@param bHelmets boolean
function PED.KNOCK_OFF_PED_PROP(PedIndex, bDamaged, bHats, bGlasses, bHelmets) end

---@param PedIndex integer
---@param bBlockEvents boolean
function PED.SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(PedIndex, bBlockEvents) end

---@param ped integer
---@return boolean
function PED._GET_BLOCKING_OF_NON_TEMPORARY_EVENTS(ped) end

---@param entity integer
---@param boneId integer
---@param p2 number
---@param p3 number
---@param p4 number
function PED._0xC17A94CC8FC3C61A(entity, boneId, p2, p3, p4) end

---@param ped integer
---@param scale number
function PED._SET_PED_SCALE(ped, scale) end

---@param ped integer
---@return number
function PED._0x134775B093AD5C38(ped) end

---@param ped integer
---@return number
function PED._GET_PED_HEIGHT(ped) end

---@param modelHash integer
---@return integer
function PED._GET_PED_MODEL_SIZE_FROM_HASH(modelHash) end

---@param PedIndex integer
---@param TargetPedIndex integer
---@param p2 boolean
function PED.REGISTER_TARGET(PedIndex, TargetPedIndex, p2) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param radius number
function PED._REGISTER_HATED_TARGETS_IN_AREA(ped, x, y, z, radius) end

---@param PedIndex integer
---@param Radius number
function PED.REGISTER_HATED_TARGETS_AROUND_PED(PedIndex, Radius) end

---@param ped integer
---@param targetPed integer
---@return boolean
function PED._IS_TARGET(ped, targetPed) end

---@param ped integer
---@param targetPed integer
function PED._REMOVE_TARGET(ped, targetPed) end

---@param VecCentreCoorsX number
---@param VecCentreCoorsY number
---@param VecCentreCoorsZ number
---@param Range number
---@param bScanRandomPeds boolean
---@param bScanMissionPeds boolean
---@param ClosestPedIndex integer
---@param p7 boolean
---@param p8 boolean
---@param p9 boolean
---@param ExclusionPedType integer
---@return boolean
---@return integer
function PED.GET_CLOSEST_PED(VecCentreCoorsX, VecCentreCoorsY, VecCentreCoorsZ, Range, bScanRandomPeds, bScanMissionPeds, ClosestPedIndex, p7, p8, p9, ExclusionPedType) end

---@param PedIndex integer
---@return boolean
function PED.CAN_PED_RAGDOLL(PedIndex) end

---@param PedIndex integer
---@param MinTime integer
---@param MaxTime integer
---@param StartTask integer
---@param bAbortIfInjured boolean
---@param bAbortIfDead boolean
---@param nmTaskMessageParameterName any
---@return boolean
function PED.SET_PED_TO_RAGDOLL(PedIndex, MinTime, MaxTime, StartTask, bAbortIfInjured, bAbortIfDead, nmTaskMessageParameterName) end

---@param PedIndex integer
---@param MinTime integer
---@param MaxTime integer
---@param nFallType integer
---@param vecDirectionX number
---@param vecDirectionY number
---@param vecDirectionZ number
---@param fGroundHeight number
---@param vecGrab1X number
---@param vecGrab1Y number
---@param vecGrab1Z number
---@param vecGrab2X number
---@param vecGrab2Y number
---@param vecGrab2Z number
---@return boolean
function PED.SET_PED_TO_RAGDOLL_WITH_FALL(PedIndex, MinTime, MaxTime, nFallType, vecDirectionX, vecDirectionY, vecDirectionZ, fGroundHeight, vecGrab1X, vecGrab1Y, vecGrab1Z, vecGrab2X, vecGrab2Y, vecGrab2Z) end

---@param PedIndex integer
---@param RagdollOnCollision boolean
---@param p2 boolean
function PED.SET_PED_RAGDOLL_ON_COLLISION(PedIndex, RagdollOnCollision, p2) end

---@param ped integer
---@param toggle boolean
function PED._SET_PED_TO_DISABLE_RAGDOLL(ped, toggle) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_RAGDOLL(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_RUNNING_RAGDOLL_TASK(PedIndex) end

---@param PedIndex integer
function PED.SET_PED_RAGDOLL_FORCE_FALL(PedIndex) end

---@param ped integer
---@param p1 integer
---@param p2 boolean
function PED._0x8CB2553C559102C1(ped, p1, p2) end

---@param ped integer
---@param p1 integer
function PED._0xFD3C31A2E45671E7(ped, p1) end

---@param PedIndex integer
function PED.RESET_PED_RAGDOLL_TIMER(PedIndex) end

---@param PedIndex integer
---@param bUnlock boolean
function PED.SET_PED_CAN_RAGDOLL(PedIndex, bUnlock) end

---@param ped integer
---@return boolean
function PED._0x3AEC4A410ECAF30D(ped) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_RUNNING_MOBILE_PHONE_TASK(PedIndex) end

---@param PedIndex integer
---@param flags integer
function PED.SET_RAGDOLL_BLOCKING_FLAGS(PedIndex, flags) end

---@param PedIndex integer
---@param flags integer
function PED.CLEAR_RAGDOLL_BLOCKING_FLAGS(PedIndex, flags) end

---@param ped integer
---@param p1 number
---@param p2 number
---@param p3 number
function PED._0x9F933E0985E12C51(ped, p1, p2, p3) end

---@param ped integer
---@param p1 number
function PED._0x88B2026A3B0BE33D(ped, p1) end

---@param ped integer
---@param volume integer
---@param p2 boolean
---@param p3 boolean
---@param p4 boolean
function PED.SET_PED_DEFENSIVE_AREA_VOLUME(ped, volume, p2, p3, p4) end

---@param PedIndex integer
---@param vCentreX number
---@param vCentreY number
---@param vCentreZ number
---@param fRadius number
---@param p5 boolean
---@param p6 boolean
---@param p7 boolean
function PED.SET_PED_SPHERE_DEFENSIVE_AREA(PedIndex, vCentreX, vCentreY, vCentreZ, fRadius, p5, p6, p7) end

---@param ped integer
---@param entity integer
---@param x number
---@param y number
---@param z number
---@param radius number
---@param p6 integer
---@param p7 boolean
function PED._SET_PED_DEFENSIVE_SPHERE_ATTACHED_TO_ENTITY(ped, entity, x, y, z, radius, p6, p7) end

---@param ped integer
---@param x1 number
---@param y1 number
---@param z1 number
---@param x2 number
---@param y2 number
---@param z2 number
---@param p7 any
---@param p8 boolean
---@param p9 boolean
---@param entity integer
---@param p11 boolean
function PED._SET_PED_DEFENSIVE_AREA_TO_ANGLED_AREA(ped, x1, y1, z1, x2, y2, z2, p7, p8, p9, entity, p11) end

---@param PedIndex integer
---@param vDefendFromPosX number
---@param vDefendFromPosY number
---@param vDefendFromPosZ number
---@param bApplyToSecondaryDefensiveArea boolean
function PED.SET_PED_DEFENSIVE_AREA_DIRECTION(PedIndex, vDefendFromPosX, vDefendFromPosY, vDefendFromPosZ, bApplyToSecondaryDefensiveArea) end

---@param PedIndex integer
---@param bRemoveSecondaryDefensiveArea boolean
function PED.REMOVE_PED_DEFENSIVE_AREA(PedIndex, bRemoveSecondaryDefensiveArea) end

---@param PedIndex integer
---@param bApplyToSecondaryDefensiveArea boolean
---@return Vector3
function PED.GET_PED_DEFENSIVE_AREA_POSITION(PedIndex, bApplyToSecondaryDefensiveArea) end

---@param PedIndex integer
---@param bCheckSecondaryDefensiveArea boolean
---@return boolean
function PED.IS_PED_DEFENSIVE_AREA_ACTIVE(PedIndex, bCheckSecondaryDefensiveArea) end

---@param ped integer
---@param p1 any
---@return integer
function PED._GET_PED_DEFENSIVE_VOLUME(ped, p1) end

---@param ped integer
---@param p1 boolean
function PED._0x4EC4EA2F72B36358(ped, p1) end

---@param ped integer
---@param x number
---@param y number
---@param z number
function PED._0xCF0B19806473D324(ped, x, y, z) end

---@param ped integer
function PED._0xB4B7C92FCE7347B7(ped) end

---@param PedIndex integer
function PED.REVIVE_INJURED_PED(PedIndex) end

---@param PedIndex integer
function PED.RESURRECT_PED(PedIndex) end

---@param PedIndex integer
---@param debugName any
function PED.SET_PED_NAME_DEBUG(PedIndex, debugName) end

---@param PedIndex integer
---@param bNoCollisionUntilClear boolean
function PED.SPECIAL_FUNCTION_DO_NOT_USE(PedIndex, bNoCollisionUntilClear) end

---@param ped integer
---@return boolean
function PED._0x7020839C7302D8AC(ped) end

---@param ped integer
---@param entity integer
---@param boneIndex1 integer
---@param boneIndex2 integer
---@param x number
---@param y number
---@param z number
---@param p7 number
---@param p8 boolean
---@param p9 boolean
---@param p10 integer
function PED._0xE1AADD0055D76603(ped, entity, boneIndex1, boneIndex2, x, y, z, p7, p8, p9, p10) end

---@param ped integer
function PED._0x5A1A929C8B729B4A(ped) end

---@param ped integer
---@param p1 boolean
function PED._0x97A38B65EBDA3D50(ped, p1) end

---@param ped integer
---@return boolean
function PED._0x06A10B4D7F50B0C3(ped) end

---@param ped integer
---@return boolean
function PED._0x88A5564B19C15391(ped) end

---@param ped integer
---@return integer
function PED._0x354CA4DDDEEC397A(ped) end

---@param ped integer
---@param p1 boolean
function PED._0xFEA6126C34DF2532(ped, p1) end

---@param ped integer
---@param p1 boolean
function PED._0xA967D6A8ED2D713B(ped, p1) end

---@param pedIndex integer
---@param component integer
---@param u number
---@param v number
---@param rotation number
---@param scale number
---@param forcedFrame integer
---@param preAge number
---@param bloodName any
function PED.APPLY_PED_BLOOD_SPECIFIC(pedIndex, component, u, v, rotation, scale, forcedFrame, preAge, bloodName) end

---@param ped integer
---@param boneId integer
---@param p2 number
---@param p3 number
---@param p4 number
---@param p5 number
---@param p6 number
---@param p7 number
---@param p8 any
function PED._0x58D32261AE0F0843(ped, boneId, p2, p3, p4, p5, p6, p7, p8) end

---@param ped integer
---@param p1 boolean
function PED._0x735662994E60A710(ped, p1) end

---@param p0 any
---@param p1 any
function PED._0x91BAB9E064F036CD(p0, p1) end

---@param ped integer
---@param p1 integer
---@param p2 number
---@param p3 number
---@param p4 number
function PED._0x897934E868EDDD6C(ped, p1, p2, p3, p4) end

---@param ped integer
---@param p1 integer
---@param boneId integer
---@param moveWoundLeftRight number
---@param bloodFountainPressure number
---@param yaw number
---@param bloodFountainDirection number
---@param bloodFountainPulse number
---@param p8 number
---@param p9 number
function PED._SET_PED_ACTIVATE_WOUND_EFFECT(ped, p1, boneId, moveWoundLeftRight, bloodFountainPressure, yaw, bloodFountainDirection, bloodFountainPulse, p8, p9) end

---@param ped integer
---@param value number
function PED._UPDATE_PED_WOUND_EFFECT(ped, value) end

---@param PedIndex integer
---@param packName any
---@param preAge number
---@param alpha_param number
function PED.APPLY_PED_DAMAGE_PACK(PedIndex, packName, preAge, alpha_param) end

---@param pedIndex integer
function PED.CLEAR_PED_BLOOD_DAMAGE(pedIndex) end

---@param PedIndex integer
---@param zone integer
function PED.CLEAR_PED_BLOOD_DAMAGE_BY_ZONE(PedIndex, zone) end

---@param PedIndex integer
---@param zone integer
---@param damageDecalName any
function PED.CLEAR_PED_DAMAGE_DECAL_BY_ZONE(PedIndex, zone, damageDecalName) end

---@param ped integer
---@param p1 integer
function PED._CLEAR_PED_BLOOD_DAMAGE_FACIAL(ped, p1) end

---@param p0 any
---@param p1 any
function PED._0x34C11114887150FD(p0, p1) end

---@param ped integer
---@param p1 integer
function PED._0xD8544F6260F5F01E(ped, p1) end

---@param ped integer
---@param p1 integer
---@param p2 any
---@param p3 number
function PED._0xEB8886E1065654CD(ped, p1, p2, p3) end

---@param ped integer
---@return integer
function PED.FADE_AND_DESTROY_PED(ped) end

---@param ped integer
---@return boolean
function PED._IS_PED_QUEUED_FOR_DELETION(ped) end

---@param pedIndex integer
function PED.CLEAR_PED_WETNESS(pedIndex) end

---@param pedIndex integer
---@param height number
function PED.SET_PED_WETNESS_HEIGHT(pedIndex, height) end

---@param ped integer
---@param p1 number
function PED._0xF9CFF5BB70E8A2CB(ped, p1) end

---@param pedIndex integer
function PED.SET_PED_WETNESS_ENABLED_THIS_FRAME(pedIndex) end

---@param ped integer
function PED._0xA7A806677F8DE138(ped) end

---@param p0 any
function PED._0xA064BBABB064446F(p0) end

---@param pedIndex integer
function PED.CLEAR_PED_ENV_DIRT(pedIndex) end

---@param pedIndex integer
---@param amount number
function PED.SET_PED_SWEAT(pedIndex, amount) end

---@param PedIndex integer
function PED.CLEAR_PED_DECORATIONS(PedIndex) end

---@param PedIndex integer
---@return boolean
function PED.WAS_PED_SKELETON_UPDATED(PedIndex) end

---@param PedIndex integer
---@param bone integer
---@param vecOffsetX number
---@param vecOffsetY number
---@param vecOffsetZ number
---@return Vector3
function PED.GET_PED_BONE_COORDS(PedIndex, bone, vecOffsetX, vecOffsetY, vecOffsetZ) end

---@param vMinX number
---@param vMinY number
---@param vMinZ number
---@param vMaxX number
---@param vMaxY number
---@param vMaxZ number
---@param bNetwork boolean
---@param blockingFlags integer
---@return integer
function PED.ADD_SCENARIO_BLOCKING_AREA(vMinX, vMinY, vMinZ, vMaxX, vMaxY, vMaxZ, bNetwork, blockingFlags) end

function PED.REMOVE_SCENARIO_BLOCKING_AREAS() end

---@param ScenarioBlockingIndex integer
---@param bNetwork boolean
function PED.REMOVE_SCENARIO_BLOCKING_AREA(ScenarioBlockingIndex, bNetwork) end

---@param volume integer
---@param p1 boolean
---@param flag integer
---@return any
function PED._ADD_SCENARIO_BLOCKING_VOLUME(volume, p1, flag) end

---@param p0 any
---@return any
function PED._0x6F46F8ACB44C4FC1(p0) end

---@param p0 any
---@return boolean
function PED._IS_SCENARIO_BLOCKING_AREA_VALID(p0) end

---@param ped integer
---@param scenarioHash integer
---@return boolean
function PED.IS_PED_USING_SCENARIO_HASH(ped, scenarioHash) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_USING_ANY_SCENARIO(PedIndex) end

---@param ped integer
---@param scenario integer
---@return boolean
function PED.IS_PED_USING_THIS_SCENARIO(ped, scenario) end

---@param ped integer
---@param scenario integer
---@param p2 any
---@param p3 any
---@param p4 any
---@return boolean
function PED._CAN_PED_USE_SCENARIO_POINT(ped, scenario, p2, p3, p4) end

---@param ped integer
---@param p1 integer
---@param p2 integer
---@return boolean
function PED._0x1148F706CF4EBDDA(ped, p1, p2) end

---@param PedIndex integer
---@param vDangerPositionX number
---@param vDangerPositionY number
---@param vDangerPositionZ number
---@return boolean
function PED.SET_PED_PANIC_EXIT_SCENARIO(PedIndex, vDangerPositionX, vDangerPositionY, vDangerPositionZ) end

---@param PedIndex integer
---@param bStart boolean
function PED.TOGGLE_SCENARIO_PED_COWER_IN_PLACE(PedIndex, bStart) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function PED._0xD8CEEED54C672B5D(p0, p1, p2, p3, p4, p5, p6) end

---@param PedIndex integer
---@param vReactPositionX number
---@param vReactPositionY number
---@param vReactPositionZ number
---@return boolean
function PED.SET_PED_SHOULD_PLAY_DIRECTED_NORMAL_SCENARIO_EXIT(PedIndex, vReactPositionX, vReactPositionY, vReactPositionZ) end

---@param PedIndex integer
function PED.SET_PED_SHOULD_PLAY_NORMAL_SCENARIO_EXIT(PedIndex) end

---@param PedIndex integer
function PED.SET_PED_SHOULD_PLAY_IMMEDIATE_SCENARIO_EXIT(PedIndex) end

---@param PedIndex integer
---@param vDangerPositionX number
---@param vDangerPositionY number
---@param vDangerPositionZ number
---@param lookIntensity integer
---@return boolean
function PED.SET_PED_SHOULD_PLAY_FLEE_SCENARIO_EXIT(PedIndex, vDangerPositionX, vDangerPositionY, vDangerPositionZ, lookIntensity) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param lookIntensity integer
---@return boolean
function PED.SET_PED_SHOULD_PLAY_COMBAT_SCENARIO_EXIT(ped, x, y, z, lookIntensity) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param lookIntensity integer
---@param p5 boolean
---@return boolean
function PED.SET_PED_SHOULD_PLAY_EMOTIONAL_SCENARIO_EXIT(ped, x, y, z, lookIntensity, p5) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param lookIntensity integer
---@param p5 boolean
---@return boolean
function PED.SET_PED_SHOULD_PLAY_QUICK_SCENARIO_EXIT(ped, x, y, z, lookIntensity, p5) end

---@param ped integer
---@return boolean
function PED._0xF9331B3A314EB49D(ped) end

---@param p0 any
function PED._0xE735A7DA22E88359(p0) end

---@param p0 any
---@return any
function PED._0x82CB0F3F0C7785E5(p0) end

---@param p0 any
---@param p1 any
function PED._0xCA95C156C14B2054(p0, p1) end

---@param PedIndex integer
---@param pOverrideIdleClipName any
---@param pOverrideIdleClipDictName any
function PED.SET_FACIAL_IDLE_ANIM_OVERRIDE(PedIndex, pOverrideIdleClipName, pOverrideIdleClipDictName) end

---@param PedIndex integer
function PED.CLEAR_FACIAL_IDLE_ANIM_OVERRIDE(PedIndex) end

---@param ped integer
---@param mood integer
---@param p2 integer
function PED._REQUEST_PED_FACIAL_MOOD_THIS_FRAME(ped, mood, p2) end

---@param p0 any
---@param p1 any
function PED._0xD2F0FE8805D91647(p0, p1) end

---@param PedIndex integer
---@param p1 boolean
---@param p2 any
function PED.SET_PED_CAN_PLAY_GESTURE_ANIMS(PedIndex, p1, p2) end

---@param ped integer
function PED._0x7EDB3C766B0D073F(ped) end

---@param PedIndex integer
---@param bAlllowAmbientAnims boolean
function PED.SET_PED_CAN_PLAY_AMBIENT_ANIMS(PedIndex, bAlllowAmbientAnims) end

---@param PedIndex integer
---@param bAlllowAmbientAnims boolean
function PED.SET_PED_CAN_PLAY_AMBIENT_BASE_ANIMS(PedIndex, bAlllowAmbientAnims) end

---@param ped integer
---@param p1 boolean
function PED._0x4F63433CE3C08230(ped, p1) end

---@param PedIndex integer
---@param bEnableIK boolean
function PED.SET_PED_CAN_ARM_IK(PedIndex, bEnableIK) end

---@param ped integer
---@param toggle boolean
function PED._SET_PED_CAN_UNK_BODYPART_IK(ped, toggle) end

---@param PedIndex integer
---@param bEnableIK boolean
function PED.SET_PED_CAN_HEAD_IK(PedIndex, bEnableIK) end

---@param PedIndex integer
---@param bEnableIK boolean
function PED.SET_PED_CAN_LEG_IK(PedIndex, bEnableIK) end

---@param PedIndex integer
---@param bEnableIK boolean
function PED.SET_PED_CAN_TORSO_IK(PedIndex, bEnableIK) end

---@param PedIndex integer
---@param bEnableIK boolean
function PED.SET_PED_CAN_TORSO_REACT_IK(PedIndex, bEnableIK) end

---@param PedIndex integer
---@param bEnableIK boolean
function PED.SET_PED_CAN_TORSO_VEHICLE_IK(PedIndex, bEnableIK) end

---@param PedIndex integer
---@param bAllowAutoConversationLookAts boolean
function PED.SET_PED_CAN_USE_AUTO_CONVERSATION_LOOKAT(PedIndex, bAllowAutoConversationLookAts) end

---@param FirstPedIndex integer
---@param SecondPedIndex integer
---@return boolean
function PED.IS_PED_HEADTRACKING_PED(FirstPedIndex, SecondPedIndex) end

---@param PedIndex integer
---@param EntityIndex integer
---@return boolean
function PED.IS_PED_HEADTRACKING_ENTITY(PedIndex, EntityIndex) end

---@param p0 any
---@param p1 any
function PED._DISABLE_AMBIENT_LOOK_AT_REQUESTS(p0, p1) end

---@param ped integer
---@param p1 integer
function PED._DISABLE_ALL_LOOK_AT_REQUESTS(ped, p1) end

---@param ped integer
---@param p1 boolean
function PED._0xCD9E5F94A2F38683(ped, p1) end

---@param PedIndex integer
---@param pinFrames integer
function PED.SET_PED_CLOTH_PIN_FRAMES(PedIndex, pinFrames) end

---@param ped integer
---@param p1 integer
function PED._0x1D4636C90BBEFACB(ped, p1) end

---@param ped integer
function PED._0xEF371232BC6053E1(ped) end

---@param ped integer
---@param p1 boolean
function PED._0x86F0B6730C32AC14(ped, p1) end

---@param ped integer
---@param ropeId integer
function PED._0x8101BA1C0B462412(ped, ropeId) end

---@param PedIndex integer
---@param ConfigFlag integer
---@param bTrue boolean
function PED.SET_PED_CONFIG_FLAG(PedIndex, ConfigFlag, bTrue) end

---@param PedIndex integer
---@param ResetFlag integer
---@param bTrue boolean
function PED.SET_PED_RESET_FLAG(PedIndex, ResetFlag, bTrue) end

---@param PedIndex integer
---@param ConfigFlag integer
---@param DoDeadCheck boolean
---@return boolean
function PED.GET_PED_CONFIG_FLAG(PedIndex, ConfigFlag, DoDeadCheck) end

---@param PedIndex integer
---@param ResetFlag integer
---@return boolean
function PED.GET_PED_RESET_FLAG(PedIndex, ResetFlag) end

---@param p0 any
function PED._0xC6981AFF6D2A71C2(p0) end

---@param p0 any
---@param p1 any
function PED._0xE0FE107AB174D64A(p0, p1) end

---@param PedIndex integer
---@param seat integer
function PED.SET_PED_GROUP_MEMBER_PASSENGER_INDEX(PedIndex, seat) end

---@param PedIndex integer
---@param EntityDivingFromIndex integer
---@return boolean
---@return integer
function PED.IS_PED_EVASIVE_DIVING(PedIndex, EntityDivingFromIndex) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param p4 integer
---@param p5 number
---@param p6 integer
---@param p7 number
---@return any
function PED._SHOOT_TRIGGER_AT_COORDS(ped, x, y, z, p4, p5, p6, p7) end

---@param model integer
---@return boolean
function PED._IS_THIS_MODEL_A_HORSE(model) end

---@param PedModelHashKey integer
---@param bSurpressModel boolean
function PED.SET_PED_MODEL_IS_SUPPRESSED(PedModelHashKey, bSurpressModel) end

---@param model integer
---@return boolean
function PED._IS_PED_MODEL_SUPPRESSED(model) end

---@param ped integer
---@param p1 boolean
function PED._0x7ABBD9E449E0DB00(ped, p1) end

---@param ped integer
---@param disable boolean
function PED._SET_PED_DISABLE_KICK_MOVE(ped, disable) end

---@param PedIndex integer
---@param bAllow boolean
function PED.SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PedIndex, bAllow) end

---@param p0 any
function PED._0xE6CB36F43A95D75F(p0) end

---@param PedIndex integer
---@param nLegIkMode integer
function PED.SET_PED_LEG_IK_MODE(PedIndex, nLegIkMode) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param radius number
---@param p5 boolean
---@return boolean
function PED._IS_PED_IN_POINT(ped, x, y, z, radius, p5) end

---@param ped integer
---@param toggle boolean
function PED._SET_PED_CAN_BE_LASSOED(ped, toggle) end

---@param PedIndex integer
---@param PedCombatMoveType integer
function PED.SET_PED_COMBAT_MOVEMENT(PedIndex, PedCombatMoveType) end

---@param PedIndex integer
---@return integer
function PED.GET_PED_COMBAT_MOVEMENT(PedIndex) end

---@param ped integer
---@param p1 integer
function PED._0x815C0074A1BC0D93(ped, p1) end

---@param ped integer
---@return integer
function PED._0xFFDE295662405B25(ped) end

---@param PedIndex integer
---@param PedCombatAbilityType integer
function PED.SET_PED_COMBAT_ABILITY(PedIndex, PedCombatAbilityType) end

---@param PedIndex integer
---@param CombatRange integer
function PED.SET_PED_COMBAT_RANGE(PedIndex, CombatRange) end

---@param PedIndex integer
---@param CombatAttribute integer
---@param bActiveSkill boolean
function PED.SET_PED_COMBAT_ATTRIBUTES(PedIndex, CombatAttribute, bActiveSkill) end

---@param ped integer
---@param attributeIndex integer
---@return boolean
function PED._GET_PED_COMBAT_ATTRIBUTE(ped, attributeIndex) end

---@param ped integer
---@param p1 integer
function PED._SET_PED_COMBAT_ATTRIBUTE_HASH(ped, p1) end

---@param PedIndex integer
---@param TargetLossResponse integer
function PED.SET_PED_TARGET_LOSS_RESPONSE(PedIndex, TargetLossResponse) end

---@param p0 any
---@param p1 any
function PED._0x0A4618FFD517E24D(p0, p1) end

---@param ped integer
---@param p1 integer
function PED._0x712B2C2B2471B493(ped, p1) end

---@param p0 any
---@param p1 any
function PED._0x00B380FF2DF6AB7A(p0, p1) end

---@param ped integer
---@param combatStyleHash integer
---@param p2 integer
---@param duration number
function PED._SET_PED_COMBAT_STYLE(ped, combatStyleHash, p2, duration) end

---@param ped integer
---@param p1 integer
function PED._CLEAR_PED_COMBAT_STYLE(ped, p1) end

---@param ped integer
---@param combatStyleModHash integer
---@param duration number
function PED._SET_PED_COMBAT_STYLE_MOD(ped, combatStyleModHash, duration) end

---@param ped integer
---@param combatStyleModHash integer
function PED._CLEAR_PED_COMBAT_STYLE_MOD(ped, combatStyleModHash) end

---@param ped integer
---@return boolean
function PED._0x5BF0B9D9A8E227A0(ped) end

---@param ped integer
---@param p1 integer
function PED._0x642720D8D69328B6(ped, p1) end

---@param PedIndex integer
---@param p1 integer
---@param p2 integer
---@return boolean
function PED.IS_PED_PERFORMING_MELEE_ACTION(PedIndex, p1, p2) end

---@param ped1 integer
---@param ped2 integer
---@param p2 integer
---@return boolean
function PED._0x99DF2639DA76C1DC(ped1, ped2, p2) end

---@param ped integer
---@return number
function PED._GET_PED_MELEE_ACTION_PHASE(ped) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_BEING_STEALTH_KILLED(PedIndex) end

---@param PedIndex integer
---@return integer
function PED.GET_MELEE_TARGET_FOR_PED(PedIndex) end

---@param p0 any
function PED._0xDEDBED3020DA49DC(p0) end

---@param p0 any
function PED._0xA405BF9F01960C16(p0) end

---@param ped integer
---@return integer
function PED._GET_PED_BRAWLING_STYLE(ped) end

---@param ped integer
---@param brawlingStyle integer
function PED._SET_PED_BRAWLING_STYLE(ped, brawlingStyle) end

---@param ped integer
function PED._0x9D8DFE2DE9CB4DFC(ped) end

---@param ped integer
---@param grapple integer
---@return any
function PED._0xC48AF420371C7407(ped, grapple) end

---@param p0 any
---@param p1 any
---@return any
function PED._0x5EFA8A3D8A60D662(p0, p1) end

---@param p0 any
---@return any
function PED._0x242EDF85D4E87B65(p0) end

---@param ped integer
---@param behaviour integer
function PED._SET_PED_COMBAT_BEHAVIOUR(ped, behaviour) end

---@param p0 any
function PED._0x9A4AC116CC1EEE14(p0) end

---@param p0 any
---@param p1 any
function PED._0xE20027B414BFE6C7(p0, p1) end

---@param ped integer
---@param p1 number
function PED._SET_PED_BEAT_MULTIPLIER(ped, p1) end

---@param ped integer
---@param actionDisableFlag integer
function PED._SET_PED_ACTION_DISABLE_FLAG(ped, actionDisableFlag) end

---@param ped integer
---@param actionDisableFlag integer
function PED._CLEAR_PED_ACTION_DISABLE_FLAG(ped, actionDisableFlag) end

---@param ped integer
---@param actionDisableFlag integer
---@return boolean
function PED._IS_PED_ACTION_DISABLE_FLAG_ENABLED(ped, actionDisableFlag) end

---@param ped integer
---@param actionDisableFlag integer
function PED._SET_PED_TARGET_ACTION_DISABLE_FLAG(ped, actionDisableFlag) end

---@param ped integer
---@param actionDisableFlag integer
function PED._CLEAR_PED_TARGET_ACTION_DISABLE_FLAG(ped, actionDisableFlag) end

---@param ped integer
---@param actionDisableFlag integer
---@return boolean
function PED._IS_PED_TARGET_ACTION_DISABLE_FLAG_ENABLED(ped, actionDisableFlag) end

---@param ped integer
---@param p1 integer
function PED._0x57F35552E771BE9D(ped, p1) end

---@param ped integer
---@param p1 integer
function PED._0x7C10221CE718AA72(ped, p1) end

---@param ped integer
---@param p1 integer
---@return boolean
function PED._0x0D3B1568917EBDA0(ped, p1) end

---@param p0 any
---@param p1 any
function PED._0x29F3539189D3E277(p0, p1) end

---@param p0 any
---@param p1 any
function PED._0xE9E06EA514A69061(p0, p1) end

---@param ped integer
---@param writhingDuration1 number
---@param writhingDuration2 number
---@param p3 integer
function PED._SET_PED_WRITHING_DURATION(ped, writhingDuration1, writhingDuration2, p3) end

---@param ped integer
---@param normalized boolean
---@return number
function PED._GET_PED_REMAINING_REVIVAL_TIME(ped, normalized) end

---@param ped integer
---@param toggle boolean
function PED.SET_PAUSE_PED_WRITHE_BLEEDOUT(ped, toggle) end

---@param ped integer
---@return boolean
function PED._0x12EB4E31F092C9B3(ped) end

---@param ped integer
---@return boolean
function PED.GET_PED_IS_GRAPPLING(ped) end

---@param ped integer
---@return boolean
function PED.GET_PED_IS_BEING_GRAPPLED(ped) end

---@param ped integer
---@return integer
function PED._GET_PED_GRAPPLER(ped) end

---@param ped integer
---@return integer
function PED.GET_PED_GRAPPLE_STATE(ped) end

---@param ped integer
---@return integer
function PED._GET_PED_GRAPPLE_STYLE(ped) end

---@param ped integer
---@param style integer
---@return any
function PED._SET_PED_GRAPPLE_STYLE(ped, style) end

---@param ped integer
---@param grappleSequence any
function PED._SET_PED_GRAPPLE_SEQUENCE(ped, grappleSequence) end

---@param ped integer
---@param flag integer
---@param enable boolean
function PED._SET_PED_GRAPPLE_FLAG(ped, flag, enable) end

---@param ped integer
---@param flag integer
function PED._CLEAR_PED_GRAPPLE_FLAG(ped, flag) end

---@param ped integer
---@return integer
function PED._GET_PED_GRAPPLE_FLAG(ped) end

---@param ped integer
---@param grappleAction integer
function PED._SET_PED_GRAPPLE_ACTION(ped, grappleAction) end

---@param ped integer
---@param multiplier number
---@return any
function PED._SET_PED_GRAPPLE_EFFECT_MULTIPLIER(ped, multiplier) end

---@param ped integer
---@param grappleAnim integer
function PED._SET_PED_GRAPPLE_ANIMATION(ped, grappleAnim) end

---@param PedIndex integer
---@param FleeAttribute integer
---@param bActiveSkill boolean
function PED.SET_PED_FLEE_ATTRIBUTES(PedIndex, FleeAttribute, bActiveSkill) end

---@param ped integer
---@return boolean
function PED._IS_PED_COWERING(ped) end

---@param pointX number
---@param pointY number
---@param pointZ number
---@param radius number
---@return boolean
function PED.IS_ANY_PED_NEAR_POINT(pointX, pointY, pointZ, radius) end

---@param PedIndex integer
---@param ForceAIPreCameraUpdate boolean
---@param ForceZeroTimestep boolean
function PED.FORCE_PED_AI_AND_ANIMATION_UPDATE(PedIndex, ForceAIPreCameraUpdate, ForceZeroTimestep) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 boolean
function PED._0xC2722B252C79E641(ped, p1, p2, p3) end

---@param ped integer
---@return boolean
function PED._IS_PED_DOING_SCENARIO_TRANSITION(ped) end

---@param ped integer
---@return boolean
function PED._0x2DC0E8DCBD3546E9(ped) end

---@param ped integer
function PED._ADD_SCENARIO_TRANSITION(ped) end

---@param ped integer
---@param commandHash integer
---@param activationDuration number
function PED._GIVE_PED_HASH_COMMAND(ped, commandHash, activationDuration) end

---@param ped integer
---@param commandHash integer
---@return boolean
function PED._GET_IS_PED_COMMAND_HASH_PRESENT(ped, commandHash) end

---@param iPedIndex integer
---@param vPointX number
---@param vPointY number
---@param vPointZ number
---@param fDegreesDelta number
---@return boolean
function PED.IS_PED_HEADING_TOWARDS_POSITION(iPedIndex, vPointX, vPointY, vPointZ, fDegreesDelta) end

---@param ped integer
function PED._0x600BBDD29820370C(ped) end

---@param ped integer
function PED.REQUEST_PED_VISIBILITY_TRACKING(ped) end

---@param ped integer
function PED.RELEASE_PED_VISIBILITY_TRACKING(ped) end

---@param ped integer
---@param trackvehicle boolean
function PED.REQUEST_PED_VEHICLE_VISIBILITY_TRACKING(ped, trackvehicle) end

---@param ped integer
---@param useSmallBox boolean
function PED.REQUEST_PED_USE_SMALL_BBOX_VISIBILITY_TRACKING(ped, useSmallBox) end

---@param ped integer
---@return integer
function PED.GET_TRACKED_PED_PIXELCOUNT(ped) end

---@param ped integer
---@return boolean
function PED.IS_TRACKED_PED_VISIBLE(ped) end

---@param ped integer
---@param percent number
---@return boolean
function PED._IS_TRACKED_PED_VISIBILITY_PERCENTAGE_NOT_LESS_THAN(ped, percent) end

---@param ped integer
---@return boolean
function PED._IS_PED_VISIBILITY_TRACKED(ped) end

---@param ped integer
---@return boolean
function PED.CAN_PED_BE_MOUNTED(ped) end

---@param ped integer
---@return boolean
function PED._IS_META_PED_FISH(ped) end

---@param ped integer
---@param eventType integer
---@return boolean
function PED.IS_EVENT_IN_QUEUE(ped, eventType) end

---@param ped integer
---@param targetEntity integer
---@param p2 boolean
---@param p3 boolean
---@return integer
function PED.CAN_PED_SEE_ENTITY(ped, targetEntity, p2, p3) end

---@param ped integer
---@param targetPed integer
---@param p2 boolean
---@return integer
function PED.CAN_PED_SEE_PED_CACHED(ped, targetPed, p2) end

---@param ped1 integer
---@param ped2 integer
---@param p2 boolean
---@return number
function PED._0x0EA9EACBA3B01601(ped1, ped2, p2) end

---@param iPedIndex integer
---@param boneTag integer
---@return integer
function PED.GET_PED_BONE_INDEX(iPedIndex, boneTag) end

---@param ped integer
---@param p1 integer
---@return integer
function PED._0xC5303F460A40D21D(ped, p1) end

---@param horse integer
function PED._0xE29D8CD66553DBAA(horse) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function PED._0xB06F5F1DEF417216(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function PED._0xFC23348F0F4E245F(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
function PED._0x9184788BFF1EDAD7(p0, p1) end

---@param ped integer
---@param p1 number
---@param p2 integer
---@param p3 boolean
---@param p4 boolean
function PED._SET_PED_DIRT_CLEANED(ped, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@return any
function PED._0x0105FEE8F9091255(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function PED._0xD049920CD29F6CC8(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@return any
function PED._0xBB3E5370EBB6BE28(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function PED._0x2FA568BFA725F8D6(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@return any
function PED._0x56E4BAD93D33453C(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function PED._0x75A082563B4452E5(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function PED._0x16802C32B2FCA06B(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function PED._0x8BA0C65AC15A7D33(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function PED._0x0FFDF937E5C11382(p0, p1, p2, p3, p4, p5) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function PED._0x5FCF25D584065BFD(p0, p1, p2, p3) end

---@param ped integer
---@param inverted boolean
function PED._0xA2116C1E4ED85C24(ped, inverted) end

---@param PedIndex integer
---@param state integer
---@param shouldRestart boolean
---@param exitstate integer
---@param ForceAIPreCameraUpdate boolean
---@return boolean
function PED.FORCE_PED_MOTION_STATE(PedIndex, state, shouldRestart, exitstate, ForceAIPreCameraUpdate) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0x75D3333409CD33CE(p0, p1, p2) end

---@param PedIndex integer
---@param MbrXOut number
---@param MbrYOut number
---@return boolean
---@return number
---@return number
function PED.GET_PED_CURRENT_MOVE_BLEND_RATIO(PedIndex, MbrXOut, MbrYOut) end

---@param PedIndex integer
---@param MoveBlendRatio number
function PED.SET_PED_MAX_MOVE_BLEND_RATIO(PedIndex, MoveBlendRatio) end

---@param PedIndex integer
---@param MoveBlendRatio number
function PED.SET_PED_MIN_MOVE_BLEND_RATIO(PedIndex, MoveBlendRatio) end

---@param p0 any
function PED._0xBC1DC48270468444(p0) end

---@param ped integer
---@param maxMoveBlendRatio number
---@return number
function PED._0x46BF2A810679D6E6(ped, maxMoveBlendRatio) end

---@param ped integer
---@param p1 number
---@return number
function PED._0xCA95924C893A0C91(ped, p1) end

---@param mount integer
---@param kickOffRider boolean
function PED._HORSE_AGITATE(mount, kickOffRider) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0x413697EC260AABBF(p0, p1, p2) end

---@param ped integer
function PED._0xCAC43D060099EA72(ped) end

---@param ped integer
function PED._0xC9151483CC06A414(ped) end

---@param p0 any
---@param p1 any
function PED._0xAD3330E3C3E98007(p0, p1) end

---@param p0 any
---@return any
function PED._0xB8E2D655E1D5BD39(p0) end

---@param p0 any
---@return any
function PED._0x7BB810E8B343AC7B(p0) end

---@param PedIndex integer
---@param DesiredRate number
function PED.SET_PED_MOVE_RATE_OVERRIDE(PedIndex, DesiredRate) end

---@param PedIndex integer
---@param array integer
---@return integer
---@return integer
function PED.GET_PED_NEARBY_VEHICLES(PedIndex, array) end

---@param PedIndex integer
---@param array integer
---@param ExclusionPedType integer
---@param p3 integer
---@return integer
function PED.GET_PED_NEARBY_PEDS(PedIndex, array, ExclusionPedType, p3) end

---@param ped integer
---@return boolean
function PED.IS_PED_READY_TO_RENDER(ped) end

---@param p0 any
function PED._0x6A489892E813951A(p0) end

---@param PedIndex integer
---@return boolean
function PED.IS_PED_USING_ACTION_MODE(PedIndex) end

---@param ped integer
---@return boolean
function PED._IS_PED_USING_ACTION_MODE_2(ped) end

---@param PedIndex integer
---@param UsingActionMode boolean
---@param ActionModeTime integer
---@param ActionModeName any
function PED.SET_PED_USING_ACTION_MODE(PedIndex, UsingActionMode, ActionModeTime, ActionModeName) end

---@param PedIndex integer
---@param Radius number
function PED.SET_PED_CAPSULE(PedIndex, Radius) end

---@param mount integer
---@param p1 boolean
---@return integer
function PED._GET_RIDER_OF_MOUNT(mount, p1) end

---@param vSearchOriginX number
---@param vSearchOriginY number
---@param vSearchOriginZ number
---@param fSearchRadius number
---@param fMaxDistZ number
---@param iFlags integer
---@param fMinimumSpacing number
---@param iMaxSearchDurationMS integer
---@param p8 number
function PED.SPAWNPOINTS_START_SEARCH(vSearchOriginX, vSearchOriginY, vSearchOriginZ, fSearchRadius, fMaxDistZ, iFlags, fMinimumSpacing, iMaxSearchDurationMS, p8) end

---@param vPoint1X number
---@param vPoint1Y number
---@param vPoint1Z number
---@param vPoint2X number
---@param vPoint2Y number
---@param vPoint2Z number
---@param fWidth number
---@param iFlags integer
---@param fMinimumSpacing number
---@param iMaxSearchDurationMS integer
---@param p10 number
function PED.SPAWNPOINTS_START_SEARCH_IN_ANGLED_AREA(vPoint1X, vPoint1Y, vPoint1Z, vPoint2X, vPoint2Y, vPoint2Z, fWidth, iFlags, fMinimumSpacing, iMaxSearchDurationMS, p10) end

---@param volume integer
---@param spawnpointsFlag integer
---@param p2 number
---@param duration integer
---@param p4 number
function PED._SPAWNPOINTS_START_SEARCH_WITH_VOLUME(volume, spawnpointsFlag, p2, duration, p4) end

function PED.SPAWNPOINTS_CANCEL_SEARCH() end

---@return boolean
function PED.SPAWNPOINTS_IS_SEARCH_ACTIVE() end

---@return boolean
function PED.SPAWNPOINTS_IS_SEARCH_COMPLETE() end

---@return boolean
function PED.SPAWNPOINTS_IS_SEARCH_FAILED() end

---@return integer
function PED.SPAWNPOINTS_GET_NUM_SEARCH_RESULTS() end

---@param iResultIndex integer
---@param fOut_X number
---@param fOut_Y number
---@param fOut_Z number
---@return number
---@return number
---@return number
function PED.SPAWNPOINTS_GET_SEARCH_RESULT(iResultIndex, fOut_X, fOut_Y, fOut_Z) end

---@param iResultIndex integer
---@param iOut_Flags integer
---@return integer
function PED.SPAWNPOINTS_GET_SEARCH_RESULT_FLAGS(iResultIndex, iOut_Flags) end

---@param PedIndex integer
---@param IKPart integer
---@param TargetEntityIndex integer
---@param TargetBone integer
---@param TargetOffsetX number
---@param TargetOffsetY number
---@param TargetOffsetZ number
---@param Flags integer
---@param BlendInTimeMS integer
---@param BlendOutTimeMS integer
function PED.SET_IK_TARGET(PedIndex, IKPart, TargetEntityIndex, TargetBone, TargetOffsetX, TargetOffsetY, TargetOffsetZ, Flags, BlendInTimeMS, BlendOutTimeMS) end

---@param ped integer
---@param name any
function PED._REQUEST_PED_EMOTIONAL_PRESET(ped, name) end

---@param ped integer
---@param name any
---@return boolean
function PED._HAS_PED_EMOTIONAL_PRESET_LOADED(ped, name) end

---@param ped integer
---@param name any
function PED._REMOVE_PED_EMOTIONAL_PRESET(ped, name) end

---@param nameHash integer
---@param ped integer
function PED._REQUEST_MOTION_TYPE_ASSET(nameHash, ped) end

---@param nameHash integer
---@param ped integer
---@return boolean
function PED.HAS_MOTION_TYPE_ASSET_LOADED(nameHash, ped) end

---@param nameHash integer
---@param ped integer
function PED._REMOVE_MOTION_TYPE_ASSET(nameHash, ped) end

---@param ped integer
---@return boolean
function PED._0x290B2E6CCDE532E1(ped) end

---@param ped integer
---@return boolean
function PED._0x0EEF7A81C17679DB(ped) end

---@param PedIndex integer
---@param multiplier number
function PED.SET_PED_LOD_MULTIPLIER(PedIndex, multiplier) end

---@param ped integer
---@return number
function PED._GET_PED_LOD_MULTIPLIER(ped) end

---@param p0 any
---@param p1 any
---@return any
function PED._0xA218D2BBCAA7388C(p0, p1) end

---@param iPedIndex integer
---@param pointX number
---@param pointY number
---@param pointZ number
---@param radius number
---@return boolean
function PED.IS_ANY_HOSTILE_PED_NEAR_POINT(iPedIndex, pointX, pointY, pointZ, radius) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0xCBDE59C48F2B06F5(p0, p1, p2) end

---@param p0 any
function PED._0x6A190B94C2541A99(p0) end

---@param PedIndex integer
---@param TargetPedIndex integer
---@param fFocusAngle number
---@param fFocusDistance number
---@param fPeripheralAngle number
---@param fPeripheralDistance number
---@return boolean
function PED.IS_TARGET_PED_IN_PERCEPTION_AREA(PedIndex, TargetPedIndex, fFocusAngle, fFocusDistance, fPeripheralAngle, fPeripheralDistance) end

---@param centerX number
---@param centerY number
---@param centerZ number
---@param pedRadius number
---@param vehRadius number
function PED.SET_POP_CONTROL_SPHERE_THIS_FRAME(centerX, centerY, centerZ, pedRadius, vehRadius) end

---@param ped integer
---@return boolean
function PED.IS_PED_HOGTIED(ped) end

---@param ped integer
---@return boolean
function PED.IS_PED_BEING_HOGTIED(ped) end

---@param ped integer
---@return integer
function PED._0x3D9F958834AB9C30(ped) end

---@param ped integer
---@return boolean
function PED._0x913D04A5176F84C9(ped) end

---@param ped integer
---@return boolean
function PED.IS_PED_HOGTYING(ped) end

---@param ped integer
---@param flagId integer
---@return boolean
function PED._GET_PED_LASSO_HOGTIE_FLAG(ped, flagId) end

---@param ped integer
---@param flagId integer
---@param value boolean
function PED.SET_PED_LASSO_HOGTIE_FLAG(ped, flagId, value) end

---@param ped integer
---@param p1 integer
---@param p2 integer
---@param p3 integer
---@param p4 integer
---@return integer
function PED._0x4642182A298187D0(ped, p1, p2, p3, p4) end

---@param ped integer
---@param p1 integer
---@param p2 integer
---@param p3 boolean
function PED._0x6B67320E0D57856A(ped, p1, p2, p3) end

---@param ped integer
---@return integer
function PED._GET_FIRST_ENTITY_PED_IS_CARRYING(ped) end

---@param ped integer
---@param p1 integer
function PED._0xAA6C49AE90A32299(ped, p1) end

---@param entity integer
---@return integer
function PED._GET_CARRIER_AS_PED(entity) end

---@param entity integer
---@return integer
function PED._GET_CARRIER_AS_MOUNT(entity) end

---@param entity integer
---@return integer
function PED._GET_CARRIER_AS_HUMAN(entity) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function PED.GET_CARRIED_ATTACHED_INFO_FOR_SLOT(p0, p1, p2, p3) end

---@param entity integer
---@param p1 boolean
---@param p2 boolean
function PED.DETACH_CARRIABLE_ENTITY(entity, p1, p2) end

---@param ped integer
---@param itemset integer
function PED.FIND_ALL_ATTACHED_CARRIABLE_ENTITIES(ped, itemset) end

---@param ped integer
---@return boolean
function PED.IS_PED_CARRYING_SOMETHING(ped) end

---@param ped integer
---@param p1 integer
---@return boolean
function PED._0xB65927F861E7AE39(ped, p1) end

---@param volume integer
---@return boolean
function PED._0xA1FBAC56D38563E2(volume) end

---@param ped integer
---@param p1 integer
---@return any
function PED._0x6F43C351A5D51E2F(ped, p1) end

---@param ped integer
---@return boolean
function PED.IS_PED_LASSOED(ped) end

---@param ped integer
---@return integer
function PED._GET_LASSOER_OF_PED(ped) end

---@param ped integer
---@return integer
function PED._GET_LASSO_TARGET(ped) end

---@param ped integer
---@return integer
function PED._GET_LASSOED_LASSOER(ped) end

---@param ped integer
---@param lootFlag integer
---@param enabled boolean
function PED.SET_LOOTING_FLAG(ped, lootFlag, enabled) end

---@param ped integer
---@param lootFlag integer
---@return boolean
function PED._GET_LOOTING_FLAG(ped, lootFlag) end

---@param ped integer
---@param p1 integer
---@param lootTarget integer
---@param p3 integer
---@param p4 integer
---@return integer
---@return integer
function PED._REFRESH_LOOT_STATE_FOR_PED(ped, p1, lootTarget, p3, p4) end

---@param ped integer
---@return integer
function PED.GET_PED_LOOT_STATUS_MP(ped) end

---@param ped integer
---@return integer
function PED._0x4B19F171450E0D4F(ped) end

---@param ped integer
---@return boolean
function PED._0x758F081DB204DDDE(ped) end

---@param ped integer
---@return integer
function PED.GET_LOOTING_PICKUP_TARGET_ENTITY(ped) end

---@param p0 any
---@return any
function PED._0x7B5C293238EE4F20(p0) end

---@param p0 any
function PED._0xAE6B68A83ABBE7C0(p0) end

---@param ped integer
---@return boolean
function PED._0xA4B6432E3880F2F9(ped) end

---@param ped integer
---@return boolean
function PED._ADD_PED_SUBSCRIBE_TO_LEGENDARY_BLIPS(ped) end

---@param ped integer
---@return boolean
function PED._REMOVE_PED_SUBSCRIBE_TO_LEGENDARY_BLIPS(ped) end

---@param ped integer
---@return boolean
function PED.IS_PED_INCAPACITATED(ped) end

---@param ped integer
---@param canBeIncapacitated boolean
---@param threshold integer
---@param bleedoutTime integer
---@param p4 integer
function PED._SET_PED_INCAPACITATION_MODIFIERS(ped, canBeIncapacitated, threshold, bleedoutTime, p4) end

---@param ped integer
---@return boolean
function PED._GET_PED_CAN_BE_INCAPACITATED_THIS_FRAME(ped) end

---@param ped integer
---@param toggle boolean
function PED.SET_PED_CAN_BE_INCAPACITATED(ped, toggle) end

---@param ped integer
---@return integer
function PED._GET_PED_INCAPACITATION_HEALTH(ped) end

---@param ped integer
---@param duration number
function PED._SET_PED_INCAPACITATION_TOTAL_BLEED_OUT_DURATION(ped, duration) end

---@param ped integer
function PED._RESET_PED_INCAPACITATION_BLEED_OUT_DURATION(ped) end

---@param ped integer
---@param flags integer
function PED._SET_PED_INCAPACITATION_FLAGS(ped, flags) end

---@param p0 any
---@param p1 any
function PED._0x92A1B55A59720395(p0, p1) end

---@param ped integer
---@param ped2 integer
function PED._INCAPACITATED_REVIVE(ped, ped2) end

---@param ped integer
---@return integer
function PED._GET_INCAPACITATION_TIME_REMAINING(ped) end

---@param ped integer
---@param p1 number
function PED._SET_PED_KNOCKED_BY_ONE_HIT(ped, p1) end

---@param ped integer
---@param p1 integer
function PED._0x2E5B5D1F1453E08E(ped, p1) end

---@param ped integer
---@param p1 number
function PED._0x29924EB8EE9DB926(ped, p1) end

---@param ped integer
---@param playerType integer
function PED._SET_PED_ACTIVE_PLAYER_TYPE(ped, playerType) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@return any
function PED._0xCB86D3E3E3708901(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
function PED._0x633F83B301C87994(p0, p1) end

---@param ped integer
---@param p1 integer
---@param p2 integer
---@return boolean
function PED._0x5203038FF8BAE577(ped, p1, p2) end

---@param ped integer
---@param p1 integer
---@return boolean
function PED._0x7F090958AE95B61B(ped, p1) end

---@param ped integer
---@param p1 integer
function PED._0xC494C76A34266E82(ped, p1) end

---@param ped integer
---@param p1 integer
---@param p2 integer
---@return boolean
function PED._0xC3995D396F1D97B6(ped, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0x15F4732C357B1D6D(p0, p1, p2) end

---@param ped integer
---@param player integer
---@param flag integer
---@param ms integer
---@return boolean
function PED._0x947E43F544B6AB34(ped, player, flag, ms) end

---@param p0 any
---@param p1 any
---@return any
function PED._0x32417CB860A3BDC4(p0, p1) end

---@param ped integer
---@param player integer
---@param p2 integer
function PED._0xE737D5F14304A2EC(ped, player, p2) end

---@param p0 any
---@param p1 any
function PED._0xEBD49472BCCF7642(p0, p1) end

---@param ped integer
---@param player integer
---@param duration integer
function PED._SET_PLAYER_GREET_DISABLED_FOR_PED(ped, player, duration) end

---@param ped integer
---@param player integer
---@param duration integer
function PED._SET_PLAYER_ANTAGONIZE_DISABLED_FOR_PED(ped, player, duration) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0xB9BDFAE609DFB7C5(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function PED._0xF7327ACC7A89AEF1(p0, p1, p2) end

---@param ped integer
---@param player integer
---@return integer
function PED._GET_PED_ATTITUDE(ped, player) end

---@param ped integer
---@param p1 integer
---@return boolean
function PED._0x1E017404784AA6A3(ped, p1) end

---@param ped integer
---@param p1 integer
function PED._0x2B4CE170DE09F346(ped, p1) end

---@param p0 any
---@param p1 any
---@return any
function PED._0x7C8AA850617651D9(p0, p1) end

---@param ped integer
---@param motivationState integer
---@param targetPed integer
---@return number
function PED._GET_PED_MOTIVATION(ped, motivationState, targetPed) end

---@param ped integer
---@param motivationState integer
---@param threshold number
---@param targetPed integer
function PED._SET_PED_MOTIVATION(ped, motivationState, threshold, targetPed) end

---@param ped integer
---@param p1 integer
---@param p2 number
---@param p3 any
function PED._0x23BDE06596A22CEC(ped, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function PED._0xCDFB8C04D4C95D9B(p0, p1, p2, p3) end

---@param ped integer
---@param motivationState integer
---@return boolean
function PED._GET_IS_PED_MOTIVATION_STATE_ENABLED(ped, motivationState) end

---@param ped integer
---@param motivationState integer
---@param enabled boolean
function PED._SET_PED_MOTIVATION_STATE_OVERRIDE(ped, motivationState, enabled) end

---@param ped integer
---@param motivationState integer
---@param modifier number
function PED._SET_PED_MOTIVATION_MODIFIER(ped, motivationState, modifier) end

---@param p0 any
---@param p1 any
function PED._0xFD8E853F0BC2E942(p0, p1) end

---@param ped integer
---@param scent number
function PED._SET_PED_SCENT(ped, scent) end

---@param ped integer
---@param p1 number
function PED._SET_PED_LADDER_MOVEMENT_SPEED_MODIFIER(ped, p1) end

---@param ped integer
function PED._RESET_PED_LADDER_MOVEMENT_SPEED_MODIFIER(ped) end

---@param p0 any
---@param p1 any
function PED._0xC6C4E15CF7D52FEA(p0, p1) end

---@param ped integer
---@param volume number
function PED._SET_PED_VOICE_VOLUME(ped, volume) end

---@param p0 any
---@param p1 any
function PED._0x0F967019CC853BCC(p0, p1) end

---@param ped integer
---@return boolean
function PED._IS_PED_DRAGGING(ped) end

---@param ped integer
---@return boolean
function PED.IS_PED_BEING_DRAGGED(ped) end

---@param p0 any
---@param p1 any
function PED._0x070A3841406C43D5(p0, p1) end

---@param ped integer
---@param volume integer
---@return boolean
function PED._ADD_PED_STAY_OUT_VOLUME(ped, volume) end

---@param ped integer
---@param volume integer
---@return boolean
function PED._REMOVE_PED_STAY_OUT_VOLUME(ped, volume) end

---@param p0 any
---@param p1 any
function PED._0x9E66708B2B41F14A(p0, p1) end

---@param ped integer
---@param p1 any
function PED._0xF634E2892220EF34(ped, p1) end

---@param ped integer
---@param targetPed integer
function PED._0xAAC0EE3B4999ABB5(ped, targetPed) end

---@param ped integer
---@return integer
function PED.GET_PED_MOTION_FOCUS_ENTITY(ped) end

---@param ped integer
---@param index integer
---@param value number
function PED._SET_CHAR_EXPRESSION(ped, index, value) end

---@param ped integer
---@param index integer
---@return number
function PED._GET_CHAR_EXPRESSION(ped, index) end

---@param p0 any
---@param p1 any
function PED._0x5BB04BC74A474B47(p0, p1) end

---@param p0 any
function PED._0x9078FB0557364099(p0) end

---@param ped integer
---@return boolean
function PED.IS_PED_FALLING_OVER(ped) end

---@param ped integer
---@param ms integer
---@return boolean
function PED._HAS_PED_BEEN_SHOVED_RECENTLY(ped, ms) end

---@param ped integer
---@return integer
function PED._GET_PED_TRANQUILIZER(ped) end

---@param p0 any
---@param p1 any
function PED._0x0D497AA69059FE40(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0xD7D2F45C56A4F4DF(p0, p1, p2) end

---@param ped integer
---@param p1 number
---@param p2 number
function PED._SET_PED_CULL_RANGE(ped, p1, p2) end

---@param p0 any
---@param p1 any
function PED._0x1D23D3F70606D788(p0, p1) end

---@param ped integer
---@return integer
function PED._GET_META_PED_TYPE(ped) end

---@param ped integer
---@param component integer
---@return boolean
function PED._IS_META_PED_USING_COMPONENT(ped, component) end

---@param ped integer
---@return boolean
function PED._0xBD0E4F52F6D95242(ped) end

---@param ped integer
---@return boolean
function PED._IS_PED_CHILD(ped) end

---@param ped integer
---@param p1 integer
function PED._0xFFA1594703ED27CA(ped, p1) end

---@param ped integer
---@param drawable integer
---@param albedo integer
---@param normal integer
---@param material integer
---@param palette integer
---@param tint0 integer
---@param tint1 integer
---@param tint2 integer
function PED._SET_META_PED_TAG(ped, drawable, albedo, normal, material, palette, tint0, tint1, tint2) end

---@param ped integer
---@param component integer
---@param p2 integer
function PED.REMOVE_TAG_FROM_META_PED(ped, component, p2) end

---@param p0 any
---@param p1 any
function PED._0xA2B8E47442C76CEC(p0, p1) end

---@param ped integer
---@return integer
function PED._GET_NUM_COMPONENT_CATEGORIES_IN_PED(ped) end

---@param ped integer
---@param index integer
---@return integer
function PED._GET_PED_COMPONENT_CATEGORY_BY_INDEX(ped, index) end

---@param ped integer
---@return integer
function PED._GET_NUM_COMPONENTS_IN_PED(ped) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function PED._0x9B90842304C938A7(p0, p1, p2) end

---@param ped integer
---@param p1 boolean
---@param p2 boolean
---@param p3 boolean
---@param p4 boolean
---@param p5 boolean
function PED._UPDATE_PED_VARIATION(ped, p1, p2, p3, p4, p5) end

---@param p0 any
---@param p1 any
function PED._0xCB1A3864C524F784(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function PED._0xFA0D206B489A6846(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function PED._0xA4AC05B1A364EBC5(p0, p1, p2) end

---@param p0 any
function PED._0x1298B3D8E4C2409F(p0) end

---@param p0 any
---@param p1 any
---@return any
function PED._0xA274F51EF7E34B95(p0, p1) end

---@param p0 any
---@return any
function PED._0xC2EF407645BEECDC(p0) end

---@param ped integer
---@param hash integer
function PED._EQUIP_META_PED_OUTFIT(ped, hash) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0xFA742B82D093D848(p0, p1, p2) end

---@param ped integer
---@return integer
function PED._GET_PED_META_OUTFIT_HASH(ped) end

---@param p0 any
---@param p1 any
function PED._0xA2F8B3B5FEDFC100(p0, p1) end

---@param ped integer
---@param suboutfit integer
---@param p2 integer
function PED._EQUIP_META_PED_SUBOUTFIT(ped, suboutfit, p2) end

---@param outfit integer
---@param model integer
---@return boolean
function PED._DOES_META_PED_OUTFIT_EXIST_FOR_PED_MODEL(outfit, model) end

---@param outfit integer
---@param suboutfit integer
---@param model integer
---@return boolean
function PED._DOES_META_PED_SUBOUTFIT_EXIST_FOR_PED_MODEL(outfit, suboutfit, model) end

---@param entity integer
---@param p1 any
---@return any
function PED._0x62FDF4E678E40CC6(entity, p1) end

---@param ped integer
function PED._RESET_PED_COMPONENTS(ped) end

---@param ped integer
---@param p1 boolean
function PED._0x370A973252741AC4(ped, p1) end

---@param ped integer
---@param p1 boolean
function PED._SET_RANDOM_OUTFIT_VARIATION(ped, p1) end

---@param ped integer
---@return integer
function PED.GET_NUM_META_PED_OUTFITS(ped) end

---@param ped integer
---@param presetId integer
---@param p2 boolean
function PED._EQUIP_META_PED_OUTFIT_PRESET(ped, presetId, p2) end

---@param ped integer
---@param component integer
---@param p2 any
---@param p3 any
function PED._EQUIP_META_PED_OUTFIT_EXTRA(ped, component, p2, p3) end

---@param ped integer
---@param outfit integer
---@return boolean
function PED._IS_META_PED_OUTFIT_EQUIPPED(ped, outfit) end

---@param p0 any
---@param p1 any
function PED._0x851966E1E35AF491(p0, p1) end

---@param ped integer
---@param componentCategory integer
---@param palette integer
---@param tint0 integer
---@param tint1 integer
---@param tint2 integer
function PED._SET_TEXTURE_OUTFIT_TINTS(ped, componentCategory, palette, tint0, tint1, tint2) end

---@param model integer
---@param p1 integer
---@return integer
function PED._REQUEST_META_PED(model, p1) end

---@param requestId integer
---@return boolean
function PED._HAS_META_PED_REQUEST_LOADED(requestId) end

---@param requestId integer
---@return boolean
function PED._IS_META_PED_REQUEST_VALID(requestId) end

---@param requestId integer
---@param x number
---@param y number
---@param z number
---@param heading number
---@param p5 boolean
---@param p6 boolean
---@param p7 boolean
---@param p8 boolean
---@param p9 boolean
---@return integer
function PED._CREATE_META_PED(requestId, x, y, z, heading, p5, p6, p7, p8, p9) end

---@param requestId integer
function PED._RELEASE_META_PED_REQUEST(requestId) end

---@param model integer
---@param outfit integer
---@return integer
function PED._REQUEST_META_PED_OUTFIT(model, outfit) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function PED._0x27E8A84C12B0B7D1(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@return any
function PED._0x273915CE30780986(p0, p1) end

---@param requestId integer
function PED._RELEASE_META_PED_OUTFIT_REQUEST(requestId) end

---@param drawable integer
---@param albedo integer
---@param normal integer
---@param material integer
---@param p4 any
---@return integer
function PED._0x3FCBB5FCFD968698(drawable, albedo, normal, material, p4) end

---@param asset integer
---@param p1 integer
---@return integer
function PED._REQUEST_META_PED_ASSET_BUNDLE(asset, p1) end

---@param metaPedType integer
---@param p1 any
---@param p2 integer
---@param p3 integer
---@param p4 integer
---@return any
function PED._REQUEST_META_PED_COMPONENT(metaPedType, p1, p2, p3, p4) end

---@param requestId integer
function PED._RELEASE_META_PED_ASSET_REQUEST(requestId) end

---@param requestId integer
---@return boolean
function PED._HAS_META_PED_ASSET_LOADED(requestId) end

---@param requestId integer
---@return boolean
function PED._IS_META_PED_ASSET_VALID(requestId) end

---@param asset integer
---@param posX number
---@param posY number
---@param posZ number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param p7 boolean
---@param p8 boolean
---@param p9 boolean
---@return integer
function PED._CREATE_META_PED_ASSET(asset, posX, posY, posZ, rotX, rotY, rotZ, p7, p8, p9) end

---@param requestId integer
---@return boolean
function PED._HAS_META_PED_OUTFIT_LOADED(requestId) end

---@param requestId integer
---@return boolean
function PED._IS_META_PED_OUTFIT_REQUEST_VALID(requestId) end

---@param requestId integer
---@param x number
---@param y number
---@param z number
---@param heading number
---@param p5 boolean
---@param p6 boolean
---@param p7 boolean
---@param p8 boolean
---@return integer
function PED._CREATE_META_PED_OUTFIT_PED(requestId, x, y, z, heading, p5, p6, p7, p8) end

---@param requestId integer
---@param ped integer
---@param p2 boolean
---@param p3 boolean
---@return boolean
function PED._APPLY_PED_META_PED_OUTFIT(requestId, ped, p2, p3) end

---@param ped integer
---@param weariness number
function PED._SET_META_PED_WEARINESS(ped, weariness) end

---@param ped integer
---@param danceIntensity integer
function PED._0xF47D54B986F0A346(ped, danceIntensity) end

---@param p0 any
function PED._0x3EFED081B4834BA1(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0x0FB1BA7FF73B41E1(p0, p1, p2) end

---@param p0 any
---@return any
function PED._0xB292203008EBBAAC(p0) end

---@param ped integer
---@return boolean
function PED._0xD4D403EA031F351C(ped) end

---@param horse integer
---@param index integer
---@return integer
function PED._GET_PELT_FROM_HORSE(horse, index) end

---@param horse integer
---@param peltId integer
function PED._SET_PELT_FOR_HORSE(horse, peltId) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function PED._0xC412AA1C73111FE0(p0, p1, p2, p3, p4) end

---@param horse integer
---@param peltId integer
function PED._CLEAR_PELT_FROM_HORSE(horse, peltId) end

---@param ped integer
---@param toggle boolean
function PED._SET_PED_LIGHTS(ped, toggle) end

---@param ped integer
---@param p1 integer
---@param p2 number
function PED._0xD049FDAF089FDDB0(ped, p1, p2) end

---@param ped integer
---@param p1 integer
---@param r number
---@param g number
---@param b number
function PED._0xDD9540E7B1C9714F(ped, p1, r, g, b) end

---@param p0 any
---@param p1 any
function PED._0x55546004A244302A(p0, p1) end

---@param ped integer
---@param multiplier integer
function PED._SET_HEALTH_RECHARGE_MULTIPLIER(ped, multiplier) end

---@param ped integer
---@return number
function PED._GET_HEALTH_RECHARGE_MULTIPLIER(ped) end

---@param ped integer
---@param multiplier integer
function PED._SET_STAMINA_DEPLETION_MULTIPLIER(ped, multiplier) end

---@param ped integer
---@return number
function PED._GET_STAMINA_DEPLETION_MULTIPLIER(ped) end

---@param ped integer
---@param multiplier integer
function PED._SET_STAMINA_RECHARGE_MULTIPLIER(ped, multiplier) end

---@param ped integer
---@return number
function PED._GET_STAMINA_RECHARGE_MULTIPLIER(ped) end

---@param ped integer
---@param amount number
---@return boolean
function PED._CHANGE_PED_STAMINA(ped, amount) end

---@param ped integer
---@return number
function PED._GET_PED_STAMINA(ped) end

---@param ped integer
---@return number
function PED._GET_PED_STAMINA_NORMALIZED(ped) end

---@param ped integer
---@return number
function PED._GET_PED_MAX_STAMINA(ped) end

---@param p0 any
function PED._0x36513AFFC703C60D(p0) end

---@param ped integer
---@param stamina number
function PED._RESTORE_PED_STAMINA(ped, stamina) end

---@param ped integer
---@return integer
function PED._0xFC3B580C4380B5B7(ped) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0xEA8763E505AFD49A(p0, p1, p2) end

---@param p0 any
function PED._0xE4EF4382E22C780C(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0xD61FCF9FCFD515B7(p0, p1, p2) end

---@param p0 any
function PED._0x8D9DB115FBA8E23D(p0) end

---@param ped integer
---@return any
function PED._GET_NUM_RESERVED_HEALTH(ped) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function PED._0xD97BC27AC039F681(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@return any
function PED._0xF6A8C4B4A11AE89C(p0, p1, p2, p3, p4, p5) end

---@param ped integer
---@param p1 any
function PED._0xE4C95E0AE31C6512(ped, p1) end

---@param ped integer
---@return integer
function PED._GET_PED_LAST_DROPPED_HAT(ped) end

---@param ped integer
---@param p1 boolean
function PED._0x5D4CD22A8C82A81A(ped, p1) end

---@param p0 any
---@param p1 any
function PED._0xBF567DF2BEF211A6(p0, p1) end

---@param xPos number
---@param yPos number
---@param zPos number
---@param heading number
---@param radius number
---@param p5 number
---@param p6 number
---@param p7 number
---@param stopAtDestination boolean
---@return integer
function PED._CREATE_GRAVITY_WELL(xPos, yPos, zPos, heading, radius, p5, p6, p7, stopAtDestination) end

---@param handle integer
function PED._REMOVE_GRAVITY_WELL(handle) end

---@param ped integer
---@return boolean
function PED._IS_PED_INTIMIDATED(ped) end

---@param ped integer
---@return boolean
function PED._0x7EE3A8660F38797E(ped) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function PED._0xA180FBD502A03125(p0, p1, p2) end

---@param albedoHash integer
---@param normalHash integer
---@param materialHash integer
---@return integer
function PED._REQUEST_TEXTURE(albedoHash, normalHash, materialHash) end

---@param ped integer
---@param componentHash integer
---@param textureId integer
function PED._APPLY_TEXTURE_ON_PED(ped, componentHash, textureId) end

---@param textureId integer
function PED._RELEASE_TEXTURE(textureId) end

---@param textureId integer
function PED._UPDATE_PED_TEXTURE(textureId) end

---@param textureId integer
function PED._RESET_PED_TEXTURE(textureId) end

---@param textureId integer
---@return boolean
function PED._IS_TEXTURE_VALID(textureId) end

---@param textureId integer
---@param albedoHash integer
---@param normalHash integer
---@param materialHash integer
---@param blendType integer
---@param texAlpha number
---@param sheetGridIndex integer
---@return integer
function PED._ADD_TEXTURE_LAYER(textureId, albedoHash, normalHash, materialHash, blendType, texAlpha, sheetGridIndex) end

---@param textureId integer
---@param overlayId integer
function PED._REMOVE_PED_OVERLAY(textureId, overlayId) end

---@param textureId integer
---@param layerId integer
---@param sheetGridIndex integer
function PED._SET_TEXTURE_LAYER_SHEET_GRID_INDEX(textureId, layerId, sheetGridIndex) end

---@param textureId integer
---@param layerId integer
---@param texAlpha number
function PED._SET_TEXTURE_LAYER_ALPHA(textureId, layerId, texAlpha) end

---@param textureId integer
---@param layerId integer
---@param texRough number
function PED._SET_TEXTURE_LAYER_ROUGHNESS(textureId, layerId, texRough) end

---@param textureId integer
---@param layerId integer
---@param paletteHash integer
function PED._SET_TEXTURE_LAYER_PALLETE(textureId, layerId, paletteHash) end

---@param textureId integer
---@param layerId integer
---@param tint0 integer
---@param tint1 integer
---@param tint2 integer
function PED._SET_TEXTURE_LAYER_TINT(textureId, layerId, tint0, tint1, tint2) end

---@param textureId integer
---@param layerId integer
---@param modTextureHash integer
---@param modAlpha number
---@param modChannel integer
function PED._SET_TEXTURE_LAYER_MOD(textureId, layerId, modTextureHash, modAlpha, modChannel) end

---@param textureId integer
---@param layerId integer
---@param albedoHash integer
---@param normalHash integer
---@param materialHash integer
function PED._SET_TEXTURE_LAYER_TEXTURE_MAP(textureId, layerId, albedoHash, normalHash, materialHash) end

---@param textureId integer
function PED._CLEAR_PED_TEXTURE(textureId) end

---@param ped integer
---@param p1 any
function PED._0xC991EF46FE323867(ped, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0x1F8215D0E446F593(p0, p1, p2) end

---@param ped integer
---@param p1 number
---@return boolean
function PED.IS_LOCATION_SPAWN_SAFE(ped, p1) end

---@param p0 any
---@param p1 any
function PED._0x53BA7D96B9A421D9(p0, p1) end

---@param p0 any
---@param p1 any
function PED._0x96C7B659854DE629(p0, p1) end

---@param horse integer
---@param avoidanceLevel integer
function PED.SET_HORSE_AVOIDANCE_LEVEL(horse, avoidanceLevel) end

---@param horse integer
function PED.RESET_HORSE_AVOIDANCE_LEVEL_TO_DEFAULT(horse) end

---@param ped integer
---@param toggle boolean
---@return any
function PED._SET_PED_USE_HORSE_MAP_COLLISION(ped, toggle) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function PED._0x5B73975B4F12F7F3(p0, p1, p2, p3, p4) end

---@param ped integer
---@param index integer
---@param drawable integer
---@param albedo integer
---@param normal integer
---@param material integer
---@return boolean
---@return integer
---@return integer
---@return integer
---@return integer
function PED.GET_META_PED_ASSET_GUIDS(ped, index, drawable, albedo, normal, material) end

---@param ped integer
---@param index integer
---@param pallete integer
---@param tint0 integer
---@param tint1 integer
---@param tint2 integer
---@return boolean
---@return integer
---@return integer
---@return integer
---@return integer
function PED.GET_META_PED_ASSET_TINT(ped, index, pallete, tint0, tint1, tint2) end

---@param ped integer
---@param variableName any
---@param value integer
---@param removeTimer integer
function PED._SET_PED_BLACKBOARD_INT(ped, variableName, value, removeTimer) end

---@param ped integer
---@param variableName any
---@param value boolean
---@param removeTimer integer
function PED._SET_PED_BLACKBOARD_BOOL(ped, variableName, value, removeTimer) end

---@param ped integer
---@param variableName any
---@param value number
---@param removeTimer integer
function PED._SET_PED_BLACKBOARD_FLOAT(ped, variableName, value, removeTimer) end

---@param ped integer
---@param variableName any
---@param value any
---@param removeTimer integer
function PED._SET_PED_BLACKBOARD_HASH(ped, variableName, value, removeTimer) end

---@param ped integer
---@param variableName any
function PED._REMOVE_PED_BLACKBOARD_INT(ped, variableName) end

---@param ped integer
---@param variableName any
function PED._REMOVE_PED_BLACKBOARD_BOOL(ped, variableName) end

---@param ped integer
---@param variableName any
function PED._REMOVE_PED_BLACKBOARD_FLOAT(ped, variableName) end

---@param ped integer
---@param variableName any
function PED._REMOVE_PED_BLACKBOARD_HASH(ped, variableName) end

---@param ped integer
---@param variableName any
---@return boolean
function PED._GET_PED_BLACKBOARD_BOOL(ped, variableName) end

---@param ped integer
---@param variableName any
---@return number
function PED._GET_PED_BLACKBOARD_FLOAT(ped, variableName) end

---@param ped integer
---@param variableName any
---@return integer
function PED._GET_PED_BLACKBOARD_HASH(ped, variableName) end

---@param ped integer
---@param variableName any
---@return integer
function PED.GET_PED_BLACKBOARD_SCRIPT_INT(ped, variableName) end

---@param ped integer
---@param variableName any
---@return boolean
function PED.GET_PED_BLACKBOARD_SCRIPT_BOOL(ped, variableName) end

---@param ped integer
---@param variableName any
---@return number
function PED.GET_PED_BLACKBOARD_SCRIPT_FLOAT(ped, variableName) end

---@param ped integer
---@param attributeIndex integer
---@param size number
function PED._SET_TANK_ATTRIBUTE_SIZE(ped, attributeIndex, size) end

---@param p0 any
---@return any
function PED._0xA31D350D66FA1855(p0) end

---@param ped integer
---@return boolean
function PED._IS_USING_SLIPSTREAM(ped) end

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
function PED._0xEEDC9B29314B2733(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param p0 any
function PED._0x5C90E20C25E6D83C(p0) end

---@param legendaryPed integer
---@param preyPed integer
---@param p2 number
function PED._0x10F96086123B939F(legendaryPed, preyPed, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0x3FDBB99EFD8CE4AF(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0x7E8F9949B7AABBF0(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function PED._0x5DA36CCCB63C0895(p0, p1, p2) end

---@param p0 any
---@param p1 any
function PED._0x56076667E7C2DCD6(p0, p1) end

---@param ped integer
---@param componentHash integer
---@param immediately boolean
---@param isMp boolean
---@param p4 boolean
function PED._APPLY_SHOP_ITEM_TO_PED(ped, componentHash, immediately, isMp, p4) end

---@param ped integer
---@param componentHash integer
---@param p2 integer
---@param p3 boolean
function PED._REMOVE_SHOP_ITEM_FROM_PED(ped, componentHash, p2, p3) end

---@param ped integer
---@param componentCategory integer
---@param p2 integer
---@param p3 boolean
function PED.REMOVE_SHOP_ITEM_FROM_PED_BY_CATEGORY(ped, componentCategory, p2, p3) end

---@param ped integer
---@param componentHash integer
---@param wearableState integer
---@param p3 integer
---@param p4 boolean
---@param p5 integer
function PED._UPDATE_SHOP_ITEM_WEARABLE_STATE(ped, componentHash, wearableState, p3, p4, p5) end

---@param ped integer
---@param index integer
---@param p2 boolean
---@param argStruct integer
---@param argStruct2 integer
---@return integer
function PED._GET_SHOP_ITEM_COMPONENT_AT_INDEX(ped, index, p2, argStruct, argStruct2) end

---@param componentHash integer
---@param isMpFemale boolean
---@param p2 boolean
---@return integer
function PED._GET_SHOP_ITEM_NUM_WEARABLE_STATES(componentHash, isMpFemale, p2) end

---@param componentHash integer
---@param wearableStateIndex integer
---@param isMpFemale boolean
---@param p3 boolean
---@return integer
function PED._GET_SHOP_ITEM_WEARABLE_STATE_BY_INDEX(componentHash, wearableStateIndex, isMpFemale, p3) end

---@param componentHash integer
---@param metapedType integer
---@param isMP boolean
---@return integer
function PED._GET_SHOP_ITEM_COMPONENT_CATEGORY(componentHash, metapedType, isMP) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function PED._0x31B2E7F2E3C58B89(p0, p1, p2, p3) end

---@param shopItem integer
---@param p1 any
---@param ped integer
---@param metapedType integer
---@param p4 boolean
---@param drawable integer
---@param albedo integer
---@param normal integer
---@param material integer
---@param p9 integer
---@param p10 integer
---@param p11 integer
---@param p12 integer
---@return boolean
---@return integer
---@return integer
---@return integer
---@return integer
---@return integer
---@return integer
---@return integer
---@return integer
function PED._GET_SHOP_ITEM_BASE_LAYERS(shopItem, p1, ped, metapedType, p4, drawable, albedo, normal, material, p9, p10, p11, p12) end

---@param ped integer
---@param isMP boolean
---@return any
function PED._0xAAB86462966168CE(ped, isMP) end

---@param ped integer
---@param metapedType integer
---@param p2 boolean
---@return any
function PED._GET_SHOP_ITEM_HAT_COMPONENT(ped, metapedType, p2) end

---@param ped integer
---@param p1 integer
function PED._REFRESH_META_PED_SHOP_ITEMS(ped, p1) end

---@param ped integer
---@param p1 integer
function PED._0xD103F6DBB5442BE8(ped, p1) end

---@param ped integer
---@param gxtEntryHash integer
function PED._SET_PED_PROMPT_NAME_FROM_GXT_ENTRY(ped, gxtEntryHash) end

---@param ped integer
---@param name any
function PED._SET_PED_PROMPT_NAME(ped, name) end

---@param ped integer
---@param gxtEntryHash integer
function PED._SET_PED_PROMPT_NAME_FROM_GXT_ENTRY_2(ped, gxtEntryHash) end

---@param ped integer
---@param name any
function PED._SET_PED_PROMPT_NAME_2(ped, name) end

---@param p0 any
function PED._0xF917F92BF22ECBAB(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0x49DADFC4CD808B0A(p0, p1, p2) end

---@param ped integer
---@param limb integer
---@return boolean
function PED._HAS_PED_TAKEN_GORE_DAMAGE(ped, limb) end

---@param ped integer
function PED._0x704C908E9C405136(ped) end

---@param p0 any
function PED._0x7406C71F4AC2FFCC(p0) end

---@param p0 any
function PED._0x28508173C6A7CC18(p0) end

---@param p0 any
---@return any
function PED._0x52250B92EA70BE3D(p0) end

---@param ped integer
---@param quality integer
function PED._SET_PED_QUALITY(ped, quality) end

---@param ped integer
---@return integer
function PED._GET_PED_QUALITY(ped) end

---@param ped integer
---@param object integer
---@param propName any
---@param animName any
function PED._0xCE7A6C1D5CDE1F9D(ped, object, propName, animName) end

---@param p0 any
---@param p1 any
---@param p2 any
function PED._0x604E1010E3162E86(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function PED._0xE8ABE3B73FC7FE17(p0, p1, p2, p3) end

---@param ped integer
---@param propName any
function PED._REMOVE_PED_PROP(ped, propName) end

---@param ped integer
---@param bonus number
function PED._SET_TOTAL_PED_DAMAGE_FALLOFF_BONUS(ped, bonus) end

---@param p0 any
---@return any
function PED._0x095C2277FED731DB(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function PED._0x09171A6F8FDE5DC1(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function PED._0x09E378C52B1433B5(p0, p1, p2, p3, p4) end

---@param x number
---@param y number
---@param z number
---@param p3 number
---@return boolean
function PED._0x6507AC3BD7C99009(x, y, z, p3) end

---@param ped integer
---@return number
function PED._GET_PLAYER_PED_WATER_DEPTH(ped) end

---@param ped integer
---@param p1 boolean
---@param duration number
function PED._SET_PED_TRAIL_EFFECT(ped, p1, duration) end

---@param ped integer
---@return boolean
function PED._0xEBAAC9A750E7563B(ped) end

---@param p0 any
---@param p1 any
function PED._0x992187D975635DF5(p0, p1) end

---@param p0 any
---@param p1 any
function PED._0x0B787A37EEDD226F(p0, p1) end
