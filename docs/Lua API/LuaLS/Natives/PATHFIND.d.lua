---@meta

---@class PATHFIND
PATHFIND = {}

---@param VecMinCoorsX number
---@param VecMinCoorsY number
---@param VecMinCoorsZ number
---@param VecMaxCoorsX number
---@param VecMaxCoorsY number
---@param VecMaxCoorsZ number
---@param p6 any
---@param bNetwork boolean
---@param p8 any
function PATHFIND.SET_ROADS_IN_AREA(VecMinCoorsX, VecMinCoorsY, VecMinCoorsZ, VecMaxCoorsX, VecMaxCoorsY, VecMaxCoorsZ, p6, bNetwork, p8) end

---@param vVec1X number
---@param vVec1Y number
---@param vVec1Z number
---@param vVec2X number
---@param vVec2Y number
---@param vVec2Z number
---@param fAreaWidth number
---@param p7 any
---@param p8 any
---@param bNetwork boolean
---@param p10 any
function PATHFIND.SET_ROADS_IN_ANGLED_AREA(vVec1X, vVec1Y, vVec1Z, vVec2X, vVec2Y, vVec2Z, fAreaWidth, p7, p8, bNetwork, p10) end

---@param volume integer
---@param p1 boolean
---@param p2 boolean
---@param p3 boolean
function PATHFIND.SET_ROADS_IN_VOLUME(volume, p1, p2, p3) end

---@param volume integer
---@param p1 boolean
function PATHFIND.RESET_ROADS_IN_VOLUME(volume, p1) end

---@param VecCoorsMinX number
---@param VecCoorsMinY number
---@param VecCoorsMinZ number
---@param VecCoorsMaxX number
---@param VecCoorsMaxY number
---@param VecCoorsMaxZ number
---@param p6 any
---@param bNetwork boolean
function PATHFIND.SET_ROADS_BACK_TO_ORIGINAL(VecCoorsMinX, VecCoorsMinY, VecCoorsMinZ, VecCoorsMaxX, VecCoorsMaxY, VecCoorsMaxZ, p6, bNetwork) end

---@param vVec1X number
---@param vVec1Y number
---@param vVec1Z number
---@param vVec2X number
---@param vVec2Y number
---@param vVec2Z number
---@param fAreaWidth number
---@param p7 any
---@param bNetwork boolean
function PATHFIND.SET_ROADS_BACK_TO_ORIGINAL_IN_ANGLED_AREA(vVec1X, vVec1Y, vVec1Z, vVec2X, vVec2Y, vVec2Z, fAreaWidth, p7, bNetwork) end

