#include "cp_src/chttp/request.h"
#include "cp_src/chttp/httpParser/parseHttp.h"
#include <stdio.h>
#include <assert.h>

// Criação da variável de teste usando as structs fornecidas
HttpRequest_t expect;

char * test_parseHttp_happy_path()
{
    char *givenRequest = "GET / HTTP/1.1\r\n"
                  "Host: your-api-endpoint\r\n"
                  "Connection: close\r\n"
                  "\r\n";
    
    HttpRequest_t result;
    parseHttp(&result, givenRequest);
    
    assert(compareHttpRequests(&expect, &result));

    return "PASS!";
}

char * test_parseRequestLine_happy_path()
{
    char *givenRequestLine = "GET / HTTP/1.1\r\n";

    HttpRequest_t expect;
    expect.method.value = "GET";
    expect.route.value = "/";
    expect.version.value = "HTTP/1.1";

    HttpRequest_t result;
    
    parseRequestLine(&result, givenRequestLine);

    assert(compareHttpRequests(&expect, &result));
    
    return "PASS!";
}


void main()
{
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
    
    printf("test_parseHttp_happy_path: %s\n", test_parseHttp_happy_path());
    printf("test_parseRequestLine_happy_path: %s\n", test_parseRequestLine_happy_path());
}