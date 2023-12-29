#include "../request.h"

#ifndef PARSE_HTTP_H
#define PARSE_HTTP_H

void parseHttp(const HttpRequest_t * target , const char * raw[]);

void parseRequestLine(HttpRequest_t * target, int needle, const char raw[]);

#endif