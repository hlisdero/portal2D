cmake_minimum_required(VERSION 2.8)

project(portal2d)

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB_RECURSE client_sources ${PROJECT_SOURCE_DIR}/src/client/*)
file(GLOB_RECURSE server_sources ${PROJECT_SOURCE_DIR}/src/server/*)
file(GLOB_RECURSE common_sources ${PROJECT_SOURCE_DIR}/src/common/*)

# be sure there's exactly one main() function in the source files
add_executable(client ${client_sources} ${common_sources})
target_compile_options (client PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline)

add_executable(server ${server_sources} ${common_sources})
target_compile_options (server PRIVATE -std=c++11 -Wall -Wextra -Werror -pedantic -pedantic-errors -O0 -ggdb -DDEBUG -fno-inline)

target_link_libraries (server pthread)
