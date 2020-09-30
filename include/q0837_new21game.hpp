//
// Created by ming on 2020/6/3.
//

#ifndef CMAKETEST_Q0837_NEW21GAME_HPP
#define CMAKETEST_Q0837_NEW21GAME_HPP

#endif //CMAKETEST_Q0837_NEW21GAME_HPP

#include"tools.hpp"

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 1) {
            double c = N > W ? 1.0 : double(N) / double(W);
            return c;
        }
        if (K == 0)return 1;
        double rst = 0;
        for (int i = 1; i <= W; ++i) {
            if (K - i > 0) {
                rst += 1.0 / W * new21Game(N - i, K - i, W);
            } else if (N - i >= 0) {
                rst += 1.0 / W;

            }

        }

        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        int N, K, W;
        N = 5, K = 3, W = 2;
        std::cout << new21Game(N, K, W) << std::endl;
        N = 21, K = 17, W = 10;
        std::cout << new21Game(N, K, W) << std::endl;
        N = 10, K = 1, W = 10;
        std::cout << new21Game(N, K, W) << std::endl;
        N = 6, K = 1, W = 10;
        std::cout << new21Game(N, K, W) << std::endl;
        N = 0, K = 0, W = 1;
        std::cout << new21Game(N, K, W) << std::endl;
        N = 421, K = 400, W = 47;
        std::cout << new21Game(N, K, W) << std::endl;
    }
};