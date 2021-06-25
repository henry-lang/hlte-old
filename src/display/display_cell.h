//
// Created by henry on 6/24/21.
//

#ifndef HLTE_DISPLAY_CELL_H
#define HLTE_DISPLAY_CELL_H

#include "../terminal/terminal_formatting.h"

typedef struct {
    char value;
    int foreground_color;
    int background_color;
} DisplayCell;

#endif //HLTE_DISPLAY_CELL_H
