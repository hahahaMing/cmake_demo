//
// Created by ming on 2020/11/28.
//

#ifndef CMAKETEST_Q0493_REVERSEPAIRS_HPP
#define CMAKETEST_Q0493_REVERSEPAIRS_HPP

#endif //CMAKETEST_Q0493_REVERSEPAIRS_HPP
#include"tools.hpp"
class Solution {
public:
    int reversePairs(std::vector<int>& nums) {

    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::mt19937 rng(std::random_device{}());
        std::vector<int> vec;
        for (int i = 0; i < 10; ++i) {
            vec = tools::random_vector(rng, 0, 9, -99, 99);
            tools::printVectorInt(vec);
        }
    }
};