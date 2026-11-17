---@meta

---@class Player
---@overload fun(pid: integer): Player
Player = {}

---@return boolean 
function Player:IsValid() end

---@return boolean 
function Player:IsModder() end

---@return boolean 
function Player:IsHost() end

---@return boolean 
function Player:IsFriend() end

---@return string 
function Player:GetName() end

---@return integer pid The player's ID (0-31).
function Player:GetId() end

---@return integer rid The player's Rockstar ID.
function Player:GetRID() end

---@return Ped ped The player's [Ped](lua://Ped) class instance.
function Player:GetPed() end

---@return integer ped The player's current rank.
function Player:GetRank() end

---@return integer ped The player's current honor.
function Player:GetHonor() end

---@return integer region The player's current region number.
function Player:GetRegionIndex() end

---@return string region The player's current region name.
function Player:GetRegionName() end

---@return integer district The player's camp location index.
function Player:GetDistrictIndex() end

---@return string district The player's camp location name.
function Player:GetDistrictName() end

---@return integer lang The player's current language index.
function Player:GetLanguageIndex() end

---@return string lang The player's current language name.
function Player:GetLanguageName() end
