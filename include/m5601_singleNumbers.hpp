//
// Created by ming on 2020/4/28.
//

#ifndef CMAKETEST_M5601_SINGLENUMBERS_HPP
#define CMAKETEST_M5601_SINGLENUMBERS_HPP

#endif //CMAKETEST_M5601_SINGLENUMBERS_HPP

#include "tools.hpp"

class Solution {
public:
    std::vector<int> singleNumbers(std::vector<int> &nums) {
        int res = 0;
        for (auto i : nums) res ^= i;
        int flag = 1;
        while ((flag & res)==0)flag <<= 1;
        int a=0,b=0;
        for (auto i : nums) {
            if (i&flag) a^=i;
            else b^=i;
        }
        std::vector<int> rst={a,b};
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
        nums = {1,2,10,4,1,4,3,3};
        tools::printVectorInt(singleNumbers(nums));


    }

};