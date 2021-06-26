#include <ncurses.h>
#include <stdbool.h>

#include "../globals.h"

#include "terminal.h"
#include "input.h"

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

void terminal_end() {
    endwin();
}

void terminal_display(int y, int x, char* format, ...) {
    move(y, x);
    va_list args;
    va_start(args, format);
    vw_printw(stdscr, format, args);
    va_end(args);
}

void terminal_flush() {
    refresh();
}

Input terminal_get_input() {
    int raw_key = getch();
    Input input;

    if(raw_key == 3) {
        editor->open = false;
    }
}

int terminal_get_width() {
    return getmaxx(stdscr);
}

int terminal_get_height() {
    return getmaxy(stdscr);
}
