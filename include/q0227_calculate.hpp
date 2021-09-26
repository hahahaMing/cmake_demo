//
// Created by ming on 2021/3/11.
//

#ifndef CMAKETEST_Q0227_CALCULATE_HPP
#define CMAKETEST_Q0227_CALCULATE_HPP

#endif //CMAKETEST_Q0227_CALCULATE_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int calculate(std::string s) {
        //先做乘除再做加减
        bool is_pos = true, is_plus = true;
        std::string num_s;
        int rst = 0, num = 1, tmp = 0;
        for (const char c:s) {
            if (c == ' ')continue;
            if (c == '+' || c == '-') {
                if (is_plus)num *= tmp;
                else num /= tmp;
                rst += is_pos ? num : -num;
                num = 1;
                tmp = 0;
                if (c == '+') is_pos = true;
                else is_pos = false;
                is_plus = true;
            } else if (c == '*' || c == '/') {
                if (is_plus)num *= tmp;
                else num /= tmp;
                tmp = 0;
                if (c == '*')is_plus = true;
                else is_plus = false;
            } else {//数字
                tmp = tmp * 10 + c - '0';
            }
        }
        if (is_plus)num *= tmp;
        else num /= tmp;
        rst += is_pos ? num : -num;
        return rst;
    }



    void test() {
        std::cout << "test start" << std::endl;
        std::string s;
        s = "3+2*2";
        std::cout << s << '=' << calculate(s) << std::endl;
        s = " 3/2 ";
        std::cout << s << '=' << calculate(s) << std::endl;
        s = " 3+5 / 2 ";
        std::cout << s << '=' << calculate(s) << std::endl;

    }
};