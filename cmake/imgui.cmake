include(FetchContent)

set(LIB_NAME "imgui")
message(STATUS "Setting up ${LIB_NAME}")

FetchContent_Declare(
    ${LIB_NAME}
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG 8cc6eee295871bc8852c12372860a50b950d3f56
    GIT_PROGRESS TRUE
)

FetchContent_GetProperties(${LIB_NAME})

if(NOT imgui_POPULATED)
    FetchContent_Populate(${LIB_NAME})

    file(GLOB SRC_IMGUI
        "${imgui_SOURCE_DIR}/*.cpp"
        "${imgui_SOURCE_DIR}/*.h"
        "${imgui_SOURCE_DIR}/backends/imgui_impl_win32.*"
        "${imgui_SOURCE_DIR}/backends/imgui_impl_dx12.*"
        "${imgui_SOURCE_DIR}/backends/imgui_impl_vulkan.*"
        "${imgui_SOURCE_DIR}/misc/cpp/imgui_stdlib.*"
    )

    add_library(imgui STATIC ${SRC_IMGUI})
    source_group(TREE ${imgui_SOURCE_DIR} PREFIX "imgui" FILES ${SRC_IMGUI})
    target_include_directories(imgui PRIVATE
        "${imgui_SOURCE_DIR}"
        "${imgui_SOURCE_DIR}/backends"
        "${imgui_SOURCE_DIR}/misc/cpp"
        "${vulkan_SOURCE_DIR}/include"
    )
endif()