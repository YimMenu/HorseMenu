---@meta

---@class VEHICLE
VEHICLE = {}

---@param entity integer
---@param p1 any
function VEHICLE._0x6355602C02EDC6DF(entity, p1) end

---@param vehicle integer
---@param enabled boolean
function VEHICLE._SET_VEHICLE_IS_IN_HURRY(vehicle, enabled) end

---@param ModelHashKey integer
---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param fVehicleHeading number
---@param RegisterAsNetworkObject boolean
---@param ScriptHostObject boolean
---@param bDontAutoCreateDraftAnimals boolean
---@param p8 boolean
---@return integer
function VEHICLE.CREATE_VEHICLE(ModelHashKey, VecCoorsX, VecCoorsY, VecCoorsZ, fVehicleHeading, RegisterAsNetworkObject, ScriptHostObject, bDontAutoCreateDraftAnimals, p8) end

---@param modelHash integer
---@param x number
---@param y number
---@param z number
---@param heading number
---@param isNetwork boolean
---@param bScriptHostVeh boolean
---@param bDontAutoCreateDraftAnimals boolean
---@param draftAnimalPopGroup integer
---@param p9 boolean
---@return integer
function VEHICLE._CREATE_DRAFT_VEHICLE(modelHash, x, y, z, heading, isNetwork, bScriptHostVeh, bDontAutoCreateDraftAnimals, draftAnimalPopGroup, p9) end

---@param VehicleIndex integer
---@return integer
function VEHICLE.DELETE_VEHICLE(VehicleIndex) end

---@param vehicle integer
---@return integer
function VEHICLE._FADE_AND_DESTROY_VEHICLE(vehicle) end

---@param vehicle integer
---@return boolean
function VEHICLE._IS_VEHICLE_FADING_OUT(vehicle) end

---@param VehicleIndex integer
---@param bAllowHomingMissileLockon boolean
function VEHICLE.SET_VEHICLE_ALLOW_HOMING_MISSLE_LOCKON(VehicleIndex, bAllowHomingMissileLockon) end

---@param VehicleIndex integer
---@param bAllowLockon boolean
function VEHICLE.SET_VEHICLE_ALLOW_NO_PASSENGERS_LOCKON(VehicleIndex, bAllowLockon) end

---@param VehicleIndex integer
---@param ModelHashKey integer
---@return boolean
function VEHICLE.IS_VEHICLE_MODEL(VehicleIndex, ModelHashKey) end

---@param volume integer
---@param toggle boolean
function VEHICLE._SET_ALL_VEHICLE_GENERATORS_DISABLED_FOR_VOLUME(volume, toggle) end

---@param VecMinCoorsX number
---@param VecMinCoorsY number
---@param VecMinCoorsZ number
---@param VecMaxCoorsX number
---@param VecMaxCoorsY number
---@param VecMaxCoorsZ number
---@param bActive boolean
---@param bSyncOverNetwork boolean
function VEHICLE.SET_ALL_VEHICLE_GENERATORS_ACTIVE_IN_AREA(VecMinCoorsX, VecMinCoorsY, VecMinCoorsZ, VecMaxCoorsX, VecMaxCoorsY, VecMaxCoorsZ, bActive, bSyncOverNetwork) end

function VEHICLE.SET_ALL_VEHICLE_GENERATORS_ACTIVE() end

---@param VehicleIndex integer
---@param hightSampleRangeUp number
---@return boolean
function VEHICLE.SET_VEHICLE_ON_GROUND_PROPERLY(VehicleIndex, hightSampleRangeUp) end

---@param VehicleIndex integer
---@return boolean
function VEHICLE.IS_VEHICLE_STOPPED(VehicleIndex) end

---@param vehicle integer
---@return integer
function VEHICLE.GET_VEHICLE_NUMBER_OF_PASSENGERS(vehicle) end

---@param VehicleIndex integer
---@return integer
function VEHICLE.GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(VehicleIndex) end

---@param VehicleModelHashKey integer
---@return integer
function VEHICLE.GET_VEHICLE_MODEL_NUMBER_OF_SEATS(VehicleModelHashKey) end

---@param VehicleIndex integer
---@param seat integer
---@return boolean
function VEHICLE.IS_SEAT_WARP_ONLY(VehicleIndex, seat) end

---@param vehicle integer
---@param seatIndex integer
---@return boolean
---@return integer
function VEHICLE._GET_VEHICLE_TURRET_SEAT(vehicle, seatIndex) end

---@param p0 any
---@param p1 any
---@return any
function VEHICLE._0xA9E185D498B9AC67(p0, p1) end

---@param DensityMultiplier number
function VEHICLE.SET_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME(DensityMultiplier) end

---@param DensityMultiplier number
function VEHICLE.SET_RANDOM_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME(DensityMultiplier) end

---@param DensityMultiplier number
function VEHICLE.SET_PARKED_VEHICLE_DENSITY_MULTIPLIER_THIS_FRAME(DensityMultiplier) end

---@param bVal boolean
function VEHICLE.SET_DISABLE_RANDOM_TRAINS_THIS_FRAME(bVal) end

---@param VehicleIndex integer
---@param NewLockState integer
function VEHICLE.SET_VEHICLE_DOORS_LOCKED(VehicleIndex, NewLockState) end

---@param VehicleIndex integer
---@param DoorIndex integer
---@param NewLockState integer
function VEHICLE.SET_VEHICLE_INDIVIDUAL_DOORS_LOCKED(VehicleIndex, DoorIndex, NewLockState) end

---@param VehicleIndex integer
---@param PlayerIndex integer
---@param Locked boolean
function VEHICLE.SET_VEHICLE_DOORS_LOCKED_FOR_PLAYER(VehicleIndex, PlayerIndex, Locked) end

---@param VehicleIndex integer
---@param PlayerIndex integer
---@return boolean
function VEHICLE.GET_VEHICLE_DOORS_LOCKED_FOR_PLAYER(VehicleIndex, PlayerIndex) end

---@param VehicleIndex integer
---@param Locked boolean
function VEHICLE.SET_VEHICLE_DOORS_LOCKED_FOR_ALL_PLAYERS(VehicleIndex, Locked) end

---@param VehicleIndex integer
---@param TeamIndex integer
---@param Locked boolean
function VEHICLE.SET_VEHICLE_DOORS_LOCKED_FOR_TEAM(VehicleIndex, TeamIndex, Locked) end

---@param vehicle integer
---@param team integer
---@return boolean
function VEHICLE._GET_VEHICLE_DOORS_LOCKED_FOR_TEAM(vehicle, team) end

---@param VehicleIndex integer
---@param isAudible boolean
---@param isInvisible boolean
---@param p3 any
---@param p4 any
function VEHICLE.EXPLODE_VEHICLE(VehicleIndex, isAudible, isInvisible, p3, p4) end

---@param p0 any
---@param p1 any
function VEHICLE._0x750D42C013F64AE7(p0, p1) end

---@param p0 any
function VEHICLE._0xE78993FF9022C064(p0) end

---@param p0 any
function VEHICLE._0x9868C0D0134855F7(p0) end

---@param vehicle integer
function VEHICLE._HIDE_HORSE_REINS(vehicle) end

---@param vehicle integer
function VEHICLE._SHOW_HORSE_REINS(vehicle) end

---@param p0 any
---@param p1 any
function VEHICLE._0xD21A3D421E7F09F7(p0, p1) end

---@param p0 any
---@param p1 any
function VEHICLE._0xA13028E22564A1BD(p0, p1) end

---@param p0 any
---@param p1 any
function VEHICLE._0x485B05EF05B9AEE9(p0, p1) end

---@param VehicleIndex integer
---@param AnchoredFlag boolean
function VEHICLE.SET_BOAT_ANCHOR(VehicleIndex, AnchoredFlag) end

