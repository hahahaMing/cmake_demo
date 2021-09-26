//
// Created by ming on 2021/1/30.
//

#ifndef CMAKETEST_Q0778_SWIMINWATER_HPP
#define CMAKETEST_Q0778_SWIMINWATER_HPP

#endif //CMAKETEST_Q0778_SWIMINWATER_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::vector<int> parent;

    void init(int n) {
        parent = std::vector<int>(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int get(int x) {
        if (parent[x] == x)return x;
        return parent[x] = get(parent[x]);
    }

    void merge(int x, int y) {
        parent[get(y)] = get(x);
    }

public:
    int swimInWater(std::vector<std::vector<int>> &grid) {
        //边的权值为相连的最大的点数，从小到大相连，直到左上右下相连
        int raws = grid.size(), cols = grid[0].size();
        init(raws * cols);
        std::vector<std::vector<int>> rcd;
        for (int i = 0; i < raws; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i != 0) rcd.push_back({std::max(grid[i][j], grid[i - 1][j]), i * cols + j - cols, i * cols + j});
                if (j != 0) rcd.push_back({std::max(grid[i][j], grid[i][j - 1]), i * cols + j - 1, i * cols + j});
            }
        }
        std::sort(rcd.begin(), rcd.end());
        for (const auto &v:rcd) {
            merge(v[1], v[2]);
            if (get(0) == get(raws * cols - 1))return v[0];
        }
        return 0;
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