#include <stdio.h>
#include <assert.h>
#include "cp_src/chttp/request.h"
#include "cp_src/chttp/method.h"
#include "cp_src/chttp/route.h"
#include "cp_src/chttp/version.h"
#include "cp_src/chttp/field.h"

// Criação da variável de teste usando as structs fornecidas
HttpRequest_t referenceRequest;

char* test_http_compare_happy_path()
{
    HttpRequest_t expect = referenceRequest;

    assert(compareHttpRequests(&expect, &expect));
    return "PASS!";
}

char* test_http_compare_not_equal()
{

    HttpRequest_t req1 = referenceRequest;
    HttpRequest_t req2 = referenceRequest;
    req2.route.value = "/teste-not-equal";

    assert(compareHttpRequests(&req1, &req2) != 1);
    return "PASS!";
}

int main()
{
    // Preenchimento da variável de teste com os dados fornecidos
    referenceRequest.method.value = "GET";
    referenceRequest.route.value = "/";
    referenceRequest.version.value = "HTTP/1.1";

    // Preenchimento dos campos da struct Field (Host e Connection)
    referenceRequest.fields[0].key = "Host";
    referenceRequest.fields[0].value = "your-api-endpoint";
    referenceRequest.fields[1].key = "Connection";
    referenceRequest.fields[1].value = "close";

    // Corpo da requisição (vazio no exemplo)
    referenceRequest.body = "";

    printf("test_http_compare_happy_path: %s\n", test_http_compare_happy_path());
    printf("test_http_compare_not_equal: %s\n", test_http_compare_not_equal());

    return 0;
}