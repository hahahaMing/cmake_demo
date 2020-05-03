//
// Created by ming on 2020/5/3.
//

#ifndef CMAKETEST_Q0053_MAXSUBARRAY_HPP
#define CMAKETEST_Q0053_MAXSUBARRAY_HPP

#endif //CMAKETEST_Q0053_MAXSUBARRAY_HPP

#include "tools.hpp"

class Solution {
public:
    int maxSubArray(std::vector<int> &nums) {
        //动态规划 记录计算末位的最大和与之前所有的最大和，每次更新
        int sum = 1<<31, tail_sum = 0, temp;
        for (auto i :nums) {
            temp = tail_sum + i;
            tail_sum = std::max(temp, i);
            sum = std::max(tail_sum,sum);
        }
        return sum;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;

        nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        std::cout << maxSubArray(nums) << std::endl;

        nums = {};
        std::cout << maxSubArray(nums) << std::endl;
    }
};