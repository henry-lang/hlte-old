#ifndef HLTE_EDITOR_H
#define HLTE_EDITOR_H

#include <stdbool.h>

#include "cursor.h"
#include "../data_structures/string.h"
#include "../data_structures/list.h"

// For now this is going to be the only editor, but in the future this will be used as an editor "panel"
// where multiple panels can be side by side.
typedef struct {
    String* file_path;
    FILE* file_context;
    bool open;
    Cursor cursor;
    int scroll_y, scroll_x;
    List* /*String*/ lines;
} Editor;

Editor* editor_init();
bool editor_load_file(Editor* editor, char* file_name);

void editor_display(Editor* editor);
void editor_get_input(Editor* editor);

String* editor_get_line(Editor* editor, size_t line_num);

void editor_line_create(Editor* editor, String* string);
void editor_line_remove(Editor* editor, size_t line_num);

void editor_close(Editor* editor);
void editor_free(Editor* editor);

#endif //HLTE_EDITOR_H
