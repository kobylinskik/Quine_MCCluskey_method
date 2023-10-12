#include "Implicant.h"
#include "unity.h"
#include <stdint.h>
#include <stdlib.h>

void setUp(void) {
}

void tearDown(void) {
}

void shouldReturnTwoImplicantsDifferByOneBit(void) {
    int bits1{0x10000};
    int bits2{0x11000};
    std::set<int> wildcards{1, 4};
    Implicant imp1{bits1, wildcards};
    Implicant imp2{bits2, wildcards};
    TEST_ASSERT_TRUE(imp1.differsByOneBit(imp2));
}

void shouldReturnFalseOnTwoImplicantsDifferByOneBit_whenTheyDifferByTwoBits(void) {
    int bits1{0x10000};
    int bits2{0x11010};
    std::set<int> wildcards{1, 4};
    Implicant imp1{bits1, wildcards};
    Implicant imp2{bits2, wildcards};
    TEST_ASSERT_FALSE(imp1.differsByOneBit(imp2));
}

void shouldReturnFalseOnTwoImplicantsDifferByOneBit_whenTheyHaveDifferentWildcards(void) {
    int bits1{0x10000};
    int bits2{0x11000};
    std::set<int> wildcards1{1, 4};
    std::set<int> wildcards2{1};
    Implicant imp1{bits1, wildcards1};
    Implicant imp2{bits2, wildcards2};
    TEST_ASSERT_FALSE(imp1.differsByOneBit(imp2));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(shouldReturnTwoImplicantsDifferByOneBit);
    RUN_TEST(shouldReturnFalseOnTwoImplicantsDifferByOneBit_whenTheyDifferByTwoBits);
    RUN_TEST(shouldReturnFalseOnTwoImplicantsDifferByOneBit_whenTheyHaveDifferentWildcards);
    return UNITY_END();
}