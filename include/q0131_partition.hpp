//
// Created by ming on 2021/3/7.
//

#ifndef CMAKETEST_Q0131_PARTITION_HPP
#define CMAKETEST_Q0131_PARTITION_HPP

#endif //CMAKETEST_Q0131_PARTITION_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    bool is_palindrome(std::string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - i - 1])return false;
        }
        return true;
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        if (s.empty())return {};
        std::vector<std::vector<std::string>> rst = {{{s[0]}}};
        std::vector<bool> is_back_all_same = {true};
        int n = s.size();
        for (int i = 1; i < n; ++i) {
            int len = rst.size();
            for (int j = 0; j < len; ++j) {
                if (is_back_all_same[j] && rst[j].back()[0] == s[i]) {
                    rst.push_back(rst[j]);
                    rst[j + len].back().push_back(s[i]);
                    is_back_all_same.push_back(true);
                } else {
                    int jlen = rst[j].size();
                    if (jlen > 1 && rst[j][jlen - 2].size() == 1 && rst[j][jlen - 2][0] == s[i]){
                        std::string tmp = rst[j][jlen - 2]+rst[j].back()+rst[j][jlen - 2];
                        rst.push_back(rst[j]);
                        rst.back().erase(rst.back().end()-2,rst.back().end());
                        rst.back().push_back(tmp);
                        is_back_all_same.push_back(false);
                    }
                }
            }
            for (int j = 0; j < len; ++j) {
                rst[j].push_back({s[i]});
                is_back_all_same[j] = true;
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s;
        s = "aabaa";
        tools::print2DvectorString(partition(s));
        s = "abab";
        tools::print2DvectorString(partition(s));
        s = "aab";
        tools::print2DvectorString(partition(s));
    }
};