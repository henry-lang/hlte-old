#ifndef HLTE_TERMINAL_H
#define HLTE_TERMINAL_H

#include <termios.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct winsize winsize;
typedef struct {
    size_t y, x;  // y first because terminals apparently *face_of_disapproval*
} TerminalDimensions;

TerminalDimensions terminal_get_dimensions();

void terminal_goto(int y, int x);

void terminal_set_colors(int foreground_color, int background_color);
void terminal_clear(int background_color);

bool terminal_is_pressed();


#endif //HLTE_TERMINAL_H
