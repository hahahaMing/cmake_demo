//
// Created by ming on 2020/5/27.
//

#ifndef CMAKETEST_Q0974_SUBARRAYSDIVBYK_HPP
#define CMAKETEST_Q0974_SUBARRAYSDIVBYK_HPP

#endif //CMAKETEST_Q0974_SUBARRAYSDIVBYK_HPP

#include"tools.hpp"

class Solution {
public:
    int subarraysDivByK(std::vector<int> &A, int K) {
        std::map<int, int> m;
        std::map<int, int> t;
        int rst = 0;
        //余下就是更新那K个数
        for (auto i : A) {
            if (i < 0)i = K - (-i) % K;
            for (auto &it : m) {
                t[(it.first + i) % K] = it.second;
            }
            m.swap(t);
            t.clear();
            if (m.find(i % K) != m.end()) m[i % K] += 1;
            else m[i % K] = 1;
            if (m.find(0)!=m.end())rst+=m[0];
        }

        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> A;
        int K;
//        A = {4, 5, 0, -2, -3, 1};
//        K = 5;
//        std::cout << subarraysDivByK(A,K) << std::endl;

        A = {5};
        K = 9;
        std::cout << subarraysDivByK(A, K) << std::endl;


        A = {0, -5};
        K = 10;
        std::cout << subarraysDivByK(A, K) << std::endl;
    }
};