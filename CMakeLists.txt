cmake_minimum_required(VERSION 2.8)

project(portal2d)

file(GLOB_RECURSE client_sources ${PROJECT_SOURCE_DIR}/src/client/*)
file(GLOB_RECURSE server_sources ${PROJECT_SOURCE_DIR}/src/server/*)
file(GLOB_RECURSE common_sources ${PROJECT_SOURCE_DIR}/src/common/*)
file(GLOB_RECURSE game_sources ${PROJECT_SOURCE_DIR}/src/game/*)
file(GLOB_RECURSE test_sources ${PROJECT_SOURCE_DIR}/test/*)

file(GLOB_RECURSE scenes ${PROJECT_SOURCE_DIR}/src/scenes/*)

# be sure there's exactly one main() function in the source files
# Client
add_executable(client ${client_sources} ${common_sources})
target_include_directories(client PRIVATE ${PROJECT_SOURCE_DIR}/include/)
target_compile_options (client PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline)

# Server
add_executable(server ${server_sources} ${common_sources})
target_include_directories(server PRIVATE ${PROJECT_SOURCE_DIR}/include/)
target_compile_options (server PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline)

# Game
add_executable(game ${game_sources})
target_include_directories(game PRIVATE ${PROJECT_SOURCE_DIR}/src/game/)
target_compile_options (game PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline)

# Scenes
add_executable(scenes ${scenes})
target_compile_options (scenes PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline)

# Test
add_executable(tests ${test_sources} ${common_sources})
target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/include/)
target_compile_options(tests PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors)

# Include SDL2
include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(YAML_CPP REQUIRED yaml-cpp)


pkg_search_module(BOX2D REQUIRED box2d)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${YAML_CPP_INCLUDEDIR})

target_link_libraries(client ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
target_link_libraries(server ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
target_link_libraries(tests ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
target_link_libraries(scenes ${YAML_CPP_LIBRARIES})

target_link_libraries(game ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${BOX2D_LIBRARIES})

# Include Catch2
target_include_directories(tests PRIVATE ${PROJECT_SOURCE_DIR}/lib/Catch2)
