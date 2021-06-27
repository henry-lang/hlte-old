#include <string.h>
#include <stdlib.h>

#include "string.h"

String* string_init(char* source) {
    String* string = malloc(sizeof(String));
    string->length = strlen(source) + 1;
    string->data = malloc(sizeof(char) * string->length);
    strcpy(string->data, source);

    return string;
}

void string_set(String* string, char* source) {
    string->length = strlen(source);
    char* new = realloc(string->data, sizeof(char) * string->length + 1);
    if(new == NULL) return;
    string->data = new;

    strcpy(string->data, source);
}

void string_insert(String* string, char* to_insert, int index) {
    string->length = string->length + strlen(to_insert);
    char* new = realloc(string->data, sizeof(char) * string->length + 1);
    if(new == NULL) return;
    memcpy(string->data, new);7
    strcat(buffer, to_insert);

    memcpy(string->data, );
}

void string_append(String* string, char* to_append) {

}

void string_free(String* string) {
    free(string->data);
    free(string);
}