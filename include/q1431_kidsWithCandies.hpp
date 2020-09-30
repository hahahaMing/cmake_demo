//
// Created by ming on 2020/6/1.
//

#ifndef CMAKETEST_Q1431_KIDSWITHCANDIES_HPP
#define CMAKETEST_Q1431_KIDSWITHCANDIES_HPP

#endif //CMAKETEST_Q1431_KIDSWITHCANDIES_HPP
#include"tools.hpp"
class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        int max_candies = 0;
        for (int i:candies) {
            if (i>max_candies)max_candies=i;
        }
        std::vector<bool> rst;
        for(int i :candies){
            if (i+extraCandies>=max_candies)rst.push_back(true);
            else rst.push_back(false);
        }
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};