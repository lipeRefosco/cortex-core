#include "method.h"
#include "route.h"
#include "version.h"
#include "field.h"

#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#define MAX_FIELDS 10

typedef struct
{
    Method method;
    Route route;
    Version version;
    Field fields[MAX_FIELDS];
    char *body;
} HttpRequest_t;

int compareHttpRequests(const HttpRequest_t *req1, const HttpRequest_t *req2);

#endif