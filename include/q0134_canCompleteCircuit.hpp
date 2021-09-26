//
// Created by ming on 2020/11/18.
//

#ifndef CMAKETEST_Q0134_CANCOMPLETECIRCUIT_HPP
#define CMAKETEST_Q0134_CANCOMPLETECIRCUIT_HPP

#endif //CMAKETEST_Q0134_CANCOMPLETECIRCUIT_HPP

#include"tools.hpp"

class Solution {
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
        /*
         * 把cost变为0
         * gas减去每个cost
         * 再建一个数组
         * 存从0出发到下一点前剩下的油gl
         * 找最低点
         */
        int n = gas.size(), sum = 0, min_sum = 0, min_id = 0;
        for (int i = 0; i < n; ++i) {
            gas[i] -= cost[i];
            sum += gas[i];
            if (sum < min_sum) {
                min_sum = sum;
                min_id = i;
            }
        }
        if (sum < 0)return -1;
        if (min_id == n - 1)return 0;
        return min_id + 1;
    }

    void test() {
        std::cout << "test start" << std::endl;

    }
};