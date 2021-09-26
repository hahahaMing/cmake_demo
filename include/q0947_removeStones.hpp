//
// Created by ming on 2021/1/15.
//

#ifndef CMAKETEST_Q0947_REMOVESTONES_HPP
#define CMAKETEST_Q0947_REMOVESTONES_HPP

#endif //CMAKETEST_Q0947_REMOVESTONES_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::vector<int> parents;

    int get_parent(int x) {
        if (parents[x] == x)return x;
        return parents[x] = get_parent(parents[x]);
    }

    void merge(int x, int y) {
        parents[get_parent(y)] = get_parent(x);
    }

public:
    int removeStones(std::vector<std::vector<int>> &stones) {
        int n = stones.size();
        parents = std::vector<int>(n);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    merge(j, i);
                }
            }
        }
        std::unordered_set<int> rcd;
        for (int i = 0; i < n; ++i) {
            if (rcd.find(get_parent(i)) == rcd.end()) {
                rcd.insert(get_parent(i));
            }
        }
        return n - rcd.size();
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