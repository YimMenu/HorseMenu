---@meta

---@class BytePatch
BytePatch = {}

-- Applies the patch bytes
function BytePatch:Apply() end

-- Restores the patch bytes
function BytePatch:Restore() end

---@return boolean 
function BytePatch:IsApplied() end
