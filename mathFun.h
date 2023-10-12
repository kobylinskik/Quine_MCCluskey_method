#ifndef __MATH_FUN__
#define __MATH_FUN__

#include <map>
#include <set>

namespace mathFun {
    int countOnes(int x);
    bool isPowerOfTwo(int num);
    int getBitwiseDifference(int a, int b);
    bool differByOneBit(int a, int b);
    std::map<int, std::set<int>> mapIntsToNumberOfOnes(std::set<int> nums);
}

#endif