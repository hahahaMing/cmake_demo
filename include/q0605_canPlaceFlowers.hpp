//
// Created by ming on 2021/1/1.
//

#ifndef CMAKETEST_Q0605_CANPLACEFLOWERS_HPP
#define CMAKETEST_Q0605_CANPLACEFLOWERS_HPP

#endif //CMAKETEST_Q0605_CANPLACEFLOWERS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
        int len = flowerbed.size();
        for (int i = 0; i < len; ++i) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == len - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                n--;
            }
            if (n <= 0)return true;
        }
        return false;
    }

    void test() {
        std::cout << "test start" << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};