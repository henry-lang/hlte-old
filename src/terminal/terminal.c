#include <ncurses.h>

#include "terminal.h"

void terminal_init() {
        initscr();
        start_color();
        raw();
        refresh();
        noecho();
        keypad(stdscr, true);
}

void terminal_clear() {
    clear();
}

void terminal_display(int y, int x, char* str) {
    move(5, 5);
    printw("%s", str);
}

void terminal_flush() {
    refresh();
}

void terminal_get_input() {
    getch();
}
