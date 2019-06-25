cmake_minimum_required(VERSION 2.8)

project(portal2d)

##
## Config
##

set(RELEASE ON)

if(RELEASE)
    # Client
    set(ASSETS_DIRECTORY /var/portal2d)
    set(CLIENT_CONF_DIRECTORY /etc/portal2d/conf)

    # Server
    set(SERVER_CONF_DIRECTORY /etc/portal2d/conf)
    set(MAPS_DIRECTORY /etc/portal2d/maps)

    # Client & Server
    set(BIN_DIRECTORY /usr/bin)

    # g++ flag: -O0 or -O3
    set(OPTIMIZE_BINARIES -O3)
else()
    # Client
    set(ASSETS_DIRECTORY ../data)
    set(CLIENT_CONF_DIRECTORY ../data/conf)

    # Server
    set(SERVER_CONF_DIRECTORY ../data/conf)
    set(MAPS_DIRECTORY ../data/maps)

    # g++ flag: -O0 or -O3
    set(OPTIMIZE_BINARIES -O0)
endif()

##
## Sources
##

file(GLOB_RECURSE client_sources src/client/*)
file(GLOB_RECURSE server_sources src/server/*)
file(GLOB_RECURSE common_sources src/common/*)

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

##
## Dependencies
##

include(FindPkgConfig)

# SDL2
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

# QtWidgets
find_package(Qt5Widgets REQUIRED)

# YAML
pkg_search_module(YAML_CPP REQUIRED yaml-cpp)

# Box2D
pkg_search_module(BOX2D REQUIRED box2d)

include_directories(include/ ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2MIXER_INCLUDE_DIRS} ${YAML_CPP_INCLUDEDIR})

##
## Executables
##

add_compile_options(-std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors ${OPTIMIZE_BINARIES} -ggdb -DDEBUG -fno-inline)
add_definitions(
    -DCLIENT_CONF_FILE="${CLIENT_CONF_DIRECTORY}/client.conf"
    -DSERVER_CONF_FILE="${SERVER_CONF_DIRECTORY}/server.conf"
    -DASSETS_DIRECTORY="${ASSETS_DIRECTORY}/"
    -DMAPS_DIRECTORY="${MAPS_DIRECTORY}/")

# Client
add_executable(client src/client_main.cpp ${client_sources} ${common_sources})
target_link_libraries(client "-pthread" ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES} Qt5::Widgets ${YAML_CPP_LIBRARIES})
set_target_properties(client PROPERTIES OUTPUT_NAME portal2d)

# Server
add_executable(server src/server_main.cpp ${server_sources} ${common_sources})
target_link_libraries(server "-pthread" ${BOX2D_LIBRARIES} ${YAML_CPP_LIBRARIES})
set_target_properties(server PROPERTIES OUTPUT_NAME portal2d-server)

##
## Install
##

if(RELEASE)
    install(TARGETS client DESTINATION ${BIN_DIRECTORY})
    install(DIRECTORY data/sounds data/sprites DESTINATION ${ASSETS_DIRECTORY})
    install(FILES data/conf/client.conf DESTINATION ${CLIENT_CONF_DIRECTORY})

    install(TARGETS server DESTINATION ${BIN_DIRECTORY})
    install(DIRECTORY data/maps/ DESTINATION ${MAPS_DIRECTORY})
    install(FILES data/conf/server.conf DESTINATION ${SERVER_CONF_DIRECTORY})
endif()

##
## Tests
##

# Interface-Test
# Client
add_executable(interface-test-client EXCLUDE_FROM_ALL ${test_interface_client_sources})
target_link_libraries(interface-test-client "-pthread")
# Server
add_executable(interface-test-server EXCLUDE_FROM_ALL ${test_interface_server_sources})
target_link_libraries(interface-test-server "-pthread")

add_custom_target(interface-test DEPENDS interface-test-client interface-test-server)

# View Test
add_executable(view-test EXCLUDE_FROM_ALL ${test_sources} ${client_sources} ${common_sources})
target_include_directories(view-test PRIVATE test/include)
target_include_directories(view-test PRIVATE lib/Catch2)
target_link_libraries(view-test "-pthread" ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES} Qt5::Widgets ${YAML_CPP_LIBRARIES})

add_custom_target(tests DEPENDS interface-test view-test)
