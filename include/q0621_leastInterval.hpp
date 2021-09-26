//
// Created by ming on 2020/12/5.
//

#ifndef CMAKETEST_Q0621_LEASTINTERVAL_HPP
#define CMAKETEST_Q0621_LEASTINTERVAL_HPP

#endif //CMAKETEST_Q0621_LEASTINTERVAL_HPP

#include"tools.hpp"

class Solution {
public:
    int leastInterval(std::vector<char> &tasks, int n) {
        if (tasks.empty())return 0;
        std::vector<int> rcd(26, 0);
        for (char c:tasks) { rcd[c - 'A']++; }
        std::sort(rcd.begin(), rcd.end(), [](int a, int b) { return a > b; });
        int total = tasks.size(), ecp = 0, max_rcd = rcd.front();
        while (++ecp < 26 && rcd[ecp] == max_rcd);
        max_rcd--;
        return std::max(total, max_rcd * (n + 1) + ecp);
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<char> tasks;
        int n;
        tasks = {'A', 'A', 'A', 'B', 'B', 'B'}, n = 2;
        std::cout << leastInterval(tasks, n) << std::endl;
        tasks = {'A', 'A', 'A', 'B', 'B', 'B'}, n = 0;
        std::cout << leastInterval(tasks, n) << std::endl;
        tasks = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'}, n = 2;
        std::cout << leastInterval(tasks, n) << std::endl;
    }
};