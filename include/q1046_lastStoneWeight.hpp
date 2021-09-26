//
// Created by ming on 2020/12/30.
//

#ifndef CMAKETEST_Q1046_LASTSTONEWEIGHT_HPP
#define CMAKETEST_Q1046_LASTSTONEWEIGHT_HPP

#endif //CMAKETEST_Q1046_LASTSTONEWEIGHT_HPP
#include"tools.hpp"
/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        while (stones.size()>1){
            std::sort(stones.begin(),stones.end());
            int new_stone = stones.back()-stones[stones.size()-2];
            stones.erase(stones.end()-2,stones.end());
            if (new_stone)stones.push_back(new_stone);
        }
        if (stones.empty())return 0;
        return stones.front();
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int> stones;
        stones = {2,2};
        std::cout<<lastStoneWeight(stones)<<std::endl;
        stones = {2,7,4,1,8,1};
        std::cout<<lastStoneWeight(stones)<<std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};