//
// Created by ming on 2020/12/15.
//

#ifndef CMAKETEST_Q0738_MONOTONEINCREASINGDIGITS_HPP
#define CMAKETEST_Q0738_MONOTONEINCREASINGDIGITS_HPP

#endif //CMAKETEST_Q0738_MONOTONEINCREASINGDIGITS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if (N < 10)return N;
        int tmp = monotoneIncreasingDigits(N / 10);
        if (tmp < N / 10)return tmp * 10 + 9;
        if (tmp % 10 <= N % 10)return tmp * 10 + N % 10;
        else return monotoneIncreasingDigits(tmp - 1) * 10 + 9;
    }

    void test() {
        std::cout << "test start" << std::endl;
        for (int i = 0; i < 10; ++i) {
            int tmp = tools::GetRandomNumber(0,1000000000);
            std::cout << tmp << ": ";
            std::cout << monotoneIncreasingDigits(tmp)<< std::endl;
        }

        std::cout << monotoneIncreasingDigits(332)<< std::endl;
        std::cout << monotoneIncreasingDigits(10)<< std::endl;
        std::cout << monotoneIncreasingDigits(1234)<< std::endl;
//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};