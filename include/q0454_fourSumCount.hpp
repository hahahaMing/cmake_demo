//
// Created by ming on 2020/11/27.
//

#ifndef CMAKETEST_Q0454_FOURSUMCOUNT_HPP
#define CMAKETEST_Q0454_FOURSUMCOUNT_HPP

#endif //CMAKETEST_Q0454_FOURSUMCOUNT_HPP

#include"tools.hpp"

class Solution {
public:
    int fourSumCount(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C, std::vector<int> &D) {
        /*
         * 每两个数组建立一个字典
         */
        int n = A.size(), rst = 0;


        std::unordered_map<int, int> AB, CD;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (AB.find(A[i] + B[j]) == AB.end())AB[A[i] + B[j]] = 1;
                else AB[A[i] + B[j]] += 1;
                if (CD.find(-C[i] - D[j]) == CD.end())CD[-C[i] - D[j]] = 1;
                else CD[-C[i] - D[j]] += 1;
            }
        }
        for (auto &it1 : AB) {
            for (auto &it2 : CD) {
                if (it1.first == it2.first)rst += it1.second * it2.second;
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::mt19937 rng(std::random_device{}());
        std::vector<int> vec;
        for (int i = 0; i < 10; ++i) {
            vec = tools::random_vector(rng, 0, 9, -99, 99);
            tools::printVectorInt(vec);
        }
    }
};