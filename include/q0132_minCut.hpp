//
// Created by ming on 2021/3/8.
//

#ifndef CMAKETEST_Q0132_MINCUT_HPP
#define CMAKETEST_Q0132_MINCUT_HPP

#endif //CMAKETEST_Q0132_MINCUT_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::string com_s;
    std::vector<std::vector<int>> rcd;

    bool is_palindrome(int i, int j) {
        if (rcd[i][j]==1)return true;
        if (rcd[i][j]==-1)return false;
        bool rst;
        if (i == j) {
            rst = true;
        } else {
            if (com_s[i] == com_s[j]) {
                if (i + 1 == j || is_palindrome(i + 1, j - 1)) rst = true;
                else rst = false;
            } else rst = false;
        }
        if (rst) rcd[i][j] = 1;
        else rcd[i][j] = -1;
        return rst;
    }

public:
    int minCut(std::string s) {
        if (s.empty())return 0;
        int n = s.size();
        com_s = s;
        rcd = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
        std::vector<int> min_num(n, 1);//记录前i个字符中最少回文子串的数量
        for (int i = 1; i < n; ++i) {
            if (is_palindrome(0, i))continue;
            min_num[i] = i + 1;
            for (int j = 1; j <= i; ++j) {
                if (is_palindrome(j, i)) {
                    if (min_num[j - 1] + 1 < min_num[i])
                        min_num[i] = min_num[j - 1] + 1;
                }
            }
        }
        tools::printVectorInt(min_num);
        return min_num.back() - 1;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s;
        s = "cabababcbc";
        std::cout << minCut(s) << std::endl;
        s = "aab";
        std::cout << minCut(s) << std::endl;
        s = "a";
        std::cout << minCut(s) << std::endl;
        s = "ab";
        std::cout << minCut(s) << std::endl;
        s = "ababababababababababababcbabababababababababababa";
        std::cout << minCut(s) << std::endl;


    }
};