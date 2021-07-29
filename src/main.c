#include <stdio.h>
#include <stdbool.h>

#include "globals.h"
#include "editor/editor.h"
#include "terminal/terminal.h"

Editor* MAIN_EDITOR;

int main(int argc, char** argv) {
    if(!(argc == 2 || argc == 1)) return 1; // Check argument count

    MAIN_EDITOR = editor_init();
    if(!editor_load_file(MAIN_EDITOR, argv[1])) {
        printf("%s: %s\n", "Unable to load file", argv[1]);
        return 1;
    }

    if(!terminal_init()) return 1;
    while(MAIN_EDITOR->open) {
        editor_display(MAIN_EDITOR);
        editor_get_input(MAIN_EDITOR);
    }

    editor_free(MAIN_EDITOR);
    terminal_end();

    return 0;
}
