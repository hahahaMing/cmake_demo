//
// Created by ming on 2020/11/7.
//

#ifndef CMAKETEST_Q0327_COUNTRANGESUM_HPP
#define CMAKETEST_Q0327_COUNTRANGESUM_HPP

#endif //CMAKETEST_Q0327_COUNTRANGESUM_HPP

#include"tools.hpp"

class Solution {
public:
    int countRangeSum(std::vector<int> &nums, int lower, int upper) {
//        std::vector<int> dp;
//        int rst = 0;
//        for (int num:nums) {
//            for (int &d:dp) {
//                d += num;
//                if (d >= lower && d <= upper)rst++;
//            }
//            dp.push_back(num);
//            if (num>=lower && num<=upper)rst++;
//        }
//        return rst;

        int n = nums.size(), sum = 0, rst = 0;
        std::vector<double> F(n, 0), L(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                F[0] = nums[0];
                L[n-1] = nums[n - 1];
            } else {
                F[i] = F[i - 1] + nums[i];
                L[n - i - 1] = L[n - i] + nums[n - i - 1];
            }
            sum += nums[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                double tmp = F[j] + L[i] - sum;
                if (tmp >= lower && tmp <= upper)rst++;
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
        int l, u;
        nums = {-2, 5, -1};
        l = -2;
        u = 2;
        std::cout << countRangeSum(nums, l, u) << std::endl;
        nums = {};
        l = -2;
        u = 2;
        std::cout << countRangeSum(nums, l, u) << std::endl;
        nums = {-2, 5, -1};
        l = -2;
        u = 5;
        std::cout << countRangeSum(nums, l, u) << std::endl;
        nums = {2147483647, -2147483648, -1, 0};
        l = -1;
        u = 0;
        std::cout << countRangeSum(nums, l, u) << std::endl;


    }
};