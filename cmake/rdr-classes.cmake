include(FetchContent)

FetchContent_Declare(
    rdr_classes
    GIT_REPOSITORY https://github.com/YimMenu/RDR-Classes.git
    GIT_TAG        6bf009fae77419a9a1e249ddb711987422cf9822
    GIT_PROGRESS TRUE
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
)
message("RDR-Classes")
if(NOT rdr_classes_POPULATED)
    FetchContent_Populate(rdr_classes)
endif()