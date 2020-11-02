#include "unity.h"
#include "time.h"

void setUp (void) {}
void tearDown (void) {}

/**
 * Test if same time returns diff 0
 */
void test_diff_equals(void) {
    struct time t1 = time_assign(42, 100);
    struct time t2 = time_assign(42, 100);
    int result = time_diff_in_milli(t1, t2);
    TEST_ASSERT_EQUAL(0, result);
}

/**
 * Test if large - small returns proper diff
 */
void test_diff_large_small(void) {
    struct time t1 = time_assign(42, 100);
    struct time t2 = time_assign(42, 50);
    int result = time_diff_in_milli(t1, t2);
    TEST_ASSERT_EQUAL(50, result);
}

/**
 * Test if small - large returns negative correctly
 */
void test_diff_small_large(void) {
    struct time t1 = time_assign(42, 50);
    struct time t2 = time_assign(42, 100);
    int result = time_diff_in_milli(t1, t2);
    TEST_ASSERT_EQUAL(-50, result);
}

/**
 * Test very large t1 and and small t2
 */
void test_diff_very_large_small(void) {
    struct time t1 = time_assign(43, 100);
    struct time t2 = time_assign(42, 50);
    int result = time_diff_in_milli(t1, t2);
    TEST_ASSERT_EQUAL(1050, result);
}

/**
 * Test millisecond overflow
 */
void test_diff_large_small_milli_overflow(void) {
    struct time t1 = time_assign(43, 50);
    struct time t2 = time_assign(42, 100);
    int result = time_diff_in_milli(t1, t2);
    TEST_ASSERT_EQUAL(950, result);
}

/**
 * Test negative diff
 */
void test_diff_small_negative(void) {
    struct time t1 = time_assign(0, 50);
    struct time t2 = time_assign(0, 100);
    int result = time_diff_in_milli(t1, t2);
    TEST_ASSERT_EQUAL(-50, result);
}

/**
 * Test if two negative times work
 */
void test_diff_negative_negative(void) {
    struct time t1 = time_assign(-1, 50);
    struct time t2 = time_assign(-1, 100);
    int result = time_diff_in_milli(t1, t2);
    TEST_ASSERT_EQUAL(-50, result);
}

/**
 * Test if t1 is postive and t2 negative
 */
void test_diff_positive_negative(void) {
    struct time t1 = time_assign(0, 50);
    struct time t2 = time_assign(-1, 500);
    int result = time_diff_in_milli(t1, t2);
    TEST_ASSERT_EQUAL(550, result);
}

/**
 * Test if t1 is negative and t2 positive
 */
void test_diff_negative_positive(void) {
    struct time t1 = time_assign(-1, 50);
    struct time t2 = time_assign(1, 100);
    int result = time_diff_in_milli(t1, t2);
    TEST_ASSERT_EQUAL(-2050, result);
}

/**
 * The main function for this unit test runner
 */
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_diff_equals);
    RUN_TEST(test_diff_large_small);
    RUN_TEST(test_diff_small_large);
    RUN_TEST(test_diff_very_large_small);
    RUN_TEST(test_diff_large_small_milli_overflow);
    RUN_TEST(test_diff_small_negative);
    RUN_TEST(test_diff_negative_negative);
    RUN_TEST(test_diff_positive_negative);
    RUN_TEST(test_diff_negative_positive);
    return UNITY_END();
}
