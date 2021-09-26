//
// Created by ming on 2020/12/7.
//

#ifndef CMAKETEST_Q0861_MATRIXSCORE_HPP
#define CMAKETEST_Q0861_MATRIXSCORE_HPP

#endif //CMAKETEST_Q0861_MATRIXSCORE_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
public:
    int matrixScore(std::vector<std::vector<int>> &A) {
        int m = A.size(), n = A[0].size();
        long long rst = 0;
        std::vector<int> rcd(n, 0);
        rcd[0] = m;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (A[i][0] == 0)A[i][j] = 1 - A[i][j];
                rcd[j] += A[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            rst += ((std::max(rcd[i], m - rcd[i])) << (n - i - 1));
        }
        return rst;
    }


    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> A;
        A = tools::string2matrixInt("[[0,0,1,1],[1,0,1,0],[1,1,0,0]]");
        std::cout << matrixScore(A) << std::endl;
    }
};