<!-- markdownlint-disable -->

# Player

## Constructors

```lua
Player(pid)
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `pid` | `integer` | The player's ID (0-31). |
## Methods

## `IsValid`

```lua
function Player:IsValid() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsModder`

```lua
function Player:IsModder() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsHost`

```lua
function Player:IsHost() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `IsFriend`

```lua
function Player:IsFriend() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` |  |

## `GetName`

```lua
function Player:GetName() end
```

### Returns

| Type | Description |
| --- | --- |
| `string` |  |

## `GetId`

```lua
function Player:GetId() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` | pid The player's ID (0-31). |

## `GetRID`

```lua
function Player:GetRID() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` | rid The player's Rockstar ID. |

## `GetPed`

```lua
function Player:GetPed() end
```

### Returns

| Type | Description |
| --- | --- |
| `Ped` | ped The player's [Ped](./Ped.md) class instance. |

## `GetRank`

```lua
function Player:GetRank() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` | ped The player's current rank. |

## `GetHonor`

```lua
function Player:GetHonor() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` | ped The player's current honor. |

## `GetRegionIndex`

```lua
function Player:GetRegionIndex() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` | region The player's current region number. |

## `GetRegionName`

```lua
function Player:GetRegionName() end
```

### Returns

| Type | Description |
| --- | --- |
| `string` | region The player's current region name. |

## `GetDistrictIndex`

```lua
function Player:GetDistrictIndex() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` | district The player's camp location index. |

## `GetDistrictName`

```lua
function Player:GetDistrictName() end
```

### Returns

| Type | Description |
| --- | --- |
| `string` | district The player's camp location name. |

## `GetLanguageIndex`

```lua
function Player:GetLanguageIndex() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` | lang The player's current language index. |

## `GetLanguageName`

```lua
function Player:GetLanguageName() end
```

### Returns

| Type | Description |
| --- | --- |
| `string` | lang The player's current language name. |
