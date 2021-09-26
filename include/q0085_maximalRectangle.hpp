//
// Created by ming on 2020/12/26.
//

#ifndef CMAKETEST_Q0085_MAXIMALRECTANGLE_HPP
#define CMAKETEST_Q0085_MAXIMALRECTANGLE_HPP

#endif //CMAKETEST_Q0085_MAXIMALRECTANGLE_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>> &matrix) {
        /*
         * 存向前连续1的个数，和以当前点为右下角的最大矩形面积
         */
        if (matrix.empty())return 0;
        int rows = matrix.size(), cols = matrix[0].size();
        int rst = 0;
        std::vector<std::vector<int>> rcd(rows, std::vector<int>(cols, 0)), s(rows, std::vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    rcd[i][j] = j > 0 ? rcd[i][j - 1] + 1 : 1;
                    int width = rcd[i][j];
                    for (int k = i; k >= 0 && width > 0; --k) {
                        width = std::min(width, rcd[k][j]);
                        s[i][j] = std::max(s[i][j], width * (i - k + 1));
                    }
                    rst = std::max(rst, s[i][j]);
                }
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<char>> matrix;
        matrix = tools::string2matrix(
                "[[\"1\",\"0\",\"1\",\"0\",\"0\"],[\"1\",\"0\",\"1\",\"1\",\"1\"],[\"1\",\"1\",\"1\",\"1\",\"1\"],[\"1\",\"0\",\"0\",\"1\",\"0\"]]");
        tools::print_matrix(matrix);
        std::cout << maximalRectangle(matrix) << std::endl;




//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};