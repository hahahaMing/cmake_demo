//
// Created by ming on 2021/2/23.
//

#ifndef CMAKETEST_Q1052_MAXSATISFIED_HPP
#define CMAKETEST_Q1052_MAXSATISFIED_HPP

#endif //CMAKETEST_Q1052_MAXSATISFIED_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int maxSatisfied(std::vector<int> &customers, std::vector<int> &grumpy, int X) {
        int n = customers.size();
        //遍历一遍，得到不控制的答案
        int rst = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0)rst += customers[i];
        }
        //控制窗口滑动，得到最多满意客户增加数量
        int add = 0;
        for (int i = 0; i < X; ++i) {
            if (grumpy[i] == 1)add += customers[i];
        }
        int tmp = add;
        for (int r = X; r < n; ++r) {
            if (grumpy[r - X] == 1)tmp -= customers[r - X];
            if (grumpy[r] == 1)tmp += customers[r];
            if (tmp > add)add = tmp;
        }
        return add + rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> customers;
        std::vector<int> grumpy;
        int X;
        customers = {1, 0, 1, 2, 1, 1, 7, 5}, grumpy = {0, 1, 0, 1, 0, 1, 0, 1}, X = 3;
        std::cout << maxSatisfied(customers, grumpy, X) << std::endl;

    }
};