include(FetchContent)

FetchContent_Declare(
    rdr_classes
    GIT_REPOSITORY https://github.com/maybegreat48/RDR-Classes.git
    GIT_TAG        67124a74bcfd54b3c8c857e67ce4b5c4aea533ac
    GIT_PROGRESS TRUE
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
)
message(STATUS "RDR-Classes")
if(NOT rdr_classes_POPULATED)
    FetchContent_Populate(rdr_classes)
endif()