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
void string_init_alloc(String* string, size_t size);
void string_set(String* string, const char* source);

bool string_insert(String* string, const char* to_insert, size_t index);
bool string_append(String* string, const char* to_append);

String* string_substring(String* string, size_t start, size_t end);

void string_remove(String* string, size_t index);

bool string_realloc(String* string, size_t size);

void string_free(String* string);

#endif //HLTE_STRING_H
