#include "unity.h"
#include "string.h"

void setUp (void) {}
void tearDown (void) {}

/**
 * Size of the destination character array.
 * Note: This is C's way of declaring a constant value
 */
#define DEST_SIZE  (8)

/**
 * Test if empty string returns 0
 */
void test_empty_string(void) {
    char dest[DEST_SIZE];
    char *empty = "";
    int amount = string_copy(dest, empty, DEST_SIZE);

    TEST_ASSERT_EQUAL(0, amount);
}

/**
 * Test if s that fits in dest is properly copied
 */
void test_small_string(void) {
    char dest[DEST_SIZE];
    char *src = "Hello";
    int amount = string_copy(dest, src, DEST_SIZE);

    TEST_ASSERT_EQUAL(5, amount);
    TEST_ASSERT_EQUAL_STRING("Hello", dest);
}

/**
 * Test if s that's too large will be properly truncated
 */
void test_large_string(void) {
    char dest[DEST_SIZE];
    char *src = "1234567890";
    int amount = string_copy(dest, src, DEST_SIZE);

    TEST_ASSERT_EQUAL(DEST_SIZE-1, amount);
    TEST_ASSERT_EQUAL_STRING("1234567", dest);
}

/**
 * Test if dest being NULL is properly handled
 */
void test_null_destination(void) {
    char *empty = "";
    int amount = string_copy(NULL, empty, 1);

    TEST_ASSERT_EQUAL(-1, amount);
}

/**
 * Test if s being NULL is properly handled
 */
void test_null_source(void) {
    char dest[DEST_SIZE];
    int amount = string_copy(dest, NULL, DEST_SIZE);

    TEST_ASSERT_EQUAL(-1, amount);
}

/**
 * The main function for this unit test runner
 */
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_empty_string);
    RUN_TEST(test_small_string);
    RUN_TEST(test_large_string);
    RUN_TEST(test_null_destination);
    RUN_TEST(test_null_source);
    return UNITY_END();
}
