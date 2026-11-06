---@meta

---@class Path
---@overload fun(path: string): Path
---@operator div(string): Path
Path = {}

---@return boolean 
function Path:Exists() end

---@return boolean 
function Path:IsFile() end

---@return boolean 
function Path:IsDir() end

-- Creates a directory if it doesn't exist
function Path:MakeDir() end

-- Creates a directory and any missing parent directories
function Path:MakeDirs() end

---@return string 
function Path:GetFilename() end

---@return string stem The file name without the extension.
function Path:GetStem() end

---@return string ext The file extension including the leading dot. Ex: `.json`. Returns empty string for folders.
function Path:GetExtension() end

---@return integer filesz The file size in bytes.
function Path:GetFileSize() end

---@return Path parentDir The parent directory. Note: This will throw if the path is outside the module's root directory.
function Path:GetParent() end

-- Joins the path with a sub-path. Does the same thing as the division operator *(__div)*: `myPath / "somefile.txt"`
---@param subPath string 
---@return Path 
function Path:Join(subPath) end

---@param mode openmode? 
---@return file*? File handle or nil
---@return string failReason An error message if the operation fails.
function Path:Open(mode) end

-- Returns the string representation of the path. `myPath:ToString()`, `myPath:__tostring()`, and `tostring(myPath)` all achieve the same thing.
---@return string strPath
function Path:ToString() end

-- Recursive directory iterator.
---@return fun(): Path
function Path:IterDir() end
