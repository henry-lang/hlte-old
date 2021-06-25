#include <stdio.h>

#include "terminal/terminal.h"
#include "terminal/terminal_formatting.h"
#include "display/display_buffer.h"

DisplayBuffer* buffer;

int main() {
    TerminalDimensions dim = terminal_get_dimensions();
    buffer = display_buffer_init(dim.y * dim.x);
    display_buffer_render(buffer);

    display_buffer_free(buffer);

    return 0;
}
