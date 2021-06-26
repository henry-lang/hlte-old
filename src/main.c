#include <stdio.h>
#include <stdbool.h>


#include "globals.h"
#include "editor/editor.h"
#include "terminal/terminal.h"

Editor* editor;

int main() {
    terminal_init();

    editor = editor_init("");

    while(editor->open) {
        editor_display(editor);
        editor_get_input(editor);
    }

    editor_free(editor);
    terminal_end();

    return 0;
}
