#include "unity.h"
#include "stats.h"

void setUp (void) {}
void tearDown (void) {}

/**
 * Test if array of length 0 returns 0 as its average
 */
void test_zeros(void) {
    int array[0];
    float result = array_averages(array, 0);
    TEST_ASSERT_EQUAL_FLOAT(0.0, result);
}

/**
 * Test if array of a single 0 returns 0 as its average
 */
void test_one_zero(void) {
    int array[] = {0};
    float result = array_averages(array, 1);
    TEST_ASSERT_EQUAL_FLOAT(0.0, result);
}

/**
 * Test if array of a two 0s returns 0 as its average
 */
void test_two_zeros(void) {
    int array[] = {0, 0};
    float result = array_averages(array, 2);
    TEST_ASSERT_EQUAL_FLOAT(0.0, result);
}

/**
 * Test if array of a 2 and 3 returns 2.5 as its average
 */
void test_even_odd(void) {
    int array[] = {2, 3};
    float result = array_averages(array, 2);
    TEST_ASSERT_EQUAL_FLOAT(2.5, result);
}

/**
 * Test if array of 4 numbers returns its average
 */
void test_four(void) {
    int array[] = {13, 14, 15, 16};
    float result = array_averages(array, 4);
    TEST_ASSERT_EQUAL_FLOAT(14.5, result);
}

/**
 * Test if array of 5 numbers returns its average
 */
void test_five(void) {
    int array[] = {12, 13, 14, 15, 16};
    float result = array_averages(array, 5);
    TEST_ASSERT_EQUAL_FLOAT(14, result);
}

/**
 * Test if an invalid array length is handled properly
 */
void test_wrong_length_negative(void) {
    int array[] = {12};
    float result = array_averages(array, -1);
    TEST_ASSERT_EQUAL_FLOAT(0, result);
}

/**
 * Test if an NULL array is handled properly
 */
void test_null_array(void) {
    float result = array_averages(NULL, 1);
    TEST_ASSERT_EQUAL_FLOAT(0, result);
}

/**
 * The main function for this unit test runner
 */
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_zeros);
    RUN_TEST(test_one_zero);
    RUN_TEST(test_two_zeros);
    RUN_TEST(test_even_odd);
    RUN_TEST(test_four);
    RUN_TEST(test_five);
    RUN_TEST(test_wrong_length_negative);
    RUN_TEST(test_null_array);
    return UNITY_END();
}
