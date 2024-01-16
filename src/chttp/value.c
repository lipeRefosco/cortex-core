#include "value.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int i;
int tgtSize;

void setValue(char *target, char *input)
{
    i = 0;
    tgtSize = strlen(target);

    do {
        target[i] = input[i];
        i++;
    } while (i < tgtSize);
}

bool valueIsEqual(char *a, char *b) {
  if (strcmp(a, b) != 0) return false;

  return true;
}