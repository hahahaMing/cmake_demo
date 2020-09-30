//
// Created by ming on 2020/7/22.
//

#ifndef CMAKETEST_OFFER11_MINARRAY_HPP
#define CMAKETEST_OFFER11_MINARRAY_HPP

#endif //CMAKETEST_OFFER11_MINARRAY_HPP

#include"tools.hpp"

class Solution {
public:
    int minArray(std::vector<int> &numbers) {
        int l = 0, r = numbers.size() - 1, m = (l + r) / 2;
        int L, R, M;
        while (l < m) {
            R = numbers[r], L = numbers[l], M = numbers[m];
            if (L == R & L == M) {
                l++;
                m = (l + r) / 2;
            } else if (R <= L && L <= M) {
                l = m;
                m = (l + r) / 2;
            } else if (M <= R && R <= L) {
                r = m;
                m = (l + r) / 2;
            } else if (L <= M && M <= R) {
                return L;
            }
        }
        return std::min(numbers[l], numbers[r]);
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> v;
//        v = {3, 4, 5, 1, 2};
//        std::cout << minArray(v) << std::endl;
//        v = {2, 2, 2, 0, 1};
//        std::cout << minArray(v) << std::endl;
        v = {10, 1, 10, 10, 10};
        std::cout << minArray(v) << std::endl;
    }
};