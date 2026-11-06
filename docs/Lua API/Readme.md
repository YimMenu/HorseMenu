<!-- markdownlint-disable MD046 -->

# Lua API

## Plugin Structure

Lua scripts must be placed in their own subfolders inside `%AppData%\Terminus\scripts` and **MUST** have a main entry file named exactly `main.lua` _(case-sensitive)_. You can have as many subfolders and files as you want inside your plugin directory, but only `main.lua` will be loaded.

```bash
├─ Terminus/
│  ├─ scripts/
│  │  ├─ disabled/      # disabled modules.
│  │  ├─ shared/        # shared scripts. Files placed here will not be automatically loaded and must be manually required by scripts that need them (ex: JSON parsers, standard library utils, etc.)
│  │  └─ MyLuaScript    # Your script.
│  │     ├─ includes/   # Optional subfolder to neatly store any other files that may be required by your plugin. Folder name and contents do not matter to the menu.
│  │     ├─ meta.json   # Optional metadata file.
│  │     └─ main.lua    # Your script's entry point. Without this file, your script will not be loaded.
```

### Optional Metadata

Script developers can place a `meta.json` file next to their `main.lua`. This file will tell the menu who the author of the script is, which version it's currently at, and most importantly, what to use as your script's name. If the metadata file isn't present then the root folder's name will be used instead.

- **Example `meta.json`:

```JSON
{
    "author": "AwesomeDev",
    "name": "Business Manager",
    "description": "A Lua script that manages your Red Dead Online businesses.",
    "version": "2.0.0.8"
}
```

## Language Server

To have type hints in your code editor, follow these steps:

1. Install Lua Language Server *([VS Code Extension](https://marketplace.visualstudio.com/items?itemName=sumneko.lua), [GitHub repository](https://github.com/LuaLS/lua-language-server))*.
2. Download the [/LuaLS](./LuaLS/) folder and note down the path where you saved it.
3. For Visual Studio Code users, create a `.code-workspace` file in your script folder *(next to your `main.lua` file)* and paste this in it:

    ```JSON
    {
        "folders": [
            {
                "path": ".",
            },
        ],
        "settings": {
            "Lua.runtime.version": "LuaJIT",
            "Lua.runtime.enableLuaJITExtensions": true,
            "Lua.workspace.checkThirdParty": false,
            "Lua.workspace.library": [
                "C:\\Path\\To\\LuaLSFolder"
            ],
            "Lua.runtime.builtin": {
                "debug": "disable"
            },
        }
    }
    ```

## API Docs

Markdown documentation for the API's bindings are in the [/Docs](./Docs/) folder.

## Lua Version Specification

The embedded version is LuaJIT v2.1 with 3.0 extensions backport. These extensions include:

- **Bit Operators:**

    ```Lua
    local x = a & b
    local y = a | b
    local z = a ~ b
    local w = ~a
    local foo = a << 4
    local bar = a >> 2
    local baz = a ~>> 0
    ```

- **C-style Operators:**

    ```Lua
    if a != b then ... end
    if !value then ... end
    if a && b then ... end
    if a || b then ... end
    ```

- **Ternary:**

    ```Lua
    local x = condition ? first : second
    ```

- **`nil` Coalescing:**

    ```Lua
    local x = value ?? fallback
    local y = maybeTable?.value
    local z = Class:MaybeMethod?(args)
    ```

- **Compound Assignment:**

    ```Lua
    i += 1
    bs &= mask
    str ..= "foo"
    ```

- **Other Additions:**

    ```Lua
    continue
    const x = 123
    local fn = (x, y) => x + y
    local n = 1_000_000
    ```

You can learn more about 3.0 extensions at [LuaJIT#1475](https://github.com/LuaJIT/LuaJIT/issues/1475).
