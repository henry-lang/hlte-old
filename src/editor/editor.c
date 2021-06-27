#include <stdlib.h>
#include <stdbool.h>

#include "editor.h"
#include "string.h"

#include "../terminal/terminal.h"
#include "../terminal/input.h"

Editor* editor_init(char* file_path) {
    Editor* editor = malloc(sizeof(Editor));
    editor->open = true;
    editor->cursor = cursor_init();
    editor->file_path = string_init(file_path);
    editor->lines = list_init();
    // We don't care if the file path isn't null since I haven't implemented file loading yet...
    list_push(editor->lines, string_init(""));

    return editor;
}

void editor_display(Editor* editor) {
    terminal_clear();

    int top = editor->scroll_y;
    int bottom = top + terminal_get_height() - 1;
    for(int line = top; line < bottom; line++) {
        terminal_display(line - editor->scroll_y + 1, 0, "%3d", line + 1);
    }

    terminal_move_cursor(editor->cursor.y, editor->cursor.x);

    terminal_flush();
}

void editor_get_input(Editor* editor) {
    Input input = terminal_get_input(editor);

    switch(input.type) {
        case CHARACTER: {

            break;
        }
        case BACKSPACE: {


            break;
        }
        case NEWLINE: {


            break;
        }
        case MOVEMENT: {


            break;
        }
        case KEYBIND: {
            switch(input.key) {
                case 3:  { // CTRL + C
                    editor_close(editor);
                    break;
                }

            }

            break;
        }
    }
}

void editor_close(Editor* editor) {
    editor->open = false;
}

void editor_free(Editor* editor) {
    list_clear_free(editor->lines, (void*) string_free);
    string_free(editor->file_path);
    list_free(editor->lines);
    free(editor);
}