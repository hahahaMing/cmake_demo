//
// Created by ming on 2020/12/21.
//

#ifndef CMAKETEST_Q0746_MINCOSTCLIMBINGSTAIRS_HPP
#define CMAKETEST_Q0746_MINCOSTCLIMBINGSTAIRS_HPP

#endif //CMAKETEST_Q0746_MINCOSTCLIMBINGSTAIRS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
public:
    int minCostClimbingStairs(std::vector<int> &cost) {
        int skip = 0, step = 0, tmp = 0;
        for(int c:cost){
            tmp = skip;
            skip = step;
            step = std::min(tmp,step)+c;
        }
        return std::min(skip,step);
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