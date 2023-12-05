#include "status.h"
#include "field.h"
#include "version.h"

#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#define MAX_FIELDS 10

typedef struct HttpResponse_t
{
    Version version;
    Status status;
    Field fields[MAX_FIELDS];
    char *body;
};

#endif
