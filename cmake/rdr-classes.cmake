include(FetchContent)

message(STATUS "RDR-Classes")

FetchContent_Declare(
    RDR-Classes
    GIT_REPOSITORY https://github.com/YimMenu/RDR-Classes.git
    GIT_TAG        a61459d3b100408f736f32046ed2545dc729e617
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(RDR-Classes)
set_property(TARGET RDR-Classes PROPERTY CXX_STANDARD 23)