---@meta

---@class WEAPON
WEAPON = {}

---@param weaponHash integer
---@return integer
function WEAPON._GET_WEAPON_UNLOCK(weaponHash) end

---@param ped integer
---@param weaponHash integer
---@param amount integer
---@param addReason integer
function WEAPON._ADD_AMMO_TO_PED(ped, weaponHash, amount, addReason) end

---@param ped integer
---@param ammoType integer
---@param amount integer
---@param addReason integer
function WEAPON._ADD_AMMO_TO_PED_BY_TYPE(ped, ammoType, amount, addReason) end

---@param ped integer
---@param weaponHash integer
---@param amount integer
---@param removeReason integer
function WEAPON._REMOVE_AMMO_FROM_PED(ped, weaponHash, amount, removeReason) end

---@param ped integer
---@param ammoHash integer
---@param amount integer
---@param removeReason integer
function WEAPON._REMOVE_AMMO_FROM_PED_BY_TYPE(ped, ammoHash, amount, removeReason) end

---@param ped integer
function WEAPON._REMOVE_ALL_PED_AMMO(ped) end

---@param PedIndex integer
---@param TypeOfWeapon integer
---@param AmountOfAmmo integer
function WEAPON.SET_PED_AMMO(PedIndex, TypeOfWeapon, AmountOfAmmo) end

---@param ped integer
---@param p1 boolean
---@param p2 integer
function WEAPON._0x8A779706DA5CA3DD(ped, p1, p2) end

---@param vehicle integer
---@param p1 boolean
function WEAPON._0x9409C62504A8F9E9(vehicle, p1) end

---@param vehicle integer
---@param p1 integer
---@param minHeading number
---@param maxHeading number
function WEAPON._SET_VEHICLE_WEAPON_HEADING_LIMITS(vehicle, p1, minHeading, maxHeading) end

---@param vehicle integer
---@param p1 integer
---@param minHeading number
---@param maxHeading number
---@return any
function WEAPON._SET_VEHICLE_WEAPON_HEADING_LIMITS_2(vehicle, p1, minHeading, maxHeading) end

---@param vehicle integer
---@param seatIndex integer
---@param heading number
---@param p3 boolean
function WEAPON.SET_VEHICLE_WEAPON_HEADING(vehicle, seatIndex, heading, p3) end

---@param PedIndex integer
---@param Infinite boolean
---@param TypeOfWeapon integer
function WEAPON.SET_PED_INFINITE_AMMO(PedIndex, Infinite, TypeOfWeapon) end

---@param ped integer
---@param toggle boolean
function WEAPON._SET_PED_INFINITE_AMMO_CLIP(ped, toggle) end

---@param PedIndex integer
---@param TypeOfWeapon integer
---@return integer
function WEAPON.GET_AMMO_IN_PED_WEAPON(PedIndex, TypeOfWeapon) end

---@param PedIndex integer
---@param WeaponType integer
---@param DoDeadCheck boolean
---@return integer
function WEAPON.GET_MAX_AMMO_IN_CLIP(PedIndex, WeaponType, DoDeadCheck) end

---@param PedIndex integer
---@param ReturnAmmoInClip integer
---@param WeaponType integer
---@return boolean
---@return integer
function WEAPON.GET_AMMO_IN_CLIP(PedIndex, ReturnAmmoInClip, WeaponType) end

---@param ped integer
---@param ammo integer
---@param inventoryUid integer
---@return boolean
---@return integer
function WEAPON._GET_AMMO_IN_CLIP_BY_INVENTORY_UID(ped, ammo, inventoryUid) end

---@param PedIndex integer
---@param WeaponType integer
---@param AmmoInClip integer
---@return boolean
function WEAPON.SET_AMMO_IN_CLIP(PedIndex, WeaponType, AmmoInClip) end

---@param ped integer
---@param clipInventoryUid integer
---@param p2 integer
---@return any
function WEAPON._REFILL_AMMO_IN_CLIP(ped, clipInventoryUid, p2) end

---@param PedIndex integer
---@param ReturnMaxAmmo integer
---@param WeaponType integer
---@return boolean
---@return integer
function WEAPON.GET_MAX_AMMO(PedIndex, ReturnMaxAmmo, WeaponType) end

