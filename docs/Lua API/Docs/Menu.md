<!-- markdownlint-disable -->

# Menu

The main bridge between Lua and the menu.

Exposes functions to register menu events, UI tabs and callbacks, commands, etc.

## Methods

## `RegisterEventHandler`

```lua
function Menu.RegisterEventHandler(event, callback) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `event` | `eMenuEvent` | The event to handle. |
| `callback` | `function` | The function to execute. |

## `RegisterEventHandler`

```lua
function Menu.RegisterEventHandler(event, callback) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `event` | `eMenuEvent.HwndProc` | The event to handle. |
| `callback` | `fun(hWnd: integer, uMsg: integer, wParam: integer, lParam: integer)` | The function to execute. |

## `RegisterEventHandler`

```lua
function Menu.RegisterEventHandler(event, callback) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `event` | `eMenuEvent.PlayerJoin` | The event to handle. |
| `callback` | `fun(playerName: string, playerId: integer)` | The function to execute. |

## `RegisterEventHandler`

```lua
function Menu.RegisterEventHandler(event, callback) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `event` | `eMenuEvent.PlayerLeave` | The event to handle. |
| `callback` | `fun(playerName: string)` | The function to execute. |

## `RegisterEventHandler`

```lua
function Menu.RegisterEventHandler(event, callback) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `event` | `eMenuEvent.ScriptedGameEventReceived` | The event to handle. |
| `callback` | `fun(playerId: integer, eventArgs: { [integer]: integer }): boolean` | The function to execute. |

## `RegisterEventHandler`

```lua
function Menu.RegisterEventHandler(event, callback) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `event` | `eMenuEvent.ChatMessageReceived` | The event to handle. |
| `callback` | `fun(playerId: integer, chatMsg: string)` | The function to execute. |

## `RegisterImGui`

```lua
function Menu.RegisterImGui(callback) end
```

Registers an ImGui function to be drawn in the menu.

NOTE: This is currently a work in progress and each script is only allowed one callback registration.

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `callback` | `function` |  |

## `UnloadThisModule`

```lua
function Menu.UnloadThisModule() end
```

Unloads the caller script.
