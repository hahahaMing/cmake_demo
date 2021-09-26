//
// Created by ming on 2020/10/25.
//

#ifndef CMAKETEST_Q0845_LONGESTMOUNTAIN_HPP
#define CMAKETEST_Q0845_LONGESTMOUNTAIN_HPP

#endif //CMAKETEST_Q0845_LONGESTMOUNTAIN_HPP

#include"tools.hpp"

class Solution {
public:
    int longestMountain(std::vector<int> &A) {
        int dp = 0, dpl = 0, rst = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                dpl = 1;
                continue;
            }
            if (A[i] < A[i - 1]) {
                if (dpl > 1 && dp == 0) {
                    dp = dpl + 1;
                } else if (dp != 0) {
                    dp++;
                }
                if (dp > rst)rst = dp;
                dpl = 1;
            } else if (A[i] == A[i - 1]) {
                dpl = 1;
                dp = 0;
            } else {
                dpl++;
                dp = 0;
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> a;
        a = {2, 1, 4, 7, 3, 2, 5};
        std::cout << longestMountain(a) << std::endl;
        a = {2, 2, 2};
        std::cout << longestMountain(a) << std::endl;
        a = {};
        std::cout << longestMountain(a) << std::endl;
        a = {3,2,1};
        std::cout << longestMountain(a) << std::endl;
        a = {1,2,1,2,3,2,1,2,3,4,3,2,1};
        std::cout << longestMountain(a) << std::endl;
    }
};