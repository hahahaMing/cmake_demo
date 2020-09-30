//
// Created by ming on 2020/6/9.
//

#ifndef CMAKETEST_M4600_TRANSLATENUM_HPP
#define CMAKETEST_M4600_TRANSLATENUM_HPP

#endif //CMAKETEST_M4600_TRANSLATENUM_HPP

#include"tools.hpp"

class Solution {
public:
    int translateNum(int num) {
        //单个字符肯定可以
        //双字符需要判断是否小于26
        //动态规划
        //记录以当前数字结尾种数a和以上一个数字结尾种数b
        int a = 1, b = 1, tmp;
        int i = -1, last_i = 26;
        while (num > 0) {
            if (i != -1)last_i = i;
            i = num % 10;
            num /= 10;
            tmp = a;
            if (i && last_i + i * 10 < 26)a += b;//如果更新出来的两个数字：1.开头不为0；2.小于26；就把b加到a上
            b = tmp;
        }
        return a;
    }

    void test() {
        std::cout << "test start" << std::endl;
        int num;
        num = 12258;
        std::cout << translateNum(num) << std::endl;
        num = 1;
        std::cout << translateNum(num) << std::endl;
        num = 25;
        std::cout << translateNum(num) << std::endl;
        num = 26;
        std::cout << translateNum(num) << std::endl;
        num = 506;//1
        std::cout << translateNum(num) << std::endl;
    }
};