---@param xMin number
---@param yMin number
---@param zMin number
---@param xMax number
---@param yMax number
---@param zMax number
---@param p6 integer
---@param p7 any
function PATHFIND._0xAFE2AE66F6251C66(xMin, yMin, zMin, xMax, yMax, zMax, p6, p7) end

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
function PATHFIND._0x4358BCF14C91761C(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param p0 any
---@param p1 any
---@param p2 any
function PATHFIND._0xB03944057FD735BA(p0, p1, p2) end

---@param xMin number
---@param yMin number
---@param zMin number
---@param xMax number
---@param yMax number
---@param zMax number
---@param p6 any
---@param p7 any
function PATHFIND._0x6C3F12ECEB6D2E2A(xMin, yMin, zMin, xMax, yMax, zMax, p6, p7) end

---@param p0 any
---@param p1 any
---@param p2 any
function PATHFIND._0x5A4E1A41E3A02AD0(p0, p1, p2) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param VecReturnNearestNodeCoors Vector3
---@param nodeFlags integer
---@param zMeasureMult number
---@param zTolerance number
---@return boolean
---@return Vector3
function PATHFIND.GET_CLOSEST_VEHICLE_NODE(VecCoorsX, VecCoorsY, VecCoorsZ, VecReturnNearestNodeCoors, nodeFlags, zMeasureMult, zTolerance) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@return any
function PATHFIND._0xCA27A86CAA4E98ED(p0, p1, p2, p3, p4, p5, p6) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param VecReturnNearestNodeCoors Vector3
---@param ReturnHeading number
---@param nodeFlags integer
---@param zMeasureMult number
---@param zTolerance number
---@return boolean
---@return Vector3
---@return number
function PATHFIND.GET_CLOSEST_VEHICLE_NODE_WITH_HEADING(VecCoorsX, VecCoorsY, VecCoorsZ, VecReturnNearestNodeCoors, ReturnHeading, nodeFlags, zMeasureMult, zTolerance) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param NodeNumber integer
---@param VecReturnNearestNodeCoors Vector3
---@param nodeFlags integer
---@param zMeasureMult number
---@param zTolerance number
---@return boolean
---@return Vector3
function PATHFIND.GET_NTH_CLOSEST_VEHICLE_NODE(VecCoorsX, VecCoorsY, VecCoorsZ, NodeNumber, VecReturnNearestNodeCoors, nodeFlags, zMeasureMult, zTolerance) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param NodeNumber integer
---@param nodeFlags integer
---@param zMeasureMult number
---@param zTolerance number
---@return integer
function PATHFIND.GET_NTH_CLOSEST_VEHICLE_NODE_ID(VecCoorsX, VecCoorsY, VecCoorsZ, NodeNumber, nodeFlags, zMeasureMult, zTolerance) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param NodeNumber integer
---@param VecReturnNearestNodeCoors Vector3
---@param ReturnHeading number
---@param ReturnNumLanes integer
---@param nodeFlags integer
---@param zMeasureMult number
---@param zTolerance number
---@return boolean
---@return Vector3
---@return number
---@return integer
function PATHFIND.GET_NTH_CLOSEST_VEHICLE_NODE_WITH_HEADING(VecCoorsX, VecCoorsY, VecCoorsZ, NodeNumber, VecReturnNearestNodeCoors, ReturnHeading, ReturnNumLanes, nodeFlags, zMeasureMult, zTolerance) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param NodeNumber integer
---@param ReturnHeading number
---@param ReturnNumLanes integer
---@param nodeFlags integer
---@param zMeasureMult number
---@param zTolerance number
---@return integer
---@return number
---@return integer
function PATHFIND.GET_NTH_CLOSEST_VEHICLE_NODE_ID_WITH_HEADING(VecCoorsX, VecCoorsY, VecCoorsZ, NodeNumber, ReturnHeading, ReturnNumLanes, nodeFlags, zMeasureMult, zTolerance) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param FaceCoorsX number
---@param FaceCoorsY number
---@param FaceCoorsZ number
---@param NodeNumber integer
---@param VecReturnNearestNodeCoors Vector3
---@param ReturnHeading number
---@param nodeFlags integer
---@param zMeasureMult number
---@param zTolerance number
---@return boolean
---@return Vector3
---@return number
function PATHFIND.GET_NTH_CLOSEST_VEHICLE_NODE_FAVOUR_DIRECTION(VecCoorsX, VecCoorsY, VecCoorsZ, FaceCoorsX, FaceCoorsY, FaceCoorsZ, NodeNumber, VecReturnNearestNodeCoors, ReturnHeading, nodeFlags, zMeasureMult, zTolerance) end

---@param NodeId integer
---@return boolean
function PATHFIND.IS_VEHICLE_NODE_ID_VALID(NodeId) end

---@param nodeId integer
---@param VecNodePosition Vector3
---@return Vector3
function PATHFIND.GET_VEHICLE_NODE_POSITION(nodeId, VecNodePosition) end

---@param nodeId integer
---@return boolean
function PATHFIND.GET_VEHICLE_NODE_IS_SWITCHED_OFF(nodeId) end

---@param TestCoorsX number
---@param TestCoorsY number
---@param TestCoorsZ number
---@param MinLength number
---@param MinLanes integer
---@param SouthEndNode Vector3
---@param NorthEndNode Vector3
---@param LanesGoingSouth integer
---@param LanesGoingNorth integer
---@param CentralReservationWidth number
---@param bIgnoreSwitchedOffNodes boolean
---@return boolean
---@return Vector3
---@return Vector3
---@return integer
---@return integer
---@return number
function PATHFIND.GET_CLOSEST_ROAD(TestCoorsX, TestCoorsY, TestCoorsZ, MinLength, MinLanes, SouthEndNode, NorthEndNode, LanesGoingSouth, LanesGoingNorth, CentralReservationWidth, bIgnoreSwitchedOffNodes) end

---@param MinX number
---@param MinY number
---@param MaxX number
---@param MaxY number
---@return boolean
function PATHFIND.ARE_NODES_LOADED_FOR_AREA(MinX, MinY, MaxX, MaxY) end

---@param MinX number
---@param MinY number
---@param MaxX number
---@param MaxY number
---@return boolean
function PATHFIND.REQUEST_PATH_NODES_IN_AREA_THIS_FRAME(MinX, MinY, MaxX, MaxY) end

---@param centrePointX number
---@param centrePointY number
---@param centrePointZ number
---@param radius number
---@param MinLanes integer
---@param bAvoidDeadEnds boolean
---@param bAvoidHighways boolean
---@param vecReturn Vector3
---@param NodeAddress integer
---@return boolean
---@return Vector3
---@return integer
function PATHFIND.GET_RANDOM_VEHICLE_NODE(centrePointX, centrePointY, centrePointZ, radius, MinLanes, bAvoidDeadEnds, bAvoidHighways, vecReturn, NodeAddress) end

---@param nodeId integer
---@param x number
---@param y number
---@param z number
---@param outCoords Vector3
---@param heading number
---@return Vector3
---@return number
function PATHFIND._GET_SPAWN_DATA_FOR_ROAD_NODE(nodeId, x, y, z, outCoords, heading) end

---@param vPosX number
---@param vPosY number
---@param vPosZ number
---@param VehicleIndex integer
---@return boolean
function PATHFIND.IS_POINT_ON_ROAD(vPosX, vPosY, vPosZ, VehicleIndex) end

---@param VecMinCoorsX number
---@param VecMinCoorsY number
---@param VecMinCoorsZ number
---@param VecMaxCoorsX number
---@param VecMaxCoorsY number
---@param VecMaxCoorsZ number
---@param bActive boolean
---@param bForceAbortCurrentPath boolean
function PATHFIND.SET_PED_PATHS_IN_AREA(VecMinCoorsX, VecMinCoorsY, VecMinCoorsZ, VecMaxCoorsX, VecMaxCoorsY, VecMaxCoorsZ, bActive, bForceAbortCurrentPath) end

---@param p0 any
---@param p1 any
---@param p2 any
function PATHFIND._0xE5EF9DE716FF737E(p0, p1, p2) end

---@param VecCoorsX number
---@param VecCoorsY number
---@param VecCoorsZ number
---@param bOnlyOnPavement boolean
---@param VecReturnSafeCoors Vector3
---@param iFlags integer
---@return boolean
---@return Vector3
function PATHFIND.GET_SAFE_COORD_FOR_PED(VecCoorsX, VecCoorsY, VecCoorsZ, bOnlyOnPavement, VecReturnSafeCoors, iFlags) end

---@param VecCoorsMinX number
---@param VecCoorsMinY number
---@param VecCoorsMinZ number
---@param VecCoorsMaxX number
---@param VecCoorsMaxY number
---@param VecCoorsMaxZ number
---@param bForceAbortCurrentPath boolean
function PATHFIND.SET_PED_PATHS_BACK_TO_ORIGINAL(VecCoorsMinX, VecCoorsMinY, VecCoorsMinZ, VecCoorsMaxX, VecCoorsMaxY, VecCoorsMaxZ, bForceAbortCurrentPath) end

---@param p0 any
---@param p1 any
---@param p2 any
function PATHFIND._0xCF213A5FC3ABFC08(p0, p1, p2) end

---@param x number
---@param y number
---@param radius number
function PATHFIND.ADD_NAVMESH_REQUIRED_REGION(x, y, radius) end

---@param vMinX number
---@param vMinY number
---@param vMinZ number
---@param vMaxX number
---@param vMaxY number
---@param vMaxZ number
---@return boolean
function PATHFIND.IS_NAVMESH_LOADED_IN_AREA(vMinX, vMinY, vMinZ, vMaxX, vMaxY, vMaxZ) end

---@param vMinX number
---@param vMinY number
---@param vMinZ number
---@param vMaxX number
---@param vMaxY number
---@param vMaxZ number
---@return integer
function PATHFIND.GET_NUM_NAVMESHES_EXISTING_IN_AREA(vMinX, vMinY, vMinZ, vMaxX, vMaxY, vMaxZ) end

---@param name any
---@return boolean
function PATHFIND._NAVMESH_ACTIVATE_SWAP(name) end

---@param name any
---@return boolean
function PATHFIND._NAVMESH_DEACTIVATE_SWAP(name) end

---@param name any
---@return boolean
function PATHFIND._NAVMESH_IS_SWAP_ACTIVE(name) end

---@param name any
---@return boolean
function PATHFIND._NAVMESH_DOES_SWAP_EXIST(name) end

---@param p0 any
---@return integer
function PATHFIND._0x5A3B54ADDF5472A3(p0) end

---@param p0 any
---@param p1 integer
---@return integer
function PATHFIND._0xA33914B00CA55756(p0, p1) end

---@param vehicle integer
---@param navMeshName any
---@return boolean
function PATHFIND._NAVMESH_ASSIGN_NAVMESH_TO_VEHICLE(vehicle, navMeshName) end

---@param vPositionX number
---@param vPositionY number
---@param vPositionZ number
---@param vSizeXYZX number
---@param vSizeXYZY number
---@param vSizeXYZZ number
---@param fHeading number
---@param bPermanent boolean
---@param iFlags integer
---@return integer
function PATHFIND.ADD_NAVMESH_BLOCKING_OBJECT(vPositionX, vPositionY, vPositionZ, vSizeXYZX, vSizeXYZY, vSizeXYZZ, fHeading, bPermanent, iFlags) end

---@param iObjectId integer
function PATHFIND.REMOVE_NAVMESH_BLOCKING_OBJECT(iObjectId) end

---@param iObjectId integer
---@return boolean
function PATHFIND.DOES_NAVMESH_BLOCKING_OBJECT_EXIST(iObjectId) end

---@param volume integer
---@param flags integer
---@return boolean
function PATHFIND._ADD_NAVMESH_BLOCKING_VOLUME(volume, flags) end

---@param volume integer
function PATHFIND._REMOVE_NAVMESH_BLOCKING_VOLUME(volume) end

---@param volume integer
---@return boolean
function PATHFIND._DOES_NAVMESH_BLOCKING_VOLUME_EXIST(volume) end

---@param p0 any
---@param p1 any
function PATHFIND._0x6DAD6630AE4A74CB(p0, p1) end

---@param ped integer
---@param x1 number
---@param y1 number
---@param z1 number
---@param x2 number
---@param y2 number
---@param z2 number
---@param bitFlag integer
---@return integer
function PATHFIND.NAVMESH_REQUEST_PATH(ped, x1, y1, z1, x2, y2, z2, bitFlag) end

---@param path integer
---@return boolean
function PATHFIND._NAVMESH_CLEAR_REQUESTED_PATH(path) end

---@param path integer
---@return integer
function PATHFIND._NAVMESH_REQUESTED_QUERY_STATUS(path) end

---@param path integer
---@return boolean
function PATHFIND._NAVMESH_REQUESTED_PATH_WAYPOINTS_FOUND(path) end

---@param path integer
---@return integer
function PATHFIND._NAVMESH_REQUESTED_PATH_WAYPOINTS_TERRAIN(path) end

---@param path integer
---@return integer
function PATHFIND._NAVMESH_REQUESTED_PATH_NUM_WAYPOINTS(path) end

---@param path integer
---@param waypointIndex integer
---@return Vector3
function PATHFIND._NAVMESH_REQUESTED_PATH_WAYPOINT_BY_INDEX(path, waypointIndex) end

---@param x number
---@param y number
---@return number
function PATHFIND.GET_APPROX_FLOOR_FOR_POINT(x, y) end

---@param fMultiplier number
function PATHFIND.SET_AMBIENT_PED_RANGE_MULTIPLIER_THIS_FRAME(fMultiplier) end

---@param bIgnore boolean
function PATHFIND.SET_IGNORE_NO_GPS_FLAG(bIgnore) end

---@return integer
function PATHFIND.GET_GPS_BLIP_ROUTE_LENGTH() end

---@param p0 any
---@return any
function PATHFIND._0xEFC535C9FAF563B3(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function PATHFIND._0x665B21666351CB37(p0, p1, p2) end

---@return boolean
function PATHFIND.GET_GPS_BLIP_ROUTE_FOUND() end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@return any
function PATHFIND._0x54F4D7B6670FBB5A(p0, p1, p2, p3, p4) end

---@param p0 any
function PATHFIND._0x34C9AF25649172D0(p0) end

---@param volume integer
---@param p1 integer
---@param p2 integer
function PATHFIND._0xF2A2177AC848B3A8(volume, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function PATHFIND._0x4BDEBEA5702B97A9(p0, p1, p2, p3, p4, p5) end

---@param p0 any
function PATHFIND._0x264E9A5CD78C338F(p0) end

---@param p0 any
function PATHFIND._0x869A7015BD4606E9(p0) end

---@param x1 number
---@param y1 number
---@param z1 number
---@param x2 number
---@param y2 number
---@param z2 number
---@param p6 integer
---@return any
function PATHFIND._SIMULATED_ROUTE_CREATE(x1, y1, z1, x2, y2, z2, p6) end

---@param p0 any
function PATHFIND._SIMULATED_ROUTE_DELETE(p0) end

---@param p0 any
---@return boolean
function PATHFIND._SIMULATED_ROUTE_EXISTS(p0) end

---@param p0 any
---@return boolean
function PATHFIND.SIMULATED_ROUTE_IS_LOADED(p0) end

---@param p0 any
---@param p1 number
---@param p2 number
function PATHFIND.SIMULATED_ROUTE_TRAVEL_TO_POINT(p0, p1, p2) end

---@param p0 any
---@return number
function PATHFIND.SIMULATED_ROUTE_GET_ETA(p0) end
