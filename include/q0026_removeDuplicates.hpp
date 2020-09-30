//
// Created by ming on 2020/8/3.
//

#ifndef CMAKETEST_Q0026_REMOVEDUPLICATES_HPP
#define CMAKETEST_Q0026_REMOVEDUPLICATES_HPP

#endif //CMAKETEST_Q0026_REMOVEDUPLICATES_HPP

#include"tools.hpp"

class Solution {
public:
    int removeDuplicates(std::vector<int> &nums) {
        /*
         * 记录rst为当前排好序的位置，i为当前遍历的位置
         * 当i上的数出现不同，改变rst和nums[rst]
         */
        if (nums.empty())return 0;
        int rst = 0, k = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != k) {
                k = nums[i];
                rst++;
                nums[rst] = k;
            }
        }
        return rst + 1;
    }

    void test() {
        std::cout << "test start" << std::endl;

    }
};