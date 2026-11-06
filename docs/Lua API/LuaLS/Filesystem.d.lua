---@meta

---@class Filesystem
Filesystem = {}

-- Returns the module's root path.
---@return Path 
function Filesystem.MyRoot() end

-- Recursive directory iterator.
---@param path Path 
---@return fun(): Path
function Filesystem.IterDir(path) end

---@param oldPath Path 
---@param newPath Path 
---@return boolean successOrFailure
---@return string failReason
function Filesystem.Rename(oldPath, newPath) end

---@param path Path 
---@param emptyOnly boolean? If true, non-empty folders will not be removed. Defaults to `true`.
---@return boolean successOrFailure
---@return string failReason
function Filesystem.Remove(path, emptyOnly) end
