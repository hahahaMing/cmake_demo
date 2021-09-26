//
// Created by ming on 2020/12/19.
//

#ifndef CMAKETEST_Q0048_ROTATE_HPP
#define CMAKETEST_Q0048_ROTATE_HPP

#endif //CMAKETEST_Q0048_ROTATE_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        int n = matrix.size();
        int m = n / 2;
        for (int i = 0; i < m; ++i) {
            int mm = n % 2 == 0 ? m : m + 1;
            for (int j = 0; j < mm; ++j) {
                std::swap(matrix[i][j], matrix[j][n - i - 1]);
                std::swap(matrix[n - j - 1][i], matrix[n - i - 1][n - j - 1]);
                std::swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);
            }
        }
    }


    void test() {
        std::cout << "test start" << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};