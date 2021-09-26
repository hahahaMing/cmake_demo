//
// Created by ming on 2020/11/15.
//

#ifndef CMAKETEST_Q0402_REMOVEKDIGITS_HPP
#define CMAKETEST_Q0402_REMOVEKDIGITS_HPP

#endif //CMAKETEST_Q0402_REMOVEKDIGITS_HPP

#include"tools.hpp"

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::string rst;
        char tmp = '9';
        int loc = 0, n = num.size(), left = 0, count = 0;
        while (k > 0) {
            tmp = '9';
            int last_loc = 0,min_loc = 0;
            for (int i = 0; i < k + 1; ++i) {
                last_loc = i + loc;
                if (last_loc >= n) {
                    if (rst.empty())return "0";
                    else return rst;
                }
                if (num[last_loc] < tmp) {
                    tmp = num[last_loc];
                    min_loc = last_loc;
                }
            }
            k -= min_loc - loc;
            loc = min_loc + 1;
            if (!rst.empty() || tmp != '0')rst.push_back(tmp);
        }
        for (int i = loc; i < n; ++i) {
            if (!rst.empty() || num[i] != '0')rst.push_back(num[i]);
        }
        if (rst.empty())return "0";
        else return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string num;
        int k;
        num = "1432219";
        for (int i = num.size(); i >= 0; --i) {
            std::cout << removeKdigits(num, i) << std::endl;
        }
        num = "10200";
        for (int i = num.size(); i >= 0; --i) {
            std::cout << removeKdigits(num, i) << std::endl;
        }
        num = "10";
        for (int i = num.size(); i >= 0; --i) {
            std::cout << removeKdigits(num, i) << std::endl;
        }
        num = "112";
        for (int i = num.size(); i >= 0; --i) {
            std::cout << removeKdigits(num, i) << std::endl;
        }
        num = "1783";
        for (int i = num.size(); i >= 0; --i) {
            std::cout << removeKdigits(num, i) << std::endl;
        }
        num = "1783";
        k = 1;
        std::cout << removeKdigits(num, k) << std::endl;


    }
};