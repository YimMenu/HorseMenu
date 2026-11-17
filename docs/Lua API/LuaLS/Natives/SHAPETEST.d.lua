---@meta

---@class SHAPETEST
SHAPETEST = {}

---@param VecStartPosX number
---@param VecStartPosY number
---@param VecStartPosZ number
---@param VecEndPosX number
---@param VecEndPosY number
---@param VecEndPosZ number
---@param LOSFlags integer
---@param ExcludeEntityIndex integer
---@param Options integer
---@return integer
function SHAPETEST.START_SHAPE_TEST_LOS_PROBE(VecStartPosX, VecStartPosY, VecStartPosZ, VecEndPosX, VecEndPosY, VecEndPosZ, LOSFlags, ExcludeEntityIndex, Options) end

---@param p0 any
---@param p1 any
---@return any
function SHAPETEST._0x04AA59CA40571C2E(p0, p1) end

---@param VecStartPosX number
---@param VecStartPosY number
---@param VecStartPosZ number
---@param VecEndPosX number
---@param VecEndPosY number
---@param VecEndPosZ number
---@param LOSFlags integer
---@param ExcludeEntityIndex integer
---@param Options integer
---@return integer
function SHAPETEST.START_EXPENSIVE_SYNCHRONOUS_SHAPE_TEST_LOS_PROBE(VecStartPosX, VecStartPosY, VecStartPosZ, VecEndPosX, VecEndPosY, VecEndPosZ, LOSFlags, ExcludeEntityIndex, Options) end

---@param scrVecPosX number
---@param scrVecPosY number
---@param scrVecPosZ number
---@param scrVecDimsX number
---@param scrVecDimsY number
---@param scrVecDimsZ number
---@param eulerAnglesX number
---@param eulerAnglesY number
---@param eulerAnglesZ number
---@param RotOrder integer
---@param LOSFlags integer
---@param ExcludeEntityIndex integer
---@param Options integer
---@return integer
function SHAPETEST.START_SHAPE_TEST_BOX(scrVecPosX, scrVecPosY, scrVecPosZ, scrVecDimsX, scrVecDimsY, scrVecDimsZ, eulerAnglesX, eulerAnglesY, eulerAnglesZ, RotOrder, LOSFlags, ExcludeEntityIndex, Options) end

---@param scrVecPosX number
---@param scrVecPosY number
---@param scrVecPosZ number
---@param scrVecEndPosX number
---@param scrVecEndPosY number
---@param scrVecEndPosZ number
---@param fRadius number
---@param LOSFlags integer
---@param ExcludeEntityIndex integer
---@param Options integer
---@return integer
function SHAPETEST.START_SHAPE_TEST_CAPSULE(scrVecPosX, scrVecPosY, scrVecPosZ, scrVecEndPosX, scrVecEndPosY, scrVecEndPosZ, fRadius, LOSFlags, ExcludeEntityIndex, Options) end

---@param scrVecPosX number
---@param scrVecPosY number
---@param scrVecPosZ number
---@param scrVecEndPosX number
---@param scrVecEndPosY number
---@param scrVecEndPosZ number
---@param fRadius number
---@param LOSFlags integer
---@param ExcludeEntityIndex integer
---@param Options integer
---@return integer
function SHAPETEST.START_SHAPE_TEST_SWEPT_SPHERE(scrVecPosX, scrVecPosY, scrVecPosZ, scrVecEndPosX, scrVecEndPosY, scrVecEndPosZ, fRadius, LOSFlags, ExcludeEntityIndex, Options) end

---@param vProbeStartPosOut Vector3
---@param vProbeEndPosOut Vector3
---@param LOSFlags integer
---@param ExcludeEntityIndex integer
---@param Options integer
---@return integer
---@return Vector3
---@return Vector3
function SHAPETEST.START_SHAPE_TEST_MOUSE_CURSOR_LOS_PROBE(vProbeStartPosOut, vProbeEndPosOut, LOSFlags, ExcludeEntityIndex, Options) end

---@param shapeTestGuid integer
---@param bHitSomething integer
---@param vPos Vector3
---@param vNormal Vector3
---@param EntityIndex integer
---@return integer
---@return integer
---@return Vector3
---@return Vector3
---@return integer
function SHAPETEST.GET_SHAPE_TEST_RESULT(shapeTestGuid, bHitSomething, vPos, vNormal, EntityIndex) end
