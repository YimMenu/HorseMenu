<!-- markdownlint-disable -->

# Vehicle

## Constructors

```lua
Vehicle(handle)
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `handle` | `integer` | The RAGE script handle of the vehicle. |
## Methods

## `IsDraft`

```lua
function Vehicle:IsDraft() end
```

### Returns

| Type | Description |
| --- | --- |
| `boolean` | isDraft Whether this vehicle is a draft animal vehicle. |

## `GetNumDraftAnimals`

```lua
function Vehicle:GetNumDraftAnimals() end
```

### Returns

| Type | Description |
| --- | --- |
| `integer` | numDrafts Number of draft animals attached to this vehicle. |

## `GetPedInHarness`

```lua
function Vehicle:GetPedInHarness(slot) end
```

### Parameters

| Name | Type | Description |
| --- | --- | --- |
| `slot` | `integer` | The harness slot index (0-5). |

### Returns

| Type | Description |
| --- | --- |
| `Ped` | ped The ped in the specified harness slot, if any. |
