//
// Created by ming on 2021/1/21.
//

#ifndef CMAKETEST_Q1489_FINDCRITICALANDPSEUDOCRITICALEDGES_HPP
#define CMAKETEST_Q1489_FINDCRITICALANDPSEUDOCRITICALEDGES_HPP

#endif //CMAKETEST_Q1489_FINDCRITICALANDPSEUDOCRITICALEDGES_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::vector<int> points_union;


public:
    std::vector<std::vector<int>> findCriticalAndPseudoCriticalEdges(int n, std::vector<std::vector<int>> &edges) {
        //使用并查集向下找,然后挨个边找替换方案
        //不可能 有 2，2，3，4，5中用2，3，4替换2，2，5
        //排序edges
        std::sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });
        //


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