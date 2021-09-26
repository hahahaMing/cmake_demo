//
// Created by ming on 2020/12/29.
//

#ifndef CMAKETEST_Q0330_MINPATCHES_HPP
#define CMAKETEST_Q0330_MINPATCHES_HPP

#endif //CMAKETEST_Q0330_MINPATCHES_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int minPatches(std::vector<int> &nums, int n) {
        /*
         * 遍历每个数
         * 保证前i个数可以表示1~sum(nums[1~i])中的所有数字
         * 如果不够就添加一位sum+1，此时可以表示1~sum*2+1的所有数字
         */
        int rst = 0;
        int sum = 0;//当前可表示1~sum的所有数字
        for (int num:nums) {
            while (num > sum + 1) {
                if (sum >= n)return rst;
                sum = sum * 2 + 1;
                rst++;
            }
            sum += num;
        }
        while (sum < n) {
            sum = sum * 2 + 1;
            rst++;
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
        int n;
        nums = {1, 3};
        n = 6;
        std::cout << minPatches(nums, n) << std::endl;
        nums = {1, 5, 10};
        n = 20;
        std::cout << minPatches(nums, n) << std::endl;
        nums = {1, 2, 2};
        n = 5;
        std::cout << minPatches(nums, n) << std::endl;
        nums = {10};
        n = 20;
        std::cout << minPatches(nums, n) << std::endl;
        nums = {1, 7, 21, 31, 34, 37, 40, 43, 49, 87, 90, 92, 93, 98, 99};
        n = 12;
        std::cout << minPatches(nums, n) << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};