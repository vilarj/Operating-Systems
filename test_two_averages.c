#include "unity.h"
#include "stats.h"

void setUp (void) {}
void tearDown (void) {}

/**
 * Test if average of 0 is still 0
 */
void test_zeros(void) {
    float result = two_averages(0, 0);
    TEST_ASSERT_EQUAL_FLOAT(0.0, result);
}

/**
 * Test if average of 2 and 0 is 1
 */
void test_two_zero(void) {
    float result = two_averages(2, 0);
    TEST_ASSERT_EQUAL_FLOAT(1.0, result);
}

/**
 * Test if average of 0 and 2 is 1
 */
void test_zero_two(void) {
    float result = two_averages(0, 2);
    TEST_ASSERT_EQUAL_FLOAT(1.0, result);
}

/**
 * Test if average of 1 and 1 is 1
 */
void test_one_one(void) {
    float result = two_averages(1, 1);
    TEST_ASSERT_EQUAL_FLOAT(1.0, result);
}

/**
 * Test if average of 2 and 1 is 1.5
 */
void test_even_odd(void) {
    float result = two_averages(2, 1);
    TEST_ASSERT_EQUAL_FLOAT(1.5, result);
}

/**
 * Test if average of -5 and 4 is -0.5
 */
void test_plus_minus(void) {
    float result = two_averages(-5, 4);
    TEST_ASSERT_EQUAL_FLOAT(-0.5, result);
}

/**
 * The main function for this unit test runner
 */
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_zeros);
    RUN_TEST(test_two_zero);
    RUN_TEST(test_zero_two);
    RUN_TEST(test_one_one);
    RUN_TEST(test_even_odd);
    RUN_TEST(test_plus_minus);
    return UNITY_END();
}
