#include <stdio.h>
#include "terminal/terminal.h"
#include "terminal/terminal_formatting.h"

int main() {
    terminal_clear(100);
    terminal_set_colors(91, 100);
    TerminalDimensions dim = terminal_get_dimensions();
    printf("%zu %d\n", dim.x, dim.y);

    return 0;
}
