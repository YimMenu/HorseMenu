---@meta

---@enum eMenuEvent
eMenuEvent = {
	ScriptsReloaded = 0, -- Event that triggers when all Lua scripts are reloaded.
	HwndProc = 1, -- Event that triggers when a window procedure is called. Refer to [WNDPROC Win32 Apps](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nc-winuser-wndproc) for more information.
	PlayerJoin = 2, -- Event that triggers when a player joins the session.
	PlayerLeave = 3, -- Event that triggers when a player leaves the session.
	ScriptedGameEventReceived = 4, -- Event that triggers when we receive a scripted game event over the network.
	ChatMessageReceived = 5, -- Event that triggers when we receive a chat message over the network.
	MenuUnloaded = 6, -- Event that triggers when the menu is unloaded.
}
