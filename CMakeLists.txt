cmake_minimum_required(VERSION 2.6)
project(cappserver)

add_definitions(-Werror -Wall -Wextra -pedantic -std=c89)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")
INSTALL(FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/cappserver.h" DESTINATION include)

add_subdirectory(server)
add_subdirectory(testmodule)

