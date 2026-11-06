message(STATUS "Setting up Sol3")

FetchContent_Declare(
    sol2
    GIT_REPOSITORY https://github.com/ThePhD/sol2.git
    GIT_TAG        v3.3.0
	GIT_PROGRESS   TRUE
)
FetchContent_MakeAvailable(sol2)
