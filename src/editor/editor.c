#include "editor.h"
#include "../terminal/terminal.h"

void editor_init() {

}

void editor_display() {
    terminal_clear();
    terminal_display(5, 5, "Hello, world!");
    terminal_flush();
}

void editor_get_input() {
    terminal_get_input();
}