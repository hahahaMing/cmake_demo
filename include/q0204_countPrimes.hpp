//
// Created by ming on 2020/12/3.
//

#ifndef CMAKETEST_Q0204_COUNTPRIMES_HPP
#define CMAKETEST_Q0204_COUNTPRIMES_HPP

#endif //CMAKETEST_Q0204_COUNTPRIMES_HPP

#include"tools.hpp"

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)return 0;
        std::vector<int> rcd(n, 0);
        int rst = 0;
        for (int i = 2; i < n; ++i) {
            if (rcd[i] == 0) {
                rst++;
                for (int j = i; j < n; j += i) {
                    if (rcd[j] == 0)rcd[j] = 1;
                }
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;


    }
};