#include <sys/ioctl.h>
#include <stdio.h>

#include "terminal.h"

TerminalDimensions terminal_get_dimensions() {
    winsize size;
    ioctl(0, TIOCGWINSZ, &size);
    return (TerminalDimensions) {
        .y = size.ws_row,
        .x = size.ws_col
    };
}

void terminal_goto(int y, int x) {
    printf("%c[%d;%df", 0x1B, y, x);
}

void terminal_set_colors(int foreground_color, int background_color) {
    printf("%c[%d;%dm", 0x1b, foreground_color, background_color);
}

void terminal_clear(int background_color) {
    terminal_goto(0, 0);
    terminal_set_colors(0, background_color);
    printf("%c[2J", 0x1b);
    terminal_set_colors(0, 0);
}