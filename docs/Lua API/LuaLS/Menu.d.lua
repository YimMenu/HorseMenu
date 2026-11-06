---@meta

-- The main bridge between Lua and the menu.
-- 
-- Exposes functions to register menu events, UI tabs and callbacks, commands, etc.
---@class Menu
Menu = {}

---@param event eMenuEvent The event to handle.
---@param callback function The function to execute.
function Menu.RegisterEventHandler(event, callback) end

---@param event eMenuEvent.HwndProc The event to handle.
---@param callback fun(hWnd: integer, uMsg: integer, wParam: integer, lParam: integer) The function to execute.
function Menu.RegisterEventHandler(event, callback) end

---@param event eMenuEvent.PlayerJoin The event to handle.
---@param callback fun(playerName: string, playerId: integer) The function to execute.
function Menu.RegisterEventHandler(event, callback) end

---@param event eMenuEvent.PlayerLeave The event to handle.
---@param callback fun(playerName: string) The function to execute.
function Menu.RegisterEventHandler(event, callback) end

---@param event eMenuEvent.ScriptedGameEventReceived The event to handle.
---@param callback fun(playerId: integer, eventArgs: { [integer]: integer }): boolean The function to execute.
function Menu.RegisterEventHandler(event, callback) end

---@param event eMenuEvent.ChatMessageReceived The event to handle.
---@param callback fun(playerId: integer, chatMsg: string) The function to execute.
function Menu.RegisterEventHandler(event, callback) end

-- Registers an ImGui function to be drawn in the menu.
--
-- NOTE: This is currently a work in progress and each script is only allowed one callback registration.
---@param callback function 
function Menu.RegisterImGui(callback) end

-- Unloads the caller script.
function Menu.UnloadThisModule() end
