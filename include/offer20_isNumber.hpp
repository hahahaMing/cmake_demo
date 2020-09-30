//
// Created by ming on 2020/9/2.
//

#ifndef CMAKETEST_OFFER_ISNUMBER_HPP
#define CMAKETEST_OFFER_ISNUMBER_HPP

#endif //CMAKETEST_OFFER_ISNUMBER_HPP

#include"tools.hpp"

class Solution {
public:
    bool isNumber(std::string s) {
        bool e_lg = true, dot_lg = true, has_num = false;
        int ep=-2, st = 0, ed = s.length() - 1;
        for (int i = 0; i <= ed; ++i) {
            if (s[i] == ' ')st++;
            else break;
        }
        for (int i = ed; i >= 0; --i) {
            if (s[i] == ' ')ed--;
            else break;
        }
        for (int i = st; i <= ed; ++i) {
            if (!isdigit(s[i])) {
                if (s[i] == '+' || s[i] == '-') {

                    if ((i == st || i == ep + 1) && i != ed) {//开头e后正负号
                        continue;
                    } else return false;
                } else if (s[i] == '.') {
                    if (!dot_lg) return false;
                    dot_lg = false;
                } else if (s[i] == 'e' || s[i] == 'E') {
                    if (!e_lg || i == st || i ==ed ||!has_num || s[i + 1] == ' ')return false;
                    e_lg = false;
                    dot_lg = false;
                    ep = i;
                } else return false;
            } else has_num = true;
        }
        return has_num;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::string> v;
        v = {"46.e3","+.8","3.", ".1", "1 ", "+100", "5e2", "-123", "3.1416", "-1E-16", "0123", "12e", "1a3.14", "1.2.3", "+-5",
             "12e+5.4"," ", ". 1", "0e ","4e+"};
        for (const std::string &str:v) {
            std::cout << str << '\t';
            std::cout << isNumber(str) << std::endl;
        }


    }
};