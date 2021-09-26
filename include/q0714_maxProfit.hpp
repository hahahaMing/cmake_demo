//
// Created by ming on 2020/12/17.
//

#ifndef CMAKETEST_Q0714_MAXPROFIT_HPP
#define CMAKETEST_Q0714_MAXPROFIT_HPP

#endif //CMAKETEST_Q0714_MAXPROFIT_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
public:
    int maxProfit(std::vector<int> &prices, int fee) {
        /*
         * 记录每一笔交易
         * 动态规划，如果开启新的交易合适，就开启
         * 否则更新当前交易到赚的最多
         * 最后统计总钱数
         */
        int n = prices.size();
//        std::vector<int> rcd(n, -1);
        int last_end = 0, this_min = 0, rst = 0;
        for (int i = 0; i < n; ++i) {
            if (prices[i] < prices[this_min])this_min = i;
            else {
                if (rst == 0 || prices[last_end] >= prices[this_min] + fee) {//满足 “开启新交易” 总盈利不比 “更新交易” 小的条件
                    if (prices[i] > prices[this_min] + fee) {//新交易盈利
//                        rcd[i] = this_min;
                        rst += prices[i] - prices[this_min] - fee;
                        this_min = i;
                        last_end = i;
                    }
                } else {//不满足 “开启新交易” 总盈利不比 “更新交易” 小的条件
                    if (prices[i] > prices[last_end]) {//更新交易
//                        rcd[i] = rcd[last_end];
//                        rcd[last_end] = -1;
                        rst += prices[i] - prices[last_end];
                        last_end = i;
                        this_min = i;
                    }
                }
            }
        }
//        tools::printVectorInt(rcd);
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> prices;
        int fee;
        prices = {1, 3, 2, 8, 4, 9}, fee = 2;
        std::cout << maxProfit(prices, fee) << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};