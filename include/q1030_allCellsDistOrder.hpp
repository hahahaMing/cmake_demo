//
// Created by ming on 2020/11/17.
//

#ifndef CMAKETEST_Q1030_ALLCELLSDISTORDER_HPP
#define CMAKETEST_Q1030_ALLCELLSDISTORDER_HPP

#endif //CMAKETEST_Q1030_ALLCELLSDISTORDER_HPP

#include"tools.hpp"

class Solution {
public:
        std::vector<std::vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
            int max_distance = std::max(R - r0 - 1, r0) + std::max(C - c0 - 1, c0);
            std::vector<std::vector<int>> rst = {{r0, c0}};
            int r, c;
            for (int i = 1; i <= max_distance; ++i) {
                for (int j = 1; j <= i; ++j) {
                    r = r0 + j;
                    c = c0 + (i - j);
                    if (r < R && c < C)rst.push_back({r, c});
                    r = r0 - (i - j);
                    c = c0 + j;
                    if (r >= 0 && c < C)rst.push_back({r, c});
                    r = r0 - j;
                    c = c0 - (i - j);
                    if (r >= 0 && c >= 0)rst.push_back({r, c});
                    r = r0 + (i - j);
                    c = c0 - j;
                    if (r < R && c >= 0)rst.push_back({r, c});

                }
            }
            return rst;
        }

    void test() {
        std::cout << "test start" << std::endl;
        int R, C, r0, c0;
        R = 5, C = 5, r0 = 2, c0 = 2;
        tools::print2DVector(allCellsDistOrder(R, C, r0, c0));


    }
};