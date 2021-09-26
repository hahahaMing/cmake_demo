//
// Created by ming on 2020/12/6.
//

#ifndef CMAKETEST_Q0118_GENERATE_HPP
#define CMAKETEST_Q0118_GENERATE_HPP

#endif //CMAKETEST_Q0118_GENERATE_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> rst;
        for (int i = 0; i < numRows; ++i) {
            rst.push_back({1});
            if (i > 0) {
                if (i > 1) {
                    for (int j = 0; j < i - 1; ++j) {
                        rst[i].push_back(rst[i - 1][j] + rst[i - 1][j + 1]);
                    }
                }
                rst[i].push_back(1);
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        tools::print2DVector(generate(5));
        tools::print2DVector(generate(0));

    }
};