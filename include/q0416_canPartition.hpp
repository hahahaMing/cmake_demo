//
// Created by ming on 2020/10/11.
//

#ifndef CMAKETEST_Q0416_CANPARTITION_HPP
#define CMAKETEST_Q0416_CANPARTITION_HPP

#endif //CMAKETEST_Q0416_CANPARTITION_HPP

#include"tools.hpp"

class Solution {
public:
    bool canPartition(std::vector<int> &nums) {
        /*
         * 先求全部的和，然后使用动态规划进行求解，如果没有装满的可能就返回false
         */
        int sum = 0;
        for (int num:nums)sum += num;
        if (sum % 2 == 1)return false;
        int half = sum / 2;
        std::vector<int> dp(half + 1, 0);//存储背包剩余空间为j时的最大存储量
        for (int num:nums) {
            // 下面向背包里试着装第i件物品
            // 倒序防止同一个物品被重复使用
            for (int j = half; j >= num; j--) {
                dp[j] = std::max(dp[j], dp[j - num] + num);
            }
            if (dp[half] == half)return true;
        }
        return false;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
        nums = {1,5,11,5};
        std::cout << canPartition(nums) << std::endl;
        nums = {1,2,3,5};
        std::cout << canPartition(nums) << std::endl;
    }
};