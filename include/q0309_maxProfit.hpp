//
// Created by ming on 2020/7/10.
//

#ifndef CMAKETEST_Q0309_MAXPROFIT_HPP
#define CMAKETEST_Q0309_MAXPROFIT_HPP

#endif //CMAKETEST_Q0309_MAXPROFIT_HPP
#include"tools.hpp"
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.empty())return 0;
        std::vector<int> fre={0},w_by={0},w_sd{0};//分别表示第i步结束时冷冻期，待买，待卖
        int pby = prices[0];//待卖的买时股价
        for (int i = 1; i < prices.size(); ++i) {
            //更新fre
            fre.push_back(w_sd[i-1]+prices[i]-pby);
            //更新w_by
            w_by.push_back(std::max(w_by[i-1],fre[i-1]));
            //更新pby
            pby = std::min(pby,prices[i]);
            //更新w_sd
            w_sd.push_back(std::max(w_sd[i-1],w_by[i-1]));
        }
        return std::max(fre.back(),w_by.back());
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int> p;
//        p = {1,2,3,0,2};
//        std::cout<<maxProfit(p)<<std::endl;
//
//        p = {2,1,3,4,7};
//        std::cout<<maxProfit(p)<<std::endl;

        p = {6,1,3,2,4,7};
        std::cout<<maxProfit(p)<<std::endl;

    }
};