//
// Created by ming on 2020/11/29.
//

#ifndef CMAKETEST_Q0976_LARGESTPERIMETER_HPP
#define CMAKETEST_Q0976_LARGESTPERIMETER_HPP

#endif //CMAKETEST_Q0976_LARGESTPERIMETER_HPP

#include"tools.hpp"

class Solution {
public:
    int largestPerimeter(std::vector<int> &A) {
        if (A.size() < 3)return 0;
        std::sort(A.begin(), A.end(), [](int a, int b) { return a > b; });
        int n = A.size();
        for (int i = 2; i < n; ++i) {
            if (A[i] + A[i - 1] > A[i - 2]) return A[i] + A[i - 1] + A[i - 2];
        }
        return 0;
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