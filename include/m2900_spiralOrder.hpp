//
// Created by ming on 2020/6/5.
//

#ifndef CMAKETEST_M2900_SPIRALORDER_HPP
#define CMAKETEST_M2900_SPIRALORDER_HPP

#endif //CMAKETEST_M2900_SPIRALORDER_HPP

#include"tools.hpp"

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
        if (matrix.empty())return {};
        int minx = 0, miny = 0, maxx = matrix[0].size() - 1, maxy = matrix.size() - 1;
        int x = 0, y = 0;
        int x_inc = 1, y_inc = 0;
        std::vector<int> rst;
        while (maxx > minx || maxy > miny) {
            rst.push_back(matrix[y][x]);
            // 判断改变方向
//            if (maxx == minx) {
//                if (x_inc == 1)y_inc = -1;
//                if (x_inc == -1)y_inc = 1;
//                x_inc = 0;
//            } else if (maxy == miny) {
//                if (y_inc == 1)x_inc = -1;
//                if (y_inc == -1)x_inc = 1;
//                y_inc = 0;
//
//            } else


            if (x_inc == 1 && x == maxx) {
                miny++;
                x_inc = 0;
                y_inc = 1;
            } else if (x_inc == -1 && x == minx) {
                maxy--;
                x_inc = 0;
                y_inc = -1;
            } else if (y_inc == 1 && y == maxy) {
                maxx--;
                x_inc = -1;
                y_inc = 0;
            } else if (y_inc == -1 && y == miny) {
                minx++;
                x_inc = 1;
                y_inc = 0;
            }
            // 走
            x += x_inc;
            y += y_inc;
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> m;
//        {
//            int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//            m = tools::array2matrix(a, 3, 3);
//            tools::print2DVector(m);
//            tools::printVectorInt(spiralOrder(m));
//        std::cout  << std::endl;
//        }
        {
            int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
            m = tools::array2matrix(a, 3, 4);
            tools::print2DVector(m);
            tools::printVectorInt(spiralOrder(m));
            std::cout  << std::endl;
        }
        {
            int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
            m = tools::array2matrix(a, 2, 6);
            tools::print2DVector(m);
            tools::printVectorInt(spiralOrder(m));
            std::cout  << std::endl;
        }
        {
            int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
            m = tools::array2matrix(a, 4, 3);
            tools::print2DVector(m);
            tools::printVectorInt(spiralOrder(m));
            std::cout  << std::endl;
        }

    }
};