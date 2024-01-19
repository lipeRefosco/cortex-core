#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "cp_src/chttp/value.h"

char* test_setValue_happypath_with_same_length()
{
    // Need have 8 because the max length of a method name is 7 + 1 (the last is '\0')
    char expect[4] = "GET";
    char result[4] = "   ";
    setValue(result, "GET");
    assert(valueIsEqual(expect, result));

    return "PASS";
}

char* test_setValue_with_differents_lengths_but_same_value()
{
    char expect[4] = "GET";
    char result[8] = "       ";

    setValue(result, "GET");
    assert(valueIsEqual(result, expect));

    return "PASS";
}

char* test_setValue_replace_value_with_same_array_length()
{
    char expect[8] = "GET";
    char result[8] = "CONNECT";
    setValue(result, "GET");
    assert(valueIsEqual(result, expect));

    return "PASS";
}

char* test_setValue_replace_value_on_array_length_less_than_input_length()
{
    char expect[4] = "CON";
    char result[4] = "   ";

    setValue(result, "CONNECT");

    assert(valueIsEqual(result, expect));

    return "PASS";
}

char* test_setValue_large_input()
{
    bool expect = true;
    char given[8] = "CONNECT";
    char result[8] = "       ";

    setValue(result, "CONNECT");
    assert(valueIsEqual(given, result) == expect);

    return "PASS";
}

int main(void)
{
    printf("Testing test_setValue_happypath_with_same_length: ");
    printf("%s\n", test_setValue_happypath_with_same_length());

    printf("Testing test_setValue_happypath_with_different_length: ");
    printf("%s\n", test_setValue_with_differents_lengths_but_same_value());

    printf("Testing test_setValue_replace_value_with_same_array_length: ");
    printf("%s\n", test_setValue_replace_value_with_same_array_length());

    printf("Testing test_setValue_replace_value_on_array_length_less_than_input_length: ");
    printf("%s\n", test_setValue_replace_value_on_array_length_less_than_input_length());

    printf("Testing test_setValue_large_input: ");
    printf("%s\n", test_setValue_large_input());


    return 0;
}