cmake_minimum_required(VERSION 3.19)
project(hlte C)

set(CMAKE_C_STANDARD 99)

add_executable(hlte src/main.c src/terminal/terminal.c src/terminal/terminal.h src/terminal/terminal_formatting.h src/display/display_buffer.c src/display/display_buffer.h src/display/display_cell.h)