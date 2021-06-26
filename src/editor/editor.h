#ifndef HLTE_EDITOR_H
#define HLTE_EDITOR_H

#include <stdbool.h>

#include "cursor.h"
#include "../data_structures/string.h"
#include "../data_structures/list.h"

// For now this is going to be the only editor, but in the future this will be used as an editor "panel"
// where multiple panels can be side by side.
typedef struct {
    bool open;
    Cursor cursor;
    int scroll_y, scroll_x;
    String* file_path;
    List* /*String*/ lines;
} Editor;

Editor* editor_init();
void editor_display(Editor* editor);
void editor_get_input(Editor* editor);
void editor_free(Editor* editor);

#endif //HLTE_EDITOR_H
