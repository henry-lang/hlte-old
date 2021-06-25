#include "editor.h"

void editor_init() {
    initscr();
    start_color();
    raw();
    refresh();
    noecho();
    keypad(stdscr, true);
}

void editor_display() {
    clear();
    move(5, 5);
    printw("%s", "Hello, world!");
    refresh();
}

void editor_get_input() {
    getch();
}