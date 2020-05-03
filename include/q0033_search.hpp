//
// Created by ming on 2020/4/27.
//

#ifndef CMAKETEST_Q0033_SEARCH_HPP
#define CMAKETEST_Q0033_SEARCH_HPP

#endif //CMAKETEST_Q0033_SEARCH_HPP

#include "tools.hpp"


class Solution {
private:
    void keep_left(int &L, int &M, int &R) {
        R = M;
        M = (L + M) / 2;

    }

    void keep_right(int &L, int &M, int &R) {
        L = M;
        M = (R + M) / 2 ;

    }

public:
    int search(std::vector<int> &nums, int target) {
        int L = 0, R = nums.size() - 1, M = (L + R) / 2;
        int l, r, m;
        if (0 == R) {
            if (target == nums[0])return 0;
            else return -1;
        }
        while (L < R) {
            l = nums[L], r = nums[R], m = nums[M];
            if (target == l)return L;
            if (target == m)return M;
            if (target == r)return R;
            if (R - L == 1) return -1;

            if (l <= m) {
                if (m <= r) {
                    if (target < l || target > r)return -1;
                    if (target < m)keep_left(L, M, R);
                    else keep_right(L, M, R);
                } else {
                    if (target < l && target > r)return -1;
                    if (target > l && target < m)keep_left(L, M, R);
                    else keep_right(L, M, R);
                }
            } else {
                if (target > m && target < r)keep_right(L, M, R);
                else keep_left(L, M, R);
            }
        }
        return -1;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
        int target;

        nums = {4, 5, 6, 7, 0, 1, 2};
        target = 0;
        std::cout << search(nums, target) << std::endl;

        target = 3;
        std::cout << search(nums, target) << std::endl;

        nums = {};
        target = 0;
        std::cout << search(nums, target) << std::endl;

        nums = {1};
        target = 1;
        std::cout << search(nums, target) << std::endl;

        nums = {1, 3};
        target = 2;
        std::cout << search(nums, target) << std::endl;

    }
};