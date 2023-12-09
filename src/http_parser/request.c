#include "request.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int compareHttpRequest(
//     HttpRequest_t *req1,
//     HttpRequest_t *req2
// ) {
//     // Compare method and route
//     if(req1->method.value != req2->method.value ||
//        req1->route.value != req2->route.value
//     )
//     {
//         return 0; // Not equal
//     }

//     return 1;
// }

// Função que compara dois HttpRequest_t
int compareHttpRequests(const HttpRequest_t *req1, const HttpRequest_t *req2)
{
    // Comparação dos membros individuais
    if (req1->method.value != req2->method.value ||
        strcmp(req1->route.value, req2->route.value) != 0 ||
        strcmp(req1->version.value, req2->version.value) != 0)
    {
        return 0; // Não são iguais
    }

    // Comparação dos campos da struct Field
    for (int i = 0; i < MAX_FIELDS; ++i)
    {
        if (req1->fields[i].key == NULL && req2->fields[i].key == NULL)
        {
            break; // Ambos os campos são nulos, termina o loop
        }

        // Comparação dos campos individuais da struct Field
        if (strcmp(req1->fields[i].key, req2->fields[i].key) != 0 ||
            strcmp(req1->fields[i].value, req2->fields[i].value) != 0)
        {
            return 0; // Não são iguais
        }
    }

    // Comparação do corpo da requisição (body)
    if (strcmp(req1->body, req2->body) != 0)
    {
        return 0; // Não são iguais
    }

    return 1; // São iguais
}