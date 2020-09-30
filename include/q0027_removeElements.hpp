//
// Created by ming on 2020/8/3.
//

#ifndef CMAKETEST_Q0027_REMOVEELEMENTS_HPP
#define CMAKETEST_Q0027_REMOVEELEMENTS_HPP

#endif //CMAKETEST_Q0027_REMOVEELEMENTS_HPP

#include"tools.hpp"

class Solution {
public:
    int removeElement(std::vector<int> &nums, int val) {
        int i = 0, j = 0;
        while (i < nums.size()) {
            while (nums[i] == val)i++;
            if(i < nums.size())nums[j++] = nums[i++];
        }
        return j;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
        int val;
        nums = {2, 3, 3, 2, 3};
        val = 3;
        std::cout <<removeElement(nums,val)<< std::endl;
        tools::printVectorInt(nums);

    }
};