---@param vehicle integer
---@param toggle boolean
function VEHICLE._0x6B53F4B811E583D2(vehicle, toggle) end

---@param VehicleIndex integer
---@return boolean
function VEHICLE.CAN_ANCHOR_BOAT_HERE(VehicleIndex) end

---@param VehicleIndex integer
---@param ForcePlayerBoatAnchorFlag boolean
---@param p2 boolean
function VEHICLE.SET_BOAT_REMAINS_ANCHORED_WHILE_PLAYER_IS_DRIVER(VehicleIndex, ForcePlayerBoatAnchorFlag, p2) end

---@param VehicleIndex integer
---@param ForcePlayerLowLodAnchorFlag boolean
function VEHICLE.SET_FORCE_LOW_LOD_ANCHOR_MODE(VehicleIndex, ForcePlayerLowLodAnchorFlag) end

---@param VehicleIndex integer
---@param LodDistance number
function VEHICLE.SET_BOAT_LOW_LOD_ANCHOR_DISTANCE(VehicleIndex, LodDistance) end

---@param VehicleIndex integer
---@param ShouldSink boolean
function VEHICLE.SET_BOAT_SINKS_WHEN_WRECKED(VehicleIndex, ShouldSink) end

---@param vehicle integer
---@param p1 boolean
function VEHICLE._SET_FORCE_HIGH_LOD_VEHICLE(vehicle, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function VEHICLE._0x98A7598C579EE871(p0, p1, p2) end

---@param vehicle integer
---@param p1 boolean
function VEHICLE._0x9E8711C81AA17876(vehicle, p1) end

---@param VehicleIndex integer
---@param StrongFlag boolean
function VEHICLE.SET_VEHICLE_STRONG(VehicleIndex, StrongFlag) end

---@param VehicleIndex integer
---@param seat integer
---@return boolean
function VEHICLE.IS_VEHICLE_SEAT_FREE(VehicleIndex, seat) end

---@param VehicleIndex integer
---@param seat integer
---@return integer
function VEHICLE.GET_PED_IN_VEHICLE_SEAT(VehicleIndex, seat) end

---@param VehicleIndex integer
---@param seat integer
---@return integer
function VEHICLE.GET_LAST_PED_IN_VEHICLE_SEAT(VehicleIndex, seat) end

---@param vehicle integer
---@return boolean
function VEHICLE.IS_DRAFT_VEHICLE(vehicle) end

---@param vehicle integer
---@param harnessId integer
---@return integer
function VEHICLE._GET_PED_IN_DRAFT_HARNESS(vehicle, harnessId) end

---@param VehicleIndex integer
---@param CarSpeed number
function VEHICLE.SET_VEHICLE_FORWARD_SPEED(VehicleIndex, CarSpeed) end

---@param VehicleIndex integer
---@param StoppingDistance number
---@param nTimeToStopFor integer
---@param ControlVerticalVelocity boolean
function VEHICLE.BRING_VEHICLE_TO_HALT(VehicleIndex, StoppingDistance, nTimeToStopFor, ControlVerticalVelocity) end

---@param vehicle integer
---@return boolean
function VEHICLE._IS_VEHICLE_BROUGHT_TO_HALT(vehicle) end

---@param VehicleIndex integer
function VEHICLE.STOP_BRINGING_VEHICLE_TO_HALT(VehicleIndex) end

---@param p0 any
function VEHICLE._0xE12F5ED49F44D40D(p0) end

---@param p0 any
function VEHICLE._0xF6E3D38869D0F7AD(p0) end

---@param VehicleIndex integer
---@param bShutInstantly boolean
function VEHICLE.SET_VEHICLE_DOORS_SHUT(VehicleIndex, bShutInstantly) end

---@param VehicleIndex integer
---@param CanBurstTyresFlag boolean
function VEHICLE.SET_VEHICLE_TYRES_CAN_BURST(VehicleIndex, CanBurstTyresFlag) end

---@param VehicleIndex integer
---@param CanBreakWheelsFlag boolean
function VEHICLE.SET_VEHICLE_WHEELS_CAN_BREAK(VehicleIndex, CanBreakWheelsFlag) end

---@param vehicle integer
---@param toggle boolean
function VEHICLE.SET_VEHICLE_DOORS_TO_OPEN_AT_ANY_DISTANCE(vehicle, toggle) end

---@param VehicleIndex integer
---@param DoorNumber integer
---@param SwingFree boolean
---@param Instant boolean
function VEHICLE.SET_VEHICLE_DOOR_OPEN(VehicleIndex, DoorNumber, SwingFree, Instant) end

---@param VehicleIndex integer
---@param WindowNumber integer
function VEHICLE.REMOVE_VEHICLE_WINDOW(VehicleIndex, WindowNumber) end

---@param p0 any
---@param p1 any
function VEHICLE._0x8878FF3EEE2868A9(p0, p1) end

---@param vehicle integer
---@param dirtLevel number
function VEHICLE._SET_VEHICLE_DIRT_LEVEL_2(vehicle, dirtLevel) end

---@param vehicle integer
---@param mudLevel number
function VEHICLE._SET_VEHICLE_MUD_LEVEL(vehicle, mudLevel) end

---@param VehicleIndex integer
---@param CarLightSetting integer
function VEHICLE.SET_VEHICLE_LIGHTS(VehicleIndex, CarLightSetting) end

---@param RandomTrainsFlag boolean
function VEHICLE.SET_RANDOM_TRAINS(RandomTrainsFlag) end

---@param configHash integer
---@param x number
---@param y number
---@param z number
---@param direction boolean
---@param p5 boolean
---@return integer
function VEHICLE._0x331CBD247FC5DAA8(configHash, x, y, z, direction, p5) end

---@param trackIndex integer
---@return boolean
function VEHICLE._0x0516FAE561276EFC(trackIndex) end

---@param train integer
---@return integer
function VEHICLE._GET_TRAIN_TRACK_FROM_TRAIN_VEHICLE(train) end

---@param trackIndex integer
---@return integer
function VEHICLE._GET_TRAIN_VEHICLE_FROM_TRACK_INDEX(trackIndex) end

---@param trackIndex integer
---@param p1 number
function VEHICLE._0x15206E88FF7617DF(trackIndex, p1) end

---@param trackIndex integer
---@param p1 number
function VEHICLE._0xA7966807953A18EE(trackIndex, p1) end

---@param trackIndex integer
---@param p1 integer
function VEHICLE._0x6B34BE961F639E21(trackIndex, p1) end

---@param train integer
---@param p1 boolean
function VEHICLE._0xE6BD7DD3FD474415(train, p1) end

---@param trackIndex integer
---@param p1 number
function VEHICLE._0x615B3B8E73634509(trackIndex, p1) end

---@param trackIndex integer
---@param p1 integer
function VEHICLE._0x38E7DD70A242D5CB(trackIndex, p1) end

---@param trackIndex integer
---@param p1 integer
function VEHICLE._0x63509DDF102E08E8(trackIndex, p1) end

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
function VEHICLE._0x7408B5C66BA31ADB(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) end

---@param trackIndex integer
---@param p1 number
function VEHICLE._0x41365DB586CD9E8E(trackIndex, p1) end

---@param trackIndex integer
---@param p1 number
function VEHICLE._0xD0AABE5B9F8FA589(trackIndex, p1) end

---@param trackIndex integer
---@param p1 integer
function VEHICLE._0x427C919E9809E370(trackIndex, p1) end

---@param trackIndex integer
---@return boolean
function VEHICLE._DOES_TRAIN_EXIST_ON_TRACK(trackIndex) end

---@param trackIndex integer
---@return Vector3
function VEHICLE._GET_TRAIN_POSITION_ON_TRACK(trackIndex) end

---@param trackIndex integer
---@return boolean
function VEHICLE._0xB4241AD8F5AEE9ED(trackIndex) end

---@param p0 any
function VEHICLE._0xA230A5DDE12ED374(p0) end

---@param trackIndex integer
function VEHICLE._0x0D5FDF0D36FA10CD(trackIndex) end

---@param p0 any
function VEHICLE._0xE682002DB1F30669(p0) end

---@param trackIndex integer
function VEHICLE._0x718EB706B6E998A0(trackIndex) end

---@param trainConfig integer
---@param x number
---@param y number
---@param z number
---@param direction boolean
---@param p5 boolean
---@return boolean
function VEHICLE._0xF05DFAF1ADFEF2CD(trainConfig, x, y, z, direction, p5) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@return any
function VEHICLE._0xD1DF5E54F4ACBE1A(p0, p1, p2, p3, p4, p5, p6) end

---@param p0 any
---@return any
function VEHICLE._0x0FDDEE66E3465726(p0) end

function VEHICLE._0x4C05B42A8D937796() end

function VEHICLE._0xB961DD799A837BD7() end

function VEHICLE._0x16B86A49E072AA85() end

function VEHICLE._0x2A7413168F6CD5A8() end

---@param p0 any
---@param p1 any
---@param p2 any
function VEHICLE._0xFFFE15B433300B8C(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
function VEHICLE._0x6EA1273D525427F4(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@return any
function VEHICLE._0x7BE0746539DEF0C8(p0, p1) end

---@param p0 any
---@param p1 any
function VEHICLE._0x3137EDC899E6DAE4(p0, p1) end

---@param x number
---@param y number
---@param z number
---@return integer
function VEHICLE._0x6C87F49BFA181DB5(x, y, z) end

---@param x number
---@param y number
---@param z number
---@return integer
function VEHICLE._GET_TRACK_INDEX_FROM_COORDS(x, y, z) end

---@param x number
---@param y number
---@param z number
---@return Vector3
function VEHICLE._GET_NEAREST_TRAIN_TRACK_POSITION(x, y, z) end

function VEHICLE.DELETE_ALL_TRAINS() end

---@param p0 any
---@param p1 any
---@return any
function VEHICLE._0x0E558D3A49D759D6(p0, p1) end

---@param p0 any
---@param p1 any
function VEHICLE._0xD4907EF4334C7602(p0, p1) end

---@param p0 any
---@param p1 any
function VEHICLE._0x68830738A6BFB370(p0, p1) end

---@param VehicleIndex integer
---@param NewTrainSpeed number
function VEHICLE.SET_TRAIN_SPEED(VehicleIndex, NewTrainSpeed) end

---@param train integer
---@param speed number
function VEHICLE._SET_TRAIN_MAX_SPEED(train, speed) end

---@param VehicleIndex integer
---@param NewTrainCruiseSpeed number
function VEHICLE.SET_TRAIN_CRUISE_SPEED(VehicleIndex, NewTrainCruiseSpeed) end

---@param train integer
---@return integer
function VEHICLE._GET_TRAIN_CARRIAGE_TRAILER_NUMBER(train) end

---@param trainConfig integer
---@param trainCarIndex integer
---@return integer
function VEHICLE._GET_TRAIN_MODEL_FROM_TRAIN_CONFIG_BY_CAR_INDEX(trainConfig, trainCarIndex) end

---@param trainConfig integer
---@return integer
function VEHICLE._GET_NUM_CARS_FROM_TRAIN_CONFIG(trainConfig) end

---@param train integer
---@return integer
function VEHICLE._GET_TRAIN_CAR(train) end

---@param train integer
---@param toggle boolean
function VEHICLE._SET_TRAIN_STOPS_FOR_STATIONS(train, toggle) end

---@param p0 any
---@param p1 any
function VEHICLE._0xDD100CE1EBBF37E3(p0, p1) end

---@param train integer
---@param p1 number
function VEHICLE._0x160C1B5AB48AB87C(train, p1) end

---@param train integer
---@return boolean
function VEHICLE.IS_TRAIN_WAITING_AT_STATION(train) end

---@param train integer
function VEHICLE._SET_TRAIN_HALT(train) end

---@param train integer
function VEHICLE._SET_TRAIN_LEAVE_STATION(train) end

---@param RandomBoatsFlag boolean
function VEHICLE.SET_RANDOM_BOATS(RandomBoatsFlag) end

---@param FileNumber integer
---@param pRecordingName any
function VEHICLE.REQUEST_VEHICLE_RECORDING(FileNumber, pRecordingName) end

---@param FileNumber integer
---@param pRecordingName any
---@return boolean
function VEHICLE.HAS_VEHICLE_RECORDING_BEEN_LOADED(FileNumber, pRecordingName) end

---@param FileNumber integer
---@param pRecordingName any
function VEHICLE.REMOVE_VEHICLE_RECORDING(FileNumber, pRecordingName) end

---@param iRecordingNumber integer
---@param fTime number
---@param pRecordingName any
---@return Vector3
function VEHICLE.GET_POSITION_OF_VEHICLE_RECORDING_AT_TIME(iRecordingNumber, fTime, pRecordingName) end

---@param iRecordingNumber integer
---@param fTime number
---@param pRecordingName any
---@return Vector3
function VEHICLE.GET_ROTATION_OF_VEHICLE_RECORDING_AT_TIME(iRecordingNumber, fTime, pRecordingName) end

---@param VehicleIndex integer
---@return number
function VEHICLE.GET_TIME_POSITION_IN_RECORDING(VehicleIndex) end

---@param VehicleIndex integer
---@param FileNumber integer
---@param pRecordingName any
---@param DoPlaceOnRoadAdjustment boolean
function VEHICLE.START_PLAYBACK_RECORDED_VEHICLE(VehicleIndex, FileNumber, pRecordingName, DoPlaceOnRoadAdjustment) end

---@param VehicleIndex integer
---@param DoPlaceOnRoadAdjustment boolean
function VEHICLE.FORCE_PLAYBACK_RECORDED_VEHICLE_UPDATE(VehicleIndex, DoPlaceOnRoadAdjustment) end

---@param VehicleIndex integer
function VEHICLE.STOP_PLAYBACK_RECORDED_VEHICLE(VehicleIndex) end

---@param VehicleIndex integer
---@return boolean
function VEHICLE.IS_PLAYBACK_GOING_ON_FOR_VEHICLE(VehicleIndex) end

---@param VehicleIndex integer
---@return boolean
function VEHICLE.IS_PLAYBACK_USING_AI_GOING_ON_FOR_VEHICLE(VehicleIndex) end

---@param VehicleIndex integer
---@param PlaybackSpeed number
function VEHICLE.SET_PLAYBACK_SPEED(VehicleIndex, PlaybackSpeed) end

---@param VehicleIndex integer
---@param TimeSkip number
function VEHICLE.SKIP_TIME_IN_PLAYBACK_RECORDED_VEHICLE(VehicleIndex, TimeSkip) end

---@param CentreX number
---@param CentreY number
---@param CentreZ number
---@param Radius number
---@param VehicleModelHashKey integer
---@param SearchFlags integer
---@return integer
function VEHICLE.GET_CLOSEST_VEHICLE(CentreX, CentreY, CentreZ, Radius, VehicleModelHashKey, SearchFlags) end

---@param TrainEngineIndex integer
---@param CarriageNumber integer
---@return integer
function VEHICLE.GET_TRAIN_CARRIAGE(TrainEngineIndex, CarriageNumber) end

---@param TrainIndex integer
---@return integer
function VEHICLE.DELETE_MISSION_TRAIN(TrainIndex) end

---@param TrainIndex integer
---@param iFlags integer
---@return integer
function VEHICLE.SET_MISSION_TRAIN_AS_NO_LONGER_NEEDED(TrainIndex, iFlags) end

---@param TrainIndex integer
---@param VecNewCoorsX number
---@param VecNewCoorsY number
---@param VecNewCoorsZ number
function VEHICLE.SET_MISSION_TRAIN_COORDS(TrainIndex, VecNewCoorsX, VecNewCoorsY, VecNewCoorsZ) end

---@param train integer
---@param x number
---@param y number
---@param z number
---@param direction boolean
function VEHICLE._SET_MISSION_TRAIN_WARP_TO_COORDS(train, x, y, z, direction) end

---@param train integer
---@param p1 boolean
function VEHICLE._0xA72B1BF3857B94D7(train, p1) end

---@param model integer
---@return boolean
function VEHICLE._IS_THIS_MODEL_A_DRAFT_VEHICLE(model) end

---@param VehicleModelHashKey integer
---@return boolean
function VEHICLE.IS_THIS_MODEL_A_BOAT(VehicleModelHashKey) end

---@param VehicleModelHashKey integer
---@return boolean
function VEHICLE.IS_THIS_MODEL_A_TRAIN(VehicleModelHashKey) end

---@param VehicleIndex integer
---@param CanBeTargettedFlag boolean
function VEHICLE.SET_VEHICLE_CAN_BE_TARGETTED(VehicleIndex, CanBeTargettedFlag) end

---@param VehicleIndex integer
---@param DontAllowPlayerToEnter boolean
function VEHICLE.SET_DONT_ALLOW_PLAYER_TO_ENTER_VEHICLE_IF_LOCKED_FOR_PLAYER(VehicleIndex, DontAllowPlayerToEnter) end

---@param VehicleIndex integer
---@param VisibleDamageFlag boolean
function VEHICLE.SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(VehicleIndex, VisibleDamageFlag) end

---@param VehicleIndex integer
---@param UnbreakableLightFlag boolean
function VEHICLE.SET_VEHICLE_HAS_UNBREAKABLE_LIGHTS(VehicleIndex, UnbreakableLightFlag) end

---@param VehicleIndex integer
---@param RespectLocks boolean
function VEHICLE.SET_VEHICLE_RESPECTS_LOCKS_WHEN_HAS_DRIVER(VehicleIndex, RespectLocks) end

---@param VehicleIndex integer
---@param RespectLocks boolean
function VEHICLE.SET_VEHICLE_CAN_EJECT_PASSENGERS_IF_LOCKED(VehicleIndex, RespectLocks) end

---@param VehicleIndex integer
---@param DirtLevel number
function VEHICLE.SET_VEHICLE_DIRT_LEVEL(VehicleIndex, DirtLevel) end

---@param VehicleIndex integer
---@param DoorNumber integer
---@return boolean
function VEHICLE.IS_VEHICLE_DOOR_FULLY_OPEN(VehicleIndex, DoorNumber) end

---@param VehicleIndex integer
---@param EngineOnFlag boolean
---@param bNoDelay boolean
function VEHICLE.SET_VEHICLE_ENGINE_ON(VehicleIndex, EngineOnFlag, bNoDelay) end

---@param VehicleIndex integer
---@param UnDriveableFlag boolean
function VEHICLE.SET_VEHICLE_UNDRIVEABLE(VehicleIndex, UnDriveableFlag) end

---@param VehicleIndex integer
---@param ProvidesCoverFlag boolean
function VEHICLE.SET_VEHICLE_PROVIDES_COVER(VehicleIndex, ProvidesCoverFlag) end

---@param p0 any
---@param p1 any
function VEHICLE._0x3053064F909B5F42(p0, p1) end

---@param VehicleIndex integer
---@param DoorNumber integer
---@param DoorStatus integer
---@param AngleRatio number
function VEHICLE.SET_VEHICLE_DOOR_CONTROL(VehicleIndex, DoorNumber, DoorStatus, AngleRatio) end

---@param VehicleIndex integer
---@param DoorNumber integer
---@param SetLatched boolean
---@param WillAutoLatch boolean
---@param bApplyForceForDoorClosed boolean
function VEHICLE.SET_VEHICLE_DOOR_LATCHED(VehicleIndex, DoorNumber, SetLatched, WillAutoLatch, bApplyForceForDoorClosed) end

---@param VehicleIndex integer
---@param DoorNumber integer
---@param bShutInstantly boolean
function VEHICLE.SET_VEHICLE_DOOR_SHUT(VehicleIndex, DoorNumber, bShutInstantly) end

---@param VehicleIndex integer
---@param DoorNumber integer
---@param bDissapear boolean
function VEHICLE.SET_VEHICLE_DOOR_BROKEN(VehicleIndex, DoorNumber, bDissapear) end

---@param VehicleIndex integer
---@param bAllowBreaking boolean
function VEHICLE.SET_VEHICLE_CAN_BREAK(VehicleIndex, bAllowBreaking) end

---@param VehicleIndex integer
---@param ConsideredByPlayerFlag boolean
function VEHICLE.SET_VEHICLE_IS_CONSIDERED_BY_PLAYER(VehicleIndex, ConsideredByPlayerFlag) end

---@param VehicleIndex integer
---@param bState boolean
function VEHICLE.SET_VEHICLE_MAY_BE_USED_BY_GOTO_POINT_ANY_MEANS(VehicleIndex, bState) end

---@param VehicleIndex integer
---@return integer
function VEHICLE.GET_VEHICLE_DOOR_LOCK_STATUS(VehicleIndex) end

---@param VehicleIndex integer
---@param DoorNumber integer
---@param bDoorBreakageAllowed boolean
function VEHICLE.SET_DOOR_ALLOWED_TO_BE_BROKEN_OFF(VehicleIndex, DoorNumber, bDoorBreakageAllowed) end

---@param VehicleIndex integer
---@return boolean
function VEHICLE.IS_VEHICLE_ON_ALL_WHEELS(VehicleIndex) end

---@param train integer
---@return boolean
function VEHICLE._GET_TRAIN_DIRECTION(train) end

---@param trackIndex integer
---@return boolean
function VEHICLE._GET_TRAIN_DIRECTION_FROM_INDEX(trackIndex) end

---@param train integer
---@param trainTrack integer
---@param junctionIndex integer
---@return any
---@return integer
---@return integer
function VEHICLE._0x09034479E6E3E269(train, trainTrack, junctionIndex) end

---@param trainTrack integer
---@param x number
---@param y number
---@param z number
---@param junctionIndex integer
---@return boolean
---@return integer
function VEHICLE._GET_TRAIN_TRACK_JUNCTION_AT_COORDS(trainTrack, x, y, z, junctionIndex) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@return any
function VEHICLE._0xD9BF3ED8EFB67EA3(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@return Vector3
function VEHICLE._0x785639D89F8451AB(p0, p1) end

---@param trainTrack integer
---@param junctionIndex integer
---@param enabled boolean
function VEHICLE._SET_TRAIN_TRACK_JUNCTION_SWITCH(trainTrack, junctionIndex, enabled) end

---@param trainTrack integer
---@param junctionIndex integer
---@param enabled boolean
function VEHICLE._0x3ABFA128F5BF5A70(trainTrack, junctionIndex, enabled) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function VEHICLE._0x2C46D2A591D8C322(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function VEHICLE._0xCAFF2C9747103C02(p0, p1, p2) end

function VEHICLE._SET_ALL_JUNCTIONS_CLEARED() end

---@param trackIndex integer
---@param p1 any
function VEHICLE._0x34BCF6209B9668A7(trackIndex, p1) end

---@param trackIndex integer
---@param x number
---@param y number
---@param z number
---@param p4 any
function VEHICLE._0xD0BA1853D76683C8(trackIndex, x, y, z, p4) end

---@param train integer
---@param offset number
function VEHICLE.SET_TRAIN_OFFSET_FROM_STATION(train, offset) end

---@param p0 any
---@param p1 any
function VEHICLE._0xDC69F6913CCA0B99(p0, p1) end

---@param train integer
---@param p1 boolean
function VEHICLE._0x7840576C50A13DBA(train, p1) end

---@param p0 any
---@param p1 any
---@return any
function VEHICLE._0xD0116DF21E6C7B36(p0, p1) end

---@param entity integer
function VEHICLE._DETACH_WAGON_ENTITY_FROM_TRAIN(entity) end

---@param train integer
---@return integer
function VEHICLE._0x1180A2974D251B7B(train) end

---@param train integer
---@return integer
function VEHICLE.GET_CURRENT_STATION_FOR_TRAIN(train) end

---@param trackIndex integer
---@param stationIndex integer
---@return integer
function VEHICLE._0x9CC94A948EAF5372(trackIndex, stationIndex) end

---@param train integer
---@return any
function VEHICLE._0xDE8C5B9F65017FA1(train) end

---@param train integer
---@return integer
function VEHICLE._GET_CURRENT_TRACK_FOR_TRAIN(train) end

---@param trackIndex integer
---@param stationIndex integer
---@return Vector3
function VEHICLE._GET_STATION_COORDS_FROM_TRAIN_STATION_DATA(trackIndex, stationIndex) end

---@param train integer
---@return integer
function VEHICLE.GET_TRACK_INDEX_OF_TRAIN(train) end

---@param train integer
---@param p1 boolean
function VEHICLE._0x1A861F899EBBE17C(train, p1) end

---@param trackIndex integer
---@param p1 boolean
function VEHICLE._0xF8F7DA13CFBD4532(trackIndex, p1) end

---@param train integer
---@param whistleSequence any
---@param p2 boolean
---@param p3 boolean
function VEHICLE._TRIGGER_TRAIN_WHISTLE(train, whistleSequence, p2, p3) end

---@param p0 any
---@param p1 any
function VEHICLE._0x2BB2B5BCF0DF8008(p0, p1) end

---@param p0 any
---@param p1 any
function VEHICLE._0x6703872EC09BC158(p0, p1) end

---@param train integer
---@param p1 boolean
function VEHICLE._0x1BFBAFCC6760FF02(train, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@return any
function VEHICLE._0xF5EA41C1408695FB(p0, p1, p2, p3) end

---@param VehicleIndex integer
function VEHICLE.SET_VEHICLE_FIXED(VehicleIndex) end

---@param VehicleIndex integer
---@param bVal boolean
function VEHICLE.SET_DISABLE_VEHICLE_PETROL_TANK_FIRES(VehicleIndex, bVal) end

---@param VehicleIndex integer
---@param bVal boolean
function VEHICLE.SET_DISABLE_VEHICLE_PETROL_TANK_DAMAGE(VehicleIndex, bVal) end

---@param VehicleIndex integer
---@param bVal boolean
function VEHICLE.SET_DISABLE_VEHICLE_ENGINE_FIRES(VehicleIndex, bVal) end

---@param VehicleIndex integer
---@param bVal boolean
function VEHICLE.SET_VEHICLE_LIMIT_SPEED_WHEN_PLAYER_INACTIVE(VehicleIndex, bVal) end

---@param VehicleIndex integer
---@param bVal boolean
function VEHICLE.SET_VEHICLE_STOP_INSTANTLY_WHEN_PLAYER_INACTIVE(VehicleIndex, bVal) end

---@param VecMinCoorsX number
---@param VecMinCoorsY number
---@param VecMinCoorsZ number
---@param VecMaxCoorsX number
---@param VecMaxCoorsY number
---@param VecMaxCoorsZ number
function VEHICLE.REMOVE_VEHICLES_FROM_GENERATORS_IN_AREA(VecMinCoorsX, VecMinCoorsY, VecMinCoorsZ, VecMaxCoorsX, VecMaxCoorsY, VecMaxCoorsZ) end

---@param VehicleIndex integer
---@param Bias number
function VEHICLE.SET_VEHICLE_STEER_BIAS(VehicleIndex, Bias) end

---@param VehicleIndex integer
---@param Extra integer
---@return boolean
function VEHICLE.IS_VEHICLE_EXTRA_TURNED_ON(VehicleIndex, Extra) end

---@param VehicleIndex integer
---@param Extra integer
---@param TurnOff boolean
function VEHICLE.SET_VEHICLE_EXTRA(VehicleIndex, Extra, TurnOff) end

---@param VehicleIndex integer
---@param Extra integer
---@return boolean
function VEHICLE.DOES_EXTRA_EXIST(VehicleIndex, Extra) end

---@param TrainIndex integer
---@param VecDamageCoorsX number
---@param VecDamageCoorsY number
---@param VecDamageCoorsZ number
---@param Damage number
---@param Deformation number
---@param localDamage boolean
function VEHICLE.SET_VEHICLE_DAMAGE(TrainIndex, VecDamageCoorsX, VecDamageCoorsY, VecDamageCoorsZ, Damage, Deformation, localDamage) end

---@param VehicleIndex integer
---@return number
function VEHICLE.GET_VEHICLE_ENGINE_HEALTH(VehicleIndex) end

---@param VehicleIndex integer
---@param health number
function VEHICLE.SET_VEHICLE_ENGINE_HEALTH(VehicleIndex, health) end

---@param VehicleIndex integer
---@return number
function VEHICLE.GET_VEHICLE_PETROL_TANK_HEALTH(VehicleIndex) end

---@param VehicleIndex integer
---@param health number
function VEHICLE.SET_VEHICLE_PETROL_TANK_HEALTH(VehicleIndex, health) end

---@param VehicleIndex integer
---@param StuckType integer
---@param RequiredTime integer
---@return boolean
function VEHICLE.IS_VEHICLE_STUCK_TIMER_UP(VehicleIndex, StuckType, RequiredTime) end

---@param VehicleIndex integer
---@param StuckType integer
function VEHICLE.RESET_VEHICLE_STUCK_TIMER(VehicleIndex, StuckType) end

---@param VehicleIndex integer
---@param bCheckFire boolean
---@param p2 boolean
---@return boolean
function VEHICLE.IS_VEHICLE_DRIVEABLE(VehicleIndex, bCheckFire, p2) end

---@param vehicle integer
---@return boolean
function VEHICLE.IS_VEHICLE_WRECKED(vehicle) end

---@param vehicle integer
---@return boolean
function VEHICLE._IS_VEHICLE_ON_FIRE(vehicle) end

---@param VehicleIndex integer
---@param bNewVal boolean
function VEHICLE.SET_VEHICLE_HAS_BEEN_OWNED_BY_PLAYER(VehicleIndex, bNewVal) end

---@param VehicleIndex integer
---@param TimeToSoundHorn integer
---@param HornTypeHash integer
---@param isMusicalHorn boolean
function VEHICLE.START_VEHICLE_HORN(VehicleIndex, TimeToSoundHorn, HornTypeHash, isMusicalHorn) end

---@param VehicleIndex integer
---@param bSet boolean
function VEHICLE.SET_VEHICLE_HAS_STRONG_AXLES(VehicleIndex, bSet) end

---@param vehicle integer
---@param snowLevel number
function VEHICLE._SET_VEHICLE_SNOW_LEVEL(vehicle, snowLevel) end

---@param vehicle integer
---@param wetLevel number
function VEHICLE._SET_VEHICLE_WET_LEVEL(vehicle, wetLevel) end

---@param vehicle integer
---@param tintId integer
function VEHICLE._SET_VEHICLE_TINT(vehicle, tintId) end

---@param vehicle integer
---@param liveryIndex integer
function VEHICLE._SET_VEHICLE_LIVERY(vehicle, liveryIndex) end

---@param vehicle integer
---@return integer
function VEHICLE._GET_VEHICLE_TINT(vehicle) end

---@param vehicle integer
---@return integer
function VEHICLE._GET_VEHICLE_LIVERY(vehicle) end

---@param VehicleIndex integer
---@param WindowNumber integer
---@return boolean
function VEHICLE.IS_VEHICLE_WINDOW_INTACT(VehicleIndex, WindowNumber) end

---@param VehicleIndex integer
---@return boolean
function VEHICLE.ARE_ANY_VEHICLE_SEATS_FREE(VehicleIndex) end

---@param VehicleIndex integer
---@param bSet boolean
function VEHICLE.SET_VEHICLE_EXPLODES_ON_HIGH_EXPLOSION_DAMAGE(VehicleIndex, bSet) end

---@param VehicleIndex integer
---@param bSet boolean
function VEHICLE.SET_ALLOW_VEHICLE_EXPLODES_ON_CONTACT(VehicleIndex, bSet) end

---@param pointX number
---@param pointY number
---@param pointZ number
---@param radius number
---@return boolean
function VEHICLE.IS_ANY_VEHICLE_NEAR_POINT(pointX, pointY, pointZ, radius) end

---@param Vehicle integer
function VEHICLE.REQUEST_VEHICLE_HIGH_DETAIL_MODEL(Vehicle) end

---@param VehicleModelHashKey integer
---@param iVehicleRequestFlags integer
function VEHICLE.REQUEST_VEHICLE_ASSET(VehicleModelHashKey, iVehicleRequestFlags) end

---@param p0 any
---@param p1 any
---@param p2 any
function VEHICLE._0xCF9DA72002FC16BF(p0, p1, p2) end

---@param VehicleModelHashKey integer
---@return boolean
function VEHICLE.HAS_VEHICLE_ASSET_LOADED(VehicleModelHashKey) end

---@param VehicleModelHashKey integer
function VEHICLE.REMOVE_VEHICLE_ASSET(VehicleModelHashKey) end

---@param TowTruckVehicleIndex integer
---@param AutomaticallyAttach boolean
---@param ScanWithNonPlayerDriver boolean
---@return any
function VEHICLE.SET_VEHICLE_AUTOMATICALLY_ATTACHES(TowTruckVehicleIndex, AutomaticallyAttach, ScanWithNonPlayerDriver) end

---@param vehicle integer
---@param p1 number
function VEHICLE._0x104D9A7B1C0D0783(vehicle, p1) end

---@param VehicleIndex integer
---@return boolean
function VEHICLE.IS_VEHICLE_IN_BURNOUT(VehicleIndex) end

---@param VehicleIndex integer
---@param bOn boolean
function VEHICLE.SET_VEHICLE_HANDBRAKE(VehicleIndex, bOn) end

function VEHICLE.INSTANTLY_FILL_VEHICLE_POPULATION() end

---@return boolean
function VEHICLE.HAS_INSTANT_FILL_VEHICLE_POPULATION_FINISHED() end

---@param vehicle integer
---@param trailer integer
---@return boolean
---@return integer
function VEHICLE.GET_VEHICLE_TRAILER_VEHICLE(vehicle, trailer) end

---@param VehicleIndex integer
---@return number
function VEHICLE.GET_VEHICLE_ESTIMATED_MAX_SPEED(VehicleIndex) end

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
---@return integer
function VEHICLE.ADD_ROAD_NODE_SPEED_ZONE(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) end

---@param index integer
---@return boolean
function VEHICLE.REMOVE_ROAD_NODE_SPEED_ZONE(index) end

---@param PedIndex integer
---@param VehicleIndex integer
---@param Seat integer
---@param CheckSide boolean
---@param LeftSide boolean
---@return boolean
function VEHICLE.IS_ENTRY_POINT_FOR_SEAT_CLEAR(PedIndex, VehicleIndex, Seat, CheckSide, LeftSide) end

---@param VehicleIndex integer
---@param Seat integer
---@return boolean
function VEHICLE.CAN_SHUFFLE_SEAT(VehicleIndex, Seat) end

---@param vehicle integer
---@param PercentChange number
function VEHICLE.MODIFY_VEHICLE_TOP_SPEED(vehicle, PercentChange) end

---@param VehicleIndex integer
---@param bStaysFrozen boolean
function VEHICLE.SET_VEHICLE_STAYS_FROZEN_WHEN_CLEANED_UP(VehicleIndex, bStaysFrozen) end

---@param VehicleIndex integer
---@param bInfluenceWantedLevel boolean
function VEHICLE.SET_VEHICLE_INFLUENCES_WANTED_LEVEL(VehicleIndex, bInfluenceWantedLevel) end

---@param vehicle integer
---@return boolean
function VEHICLE._IS_BOAT_GROUNDED(vehicle) end

---@param vehicle integer
---@param bStealable boolean
function VEHICLE.SET_VEHICLE_NOT_STEALABLE_AMBIENTLY(vehicle, bStealable) end

---@param vehicle integer
function VEHICLE.LOCK_DOORS_WHEN_NO_LONGER_NEEDED(vehicle) end

---@return integer
function VEHICLE.GET_LAST_DRIVEN_VEHICLE() end

function VEHICLE.CLEAR_LAST_DRIVEN_VEHICLE() end

---@param ped integer
---@param vehicle integer
function VEHICLE.SET_PED_OWNS_VEHICLE(ped, vehicle) end

---@param vehicle integer
---@return integer
function VEHICLE._GET_VEHICLE_OWNER(vehicle) end

---@param vehicle integer
---@param multiplier number
function VEHICLE.SET_VEHICLE_LOD_MULTIPLIER(vehicle, multiplier) end

---@param vehicle integer
---@param lodLevel integer
function VEHICLE._SET_VEHICLE_LOD_LEVEL(vehicle, lodLevel) end

---@param vehicle integer
---@param forceEngineDamage boolean
function VEHICLE.SET_FORCE_VEHICLE_ENGINE_DAMAGE_BY_BULLET(vehicle, forceEngineDamage) end

---@param srcVehicle integer
---@param dstVehicle integer
function VEHICLE.COPY_VEHICLE_DAMAGES(srcVehicle, dstVehicle) end

---@param pedIndex integer
---@param targetEntity integer
---@param vecTargetCoorsX number
---@param vecTargetCoorsY number
---@param vecTargetCoorsZ number
---@param p5 any
function VEHICLE.SET_VEHICLE_SHOOT_AT_TARGET(pedIndex, targetEntity, vecTargetCoorsX, vecTargetCoorsY, vecTargetCoorsZ, p5) end

---@param vehicleIndex integer
---@param forceHd boolean
function VEHICLE.SET_FORCE_HD_VEHICLE(vehicleIndex, forceHd) end

---@param vehicleIndex integer
function VEHICLE.TRACK_VEHICLE_VISIBILITY(vehicleIndex) end

---@param vehicleIndex integer
---@return boolean
function VEHICLE.IS_VEHICLE_VISIBLE(vehicleIndex) end

---@param p0 any
---@return any
function VEHICLE._0x13C190302369308B(p0) end

---@param EnableSlipstreaming boolean
function VEHICLE.SET_ENABLE_VEHICLE_SLIPSTREAMING(EnableSlipstreaming) end

---@param vehicleIndex integer
---@param bForceInactive boolean
function VEHICLE.SET_VEHICLE_INACTIVE_DURING_PLAYBACK(vehicleIndex, bForceInactive) end

---@param vehicleIndex integer
---@param bEnableDegrading boolean
function VEHICLE.SET_VEHICLE_ENGINE_CAN_DEGRADE(vehicleIndex, bEnableDegrading) end

---@param vehicleIndex integer
---@param bIsStolen boolean
function VEHICLE.SET_VEHICLE_IS_STOLEN(vehicleIndex, bIsStolen) end

---@param vehicle integer
---@param p1 boolean
function VEHICLE._0xCBF88256E44D5D39(vehicle, p1) end

---@param vehicle integer
---@param p1 boolean
function VEHICLE._0xC325A6BAA62CF8A2(vehicle, p1) end

---@param p0 any
---@param p1 any
function VEHICLE._0x0CD7914D17A970AB(p0, p1) end

---@param p0 any
---@param p1 any
function VEHICLE._0x23F66C36F8E5EAAB(p0, p1) end

---@param p0 any
function VEHICLE._0x697DF68F3A761A50(p0) end

---@param p0 any
---@param p1 any
function VEHICLE._0x27E3F2B57209FA54(p0, p1) end

---@param disable boolean
---@param TypeOfWeapon integer
---@param vehicleIndex integer
---@param PedIndex integer
function VEHICLE.DISABLE_VEHICLE_WEAPON(disable, TypeOfWeapon, vehicleIndex, PedIndex) end

---@param vehicle integer
---@param canBeUsed boolean
function VEHICLE.SET_VEHICLE_CAN_BE_USED_BY_FLEEING_PEDS(vehicle, canBeUsed) end

---@param vehicle integer
---@param keepEngineOn boolean
function VEHICLE.SET_VEHICLE_KEEP_ENGINE_ON_WHEN_ABANDONED(vehicle, keepEngineOn) end

---@param vehicle integer
---@param bCanWheelsBreakoff boolean
function VEHICLE.SET_VEHICLE_WHEELS_CAN_BREAK_OFF_WHEN_BLOW_UP(vehicle, bCanWheelsBreakoff) end

---@param vehicle integer
---@param p1 integer
function VEHICLE._0x15CC8C33D7FFCC4A(vehicle, p1) end

---@param vehicle integer
---@param canUse boolean
function VEHICLE.SET_VEHICLE_AI_CAN_USE_EXCLUSIVE_SEATS(vehicle, canUse) end

---@param vehicle integer
---@param PedIndex integer
---@param driverIndex integer
function VEHICLE.SET_VEHICLE_EXCLUSIVE_DRIVER(vehicle, PedIndex, driverIndex) end

---@param ped integer
---@param vehicle integer
---@param outIndex integer
---@return boolean
---@return integer
function VEHICLE._IS_PED_EXCLUSIVE_DRIVER_OF_VEHICLE(ped, vehicle, outIndex) end

---@param p0 any
function VEHICLE._0xDC0556D0F484ECAA(p0) end

---@param vehicle integer
---@param disabled boolean
function VEHICLE.SET_DISABLE_SUPERDUMMY(vehicle, disabled) end

---@param VehicleIndex integer
---@return number
function VEHICLE.GET_VEHICLE_BODY_HEALTH(VehicleIndex) end

---@param VehicleIndex integer
---@param health number
function VEHICLE.SET_VEHICLE_BODY_HEALTH(VehicleIndex, health) end

---@param p0 any
---@return any
function VEHICLE._0xE777DDF3E78397E8(p0) end

---@param vehicle integer
---@param bIgnoreBrokenParts boolean
function VEHICLE.SET_VEHICLE_BROKEN_PARTS_DONT_AFFECT_AI_HANDLING(vehicle, bIgnoreBrokenParts) end

---@param p0 number
---@param p1 number
function VEHICLE._0x012701ED938B85DE(p0, p1) end

function VEHICLE._0x8379E05871AD24E0() end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function VEHICLE._SET_HORSE_TRAFFIC_GROUPING_DISTRIBUTION(p0, p1, p2, p3) end

---@param mount integer
---@param draft integer
---@param harnessId integer
---@return boolean
function VEHICLE._ATTACH_DRAFT_VEHICLE_HARNESS_PED(mount, draft, harnessId) end

---@param draft integer
---@param harnessId integer
---@return boolean
function VEHICLE._DETACH_DRAFT_VEHICLE_HARNESS_FROM_INDEX(draft, harnessId) end

---@param draft integer
---@param ped integer
---@return boolean
function VEHICLE._DETACH_DRAFT_VEHICLE_HARNESS_PED(draft, ped) end

---@param p0 any
function VEHICLE._0x0F7F603BDE08C4D3(p0) end

---@param modelHash integer
---@return integer
function VEHICLE._GET_NUM_DRAFT_VEHICLE_HARNESS_PED(modelHash) end

---@param trackIndex integer
---@param x number
---@param y number
---@param z number
---@param distance number
---@param direction boolean
---@return Vector3
function VEHICLE._GET_CHECKPOINT_TRAIN_SPAWN_LOCATION(trackIndex, x, y, z, distance, direction) end

---@param vehicle integer
---@param p1 boolean
function VEHICLE._0xC399CC89FBA05DA0(vehicle, p1) end

---@param vehicle integer
---@param left integer
---@param right integer
---@return integer
---@return integer
function VEHICLE._GET_ROWING_OARS(vehicle, left, right) end

---@param vehicle integer
---@return integer
function VEHICLE.GET_DRIVER_OF_VEHICLE(vehicle) end

---@param vehicle integer
---@param coachrobberyLoot integer
function VEHICLE._SET_FORCE_COACH_ROBBERY_LOOT(vehicle, coachrobberyLoot) end

---@param p0 any
---@return any
function VEHICLE._0x0BA4250D20007C2E(p0) end

---@param vehicle integer
---@param x number
---@param y number
---@param z number
---@param p4 boolean
---@param p5 number
function VEHICLE._0x2200AB13CBD10F4E(vehicle, x, y, z, p4, p5) end

---@param vehicle integer
---@param x number
---@param y number
---@param z number
function VEHICLE._0xB42C87521D1BDD2F(vehicle, x, y, z) end

---@param p0 any
function VEHICLE._0xC351394B932A6A50(p0) end

---@param p0 any
function VEHICLE._0x172E9DD35858DCD7(p0) end

---@param vehicle integer
---@return integer
function VEHICLE._GET_BREAKABLE_VEHICLE_LOCKS_STATE(vehicle) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function VEHICLE._0x877EA24EB1614495(p0, p1, p2) end

---@param vehicle integer
---@param index integer
---@return integer
function VEHICLE._GET_BREAKABLE_VEHICLE_LOCK_OBJECT(vehicle, index) end

---@param vehicle integer
---@return integer
function VEHICLE._GET_NUM_BREAKABLE_VEHICLE_LOCK_OBJECTS(vehicle) end

---@param vehicle integer
---@param toggle boolean
function VEHICLE.SET_BREAKABLE_VEHICLE_LOCKS_UNBREAKABLE(vehicle, toggle) end

---@param p0 any
function VEHICLE._0x9D12796EF4BF9EA9(p0) end

---@param vehicle integer
---@param p1 any
function VEHICLE._0x850CE59DEC2028F3(vehicle, p1) end

---@param p0 any
---@param p1 any
function VEHICLE._0x0355FE37240E2C77(p0, p1) end

---@param p0 any
---@param p1 any
function VEHICLE._0x3D86997A86FEEF0D(p0, p1) end

---@param vehicle integer
---@param p1 any
function VEHICLE._0xD826690B5CF3BEFF(vehicle, p1) end

---@param vehicle integer
---@param wheelIndex integer
---@param destroyingForce number
function VEHICLE._BREAK_OFF_DRAFT_WHEEL(vehicle, wheelIndex, destroyingForce) end

---@param vehicle integer
---@param expected integer
---@param actual integer
---@return boolean
---@return integer
---@return integer
function VEHICLE.GET_DRAFT_ANIMAL_COUNT(vehicle, expected, actual) end

---@param p0 any
function VEHICLE._0x165BE2001E5E4B75(p0) end

---@param draft integer
---@param canDetach boolean
function VEHICLE._SET_DRAFT_VEHICLE_ANIMALS_CAN_DETACH(draft, canDetach) end

---@param draft integer
---@param canBreak boolean
function VEHICLE._SET_DRAFT_VEHICLE_YOKE_CAN_BREAK(draft, canBreak) end

---@param train integer
---@param trackIndex integer
---@param x number
---@param y number
---@param z number
function VEHICLE._ADD_TRAIN_TEMPORARY_STOP(train, trackIndex, x, y, z) end

---@param wagon integer
---@param p1 boolean
function VEHICLE._0x0794199B25E499E1(wagon, p1) end

---@param wagon integer
---@param p1 integer
---@param p2 boolean
function VEHICLE._0x73118A3EE9C9B6DB(wagon, p1, p2) end

---@param wagon integer
---@param p1 integer
---@return boolean
function VEHICLE._0xE1C0F8781BF130C2(wagon, p1) end

---@param vehicle integer
---@param wheel integer
---@return boolean
function VEHICLE._IS_VEHICLE_WHEEL_DESTROYED(vehicle, wheel) end

---@param vehicle integer
---@return boolean
function VEHICLE._0x18714953CCED17D3(vehicle) end

---@param wagon integer
function VEHICLE._0x41F0B254DDF71473(wagon) end

---@param vehicle integer
---@param amount number
---@param p2 integer
---@param p3 boolean
function VEHICLE._SET_VEHICLE_DETERIORATION(vehicle, amount, p2, p3) end

---@param vehicle integer
---@param doorId integer
---@return boolean
function VEHICLE._IS_VEHICLE_DOOR_BROKEN(vehicle, doorId) end

---@param vehicle integer
---@param wheelIndex integer
---@return integer
function VEHICLE._BREAK_OFF_VEHICLE_WHEEL(vehicle, wheelIndex) end

---@param vehicle integer
---@return boolean
function VEHICLE._DELETE_VEHICLE_LANTERNS(vehicle) end

---@param vehicle integer
---@param p1 boolean
function VEHICLE._0x6DE072AC8A95FFC1(vehicle, p1) end

---@param vehicle integer
---@param speed number
function VEHICLE._SET_DRAFT_VEHICLE_DESIRED_SPEED(vehicle, speed) end

---@param vehicle integer
---@return number
function VEHICLE._GET_DRAFT_VEHICLE_DESIRED_SPEED(vehicle) end

---@param vehicle integer
---@param p1 boolean
function VEHICLE._0xC4A2C11FC0D41916(vehicle, p1) end

---@param vehicle integer
---@param p1 boolean
function VEHICLE._0xFC4F15A7DDDC47B1(vehicle, p1) end

---@param vehicle integer
---@param p1 boolean
function VEHICLE._0x4C60C333F9CCA2B6(vehicle, p1) end

---@param vehicle integer
---@param p1 number
function VEHICLE._0xCF342503CA4C8DF1(vehicle, p1) end

---@param train integer
---@param p1 boolean
function VEHICLE._0x06A09A6E0C6D2A84(train, p1) end

---@param train integer
---@param p1 boolean
function VEHICLE._0xAE7E66A61E7C17A5(train, p1) end

---@param train integer
---@param p1 boolean
function VEHICLE._0xEF28A614B4B264B8(train, p1) end

---@param vehicle integer
function VEHICLE._0x04F0579DBDD32F34(vehicle) end

---@param vehicle integer
---@param x number
---@param y number
---@param z number
function VEHICLE._0x12F6C6ED3EFF42DE(vehicle, x, y, z) end

---@param vehicle integer
---@param p1 boolean
function VEHICLE._0x87B974E54C71BA7B(vehicle, p1) end

---@param train integer
---@return boolean
function VEHICLE._HAS_TRAIN_LOADED(train) end

---@param configHash integer
---@param x number
---@param y number
---@param z number
---@param direction boolean
---@param passengers boolean
---@param p6 boolean
---@param conductor boolean
---@return integer
function VEHICLE._CREATE_MISSION_TRAIN(configHash, x, y, z, direction, passengers, p6, conductor) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function VEHICLE._0xD1EFA8D68BF5D63D(p0, p1, p2, p3) end

---@param p0 any
---@return any
function VEHICLE._0x1121B07088ED3013(p0) end

---@param p0 any
---@return any
function VEHICLE._0x42404D57D621601A(p0) end

---@param p0 any
---@return any
function VEHICLE._0x288CBB414C3C2FBB(p0) end

---@param p0 any
---@param p1 any
function VEHICLE._0x6FD7BDF10304363A(p0, p1) end

---@param p0 any
---@param p1 any
function VEHICLE._0xCEB1F1EED484A5B4(p0, p1) end

---@param p0 any
---@return any
function VEHICLE._0xF57DB8E83DCD8349(p0) end

---@param balloon integer
---@param p1 number
function VEHICLE._SET_BALLOON_HOVER_STATE(balloon, p1) end

---@param balloon integer
---@param x number
---@param y number
---@param z number
---@param autoDrive boolean
---@param speedMultiplier number
function VEHICLE._SET_BALLOON_ROUTE(balloon, x, y, z, autoDrive, speedMultiplier) end

---@param vehicle integer
---@return integer
function VEHICLE._GET_BALLOON_OBJECT_FROM_VEHICLE(vehicle) end

---@param vehicle integer
---@param allow boolean
function VEHICLE._SET_DRAFT_VEHICLE_ALLOW_DRAFT_ANIMAL_AUTO_CREATION(vehicle, allow) end

---@param p0 any
---@param p1 any
function VEHICLE._0x6835AFEA10E186F4(p0, p1) end

---@param vehicle integer
---@param seed integer
function VEHICLE._SET_DRAFT_ANIMAL_RANDOM_SEED(vehicle, seed) end

---@param p0 any
---@return any
function VEHICLE._0x14DA8C4BC2CCD90A(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function VEHICLE._0xCACAB2B123BBDBD6(p0, p1, p2) end

---@param p0 any
function VEHICLE._0xFF2B1F59FB892F14(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function VEHICLE._0x5AADC7BBBB1BCEEB(p0, p1, p2, p3, p4) end

---@param vehicle integer
---@return boolean
function VEHICLE._GET_VEHICLE_IS_PROP_SET_APPLIED(vehicle) end

---@param vehicle integer
---@param height number
---@param immediately boolean
function VEHICLE._SET_BATCH_TARP_HEIGHT(vehicle, height, immediately) end

---@param p0 any
---@param p1 any
function VEHICLE._0x07E2E21E799080A0(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function VEHICLE._0xC2E62678D602853C(p0, p1, p2, p3, p4, p5, p6) end

---@param p0 any
function VEHICLE._0x873AAF600CC36DAC(p0) end

---@param p0 any
---@return any
function VEHICLE._0x51C7694E140FAE43(p0) end

---@param p0 any
---@param p1 any
function VEHICLE._0x8DECD262602548B9(p0, p1) end

---@param p0 any
---@param p1 any
function VEHICLE._0xCBC7B6F9A56B79F6(p0, p1) end

---@param trackIndex integer
---@return boolean
function VEHICLE._0x37D238BE69F7378A(trackIndex) end

---@param p0 any
---@param p1 any
function VEHICLE._0x703D4FB366DA4452(p0, p1) end

---@param trainCarriage integer
---@param p1 boolean
function VEHICLE._0x762FDC4C19E5A981(trainCarriage, p1) end

---@param p0 any
---@return any
function VEHICLE._0x2045429505158D1A(p0) end

---@param p0 any
---@param p1 any
function VEHICLE._0x13EB275BF81636D1(p0, p1) end
