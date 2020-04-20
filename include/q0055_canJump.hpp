//
// Created by ming on 2020/4/17.
//

#ifndef CMAKETEST_Q0055_CANJUMP_HPP
#define CMAKETEST_Q0055_CANJUMP_HPP

#endif //CMAKETEST_Q0055_CANJUMP_HPP

#include "tools.hpp"

class Solution {
public:
    bool canJump(std::vector<int> &nums) {
        if (nums.empty()) return true;
        int len = nums.size();
        int far = 0;
        for (int i = 0; i < len; i++) {
            if (far < i)return false;
            far = std::max(far, i + nums[i]);
            if (far >= len - 1)return true;
        }
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;

        nums = {0};//
        std::cout << canJump(nums) << std::endl;

        nums = {2, 3, 1, 1, 4};//
        std::cout << canJump(nums) << std::endl;

        nums = {3, 2, 1, 0, 4};//
        std::cout << canJump(nums) << std::endl;

    }
};