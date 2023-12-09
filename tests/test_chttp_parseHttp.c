#include "cp_src/chttp/request.h"
#include <stdio.h>
#include <assert.h>

char * test_http_parser_happy_path()
{
    char *given = "GET / HTTP/1.1\r\n"
                  "Host: your-api-endpoint\r\n"
                  "Connection: close\r\n"
                  "\r\n";
    // Criação da variável de teste usando as structs fornecidas
    HttpRequest_t expect;

    // Preenchimento da variável de teste com os dados fornecidos
    expect.method.value = "GET";
    expect.route.value = "/";
    expect.version.value = "HTTP/1.1";

    // Preenchimento dos campos da struct Field (Host e Connection)
    expect.fields[0].key = "Host";
    expect.fields[0].value = "your-api-endpoint";
    expect.fields[1].key = "Connection";
    expect.fields[1].value = "close";

    // Corpo da requisição (vazio no exemplo)
    expect.body = "";
    
    HttpRequest_t result;
    parseHttp(&result, given);
    
    assert(compareHttpRequests(&expect, &result));

    return "PASS!";
}


void main()
{
    printf("test_http_compare_happy_path: %s\n", test_http_parser_happy_path());
}