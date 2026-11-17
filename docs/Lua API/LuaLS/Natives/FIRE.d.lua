---@meta

---@class FIRE
FIRE = {}

---@param VecPosX number
---@param VecPosY number
---@param VecPosZ number
---@param GenerationsAllowed integer
---@param p4 number
---@param p5 boolean
---@param soundsetName any
---@param p7 number
---@param p8 integer
---@return integer
function FIRE.START_SCRIPT_FIRE(VecPosX, VecPosY, VecPosZ, GenerationsAllowed, p4, p5, soundsetName, p7, p8) end

---@param FireIndex integer
function FIRE.REMOVE_SCRIPT_FIRE(FireIndex) end

---@param EntityIndex integer
---@param p1 any
---@param p2 any
---@param p3 any
function FIRE.START_ENTITY_FIRE(EntityIndex, p1, p2, p3) end

---@param EntityIndex integer
---@param p1 any
function FIRE.STOP_ENTITY_FIRE(EntityIndex, p1) end

---@param EntityIndex integer
---@return boolean
function FIRE.IS_ENTITY_ON_FIRE(EntityIndex) end

---@param p0 any
function FIRE._0x754937C28271BC65(p0) end

---@param VecPosX number
---@param VecPosY number
---@param VecPosZ number
---@param Radius number
---@return integer
function FIRE.GET_NUMBER_OF_FIRES_IN_RANGE(VecPosX, VecPosY, VecPosZ, Radius) end

---@param VecPosX number
---@param VecPosY number
---@param VecPosZ number
---@param fRadius number
function FIRE.STOP_FIRE_IN_RANGE(VecPosX, VecPosY, VecPosZ, fRadius) end

---@param posX number
---@param posY number
---@param posZ number
---@param rotX number
---@param rotY number
---@param rotZ number
---@param scaleX number
---@param scaleY number
---@param scaleZ number
function FIRE._STOP_FIRE_IN_BOX(posX, posY, posZ, rotX, rotY, rotZ, scaleX, scaleY, scaleZ) end

---@param VecClosestFirePos Vector3
---@param VecTestPosX number
---@param VecTestPosY number
---@param VecTestPosZ number
---@return boolean
---@return Vector3
function FIRE.GET_CLOSEST_FIRE_POS(VecClosestFirePos, VecTestPosX, VecTestPosY, VecTestPosZ) end

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
---@return any
function FIRE._0x559FC1D310813031(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

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
---@return any
function FIRE._0x41B87A6495EE13DD(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param p0 any
---@return any
function FIRE._0xA4454592DCF7C992(p0) end

---@param entity integer
---@return boolean
function FIRE._IS_ENTITY_CONSUMED_BY_FIRE(entity) end

---@param VecExplosionPosX number
---@param VecExplosionPosY number
---@param VecExplosionPosZ number
---@param ExplosionTag integer
---@param SizeScale number
---@param bMakeSound boolean
---@param bNoFx boolean
---@param CamShakeMultiplier number
function FIRE.ADD_EXPLOSION(VecExplosionPosX, VecExplosionPosY, VecExplosionPosZ, ExplosionTag, SizeScale, bMakeSound, bNoFx, CamShakeMultiplier) end

---@param ExplosionOwner integer
---@param VecExplosionPosX number
---@param VecExplosionPosY number
---@param VecExplosionPosZ number
---@param ExplosionTag integer
---@param SizeScale number
---@param bMakeSound boolean
---@param bNoFx boolean
---@param CamShakeMultiplier number
function FIRE.ADD_OWNED_EXPLOSION(ExplosionOwner, VecExplosionPosX, VecExplosionPosY, VecExplosionPosZ, ExplosionTag, SizeScale, bMakeSound, bNoFx, CamShakeMultiplier) end

---@param entity integer
---@param p1 integer
---@param x number
---@param y number
---@param z number
---@param explosionType integer
---@param damageScale number
---@param isAudible boolean
---@param isInvisible boolean
---@param cameraShake number
function FIRE._0xB7DF150605EEDC9B(entity, p1, x, y, z, explosionType, damageScale, isAudible, isInvisible, cameraShake) end

---@param VecExplosionPosX number
---@param VecExplosionPosY number
---@param VecExplosionPosZ number
---@param ExplosionTag integer
---@param VfxTagHash integer
---@param SizeScale number
---@param bMakeSound boolean
---@param bNoFx boolean
---@param CamShakeMultiplier number
function FIRE.ADD_EXPLOSION_WITH_USER_VFX(VecExplosionPosX, VecExplosionPosY, VecExplosionPosZ, ExplosionTag, VfxTagHash, SizeScale, bMakeSound, bNoFx, CamShakeMultiplier) end

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
function FIRE._0x34AE85C7CA4857AA(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) end

---@param ExplosionTag integer
---@param VecPosMinX number
---@param VecPosMinY number
---@param VecPosMinZ number
---@param VecPosMaxX number
---@param VecPosMaxY number
---@param VecPosMaxZ number
---@return boolean
function FIRE.IS_EXPLOSION_IN_AREA(ExplosionTag, VecPosMinX, VecPosMinY, VecPosMinZ, VecPosMaxX, VecPosMaxY, VecPosMaxZ) end

---@param ExplosionTag integer
---@param VecPosMinX number
---@param VecPosMinY number
---@param VecPosMinZ number
---@param VecPosMaxX number
---@param VecPosMaxY number
---@param VecPosMaxZ number
---@return boolean
function FIRE.IS_EXPLOSION_ACTIVE_IN_AREA(ExplosionTag, VecPosMinX, VecPosMinY, VecPosMinZ, VecPosMaxX, VecPosMaxY, VecPosMaxZ) end

---@param ExplosionTag integer
---@param VecCentrePosX number
---@param VecCentrePosY number
---@param VecCentrePosZ number
---@param Radius number
---@return boolean
function FIRE.IS_EXPLOSION_IN_SPHERE(ExplosionTag, VecCentrePosX, VecCentrePosY, VecCentrePosZ, Radius) end

---@param ExplosionTag integer
---@param VecPos1X number
---@param VecPos1Y number
---@param VecPos1Z number
---@param VecPos2X number
---@param VecPos2Y number
---@param VecPos2Z number
---@param AreaWidth number
---@return boolean
function FIRE.IS_EXPLOSION_IN_ANGLED_AREA(ExplosionTag, VecPos1X, VecPos1Y, VecPos1Z, VecPos2X, VecPos2Y, VecPos2Z, AreaWidth) end

---@param explosionType integer
---@param volume integer
---@return boolean
function FIRE._IS_EXPLOSION_IN_VOLUME(explosionType, volume) end

---@param ExplosionTag integer
---@param VecPos1X number
---@param VecPos1Y number
---@param VecPos1Z number
---@param VecPos2X number
---@param VecPos2Y number
---@param VecPos2Z number
---@param AreaWidth number
---@return integer
function FIRE.GET_OWNER_OF_EXPLOSION_IN_ANGLED_AREA(ExplosionTag, VecPos1X, VecPos1Y, VecPos1Z, VecPos2X, VecPos2Y, VecPos2Z, AreaWidth) end

---@param x number
---@param y number
---@param z number
---@param p3 number
function FIRE._0x68F6A75FDF5A70D6(x, y, z, p3) end

---@param p0 number
function FIRE._0x24DB6B9F2B719043(p0) end

---@param ped integer
---@param p1 integer
---@return boolean
function FIRE._IS_PED_SHOCKING_EVENT_ACTIVE(ped, p1) end
