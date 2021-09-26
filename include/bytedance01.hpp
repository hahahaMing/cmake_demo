//
// Created by ming on 2020/10/21.
//

#ifndef CMAKETEST_BYTEDANCE01_HPP
#define CMAKETEST_BYTEDANCE01_HPP

#endif //CMAKETEST_BYTEDANCE01_HPP

#include"tools.hpp"
#include <cstdlib>

class Solution {
public:
    std::string find_longest_substr(std::string str) {
        /*
         * 记录当前最长无重复子串与以当前位为结尾的无重复子串
         */
        if (str.empty())return str;
        std::string cur = str.substr(0,1), dp = str.substr(0,1);
        int n = str.size();
        for (int i = 1; i < n; ++i) {
            int dpl = dp.size();
            //从后向前遍历，如果有一样的就更新dp
            int j;
            for (j = dpl - 1; j >= 0; --j) {
                if (dp[j] == str[i]) {
                    break;
                }
            }
            if (j>=0){
                dp = dp.substr(j+1,dpl-j-1);
                dp = dp+str[i];
            }else{
                dp = dp+str[i];
                if (dp.size()>cur.size())cur = dp;
            }
            //如果没有就把这一位加到dp上，同时与cur比长度，更新cur
        }

        return cur;
    }


    void test() {
        std::cout << "test start" << std::endl;
        std::string test_str;
        test_str = "ahavbbdfghh";
        std::cout << find_longest_substr(test_str)<< std::endl;
        test_str = "abc";
        std::cout << find_longest_substr(test_str)<< std::endl;
        test_str = "ccc";
        std::cout << find_longest_substr(test_str)<< std::endl;
        test_str = "";
        std::cout << find_longest_substr(test_str)<< std::endl;
        test_str = "ababcabcd";
        std::cout << find_longest_substr(test_str)<< std::endl;

    }
};