//
// Created by henry on 6/24/21.
//

#ifndef HLTE_DISPLAY_BUFFER_H
#define HLTE_DISPLAY_BUFFER_H

#include <stddef.h>

#include "display_cell.h"

typedef struct {
    size_t size;
    DisplayCell* cells;
} DisplayBuffer;

DisplayBuffer* display_buffer_init(size_t size);
void display_buffer_free(DisplayBuffer* buffer);

void display_buffer_resize(DisplayBuffer* buffer, size_t size);

void display_buffer_render(DisplayBuffer* buffer);

#endif //HLTE_DISPLAY_BUFFER_H
