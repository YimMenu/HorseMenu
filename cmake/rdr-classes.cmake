include(FetchContent)

message(STATUS "RDR-Classes")

FetchContent_Declare(
    RDR-Classes
    GIT_REPOSITORY https://github.com/YimMenu/RDR-Classes.git
    GIT_TAG        30ffb972079e1f61b7035d2dfc23d2ce642e7513
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(RDR-Classes)
set_property(TARGET RDR-Classes PROPERTY CXX_STANDARD 23)