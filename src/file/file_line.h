//
// Created by Henry Langmack on 6/25/21.
//

#ifndef HLTE_FILE_LINE_H
#define HLTE_FILE_LINE_H

#include <stddef.h>

typedef struct {
    char** data;
    size_t length;
} FileLine;

#endif //HLTE_FILE_LINE_H
