//
// Created by ming on 2021/1/29.
//

#ifndef CMAKETEST_Q1631_MINIMUMEFFORTPATH_HPP
#define CMAKETEST_Q1631_MINIMUMEFFORTPATH_HPP

#endif //CMAKETEST_Q1631_MINIMUMEFFORTPATH_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::vector<int> parents;

    void init(int n) {
        parents = std::vector<int>(n);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
    }

    int get(int x) {
        if (parents[x] == x)return x;
        return parents[x] = get(parents[x]);
    }

    void merge(int x, int y) {
        parents[get(y)] = get(x);
    }

public:
    int minimumEffortPath(std::vector<std::vector<int>> &heights) {
        int raws = heights.size(), cols = heights[0].size();
        init(raws * cols);
        std::vector<std::vector<int>> rcd;
        for (int i = 0; i < raws; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i != 0)rcd.push_back({abs(heights[i][j] - heights[i - 1][j]), i * cols + j - cols, i * cols + j});
                if (j != 0)rcd.push_back({abs(heights[i][j] - heights[i][j - 1]), i * cols + j - 1, i * cols + j});
            }
        }
        std::sort(rcd.begin(),rcd.end());
        for(const auto& v:rcd){
            merge(v[1],v[2]);
            if (get(0)==get(raws*cols-1))return v[0];
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