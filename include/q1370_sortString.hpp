//
// Created by ming on 2020/11/25.
//

#ifndef CMAKETEST_Q1370_SORTSTRING_HPP
#define CMAKETEST_Q1370_SORTSTRING_HPP

#endif //CMAKETEST_Q1370_SORTSTRING_HPP

#include"tools.hpp"

class Solution {
public:
    std::string sortString(std::string s) {
        std::sort(s.begin(), s.end());
        int n = s.size(), count = 0;
        std::vector<int> used(n, 0);
        char last;
        std::string rst;
        while (count < n) {
            last = 'a' - 1;
            for (int i = 0; i < n; ++i) {
                if (used[i] == 0 && s[i] != last) {
                    used[i] = 1;
                    rst.push_back(s[i]);
                    last = s[i];
                    count++;
                }
            }
            last = 'z' + 1;
            for (int i = n - 1; i > 0; --i) {
                if (used[i] == 0 && s[i] != last) {
                    used[i] = 1;
                    rst.push_back(s[i]);
                    last = s[i];
                    count++;
                }
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s;
        s = "";
        std::cout << sortString(s) << std::endl;
        s = "aaaabbbbcccc";
        std::cout << sortString(s) << std::endl;
        s = "rat";
        std::cout << sortString(s) << std::endl;
        s = "leetcode";
        std::cout << sortString(s) << std::endl;
        s = "ggggggg";
        std::cout << sortString(s) << std::endl;
        s = "spo";
        std::cout << sortString(s) << std::endl;

    }
};