//
// Created by ming on 2020/8/3.
//

#ifndef CMAKETEST_Q0029_DIVIDE_HPP
#define CMAKETEST_Q0029_DIVIDE_HPP

#endif //CMAKETEST_Q0029_DIVIDE_HPP

#include"tools.hpp"

class Solution {
public:
    int divide(int dividend, int divisor) {
        /*
         * 利用移位做到乘除
         */
        bool pstv = dividend < 0 ^divisor < 0;
        if (dividend < 0) dividend = -dividend;
        if (divisor < 0)divisor = -divisor;
        if (divisor > dividend)return 0;
        int i = 0, a = dividend, b = divisor;
        while (a > b) {
            b = b << 1;
            i++;
        }
        int rst = (1 << (i - 1));
        rst += divide(dividend - rst, divisor);
        if (pstv)return rst;
        else return -rst;
    }

    void test() {
        std::cout << "test start" << std::endl;

    }

};