//
// Created by ming on 2021/1/10.
//

#ifndef CMAKETEST_Q0228_SUMMARYRANGES_HPP
#define CMAKETEST_Q0228_SUMMARYRANGES_HPP

#endif //CMAKETEST_Q0228_SUMMARYRANGES_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int> &nums) {
        int low, high;
        int i = 0, n = nums.size();
        std::vector<std::string> rst;
        while (i < n) {
            low = nums[i++];
            high = low;
            while (i < n && nums[i] == high + 1) {
                i++;
                high++;
            }
            if (low == high)rst.push_back(std::to_string(low));
            else rst.push_back(std::to_string(low) + "->" + std::to_string(high));
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
        nums = {0,1,2,4,5,7};
        tools::printVectorString(summaryRanges(nums));
        nums = {0,2,3,4,6,8,9};
        tools::printVectorString(summaryRanges(nums));
        nums = {};
        tools::printVectorString(summaryRanges(nums));
        nums = {-1};
        tools::printVectorString(summaryRanges(nums));



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};