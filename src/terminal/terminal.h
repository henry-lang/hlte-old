//
// I'm going to encapsulate everything from ncurses because it's a bit weird.
//

#ifndef HLTE_TERMINAL_H
#define HLTE_TERMINAL_H

void terminal_init();
void terminal_clear();
void terminal_display(int y, int x, char* str);
void terminal_flush();
void terminal_get_input();

#endif //HLTE_TERMINAL_H
