#include "status.h"
#include "field.h"

#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#define MAX_FIELDS 10

typedef struct HttpResponse_t
{
    Status status;
    Field fields[MAX_FIELDS];
    char *body;
};

#endif
