//
// Created by ming on 2021/1/2.
//

#ifndef CMAKETEST_Q0239_MAXSLIDINGWINDOW_HPP
#define CMAKETEST_Q0239_MAXSLIDINGWINDOW_HPP

#endif //CMAKETEST_Q0239_MAXSLIDINGWINDOW_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
        int n = nums.size();
        std::vector<int> rst(n - k + 1);
        int peak = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[peak])peak = i;
            else {
                if (i >= peak + k) {
                    peak = i;
                    for (int j = 0; j < k; ++j) {
                        if (nums[i - j] > nums[peak])peak = i - j;
                    }
                }
            }
            if (i >= k - 1)rst[i - k + 1] = nums[peak];
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
//        nums = {1, 3, -1, -3, 5, 3, 6, 7};
//        for (int i = 1; i <= nums.size(); ++i) {
//            tools::printVectorInt(nums);
//            tools::printVectorInt(maxSlidingWindow(nums, i));
//        }
//        nums = {1};
//        for (int i = 1; i <= nums.size(); ++i) {
//            tools::printVectorInt(nums);
//            tools::printVectorInt(maxSlidingWindow(nums, i));
//        }
//        nums = {1,-1};
//        for (int i = 1; i <= nums.size(); ++i) {
//            tools::printVectorInt(nums);
//            tools::printVectorInt(maxSlidingWindow(nums, i));
//        }
//        nums = {9,12};
//        for (int i = 1; i <= nums.size(); ++i) {
//            tools::printVectorInt(nums);
//            tools::printVectorInt(maxSlidingWindow(nums, i));
//        }
        nums = {1, 3, 1, 2, 0, 5};
        tools::printVectorInt(nums);
        tools::printVectorInt(maxSlidingWindow(nums, 3));



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//
//        for (int i = 0; i < 1; ++i) {
//            vec = tools::random_vector(rng, 1, 100000, -10000, 10000);
//            tools::printVectorInt(vec);
//            tools::printVectorInt(maxSlidingWindow(vec, 50000));
//        }
    }
};