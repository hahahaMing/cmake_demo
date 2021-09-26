//
// Created by ming on 2021/3/4.
//

#ifndef CMAKETEST_Q0354_MAXENVELOPES_HPP
#define CMAKETEST_Q0354_MAXENVELOPES_HPP

#endif //CMAKETEST_Q0354_MAXENVELOPES_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    std::vector<std::vector<int>> involve;//无环有向图，involve[i]存包含的id。
    std::vector<int> rcd;//记录以当前元素开头的搜索深度（包括自己）
    int n;


    void dfs(int x) {
        if (rcd[x] != -1)return;
        int depth = 0;
        for (int y:involve[x]) {
            if (rcd[y] == -1)dfs(y);
            if (rcd[y] > depth)depth = rcd[y];
        }
        rcd[x] = depth + 1;
    }

public:
    int maxEnvelopes(std::vector<std::vector<int>> &envelopes) {
        if (envelopes.empty())return 0;
        n = envelopes.size();
        std::sort(envelopes.begin(), envelopes.end(), [](std::vector<int> &a, std::vector<int> &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        std::vector<int> rcd = {envelopes[0][1]};
        for (int i = 1; i < n; ++i) {
            int tmp = envelopes[i][1];
            if (tmp>rcd.back())rcd.push_back(tmp);
            else{
                //向前找第一个>=tmp的数，然后替换掉它
                auto it = std::lower_bound(rcd.begin(),rcd.end(),tmp);
                *it = tmp;
            }
        }
        return rcd.size();
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<std::vector<int>> envelopes;
        envelopes = {{5, 4},
                     {6, 4},
                     {6, 7},
                     {2, 3}};
        std::cout << maxEnvelopes(envelopes) << std::endl;
        envelopes = {};
        std::cout << maxEnvelopes(envelopes) << std::endl;
    }
};