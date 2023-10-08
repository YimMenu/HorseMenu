include(FetchContent)

FetchContent_Declare(
    rdr_classes
    GIT_REPOSITORY https://github.com/maybegreat48/RDR-Classes.git
    GIT_TAG        ed17a6a4aad5b90633531bf163f49660463d2dd9
    GIT_PROGRESS TRUE
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
)
message(STATUS "RDR-Classes")
if(NOT rdr_classes_POPULATED)
    FetchContent_Populate(rdr_classes)
endif()