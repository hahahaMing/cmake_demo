//
// Created by ming on 2020/7/6.
//

#ifndef CMAKETEST_Q0063_UNIQUEPATHSWITHOBSTACLES_HPP
#define CMAKETEST_Q0063_UNIQUEPATHSWITHOBSTACLES_HPP

#endif //CMAKETEST_Q0063_UNIQUEPATHSWITHOBSTACLES_HPP

#include"tools.hpp"

class Solution {
    int paths_by_start(std::vector<std::vector<int>> &obstacleGrid, int st_x, int st_y) {
        if (st_x == obstacleGrid[0].size())return 0;
        if (st_y == obstacleGrid.size())return 0;
        if (obstacleGrid[st_y][st_x] == 1)return 0;
        if (st_y == obstacleGrid.size() - 1 && st_x == obstacleGrid[0].size() - 1)return 1;

        return paths_by_start(obstacleGrid, st_x, st_y + 1) +
               paths_by_start(obstacleGrid, st_x + 1, st_y);
    }

public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
        /*
         * 递归
         * 指定起点，只能往右下走，看能分几步
         */
        if (obstacleGrid.empty())return 0;
        return paths_by_start(obstacleGrid, 0, 0);

    }

    void test() {
        std::cout << "test start" << std::endl;
        int a[9] = {1, 0, 0, 0, 1, 0, 0, 0, 0};
        std::vector<std::vector<int>> obt;
        obt = tools::array2matrix(a, 3, 3);
        tools::print2DVector(obt);
        std::cout << uniquePathsWithObstacles(obt) << std::endl;

    }
};