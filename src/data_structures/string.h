#ifndef HLTE_STRING_H
#define HLTE_STRING_H

#include <stddef.h>

typedef struct {
    size_t length;
    char* data;
} String;

String* string_init(char* source);
void string_set(String* string, char* source);
void string_free(String* string);

#endif //HLTE_STRING_H
