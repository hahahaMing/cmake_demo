//
// Created by ming on 2020/12/25.
//

#ifndef CMAKETEST_Q0455_FINDCONTENTCHILDREN_HPP
#define CMAKETEST_Q0455_FINDCONTENTCHILDREN_HPP

#endif //CMAKETEST_Q0455_FINDCONTENTCHILDREN_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int findContentChildren(std::vector<int> &g, std::vector<int> &s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int i = 0, j = 0, rst = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                i++;
                j++;
                rst++;
            } else {
                j++;
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> g,s;
        g = {1,2,3};
        s = {1,1};
        std::cout << findContentChildren(g,s) << std::endl;
        g = {1,2};
        s = {1,2,3};
        std::cout << findContentChildren(g,s) << std::endl;
        g = {1,2};
        s = {};
        std::cout << findContentChildren(g,s) << std::endl;
        g = {};
        s = {1,2,3};
        std::cout << findContentChildren(g,s) << std::endl;


//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};