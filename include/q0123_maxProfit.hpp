//
// Created by ming on 2021/1/9.
//

#ifndef CMAKETEST_Q0123_MAXPROFIT_HPP
#define CMAKETEST_Q0123_MAXPROFIT_HPP

#endif //CMAKETEST_Q0123_MAXPROFIT_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        //动态规划，记录一次交易最多赚多少dp1，两次交易最多赚多少dp2，dp1[i]
//        int n = prices.size();
//        if (n < 2)return 0;
//        std::vector<int> dp1(n, 0), dp2(n, 0);
//        int tmp_min = prices.front();
//        int max_prm = -prices[1];
//        for (int i = 1; i < n; ++i) {
//            dp1[i] = prices[i] - tmp_min > dp1[i - 1] ? prices[i] - tmp_min : dp1[i - 1];
//            if (prices[i] < tmp_min)tmp_min = prices[i];
//            dp2[i] = prices[i] + max_prm > dp2[i - 1] ? prices[i] + max_prm : dp2[i - 1];
//            if (dp1[i - 1] - prices[i] > max_prm)max_prm = dp1[i - 1] - prices[i];
//        }
//        tools::printVectorInt(dp1);
//        tools::printVectorInt(dp2);
//        return std::max(dp1.back(), dp2.back());

        int n = prices.size();
        if (n < 2)return 0;
        int dp1 = 0,dp2 = 0;
        int tmp_min = prices.front();
        int max_prm = -prices[1];
        for (int i = 1; i < n; ++i) {
            dp1 = prices[i] - tmp_min > dp1 ? prices[i] - tmp_min : dp1;
            if (prices[i] < tmp_min)tmp_min = prices[i];
            dp2 = prices[i] + max_prm > dp2 ? prices[i] + max_prm : dp2;
            if (dp1 - prices[i] > max_prm)max_prm = dp1 - prices[i];
        }
        return std::max(dp1, dp2);

    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> p;
        p = {3, 3, 5, 0, 0, 3, 1, 4};
        std::cout << maxProfit(p) << std::endl;
        p = {1,2,3,4,5};
        std::cout << maxProfit(p) << std::endl;
        p = {7,6,4,3,1};
        std::cout << maxProfit(p) << std::endl;
        p = {1};
        std::cout << maxProfit(p) << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};