//
// Created by ming on 2020/9/2.
//

#ifndef CMAKETEST_HUAWEI02_HPP
#define CMAKETEST_HUAWEI02_HPP

#endif //CMAKETEST_HUAWEI02_HPP

#include"tools.hpp"

class Solution {
public:
//建立函数递归使看到的岛屿全部置零
    static void refill(std::vector<std::string> &grid, int y0, int x0) {
        int ly = grid.size(), lx = grid[0].size();
        //把当前的1置零
        grid[y0][x0]='H';
        //遍历四个方向
        std::vector<std::vector<int>> drc = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto i:drc){
            int y = y0+i[0],x = x0+i[1];
            //  如果是边界，就不管
            //  如果是0，不管
            if(x<0||y<0||x>=lx||y>=ly||grid[y][x]=='H')continue;
                //  如果是1，递归调用refill
            else refill(grid,y,x);
        }
    }
    int numIslands(std::vector<std::string> &grid) {
        //遍历区域见到岛屿记录，然后把该岛置零
        if (grid.empty()) return 0;
        int ly = grid.size(), lx = grid[0].size();
        int rst = 0;
        for(int y = 0;y<ly;y++){
            for(int x=0;x<lx;x++){
                if(grid[y][x]=='S') {
                    rst++;
                    refill(grid,y,x);
                }
            }
        }
        return rst;
    }
    void test() {

        std::vector<std::string> land;
        int m, n;
        char coma;
        std::cin>>m>>coma>>n;
        std::cout<<m<<'\t'<<coma<<'\t'<<n<<std::endl;
        std::string s;
//        while (std::cin>>s){
//            land.push_back(s);
//        }
        m = 4, n = 5;
//        land = {"SSHHH", "SSHHH", "HHSHH", "HHHSS"};
        land = {"S"};

        std::cout << numIslands(land) << std::endl;
        land = {"SH"};


        std::cout << numIslands(land) << std::endl;
        land = {"H"};

        std::cout << numIslands(land) << std::endl;

        land = {"HSH"};

        std::cout << numIslands(land) << std::endl;


        land = {"S","H","S"};

        std::cout << numIslands(land) << std::endl;
    }
};