//
// Created by ming on 2020/12/10.
//

#ifndef CMAKETEST_Q0860_LEMONADECHANGE_HPP
#define CMAKETEST_Q0860_LEMONADECHANGE_HPP

#endif //CMAKETEST_Q0860_LEMONADECHANGE_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 */
class Solution {
public:
    bool lemonadeChange(std::vector<int> &bills) {
        int five = 0, ten = 0;
        for (int bill:bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five > 0) {
                    five--;
                    ten++;
                } else return false;
            } else {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else return false;
            }
        }
        return true;
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