//
// Created by ming on 2020/5/17.
//

#ifndef CMAKETEST_Q0152_MAXPRODUCT_HPP
#define CMAKETEST_Q0152_MAXPRODUCT_HPP

#endif //CMAKETEST_Q0152_MAXPRODUCT_HPP

#include "tools.hpp"

class Solution {
public:
    int maxProduct(std::vector<int> &nums) {
        //动态规划。。。记录最大正数积与最小负数积和最后一位的最大正数积与最小负数积
        int maxp = INT16_MIN, temp, lxp = 0, lnp = 0;//lxp>=0,,lnp<=0
        bool pstv = false;
        for (auto i:nums) {
            if (i >= 0) {
                lxp = lxp ? lxp * i : i;
                lnp *= i;
            } else {
                temp = lnp;
                if (lxp == 0 )lnp = i;
                else lnp = lxp * i;
                lxp = temp * i;
            }
            if (lxp > 0)pstv = true;

            if (pstv)maxp = std::max(maxp, lxp);
            else maxp = std::max(maxp, lnp);
        }
        return maxp;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
//
        nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        std::cout << maxProduct(nums) << std::endl;

        nums = {-1};
        std::cout << maxProduct(nums) << std::endl;

        nums = {2, 3, -2, 4};
        std::cout << maxProduct(nums) << std::endl;

        nums = {-2, 0, -1};
        std::cout << maxProduct(nums) << std::endl;

        nums = {-2, -1};
        std::cout << maxProduct(nums) << std::endl;

        nums = {2, -5, -2, -4, 3};
        std::cout << maxProduct(nums) << std::endl;
    }


};