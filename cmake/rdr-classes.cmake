include(FetchContent)

FetchContent_Declare(
    rdr_classes
    GIT_REPOSITORY https://github.com/maybegreat48/RDR-Classes.git
    GIT_TAG        64aacd51bb65a74e2bd9ab0e6e6b39a84dc09525
    GIT_PROGRESS TRUE
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
)
message("RDR-Classes")
if(NOT rdr_classes_POPULATED)
    FetchContent_Populate(rdr_classes)
endif()