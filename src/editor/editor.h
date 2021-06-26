#ifndef HLTE_EDITOR_H
#define HLTE_EDITOR_H

#include <stdbool.h>

#include "cursor.h"
#include "../file/file_context.h"

// For now this is going to be the only editor, but in the future this will be used as an editor "panel"
// where multiple panels can be side by side.
typedef struct {
    Cursor cursor;
    FileContext file;
    int scroll_y, scroll_x;
} Editor;

void editor_init(Editor* editor);
void editor_display();
void editor_get_input();

#endif //HLTE_EDITOR_H
