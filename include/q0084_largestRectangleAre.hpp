//
// Created by ming on 2020/5/29.
//

#ifndef CMAKETEST_Q0084_LARGESTRECTANGLEARE_HPP
#define CMAKETEST_Q0084_LARGESTRECTANGLEARE_HPP

#endif //CMAKETEST_Q0084_LARGESTRECTANGLEARE_HPP

#include"tools.hpp"

class Solution {
    int find_min(std::vector<int> &heights, int begin, int end) {
        //找到heights中索引范围内的最小值
        int m = INT16_MAX;
        for (int i = begin; i <= end; ++i) {
            m = std::min(m, heights[i]);
        }
        return m;
    }

public:
    int largestRectangleArea(std::vector<int> &heights) {
        //夹逼法，不正确
        /*int l = 0, r = heights.size() - 1, last;
        int h = find_min(heights, l, r);
        int rst = 0;
        while (r >= l) {
            rst = std::max(h * (r - l + 1), rst);
            if (heights[l] < heights[r]) {
                last = heights[l++];
            } else {
                last = heights[r--];
            }
            if (last == h)h = find_min(heights, l, r);
        }
        return rst;*/

        //动态规划
        int last_area = 0,last_h = 0,
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> heights;
        heights = {2, 1, 5, 6, 2, 3};
        std::cout << largestRectangleArea(heights) << std::endl;

        heights = {1, 1, 1, 1, 1, 100, 1, 1, 1, 1, 1};
        std::cout << largestRectangleArea(heights) << std::endl;

        heights = {4, 2, 0, 3, 2, 4, 3, 4};
        std::cout << largestRectangleArea(heights) << std::endl;


    }
};