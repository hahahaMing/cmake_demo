//
// Created by ming on 2020/10/11.
//

#ifndef CMAKETEST_Q5538_COUNTSUBGRAPHSFOREACHDIAMETER_HPP
#define CMAKETEST_Q5538_COUNTSUBGRAPHSFOREACHDIAMETER_HPP

#endif //CMAKETEST_Q5538_COUNTSUBGRAPHSFOREACHDIAMETER_HPP
#include"tools.hpp"
class Solution {
public:
    std::vector<int> countSubgraphsForEachDiameter(int n, std::vector<std::vector<int>>& edges) {
        std::vector<std::unordered_set<int>> citys(n+1);
        for (auto vec:edges) {
            citys[vec[0]].emplace(vec[1]);
            citys[vec[1]].emplace(vec[0]);
        }
        std::vector<int> rst(n-1,0);
        for (int i = 0; i < n; ++i) {
            int count =0;
            for (int j = 1; j < n; ++j) {

            }
        }


    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};