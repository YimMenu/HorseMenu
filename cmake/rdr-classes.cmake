include(FetchContent)

message(STATUS "RDR-Classes")

FetchContent_Declare(
    RDR-Classes
    GIT_REPOSITORY https://github.com/YimMenu/RDR-Classes.git
    GIT_TAG        ec19493aedc48e3fe0860342484058e48204dda2
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(RDR-Classes)
set_property(TARGET RDR-Classes PROPERTY CXX_STANDARD 23)