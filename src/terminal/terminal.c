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

Input terminal_get_input(Editor* editor) {
    int raw_key = getch();
    Input input;

    if(raw_key > 31 && raw_key < 127) { // Any printable character... for now.. I'll add support for other character types later.
        input.type = CHARACTER;
    } else if(raw_key == 127 || raw_key == KEY_BACKSPACE) {
        input.type = BACKSPACE;
    } else if(raw_key == KEY_UP || raw_key == KEY_DOWN || raw_key == KEY_LEFT || raw_key == KEY_RIGHT) {
        input.type = NEWLINE;
    } else if(raw_key == 10 || raw_key == KEY_ENTER)

    input.key = raw_key;
    input.y = editor->cursor.y;
    input.x = editor->cursor.x;

    return input;
}

int terminal_get_width() {
    return getmaxx(stdscr);
}

int terminal_get_height() {
    return getmaxy(stdscr);
}
