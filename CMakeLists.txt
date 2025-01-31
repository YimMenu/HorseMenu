cmake_minimum_required(VERSION 3.20.x)

project(Terminus VERSION 0.0.1 DESCRIPTION "Terminus, a beta-stage mod menu for Red Dead Redemption 2 and Red Dead Online, inspired by YimMenu, that protects against crashes and enhances your experience.")

# libs
include(cmake/vulkan.cmake)
include(cmake/async-logger.cmake)
include(cmake/imgui.cmake)
include(cmake/json.cmake)
include(cmake/minhook.cmake)
include(cmake/rdr-classes.cmake)


# source
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
file(GLOB_RECURSE SRC_FILES
    "${SRC_DIR}/**.hpp"
    "${SRC_DIR}/**.cpp"
)
set(DEPS_DIR "${PROJECT_SOURCE_DIR}/deps")

add_library(${PROJECT_NAME} MODULE ${SRC_FILES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)

target_precompile_headers(${PROJECT_NAME} PUBLIC "${SRC_DIR}/common.hpp")

message(STATUS "Setting up include directories.")
target_include_directories(${PROJECT_NAME} PRIVATE
    "${SRC_DIR}"
    "${imgui_SOURCE_DIR}"
    "${minhook_SOURCE_DIR}/include"    
    "${minhook_SOURCE_DIR}/src/hde"    
    "${RDR-Classes_SOURCE_DIR}"
    "${vulkan_SOURCE_DIR}/include"
)

message(STATUS "Setting up linked libraries")
target_link_libraries(${PROJECT_NAME} PRIVATE AsyncLogger imgui minhook nlohmann_json::nlohmann_json dbghelp RDR-Classes "${DEPS_DIR}/vulkan-1.lib")

add_compile_definitions("_CRT_SECURE_NO_WARNINGS" "NOMINMAX" "WIN32_LEAN_AND_MEAN")

if(MSVC)
    set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /LTCG /OPT:REF,ICF /GUARD:NO")
    string(REPLACE "/Ob1" "/Ob3" CMAKE_CXX_FLAGS_RELWITHDEBINFO ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
endif()