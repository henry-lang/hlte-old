#include <malloc.h>

#include "../terminal/terminal.h"
#include "../terminal/terminal_formatting.h"

#include "display_buffer.h"

DisplayBuffer* display_buffer_init(size_t size) {
    DisplayBuffer* buffer = malloc(sizeof(DisplayBuffer));
    DisplayCell* cells = malloc(sizeof(DisplayCell) * size);
    for(size_t i = 0; i < size; i++) {
        cells[i] = (DisplayCell) {
             .value = 'a',
             .foreground_color = 0,
             .background_color = TEXT_RED
        };
    }

    buffer->size = size;
    buffer->cells = cells;

    return buffer;
}

void display_buffer_free(DisplayBuffer* buffer) {
    free(buffer->cells);
    free(buffer);
}

void display_buffer_resize(DisplayBuffer* buffer, size_t size) {
    DisplayCell* new = realloc(buffer->cells, sizeof(DisplayCell) * size);
    if(new == NULL) return;

    buffer->size = size;
    buffer->cells = new;
}

void display_buffer_render(DisplayBuffer* buffer) {
    DisplayCell* current;
    terminal_goto(0, 0);
    for(int i = 0; i < buffer->size; i++) {
        current = &(buffer->cells[i]);
        terminal_set_colors(current->foreground_color, current->background_color);
        printf("%c", current->value);
    }
}