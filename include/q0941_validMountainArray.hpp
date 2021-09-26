//
// Created by ming on 2020/11/3.
//

#ifndef CMAKETEST_Q0941_VALIDMOUNTAINARRAY_HPP
#define CMAKETEST_Q0941_VALIDMOUNTAINARRAY_HPP

#endif //CMAKETEST_Q0941_VALIDMOUNTAINARRAY_HPP

#include"tools.hpp"

class Solution {
public:
    bool validMountainArray(std::vector<int> &A) {
        int i = 0, n = A.size();
        if (n < 3)return false;
        while (i < n - 1 && A[i] < A[i + 1]) {
            i++;
        }
        if (i == 0 || i == n - 1)return false;
        while (i < n - 1 && A[i] > A[i + 1]) {
            i++;
        }
        if (i < n - 1)return false;
        return true;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> A;
        A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::cout << validMountainArray(A) << std::endl;

    }
};