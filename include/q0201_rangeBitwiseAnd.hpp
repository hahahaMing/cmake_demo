//
// Created by ming on 2020/8/23.
//

#ifndef CMAKETEST_Q0201_RANGEBITWISEAND_HPP
#define CMAKETEST_Q0201_RANGEBITWISEAND_HPP

#endif //CMAKETEST_Q0201_RANGEBITWISEAND_HPP

#include"tools.hpp"

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        /*
         * 通过最小数可得知最前位1的位置，通过范围大小，可得知尾部有几个零；
         */
        long r1 = 1;
        int count = 0;
        while (r1 <= m && count < 31) {
            r1 = r1 << 1;
            count++;
        }
        long rst = 0;
        for (int i = count - 1; i >= 0; --i) {
            if (i == 30) {
                if (rst + (1 << i) <= m && 2147483647 >= n)rst += (1 << i);
            } else if (rst + (1 << i) <= m && rst + ((1 << (i + 1)) - 1) >= n)rst += (1 << i);
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        long m, n;
//        m = (1 << 31) - 1;
//        n = (1 << 31) - 1;
//        std::cout << rangeBitwiseAnd(m, n) << std::endl;
//        m = 0;
//        n = (1 << 31) - 1;
//        std::cout << rangeBitwiseAnd(m, n) << std::endl;
//        m = 5;
//        n = 453453;
//        std::cout << rangeBitwiseAnd(m, n) << std::endl;
        m = 2147483646;
        n = 2147483647;
        std::cout << rangeBitwiseAnd(m, n) << std::endl;
    }
};