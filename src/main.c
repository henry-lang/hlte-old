#include <stdio.h>

#include "editor/editor.h"

bool editing = true;

int main() {
    editor_init();
    while(editing) {
        editor_display();
        editor_get_input();
    }
    return 0;
}
