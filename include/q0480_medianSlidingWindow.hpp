//
// Created by ming on 2021/2/3.
//

#ifndef CMAKETEST_Q0480_MEDIANSLIDINGWINDOW_HPP
#define CMAKETEST_Q0480_MEDIANSLIDINGWINDOW_HPP

#endif //CMAKETEST_Q0480_MEDIANSLIDINGWINDOW_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {

public:
    std::vector<double> medianSlidingWindow(std::vector<int> &nums, int k) {
        //维护两个数组，一个小于中位数，一个大于等于中位数，滑动更新
        int n = nums.size();
        std::vector<double> rst(n - k + 1);
        std::vector<int> lv, rv;
        int med = nums.front();
        int max_left, min_right;
        for (int i = 0; i < k; ++i) {
            if (nums[i] <)

        }


    }

    void test() {
        std::cout << "test start" << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};