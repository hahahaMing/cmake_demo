//
// Created by ming on 2020/12/28.
//

#ifndef CMAKETEST_Q0188_MAXPROFIT_HPP
#define CMAKETEST_Q0188_MAXPROFIT_HPP

#endif //CMAKETEST_Q0188_MAXPROFIT_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int maxProfit(int k, std::vector<int> &prices) {
        if (k==0)return 0;
        std::vector<int> rcd = {};
        int i = 0, n = prices.size(), rst = 0;
        while (i + 1 < n) {
            int loss = 0;
            while (i + 1 < n && prices[i] >= prices[i + 1]) {
                loss += prices[i] - prices[i + 1];
                i++;
            }
            rcd.push_back(loss);
            int gain = 0;
            while (i + 1 < n && prices[i] <= prices[i + 1]) {
                gain += prices[i + 1] - prices[i];
                i++;
            }
            rcd.push_back(gain);
            rst += gain;
        }
        if (!rcd.empty())rcd.erase(rcd.begin());
        if (!rcd.empty() && rcd.back() == 0)rcd.erase(rcd.end() - 2, rcd.end());
//        tools::printVectorInt(rcd);
        int count = rcd.size() / 2 + 1;
        while (count > k) {
            int min_loss = rcd.front(), min_id = 0;
            for (int j = 0; j < rcd.size(); ++j) {
                if (rcd[j] < min_loss) {
                    min_loss = rcd[j];
                    min_id = j;
                }
            }
            rst -= min_loss;
            if (min_id == 0) {
                rcd.erase(rcd.begin(), rcd.begin() + 2);
            } else if (min_id == rcd.size() - 1) {
                rcd.erase(rcd.end() - 2, rcd.end());
            } else {
                rcd[min_id - 1] += rcd[min_id + 1] - rcd[min_id];
                rcd.erase(rcd.begin() + min_id, rcd.begin() + min_id + 2);
            }
            count--;
//            tools::printVectorInt(rcd);
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> prices;
//        prices = {2, 1, 2, 1, 2, 1};
//        std::cout << maxProfit(2, prices) << std::endl;
//        prices = {2, 4, 1};
//        std::cout << maxProfit(2, prices) << std::endl;
//        prices = {3, 2, 6, 5, 0, 3};
//        std::cout << maxProfit(2, prices) << std::endl;
//        prices = {};
//        std::cout << maxProfit(2, prices) << std::endl;
//        prices = {1};
//        std::cout << maxProfit(2, prices) << std::endl;
//        prices = {3, 2, 1, 2, 3};
//        std::cout << maxProfit(2, prices) << std::endl;
//        prices = {5, 2, 3, 2, 6, 6, 2, 9, 1, 0, 7, 4, 5, 0};
//        std::cout << maxProfit(2, prices) << std::endl;
//        prices = {1,9,6,9,1,7,1,1,5,9,9,9};
//        std::cout << maxProfit(2, prices) << std::endl;
        prices = {1,9,6,9,1,7,1,1,5,9,9,9};
        std::cout << maxProfit(0, prices) << std::endl;
//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};