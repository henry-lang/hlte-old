typedef struct {
    int y, x;
} Cursor;

static inline Cursor cursor_init() {
    return (Cursor) {
            .y = 0,
            .x = 0
    };
}