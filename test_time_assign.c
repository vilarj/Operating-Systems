#include "unity.h"
#include "time.h"

void setUp (void) {}
void tearDown (void) {}

/**
 * Test if regular assign works
 */
void test_assign(void) {
    struct time result = time_assign(42, 5);
    TEST_ASSERT_EQUAL(42, result.seconds);
    TEST_ASSERT_EQUAL(5, result.milli);
}

/**
 * Test if assign with overflow works
 */
void test_assign_overflow(void) {
    struct time result = time_assign(42, 1005);
    TEST_ASSERT_EQUAL(43, result.seconds);
    TEST_ASSERT_EQUAL(5, result.milli);
}

/**
 * Test if assign with larger overflow works
 */
void test_assign_overflow2(void) {
    struct time result = time_assign(42, 2013);
    TEST_ASSERT_EQUAL(44, result.seconds);
    TEST_ASSERT_EQUAL(13, result.milli);
}

/**
 * Test if assign with underflow works
 */
void test_assign_underflow(void) {
    struct time result = time_assign(42, -100);
    TEST_ASSERT_EQUAL(41, result.seconds);
    TEST_ASSERT_EQUAL(900, result.milli);
}

/**
 * The main function for this unit test runner
 */
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_assign);
    RUN_TEST(test_assign_overflow);
    RUN_TEST(test_assign_overflow2);
    RUN_TEST(test_assign_underflow);
    return UNITY_END();
}
