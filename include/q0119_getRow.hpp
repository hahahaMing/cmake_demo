//
// Created by ming on 2021/2/12.
//

#ifndef CMAKETEST_Q0119_GETROW_HPP
#define CMAKETEST_Q0119_GETROW_HPP

#endif //CMAKETEST_Q0119_GETROW_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    int factorial(int x) {
        if (x <= 1)return 1;
        int rst = 1;
        for (int i = 1; i <= x; ++i) {
            rst *= i;
        }
        return rst;
    }

public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> rst(rowIndex+1, 1);
        for (int i = 1; i < rowIndex; ++i) {
            rst[i] = int(double(rst[i - 1]) * (rowIndex+1 - i)/ i) ;
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        for (int i = 1; i <= 33; ++i) {
            tools::printVectorInt(getRow(i));
        }

    }
};