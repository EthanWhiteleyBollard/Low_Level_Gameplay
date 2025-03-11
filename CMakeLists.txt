cmake_minimum_required(VERSION 3.8)

project(lowlevel)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(lowlevel src/main.cpp "src/main.h" "src/Character/Player.cpp" "src/SpriteRender.h" "src/SpriteRender.cpp")

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
target_sources(lowlevel PRIVATE ${MY_SOURCES})
target_include_directories(lowlevel PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(lowlevel PRIVATE SFML::Graphics)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lowlevel PROPERTY CXX_STANDARD 20)
endif()
