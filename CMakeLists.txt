cmake_minimum_required(VERSION 3.19)
project(hlte C)

set(CMAKE_C_STANDARD 99)

add_executable(
        hlte
        src/main.c
        src/editor/editor.c
        src/editor/editor.h
        src/editor/cursor.h
        src/terminal/terminal.c
        src/terminal/terminal.h
        src/data_structures/string.c
        src/data_structures/string.h
        src/data_structures/list.c
        src/data_structures/list.h
        src/terminal/input.h src/globals.h)

find_package(Curses REQUIRED Curses)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})
