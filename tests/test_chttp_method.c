#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "cp_src/chttp/method.h"
#include "cp_src/chttp/value.h"

char* test_compareMethod_function_happy_path(Method * given)
{
    bool expect = true;
    assert(compareMethod(given, given) == expect);
    return "PASS";
}

char* test_compareMethod_function_with_different_lenghts(Method * given_three)
{
    bool expect = false;
    
    Method given_four;
    given_four.value[0] = 'G';
    given_four.value[1] = 'E';
    given_four.value[2] = 'T';
    given_four.value[3] = 'T';

    assert(compareMethod(given_three, &given_four) == expect);
    assert(compareMethod(&given_four, given_three) == expect);
    return "PASS";
}

char* test_setMethod_function_happy_path(Method * given_to_compare)
{
    bool expect = true;

    Method result;
    setMethod(&result, "GET");

    assert(compareMethod(given_to_compare, &result) == expect);
    assert(compareMethod(&result, given_to_compare) == expect);

    return "PASS";
}

int main (void) 
{
    Method reference;
    reference.value[0] = 'G';
    reference.value[1] = 'E';
    reference.value[2] = 'T';

    printf("Testing test_compareMethod_function: ");
    printf("%s\n", test_compareMethod_function_happy_path(&reference));

    printf("Testing test_compareMethod_function_with_different_lenghts: ");
    printf("%s\n", test_compareMethod_function_with_different_lenghts(&reference));

    printf("Testing test_setMethod_function_happy_path: ");
    printf("%s\n", test_setMethod_function_happy_path(&reference));

    return 0;
}