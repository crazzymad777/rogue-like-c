cmake_minimum_required(VERSION 2.8.9)
project (rogue-like-c)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(rogue-like-c src/main.c src/game.c)
target_link_libraries(rogue-like-c ${CURSES_LIBRARY})

