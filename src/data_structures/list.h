#ifndef LIST_H
#define LIST_H

#define INITIAL_SIZE 1

#include <stdbool.h>

typedef struct {
    unsigned int curr_length;
    unsigned int alloc_length;
    void** data;
} List;

List* list_init();
void list_free(List* int_list);

void list_push(List* int_list, void* value);
void list_pop(List* int_list);

void list_insert(List* int_list, void* value, size_t index);
void list_remove(List* int_list, size_t index);

void list_set(List* int_list, size_t index, void* value);
void* list_get(List* int_list, size_t index);

size_t list_length(List* int_list);

void list_clear(List* int_list);
bool list_grow(List* int_list);
bool list_shrink(List* int_list);

#endif // LIST_H
