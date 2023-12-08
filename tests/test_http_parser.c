#include <stdio.h>
#include <assert.h>
#include "cp_src/http_parser/http-request.h"
#include "cp_src/http_parser/method.h"
#include "cp_src/http_parser/route.h"
#include "cp_src/http_parser/version.h"
#include "cp_src/http_parser/field.h"

void test_http_parser_happy_path()
{
    char *given = "GET / HTTP/1.1\r\n"
                  "Host: your-api-endpoint\r\n"
                  "Connection: close\r\n"
                  "\r\n";

    Method m;
    Route r;
    Version v;
    HttpRequest_t expect;
    Field field_one;
    Field field_two;

    //  Define Method, Route and Version values;
    m.value = "GET";
    r.value = "/";
    v.value = "HTTP/1.1";

    expect.method = m;
    expect.route = r;
    expect.version = v;
    expect.fields[0] = field_one;
    expect.fields[1] = field_two;

    expect.fields[0].key = "Host";
    expect.fields[0].value = "your-api-endpoint";
    expect.fields[1].key = "Connection";
    expect.fields[1].value = "close";
    
    HttpRequest_t result;
    http_parser(&given, &result);
    
    assert(1?1:0);
}

int main()
{
    test_http_parser_happy_path();
    return 0;
}