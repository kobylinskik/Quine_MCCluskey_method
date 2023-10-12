#include "mathFun.h"
#include "unity.h"
#include <stdint.h>
#include <stdlib.h>

using namespace mathFun;

void setUp(void) {
}

void tearDown(void) {
}

void shouldCountNumberOfOnesIn0(void) {
    int result = countOnes(0);
    TEST_ASSERT_EQUAL_INT(0, result);
}

void shouldCountNumberOfOnesIn1(void) {
    int result = countOnes(1);
    TEST_ASSERT_EQUAL_INT(1, result);
}

void shouldCountNumberOfOnesIn5(void) {
    int result = countOnes(5);
    TEST_ASSERT_EQUAL_INT(2, result);
}

void shouldCountNumberOfOnesIn15(void) {
    int result = countOnes(15);
    TEST_ASSERT_EQUAL_INT(4, result);
}

void shouldCountNumberOfOnesIn0x10101010(void) {
    int result = countOnes(0x10101010);
    TEST_ASSERT_EQUAL_INT(4, result);
}

void shouldSay0IsNotPowerOf2(void) {
    TEST_ASSERT_FALSE(isPowerOfTwo(0));
}

void shouldSay1IsPowerOf2(void) {
    TEST_ASSERT_TRUE(isPowerOfTwo(1));
}

void shouldSay2IsPowerOf2(void) {
    TEST_ASSERT_TRUE(isPowerOfTwo(2));
}

void shouldSay15IsNotPowerOf2(void) {
    TEST_ASSERT_FALSE(isPowerOfTwo(15));
}

void shouldSay0x100000IsPowerOf2(void) {
    TEST_ASSERT_TRUE(isPowerOfTwo(0x100000));
}

void shouldSay0x100010IsNotPowerOf2(void) {
    TEST_ASSERT_TRUE(isPowerOfTwo(0x100000));
}

void shouldSay0x1000And0x1010DifferByOneBit(void) {
    TEST_ASSERT_TRUE(differByOneBit(0x1000, 0x1010));
}

void shouldSay0x100And0x100DontDifferByOneBit(void) {
    TEST_ASSERT_FALSE(differByOneBit(0x100, 0x100));
}

void shouldSay0x100And0x111DontDifferByOneBit(void) {
    TEST_ASSERT_FALSE(differByOneBit(0x100, 0x111));
}

void shouldMapIntsTonNumberOfOnes(void) {
    std::set<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::map<int, std::set<int>> result = mapIntsToNumberOfOnes(nums);

    TEST_ASSERT_TRUE(result.find(1) != result.end());
    TEST_ASSERT_TRUE(result[1].find(1) != result[1].end());
    TEST_ASSERT_TRUE(result[1].find(2) != result[1].end());
    TEST_ASSERT_TRUE(result[1].find(4) != result[1].end());
    TEST_ASSERT_TRUE(result[1].find(8) != result[1].end());

    TEST_ASSERT_TRUE(result.find(2) != result.end());
    TEST_ASSERT_TRUE(result[2].find(3) != result[2].end());
    TEST_ASSERT_TRUE(result[2].find(5) != result[2].end());
    TEST_ASSERT_TRUE(result[2].find(9) != result[2].end());
    TEST_ASSERT_TRUE(result[2].find(10) != result[2].end());

    TEST_ASSERT_TRUE(result.find(3) != result.end());
    TEST_ASSERT_TRUE(result[3].find(7) != result[3].end());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(shouldCountNumberOfOnesIn0);
    RUN_TEST(shouldCountNumberOfOnesIn5);
    RUN_TEST(shouldCountNumberOfOnesIn1);
    RUN_TEST(shouldCountNumberOfOnesIn15);
    RUN_TEST(shouldCountNumberOfOnesIn0x10101010);

    RUN_TEST(shouldSay0IsNotPowerOf2);
    RUN_TEST(shouldSay1IsPowerOf2);
    RUN_TEST(shouldSay2IsPowerOf2);
    RUN_TEST(shouldSay15IsNotPowerOf2);
    RUN_TEST(shouldSay0x100000IsPowerOf2);
    RUN_TEST(shouldSay0x100010IsNotPowerOf2);

    RUN_TEST(shouldSay0x1000And0x1010DifferByOneBit);
    RUN_TEST(shouldSay0x100And0x100DontDifferByOneBit);
    RUN_TEST(shouldSay0x100And0x111DontDifferByOneBit);

    RUN_TEST(shouldMapIntsTonNumberOfOnes);
    return UNITY_END();
}
