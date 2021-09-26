//
// Created by ming on 2021/3/15.
//

#ifndef CMAKETEST_Q0054_SPIRALORDER_HPP
#define CMAKETEST_Q0054_SPIRALORDER_HPP

#endif //CMAKETEST_Q0054_SPIRALORDER_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        std::vector<int> rst(m * n*2);
        int layer = 0, count = 0;
        while (layer <= m / 2 && layer <= n / 2) {

            for (int i = layer; i < m - layer; i++) {
                rst[count++] = matrix[layer][i];
            }
            for (int i = layer + 1; i < n - layer; i++) {
                rst[count++] = matrix[i][m - layer - 1];
            }
            if (layer == n - 1 - layer || layer == m - layer - 1)break;
            for (int i = m - 2 - layer; i >= layer; i--) {
                rst[count++] = matrix[n - 1 - layer][i];
            }
            for (int i = n - 2 - layer; i > layer; i--) {
                rst[count++] = matrix[i][layer];
            }
            layer++;
            if (layer > n - 1 - layer || layer > m - layer - 1)break;
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> matrix;
        matrix = tools::string2matrixInt("[[2,5,8],[4,0,-1]]");
        tools::printVectorInt(spiralOrder(matrix));
        matrix = tools::string2matrixInt("[[1,2,3,4],[5,6,7,8],[9,10,11,12]]");
        tools::printVectorInt(spiralOrder(matrix));
        matrix = tools::string2matrixInt("[[1,2,3],[4,5,6],[7,8,9]]");
        tools::printVectorInt(spiralOrder(matrix));
        matrix = tools::string2matrixInt("[[7],[9],[6]]");
        tools::printVectorInt(spiralOrder(matrix));
        matrix = tools::string2matrixInt("[[]]");
        tools::printVectorInt(spiralOrder(matrix));
        matrix = tools::string2matrixInt("[[1]]");
        tools::printVectorInt(spiralOrder(matrix));

    }
};