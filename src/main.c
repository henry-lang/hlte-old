#include <stdio.h>
#include <stdbool.h>


#include "globals.h"
#include "editor/editor.h"
#include "terminal/terminal.h"

Editor* MAIN_EDITOR;

int main() {
    terminal_init();

    MAIN_EDITOR = editor_init("");

    while(MAIN_EDITOR->open) {
        editor_display(MAIN_EDITOR);
        editor_get_input(MAIN_EDITOR);
    }

    editor_free(MAIN_EDITOR);
    terminal_end();

    return 0;
}
