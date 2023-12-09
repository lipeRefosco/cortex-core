#include "status.h"
#include "field.h"
#include "version.h"

#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#define MAX_FIELDS 10

typedef struct
{
    Version version;
    Status status;
    Field fields;
    char *body;
} HttpResponse_t;

#endif
