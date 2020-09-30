//
// Created by ming on 2020/7/14.
//

#ifndef CMAKETEST_Q0120_MINIMUMTOTAL_HPP
#define CMAKETEST_Q0120_MINIMUMTOTAL_HPP

#endif //CMAKETEST_Q0120_MINIMUMTOTAL_HPP
#include"tools.hpp"
class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        /*
         * 思路：
         * 从最后一层向上，维护一个数组
         * 数组存储以当前位置为三角形顶点的最小路径和
         * 也算动态规划吧
         *
         */
        if (triangle.empty())return 0;
        int h = triangle.size();
        std::vector<int> rst = triangle.back();
        for (int y = h-2; y >=0; --y) {
            for (int x = 0; x <= y; ++x) {
                rst[x] = triangle[y][x]+std::min(rst[x],rst[x+1]);
            }
        }
        return rst[0];
    }

    void test(){
        std::cout<<"test start"<<std::endl;

    }
};