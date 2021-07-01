#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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
    editor->scroll_y = editor->scroll_x = 0;
    // We don't care if the file path isn't null since I haven't implemented file loading yet...
    list_push(editor->lines, string_init(""));

    return editor;
}

void editor_display(Editor* editor) {
    terminal_clear();

    int top = editor->scroll_y;
    int bottom = terminal_get_height() - 1;
            //top + terminal_get_height() - 1;
    for(int line = top; line < bottom; line++) {
        String* current = editor_get_line(editor, line);
        if(current) {
            terminal_display(line - editor->scroll_y + 1, 0, "%3d", line + 1);
            terminal_display(line - editor->scroll_y + 1, 4, "%s", current->data);
        }
    }

    terminal_move_cursor(editor->cursor.y + 1, editor->cursor.x + 4);

    terminal_flush();
}

void editor_get_input(Editor* editor) {
    Input input = terminal_get_input(editor);
    String* line = editor_get_line(editor, editor->cursor.y);

    switch(input.type) {
        case CHARACTER: {
            string_append(line, (const char *) &(input.key));
            editor->cursor.x++;
            break;
        }

        case BACKSPACE: {
            string_remove(line, editor->cursor.x - 1);
            editor->cursor.x--;
            break;
        }
        case NEWLINE: {
            String* new_line = string_init("");
//                    string_substring(line, editor->cursor.x, line->length);
            editor_line_create(editor, new_line);
            editor->cursor.y++;
            editor->cursor.x = 0;
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

String* editor_get_line(Editor* editor, size_t line_num) {
    if(line_num >= list_length(editor->lines)) return NULL;

    return list_get(editor->lines, line_num);
}

void editor_line_create(Editor* editor, String* string) { // Appends a new line into the internal lines list.
    list_push(editor->lines, string);
}

void editor_line_remove(Editor* editor, size_t line_num) {
    if(line_num >= list_length(editor->lines)) return;

    list_remove_free(editor->lines, line_num, (void*) string_free);
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

