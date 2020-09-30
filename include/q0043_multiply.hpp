//
// Created by ming on 2020/8/13.
//

#ifndef CMAKETEST_Q0043_MULTIPLY_HPP
#define CMAKETEST_Q0043_MULTIPLY_HPP

#endif //CMAKETEST_Q0043_MULTIPLY_HPP

#include"tools.hpp"

class Solution {
    std::string add_misposition(std::string &a, std::string &b, int mp) {
        std::string rst;
        for (int i = 0; i < mp; ++i) {
            if (i < a.size()) rst.push_back(a[i]);
            else rst.push_back('0');
        }
        int i = mp, j = 0, carry = 0;
        while (i < a.size() || j < b.size()) {
            int c;
            if (i >= a.size()) c = b[j] - '0' + carry;
            else if (j >= b.size()) c = a[i] - '0' + carry;
            else c = a[i] - '0' + b[j] - '0' + carry;
            rst.push_back(c % 10 + '0');
            carry = c / 10;
        }
        if (carry)rst.push_back('0' + carry);
        return rst;
    }

public:
    std::string multiply(std::string num1, std::string num2) {
        /*
         * 取一个逐位相乘，然后再错位加到一起
         */
        std::string rst;
        for (int i = 0; i < num2.size(); ++i) {
            std::string tmp;
            int a = num2[i] - '0';
            int carry = 0;
            for (int j = 0; j < num1.size(); ++j) {
                int b = (num1[j] - '0') * a + carry;
                tmp.push_back('0' + b % 10);
                carry = b / 10;
            }
            if (carry)tmp.push_back('0' + carry);
            //错位合并
            rst = add_misposition(rst, tmp, i);
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string num1, num2;
        num1 = "1";
        num2 = "84";
        std::cout << multiply(num1, num2) << std::endl;

    }
};