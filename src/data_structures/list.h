#ifndef LIST_H
#define LIST_H
//what
#define INITIAL_SIZE 1

#include <stdbool.h>

typedef struct {
    unsigned int curr_length;
    unsigned int alloc_length;
    void** data;
} List;

List* list_init();
void list_free(List* list);

void list_push(List* list, void* value);
void list_pop(List* list);
void list_pop_free(List* list, void free_func(void* reference, ...));

void list_insert(List* list, void* value, size_t index);
void list_remove(List* list, size_t index);
void list_remove_free(List* list, size_t index, void free_func(void* reference, ...));

void list_set(List* list, size_t index, void* value);
void* list_get(List* list, size_t index);
#define list_get_cast(list, index, type) ((type*) list_get(list, index))

size_t list_length(List* list);

void list_clear(List* list);
void list_clear_free(List* list, void free_func(void* reference, ...));
bool list_grow(List* list);
bool list_shrink(List* list);

#endif // LIST_H
