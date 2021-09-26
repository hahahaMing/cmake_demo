//
// Created by ming on 2020/11/8.
//

#ifndef CMAKETEST_Q0122_MAXPROFIT_HPP
#define CMAKETEST_Q0122_MAXPROFIT_HPP

#endif //CMAKETEST_Q0122_MAXPROFIT_HPP
#include"tools.hpp"
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if(prices.empty())return 0;
        int n = prices.size(),rst=0;
        for (int i = 1; i < n; ++i) {
            if (prices[i]>prices[i-1])rst+=prices[i]-prices[i-1];
        }
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};