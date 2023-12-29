#include <stdio.h>
#include <unistd.h>
#include "parseHttp.h"

enum InternalState{
    METHOD=0,
    ROUTE,
    VERSION,
    EOL
};

void parseRequestLine(
    HttpRequest_t * target,
    int needle,
    const char raw[]
) {
    enum InternalState state = METHOD; 
    int endOfLine = 'n';
    
    printf("%s\n", target->method.value);
    printf("%c\n", raw[needle]);

    while(state != EOL ) {

        // printf("dentro do while\n");
        // // printf("end of line: %c\n", endOfLine);
        // printf("fita do request: %c\n", raw[needle]);
        // printf("state: %d\n", state);

        if(raw[needle] == ' ') {
            printf("dentro do separador espaco\n");
            state++;
            needle++;
            continue;
        }

        if(state == METHOD) {
            printf("dentro do state method\n");
            target->method.value = target->method.value + raw[needle];
            needle++;
            continue;
        }
        
        if(state == ROUTE) {
            printf("dentro do state route\n");
            target->route.value = target->route.value + raw[needle];
            needle++;
            continue;
        }
        
        if (state == VERSION) {
            printf("dentro do state version\n");
            target->version.value = target->version.value + raw[needle];
            needle++;
            continue;
        }

    }
}

// void parseHttp(
//     const HttpRequest_t * target,
//     const char * raw[]
// ) {
//     int count = 0;
//     target;
//     // While is not the end of request
//     while(raw[count] != 0)
//     {
//         printf("im here!!!!!!\n");
//     }
// }