//
// Created by ming on 2020/8/3.
//

#ifndef CMAKETEST_Q0028_STRSTR_HPP
#define CMAKETEST_Q0028_STRSTR_HPP

#endif //CMAKETEST_Q0028_STRSTR_HPP

#include"tools.hpp"

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.empty())return 0;
        int n = haystack.size() - needle.size();
        for (int i = 0; i <= n; ++i) {
            bool flag = true;
            for (int j = 0, k = i; j < needle.size(); ++j) {
                if (haystack[k] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)return i;
        }
        return -1;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string haystack,needle;
        haystack="aaa",needle="aaaa";

        for (int i = 0; i <= -1; ++i) {
            std::cout << "test start" << std::endl;
        }
        std::cout << strStr(haystack,needle) << std::endl;


    }
};