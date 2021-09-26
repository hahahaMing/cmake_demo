//
// Created by ming on 2020/12/12.
//

#ifndef CMAKETEST_Q0376_WIGGLEMAXLENGTH_HPP
#define CMAKETEST_Q0376_WIGGLEMAXLENGTH_HPP

#endif //CMAKETEST_Q0376_WIGGLEMAXLENGTH_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
public:
    int wiggleMaxLength(std::vector<int> &nums) {
        /*
         * 存以每位为结尾的两种最长摆动子序列的长度
         */
        if (nums.empty())return 0;
        int len = nums.size();
        std::vector<int> up(2, 0), down(2, 0), tmp(2, 0);//存以上升结尾的最长子序列中的最大结尾数,以下降结尾的最长子序列中的最小结尾数
        up[0] = down[0] = nums[0];
        up[1] = down[1] = 1;
        for (int num:nums) {
            tmp[0] = up[0];
            tmp[1] = up[1];

            if (num > down[0]) {
                if (down[1] + 1 > up[1]) {
                    up = {num, down[1] + 1};
                } else if (down[1] + 1 == up[1]) {
                    if (num > up[0])up[0] = num;
                }
            }
            if (num < tmp[0]) {
                if (tmp[1] + 1 > down[1]) {
                    down = {num, tmp[1] + 1};
                } else if (tmp[1] + 1 == down[1]) {
                    if (num < down[0])down[0] = num;
                }
            }
        }
        return std::max(up[1],down[1]);
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
        nums = {1,7,4,9,2,5};
        std::cout << wiggleMaxLength(nums) << std::endl;
        nums = {1,17,5,10,13,15,10,5,16,8};
        std::cout << wiggleMaxLength(nums) << std::endl;
        nums = {1,2,3,4,5,6,7,8,9};
        std::cout << wiggleMaxLength(nums) << std::endl;


//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};