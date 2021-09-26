//
// Created by ming on 2020/12/20.
//

#ifndef CMAKETEST_CONTEST1_HPP
#define CMAKETEST_CONTEST1_HPP

#endif //CMAKETEST_CONTEST1_HPP

#include"tools.hpp"

class Solution {
    int purchasePlans(std::vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size(), rst = 0;
        for (int i = 0; i < n; ++i) {
            rst += std::upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]) - (nums.begin() + i + 1);
        }
        return rst%1000000007;
    }

public:

    void test() {
        std::vector<int> nums;
        int target;
        nums = std::vector<int>(100000,2);
        target = 100;
        std::cout << purchasePlans(nums, target) << std::endl;
        nums = {2,2,1,9};
        target = 10;
        std::cout << purchasePlans(nums, target) << std::endl;


    }
};