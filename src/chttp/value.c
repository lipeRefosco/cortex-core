#include "value.h"
#include <string.h>

void setValue(char target[], char input[])
{
    int i = 0;
    do {
        target[i] = input[i];
        i++;
    } while(i <= strlen(target));
}