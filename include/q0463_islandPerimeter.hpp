//
// Created by ming on 2020/10/30.
//

#ifndef CMAKETEST_Q0463_ISLANDPERIMETER_HPP
#define CMAKETEST_Q0463_ISLANDPERIMETER_HPP

#endif //CMAKETEST_Q0463_ISLANDPERIMETER_HPP

#include"tools.hpp"

class Solution {
    int w, h;
    int rst;

    void dfs(std::vector<std::vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= w || j < 0 || j >= h || grid[i][j] == 0) {
            rst++;
            return;
        }
        if (grid[i][j] == 1) {
            grid[i][j] = 2;
            dfs(grid, i - 1, j);
            dfs(grid, i + 1, j);
            dfs(grid, i, j - 1);
            dfs(grid, i, j + 1);
        }
    }


public:
    int islandPerimeter(std::vector<std::vector<int>> &grid) {
        if (grid.empty())return 0;
        w = grid.size();
        h = grid[0].size();
        rst = 0;
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                if (grid[i][j]==1)dfs(grid,i,j);
                return rst;
            }
        }
        return 0;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> g;
        g = tools::string2matrixInt("[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]");
        tools::print_matrix(g);
        std::cout << islandPerimeter(g)<< std::endl;
        tools::print_matrix(g);


    }
};