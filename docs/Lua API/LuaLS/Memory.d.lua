---@meta

---@class Memory
Memory = {}

-- Scans a byte signature and returns a Pointer object. The function is synchronous so it's best to run it in a fiber.
---@param sig string IDA-style byte signature. Example: `"8B 88 C0 ? ? ? 89 8F"`
---@param name string? Optional name of the pattern to scan. Purely for logging purposes.
---@return Pointer ptr A pointer at the found address or a null pointer if the scan fails. This is guaranteed to always return a Pointer object.
function Memory.ScanPattern(sig, name) end

---@param handle integer RAGE entity handle
---@return Pointer 
function Memory.HandleToPointer(handle) end

---@param ptr Pointer entity pointer
---@return integer handle
function Memory.PointerToHandle(ptr) end

-- Allocates a memory block and returns a Pointer to the allocated memory address.
---@param size integer size in bytes
---@return Pointer ptr Pointer to the allocated memory address.
function Memory.Allocate(size) end

-- Frees an allocated memory block.
---@param ptr Pointer 
function Memory.Free(ptr) end
