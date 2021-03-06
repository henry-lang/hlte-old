//
// I'm going to encapsulate everything from ncurses because it's a bit weird.
//

#ifndef HLTE_TERMINAL_H
#define HLTE_TERMINAL_H

#include "input.h"

bool terminal_init();
void terminal_clear();
void terminal_end();
void terminal_display(int y, int x, char* format, ...);
void terminal_move_cursor(int y, int x);
void terminal_flush();

Input terminal_get_input(Editor* editor);
int terminal_get_width();
int terminal_get_height();

#endif //HLTE_TERMINAL_H
