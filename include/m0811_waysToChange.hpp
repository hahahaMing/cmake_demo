//
// Created by ming on 2020/4/23.
//

#ifndef CMAKETEST_M0811_WAYSTOCHANGE_HPP
#define CMAKETEST_M0811_WAYSTOCHANGE_HPP

#endif //CMAKETEST_M0811_WAYSTOCHANGE_HPP

#include "tools.hpp"

class Solution {
public:

    int way5(int n) { return n / 5 + 1; }

    int way10(int n) {
        int rst = 0, m = n / 10;
        for (int i = 0; i <= m; i++) rst += way5(n - 10 * i);
        return rst;
    }

    int waysToChange(int n) {
        if (n <= 0) return 0;
        int rst = 0, m = n / 25;
        for (int i = 0; i <= m; i++) {
            rst += way10(n - 25 * i);
        }
        return rst%1000000007;
    }
    int waysToChange2(int n) {
        int ans = 0;
        for (int i = 0; i <= n / 25; i ++) {
            int rest = n - i * 25;
            int p = rest / 5;
            int q = rest / 10;
            ans += (p + 1)*(q + 1)  - q*(q + 1);
        }
        return ans;
    }

    void test() {
        std::cout << "test start" << std::endl;
        int n;

//        n = 5;//2
//        std::cout << waysToChange(n) << std::endl;
////
//        n = 10;//4
//        std::cout << waysToChange(n) << std::endl;
//
//        n = 25;//13
//        std::cout << waysToChange(n) << std::endl;
////
//        n = 100;//242
//        std::cout << waysToChange(n) << std::endl;
//
//        n = 1000000;//332576607
//        std::cout << waysToChange(n) << std::endl;

//        n = 1654;//2
//        std::cout << waysToChange(n) << std::endl;
//
//        n = 1546;//4
//        std::cout << waysToChange(n) << std::endl;
//
//        n = 1879;//13
//        std::cout << waysToChange(n) << std::endl;
//
//        n = 598;//242
//        std::cout << waysToChange(n) << std::endl;

        n = 900750;//2
        std::cout << waysToChange(n) << std::endl;
        std::cout << waysToChange2(n) << std::endl;



    }
};