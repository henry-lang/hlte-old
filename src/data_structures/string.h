#ifndef HLTE_STRING_H
#define HLTE_STRING_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    size_t capacity;
    size_t length;
    char* data;
} String;

String* string_init(const char* source);
void string_free(String* string);

//void string_set(String* string, const char* source);
void string_append(String* string, char to_append);
void string_insert(String* string, const char* to_insert, size_t index);

void string_remove(String* string, size_t index, size_t length);

bool string_has_space(String* string);
void string_realloc(String* string);

#endif //HLTE_STRING_H
