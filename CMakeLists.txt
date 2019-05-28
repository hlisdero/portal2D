cmake_minimum_required(VERSION 2.8)

project(portal2d)

# Sources
file(GLOB_RECURSE client_sources ${PROJECT_SOURCE_DIR}/src/client/*)
file(GLOB_RECURSE server_sources ${PROJECT_SOURCE_DIR}/src/server/*)
file(GLOB_RECURSE common_sources ${PROJECT_SOURCE_DIR}/src/common/*)
file(GLOB_RECURSE game_sources ${PROJECT_SOURCE_DIR}/src/game/*)
file(GLOB_RECURSE test_sources ${PROJECT_SOURCE_DIR}/test/*)

# Include packages
include(FindPkgConfig)
# SDL2
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

# YAML
pkg_search_module(YAML_CPP REQUIRED yaml-cpp)

# Box2D
pkg_search_module(BOX2D REQUIRED box2d)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS} ${YAML_CPP_INCLUDEDIR})

# Executables
# be sure there's exactly one main() function in the source files

# Game
add_executable(game ${game_sources} ${common_sources} ${server_sources} ${client_sources})
target_include_directories(game PRIVATE ${PROJECT_SOURCE_DIR}/include/)
target_compile_options(game PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline)
target_link_libraries(game ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${BOX2D_LIBRARIES} ${YAML_CPP_LIBRARIES})

# View Test
add_executable(view-test ${test_sources} ${client_sources} ${common_sources})
target_include_directories(view-test PRIVATE ${PROJECT_SOURCE_DIR}/include/)
target_include_directories(view-test PRIVATE ${PROJECT_SOURCE_DIR}/test/include)
target_include_directories(view-test PRIVATE ${PROJECT_SOURCE_DIR}/lib/Catch2)
target_compile_options(view-test PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline)
target_link_libraries(view-test ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${YAML_CPP_LIBRARIES})