---@param PedIndex integer
---@param AmmoType integer
---@param AmmoAmount integer
function WEAPON.SET_PED_AMMO_BY_TYPE(PedIndex, AmmoType, AmmoAmount) end

---@param PedIndex integer
---@param AmmoType integer
---@return integer
function WEAPON.GET_PED_AMMO_BY_TYPE(PedIndex, AmmoType) end

---@param PedIndex integer
---@param MinAmount integer
---@param MaxAmount integer
function WEAPON.SET_PED_AMMO_TO_DROP(PedIndex, MinAmount, MaxAmount) end

---@param weaponHash integer
---@return integer
function WEAPON._GET_AMMO_TYPE_FOR_WEAPON(weaponHash) end

---@param PedIndex integer
---@param WeaponType integer
---@return integer
function WEAPON.GET_PED_AMMO_TYPE_FROM_WEAPON(PedIndex, WeaponType) end

---@param ammoType integer
---@return integer
function WEAPON._GET_WEAPON_TYPE_FROM_AMMO_TYPE(ammoType) end

---@param componentHash integer
---@return integer
function WEAPON._GET_WEAPON_COMPONENT_TYPE_MODEL(componentHash) end

---@param weaponHash integer
---@return integer
function WEAPON._GET_WEAPONTYPE_MODEL(weaponHash) end

---@param weaponHash integer
---@return integer
function WEAPON._GET_WEAPONTYPE_SLOT(weaponHash) end

---@param weapon integer
---@return integer
function WEAPON.GET_WEAPONTYPE_GROUP(weapon) end

---@param weaponGroupHash integer
---@param p1 number
---@param p2 number
---@param p3 any
---@return integer
function WEAPON._0xF8204EF17410BF43(weaponGroupHash, p1, p2, p3) end

