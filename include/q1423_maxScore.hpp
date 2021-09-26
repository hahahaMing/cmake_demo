//
// Created by ming on 2021/2/6.
//

#ifndef CMAKETEST_Q1423_MAXSCORE_HPP
#define CMAKETEST_Q1423_MAXSCORE_HPP

#endif //CMAKETEST_Q1423_MAXSCORE_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int maxScore(std::vector<int> &cardPoints, int k) {
        int tmp = 0, n = cardPoints.size();
        for (int i = 0; i < k; ++i) {
            tmp += cardPoints[i];
        }
        int rst = tmp;
        for (int i = 1; i <= k; ++i) {
            tmp = tmp - cardPoints[k - i] + cardPoints[n - i];
            if (tmp>rst)rst = tmp;
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> cards;
        cards = {};



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};