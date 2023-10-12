#include "mathFun.h"

namespace mathFun {
    int countOnes(int x) {
        int ones = 0;
        int current = 1;
        while (x) {
            if (x & current) {
                ones++;
                x &= ~current;
            }
            current *= 2;
        }
        return ones;
    }

    bool isPowerOfTwo(int num) {
        return num != 0 && (num & (num - 1)) == 0;
    }

    bool differByOneBit(int a, int b) {
        return isPowerOfTwo(a ^ b);
    }

    std::map<int, std::set<int>> mapIntsToNumberOfOnes(std::set<int> nums) {
        std::map<int, std::set<int>> result;
        for (int num : nums) {
            int numberOfOnes = countOnes(num);
            if (result.find(numberOfOnes) == result.end()) {
                result[numberOfOnes] = std::set<int>{num};
            } else {
                result[numberOfOnes].insert(num);
            }
        }
        return result;
    }
}