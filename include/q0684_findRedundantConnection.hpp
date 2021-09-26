//
// Created by ming on 2021/1/13.
//

#ifndef CMAKETEST_Q0684_FINDREDUNDANTCONNECTION_HPP
#define CMAKETEST_Q0684_FINDREDUNDANTCONNECTION_HPP

#endif //CMAKETEST_Q0684_FINDREDUNDANTCONNECTION_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::vector<int> union_find;

    int get(int x) {
        if (union_find[x] == x)return x;
        return union_find[x] = get(union_find[x]);
    }

    void merge(int x, int y) {
        union_find[get(y)] = get(x);
    }

public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges) {
        //并查集
        int n = edges.size();
        union_find = std::vector<int>(n+1);
        for (int i = 0; i < n+1; ++i) {
            union_find[i] = i;
        }
        for (const auto &edge:edges) {
            if (get(edge[0]) == get(edge[1]))return edge;
            merge(edge[0], edge[1]);
            tools::printVectorInt(union_find);
        }
        return {};
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> edges;
        edges = tools::string2matrixInt("[[1,2],[1,3],[2,3]]");
        tools::printVectorInt(findRedundantConnection(edges));
//        edges = tools::string2matrixInt("[[1,2],[2,3],[3,4],[1,4],[1,5]]");
//        tools::printVectorInt(findRedundantConnection(edges));




//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};