---@meta

---@class FLOCK
FLOCK = {}

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@return number
function FLOCK.GET_SPECIES_TUNING_FLOAT_PARAM(p0, p1, p2) end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@param p3 number
function FLOCK.SET_SPECIES_TUNING_FLOAT_PARAM(p0, p1, p2, p3) end

---@param p0 integer
---@param p1 integer
---@param p2 integer
---@param p3 boolean
function FLOCK.SET_SPECIES_TUNING_BOOL_PARAM(p0, p1, p2, p3) end

---@param animal integer
---@param index integer
---@return number
function FLOCK.GET_ANIMAL_TUNING_FLOAT_PARAM(animal, index) end

---@param animal integer
---@param index integer
---@param value number
function FLOCK.SET_ANIMAL_TUNING_FLOAT_PARAM(animal, index, value) end

---@param animal integer
---@param index integer
function FLOCK.RESET_ANIMAL_TUNING_FLOAT_PARAM(animal, index) end

---@param animal integer
---@param index integer
---@return boolean
function FLOCK.GET_ANIMAL_TUNING_BOOL_PARAM(animal, index) end

---@param animal integer
---@param index integer
---@param value boolean
function FLOCK.SET_ANIMAL_TUNING_BOOL_PARAM(animal, index, value) end

---@param animal integer
---@param index integer
function FLOCK.RESET_ANIMAL_TUNING_BOOL_PARAM(animal, index) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@return any
function FLOCK._0x8049B17BEC937662(p0, p1, p2, p3, p4, p5, p6) end

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
function FLOCK._0xE93415B3307208E5(p0, p1, p2, p3, p4, p5, p6, p7, p8) end

---@param p0 any
---@param p1 any
---@return any
function FLOCK._0x19870C40C7EE15BE(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function FLOCK._0x0816C31480764AB0(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
function FLOCK._0xC3D581A34BC0A1F0(p0, p1) end

---@param species integer
---@param x1 number
---@param y1 number
---@param z1 number
---@param x2 number
---@param y2 number
---@param z2 number
---@param x3 number
---@param y3 number
---@param z3 number
---@param p10 number
---@param p11 number
---@param p12 number
---@param p13 number
function FLOCK._0xF2CCA7B68CFAB2B9(species, x1, y1, z1, x2, y2, z2, x3, y3, z3, p10, p11, p12, p13) end

---@param p0 any
function FLOCK._0xFB16F08F47B83B4C(p0) end

---@param ped integer
---@return boolean
function FLOCK._GET_ANIMAL_IS_WILD(ped) end

---@param ped integer
---@param toggle boolean
function FLOCK._SET_ANIMAL_IS_WILD(ped, toggle) end

---@param ped integer
---@return integer
function FLOCK._GET_ANIMAL_RARITY(ped) end

---@param ped integer
---@param rarityLevel integer
function FLOCK._SET_ANIMAL_RARITY(ped, rarityLevel) end

---@param p0 any
---@param p1 any
function FLOCK._0xFF1E339CE40EAAAF(p0, p1) end

---@param herdHandle integer
---@return boolean
function FLOCK._IS_HERD_VALID(herdHandle) end

---@return integer
function FLOCK._CREATE_HERD() end

---@param p0 any
function FLOCK._0xE0961AED72642B80(p0) end

---@param p0 any
---@param ped integer
function FLOCK._ADD_PED_TO_FLOCK(p0, ped) end

---@param p0 any
---@param p1 any
function FLOCK._0x408D1149C5E39C1E(p0, p1) end

---@param p0 any
---@param p1 any
---@return any
function FLOCK._0x9E13ACC38BA8F9C3(p0, p1) end

---@param p0 any
---@return any
function FLOCK._0x34B9C4D86DF2C2F3(p0) end

---@param p0 any
---@return Vector3
function FLOCK._0x1DA6CB02071055D5(p0) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function FLOCK._0xC95611869E14F8AF(p0, p1, p2, p3) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@return any
function FLOCK._0x09EE00B8F858E0BE(p0, p1, p2, p3, p4, p5, p6) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
---@param p4 any
---@param p5 any
---@param p6 any
---@param p7 any
function FLOCK._0xE36D2CB540597EF7(p0, p1, p2, p3, p4, p5, p6, p7) end

---@param p0 any
---@param p1 any
---@return any
function FLOCK._0xD95F04A4E73BE85E(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function FLOCK._0x17E3E5C46ECCD308(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
---@param p3 any
function FLOCK._0xC72CE37081DAE625(p0, p1, p2, p3) end

---@param p0 any
function FLOCK._0x67A43EA3F6FE0076(p0) end

---@param p0 any
---@return any
function FLOCK._0x36486AF7DA93A464(p0) end

---@param p0 any
---@param p1 any
function FLOCK._0x6C57BEA886A20C6B(p0, p1) end

---@param p0 any
---@param p1 any
function FLOCK._0x1520626FFAFFFA8F(p0, p1) end

---@param p0 any
---@param p1 any
---@param p2 any
function FLOCK._0xFA821997794F48E7(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
function FLOCK._0xCC6B5AAFC87BFC7B(p0, p1, p2) end

---@param p0 any
---@param p1 any
---@param p2 any
function FLOCK._0xFDB008B3BCF5992F(p0, p1, p2) end

---@param p0 any
---@param p1 any
function FLOCK._0x2DF3D457D86F8E57(p0, p1) end

---@param p0 any
function FLOCK._0x706B434FEFAD6A24(p0) end

---@param p0 any
function FLOCK._0xA881F5C77A560906(p0) end

---@param p0 any
---@return any
function FLOCK._0x53187E563F938E76(p0) end
