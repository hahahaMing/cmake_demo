//
// Created by ming on 2021/3/18.
//

#ifndef CMAKETEST_Q0115_NUMDISTINCT_HPP
#define CMAKETEST_Q0115_NUMDISTINCT_HPP

#endif //CMAKETEST_Q0115_NUMDISTINCT_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        //动态规划，记录t的前j位在s前i位中出现的次数rcd
        //转移方程：if(s[i]==t[j]) rcd[i][j] = rcd[i-1][j]+rcd[i-1][j-1];
        //        else rcd[i][j] = rcd[i-1][j];
        if (s.empty()||t.empty())return 0;
        int m = t.size(), n = s.size();
        std::vector<std::vector<int>> rcd(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            if (i==0){
                if (t[0]==s[0])rcd[0][0]=1;
                continue;
            }
            for (int j = 0; j < m; ++j) {
                if (j==0){
                    if (s[i] == t[j]) rcd[i][j] = rcd[i - 1][j] + 1;
                    else rcd[i][j] = rcd[i - 1][j];
                    continue;
                }
                if (s[i] == t[j]) rcd[i][j] = rcd[i - 1][j] + rcd[i - 1][j - 1];
                else rcd[i][j] = rcd[i - 1][j];
            }
        }
//        tools::print_matrix(rcd);
        return rcd.back().back();
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::string s,t;
        s = "rabbbit", t = "rabbit";
        std::cout << numDistinct(s,t) << std::endl;
        s = "babgbag", t = "bag";
        std::cout << numDistinct(s,t) << std::endl;
    }
};