#include"tools.hpp"

class Solution {
public:
    int clumsy(int N) {
        int rst = 0;
        int tmp = N--;
        while (N > 0) {
            tmp *= N--;
            if (N <= 0)return rst + tmp;
            tmp /= N--;
            if (N <= 0)return rst + tmp;
            tmp += N--;
            if (N <= 0)return rst + tmp;
            rst += tmp;
            tmp = -N--;
        }
        return rst + tmp;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::cout << clumsy(4) << std::endl;
        std::cout << clumsy(10) << std::endl;
    }
};