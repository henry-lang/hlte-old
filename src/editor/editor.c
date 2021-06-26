#include <stdlib.h>

#include "editor.h"
#include "../terminal/terminal.h"

Editor* editor_init() {
    Editor* editor = malloc(sizeof(Editor));
    editor->
}

void editor_display(Editor* editor) {
    terminal_clear();
    terminal_display(5, 5, "Hello, world!");
    terminal_flush();
}

void editor_get_input(Editor* editor) {
    terminal_get_input();
}