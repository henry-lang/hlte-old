#include <stdio.h>
#include <stdbool.h>

#include "editor/editor.h"
#include "terminal/terminal.h"

bool editing = true;

int main() {
    terminal_init();
    while(editing) {
        editor_display();
        editor_get_input();
    }
    return 0;
}
