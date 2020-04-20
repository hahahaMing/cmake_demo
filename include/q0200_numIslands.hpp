//
// Created by ming on 2020/4/20.
//

#ifndef CMAKETEST_Q0200_NUMISLANDS_HPP
#define CMAKETEST_Q0200_NUMISLANDS_HPP

#endif //CMAKETEST_Q0200_NUMISLANDS_HPP

#include "tools.hpp"

class Solution {
public:
    //建立函数递归使看到的岛屿全部置零
    static void refill(std::vector<std::vector<char>> &grid, int y0, int x0) {
        int ly = grid.size(), lx = grid[0].size();
        //把当前的1置零
        grid[y0][x0]='0';
        //遍历四个方向
        std::vector<std::vector<int>> drc = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto i:drc){
            int y = y0+i[0],x = x0+i[1];
            //  如果是边界，就不管
            //  如果是0，不管
            if(x<0||y<0||x>=lx||y>=ly||grid[y][x]=='0')continue;
            //  如果是1，递归调用refill
            else refill(grid,y,x);
        }


    }


    int numIslands(std::vector<std::vector<char>> &grid) {
        //遍历区域见到岛屿记录，然后把该岛置零
        if (grid.empty()) return 0;
        int ly = grid.size(), lx = grid[0].size();
        int rst = 0;
        for(int y = 0;y<ly;y++){
            for(int x=0;x<lx;x++){
                if(grid[y][x]=='1') {
                    rst++;
                    refill(grid,y,x);
                }

            }
        }
        return rst;
    }

    static void test() {
        std::cout << "test start" << std::endl;

    }


};