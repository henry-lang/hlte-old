#ifndef HLTE_INPUT_H
#define HLTE_INPUT_H

typedef enum {
    CHARACTER,
    BACKSPACE,
    NEWLINE
} InputType;

typedef struct {
    InputType type;
    int key; // Actual keycode
    int y, x; // Where was the cursor when this input occurred?
} Input;

#endif //HLTE_INPUT_H
