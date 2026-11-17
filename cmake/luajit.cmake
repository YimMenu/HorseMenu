message(STATUS "Setting up LuaJIT 2.1")
set(LUAJIT_BUILD_TOOL OFF)
set(LUAJIT_FORCE_UTF8_FOPEN ON)

FetchContent_Declare(
    luajit
    GIT_REPOSITORY https://github.com/xesdoog/LuaJIT.git
    GIT_TAG        efdacd0aaa291d1e30282e10742c28949f83f81e
    GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(luajit)

target_compile_definitions(libluajit PRIVATE
	"_CRT_SECURE_NO_WARNINGS"
	"LUAJIT_ENABLE_LUA52COMPAT"
)
