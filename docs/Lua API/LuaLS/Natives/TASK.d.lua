---@meta

---@class TASK
TASK = {}

---@param PedIndex integer
---@param Time integer
function TASK.TASK_PAUSE(PedIndex, Time) end

---@param PedIndex integer
---@param Time integer
function TASK.TASK_STAND_STILL(PedIndex, Time) end

---@param PedIndex integer
---@param unused boolean
function TASK.TASK_JUMP(PedIndex, unused) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param entity integer
function TASK._TASK_JUMP_2(ped, x, y, z, entity) end

---@param PedIndex integer
---@param Time integer
---@param pedToCowerFrom integer
---@param p3 any
function TASK.TASK_COWER(PedIndex, Time, pedToCowerFrom, p3) end

---@param PedIndex integer
---@param Time integer
---@param PedToFaceIndex integer
---@param TimeToFacePed integer
---@param Flags integer
function TASK.TASK_HANDS_UP(PedIndex, Time, PedToFaceIndex, TimeToFacePed, Flags) end

---@param ped integer
---@param p1 number
---@param permanently boolean
function TASK.TASK_KNOCKED_OUT(ped, p1, permanently) end

---@param ped integer
---@param p1 number
---@param p2 integer
function TASK.TASK_KNOCKED_OUT_AND_HOGTIED(ped, p1, p2) end

---@param ped integer
---@param p1 number
function TASK._0xFFB520A3E16F7B7B(ped, p1) end

---@param ped integer
---@param p1 number
function TASK._0x8B1FDF63C3193EDA(ped, p1) end

---@param PedIndex integer
---@param Time integer
function TASK.UPDATE_TASK_HANDS_UP_DURATION(PedIndex, Time) end

---@param ped integer
---@param p1 integer
function TASK._0x28EF780BDEA8A639(ped, p1) end

---@param ped integer
---@param p1 integer
function TASK.TASK_DUCK(ped, p1) end

---@param ped integer
---@param vehicle integer
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function TASK._TASK_BOARD_VEHICLE(ped, vehicle, p2, p3, p4, p5) end

---@param p0 any
---@param vehicle integer
---@param p2 integer
---@param p3 any
---@param p4 number
---@param p5 any
function TASK._TASK_DISEMBARK_VEHICLE(p0, vehicle, p2, p3, p4, p5) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 number
---@param flags integer
function TASK._TASK_BOARD_VEHICLE_2(ped, p1, p2, p3, flags) end

---@param ped integer
---@param p1 number
---@param flags integer
function TASK.TASK_DISEMBARK_NEAREST_TRAIN_CARRIAGE(ped, p1, flags) end

---@param PedIndex integer
---@param VehicleIndex integer
---@param Time integer
---@param seat integer
---@param MoveBlendRatio number
---@param iFlags integer
---@param OverridenClipSet any
function TASK.TASK_ENTER_VEHICLE(PedIndex, VehicleIndex, Time, seat, MoveBlendRatio, iFlags, OverridenClipSet) end

---@param PedIndex integer
---@param VehicleIndex integer
---@param iFlags integer
---@param unkPed integer
function TASK.TASK_LEAVE_VEHICLE(PedIndex, VehicleIndex, iFlags, unkPed) end

---@param ped integer
---@param mount integer
---@param timer integer
---@param seatIndex integer
---@param pedSpeed number
---@param mountStyle integer
---@param p6 any
---@param p7 any
function TASK.TASK_MOUNT_ANIMAL(ped, mount, timer, seatIndex, pedSpeed, mountStyle, p6, p7) end

---@param rider integer
---@param taskFlag integer
---@param p2 any
---@param p3 any
---@param p4 any
---@param targetPed integer
function TASK.TASK_DISMOUNT_ANIMAL(rider, taskFlag, p2, p3, p4, targetPed) end

---@param ped integer
---@param scenarioPoint integer
---@param flag integer
function TASK.TASK_HITCH_ANIMAL(ped, scenarioPoint, flag) end

---@param p0 any
function TASK._0xE05A5D39BE6E93AF(p0) end

---@param PedIndex integer
---@param VehicleIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param Speed number
---@param Style integer
---@param CarModel integer
---@param Mode integer
---@param TargetRadius number
---@param StraightLineDist number
function TASK.TASK_VEHICLE_DRIVE_TO_COORD(PedIndex, VehicleIndex, VecCoorsX, VecCoorsY, VecCoorsZ, Speed, Style, CarModel, Mode, TargetRadius, StraightLineDist) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
function TASK._TASK_VEHICLE_DRIVE_TO_COORD_2(ped, p1, p2, p3, p4, p5, p6, p7, p8) end

---@param PedIndex integer
---@param VehicleIndex integer
---@param CruiseSpeed number
---@param Mode integer
function TASK.TASK_VEHICLE_DRIVE_WANDER(PedIndex, VehicleIndex, CruiseSpeed, Mode) end

---@param PedIndex integer
---@param EntityIndex integer
---@param VecOffsetX number
---@param VecOffsetY number
---@param VecOffsetZ number
---@param MoveBlendRatio number
---@param Time integer
---@param Radius number
---@param persistFollowing boolean
---@param p9 boolean
---@param walkOnly boolean
---@param p11 boolean
---@param p12 boolean
---@param p13 boolean
function TASK.TASK_FOLLOW_TO_OFFSET_OF_ENTITY(PedIndex, EntityIndex, VecOffsetX, VecOffsetY, VecOffsetZ, MoveBlendRatio, Time, Radius, persistFollowing, p9, walkOnly, p11, p12, p13) end

