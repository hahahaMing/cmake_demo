//
// Created by ming on 2020/10/11.
//

#ifndef CMAKETEST_Q5536_MAXIMALNETWORKRANK_HPP
#define CMAKETEST_Q5536_MAXIMALNETWORKRANK_HPP

#endif //CMAKETEST_Q5536_MAXIMALNETWORKRANK_HPP

#include"tools.hpp"

class Solution {
public:
    int maximalNetworkRank(int n, std::vector<std::vector<int>> &roads) {
        std::vector<std::unordered_set<int>> citys(n);
        for (auto vec:roads) {
            citys[vec[0]].emplace(vec[1]);
            citys[vec[1]].emplace(vec[0]);
        }
        int rst = 0, tmp;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                tmp = citys[i].size() + citys[j].size();
                if (citys[i].find(j) != citys[i].end())tmp--;
                if (tmp > rst)rst = tmp;
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> roads;
        int n;
        n = 5;
        roads = {{0, 1},
                 {0, 3},
                 {1, 2},
                 {1, 3},
                 {2, 3},
                 {2, 4}};
        tools::print2DVector(roads);
        std::cout << maximalNetworkRank(n, roads) << std::endl;
        n = 2;
        roads = {{0, 1}};
        tools::print2DVector(roads);
        std::cout << maximalNetworkRank(n, roads) << std::endl;
    }
};