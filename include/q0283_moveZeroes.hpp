//
// Created by ming on 2020/11/19.
//

#ifndef CMAKETEST_Q0283_MOVEZEROES_HPP
#define CMAKETEST_Q0283_MOVEZEROES_HPP

#endif //CMAKETEST_Q0283_MOVEZEROES_HPP

#include"tools.hpp"

class Solution {
public:
    void moveZeroes(std::vector<int> &nums) {
        int n = nums.size();
        int z = 0, o = 0;
        while (o < n) {
            while (z < n && nums[z] != 0)z++;
            while (o < n && nums[o] == 0)o++;
            if (o >= n || z >= n)return;
            if (z < o) std::swap(nums[z], nums[o]);
            else o++;
        }
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
//        nums = {0, 1};
//        moveZeroes(nums);
//        tools::printVectorInt(nums);
        nums = {1, 0};
        moveZeroes(nums);
        tools::printVectorInt(nums);
        nums = {0,1,0,3,12};
        moveZeroes(nums);
        tools::printVectorInt(nums);

    }
};