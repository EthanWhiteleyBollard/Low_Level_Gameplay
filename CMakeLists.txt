cmake_minimum_required(VERSION 3.8)

project(Low_Level_Gameplay)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(Low_Level_Gameplay "src/main.cpp"  "src/Game.cpp" "src/SpriteManager.h")

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
target_sources(Low_Level_Gameplay PRIVATE ${MY_SOURCES})
target_include_directories(Low_Level_Gameplay PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
file(COPY "Assets/" DESTINATION "Assets")
target_link_libraries(Low_Level_Gameplay PRIVATE SFML::Graphics)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Low_Level_Gameplay PROPERTY CXX_STANDARD 20)
endif()
