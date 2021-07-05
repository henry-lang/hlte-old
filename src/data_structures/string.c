#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "string.h"

String* string_init(const char* source) {
    size_t source_length = strlen(source);

    String* string = malloc(sizeof(String));
    string->length = source_length;
    string->capacity = source_length + 1;
    string->data = malloc(string->capacity);
    memcpy(string->data, source, string->length);
    string->data[string->length] = '\0';

    return string;
}

void string_free(String* string) {
    free(string->data);
    free(string);
}

void string_append(String* string, char to_append) {
//    if(string->capacity <= ) string_realloc(string);
//
//    string->data[string->length] = to_append;
//    string->length++;
//    string->data[string->length] = '\0';
}

void string_insert(String* string, const char* to_insert, size_t index) {
    size_t added_length = strlen(to_insert);
    size_t new_length = string->length + added_length;

    if(string->capacity <= new_length + 1) {
        char* new = malloc(new_length + 1);
        string->capacity = new_length + 1;

        memcpy(new, string->data, index);
        memcpy(&new[index + added_length], &string->data[index], string->length - index);
        free(string->data);
        string->data = new;
    } else {
        memmove(&string->data[index], &string->data[index + added_length], string->length - index);
    }
    string->length = new_length;
    memcpy(&string->data[index], to_insert, added_length);
    string->data[new_length] = '\0';
}

void string_remove(String* string, size_t index, size_t length) {
    memmove(&string->data[index], &string->data[index + length], string->length - index);
    string->length -= length;
    string->data[string->length] = '\0';
}

bool string_has_space(String* string) {
    return string->capacity - (string->length + 1) > 0;
}

void string_realloc(String* string) {
    string->capacity <<= 1;

    char* new = malloc(string->capacity);
    strcpy(new, string->data);
    free(string->data);
    string->data = new;
}