//
// Created by ming on 2020/5/26.
//

#ifndef CMAKETEST_Q0287_FINDDUPLICATE_HPP
#define CMAKETEST_Q0287_FINDDUPLICATE_HPP

#endif //CMAKETEST_Q0287_FINDDUPLICATE_HPP

#include"tools.hpp"

class Solution {
public:
    int findDuplicate(std::vector<int> &nums) {
        //可以记录 比x大的个数，比x小的个数，以及二者的和
        /** 方法1
         * 如果比x小的个数小于x-1
         *  rst比x大
         * 等于：未知
         * 大于：rst比x小
         *
         *具体就是二分
         *
         *
         *
         */
        int n = nums.size() - 1;
        int l = 1, r = n, m = (l + r) / 2;
        int small, large, same;
        while (true) {
            small = 0, large = 0, same = 0;
            for (int i:nums) {
                if (i < m && i >= l)small++;
                if (i == m)same++;
                if (i <= r && i > m) large++;
                //减少遍历次数，但增加判断次数
                if (same >= 2)return m;
                if (small > m - l) {
                    r = m, m = (l + r) / 2;
                    break;
                }
                if (large > r - m) {
                    if (r - l == 1)return r;
                    l = m, m = (l + r) / 2;
                    break;
                }

            }


        }
        return 1;
        /** 方法2
         * 求积，如果比正常的积大
         */

    }

    void test() {
        std::cout << "test start" << std::endl;

        std::vector<int> nums;
//        nums= {1,3,4,2,2};
//        std::cout << findDuplicate(nums)<< std::endl;

        nums = {1, 3, 4, 3, 2};
        std::cout << findDuplicate(nums) << std::endl;


    }
};