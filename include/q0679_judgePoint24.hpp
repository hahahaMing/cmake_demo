//
// Created by ming on 2020/8/22.
//

#ifndef CMAKETEST_JUDGEPOINT24_HPP
#define CMAKETEST_JUDGEPOINT24_HPP

#endif //CMAKETEST_JUDGEPOINT24_HPP

#include"tools.hpp"

class Solution {
    std::vector<double> cal2cards(double a, double b) {
        return {double(a + b), double(a * b), double(a / b), double(b / a), double(a - b), double(b - a)};
    }

public:
    bool judgePoint24(std::vector<int> &nums) {
        double eor = 0.000001;
        std::vector<std::vector<int>> ref1 = {{0, 1, 2, 3},
                                              {0, 2, 1, 3},
                                              {0, 3, 1, 2},
                                              {1, 2, 0, 3},
                                              {1, 3, 0, 2},
                                              {2, 3, 0, 1}};
        std::vector<std::vector<int>> ref2 = {{0, 1, 2},
                                              {0, 2, 1},
                                              {1, 2, 0}};
//        std::vector<std::vector<double>> cards3, cards2;
        std::vector<double> rst1, rst2, rst3, rst4, cards3, cards2;
        for (int r1 = 0; r1 < 6; ++r1) {
            rst1 = cal2cards(nums[ref1[r1][0]], nums[ref1[r1][1]]);
            for (int r2 = 0; r2 < 6; ++r2) {
                rst2 = {rst1[r2], double(nums[ref1[r1][2]]), double(nums[ref1[r1][3]])};
                for (int r3 = 0; r3 < 3; ++r3) {
                    rst3 = cal2cards(rst2[ref2[r3][0]], rst2[ref2[r3][1]]);
                    for (int r4 = 0; r4 < 6; ++r4) {
                        rst4 = cal2cards(rst3[r4], rst2[ref2[r3][2]]);
                        for (int r5 = 0; r5 < 6; ++r5) {
                            if (rst4[r5] < 24+eor && rst4[r5] > 24-eor) {
                                std::cout << rst4[r5] << std::endl;
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
//        nums = {4,1,8,7};
//        judgePoint24(nums);
//        nums = {1,2,1,2};
//        judgePoint24(nums);
        nums = {3, 3, 8, 8};
        judgePoint24(nums);
    }
};