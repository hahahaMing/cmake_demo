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
        //转为正数相除
        int sign = 1;
        if (dividend < 0) {
            sign = -sign;
            dividend = -dividend;
        }
        if (divisor < 0) {
            sign = -sign;
            divisor = -divisor;
        }
        //相除


        //添加符号


    }

    void test() {
        std::cout << "test start" << std::endl;

        std::cout << divide(10, 3) << std::endl;
        std::cout << divide(7, -3) << std::endl;

    }

};