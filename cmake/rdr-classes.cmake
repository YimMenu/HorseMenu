include(FetchContent)

FetchContent_Declare(
    rdr_classes
    GIT_REPOSITORY https://github.com/YimMenu/RDR-Classes.git
    GIT_TAG        99bae26b377a1075172caf4842889d24f8344054
    GIT_PROGRESS TRUE
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
)
message(STATUS "RDR-Classes")
if(NOT rdr_classes_POPULATED)
    FetchContent_Populate(rdr_classes)
endif()