---@param ped integer
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
function TASK.TASK_FOLLOW_TO_OFFSET_OF_COORD(ped, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
function TASK._0x3FFCD7BBA074CC80(ped, p1, p2, p3, p4, p5, p6, p7, p8) end

---@param PedIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param MoveBlendRatio number
---@param Time integer
---@param FinalHeading number
---@param TargetRadius number
---@param p8 integer
function TASK.TASK_GO_STRAIGHT_TO_COORD(PedIndex, VecCoorsX, VecCoorsY, VecCoorsZ, MoveBlendRatio, Time, FinalHeading, TargetRadius, p8) end

---@param PedIndex integer
---@param EntityIndex integer
---@param VecOffsetX number
---@param VecOffsetY number
---@param VecOffsetZ number
---@param MoveBlendRatio number
---@param Time integer
---@param p7 any
function TASK.TASK_GO_STRAIGHT_TO_COORD_RELATIVE_TO_ENTITY(PedIndex, EntityIndex, VecOffsetX, VecOffsetY, VecOffsetZ, MoveBlendRatio, Time, p7) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
function TASK.TASK_MOVE_IN_TRAFFIC(ped, p1, p2, p3) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
function TASK.TASK_MOVE_IN_TRAFFIC_TO_DESTINATION(ped, p1, p2, p3, p4, p5, p6, p7) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function TASK.TASK_MOVE_IN_TRAFFIC_AWAY_FROM_ENTITY(ped, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
function TASK._0xBAAB791AA72C2821(p0, p1) end

---@param ped integer
---@param moveBlendRatio number
---@param x number
---@param y number
---@param z number
---@param p5 any
function TASK.TASK_MOVE_FOLLOW_ROAD_USING_NAVMESH(ped, moveBlendRatio, x, y, z, p5) end

---@param PedIndex integer
---@param heading number
---@param Time integer
function TASK.TASK_ACHIEVE_HEADING(PedIndex, heading, Time) end

function TASK.TASK_FLUSH_ROUTE() end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
function TASK.TASK_EXTEND_ROUTE(VecCoorsX, VecCoorsY, VecCoorsZ) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function TASK.TASK_FOLLOW_POINT_ROUTE(ped, p1, p2, p3, p4, p5) end

---@param ped integer
---@param animScene integer
---@param entityName any
---@param playbackListName any
---@param enterSpeed number
---@param bAutoStart boolean
---@param flag integer
---@param p7 integer
---@param p8 number
function TASK.TASK_ENTER_ANIM_SCENE(ped, animScene, entityName, playbackListName, enterSpeed, bAutoStart, flag, p7, p8) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function TASK.TASK_MOVE_BE_IN_FORMATION(ped, p1, p2, p3, p4, p5, p6) end

---@param PedIndex integer
---@param EntityIndex integer
---@param Time integer
---@param SeekRadius number
---@param MoveBlendRatio number
---@param SlowDownDistance number
---@param GotoFlags integer
function TASK.TASK_GO_TO_ENTITY(PedIndex, EntityIndex, Time, SeekRadius, MoveBlendRatio, SlowDownDistance, GotoFlags) end

---@param ped integer
---@param targetPed integer
---@param p2 any
---@param p3 any
---@param p4 number
---@param p5 number
---@param p6 integer
---@param p7 any
---@param p8 any
---@param p9 number
---@param p10 number
function TASK.TASK_FOLLOW_AND_CONVERSE_WITH_PED(ped, targetPed, p2, p3, p4, p5, p6, p7, p8, p9, p10) end

---@param p0 any
---@param p1 any
function TASK._0xA052608A12559BBB(p0, p1) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
function TASK.TASK_WANDER_AND_CONVERSE_WITH_PED(ped, p1, p2, p3) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
function TASK.TASK_LEAD_AND_CONVERSE(ped, p1, p2, p3, p4, p5, p6, p7, p8) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function TASK._0xDE0C8B145EA466FF(p0, p1, p2, p3, p4, p5) end

---@param ped integer
---@param entity integer
---@param p2 number
---@param p3 number
---@param p4 number
function TASK.TASK_SEEK_CLEAR_LOS_TO_ENTITY(ped, entity, p2, p3, p4) end

---@param ped integer
---@param p1 integer
---@param whistleType integer
function TASK.TASK_GO_TO_WHISTLE(ped, p1, whistleType) end

---@param p0 any
---@return any
function TASK._0xEB67D4E056C85A81(p0) end

---@param p0 any
---@return any
function TASK._0x78D8C1D4EB80C588(p0) end

---@param ped integer
---@param horse integer
function TASK.TASK_LEAD_HORSE(ped, horse) end

---@param ped integer
function TASK.TASK_STOP_LEADING_HORSE(ped) end

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
function TASK._TASK_FLEE_FROM_COORD(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11) end

---@param ped integer
---@param fleeFromTarget integer
---@param x number
---@param y number
---@param z number
---@param distance number
---@param p6 integer
---@param p7 integer
---@param p8 number
---@param targetPed integer
function TASK._TASK_FLEE_FROM_PED(ped, fleeFromTarget, x, y, z, distance, p6, p7, p8, targetPed) end

---@param PedIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param SafeDistance number
---@param FleeTime integer
---@param fleeType integer
---@param fleeSpeed number
function TASK.TASK_SMART_FLEE_COORD(PedIndex, VecCoorsX, VecCoorsY, VecCoorsZ, SafeDistance, FleeTime, fleeType, fleeSpeed) end

---@param PedIndex integer
---@param OtherPedIndex integer
---@param SafeDistance number
---@param FleeTime integer
---@param fleeType integer
---@param fleeSpeed number
---@param targetPed integer
function TASK.TASK_SMART_FLEE_PED(PedIndex, OtherPedIndex, SafeDistance, FleeTime, fleeType, fleeSpeed, targetPed) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function TASK._0x673A8779D229BA5A(p0, p1, p2, p3, p4, p5) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TASK._0x2E1D6D87346BB7D2(p0, p1, p2, p3) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param fleeStyle integer
---@param p5 integer
---@param p6 number
---@param duration integer
---@param p8 integer
function TASK.TASK_FLEE_COORD(ped, x, y, z, fleeStyle, p5, p6, duration, p8) end

---@param ped integer
---@param fleeFromTarget integer
---@param fleeStyle integer
---@param flag integer
---@param p4 number
---@param p5 integer
---@param p6 integer
function TASK.TASK_FLEE_PED(ped, fleeFromTarget, fleeStyle, flag, p4, p5, p6) end

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
function TASK.TASK_FLEE_COORD_VIA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11) end

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
function TASK.TASK_FLEE_PED_VIA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param p4 number
function TASK._ADD_FLEE_TARGET_COORDS(ped, x, y, z, p4) end

---@param ped integer
---@param targetPed integer
---@param p2 number
function TASK.ADD_FLEE_TARGET_PED(ped, targetPed, p2) end

---@param p0 any
function TASK._0xA42DC7919159CCCF(p0) end

---@param ped integer
---@param fleeFromTarget integer
function TASK.TASK_FLY_AWAY(ped, fleeFromTarget) end

---@param ped integer
---@param travelMbr number
---@param x number
---@param y number
---@param z number
---@param p5 boolean
---@param p6 boolean
function TASK.TASK_FLY_TO_COORD(ped, travelMbr, x, y, z, p5, p6) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function TASK.TASK_FLYING_CIRCLE(ped, p1, p2, p3, p4, p5, p6) end

---@param ped integer
---@param entity integer
function TASK.TASK_WALK_AWAY(ped, entity) end

---@param PedIndex integer
---@param shockingEventId integer
---@param p2 any
function TASK.TASK_SHOCKING_EVENT_REACT(PedIndex, shockingEventId, p2) end

---@param ped integer
---@param reactingTo integer
---@param x number
---@param y number
---@param z number
---@param reactionName any
---@param p6 number
---@param p7 number
---@param p8 integer
function TASK.TASK_REACT(ped, reactingTo, x, y, z, reactionName, p6, p7, p8) end

---@param PedIndex integer
---@param VecCenterX number
---@param VecCenterY number
---@param VecCenterZ number
---@param Radius number
---@param MinWaitTime number
---@param MaxWaitTime number
---@param p7 integer
function TASK.TASK_WANDER_IN_AREA(PedIndex, VecCenterX, VecCenterY, VecCenterZ, Radius, MinWaitTime, MaxWaitTime, p7) end

---@param ped integer
---@param volume integer
---@param p2 number
---@param p3 number
---@param p4 integer
function TASK.TASK_WANDER_IN_VOLUME(ped, volume, p2, p3, p4) end

---@param PedIndex integer
---@param Heading number
---@param WanderFlags integer
function TASK.TASK_WANDER_STANDARD(PedIndex, Heading, WanderFlags) end

---@param ped integer
---@param p1 any
function TASK.TASK_WANDER_SWIM(ped, p1) end

---@param PedIndex integer
---@param vTargetPositionX number
---@param vTargetPositionY number
---@param vTargetPositionZ number
---@param fTargetHeading number
function TASK.TASK_PLANT_BOMB(PedIndex, vTargetPositionX, vTargetPositionY, vTargetPositionZ, fTargetHeading) end

---@param ped integer
---@param action integer
---@param targetPed integer
---@param p3 any
function TASK.TASK_HORSE_ACTION(ped, action, targetPed, p3) end

---@param ped integer
---@param targetPed integer
---@param interactionType integer
---@param interactionModel integer
---@param skipIdleAnimationClip boolean
function TASK.TASK_ANIMAL_INTERACTION(ped, targetPed, interactionType, interactionModel, skipIdleAnimationClip) end

---@param ped integer
---@param p1 any
---@param p2 any
function TASK.TASK_COMBAT_ANIMAL_WARN(ped, p1, p2) end

---@param ped integer
---@param targetPed integer
---@param p2 boolean
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function TASK.TASK_COMBAT_ANIMAL_CHARGE_PED(ped, targetPed, p2, p3, p4, p5, p6) end

---@param p0 any
---@return any
function TASK._0x76610D12A838EBDE(p0) end

---@param ped integer
---@param p1 any
---@param p2 any
function TASK.TASK_AMBIENT_ANIMAL_STALK(ped, p1, p2) end

---@param ped integer
---@param p1 any
---@param p2 any
function TASK.TASK_AMBIENT_ANIMAL_HUNT(ped, p1, p2) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function TASK.TASK_ANIMAL_UNALERTED(ped, p1, p2, p3, p4) end

---@param ped integer
---@param p1 any
---@param p2 any
function TASK.TASK_ANIMAL_ALERTED(ped, p1, p2) end

---@param ped integer
---@param targetPed integer
---@param p2 any
function TASK.TASK_ANIMAL_FLEE(ped, targetPed, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function TASK._0x244430C13BA5258E(p0, p1, p2, p3) end

---@param ped integer
---@param p1 any
---@param p2 any
function TASK.TASK_EAT(ped, p1, p2) end

---@param ped integer
---@param barkAtTarget integer
---@param mood integer
function TASK.TASK_BARK(ped, barkAtTarget, mood) end

---@param ped integer
---@param args integer
function TASK.TASK_FOLLOW_PAVEMENT_TO_COORD(ped, args) end

---@param PedIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param MoveBlendRatio number
---@param Time integer
---@param Radius number
---@param NavFlags integer
---@param FinalHeading number
function TASK.TASK_FOLLOW_NAV_MESH_TO_COORD(PedIndex, VecCoorsX, VecCoorsY, VecCoorsZ, MoveBlendRatio, Time, Radius, NavFlags, FinalHeading) end

---@param PedIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param MoveBlendRatio number
---@param Time integer
---@param Radius number
---@param iNavFlags integer
---@param m_fSlideToCoordHeading number
---@param m_fMaxSlopeNavigable number
---@param m_fClampMaxSearchDistance number
---@param entity integer
---@param FinalHeading number
function TASK.TASK_FOLLOW_NAV_MESH_TO_COORD_ADVANCED(PedIndex, VecCoorsX, VecCoorsY, VecCoorsZ, MoveBlendRatio, Time, Radius, iNavFlags, m_fSlideToCoordHeading, m_fMaxSlopeNavigable, m_fClampMaxSearchDistance, entity, FinalHeading) end

---@param PedIndex integer
---@param bUseClimbovers boolean
function TASK.SET_PED_PATH_CAN_USE_CLIMBOVERS(PedIndex, bUseClimbovers) end

---@param PedIndex integer
---@param bUseLadders boolean
function TASK.SET_PED_PATH_CAN_USE_LADDERS(PedIndex, bUseLadders) end

---@param PedIndex integer
---@param bDrop boolean
function TASK.SET_PED_PATH_CAN_DROP_FROM_HEIGHT(PedIndex, bDrop) end

---@param p0 any
---@return any
function TASK._0xE6A151364C600B24(p0) end

---@param p0 any
---@param p1 any
function TASK._0x1632EB9386CDBE64(p0, p1) end

---@param PedIndex integer
---@param fClimbModifier number
function TASK.SET_PED_PATH_CLIMB_COST_MODIFIER(PedIndex, fClimbModifier) end

---@param ped integer
---@param modifier number
function TASK.SET_PED_PATH_DEEP_SNOW_COST_MODIFIER(ped, modifier) end

---@param ped integer
---@param modifier number
function TASK.SET_PED_PATH_FOLIAGE_COST_MODIFIER(ped, modifier) end

---@param p0 any
---@param p1 any
function TASK._0x8798CF6815B8FE0F(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x5B68D0007D9C92EB(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x82ED59F095056550(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0xE01C8DC8EDD28D31(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x098CAA6DBE7D8D82(p0, p1) end

---@param ped integer
---@return boolean
function TASK._GET_PED_IS_IGNORING_DEAD_BODIES(ped) end

---@param ped integer
---@param toggle boolean
function TASK._SET_PED_IGNORE_DEAD_BODIES(ped, toggle) end

---@param ped integer
---@param modifier number
function TASK._SET_PED_PATH_LADDER_COST_MODIFIER(ped, modifier) end

---@param PedIndex integer
---@param bMayEnter boolean
function TASK.SET_PED_PATH_MAY_ENTER_WATER(PedIndex, bMayEnter) end

---@param ped integer
---@param mayEnterDeepWater boolean
function TASK._SET_PED_PATH_MAY_ENTER_DEEP_WATER(ped, mayEnterDeepWater) end

---@param p0 any
---@param p1 any
---@param p2 any
function TASK._0xC6170856E54557B2(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
function TASK._0xF948F4356F010F11(p0, p1, p2) end

---@param PedIndex integer
---@param bPreferToAvoid boolean
---@param p2 number
function TASK.SET_PED_PATH_PREFER_TO_AVOID_WATER(PedIndex, bPreferToAvoid, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
function TASK._0x8BB283A7888AD1AD(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
function TASK._0x12990818C1D35886(p0, p1, p2) end

---@param p0 any
---@param p1 any
function TASK._0x7C015D8BCEC72CF4(p0, p1) end

---@param PedIndex integer
---@param bAvoid boolean
function TASK.SET_PED_PATH_AVOID_FIRE(PedIndex, bAvoid) end

---@param p0 any
---@param p1 any
function TASK._0x42CFD8FD8CC8DC69(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function TASK._0x216343750545A486(p0, p1, p2) end

---@param p0 any
---@param p1 any
function TASK._0x06ECF3925BC2ABAE(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0xFA30E2254461ADEB(p0, p1) end

---@param PedIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param MoveBlendRatio number
---@param VehicleIndex integer
---@param p6 boolean
---@param DrivingFlags integer
---@param MaxRangeToShootTargets number
function TASK.TASK_GO_TO_COORD_ANY_MEANS(PedIndex, VecCoorsX, VecCoorsY, VecCoorsZ, MoveBlendRatio, VehicleIndex, p6, DrivingFlags, MaxRangeToShootTargets) end

---@param PedIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param MoveBlendRatio number
---@param VehicleIndex integer
---@param p6 boolean
---@param DrivingFlags integer
---@param MaxRangeToShootTargets number
---@param fExtraVehToTargetDistToPreferVeh number
---@param fDriveStraightLineDistance number
---@param iExtraFlags integer
---@param fWarpTimerMS number
function TASK.TASK_GO_TO_COORD_ANY_MEANS_EXTRA_PARAMS(PedIndex, VecCoorsX, VecCoorsY, VecCoorsZ, MoveBlendRatio, VehicleIndex, p6, DrivingFlags, MaxRangeToShootTargets, fExtraVehToTargetDistToPreferVeh, fDriveStraightLineDistance, iExtraFlags, fWarpTimerMS) end

---@param PedIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param MoveBlendRatio number
---@param VehicleIndex integer
---@param p6 boolean
---@param DrivingFlags integer
---@param MaxRangeToShootTargets number
---@param fExtraVehToTargetDistToPreferVeh number
---@param fDriveStraightLineDistance number
---@param iExtraFlags integer
---@param fCruiseSpeed number
---@param fTargetArriveDist number
---@param p14 any
function TASK.TASK_GO_TO_COORD_ANY_MEANS_EXTRA_PARAMS_WITH_CRUISE_SPEED(PedIndex, VecCoorsX, VecCoorsY, VecCoorsZ, MoveBlendRatio, VehicleIndex, p6, DrivingFlags, MaxRangeToShootTargets, fExtraVehToTargetDistToPreferVeh, fDriveStraightLineDistance, iExtraFlags, fCruiseSpeed, fTargetArriveDist, p14) end

---@param PedIndex integer
---@param pAnimDictName any
---@param pAnimName any
---@param fBlendInDelta number
---@param fBlendOutDelta number
---@param nTimeToPlay integer
---@param AnimFlags integer
---@param startPhase number
---@param phaseControlled boolean
---@param ikFlags integer
---@param bAllowOverrideCloneUpdate boolean
---@param taskFilter any
---@param p12 boolean
function TASK.TASK_PLAY_ANIM(PedIndex, pAnimDictName, pAnimName, fBlendInDelta, fBlendOutDelta, nTimeToPlay, AnimFlags, startPhase, phaseControlled, ikFlags, bAllowOverrideCloneUpdate, taskFilter, p12) end

---@param PedIndex integer
---@param pAnimDictName any
---@param pAnimName any
---@param posX number
---@param posY number
---@param posZ number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param fBlendInDelta number
---@param fBlendOutDelta number
---@param nTimeToPlay integer
---@param AnimFlags integer
---@param startPhase number
---@param RotOrder integer
---@param p15 integer
---@param p16 boolean
function TASK.TASK_PLAY_ANIM_ADVANCED(PedIndex, pAnimDictName, pAnimName, posX, posY, posZ, rotX, rotY, rotZ, fBlendInDelta, fBlendOutDelta, nTimeToPlay, AnimFlags, startPhase, RotOrder, p15, p16) end

---@param ped integer
---@param animDict any
---@param animName any
---@param entity integer
---@param p4 integer
---@param p5 number
---@param p6 number
---@param p7 integer
---@param p8 number
---@param p9 boolean
---@param p10 boolean
---@param p11 number
---@param p12 any
---@param p13 integer
---@param p14 number
function TASK.TASK_PLAY_UPPER_ANIM_FACING_ENTITY(ped, animDict, animName, entity, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14) end

---@param EntityIndex integer
---@param pAnimDictName any
---@param pAnimName any
---@param fBlendOutDelta number
function TASK.STOP_ANIM_TASK(EntityIndex, pAnimDictName, pAnimName, fBlendOutDelta) end

---@param PedIndex integer
---@param args integer
function TASK.TASK_SCRIPTED_ANIMATION(PedIndex, args) end

---@param EntityIndex integer
---@param args integer
function TASK.PLAY_ENTITY_SCRIPTED_ANIM(EntityIndex, args) end

---@param EntityIndex integer
---@param priority integer
---@param secondary boolean
function TASK.STOP_ANIM_PLAYBACK(EntityIndex, priority, secondary) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TASK.SET_ANIM_FILTER(p0, p1, p2, p3) end

---@param EntityIndex integer
---@param rate number
---@param priority integer
---@param secondary boolean
function TASK.SET_ANIM_RATE(EntityIndex, rate, priority, secondary) end

---@param ped integer
---@param itemHash integer
---@param interactionAnimHash integer
---@param p3 integer
---@return boolean
function TASK.CAN_START_ITEM_INTERACTION(ped, itemHash, interactionAnimHash, p3) end

---@param ped integer
---@param itemHash integer
---@param interactionAnimHash integer
---@param p3 integer
---@param flag integer
---@param p5 number
function TASK.START_TASK_ITEM_INTERACTION(ped, itemHash, interactionAnimHash, p3, flag, p5) end

---@param ped integer
---@param propNameGxt integer
---@param prop integer
---@param propId integer
---@param itemInteractionState integer
---@param p5 integer
---@param p6 any
---@param p7 number
function TASK._TASK_ITEM_INTERACTION_2(ped, propNameGxt, prop, propId, itemInteractionState, p5, p6, p7) end

---@param ped integer
---@param item integer
---@param guid integer
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 number
function TASK._TASK_ITEM_INTERACTION_3(ped, item, guid, p3, p4, p5, p6) end

---@param ped integer
---@param item integer
---@param p2 number
function TASK._0xB35370D5353995CB(ped, item, p2) end

---@param ped integer
---@return integer
function TASK.GET_ITEM_INTERACTION_STATE(ped) end

---@param ped integer
---@return integer
function TASK.GET_ITEM_INTERACTION_ITEM_ID(ped) end

---@param ped integer
---@return boolean
function TASK.IS_PED_RUNNING_INSPECTION_TASK(ped) end

---@param ped integer
---@return boolean
function TASK.IS_PED_RUNNING_TASK_ITEM_INTERACTION(ped) end

---@param ped integer
---@param item integer
---@return integer
function TASK._GET_ITEM_INTERACTION_ENTITY_FROM_PED(ped, item) end

---@param ped integer
---@param inputContext integer
---@return number
function TASK.GET_ITEM_INTERACTION_PROMPT_PROGRESS(ped, inputContext) end

---@param ped integer
---@param p1 boolean
---@return integer
function TASK._0x678D3226CF70B9C8(ped, p1) end

---@param ped1 integer
---@param ped2 integer
---@param p2 integer
function TASK.TASK_EVASIVE_ANIM(ped1, ped2, p2) end

---@param PedIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param time integer
---@param LookFlags integer
---@param p6 integer
---@param p7 boolean
function TASK.TASK_LOOK_AT_COORD(PedIndex, VecCoorsX, VecCoorsY, VecCoorsZ, time, LookFlags, p6, p7) end

---@param PedIndex integer
---@param EntityIndex integer
---@param time integer
---@param p3 integer
---@param p4 integer
---@param p5 integer
function TASK.TASK_LOOK_AT_ENTITY(PedIndex, EntityIndex, time, p3, p4, p5) end

---@param PedIndex integer
function TASK.TASK_CLEAR_LOOK_AT(PedIndex) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param p4 number
---@return boolean
function TASK._0x508F5053E3F6F0C4(ped, x, y, z, p4) end

---@param p0 any
---@param p1 any
function TASK._0x23767D80C7EED7C6(p0, p1) end

---@param Sequence integer
---@return integer
function TASK.OPEN_SEQUENCE_TASK(Sequence) end

---@param Sequence integer
function TASK.CLOSE_SEQUENCE_TASK(Sequence) end

---@param PedIndex integer
---@param Sequence integer
function TASK.TASK_PERFORM_SEQUENCE(PedIndex, Sequence) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TASK._TASK_PERFORM_SEQUENCE_2(p0, p1, p2, p3) end

---@param Sequence integer
---@return integer
function TASK.CLEAR_SEQUENCE_TASK(Sequence) end

---@param Sequence integer
---@param DoRepeat integer
function TASK.SET_SEQUENCE_TO_REPEAT(Sequence, DoRepeat) end

---@param PedIndex integer
---@return integer
function TASK.GET_SEQUENCE_PROGRESS(PedIndex) end

---@param PedIndex integer
---@param TaskID integer
---@return boolean
function TASK.GET_IS_TASK_ACTIVE(PedIndex, TaskID) end

---@param PedIndex integer
---@param TaskName integer
---@param p2 boolean
---@return integer
function TASK.GET_SCRIPT_TASK_STATUS(PedIndex, TaskName, p2) end

---@param p0 any
---@return any
function TASK._0x9FF5F9B24E870748(p0) end

---@param ped integer
---@param task integer
---@return number
function TASK._GET_SCRIPT_TASK_ACTION_TIME(ped, task) end

---@param ped integer
---@param targetPed integer
---@param lookIntensity integer
---@param exitAnimation integer
---@param duration number
---@param p5 integer
---@param targetPed2 integer
---@param p7 any
---@param p8 any
function TASK.REACT_LOOK_AT(ped, targetPed, lookIntensity, exitAnimation, duration, p5, targetPed2, p7, p8) end

---@param ped integer
---@param exitAnimation integer
---@param p2 boolean
function TASK.REACT_LOOK_AT_END(ped, exitAnimation, p2) end

---@param ped integer
---@param p1 boolean
---@return boolean
function TASK.IS_PED_SCENARIO_REACT_LOOKING(ped, p1) end

---@param vehIndex integer
---@return integer
function TASK.GET_ACTIVE_VEHICLE_MISSION_TYPE(vehIndex) end

---@param PedIndex integer
---@param DelayTime integer
---@param iFlags integer
function TASK.TASK_LEAVE_ANY_VEHICLE(PedIndex, DelayTime, iFlags) end

---@param p0 any
---@return any
function TASK._0xBD70108D01875299(p0) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function TASK.TASK_USE_RANDOM_SCENARIO_IN_GROUP(ped, p1, p2, p3, p4) end

---@param PedIndex integer
---@param EntityIndex integer
---@param Duration integer
---@param InstantBlendToAim boolean
---@param p4 integer
function TASK.TASK_AIM_GUN_AT_ENTITY(PedIndex, EntityIndex, Duration, InstantBlendToAim, p4) end

---@param PedIndex integer
---@param EntityIndex integer
---@param Time integer
---@param p3 number
---@param p4 number
---@param p5 number
function TASK.TASK_TURN_PED_TO_FACE_ENTITY(PedIndex, EntityIndex, Time, p3, p4, p5) end

---@param PedIndex integer
---@param VecTargetCoorsX number
---@param VecTargetCoorsY number
---@param VecTargetCoorsZ number
---@param Duration integer
---@param InstantBlendToAim boolean
---@param PlayAimIntro boolean
function TASK.TASK_AIM_GUN_AT_COORD(PedIndex, VecTargetCoorsX, VecTargetCoorsY, VecTargetCoorsZ, Duration, InstantBlendToAim, PlayAimIntro) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function TASK.TASK_AIM_AT_COORD(ped, p1, p2, p3, p4, p5, p6) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function TASK.TASK_AIM_AT_ENTITY(ped, p1, p2, p3, p4) end

---@param PedIndex integer
---@param VecTargetCoorsX number
---@param VecTargetCoorsY number
---@param VecTargetCoorsZ number
---@param Duration integer
---@param FiringType integer
---@param p6 any
function TASK.TASK_SHOOT_AT_COORD(PedIndex, VecTargetCoorsX, VecTargetCoorsY, VecTargetCoorsZ, Duration, FiringType, p6) end

---@param PedIndex integer
---@param VehicleIndex integer
function TASK.TASK_SHUFFLE_TO_NEXT_VEHICLE_SEAT(PedIndex, VehicleIndex) end

---@param PedIndex integer
---@param p1 boolean
---@param p2 boolean
function TASK.CLEAR_PED_TASKS(PedIndex, p1, p2) end

---@param p0 any
function TASK._0x1A7D63CB1B0BB223(p0) end

---@param p0 any
function TASK._0xB2D15D3551FE4FAE(p0) end

---@param ped integer
function TASK._0xDF94844D474F31E5(ped) end

---@param p0 any
function TASK._0xEBA2081E0A5F4D17(p0) end

---@param vehicle integer
function TASK._0x141BC64C8D7C5529(vehicle) end

---@param PedIndex integer
function TASK.CLEAR_PED_SECONDARY_TASK(PedIndex) end

---@param vehicle integer
---@param p1 boolean
function TASK.TASK_EVERYONE_LEAVE_VEHICLE_IN_ORDER(vehicle, p1) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function TASK.TASK_INVESTIGATE(ped, p1, p2, p3, p4, p5) end

---@param PedIndex integer
---@param EntityIndex integer
---@param Time integer
---@param SeekRadius number
---@param SeekAngle number
---@param MoveBlendRatio number
---@param OffsetFlags integer
function TASK.TASK_GOTO_ENTITY_OFFSET(PedIndex, EntityIndex, Time, SeekRadius, SeekAngle, MoveBlendRatio, OffsetFlags) end

---@param PedIndex integer
---@param EntityIndex integer
---@param Time integer
---@param fTargetRadius number
---@param fXOffset number
---@param fYOffset number
---@param MoveBlendRatio number
---@param OffsetFlags integer
function TASK.TASK_GOTO_ENTITY_OFFSET_XY(PedIndex, EntityIndex, Time, fTargetRadius, fXOffset, fYOffset, MoveBlendRatio, OffsetFlags) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
function TASK.TASK_GOTO_ENTITY_OFFSET_XYZ(ped, p1, p2, p3, p4, p5, p6, p7, p8) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
function TASK.TASK_GOTO_ENTITY_OFFSET_XY_AIMING(ped, p1, p2, p3, p4, p5, p6, p7, p8) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
---@param p9 any
function TASK.TASK_GOTO_ENTITY_OFFSET_XYZ_AIMING(ped, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
function TASK.TASK_FOLLOW_ENTITY_WHILE_AIMING_AT_ENTITY(ped, p1, p2, p3, p4, p5, p6, p7) end

---@param PedIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param Time integer
function TASK.TASK_TURN_PED_TO_FACE_COORD(PedIndex, VecCoorsX, VecCoorsY, VecCoorsZ, Time) end

---@param PedIndex integer
---@param VehicleIndex integer
---@param Action integer
---@param Time integer
function TASK.TASK_VEHICLE_TEMP_ACTION(PedIndex, VehicleIndex, Action, Time) end

---@param PedIndex integer
---@param VehicleIndex integer
---@param TargetVehicleIndex integer
---@param Mission integer
---@param CruiseSpeed number
---@param mode integer
---@param TargetReachedDist number
---@param StraightLineDist number
---@param DriveAgainstTraffic boolean
function TASK.TASK_VEHICLE_MISSION(PedIndex, VehicleIndex, TargetVehicleIndex, Mission, CruiseSpeed, mode, TargetReachedDist, StraightLineDist, DriveAgainstTraffic) end

---@param driver integer
---@param vehicle integer
---@param x number
---@param y number
---@param z number
---@param speed number
---@param drivingFlags integer
---@param p7 integer
---@param stoppingRange1 number
---@param stoppingRange2 number
---@param p10 boolean
function TASK.TASK_VEHICLE_DRIVE_TO_DESTINATION(driver, vehicle, x, y, z, speed, drivingFlags, p7, stoppingRange1, stoppingRange2, p10) end

---@param vehicle integer
---@param x number
---@param y number
---@param z number
---@param speed number
---@param p5 integer
---@param p6 integer
---@param p7 number
---@param p8 number
function TASK._TASK_VEHICLE_DRIVE_TO_DESTINATION_2(vehicle, x, y, z, speed, p5, p6, p7, p8) end

---@param vehicle integer
---@param p1 number
---@param p2 number
---@param p3 number
---@param speed number
---@param type integer
function TASK._TASK_VEHICLE_FLEE_ON_CLEANUP(vehicle, p1, p2, p3, speed, type) end

---@param driver integer
---@param vehicle integer
---@param x number
---@param y number
---@param z number
---@param p5 number
---@param p6 number
---@param flag integer
function TASK.TASK_VEHICLE_DRIVE_STRAIGHT_TO_POINT(driver, vehicle, x, y, z, p5, p6, flag) end

---@param vehicle integer
---@param x number
---@param y number
---@param z number
---@param p4 number
---@param p5 number
---@param p6 any
function TASK._TASK_VEHICLE_DRIVE_TO_POINT_2(vehicle, x, y, z, p4, p5, p6) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TASK._0x1D125814EBC517EB(p0, p1, p2, p3) end

---@param vehicle integer
---@param x number
---@param y number
---@param z number
---@return boolean
function TASK._0x583AE9AF9CEE0958(vehicle, x, y, z) end

---@param PedIndex integer
---@param VehicleIndex integer
---@param TargetPedIndex integer
---@param Mission integer
---@param CruiseSpeed number
---@param mode integer
---@param TargetReachedDist number
---@param StraightLineDist number
---@param DriveAgainstTraffic boolean
function TASK.TASK_VEHICLE_MISSION_PED_TARGET(PedIndex, VehicleIndex, TargetPedIndex, Mission, CruiseSpeed, mode, TargetReachedDist, StraightLineDist, DriveAgainstTraffic) end

---@param p0 any
---@param p1 any
function TASK._0xA263ADBBC8056214(p0, p1) end

---@param PedIndex integer
---@param VehicleIndex integer
---@param EscortEntityIndex integer
---@param EscortType integer
---@param CruiseSpeed number
---@param mode integer
---@param CustomOffset number
---@param MinHeightAboveTerrain integer
---@param StraightLineDistance number
function TASK.TASK_VEHICLE_ESCORT(PedIndex, VehicleIndex, EscortEntityIndex, EscortType, CruiseSpeed, mode, CustomOffset, MinHeightAboveTerrain, StraightLineDistance) end

---@param PedIndex integer
---@param BoatIndex integer
---@param TargetVehicleIndex integer
---@param TargetPedIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param Mission integer
---@param CruiseSpeed number
---@param mode integer
---@param TargetReachedDist number
---@param BoatFlags integer
function TASK.TASK_BOAT_MISSION(PedIndex, BoatIndex, TargetVehicleIndex, TargetPedIndex, VecCoorsX, VecCoorsY, VecCoorsZ, Mission, CruiseSpeed, mode, TargetReachedDist, BoatFlags) end

---@param ped integer
function TASK.TASK_WEAPON(ped) end

---@param PedIndex integer
---@param OtherPedIndex integer
---@param TargetVehicleIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param AbortRange number
---@param FrequencyPercentage integer
---@param bPushUnderneathDrivingTaskIfDriving boolean
---@param FiringPatternHash integer
function TASK.TASK_DRIVE_BY(PedIndex, OtherPedIndex, TargetVehicleIndex, VecCoorsX, VecCoorsY, VecCoorsZ, AbortRange, FrequencyPercentage, bPushUnderneathDrivingTaskIfDriving, FiringPatternHash) end

---@param PedIndex integer
---@param OtherPedIndex integer
---@param TargetVehicleIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
function TASK.SET_DRIVEBY_TASK_TARGET(PedIndex, OtherPedIndex, TargetVehicleIndex, VecCoorsX, VecCoorsY, VecCoorsZ) end

---@param PedIndex integer
function TASK.CLEAR_DRIVEBY_TASK_UNDERNEATH_DRIVING_TASK(PedIndex) end

---@param PedIndex integer
---@return boolean
function TASK.IS_DRIVEBY_TASK_UNDERNEATH_DRIVING_TASK(PedIndex) end

---@param ped integer
---@return boolean
function TASK.GET_IS_PED_AIMING_IN_THE_AIR(ped) end

---@param ped integer
---@param p1 any
function TASK._SET_PED_CLEAR_AIMING_IN_THE_AIR(ped, p1) end

---@param PedIndex integer
---@return boolean
function TASK.IS_MOUNTED_WEAPON_TASK_UNDERNEATH_DRIVING_TASK(PedIndex) end

---@param Ped integer
---@param VehicleIndex integer
---@param seat integer
function TASK.TASK_WARP_PED_INTO_VEHICLE(Ped, VehicleIndex, seat) end

---@param PedIndex integer
---@param EntityIndex integer
---@param Time integer
---@param FiringType integer
---@param affectCockedState boolean
function TASK.TASK_SHOOT_AT_ENTITY(PedIndex, EntityIndex, Time, FiringType, affectCockedState) end

---@param ped integer
---@param args integer
function TASK.TASK_SHOOT_WITH_WEAPON(ped, args) end

---@param entity integer
---@param targetEntity integer
---@param duration integer
---@param p3 any
---@param p4 any
function TASK._0x2416EC2F31F75266(entity, targetEntity, duration, p3, p4) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function TASK._0x41323F4E0C4AE94B(p0, p1, p2, p3, p4, p5, p6) end

---@param p0 any
---@return any
function TASK._0x5EA655F01D93667A(p0) end

---@param PedIndex integer
---@param UsePlayerLaunchForce boolean
function TASK.TASK_CLIMB(PedIndex, UsePlayerLaunchForce) end

---@param ped integer
---@param heading number
function TASK._TASK_CLIMB_2(ped, heading) end

---@param PedIndex integer
---@param p1 number
---@param p2 boolean
---@param p3 boolean
function TASK.TASK_CLIMB_LADDER(PedIndex, p1, p2, p3) end

---@param PedIndex integer
---@param p1 boolean
---@param resetCrouch boolean
function TASK.CLEAR_PED_TASKS_IMMEDIATELY(PedIndex, p1, resetCrouch) end

---@param PedIndex integer
---@param TaskIndex integer
---@param Progress1 integer
---@param Progress2 integer
function TASK.TASK_PERFORM_SEQUENCE_FROM_PROGRESS(PedIndex, TaskIndex, Progress1, Progress2) end

---@param PedIndex integer
---@param MoveBlendRatio number
function TASK.SET_PED_DESIRED_MOVE_BLEND_RATIO(PedIndex, MoveBlendRatio) end

---@param PedIndex integer
---@return number
function TASK.GET_PED_DESIRED_MOVE_BLEND_RATIO(PedIndex) end

---@param PedIndex integer
---@param EntityIndex integer
---@param SeekRadius number
---@param AimRadius number
function TASK.TASK_GOTO_ENTITY_AIMING(PedIndex, EntityIndex, SeekRadius, AimRadius) end

---@param PedIndex integer
---@param vCentreX number
---@param vCentreY number
---@param vCentreZ number
---@param fRadius number
function TASK.TASK_SET_SPHERE_DEFENSIVE_AREA(PedIndex, vCentreX, vCentreY, vCentreZ, fRadius) end

---@param PedIndex integer
function TASK.TASK_CLEAR_DEFENSIVE_AREA(PedIndex) end

---@param PedIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param headingDegrees number
---@param speed number
function TASK.TASK_PED_SLIDE_TO_COORD(PedIndex, VecCoorsX, VecCoorsY, VecCoorsZ, headingDegrees, speed) end

---@param p0 any
---@return any
function TASK._0x9420FB11B8D77948(p0) end

---@param p0 any
---@return any
function TASK._0x6BA606AB3A83BC4D(p0) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param direction number
---@param usage integer
---@param height integer
---@param arc integer
---@param isPriorityToPlayer boolean
---@return integer
function TASK.ADD_COVER_POINT(VecCoorsX, VecCoorsY, VecCoorsZ, direction, usage, height, arc, isPriorityToPlayer) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
---@return any
function TASK._0x59872EA4CBD11C56(p0, p1, p2, p3, p4, p5, p6, p7, p8) end

---@param index integer
function TASK.REMOVE_COVER_POINT(index) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param p3 any
---@return boolean
function TASK.DOES_SCRIPTED_COVER_POINT_EXIST_AT_COORDS(VecCoorsX, VecCoorsY, VecCoorsZ, p3) end

---@param index integer
---@return Vector3
function TASK.GET_SCRIPTED_COVER_POINT_COORDS(index) end

---@param p0 any
---@return Vector3
function TASK._0xE116F6F2DA2D777E(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function TASK._0x50AA09A0DA64E73C(p0, p1, p2, p3, p4, p5, p6) end

---@param p0 any
function TASK._0xE5831AA1E2FD147C(p0) end

---@param PedIndex integer
---@param OtherPedIndex integer
---@param CombatFlags integer
---@param TaskThreatResponseFlags integer
function TASK.TASK_COMBAT_PED(PedIndex, OtherPedIndex, CombatFlags, TaskThreatResponseFlags) end

---@param PedIndex integer
---@param OtherPedIndex integer
---@param Time integer
---@param Flags integer
function TASK.TASK_COMBAT_PED_TIMED(PedIndex, OtherPedIndex, Time, Flags) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function TASK._TASK_COMBAT_PED_3(p0, p1, p2, p3, p4, p5) end

---@param PedIndex integer
---@param VecFromCoorsX number
---@param VecFromCoorsY number
---@param VecFromCoorsZ number
---@param Time integer
---@param p5 boolean
---@param p6 boolean
---@param p7 boolean
function TASK.TASK_SEEK_COVER_FROM_POS(PedIndex, VecFromCoorsX, VecFromCoorsY, VecFromCoorsZ, Time, p5, p6, p7) end

---@param PedIndex integer
---@param OtherPedIndex integer
---@param Time integer
---@param p3 boolean
---@param p4 boolean
---@param p5 boolean
function TASK.TASK_SEEK_COVER_FROM_PED(PedIndex, OtherPedIndex, Time, p3, p4, p5) end

---@param PedIndex integer
---@param CoverIndex integer
---@param VecFromCoorsX number
---@param VecFromCoorsY number
---@param VecFromCoorsZ number
---@param Time integer
---@param p6 any
---@param p7 any
---@param p8 any
function TASK.TASK_SEEK_COVER_TO_COVER_POINT(PedIndex, CoverIndex, VecFromCoorsX, VecFromCoorsY, VecFromCoorsZ, Time, p6, p7, p8) end

---@param PedIndex integer
---@param VecCooverCoorsX number
---@param VecCooverCoorsY number
---@param VecCooverCoorsZ number
---@param VecFromCoorsX number
---@param VecFromCoorsY number
---@param VecFromCoorsZ number
---@param Time integer
---@param p8 any
---@param p9 any
---@param p10 any
function TASK.TASK_SEEK_COVER_TO_COORDS(PedIndex, VecCooverCoorsX, VecCooverCoorsY, VecCooverCoorsZ, VecFromCoorsX, VecFromCoorsY, VecFromCoorsZ, Time, p8, p9, p10) end

---@param PedIndex integer
---@param vCoverPosX number
---@param vCoverPosY number
---@param vCoverPosZ number
---@param Time integer
---@param CanPeekAndAim boolean
---@param BlendInDuration number
---@param p7 any
---@param p8 any
---@param coverpoint integer
---@param p10 boolean
---@param p11 boolean
---@param p12 any
function TASK.TASK_PUT_PED_DIRECTLY_INTO_COVER(PedIndex, vCoverPosX, vCoverPosY, vCoverPosZ, Time, CanPeekAndAim, BlendInDuration, p7, p8, coverpoint, p10, p11, p12) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param fromX number
---@param fromY number
---@param fromZ number
---@param timeout integer
---@param p8 any
---@param p9 any
---@param p10 any
---@param p11 any
---@param p12 any
---@param p13 any
---@param p14 any
---@param p15 any
---@param p16 any
---@param p17 any
function TASK._TASK_PUT_PED_DIRECTLY_INTO_COVER_FROM_COORDS(ped, x, y, z, fromX, fromY, fromZ, timeout, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17) end

---@param PedIndex integer
---@param PedTargetIndex integer
---@param meleeStyle integer
---@param p3 number
---@param animBlendRatio number
---@param p5 boolean
---@param AiCombatFlags integer
function TASK.TASK_PUT_PED_DIRECTLY_INTO_MELEE(PedIndex, PedTargetIndex, meleeStyle, p3, animBlendRatio, p5, AiCombatFlags) end

---@param ped integer
---@param grappleTarget integer
---@param grappleStyle integer
---@param p3 number
---@param p4 number
---@param p5 boolean
---@param p6 integer
function TASK.TASK_PUT_PED_DIRECTLY_INTO_GRAPPLE(ped, grappleTarget, grappleStyle, p3, p4, p5, p6) end

---@param ped integer
---@param p1 any
function TASK.TASK_COMPANION_AMBIENT(ped, p1) end

---@param p0 any
function TASK._0x098036CAB8373D36(p0) end

---@param p0 any
function TASK._0x10C44F633E2D6D9E(p0) end

---@param p0 any
function TASK._0x7FB78B2199C10E92(p0) end

---@param ped integer
---@param p1 any
---@param p2 any
function TASK.TASK_GUARD(ped, p1, p2) end

---@param PedIndex integer
---@param fMaxPatrolProximity number
---@param GuardAreaRadius number
---@param bSetDefensiveArea boolean
function TASK.TASK_GUARD_CURRENT_POSITION(PedIndex, fMaxPatrolProximity, GuardAreaRadius, bSetDefensiveArea) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
function TASK._TASK_GUARD_ASSIGNED_DEFENSIVE_AREA_2(ped, p1, p2, p3, p4, p5, p6, p7) end

---@param PedIndex integer
---@param vDefendPositionX number
---@param vDefendPositionY number
---@param vDefendPositionZ number
---@param fHeading number
---@param fMaxPatrolProximity number
---@param nTimer integer
function TASK.TASK_GUARD_ASSIGNED_DEFENSIVE_AREA(PedIndex, vDefendPositionX, vDefendPositionY, vDefendPositionZ, fHeading, fMaxPatrolProximity, nTimer) end

---@param PedIndex integer
---@param vDefendPositionX number
---@param vDefendPositionY number
---@param vDefendPositionZ number
---@param fHeading number
---@param context any
function TASK.TASK_STAND_GUARD(PedIndex, vDefendPositionX, vDefendPositionY, vDefendPositionZ, fHeading, context) end

---@param PedIndex integer
---@param CruiseSpeed number
function TASK.SET_DRIVE_TASK_CRUISE_SPEED(PedIndex, CruiseSpeed) end

---@param PedIndex integer
---@param MaxCruiseSpeed number
function TASK.SET_DRIVE_TASK_MAX_CRUISE_SPEED(PedIndex, MaxCruiseSpeed) end

---@param vStartX number
---@param vStartY number
---@param vStartZ number
---@param vEndX number
---@param vEndY number
---@param vEndZ number
---@param bBlockObjects boolean
---@param bBlockVehicles boolean
---@param bBlockMap boolean
---@param bBlockPlayer boolean
function TASK.ADD_COVER_BLOCKING_AREA(vStartX, vStartY, vStartZ, vEndX, vEndY, vEndZ, bBlockObjects, bBlockVehicles, bBlockMap, bBlockPlayer) end

---@param volume integer
---@param p1 boolean
---@param p2 boolean
---@param p3 boolean
---@param p4 boolean
function TASK._ADD_COVER_BLOCKING_VOLUME(volume, p1, p2, p3, p4) end

function TASK.REMOVE_ALL_COVER_BLOCKING_AREAS() end

---@param p0 any
---@param p1 any
function TASK._0x2A10538D0A005E81(p0, p1) end

function TASK._0x4F57397388E1DFF8() end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function TASK.TASK_ROB_PED(ped, p1, p2, p3, p4) end

---@param ped integer
---@return boolean
function TASK._0xBEDBE39B5FD98FD6(ped) end

---@param scenarioHash integer
---@param x number
---@param y number
---@param z number
---@param heading number
---@param p5 any
---@param p6 any
---@param p7 boolean
---@return integer
function TASK.CREATE_SCENARIO_POINT_HASH(scenarioHash, x, y, z, heading, p5, p6, p7) end

---@param entity integer
---@param scenarioHash integer
---@param x number
---@param y number
---@param z number
---@param heading number
---@param p6 any
---@param p7 any
---@param p8 boolean
---@return integer
function TASK.CREATE_SCENARIO_POINT_HASH_ATTACHED_TO_ENTITY(entity, scenarioHash, x, y, z, heading, p6, p7, p8) end

---@param scenario integer
---@return boolean
function TASK._DOES_SCENARIO_POINT_HAVE_PROPS(scenario) end

---@param scenarioPoint integer
---@param name any
---@return integer
function TASK.GET_PROP_FOR_SCENARIO_POINT(scenarioPoint, name) end

---@param scenario integer
---@param entity integer
---@param propName any
---@param p3 boolean
---@return boolean
function TASK._ASSOCIATE_PROP_WITH_SCENARIO(scenario, entity, propName, p3) end

---@param scenario integer
---@param flag integer
---@param value boolean
function TASK._SET_SCENARIO_POINT_FLAG(scenario, flag, value) end

---@param scenario integer
---@param flag integer
---@return boolean
function TASK._IS_SCENARIO_POINT_FLAG_SET(scenario, flag) end

---@param p0 any
---@param p1 any
function TASK._0xADC45010BC17AF0E(p0, p1) end

---@param p0 any
---@return any
function TASK._0x974DA3408DEC4E79(p0) end

---@param scenario integer
---@param propName any
---@return boolean
function TASK._DISASSOCIATE_PROP_FROM_SCENARIO(scenario, propName) end

---@param scenario integer
---@return boolean
function TASK.DOES_SCENARIO_POINT_EXIST(scenario) end

---@param p0 any
---@return any
function TASK._0x22CD2C33ED4467A1(p0) end

---@param scenario integer
---@return integer
function TASK._GET_SCENARIO_POINT_ENTITY(scenario) end

---@param scenario integer
---@return integer
function TASK._GET_PED_USING_SCENARIO_POINT(scenario) end

---@param scenario integer
---@param p1 boolean
---@return Vector3
function TASK._GET_SCENARIO_POINT_COORDS(scenario, p1) end

---@param p0 any
---@return Vector3
function TASK._0x91CB5E431F579BA1(p0) end

---@param p0 any
---@return any
function TASK._0x370F57C47F68EBCA(p0) end

---@param scenario integer
---@param p1 boolean
---@return number
function TASK._GET_SCENARIO_POINT_HEADING(scenario, p1) end

---@param scenario integer
---@return number
function TASK._GET_SCENARIO_POINT_RADIUS(scenario) end

---@param scenario integer
---@param xPos number
---@param yPos number
---@param zPos number
---@param p4 boolean
function TASK._SET_SCENARIO_POINT_COORDS(scenario, xPos, yPos, zPos, p4) end

---@param scenario integer
---@param heading number
---@param p2 boolean
function TASK._SET_SCENARIO_POINT_HEADING(scenario, heading, p2) end

---@param scenario integer
---@param radius number
function TASK._SET_SCENARIO_POINT_RADIUS(scenario, radius) end

---@param p0 any
---@param p1 any
function TASK._0xA7479FB665361EDB(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0xE69FDA40AAC3EFC0(p0, p1) end

---@param posX number
---@param posY number
---@param posZ number
---@param radius number
---@param scenariosInRadius integer
---@param size integer
---@return integer
function TASK.GET_SCENARIO_POINTS_IN_AREA(posX, posY, posZ, radius, scenariosInRadius, size) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function TASK._0xEFD875C2791EBEFD(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@return any
function TASK._0x152664AA3188B193(p0, p1, p2, p3, p4, p5) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function TASK._0xE7BBC4E56B989449(p0, p1, p2) end

---@param ped integer
---@param p1 boolean
---@return integer
function TASK._GET_SCENARIO_POINT_PED_IS_USING(ped, p1) end

---@param ped integer
---@return any
function TASK.GET_RANSACK_SCENARIO_POINT_PED_IS_USING(ped) end

---@param entity integer
---@param open boolean
function TASK._SET_SCENARIO_CONTAINER_OPENING_STATE(entity, open) end

---@param p0 any
---@return any
function TASK._0xA9E7672F8C6C6F74(p0) end

---@param p0 any
---@return any
function TASK._0x0A98A362C5A19A43(p0) end

---@param p0 any
---@return any
function TASK._0x849791EBBDBA0362(p0) end

---@param p0 any
---@return any
function TASK._0x640A602946A8C972(p0) end

---@param p0 any
---@return any
function TASK._0x01AF8A3729231A43(p0) end

---@param entity integer
---@return boolean
function TASK._GET_SCENARIO_CONTAINER_OPENING_STATE(entity) end

---@param scenario integer
---@param entity integer
function TASK._RESET_SCENARIO_FOR_ENTITY(scenario, entity) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TASK._0x4161648394262FDF(p0, p1, p2, p3) end

---@param p0 any
function TASK._0x9C8F42A5D1859DC1(p0) end

---@param scenario integer
function TASK._DELETE_SCENARIO_POINT(scenario) end

---@param ped integer
---@param scenario integer
---@param conditionalAnim any
---@param p3 integer
---@param p4 boolean
---@param p5 boolean
---@param p6 integer
---@param p7 boolean
---@param p8 number
---@param p9 boolean
function TASK.TASK_USE_SCENARIO_POINT(ped, scenario, conditionalAnim, p3, p4, p5, p6, p7, p8, p9) end

---@param ped integer
---@param ped2 integer
---@param p2 any
---@param p3 any
---@param p4 integer
---@param p5 integer
---@param p6 number
---@param p7 boolean
function TASK._TASK_USE_SCENARIO_POINT_2(ped, ped2, p2, p3, p4, p5, p6, p7) end

---@param ped integer
---@param scenarioHash integer
---@param duration integer
---@param playEnterAnim boolean
---@param conditionalHash integer
---@param heading number
---@param p6 boolean
function TASK.TASK_START_SCENARIO_IN_PLACE_HASH(ped, scenarioHash, duration, playEnterAnim, conditionalHash, heading, p6) end

---@param ped integer
---@param p1 any
---@param p2 any
---@param p3 integer
---@param p4 boolean
---@param p5 number
---@param p6 boolean
function TASK._TASK_START_SCENARIO_IN_PLACE_2(ped, p1, p2, p3, p4, p5, p6) end

---@param ped integer
---@param scenarioHash integer
---@param x number
---@param y number
---@param z number
---@param heading number
---@param duration integer
---@param sittingScenario boolean
---@param teleport boolean
---@param p9 any
---@param p10 number
---@param p11 boolean
function TASK.TASK_START_SCENARIO_AT_POSITION(ped, scenarioHash, x, y, z, heading, duration, sittingScenario, teleport, p9, p10, p11) end

---@param p0 any
---@return any
function TASK._0xF97F462779B31786(p0) end

---@param p0 any
---@return any
function TASK._0x6C269F673C47031E(p0) end

---@param p0 any
function TASK._0x9667CCE29BFA0780(p0) end

---@param p0 any
---@return any
function TASK._0x00FFE0F85253C572(p0) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param distance number
---@param duration integer
---@param p6 boolean
---@param p7 boolean
---@param p8 boolean
---@param p9 boolean
function TASK._TASK_USE_NEAREST_SCENARIO_TO_COORD(ped, x, y, z, distance, duration, p6, p7, p8, p9) end

---@param PedIndex integer
---@param vPositionX number
---@param vPositionY number
---@param vPositionZ number
---@param fRange number
---@param iTimeToLeaveMS integer
---@param p6 boolean
---@param p7 boolean
---@param p8 boolean
---@param p9 boolean
function TASK.TASK_USE_NEAREST_SCENARIO_TO_COORD_WARP(PedIndex, vPositionX, vPositionY, vPositionZ, fRange, iTimeToLeaveMS, p6, p7, p8, p9) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param distance number
function TASK.TASK_USE_NEAREST_TRAIN_SCENARIO_TO_COORD_WARP(ped, x, y, z, distance) end

---@param PedIndex integer
---@param vPositionX number
---@param vPositionY number
---@param vPositionZ number
---@param fRange number
---@param p5 boolean
---@param p6 boolean
---@param p7 boolean
---@param p8 boolean
function TASK.TASK_USE_NEAREST_SCENARIO_CHAIN_TO_COORD(PedIndex, vPositionX, vPositionY, vPositionZ, fRange, p5, p6, p7, p8) end

---@param PedIndex integer
---@param vPositionX number
---@param vPositionY number
---@param vPositionZ number
---@param fRange number
---@param p5 boolean
---@param p6 boolean
---@param p7 boolean
---@param p8 boolean
function TASK.TASK_USE_NEAREST_SCENARIO_CHAIN_TO_COORD_WARP(PedIndex, vPositionX, vPositionY, vPositionZ, fRange, p5, p6, p7, p8) end

---@param ped integer
---@return any
function TASK._0xFDECCA06E8B81346(ped) end

---@param ped integer
---@param p1 number
---@return any
function TASK._0x2D657B10F211C572(ped, p1) end

---@param ped integer
---@param train integer
---@param scenarioPoint integer
---@param scenarioHash integer
function TASK.TASK_RIDE_TRAIN(ped, train, scenarioPoint, scenarioHash) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@return any
function TASK._0x79197F7D2BB5E73A(p0, p1, p2, p3, p4, p5) end

---@param vPositionX number
---@param vPositionY number
---@param vPositionZ number
---@param fRange number
---@param p4 boolean
---@param p5 any
---@param p6 boolean
---@return boolean
function TASK.DOES_SCENARIO_EXIST_IN_AREA(vPositionX, vPositionY, vPositionZ, fRange, p4, p5, p6) end

---@param x number
---@param y number
---@param z number
---@param typeHash integer
---@param radius number
---@param p5 boolean
---@return boolean
function TASK.DOES_SCENARIO_OF_TYPE_EXIST_IN_AREA_HASH(x, y, z, typeHash, radius, p5) end

---@param xPos number
---@param yPos number
---@param zPos number
---@param scenarioType integer
---@param distance number
---@param p5 any
---@param p6 boolean
---@return integer
function TASK.FIND_SCENARIO_OF_TYPE_HASH(xPos, yPos, zPos, scenarioType, distance, p5, p6) end

---@param p0 any
---@param p1 any
function TASK._0x0D322AEF8878B8FE(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@return any
function TASK._0xD508FA229F1C4900(p0, p1, p2, p3, p4, p5) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function TASK._0xB8E213D02F37947D(p0, p1, p2, p3, p4, p5, p6) end

---@param vPositionX number
---@param vPositionY number
---@param vPositionZ number
---@param fRange number
---@param bOnlyUsersActuallyAtScenario boolean
---@return boolean
function TASK.IS_SCENARIO_OCCUPIED(vPositionX, vPositionY, vPositionZ, fRange, bOnlyUsersActuallyAtScenario) end

---@param scenario integer
---@return any
function TASK._0x1ACBC313966C21F3(scenario) end

---@param PedIndex integer
---@return boolean
function TASK.PED_HAS_USE_SCENARIO_TASK(PedIndex) end

---@param ped integer
---@return boolean
function TASK._PED_IS_IN_SCENARIO_BASE(ped) end

---@param p0 any
---@param p1 any
---@return any
function TASK._0x90703A8F75EE4ABD(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function TASK._0xD999E379265A4501(p0, p1, p2) end

---@param PedIndex integer
---@param clipSet any
---@param clip any
function TASK.PLAY_ANIM_ON_RUNNING_SCENARIO(PedIndex, clipSet, clip) end

---@return any
function TASK._0x74F0209674864CBD() end

---@return any
function TASK._0xE1C105E6BBA48270() end

---@param p0 any
---@return any
function TASK._0x1AC5A8AB50CFAA33(p0) end

---@param p0 any
function TASK._0xBEEFBB608D2AA68A(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
function TASK._0x19BC99C678FBA139(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TASK._0x5D9B0BAAF04CF65B(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
function TASK._0x9B6A58FDB0024F12(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0xBC3F847AE2C3DC65(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x450080DDEDB91258(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x954451EA2D2120FB(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x0F4F6C4CE471259D(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0xB8E3486D107F4194(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x827A58CED9D4D5B4(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x4A7D73989F52EB37(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0xB79817DB31FF72B9(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x65D281985F2BDFC2(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x885D19AC2B6FBFF4(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TASK._0x2064B33F6E6B92D4(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TASK._0xCE4E669400E5F8AA(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
function TASK._0x2EB977293923C723(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0xE9225354FB7437A7(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x764DB5A48390FBAD(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x8F8C84363810691A(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0xFF8AFCA532B500D4(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function TASK._0xFE5D28B9B7837CC1(p0, p1, p2, p3) end

---@param p0 any
function TASK._0x2B8AF29A78024BD3(p0) end

---@param p0 any
---@return any
function TASK._0x0365000D8BF86531(p0) end

---@param p0 any
---@return Vector3
function TASK._0x865732725536EE39(p0) end

function TASK._0x0E184495B27BB57D() end

---@param scenarioGroupName any
---@return boolean
function TASK.DOES_SCENARIO_GROUP_EXIST(scenarioGroupName) end

---@param scenarioGroup integer
---@return boolean
function TASK._DOES_SCENARIO_GROUP_EXIST_HASH(scenarioGroup) end

---@param scenarioGroupName any
---@return boolean
function TASK.IS_SCENARIO_GROUP_ENABLED(scenarioGroupName) end

---@param scenarioGroup integer
---@return boolean
function TASK._IS_SCENARIO_GROUP_ENABLED_HASH(scenarioGroup) end

---@param scenarioGroupName any
---@param enabled boolean
function TASK.SET_SCENARIO_GROUP_ENABLED(scenarioGroupName, enabled) end

---@param scenarioGroup integer
---@param toggle boolean
function TASK._SET_SCENARIO_GROUP_ENABLED_HASH(scenarioGroup, toggle) end

function TASK.RESET_SCENARIO_GROUPS_ENABLED() end

---@param p0 any
function TASK._0x358A1A751B335A11(p0) end

---@param p0 any
---@param p1 any
function TASK.FORCE_SCENARIO_GROUP_PRIORITY(p0, p1) end

---@param p0 any
---@return any
function TASK._0xE55478C5EDF70AC2(p0) end

---@param scenario integer
---@return boolean
function TASK._IS_SCENARIO_POINT_ACTIVE(scenario) end

---@param scenario integer
---@param active boolean
function TASK._SET_SCENARIO_POINT_ACTIVE(scenario, active) end

---@param scenario integer
function TASK._RESET_SCENARIO_SCRIPT(scenario) end

---@param scenarioTypeName any
---@return boolean
function TASK.IS_SCENARIO_TYPE_ENABLED(scenarioTypeName) end

---@param scenarioTypeName any
---@param enabled boolean
function TASK.SET_SCENARIO_TYPE_ENABLED(scenarioTypeName, enabled) end

---@param scenarioType integer
---@param toggle boolean
function TASK._SET_SCENARIO_TYPE_ENABLED_HASH(scenarioType, toggle) end

function TASK.RESET_SCENARIO_TYPES_ENABLED() end

---@param ped integer
---@return integer
function TASK._GET_SCENARIO_POINT_TYPE_PED_IS_USING(ped) end

---@param scenario integer
---@return integer
function TASK._GET_SCENARIO_POINT_TYPE(scenario) end

---@param PedIndex integer
---@param scenario integer
---@return boolean
function TASK.IS_PED_ACTIVE_IN_SCENARIO(PedIndex, scenario) end

---@param ped integer
---@param p1 boolean
---@return boolean
function TASK.IS_PED_EXITING_SCENARIO(ped, p1) end

---@param p0 any
---@return any
function TASK._0x2C497BDEF897C6DF(p0) end

---@param PedIndex integer
---@param vPositionX number
---@param vPositionY number
---@param vPositionZ number
---@param fRange number
---@param Flags integer
---@param p6 any
function TASK.TASK_COMBAT_HATED_TARGETS_IN_AREA(PedIndex, vPositionX, vPositionY, vPositionZ, fRange, Flags, p6) end

---@param ped integer
---@param radius number
function TASK.TASK_COMBAT_HATED_TARGETS_NO_LOS_TEST(ped, radius) end

---@param PedIndex integer
---@param fRange number
---@param Flags integer
---@param p3 any
function TASK.TASK_COMBAT_HATED_TARGETS_AROUND_PED(PedIndex, fRange, Flags, p3) end

---@param PedIndex integer
---@param fRange number
---@param iTime integer
---@param Flags integer
function TASK.TASK_COMBAT_HATED_TARGETS_AROUND_PED_TIMED(PedIndex, fRange, iTime, Flags) end

---@param ped integer
---@param radius number
function TASK.TASK_COMBAT_HATED_TARGETS(ped, radius) end

---@param p0 any
function TASK._0x30B391915538EBE2(p0) end

---@param PedIndex integer
---@param ThrowAtCoordX number
---@param ThrowAtCoordY number
---@param ThrowAtCoordZ number
function TASK.TASK_THROW_PROJECTILE(PedIndex, ThrowAtCoordX, ThrowAtCoordY, ThrowAtCoordZ) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TASK._TASK_THROW_PROJECTILE_2(p0, p1, p2, p3) end

---@param ped integer
---@param audPedWhistleType integer
---@param p2 integer
function TASK.TASK_WHISTLE_ANIM(ped, audPedWhistleType, p2) end

---@param PedIndex integer
---@param p1 boolean
---@param p2 boolean
---@param p3 boolean
---@param p4 boolean
function TASK.TASK_SWAP_WEAPON(PedIndex, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
function TASK._0x0000A8ACDC2E1B6A(p0, p1) end

---@param PedIndex integer
---@param bDrawWeapon boolean
function TASK.TASK_RELOAD_WEAPON(PedIndex, bDrawWeapon) end

---@param ped integer
---@param p1 any
function TASK.TASK_PICK_UP_WEAPON(ped, p1) end

---@param PedIndex integer
---@return boolean
function TASK.IS_PED_GETTING_UP(PedIndex) end

---@param ped integer
---@param p1 any
---@param p2 any
function TASK.TASK_ANIMAL_WRITHE(ped, p1, p2) end

---@param ped integer
---@param killer integer
---@param p2 boolean
---@param weaponHash integer
---@param p4 integer
---@param p5 integer
function TASK._TASK_ANIMAL_BLEED_OUT(ped, killer, p2, weaponHash, p4, p5) end

---@param PedIndex integer
---@return boolean
function TASK.IS_PED_IN_WRITHE(PedIndex) end

---@param p0 any
---@param p1 any
---@return any
function TASK._0x3F8387DB1B9F31B7(p0, p1) end

---@param p0 any
---@return any
function TASK._0x756C7B4C43DF0422(p0) end

---@return any
function TASK._0x351F74ED6177EBE7() end

---@param p0 any
---@return any
function TASK._0x6C50B9DCCCA70023(p0) end

---@param ped integer
---@param reviver integer
---@param tool integer
function TASK.TASK_REVIVE_TARGET(ped, reviver, tool) end

---@param RouteName any
function TASK.OPEN_PATROL_ROUTE(RouteName) end

function TASK.CLOSE_PATROL_ROUTE() end

---@param NodeId integer
---@param NodeType any
---@param vNodePositionX number
---@param vNodePositionY number
---@param vNodePositionZ number
---@param NodeLookAtPosX number
---@param NodeLookAtPosY number
---@param NodeLookAtPosZ number
---@param Duration integer
---@param p9 boolean
function TASK.ADD_PATROL_ROUTE_NODE(NodeId, NodeType, vNodePositionX, vNodePositionY, vNodePositionZ, NodeLookAtPosX, NodeLookAtPosY, NodeLookAtPosZ, Duration, p9) end

---@param NodeId1 integer
---@param NodeId2 integer
function TASK.ADD_PATROL_ROUTE_LINK(NodeId1, NodeId2) end

function TASK.CREATE_PATROL_ROUTE() end

---@param RouteName any
function TASK.DELETE_PATROL_ROUTE(RouteName) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function TASK._0x643FD1556F621772(p0, p1, p2) end

---@param Ped integer
---@param RouteName any
---@param PedAlertState integer
---@param CanChatToPeds boolean
---@param CanUseHeadLookAtAlongRoute boolean
function TASK.TASK_PATROL(Ped, RouteName, PedAlertState, CanChatToPeds, CanUseHeadLookAtAlongRoute) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
function TASK._TASK_PATROL_2(p0, p1, p2, p3, p4, p5, p6, p7) end

---@param Ped integer
function TASK.TASK_STAY_IN_COVER(Ped) end

---@param PedIndex integer
---@param OtherPed integer
---@param FireTolerance number
function TASK.TASK_VEHICLE_SHOOT_AT_PED(PedIndex, OtherPed, FireTolerance) end

---@param PedIndex integer
---@param OtherPed integer
function TASK.TASK_VEHICLE_AIM_AT_PED(PedIndex, OtherPed) end

---@param PedIndex integer
---@param vPositionX number
---@param vPositionY number
---@param vPositionZ number
---@param FireTolerance number
function TASK.TASK_VEHICLE_SHOOT_AT_COORD(PedIndex, vPositionX, vPositionY, vPositionZ, FireTolerance) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TASK._0xAF2EF28CE3084505(p0, p1, p2, p3) end

---@param PedIndex integer
---@param vPositionX number
---@param vPositionY number
---@param vPositionZ number
function TASK.TASK_VEHICLE_AIM_AT_COORD(PedIndex, vPositionX, vPositionY, vPositionZ) end

---@param iPed integer
---@param VehicleIndex integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param CruiseSpeed number
---@param Mode integer
---@param TargetReachedDist number
function TASK.TASK_VEHICLE_GOTO_NAVMESH(iPed, VehicleIndex, VecCoorsX, VecCoorsY, VecCoorsZ, CruiseSpeed, Mode, TargetReachedDist) end

---@param PedIndex integer
---@param GoToCoordX number
---@param GoToCoordY number
---@param GoToCoordZ number
---@param AimAtCoordX number
---@param AimAtCoordY number
---@param AimAtCoordZ number
---@param p7 number
---@param p8 boolean
---@param p9 number
---@param p10 number
---@param p11 boolean
---@param p12 any
---@param p13 boolean
---@param FiringPatternHash integer
---@param p15 any
function TASK.TASK_GO_TO_COORD_WHILE_AIMING_AT_COORD(PedIndex, GoToCoordX, GoToCoordY, GoToCoordZ, AimAtCoordX, AimAtCoordY, AimAtCoordZ, p7, p8, p9, p10, p11, p12, p13, FiringPatternHash, p15) end

---@param ped integer
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
function TASK.TASK_GO_TO_COORD_WHILE_AIMING_AT_COORD_USING_COMBAT_STYLE(ped, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15) end

---@param PedIndex integer
---@param GoToCoordX number
---@param GoToCoordY number
---@param GoToCoordZ number
---@param ped2 integer
---@param p5 number
---@param p6 any
---@param p7 number
---@param p8 number
---@param p9 any
---@param p10 any
---@param p11 any
---@param firingPattern integer
---@param p13 integer
---@param p14 any
function TASK.TASK_GO_TO_COORD_WHILE_AIMING_AT_ENTITY(PedIndex, GoToCoordX, GoToCoordY, GoToCoordZ, ped2, p5, p6, p7, p8, p9, p10, p11, firingPattern, p13, p14) end

---@param ped integer
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
function TASK.TASK_GO_TO_COORD_WHILE_AIMING_AT_ENTITY_USING_COMBAT_STYLE(ped, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14) end

---@param PedIndex integer
---@param GoToEntityIndex integer
---@param AimAtEntityIndex integer
---@param p3 number
---@param p4 any
---@param p5 number
---@param p6 number
---@param p7 any
---@param p8 any
---@param FiringPatternHash integer
---@param p10 any
function TASK.TASK_GO_TO_ENTITY_WHILE_AIMING_AT_ENTITY(PedIndex, GoToEntityIndex, AimAtEntityIndex, p3, p4, p5, p6, p7, p8, FiringPatternHash, p10) end

---@param ped integer
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
function TASK.TASK_GO_TO_ENTITY_WHILE_AIMING_AT_ENTITY_USING_COMBAT_STYLE(ped, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) end

---@param PedIndex integer
---@param GoToCoordX number
---@param GoToCoordY number
---@param GoToCoordZ number
---@param AimNearCoordX number
---@param AimNearCoordY number
---@param AimNearCoordZ number
---@param MoveBlendRatio number
---@param Shoot boolean
---@param TargetDistance number
---@param SlowDistance number
---@param UseNavMesh boolean
---@param iNavFlags integer
---@param iTaskFlags integer
---@param FiringPatternHash integer
function TASK.TASK_GO_TO_COORD_AND_AIM_AT_HATED_ENTITIES_NEAR_COORD(PedIndex, GoToCoordX, GoToCoordY, GoToCoordZ, AimNearCoordX, AimNearCoordY, AimNearCoordZ, MoveBlendRatio, Shoot, TargetDistance, SlowDistance, UseNavMesh, iNavFlags, iTaskFlags, FiringPatternHash) end

---@param ped integer
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
function TASK.TASK_GO_TO_COORD_AND_AIM_AT_HATED_ENTITIES_NEAR_COORD_USING_COMBAT_STYLE(ped, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14) end

---@param nPedIndex integer
---@param nMinTime integer
---@param nMaxTime integer
---@param type integer
function TASK.SET_HIGH_FALL_TASK(nPedIndex, nMinTime, nMaxTime, type) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function TASK._0x5217B7B6DB78E1F3(p0, p1, p2, p3, p4) end

---@param RecordingName any
function TASK.REQUEST_WAYPOINT_RECORDING(RecordingName) end

---@param RecordingName any
---@return boolean
function TASK.GET_IS_WAYPOINT_RECORDING_LOADED(RecordingName) end

---@param RecordingName any
function TASK.REMOVE_WAYPOINT_RECORDING(RecordingName) end

function TASK._0xF718931A82EEB898() end

---@param RecordingName any
---@param iOutNumPoints integer
---@return boolean
---@return integer
function TASK.WAYPOINT_RECORDING_GET_NUM_POINTS(RecordingName, iOutNumPoints) end

---@param RecordingName any
---@param iWaypoint integer
---@param vOutCoord Vector3
---@return boolean
---@return Vector3
function TASK.WAYPOINT_RECORDING_GET_COORD(RecordingName, iWaypoint, vOutCoord) end

---@param RecordingName any
---@param iWaypoint integer
---@return number
function TASK.WAYPOINT_RECORDING_GET_SPEED_AT_POINT(RecordingName, iWaypoint) end

---@param RecordingName any
---@param vPosX number
---@param vPosY number
---@param vPosZ number
---@param iOutWaypoint integer
---@return boolean
---@return integer
function TASK.WAYPOINT_RECORDING_GET_CLOSEST_WAYPOINT(RecordingName, vPosX, vPosY, vPosZ, iOutWaypoint) end

---@param ped integer
---@param p1 any
function TASK.TASK_FOLLOW_WAYPOINT_RECORDING_ADVANCED(ped, p1) end

---@param iPed integer
---@param RecordingName any
---@param iStartingProgress integer
---@param iFlags integer
---@param iTargetProgress integer
---@param p5 boolean
---@param p6 any
---@param p7 integer
function TASK.TASK_FOLLOW_WAYPOINT_RECORDING(iPed, RecordingName, iStartingProgress, iFlags, iTargetProgress, p5, p6, p7) end

---@param ped integer
---@param waypointRecording any
---@param p2 number
---@param p3 integer
---@param p4 integer
---@param p5 integer
---@param p6 boolean
function TASK.TASK_FOLLOW_WAYPOINT_RECORDING_AT_OFFSET(ped, waypointRecording, p2, p3, p4, p5, p6) end

---@param ped0 integer
---@param ped1 integer
---@param waypointRecording any
---@param p3 number
---@param p4 number
---@param p5 integer
---@param p6 integer
---@param p7 integer
---@param p8 boolean
function TASK.TASK_FOLLOW_ENTITY_ALONG_WAYPOINT_RECORDING_AT_OFFSET(ped0, ped1, waypointRecording, p3, p4, p5, p6, p7, p8) end

---@param iPed integer
---@param waypointRecording any
---@return boolean
function TASK.IS_WAYPOINT_PLAYBACK_GOING_ON_FOR_PED(iPed, waypointRecording) end

---@param iPed integer
---@return integer
function TASK.GET_PED_WAYPOINT_PROGRESS(iPed) end

---@param iPed integer
---@return number
function TASK.GET_PED_WAYPOINT_DISTANCE(iPed) end

---@param iPed integer
---@param vOffsetX number
---@param vOffsetY number
---@param vOffsetZ number
---@return boolean
function TASK.SET_PED_WAYPOINT_ROUTE_OFFSET(iPed, vOffsetX, vOffsetY, vOffsetZ) end

---@param RecordingName any
---@param iWaypoint integer
---@return number
function TASK.GET_WAYPOINT_DISTANCE_ALONG_ROUTE(RecordingName, iWaypoint) end

---@param waypointRecording any
---@param x number
---@param y number
---@param z number
---@return number
function TASK._0x3ACC128510142B9D(waypointRecording, x, y, z) end

---@param iPed integer
---@return boolean
function TASK.WAYPOINT_PLAYBACK_GET_IS_PAUSED(iPed) end

---@param ped integer
---@return boolean
function TASK.WAYPOINT_PLAYBACK_GET_IS_AIMING(ped) end

---@param ped integer
---@return boolean
function TASK.WAYPOINT_PLAYBACK_GET_IS_SHOOTING(ped) end

---@param iPed integer
---@param p1 boolean
---@param p2 boolean
---@param p3 boolean
function TASK.WAYPOINT_PLAYBACK_PAUSE(iPed, p1, p2, p3) end

---@param iPed integer
---@param bAchieveHeadingFirst boolean
---@param iProgressToContinueFrom integer
---@param iTimeBeforeResumingMs integer
function TASK.WAYPOINT_PLAYBACK_RESUME(iPed, bAchieveHeadingFirst, iProgressToContinueFrom, iTimeBeforeResumingMs) end

---@param iPed integer
---@param fMoveBlendRatio number
---@param p2 boolean
---@param p3 number
---@param p4 boolean
function TASK.WAYPOINT_PLAYBACK_OVERRIDE_SPEED(iPed, fMoveBlendRatio, p2, p3, p4) end

---@param iPed integer
function TASK.WAYPOINT_PLAYBACK_USE_DEFAULT_SPEED(iPed) end

---@param ped integer
---@return number
function TASK.GET_PED_WAYPOINT_OVERRIDE_SPEED(ped) end

---@param RecordingName any
---@param bUseAsAssistedMovementRoute boolean
---@param fPathWidth number
---@param fTension number
---@param p4 boolean
function TASK.USE_WAYPOINT_RECORDING_AS_ASSISTED_MOVEMENT_ROUTE(RecordingName, bUseAsAssistedMovementRoute, fPathWidth, fTension, p4) end

---@param iPed integer
---@param iTargetPed integer
---@param bRunAndGun boolean
---@param p3 any
function TASK.WAYPOINT_PLAYBACK_START_AIMING_AT_PED(iPed, iTargetPed, bRunAndGun, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TASK.WAYPOINT_PLAYBACK_START_AIMING_AT_ENTITY(p0, p1, p2, p3) end

---@param iPed integer
---@param vTargetCoordsX number
---@param vTargetCoordsY number
---@param vTargetCoordsZ number
---@param bRunAndGun boolean
---@param p5 any
function TASK.WAYPOINT_PLAYBACK_START_AIMING_AT_COORD(iPed, vTargetCoordsX, vTargetCoordsY, vTargetCoordsZ, bRunAndGun, p5) end

---@param iPed integer
---@param iTargetPed integer
---@param bRunAndGun boolean
---@param FiringPatternHash integer
---@param p4 number
function TASK.WAYPOINT_PLAYBACK_START_SHOOTING_AT_PED(iPed, iTargetPed, bRunAndGun, FiringPatternHash, p4) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function TASK.WAYPOINT_PLAYBACK_START_SHOOTING_AT_ENTITY(p0, p1, p2, p3, p4) end

---@param iPed integer
---@param vTargetCoordsX number
---@param vTargetCoordsY number
---@param vTargetCoordsZ number
---@param bRunAndGun boolean
---@param FiringPatternHash integer
---@param p6 number
function TASK.WAYPOINT_PLAYBACK_START_SHOOTING_AT_COORD(iPed, vTargetCoordsX, vTargetCoordsY, vTargetCoordsZ, bRunAndGun, FiringPatternHash, p6) end

---@param iPed integer
function TASK.WAYPOINT_PLAYBACK_STOP_AIMING_OR_SHOOTING(iPed) end

---@param RouteName any
function TASK.ASSISTED_MOVEMENT_REMOVE_ROUTE(RouteName) end

---@param pathName any
---@param p1 integer
---@param nodes integer
---@param p3 integer
---@return boolean
function TASK._CREATE_WAYPOINT_PATH(pathName, p1, nodes, p3) end

---@param RouteName any
---@return boolean
function TASK.ASSISTED_MOVEMENT_IS_ROUTE_LOADED(RouteName) end

---@param RouteName any
---@param iFlags integer
function TASK.ASSISTED_MOVEMENT_SET_ROUTE_PROPERTIES(RouteName, iFlags) end

---@param p0 any
---@param p1 any
function TASK.SET_ENABLE_SPEED_RESTRAIN_FOR_WAYPOINT_RECORDING_LEADER(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
function TASK.SET_UP_SPEED_RESTRAIN_INFORMATION_FOR_PLAYER_FOLLOWER(p0, p1, p2, p3, p4, p5, p6, p7, p8) end

---@param iPed integer
---@param VehicleIndex integer
---@param RecordingName any
---@param Mode integer
---@param p4 any
---@param eWaypoint integer
---@param iFlags integer
---@param MaxSpeed number
---@param DriveInLoop boolean
---@param fTargetArriveDistance number
---@param p10 boolean
function TASK.TASK_VEHICLE_FOLLOW_WAYPOINT_RECORDING(iPed, VehicleIndex, RecordingName, Mode, p4, eWaypoint, iFlags, MaxSpeed, DriveInLoop, fTargetArriveDistance, p10) end

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
function TASK._TASK_VEHICLE_FOLLOW_WAYPOINT_RECORDING_2(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param iVeh integer
---@param p1 any
---@return boolean
function TASK.IS_WAYPOINT_PLAYBACK_GOING_ON_FOR_VEHICLE(iVeh, p1) end

---@param iVeh integer
---@return integer
function TASK.GET_VEHICLE_WAYPOINT_PROGRESS(iVeh) end

---@param iVeh integer
---@return integer
function TASK.GET_VEHICLE_WAYPOINT_TARGET_POINT(iVeh) end

---@param iVeh integer
function TASK.VEHICLE_WAYPOINT_PLAYBACK_PAUSE(iVeh) end

---@param p0 any
---@return any
function TASK.VEHICLE_WAYPOINT_PLAYBACK_GET_IS_PAUSED(p0) end

---@param iVeh integer
function TASK.VEHICLE_WAYPOINT_PLAYBACK_RESUME(iVeh) end

---@param iVeh integer
function TASK.VEHICLE_WAYPOINT_PLAYBACK_USE_DEFAULT_SPEED(iVeh) end

---@param iVeh integer
---@param fSpeed number
function TASK.VEHICLE_WAYPOINT_PLAYBACK_OVERRIDE_SPEED(iVeh, fSpeed) end

---@param p0 any
---@return any
function TASK.GET_VEHICLE_WAYPOINT_PLAYBACK_OVERRIDE_SPEED(p0) end

---@param PedIndex integer
---@param bSet boolean
function TASK.TASK_SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(PedIndex, bSet) end

---@param ped integer
---@param p1 boolean
---@param p2 any
---@param p3 boolean
function TASK.TASK_SET_STEALTH_MOVEMENT(ped, p1, p2, p3) end

---@param ped integer
---@param p1 boolean
---@param p2 any
---@param p3 boolean
function TASK.TASK_SET_CROUCH_MOVEMENT(ped, p1, p2, p3) end

---@param PedIndex integer
---@param motionState integer
---@param bForceRestart boolean
function TASK.TASK_FORCE_MOTION_STATE(PedIndex, motionState, bForceRestart) end

---@param PedIndex integer
---@param network any
---@param blendDuration number
---@param bAllowOverrideCloneUpdate boolean
---@param animDictionary any
---@param flags integer
function TASK.TASK_MOVE_NETWORK_BY_NAME(PedIndex, network, blendDuration, bAllowOverrideCloneUpdate, animDictionary, flags) end

---@param ped integer
---@param moveNetworkDefName any
---@param taskData integer
---@param p3 number
---@param p4 boolean
---@param animDict any
---@param flags integer
function TASK.TASK_MOVE_NETWORK_BY_NAME_WITH_INIT_PARAMS(ped, moveNetworkDefName, taskData, p3, p4, animDict, flags) end

---@param ped integer
---@param moveNetworkDefName any
---@param taskData integer
---@param xPos number
---@param yPos number
---@param zPos number
---@param xRot number
---@param yRot number
---@param zRot number
---@param p9 integer
---@param p10 number
---@param p11 integer
---@param p12 integer
---@param flag integer
---@param p14 integer
function TASK.TASK_MOVE_NETWORK_ADVANCED_BY_NAME_WITH_INIT_PARAMS(ped, moveNetworkDefName, taskData, xPos, yPos, zPos, xRot, yRot, zRot, p9, p10, p11, p12, flag, p14) end

---@param ped integer
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
---@param p16 any
---@param p17 any
function TASK.TASK_MOVE_NETWORK_ADVANCED_BY_NAME_WITH_INIT_PARAMS_ATTACHED(ped, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17) end

---@param PedIndex integer
---@return boolean
function TASK.IS_TASK_MOVE_NETWORK_ACTIVE(PedIndex) end

---@param ped integer
---@return integer
function TASK._GET_TASK_MOVE_NETWORK_ID(ped) end

---@param PedIndex integer
---@return boolean
function TASK.IS_TASK_MOVE_NETWORK_READY_FOR_TRANSITION(PedIndex) end

---@param PedIndex integer
---@param StateName any
function TASK.REQUEST_TASK_MOVE_NETWORK_STATE_TRANSITION(PedIndex, StateName) end

---@param PedIndex integer
---@return string
function TASK.GET_TASK_MOVE_NETWORK_STATE(PedIndex) end

---@param p0 any
---@return any
function TASK._0xE9A6400D1A0E7A55(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
function TASK._0x615DC4A82E90BB48(p0, p1, p2) end

---@param PedIndex integer
---@param signalName any
---@param fSignal number
function TASK.SET_TASK_MOVE_NETWORK_SIGNAL_FLOAT(PedIndex, signalName, fSignal) end

---@param ped integer
---@param signalName any
---@param value number
function TASK._SET_TASK_MOVE_NETWORK_SIGNAL_FLOAT_2(ped, signalName, value) end

---@param PedIndex integer
---@param signalName any
---@param bSignal boolean
function TASK.SET_TASK_MOVE_NETWORK_SIGNAL_BOOL(PedIndex, signalName, bSignal) end

---@param ped integer
---@param signalName any
---@param x number
---@param y number
---@param z number
function TASK._SET_TASK_MOVE_NETWORK_SIGNAL_VECTOR(ped, signalName, x, y, z) end

---@param ped integer
---@param phaseName any
---@return number
function TASK._GET_TASK_MOVE_NETWORK_PHASE_FLOAT(ped, phaseName) end

---@param PedIndex integer
---@param eventName any
---@return boolean
function TASK.GET_TASK_MOVE_NETWORK_EVENT(PedIndex, eventName) end

---@param p0 any
---@param p1 any
function TASK._0x9585FF23C4B8EDE0(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0xEAF87DA2BE78A15B(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x3BBEECC5B8F35318(p0, p1) end

---@param MoveBlendRatio number
---@return boolean
function TASK.IS_MOVE_BLEND_RATIO_STILL(MoveBlendRatio) end

---@param MoveBlendRatio number
---@return boolean
function TASK.IS_MOVE_BLEND_RATIO_WALKING(MoveBlendRatio) end

---@param MoveBlendRatio number
---@return boolean
function TASK.IS_MOVE_BLEND_RATIO_RUNNING(MoveBlendRatio) end

---@param MoveBlendRatio number
---@return boolean
function TASK.IS_MOVE_BLEND_RATIO_SPRINTING(MoveBlendRatio) end

---@param PedIndex integer
---@return boolean
function TASK.IS_PED_STILL(PedIndex) end

---@param PedIndex integer
---@return boolean
function TASK.IS_PED_WALKING(PedIndex) end

---@param PedIndex integer
---@return boolean
function TASK.IS_PED_RUNNING(PedIndex) end

---@param PedIndex integer
---@return boolean
function TASK.IS_PED_SPRINTING(PedIndex) end

---@param ped integer
---@return boolean
function TASK.IS_PED_IN_HIT_REACT(ped) end

---@param ArresterPedIndex integer
---@param ArresteePedIndex integer
function TASK.TASK_ARREST_PED(ArresterPedIndex, ArresteePedIndex) end

---@param PedIndex integer
---@return boolean
function TASK.IS_PED_BEING_ARRESTED(PedIndex) end

---@param ped integer
---@return boolean
function TASK._IS_PED_ARRESTING_ANY_PED(ped) end

---@param ped integer
function TASK._CUFF_PED(ped) end

---@param PedIndex integer
function TASK.UNCUFF_PED(PedIndex) end

---@param PedIndex integer
---@return boolean
function TASK.IS_PED_CUFFED(PedIndex) end

---@param ped integer
---@return boolean
function TASK._IS_PED_DUELLING(ped) end

---@param ped integer
---@param p1 any
---@param p2 number
---@param entity integer
---@param p4 number
---@param p5 integer
---@param vPosOpponentX number
---@param vPosOpponentY number
---@param vPosOpponentZ number
---@param fOpponentHead number
---@param p10 integer
function TASK.TASK_DUEL(ped, p1, p2, entity, p4, p5, vPosOpponentX, vPosOpponentY, vPosOpponentZ, fOpponentHead, p10) end

---@param p0 any
---@return any
function TASK._0x908BB14BCE85C80E(p0) end

---@param p0 any
---@return any
function TASK._0x1F7A9A9C38C13A56(p0) end

---@param p0 any
---@return any
function TASK._0x3FEB770D8ED9047A(p0) end

---@param p0 any
---@param p1 any
---@return any
function TASK._0x30146C25686B7836(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function TASK._0x59AE5CA4FFB4E378(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function TASK._0x748D5E0D2A1A4C61(p0, p1, p2) end

---@param ped integer
---@param p1 boolean
---@param p2 number
function TASK.END_DUEL(ped, p1, p2) end

---@param p0 any
---@param p1 any
function TASK._0x651F0530083C0E5A(p0, p1) end

---@param entity integer
---@param carryConfig integer
---@param carrier integer
---@param carriableSlot integer
---@param flags integer
function TASK.TASK_CARRIABLE(entity, carryConfig, carrier, carriableSlot, flags) end

---@param p0 any
function TASK._0x9EBD34958AB6F824(p0) end

---@param entity integer
---@return boolean
function TASK.GET_IS_CARRIABLE_ENTITY(entity) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function TASK._0x10ADFDF07B7DFFBA(p0, p1, p2) end

---@param ped integer
---@param entity integer
---@param x number
---@param y number
---@param z number
---@param p5 number
---@param flags integer
function TASK.TASK_PLACE_CARRIED_ENTITY_AT_COORD(ped, entity, x, y, z, p5, flags) end

---@param ped integer
---@param entity integer
---@param mount integer
---@param p3 number
function TASK.TASK_PLACE_CARRIED_ENTITY_ON_MOUNT(ped, entity, mount, p3) end

---@param ped integer
---@param ped2 integer
---@param entity integer
function TASK.TASK_DUMP_CARRIABLE_FROM_PARENT(ped, ped2, entity) end

---@param ped integer
function TASK._DETACH_CARRIABLE_PED(ped) end

---@param p0 any
function TASK._0xE2CF104ADD49D4BF(p0) end

---@param ped integer
---@param entity integer
function TASK.TASK_PICKUP_CARRIABLE_ENTITY(ped, entity) end

---@param ped integer
---@param targetPed integer
function TASK.TASK_HOGTIE_TARGET_PED(ped, targetPed) end

---@param ped integer
---@param targetPed integer
function TASK._TASK_CUT_FREE_HOGTIED_TARGET_PED(ped, targetPed) end

---@param ped integer
---@param targetPed integer
---@param p2 number
function TASK._TASK_CUT_FREE_HOGTIED_TARGET_PED_2(ped, targetPed, p2) end

---@param ped integer
---@param time number
function TASK._SET_HOGTIE_ESCAPE_TIMER(ped, time) end

---@param ped integer
---@return number
function TASK._GET_HOGTIE_ESCAPE_TIMER(ped) end

---@param p0 any
---@return any
function TASK._0x03D741CB4052E26C(p0) end

---@param asset integer
---@return boolean
function TASK._REQUEST_HERB_COMPOSITE_ASSET(asset) end

---@param asset integer
---@return boolean
function TASK.ARE_COMPOSITE_LOOTABLE_ENTITY_DEF_ASSETS_LOADED(asset) end

---@param asset integer
---@param x number
---@param y number
---@param z number
---@param heading number
---@param groundSetting integer
---@param p6 integer
---@param p7 integer
---@return integer
function TASK._CREATE_HERB_COMPOSITES(asset, x, y, z, heading, groundSetting, p6, p7) end

---@param compositeId integer
---@param p1 boolean
function TASK._DELETE_PATCH_OBJECTS_FROM_HERB_COMPOSITES(compositeId, p1) end

---@param compositeId integer
---@param outEntities integer
---@return integer
function TASK._GET_HERB_COMPOSITE_NUM_ENTITIES(compositeId, outEntities) end

---@param p0 any
---@param p1 any
---@return any
function TASK._0xDF56A2B50C04DEA4(p0, p1) end

---@param ped integer
---@param entity integer
function TASK.TASK_LOOT_ENTITY(ped, entity) end

---@param ped integer
---@param vehicle integer
function TASK.TASK_BREAK_VEHICLE_DOOR_LOCK(ped, vehicle) end

---@param ped integer
---@param x number
---@param y number
---@param z number
---@param p4 integer
---@param p5 number
function TASK.TASK_LOOT_NEAREST_ENTITY(ped, x, y, z, p4, p5) end

---@param ped integer
---@param targetPed integer
function TASK.TASK_LASSO_PED(ped, targetPed) end

---@param ped integer
function TASK.TASK_HOGTIEABLE(ped) end

---@param ped integer
---@param flags integer
---@param getupSetHash integer
---@param p3 any
---@param p4 any
---@param p5 number
function TASK.UNHOGTIE_PED(ped, flags, getupSetHash, p3, p4, p5) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function TASK._0x722D6A49200174FE(p0, p1, p2, p3, p4) end

---@param object integer
function TASK._MAKE_OBJECT_CARRIABLE(object) end

---@param object integer
function TASK.MAKE_OBJECT_NOT_CARRIABLE(object) end

---@param p0 any
---@param p1 any
function TASK._0x8E1DDE26D270CC5E(p0, p1) end

---@param p0 any
---@param item integer
function TASK._0xA6A76D666A281F2D(p0, item) end

---@param p0 any
---@param p1 any
function TASK._0xA21AA2F0C2180125(p0, p1) end

---@param item integer
---@return integer
function TASK._FIND_MODEL_FOR_ITEM(item) end

---@param p0 any
function TASK._0xFF745B0346E19E2C(p0) end

---@param p0 any
---@return any
function TASK._0xB8F52A3F84A7CC59(p0) end

---@param p0 any
function TASK._0x6AFDA2264925BD11(p0) end

---@param p0 any
---@param p1 any
function TASK._0x816A3ACD265E2297(p0, p1) end

---@param p0 any
function TASK._0x4E806A395D43A458(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
function TASK.SET_TEAM_CARRIABLE_ENTITY(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@return boolean
function TASK.IS_TEAM_CARRIABLE_ENTITY(p0, p1) end

---@param hatObject integer
---@return boolean
function TASK._IS_HAT_BEING_PICKED_UP(hatObject) end

---@param object integer
---@param ped integer
function TASK._0x9ADDBB9242179D56(object, ped) end

---@param hatObject integer
---@return boolean
function TASK._IS_HAT_BEING_PICKED_UP_2(hatObject) end

---@param hatObject integer
---@param ped integer
function TASK._TASK_EQUIP_HAT(hatObject, ped) end

---@param p0 any
---@return any
function TASK._0x7CB99FADDE73CD1B(p0) end

---@param entity integer
---@param p1 any
function TASK._0xF3C3503276F4A034(entity, p1) end

---@param p0 any
---@param p1 any
---@return any
function TASK._0x6DAC799857EF3F11(p0, p1) end

---@param p0 any
---@return any
function TASK._0x920684BE432875B1(p0) end

---@param ped integer
---@param p1 boolean
---@param clipset any
---@return boolean
function TASK.SET_ENHANCED_BREAK_FREE(ped, p1, clipset) end

---@param p0 any
---@return any
function TASK._0x6AFD84AEAA3EA538(p0) end

---@param p0 any
---@param p1 any
function TASK._0xBD1C3C0F271C39D3(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0x1ECF56C040FD839C(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function TASK._0xF40A109B4B79A848(p0, p1, p2) end

---@param ped integer
---@return boolean
function TASK._IS_PED_LEADING_HORSE(ped) end

---@param p0 any
---@return any
function TASK._0xAC5045AB7F1A34FD(p0) end

---@param ped integer
---@return integer
function TASK._GET_LED_HORSE_FROM_PED(ped) end

---@param ped integer
---@param p1 number
---@param p2 number
---@param p3 integer
function TASK.TASK_TURN_TO_FACE_CLOSEST_PED(ped, p1, p2, p3) end

---@param ped integer
---@param targetPed integer
---@param p2 integer
---@return boolean
function TASK.TASK_CONFRONT(ped, targetPed, p2) end

---@param ped integer
---@param p1 boolean
---@return boolean
function TASK.TASK_POLICE(ped, p1) end

---@param ped integer
---@param targetPed integer
---@param p2 integer
---@param p3 any
---@param p4 any
---@param p5 number
---@param p6 any
---@param p7 number
---@return boolean
function TASK.TASK_MELEE(ped, targetPed, p2, p3, p4, p5, p6, p7) end

---@param ped integer
---@param targetPed integer
---@param grappleStyle integer
---@param p3 integer
---@param p4 number
---@param p5 integer
---@param p6 integer
---@return boolean
function TASK.TASK_GRAPPLE(ped, targetPed, grappleStyle, p3, p4, p5, p6) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@return boolean
function TASK._TASK_INTIMIDATED(p0, p1, p2, p3, p4) end

---@param victim integer
---@param attacker integer
---@param p2 integer
---@param p3 boolean
---@param p4 boolean
---@param everyFrame boolean
---@param p6 boolean
---@param p7 boolean
---@param flag integer
---@return boolean
function TASK._TASK_INTIMIDATED_2(victim, attacker, p2, p3, p4, everyFrame, p6, p7, flag) end

---@param p0 any
---@param p1 any
function TASK._0x2948235DB2058E99(p0, p1) end

---@param p0 any
---@param p1 any
function TASK._0xB2F47A1AFDFCC595(p0, p1) end

---@param ped integer
---@param p1 integer
---@param p2 any
function TASK._0x41D1331AFAD5A091(ped, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TASK._0x801BD27403F3CBA0(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TASK._0x0FE797DD9F70DFA6(p0, p1, p2, p3) end

---@param ped integer
function TASK.TASK_PERSISTENT_CHARACTER(ped) end

---@param p0 any
function TASK._0xFC7F71CF49F70B6B(p0) end

---@param p0 any
---@param p1 any
function TASK._0xE01F55B2896F6B37(p0, p1) end

---@param p0 any
---@return any
function TASK._0xE62754D09354F6CF(p0) end

---@param p0 any
---@param p1 any
function TASK._0x4BA972D0E5AD8122(p0, p1) end

---@param ped integer
---@param p1 integer
---@return boolean
function TASK._GET_TASK_FISHING(ped, p1) end

---@param ped integer
---@param p1 integer
---@return boolean
function TASK._SET_TASK_FISHING(ped, p1) end

---@param ped integer
---@param bait any
---@param withoutBuoy boolean
function TASK.TASK_SWAP_FISHING_BAIT(ped, bait, withoutBuoy) end

---@param ped integer
---@param bait any
---@param withoutBuoy boolean
---@param instantly boolean
function TASK._SET_FISHING_BAIT(ped, bait, withoutBuoy, instantly) end

---@param ped integer
function TASK._0x1F298C7BD30D1240(ped) end

---@param ped integer
---@param entity integer
function TASK._PED_FISHINGROD_HOOK_ENTITY(ped, entity) end

---@param ped integer
---@param object integer
function TASK._PED_FISHINGROD_HOOK_OBJECT(ped, object) end

---@param ped integer
---@return boolean
function TASK._0xB520DBDA7FCF573F(ped) end

---@param ped integer
---@param p1 boolean
function TASK._0x31BB338F64D5C861(ped, p1) end

---@param ped integer
---@param entity integer
---@param p2 number
---@param p3 number
---@param p4 number
---@param p5 number
---@param p6 integer
function TASK._0x517D01BF27B682D1(ped, entity, p2, p3, p4, p5, p6) end

---@param ped integer
function TASK._0x88FD60D846D9CD63(ped) end

---@param ped integer
---@param p1 number
function TASK._0x9050DF2C53801208(ped, p1) end

---@param ped integer
function TASK._0x22CDBF317C40A122(ped) end

---@return any
function TASK._0x5952DFA38FA529FE() end

---@param ped integer
---@param emoteType integer
---@param playbackMode integer
---@param emote integer
---@param isSecondaryTask boolean
---@param canBreakOut boolean
---@param disableEarlyOutAnimTag boolean
---@param ignoreInvalidMainTask boolean
---@param destroyProps boolean
function TASK.TASK_PLAY_EMOTE_WITH_HASH(ped, emoteType, playbackMode, emote, isSecondaryTask, canBreakOut, disableEarlyOutAnimTag, ignoreInvalidMainTask, destroyProps) end

---@param ped integer
---@param emoteType integer
---@param playbackMode integer
---@param emote integer
---@param isSecondaryTask boolean
---@param canBreakOut boolean
---@param disableEarlyOutAnimTag boolean
---@param ignoreInvalidMainTask boolean
---@param destroyProps boolean
function TASK._TASK_PLAY_EMOTE(ped, emoteType, playbackMode, emote, isSecondaryTask, canBreakOut, disableEarlyOutAnimTag, ignoreInvalidMainTask, destroyProps) end

---@param p0 any
function TASK._0x6A1AF481407BF6E9(p0) end

---@param ped integer
function TASK._TASK_EMOTE_OUTRO(ped) end

---@param p0 any
function TASK._0xEC516FE805D2CB2D(p0) end

---@param p0 any
---@param p1 any
function TASK._0x59AEA4DC640814B9(p0, p1) end

---@param p0 any
---@return any
function TASK._0x11C7CE1AE38911B5(p0) end

---@param p0 any
---@param p1 any
---@return any
function TASK._0xD0ABC4EA3B5E21A0(p0, p1) end

---@param ped integer
---@param p1 any
---@return boolean
function TASK.IS_EMOTE_TASK_RUNNING(ped, p1) end
