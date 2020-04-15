//
// Created by ming on 2020/4/15.
//

#ifndef CMAKETEST_Q0542_UPDATEMATRIX_HPP
#define CMAKETEST_Q0542_UPDATEMATRIX_HPP

#endif //CMAKETEST_Q0542_UPDATEMATRIX_HPP

#include "tools.hpp"


class Solution {
    int MAX = 200;
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> &matrix) {
        int ly = matrix.size(), lx = matrix[0].size();
        std::vector<std::vector<int> > rst(ly, std::vector<int>(lx, 0));
        for (int y = 0; y < ly; y++) {
            for (int x = 0; x < lx; x++) {
                if (x == 0 && y == 0) rst[0][0] =  matrix[0][0] ? MAX : 0;
                else if (y == 0) rst[0][x] = matrix[0][x] ? rst[0][x - 1] + 1 : 0;
                else if (x == 0) rst[y][0] = matrix[y][0] ? rst[y - 1][0] + 1 : 0;
                else
                    rst[y][x] = std::min((matrix[y][x] ? rst[y][x - 1] + 1 : 0),
                                         (matrix[y][x] ? rst[y - 1][x] + 1 : 0));
            }
        }
        for (int y = ly - 1; y >= 0; y--) {
            for (int x = lx - 1; x >= 0; x--) {
                if (x == lx - 1 && y == ly - 1) continue;
                else if (y == ly - 1)
                    rst[ly - 1][x] = std::min((matrix[ly - 1][x] ? rst[ly - 1][x + 1] + 1 : 0), rst[ly - 1][x]);
                else if (x == lx - 1)
                    rst[y][lx - 1] = std::min((matrix[y][lx - 1] ? rst[y + 1][lx - 1] + 1 : 0), rst[y][lx - 1]);
                else
                    rst[y][x] = std::min((std::min((matrix[y][x] ? rst[y][x + 1] + 1 : 0),
                                                   (matrix[y][x] ? rst[y + 1][x] + 1 : 0))), rst[y][x]);
            }
        }
        return rst;
    }

    void test() {
        int a[] = {0, 0, 0,
                   0, 1, 0,
                   1, 1, 1};
        auto m = tools::array2matrix(a, 3, 3);
        tools::print_matrix(m);
        tools::print_matrix(updateMatrix(m));
    }
};