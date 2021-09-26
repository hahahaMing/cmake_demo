//
// Created by ming on 2020/12/9.
//

#ifndef CMAKETEST_Q0062_UNIQUEPATHS_HPP
#define CMAKETEST_Q0062_UNIQUEPATHS_HPP

#endif //CMAKETEST_Q0062_UNIQUEPATHS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        double rst = 1;
        for (int i = 0; i < n - 1; ++i) {
            rst *= (double(m + i) / double(i + 1));
        }
        if (rst - int(rst) > 0.5)return int(rst) + 1;
        else return int(rst);
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::cout << uniquePaths(3, 7) << std::endl;
        std::cout << uniquePaths(3, 2) << std::endl;
        std::cout << uniquePaths(11, 11) << std::endl;

//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};