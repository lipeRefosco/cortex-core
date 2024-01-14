#include <string.h>
#include <stdbool.h>
#include "method.h"
#include "value.h"

bool compareMethod(Method * a, Method * b) {
    if(strlen(a->value) != strlen(b->value)) return false;

    // verify each character
    int counter = 0;

    do {
        if (a->value[counter] != b->value[counter]) return false;
        counter++;
    } while (counter <= strlen(a->value));

    return true;
}

void setMethod(Method * target, char * input)
{
    setValue(target->value, input);
}