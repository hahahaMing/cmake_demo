//
// Created by ming on 2021/1/8.
//

#ifndef CMAKETEST_Q0189_ROTATE_HPP
#define CMAKETEST_Q0189_ROTATE_HPP

#endif //CMAKETEST_Q0189_ROTATE_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    void rotate(std::vector<int> &nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0)return;
        int start = 0, l_len = n - k, r_len = k;
        while (start < n && l_len > 0 && r_len > 0) {
            int tmp = std::min(l_len, r_len);
            for (int i = start; i < start + tmp; ++i) {
                std::swap(nums[i], nums[i + l_len]);
            }
            start += tmp;
            if (l_len<r_len){
                l_len = tmp;
                r_len = r_len-tmp;
            }else{
                l_len = l_len-tmp;
                r_len = tmp;
            }
            tools::printVectorInt(nums);
        }
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;

        for (int i = 0; i < 10; ++i) {
            nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            std::cout << "test start" << i << std::endl;
            rotate(nums, i);
        }



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};