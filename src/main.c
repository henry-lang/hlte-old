#include <stdio.h>
#include <stdbool.h>

#include "editor/editor.h"
#include "terminal/terminal.h"

bool running = true;

int main() {


    terminal_init();
    while(running) {
        editor_display();
        editor_get_input();
    }
    return 0;
}
