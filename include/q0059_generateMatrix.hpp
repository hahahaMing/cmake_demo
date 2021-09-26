//
// Created by ming on 2021/3/16.
//

#ifndef CMAKETEST_Q0059_GENERATEMATRIX_HPP
#define CMAKETEST_Q0059_GENERATEMATRIX_HPP

#endif //CMAKETEST_Q0059_GENERATEMATRIX_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> rst(n, std::vector<int>(n));
        int count = 1;
        for (int layer = 0; layer < n / 2; ++layer) {
            for (int i = layer; i < n - 1 - layer; ++i) {
                rst[layer][i] = count++;
            }
            for (int i = layer; i < n - 1 - layer; ++i) {
                rst[i][n - 1 - layer] = count++;
            }
            for (int i = n - 1 - layer; i >= 1 + layer; --i) {
                rst[n - 1 - layer][i] = count++;
            }
            for (int i = n - 1 - layer; i >= 1 + layer; --i) {
                rst[i][layer] = count++;
            }
        }
        if (n%2==1)rst[n/2][n/2] = n*n;
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        for (int i = 0; i < 21; ++i) {
            tools::print_matrix(generateMatrix(i));
        }


    }
};