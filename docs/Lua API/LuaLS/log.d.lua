---@meta

---@class log
log = {}

-- Logs an information message. Arguments are the same as [print](lua://print)
---@param ... any 
function log.info(...) end

-- Logs a warning message. Arguments are the same as [print](lua://print)
---@param ... any 
function log.warning(...) end

-- Logs a debug message. Arguments are the same as [print](lua://print)
---@param ... any 
function log.debug(...) end

-- Logs an error message. Arguments are the same as [print](lua://print)
---@param ... any 
function log.error(...) end

-- Logs a formatted information message. Formatting works the same as [string.format](lua://string.format)
---@param msg string Message.
---@param ... any Optional format arguments.
function log.finfo(msg, ...) end

-- Logs a formatted warning message. Formatting works the same as [string.format](lua://string.format)
---@param msg string Message.
---@param ... any Optional format arguments.
function log.fwarning(msg, ...) end

-- Logs a formatted debug message. Formatting works the same as [string.format](lua://string.format)
---@param msg string Message.
---@param ... any Optional format arguments.
function log.fdebug(msg, ...) end

-- Logs a formatted error message. Formatting works the same as [string.format](lua://string.format)
---@param msg string Message.
---@param ... any Optional format arguments.
function log.ferror(msg, ...) end
