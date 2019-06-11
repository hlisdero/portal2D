cmake_minimum_required(VERSION 2.8)

project(portal2d)

# Sources
file(GLOB_RECURSE client_sources ${PROJECT_SOURCE_DIR}/src/client/*)
file(GLOB_RECURSE server_sources ${PROJECT_SOURCE_DIR}/src/server/*)
file(GLOB_RECURSE common_sources ${PROJECT_SOURCE_DIR}/src/common/*)

set(test_sources
    test/test_button.cpp test/character.cpp test/key_detector.cpp
    test/test_animation.cpp test/test_keyboard.cpp test/test_main.cpp
    test/test_mouse.cpp test/test_sound.cpp test/test_view_player_block.cpp)

set(test_interface_client_sources
    test/test_interface_client.cpp
    src/common/protocol/protocol.cpp src/common/protocol/abstract_thread.cpp
    src/common/socket/active_socket.cpp src/common/socket/socket.cpp
    src/common/events/view_event.cpp src/common/events/world_event.cpp
    src/common/objects/position.cpp src/common/objects/click_direction.cpp)

set(test_interface_server_sources
    test/test_interface_server.cpp
    src/common/protocol/protocol.cpp src/common/protocol/abstract_thread.cpp
    src/common/socket/active_socket.cpp src/common/socket/passive_socket.cpp
    src/common/socket/socket.cpp src/common/events/view_event.cpp
    src/common/events/world_event.cpp src/common/objects/position.cpp
    src/common/objects/click_direction.cpp)

# Include packages
include(FindPkgConfig)
# SDL2
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

# QtWidgets
find_package(Qt5Widgets)

# YAML
pkg_search_module(YAML_CPP REQUIRED yaml-cpp)

# Box2D
pkg_search_module(BOX2D REQUIRED box2d)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS} ${YAML_CPP_INCLUDEDIR})

# Executables
# be sure there's exactly one main() function in the source files

# Client
add_executable(client src/client_main.cpp ${client_sources} ${common_sources})
target_include_directories(client PRIVATE ${PROJECT_SOURCE_DIR}/include/)
target_compile_options(client PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline)
target_link_libraries(client "-pthread" ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES} Qt5::Widgets)

# Server
add_executable(server src/server_main.cpp ${server_sources} ${common_sources})
target_include_directories(server PRIVATE ${PROJECT_SOURCE_DIR}/include/)
target_compile_options(server PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline)
target_link_libraries(server "-pthread" ${BOX2D_LIBRARIES} ${YAML_CPP_LIBRARIES})

# Game
add_custom_target(game DEPENDS client server)

# Interface-Test
# Client
add_executable(interface-test-client ${test_interface_client_sources})
target_include_directories(interface-test-client PRIVATE ${PROJECT_SOURCE_DIR}/include/)
target_compile_options(interface-test-client PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline)
target_link_libraries(interface-test-client "-pthread")
# Server
add_executable(interface-test-server ${test_interface_server_sources})
target_include_directories(interface-test-server PRIVATE ${PROJECT_SOURCE_DIR}/include/)
target_compile_options(interface-test-server PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline)
target_link_libraries(interface-test-server "-pthread")

add_custom_target(interface-test DEPENDS interface-test-client interface-test-server)

# View Test
add_executable(view-test ${test_sources} ${client_sources} ${common_sources})
target_include_directories(view-test PRIVATE ${PROJECT_SOURCE_DIR}/include/)
target_include_directories(view-test PRIVATE ${PROJECT_SOURCE_DIR}/test/include)
target_include_directories(view-test PRIVATE ${PROJECT_SOURCE_DIR}/lib/Catch2)
target_compile_options(view-test PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline)
target_link_libraries(view-test "-pthread" ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES} Qt5::Widgets)
