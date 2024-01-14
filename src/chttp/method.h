#include <stdbool.h>

#ifndef METHOD_H
#define METHOD_H

#define MAX_CHARS 8

typedef struct
{
    char value[MAX_CHARS];
} Method;

bool compareMethod(Method * a, Method * b);

void setMethod(Method * target, char * input);

#endif