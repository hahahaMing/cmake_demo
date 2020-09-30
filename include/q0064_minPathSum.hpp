//
// Created by ming on 2020/7/23.
//

#ifndef CMAKETEST_Q0064_MINPATHSUM_HPP
#define CMAKETEST_Q0064_MINPATHSUM_HPP

#endif //CMAKETEST_Q0064_MINPATHSUM_HPP

#include"tools.hpp"

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>> &grid) {
        if (grid.empty())return 0;
        int m = grid.size(), n = grid[0].size();
        /*
         * 直接修改数组，记录到(x,y)这点的最小路径长度
         */
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (y==0&&x==0)continue;
                if (y==0){
                    grid[y][x] = grid[y][x-1]+grid[y][x];
                }else if(x==0){
                    grid[y][x] = grid[y-1][x]+grid[y][x];
                }else{
                    grid[y][x] = std::min(grid[y-1][x],grid[y][x-1])+grid[y][x];
                }

            }
        }
        return grid.back().back();
    }

    void test() {
        std::cout << "test start" << std::endl;
        int a[] = {1,3,1,1,5,1,4,2,1,1,2,3};
        auto g = tools::array2matrix(a,4,3);
        tools::print_matrix(g);
        std::cout << minPathSum(g)<< std::endl;
        tools::print_matrix(g);

    }
};