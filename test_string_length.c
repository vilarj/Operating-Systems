#include "unity.h"
#include "string.h"
#include <stdlib.h>

void setUp (void) {}
void tearDown (void) {}

/**
 * Test if NULL argument returns -1 properly
 */
void test_null_string(void) {
    char* null_string = NULL;

    int length = get_string_length(null_string);
    TEST_ASSERT_EQUAL(-1, length);
}

/**
 * Test if empty string returns 0.
 */
void test_empty_string(void) {
    char* test_string = "";

    int length = get_string_length(test_string);
    TEST_ASSERT_EQUAL(0, length);
}

/**
 * Test if string of length 1 works
 */
void test_one_char(void) {
    char* test_string = "A";

    int length = get_string_length(test_string);
    TEST_ASSERT_EQUAL(1, length);
}

/**
 * Test if string of length 2 works
 */
void test_two_chars(void) {
    char* test_string = "ab";

    int length = get_string_length(test_string);
    TEST_ASSERT_EQUAL(length, 2);
}

/**
 * Test if string with special characters work
 */
void test_special_chars(void) {
    char* test_string = "... ;;;";

    int length = get_string_length(test_string);
    TEST_ASSERT_EQUAL(length, 7);
}

/**
 * Test if string with a "hole" inside still returns
 * the proper length
 */
void test_hole(void) {
    char* test_string = "AB\0DEFG";

    int length = get_string_length(test_string);
    TEST_ASSERT_EQUAL(length, 2);
}

/**
 * The main function for this unit test runner
 */
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_empty_string);
    RUN_TEST(test_one_char);
    RUN_TEST(test_two_chars);
    RUN_TEST(test_special_chars);
    RUN_TEST(test_hole);
    RUN_TEST(test_null_string);
    return UNITY_END();
}
