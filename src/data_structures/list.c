#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "list.h"

List* list_init() {
    List* list = malloc(sizeof(List));
    list->curr_length = 0;
    list->alloc_length = INITIAL_SIZE;
    list->data = malloc(INITIAL_SIZE * sizeof(void*));
    return list;
}

void list_free(List* list) {
    free(list->data);
    free(list);
}

void list_push(List* list, void* value) {
    list_insert(list, value, list->curr_length);
}

void list_pop(List* list) {
    list_remove(list, list->curr_length - 1);
}

void list_pop_free(List* list, void free_func(void* reference, ...)) {
    free_func(list->data[list->curr_length - 1]);
    // Pop freed pointer
    list_pop(list);
}

void list_insert(List* list, void* value, size_t index) {
    if (list->alloc_length == list->curr_length) {
        if (!list_grow(list)) return;
    }

    memmove(list->data+(index+1), list->data+index, (list->curr_length-index) * sizeof(void*));
    list->data[index] = value;
    list->curr_length++;
}

void list_remove(List* list, size_t index) {
    if (index == list->curr_length) return;
    memmove(list->data+index, list->data+(index+1), (list->curr_length-index) * sizeof(void*));

    list->curr_length--;
    if(list->curr_length < list->alloc_length >> 1) {
        list_shrink(list);
    }
}

void list_remove_free(List* list, size_t index, void free_func(void* reference, ...)) {
    free_func(list->data[index]);
    // Remove freed pointer
    list_remove(list, index);
}

void list_set(List* list, size_t index, void* value) {
    list->data[index] = value;
}

void* list_get(List* list, size_t index) {
    return list->data[index];
}

// #define list_get_cast(type, list, index) ((type*) list_get(list, index))

size_t list_length(List* list) {
    return list->curr_length;
}

bool list_grow(List* list) {
    unsigned int new_length = list->alloc_length << 1;
    void** new_data = realloc(list->data, sizeof(void*) * new_length);
    if(new_data != NULL) {
        list->data = new_data;
        list->alloc_length = new_length;
        return true;
    } else {
        printf("Failed to reallocate array.\n");
        return false;
    }
}

bool list_shrink(List* list) {
    unsigned int new_length = list->alloc_length >> 1;
    void** new_data = realloc(list->data, sizeof(void*) * new_length);
    if(new_data != NULL) {
        list->data = new_data;
        list->alloc_length = new_length;
        return true;
    } else {
        printf("Failed to reallocate array.\n");
        return false;
    }
}

void list_clear(List* list) {
    list->curr_length = 0;
    void** new_data = realloc(list->data, sizeof(void*) * INITIAL_SIZE);
    if(new_data != NULL) {
        list->data = new_data;
        list->alloc_length = INITIAL_SIZE;
    } else {
        printf("Failed to clear array?.\n");
    }
}

void list_clear_free(List* list, void free_func(void* reference, ...)) {
    for(int i = 0; i < list->curr_length; i++) {
        free_func(list->data[i]);
    }

    // Clear freed pointers
    list_clear(list);
}