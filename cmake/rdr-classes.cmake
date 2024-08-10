include(FetchContent)

message(STATUS "RDR-Classes")

FetchContent_Declare(
    RDR-Classes
    GIT_REPOSITORY https://github.com/YimMenu/RDR-Classes.git
    GIT_TAG        fe55483ceaaae7b14fad984a495b07272679bd5d
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(RDR-Classes)
set_property(TARGET RDR-Classes PROPERTY CXX_STANDARD 23)