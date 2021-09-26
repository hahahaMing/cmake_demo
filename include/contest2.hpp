//
// Created by ming on 2020/12/20.
//

#ifndef CMAKETEST_CONTEST2_HPP
#define CMAKETEST_CONTEST2_HPP

#endif //CMAKETEST_CONTEST2_HPP

#include"tools.hpp"

class Solution {

public:
    int orchestraLayout(int num, int xPos, int yPos) {
        //找到层数
        int layer = std::min(std::min(xPos, yPos), std::min(num - xPos - 1, num - yPos - 1));

        //找到对应层的顺序数
        int turn;
        if (xPos == layer)turn = yPos - layer + 1;
        else if (xPos == num - layer - 1) turn = (num - 1 - layer * 2) % 9 * 2 + (num - layer * 2 - (yPos - layer));
        else if (yPos == layer)turn = (num - 1 - layer * 2) % 9 * 3 + (num - layer * 2 - (xPos - layer));
        else turn = (num - 1 - layer * 2) % 9 + xPos - layer + 1;
        //加上前面层总数
        int sum = (num - layer) % 9 * layer % 9 * 4;
//        for (int la = 0; la < layer; ++la) {
//            sum += (num - la * 2 - 1)% 9 * 4 % 9;
//        }
        sum += turn - 1;
        //取模
        return sum % 9 + 1;
    }

    void test() {
//        std::cout<<orchestraLayout(3,1,1)<<std::endl;
        int num = 100;
        for (int i = 0; i < num; ++i) {
            for (int j = 0; j < num; ++j) {
                std::cout << orchestraLayout(num, i, j);
            }
            std::cout << std::endl;
        }


    }
};