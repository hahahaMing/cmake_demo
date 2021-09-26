//
// Created by ming on 2020/10/26.
//

#ifndef CMAKETEST_Q1365_SMALLERNUMBERSTHANCURRENT_HPP
#define CMAKETEST_Q1365_SMALLERNUMBERSTHANCURRENT_HPP

#endif //CMAKETEST_Q1365_SMALLERNUMBERSTHANCURRENT_HPP

#include"tools.hpp"

class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> rst(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums[j] < nums[i])rst[i]++;
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
        nums = {8, 1, 2, 2, 3};
        tools::printVectorInt(smallerNumbersThanCurrent(nums));

    }
};