---@param weaponHash integer
---@return boolean
function WEAPON._IS_WEAPON_KIT(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON._IS_WEAPON_KIT_2(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON.IS_WEAPON_BOW(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON._IS_WEAPON_LANTERN(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON._IS_WEAPON_TORCH(weaponHash) end

---@param ped integer
---@param data integer
---@param outData integer
---@return boolean
function WEAPON.GIVE_WEAPON_TO_PED_WITH_OPTIONS(ped, data, outData) end

---@param ped integer
---@param weaponHash integer
---@param ammoCount integer
---@param bForceInHand boolean
---@param bForceInHolster boolean
---@param attachPoint integer
---@param bAllowMultipleCopies boolean
---@param p7 number
---@param p8 number
---@param addReason integer
---@param bIgnoreUnlocks boolean
---@param permanentDegradation number
---@param p12 boolean
---@return integer
function WEAPON.GIVE_WEAPON_TO_PED(ped, weaponHash, ammoCount, bForceInHand, bForceInHolster, attachPoint, bAllowMultipleCopies, p7, p8, addReason, bIgnoreUnlocks, permanentDegradation, p12) end

---@param ped integer
---@param attachPoint integer
function WEAPON._SET_FORCE_CURRENT_WEAPON_INTO_COCKED_STATE(ped, attachPoint) end

---@param p0 boolean
---@return any
function WEAPON._0x9F0E1892C7F228A8(p0) end

---@param ped integer
---@param p1 boolean
---@param p2 boolean
---@param p3 boolean
---@param immediately boolean
function WEAPON._HOLSTER_PED_WEAPONS(ped, p1, p2, p3, immediately) end

---@param ped integer
---@param p0 integer
---@param immediately boolean
function WEAPON._HIDE_PED_WEAPONS(ped, p0, immediately) end

---@param p0 any
---@param p1 any
function WEAPON._0x4820A6939D7CEF28(p0, p1) end

---@param PedIndex integer
---@param TypeOfWeapon integer
---@param bForceInHand boolean
---@param attachPoint integer
---@param p4 boolean
---@param p5 boolean
function WEAPON.SET_CURRENT_PED_WEAPON(PedIndex, TypeOfWeapon, bForceInHand, attachPoint, p4, p5) end

---@param PedIndex integer
---@param ReturnWeaponType integer
---@param DoDeadCheck boolean
---@param attachPoint integer
---@param p4 boolean
---@return boolean
---@return integer
function WEAPON.GET_CURRENT_PED_WEAPON(PedIndex, ReturnWeaponType, DoDeadCheck, attachPoint, p4) end

---@param PedIndex integer
---@param attachPoint integer
---@return integer
function WEAPON.GET_CURRENT_PED_WEAPON_ENTITY_INDEX(PedIndex, attachPoint) end

---@param ped integer
---@return boolean
function WEAPON._ENABLE_WEAPON_RESTORE(ped) end

---@param ped integer
---@param p1 boolean
---@return integer
function WEAPON.GET_PED_BACKUP_WEAPON(ped, p1) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0x486C96A0DCD2BC92(p0, p1) end

---@param ped integer
---@param p1 boolean
---@param p2 boolean
---@param p3 boolean
---@return integer
function WEAPON._GET_PED_WORST_WEAPON(ped, p1, p2, p3) end

---@param PedIndex integer
---@param p1 boolean
---@param p2 boolean
---@return integer
function WEAPON.GET_BEST_PED_WEAPON(PedIndex, p1, p2) end

---@param ped integer
---@param p1 any
---@param guidPrimary integer
---@return any
function WEAPON._GET_BEST_PED_WEAPON_IN_INVENTORY(ped, p1, guidPrimary) end

---@param ped integer
---@param outGUID integer
---@param p2 boolean
---@param p3 boolean
function WEAPON.GET_BEST_PED_SHORTARM_GUID(ped, outGUID, p2, p3) end

---@param ped integer
---@param attachPoint integer
---@param weaponGuid integer
---@return boolean
function WEAPON.GET_PED_WEAPON_GUID_AT_ATTACH_POINT(ped, attachPoint, weaponGuid) end

---@param ped integer
---@param weaponGroup integer
---@param p2 boolean
---@param p3 boolean
---@return integer
function WEAPON._GET_BEST_PED_WEAPON_IN_GROUP(ped, weaponGroup, p2, p3) end

---@param ped integer
---@return integer
function WEAPON._GET_DEFAULT_UNARMED_WEAPON_HASH(ped) end

---@param vehicle integer
---@param turretHash integer
---@param ammo integer
function WEAPON._SET_AMMO_IN_TURRET(vehicle, turretHash, ammo) end

---@param PedIndex integer
---@param TypeOfWeapon integer
---@return boolean
function WEAPON.SET_CURRENT_PED_VEHICLE_WEAPON(PedIndex, TypeOfWeapon) end

---@param PedIndex integer
---@param ReturnWeaponType integer
---@return boolean
---@return integer
function WEAPON.GET_CURRENT_PED_VEHICLE_WEAPON(PedIndex, ReturnWeaponType) end

---@param ped integer
---@param flags integer
---@return boolean
function WEAPON.IS_PED_ARMED(ped, flags) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0xA2091482ED42EF85(p0, p1) end

---@param ped integer
---@return boolean
function WEAPON._IS_WEAPON_HOLSTER_STATE_CHANGING(ped) end

---@param TypeOfWeapon integer
---@return boolean
function WEAPON.IS_WEAPON_VALID(TypeOfWeapon) end

---@param ammoHash integer
---@return boolean
function WEAPON._IS_AMMO_VALID(ammoHash) end

---@param p0 any
---@return any
function WEAPON._0x23BF601A42F329A0(p0) end

---@param ped integer
---@param weaponHash integer
---@return boolean
function WEAPON.IS_PED_CARRYING_WEAPON(ped, weaponHash) end

---@param PedIndex integer
---@param TypeOfWeapon integer
---@param GeneralWeaponType integer
---@param p3 boolean
---@return boolean
function WEAPON.HAS_PED_GOT_WEAPON(PedIndex, TypeOfWeapon, GeneralWeaponType, p3) end

---@param ped integer
---@param weapon integer
---@return boolean
function WEAPON._0x07E1C35F0078C3F9(ped, weapon) end

---@param PedIndex integer
---@return boolean
function WEAPON.IS_PED_WEAPON_READY_TO_SHOOT(PedIndex) end

---@param ped integer
---@param slotHash integer
---@return integer
function WEAPON._GET_PED_WEAPON_IN_SLOT(ped, slotHash) end

---@param PedIndex integer
---@param TypeOfWeapon integer
---@param AmountOfAmmo integer
---@param bSetAsCurrentWeapon boolean
---@param addReason integer
function WEAPON.GIVE_DELAYED_WEAPON_TO_PED(PedIndex, TypeOfWeapon, AmountOfAmmo, bSetAsCurrentWeapon, addReason) end

---@param PedIndex integer
---@param p1 boolean
---@param p2 boolean
function WEAPON.REMOVE_ALL_PED_WEAPONS(PedIndex, p1, p2) end

---@param PedIndex integer
---@param TypeOfWeapon integer
---@param p2 boolean
---@param removeReason integer
function WEAPON.REMOVE_WEAPON_FROM_PED(PedIndex, TypeOfWeapon, p2, removeReason) end

---@param ped integer
---@param weaponGuid integer
---@param removeReason integer
function WEAPON._REMOVE_WEAPON_FROM_PED_BY_GUID(ped, weaponGuid, removeReason) end

---@param PedIndex integer
---@param HideWeaponFlag boolean
function WEAPON.HIDE_PED_WEAPON_FOR_SCRIPTED_CUTSCENE(PedIndex, HideWeaponFlag) end

---@param PedIndex integer
---@param VisibleFlag boolean
---@param DestroyObject boolean
---@param DeadCheck boolean
---@param StoreDestroyedWeaponClipValue boolean
function WEAPON.SET_PED_CURRENT_WEAPON_VISIBLE(PedIndex, VisibleFlag, DestroyObject, DeadCheck, StoreDestroyedWeaponClipValue) end

---@param ped integer
---@param attachPoint integer
---@param visible boolean
function WEAPON._SET_PED_WEAPON_ATTACH_POINT_VISIBILITY(ped, attachPoint, visible) end

---@param ped integer
---@param visible boolean
function WEAPON._SET_PED_ALL_WEAPONS_VISIBILITY(ped, visible) end

---@param PedIndex integer
---@param DropsWeaponsFlag boolean
function WEAPON.SET_PED_DROPS_WEAPONS_WHEN_DEAD(PedIndex, DropsWeaponsFlag) end

---@param ped integer
---@param toggle boolean
function WEAPON._0x431240A58484D5D0(ped, toggle) end

---@param ped integer
---@param toggle boolean
function WEAPON._0x45E57FDD531C9477(ped, toggle) end

---@param ped integer
---@param toggle boolean
function WEAPON._0xF08D8FEB455F2C8C(ped, toggle) end

---@param ped integer
---@param toggle boolean
function WEAPON._0x16D9841A85FA627E(ped, toggle) end

---@param PedIndex integer
---@param ImpactCoord Vector3
---@return boolean
---@return Vector3
function WEAPON.GET_PED_LAST_WEAPON_IMPACT_COORD(PedIndex, ImpactCoord) end

---@param ped integer
function WEAPON._CLEAR_PED_LAST_WEAPON_DAMAGE(ped) end

---@param entity integer
---@param weaponName integer
---@param weaponType integer
---@return boolean
function WEAPON._HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON(entity, weaponName, weaponType) end

---@param PedIndex integer
---@param WeaponType integer
---@param offsetX number
---@param offsetY number
---@param offsetZ number
---@param ammoAmount integer
function WEAPON.SET_PED_DROPS_INVENTORY_WEAPON(PedIndex, WeaponType, offsetX, offsetY, offsetZ, ammoAmount) end

---@param p0 any
---@param p1 any
---@param p2 any
function WEAPON._0xB0FB9B196A3D13F0(p0, p1, p2) end

---@param ped integer
---@param p1 integer
function WEAPON._0x2EBF70E1D8C06683(ped, p1) end

---@param p0 any
function WEAPON._0x63B83A526329AFBC(p0) end

---@param ped integer
---@return any
function WEAPON._MAKE_PED_RELOAD(ped) end

---@param ped integer
---@return any
function WEAPON._REFILL_AMMO_IN_CURRENT_PED_WEAPON(ped) end

---@param ped integer
---@param p1 boolean
---@param attachPoint integer
---@param p3 boolean
---@param p4 boolean
---@return integer
function WEAPON.MAKE_PED_DROP_WEAPON(ped, p1, attachPoint, p3, p4) end

---@param ped integer
---@return integer
function WEAPON._GET_PED_CURRENT_HELD_WEAPON(ped) end

---@param ped integer
---@param toggle boolean
function WEAPON.SET_ALLOW_ANY_WEAPON_DROP(ped, toggle) end

---@param p0 any
---@param p1 any
---@param p2 any
function WEAPON._0xA3716A77DCF17424(p0, p1, p2) end

---@param p0 any
function WEAPON._0x457B16951AD77C1B(p0) end

---@param p0 any
---@return any
function WEAPON._0x3799EFCC3C8CD5E1(p0) end

---@param ped integer
---@return number
function WEAPON._GET_MAX_LOCKON_DISTANCE_OF_CURRENT_PED_WEAPON(ped) end

---@param ped integer
---@param componentHash integer
---@param weaponHash integer
function WEAPON._REMOVE_WEAPON_COMPONENT_FROM_PED(ped, componentHash, weaponHash) end

---@param ped integer
---@param componentHash integer
---@param weaponHash integer
---@return boolean
function WEAPON._HAS_PED_GOT_WEAPON_COMPONENT(ped, componentHash, weaponHash) end

---@param ped integer
---@return boolean
function WEAPON._IS_PED_CURRENT_WEAPON_HOLSTERED(ped) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0xD2209866B0CB72EA(p0, p1) end

---@param weaponHash integer
---@param p1 integer
---@param p2 boolean
function WEAPON._REQUEST_WEAPON_ASSET(weaponHash, p1, p2) end

---@param weaponHash integer
---@return boolean
function WEAPON._HAS_WEAPON_ASSET_LOADED(weaponHash) end

---@param weaponHash integer
function WEAPON._REMOVE_WEAPON_ASSET(weaponHash) end

---@param p0 any
---@param p1 any
---@param p2 any
function WEAPON._0xE9B3FEC825668291(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@return any
function WEAPON._0x9CCA3131E6B53C68(p0, p1, p2) end

---@param weaponHash integer
---@return string
function WEAPON._GET_WEAPON_NAME_2(weaponHash) end

---@param weaponHash integer
---@return string
function WEAPON._GET_WEAPON_NAME(weaponHash) end

---@param weaponHash integer
---@param permanentDegradationLevel number
---@return string
function WEAPON._GET_WEAPON_NAME_WITH_PERMANENT_DEGRADATION(weaponHash, permanentDegradationLevel) end

---@param p0 any
---@param p1 any
---@param p2 any
function WEAPON._0xB832F1A686B9B810(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0x5A695BD328586B44(p0, p1) end

---@param p0 any
---@param p1 any
function WEAPON._0x641351E9AD103890(p0, p1) end

---@param ped integer
---@param toggle boolean
function WEAPON.SET_INSTANTLY_EQUIP_WEAPON_PICKUPS(ped, toggle) end

---@param ped integer
---@param toggle boolean
function WEAPON._SET_FORCE_AUTO_EQUIP(ped, toggle) end

---@param ped integer
---@param weaponHash integer
function WEAPON._SEND_WEAPON_TO_INVENTORY(ped, weaponHash) end

---@param horse integer
---@param weaponHash integer
---@param ped integer
function WEAPON._0x14FF0C2545527F9B(horse, weaponHash, ped) end

---@param p0 any
function WEAPON._0xD4C6E24D955FF061(p0) end

---@param p0 any
---@return any
function WEAPON._0xAFFD0CCF31F469B8(p0) end

---@param weaponHash integer
---@return integer
function WEAPON._GET_WEAPON_STAT_ID(weaponHash) end

---@param entity integer
---@param weaponHash integer
---@param ms integer
---@return boolean
function WEAPON._HAS_ENTITY_BEEN_DAMAGED_BY_WEAPON_RECENTLY(entity, weaponHash, ms) end

---@param ped integer
---@return integer
function WEAPON._GET_PED_HOGTIE_WEAPON(ped) end

---@param weaponHash integer
---@param ammoCount integer
---@param x number
---@param y number
---@param z number
---@param showWorldModel boolean
---@param scale number
---@return integer
function WEAPON._CREATE_WEAPON_OBJECT(weaponHash, ammoCount, x, y, z, showWorldModel, scale) end

---@param WeaponObjectIndex integer
---@param WeaponComponent integer
function WEAPON.REMOVE_WEAPON_COMPONENT_FROM_WEAPON_OBJECT(WeaponObjectIndex, WeaponComponent) end

---@param WeaponObjectIndex integer
---@param WeaponComponent integer
---@return boolean
function WEAPON.HAS_WEAPON_GOT_WEAPON_COMPONENT(WeaponObjectIndex, WeaponComponent) end

---@param weaponObject integer
---@param ped integer
---@param componentHash integer
---@param p3 boolean
---@return integer
function WEAPON._GIVE_WEAPON_COMPONENT_TO_WEAPON_OBJECT(weaponObject, ped, componentHash, p3) end

---@param ped integer
---@param p1 boolean
---@return integer
function WEAPON._GET_WEAPON_OBJECT_FROM_PED(ped, p1) end

---@param ped integer
---@param p1 boolean
---@return integer
function WEAPON._GET_PED_WEAPON_OBJECT(ped, p1) end

---@param entity integer
---@param componentHash integer
---@param weaponHash integer
---@param p3 boolean
function WEAPON._GIVE_WEAPON_COMPONENT_TO_ENTITY(entity, componentHash, weaponHash, p3) end

---@param p0 any
---@param p1 any
function WEAPON._0x74C9080FDD1BB48E(p0, p1) end

---@param p0 any
---@param p1 any
function WEAPON._0x74C9080FDD1BB48F(p0, p1) end

---@param p0 any
---@param p1 any
function WEAPON._0x74C2365FDD1BB48F(p0, p1) end

---@param p0 any
function WEAPON._0x74C90AAACC1DD48F(p0) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0x74C8000FDD1BB111(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0x74C8000FDD1BB222(p0, p1) end

---@param emote integer
---@param weaponEmoteTrickType integer
---@return integer
function WEAPON._GET_WEAPON_GUN_SPINNING_WEAPON_EMOTE_TRICK_TYPE_HASH(emote, weaponEmoteTrickType) end

---@param ped integer
---@param emote integer
function WEAPON._SET_ACTIVE_GUN_SPINNING_EQUIP_KIT_EMOTE_TWIRL(ped, emote) end

---@param ped integer
---@return integer
function WEAPON._GET_PED_GUN_SPINNING_EQUIPPED_KIT_EMOTE_TWIRL(ped) end

---@param ped integer
---@param weaponEmoteTrickType integer
---@param spin integer
function WEAPON._SET_ACTIVE_GUN_SPINNING_KIT_EMOTE_TWIRL(ped, weaponEmoteTrickType, spin) end

---@param ped integer
---@param weaponEmoteVariation integer
---@return integer
function WEAPON._GET_PED_GUN_SPINNING_HASH_FROM_WEAPON_EMOTE_VARIATION(ped, weaponEmoteVariation) end

---@param ped integer
---@param variation integer
---@return integer
function WEAPON._GET_WEAPON_EMOTE_VARIATION(ped, variation) end

---@param ped integer
---@param emoteType integer
function WEAPON._SET_GUN_SPINNING_INVENTORY_SLOT_ID_ACTIVATE(ped, emoteType) end

---@param weaponHash integer
---@return boolean
function WEAPON._GET_CAN_TWIRL_WEAPON(weaponHash) end

---@param ped integer
---@param weaponGuid integer
---@return boolean
function WEAPON._GET_CORRECT_KIT_EMOTE_TWIRL_GUN(ped, weaponGuid) end

---@param p0 any
---@return any
function WEAPON._0xBC9444F2FF94A9C0(p0) end

---@param pedModel integer
---@return integer
function WEAPON._GET_DEFAULT_PED_WEAPON_COLLECTION(pedModel) end

---@param ped integer
---@param weaponCollection integer
function WEAPON._GIVE_WEAPON_COLLECTION_TO_PED(ped, weaponCollection) end

---@param weaponCollection integer
---@param dualwieldVariant integer
---@return boolean
function WEAPON._0xF252A85B8F3F8C58(weaponCollection, dualwieldVariant) end

---@param weaponCollection integer
---@param weaponGroup integer
---@return integer
function WEAPON._0x9EEFD670F10656D7(weaponCollection, weaponGroup) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0xF2F585411E748B9C(p0, p1) end

---@param weaponHash integer
---@return integer
function WEAPON.GET_WEAPON_CLIP_SIZE(weaponHash) end

---@param p0 any
---@param p1 any
---@param p2 any
function WEAPON._0xA769D753922B031B(p0, p1, p2) end

---@param p0 any
function WEAPON._0xC5899C4CD2E2495D(p0) end

---@param ped integer
---@return boolean
function WEAPON.GET_ALLOW_DUAL_WIELD(ped) end

---@param ped integer
---@param allow boolean
function WEAPON._SET_ALLOW_DUAL_WIELD(ped, allow) end

---@param ped integer
---@param ammoHash integer
---@return boolean
function WEAPON._0x44C8F4908F1B2622(ped, ammoHash) end

---@param weaponHash integer
---@return boolean
function WEAPON._IS_WEAPON_KNIFE(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON.IS_WEAPON_REVOLVER(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON.IS_WEAPON_PISTOL(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON.IS_WEAPON_REPEATER(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON.IS_WEAPON_RIFLE(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON.IS_WEAPON_SHOTGUN(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON._IS_WEAPON_SNIPER(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON.IS_WEAPON_MELEE_WEAPON(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON._IS_WEAPON_THROWABLE(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON._IS_WEAPON_LASSO(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON._IS_WEAPON_BINOCULARS(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON.IS_WEAPON_A_GUN(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON._IS_WEAPON_TWO_HANDED(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON._IS_WEAPON_ONE_HANDED(weaponHash) end

---@param weaponHash integer
---@return boolean
function WEAPON._IS_WEAPON_SILENT(weaponHash) end

---@param p0 any
---@return any
function WEAPON._0xEA522F991E120D45(p0) end

---@param ammoHash integer
---@return boolean
function WEAPON._IS_AMMO_SILENT(ammoHash) end

---@param ammoHash integer
---@return boolean
function WEAPON._IS_AMMO_SILENT_2(ammoHash) end

---@param weaponHash integer
---@return boolean
function WEAPON.SHOULD_WEAPON_BE_DISCARDED_WHEN_SWAPPED(weaponHash) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0x5B235F24472F2C3B(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0xBFCA7AFABF9D7967(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0x495A04CAEC263AF8(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0x95CA12E2C68043E5(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0xABC18A28BAD4B46F(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0x80BB243789008A82(p0, p1) end

---@param weaponObject integer
---@return number
function WEAPON._GET_WEAPON_DAMAGE(weaponObject) end

---@param weaponObject integer
---@param level number
---@param p2 boolean
function WEAPON._SET_WEAPON_DAMAGE(weaponObject, level, p2) end

---@param weaponObject integer
---@return number
function WEAPON._GET_WEAPON_DIRT(weaponObject) end

---@param weaponObject integer
---@param level number
---@param p2 boolean
function WEAPON._SET_WEAPON_DIRT(weaponObject, level, p2) end

---@param weaponObject integer
---@return number
function WEAPON._GET_WEAPON_SOOT(weaponObject) end

---@param weaponObject integer
---@param level number
---@param p2 boolean
function WEAPON._SET_WEAPON_SOOT(weaponObject, level, p2) end

---@param weaponObject integer
---@param threshold number
function WEAPON._SET_WEAPON_LEVEL_THRESHOLD(weaponObject, threshold) end

---@param weaponObject integer
---@return number
function WEAPON.GET_WEAPON_DEGRADATION(weaponObject) end

---@param weaponObject integer
---@return number
function WEAPON.GET_WEAPON_PERMANENT_DEGRADATION(weaponObject) end

---@param weaponObject integer
---@param level number
function WEAPON._SET_WEAPON_DEGRADATION(weaponObject, level) end

---@param listen boolean
function WEAPON._LISTEN_PROJECTILE_HIT_EVENTS(listen) end

---@param weaponObject integer
---@return number
function WEAPON._GET_WEAPON_SCALE(weaponObject) end

---@param weaponObject integer
---@param scale number
function WEAPON._SET_WEAPON_SCALE(weaponObject, scale) end

---@param p0 any
---@return any
function WEAPON._0x58425FCA3D3A2D15(p0) end

---@param p0 any
---@return any
function WEAPON._0xEC97101A8F311282(p0) end

---@param ped integer
---@param weaponObject integer
---@return integer
function WEAPON._GET_CURRENT_PED_WEAPON_AMMO_TYPE(ped, weaponObject) end

---@param ped integer
---@param weaponGuid integer
---@return integer
function WEAPON._GET_CURRENT_AMMO_TYPE_FROM_GUID(ped, weaponGuid) end

---@param weaponHash integer
---@param ammoHash integer
---@return boolean
function WEAPON._IS_AMMO_TYPE_VALID_FOR_WEAPON(weaponHash, ammoHash) end

---@param ped integer
---@param weaponHash integer
---@param ammoHash integer
function WEAPON._SET_AMMO_TYPE_FOR_PED_WEAPON(ped, weaponHash, ammoHash) end

---@param p0 any
---@param p1 any
function WEAPON._0x183CE355115B6E75(p0, p1) end

---@param ped integer
---@param weaponInventoryUid integer
---@param ammoHash integer
function WEAPON._SET_AMMO_TYPE_FOR_PED_WEAPON_INVENTORY(ped, weaponInventoryUid, ammoHash) end

---@param ped integer
---@param weaponHash integer
---@param ammoHash integer
function WEAPON._DISABLE_AMMO_TYPE_FOR_PED_WEAPON(ped, weaponHash, ammoHash) end

---@param ped integer
---@param ammoHash integer
function WEAPON._DISABLE_AMMO_TYPE_FOR_PED(ped, ammoHash) end

---@param p0 any
---@param p1 any
function WEAPON._0xD63B4BA3A02A99E0(p0, p1) end

---@param ped integer
---@param weaponHash integer
---@param ammoHash integer
function WEAPON._ENABLE_AMMO_TYPE_FOR_PED_WEAPON(ped, weaponHash, ammoHash) end

---@param ped integer
---@param weaponHash integer
function WEAPON._ENABLE_AMMO_TYPE_FOR_PED(ped, weaponHash) end

---@param p0 any
---@param p1 any
function WEAPON._0x404514D231DB27A0(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function WEAPON._0xD53846B9C931C181(p0, p1, p2) end

---@param p0 any
function WEAPON._0x000FA7A4A8443AF7(p0) end

---@param p0 any
function WEAPON._0xECBB26529A737EF6(p0) end

---@param ped integer
---@param attachPoint integer
---@return integer
function WEAPON._GET_WEAPON_ATTACH_POINT(ped, attachPoint) end

---@param p0 any
---@param p1 any
---@return any
function WEAPON._0x4823F13A21F51964(p0, p1) end

---@param ped integer
---@param weaponUid integer
---@param p2 boolean
---@param p3 boolean
---@param p4 boolean
---@param p5 boolean
function WEAPON.SET_CURRENT_PED_WEAPON_BY_GUID(ped, weaponUid, p2, p3, p4, p5) end

---@param ped integer
---@param guidPrimary integer
---@param guidSecondary integer
function WEAPON.SET_PLAYER_PED_QUICK_SWAP_WEAPON_BY_GUID(ped, guidPrimary, guidSecondary) end

---@param ped integer
---@param guidPrimary integer
---@param guidSecondary integer
function WEAPON._GET_PLAYER_PED_QUICK_SWAP_WEAPON_BY_GUID(ped, guidPrimary, guidSecondary) end

---@param ped integer
---@return boolean
function WEAPON._0x0DE0944ECCB3DF5D(ped) end

---@param ped integer
---@return any
function WEAPON._0x46D42883E873C1D7(ped) end

---@param ped integer
---@param targetPed integer
---@return boolean
function WEAPON._IS_TARGET_PED_CONSTRAINED_BY_PED_USING_BOLAS(ped, targetPed) end

---@param weaponHash integer
---@return integer
function WEAPON._0x65DC4AC5B96614CB(weaponHash) end
