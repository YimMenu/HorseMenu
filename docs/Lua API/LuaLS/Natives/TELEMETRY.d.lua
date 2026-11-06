---@meta

---@class TELEMETRY
TELEMETRY = {}

---@param toggle boolean
function TELEMETRY._TELEMETRY_SET_IS_FLOW(toggle) end

---@param toggle boolean
function TELEMETRY._0xEC0BD8736DCAF841(toggle) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TELEMETRY._TELEMETRY_MISSION_STARTED(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
function TELEMETRY._TELEMETRY_MISSION_OVER(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function TELEMETRY._TELEMETRY_MISSION_CHECKPOINT(p0, p1, p2) end

---@param ped integer
function TELEMETRY._TELEMETRY_PLAYER_SPAWNED(ped) end

---@param uuid integer
---@return boolean
function TELEMETRY._TELEMETRY_CREATE_UUID(uuid) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function TELEMETRY._TELEMETRY_MATCH_QUEUE(p0, p1, p2, p3, p4, p5, p6) end

---@param p0 integer
---@param p1 integer
function TELEMETRY._TELEMETRY_MATCH_STARTED(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function TELEMETRY._TELEMETRY_MATCH_OVER(p0, p1, p2, p3, p4) end

---@param p0 integer
---@param p1 integer
function TELEMETRY._TELEMETRY_MATCH_VOTE(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TELEMETRY._TELEMETRY_LOBBY_PROGRESSION(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
function TELEMETRY._TELEMETRY_GAME_PROGRESS(p0, p1) end

---@param herbType integer
function TELEMETRY._TELEMETRY_HERB_PICKED(herbType) end

---@param type integer
---@param items integer
function TELEMETRY._TELEMETRY_ANIMAL_SKINNED(type, items) end

---@param p0 any
function TELEMETRY._TELEMETRY_CAMP_CREATED(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function TELEMETRY._TELEMETRY_CAMP_SUPPLIES(p0, p1, p2, p3, p4) end

---@param regionHash integer
function TELEMETRY._TELEMETRY_REGION(regionHash) end

---@param shopType any
---@param shopRegion any
---@param region any
---@param p3 any
---@param p4 any
---@param p5 any
function TELEMETRY._TELEMETRY_SHOP_ENTRY(shopType, shopRegion, region, p3, p4, p5) end

---@param p0 any
---@param p1 any
function TELEMETRY._TELEMETRY_SHOP_EXIT(p0, p1) end

---@param transactionId integer
---@param p1 integer
---@param p2 integer
function TELEMETRY._TELEMETRY_SET_SHOP_FOR_TRANSACTION(transactionId, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function TELEMETRY._TELEMETRY_SHOP_PURCHASE(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param centSalePrice integer
function TELEMETRY._TELEMETRY_SHOP_SELL(p0, p1, p2, p3, centSalePrice) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TELEMETRY._TELEMETRY_GOLD_STORE(p0, p1, p2, p3) end

function TELEMETRY._CLEAR_TELEMETRY_SHOP_UI() end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TELEMETRY._TELEMETRY_SHOP_CUTSCENE(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function TELEMETRY._TELEMETRY_AMBIENT_VIGNETTE(p0, p1, p2, p3, p4, p5, p6) end

---@param p0 any
function TELEMETRY._TELEMETRY_DISCOVERABLE(p0) end

---@param p0 any
---@param p1 any
function TELEMETRY._TELEMETRY_HONOR(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param quantity any
function TELEMETRY._TELEMETRY_CRAFT_ITEM(p0, p1, p2, quantity) end

---@param transactionId any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param slotId integer
---@param p6 integer
---@param p7 any
---@param p8 boolean
function TELEMETRY.TELEMETRY_CAMP_DONATE(transactionId, p1, p2, p3, p4, slotId, p6, p7, p8) end

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
function TELEMETRY._TELEMETRY_MOONSHINE_BREW(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) end

---@param transactionId any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function TELEMETRY._TELEMETRY_COLLECT(transactionId, p1, p2, p3, p4, p5, p6) end

---@param p0 any
---@param p1 any
function TELEMETRY._TELEMETRY_MISSION_ILO_OPTION(p0, p1) end

---@param p0 any
---@param p1 any
---@param x number
---@param y number
---@param z number
---@param reason integer
function TELEMETRY._TELEMETRY_MISSION_FAILED_TO_LAUNCH(p0, p1, x, y, z, reason) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TELEMETRY._TELEMETRY_GANG_SHARES(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function TELEMETRY._TELEMETRY_FAST_TRAVEL(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function TELEMETRY._TELEMETRY_NET_CAMP(p0, p1, p2, p3, p4, p5, p6) end

function TELEMETRY._TELEMETRY_RPG_GLOBAL_CALCULATE_ATTRIBUTE_CORE_DELTA() end

---@param p0 any
function TELEMETRY._TELEMETRY_SLEEP(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
function TELEMETRY._TELEMETRY_PARLEY_FEUD(p0, p1, p2, p3, p4) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TELEMETRY.TELEMETRY_PLAYER_MENU_PIN(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TELEMETRY._TELEMETRY_NOTORIETY(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
function TELEMETRY._TELEMETRY_DEFENSIVE(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TELEMETRY._TELEMETRY_LOOT(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param emote integer
function TELEMETRY._TELEMETRY_EMOTE_ADD_CATEGORY_TO_SAVE(p0, p1, emote) end

---@param p0 any
---@param p1 any
---@param p2 any
function TELEMETRY._TELEMETRY_FAVOR_EMOTE(p0, p1, p2) end

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
function TELEMETRY._TELEMETRY_POKER_OVER(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param requestId integer
---@param transactionId integer
---@return boolean
function TELEMETRY._TELEMETRY_TRIGGER_TRANSACTION_REQUEST(requestId, transactionId) end

---@param transactionId integer
---@param requestId integer
---@return boolean
function TELEMETRY._TRY_GET_TELEMETRY_ID_FROM_TRANSACTION_ID(transactionId, requestId) end

---@param p0 any
function TELEMETRY._TELEMETRY_ROLE_BOUNTY(p0) end

---@param data integer
function TELEMETRY._TELEMETRY_BOUNTY_TARGET(data) end

---@param transactionId any
---@param bountyAmount any
---@param ped integer
---@param completionType any
---@param jailTimeServed any
---@param jailTimeLeft any
---@param posseRole any
function TELEMETRY._TELEMETRY_PRISON(transactionId, bountyAmount, ped, completionType, jailTimeServed, jailTimeLeft, posseRole) end

---@param p0 any
---@param transactionId any
function TELEMETRY._TELEMETRY_ROLE_TRADER(p0, transactionId) end

---@param p0 any
---@param transactionId any
function TELEMETRY._TELEMETRY_ROLE_MOONSHINER(p0, transactionId) end

---@param transactionId any
---@param collectible any
---@param category any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function TELEMETRY._TELEMETRY_ROLE_COLLECTOR(transactionId, collectible, category, p3, p4, p5, p6) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TELEMETRY._TELEMETRY_PHOTO(p0, p1, p2, p3) end

function TELEMETRY._TELEMETRY_START_GUN_LOCKER_INTERACTION() end

function TELEMETRY._TELEMETRY_GUN_LOCKER() end

---@param p0 integer
function TELEMETRY._TELEMETRY_GUN_LOCKER_WEAPON_STORED(p0) end

---@param p0 integer
function TELEMETRY._TELEMETRY_GUN_LOCKER_WEAPON_REMOVED(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function TELEMETRY._TELEMETRY_ROLE_TOKEN_TRANSACTION(p0, p1, p2, p3, p4, p5) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
function TELEMETRY._TELEMETRY_COUPON(p0, p1, p2, p3, p4, p5) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TELEMETRY.TELEMETRY_PERSONAL_VEHICLE_MOUNT(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
function TELEMETRY._TELEMETRY_PERSONAL_VEHICLE_WAGON(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TELEMETRY._TELEMETRY_MENU_NAVIGATION(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function TELEMETRY._TELEMETRY_HUB_NAVIGATION(p0, p1, p2, p3) end

---@param couponItem any
---@param p1 any
function TELEMETRY._TELEMETRY_HUB_OFFERS(couponItem, p1) end

---@param transactionId any
---@param animal any
---@param p2 any
---@param bSampled any
---@param bTranq boolean
function TELEMETRY._TELEMETRY_SAMPLE(transactionId, animal, p2, bSampled, bTranq) end

---@param transactionId any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
---@param p9 any
function TELEMETRY._TELEMETRY_ROLE_NATURALIST(transactionId, p1, p2, p3, p4, p5, p6, p7, p8, p9) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
---@param p8 any
function TELEMETRY._TELEMETRY_PHOTO_CAM(p0, p1, p2, p3, p4, p5, p6, p7, p8) end

---@param p0 any
---@param p1 any
---@param p2 any
function TELEMETRY._TELEMETRY_INTRO_SKIP(p0, p1, p2) end

function TELEMETRY.ANALYTICS_PLAYTIME_FREEMODE_START() end

function TELEMETRY.ANALYTICS_PLAYTIME_FREEMODE_END() end

---@param args integer
function TELEMETRY._TELEMETRY_CUSTOM(args) end

---@param args integer
function TELEMETRY._TELEMETRY_MATCH_NOMINATION(args) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
function TELEMETRY._TELEMETRY_CHAR_CREATOR(p0, p1, p2, p3, p4, p5, p6) end
