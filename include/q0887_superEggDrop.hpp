#include "iostream"
#include "string"
#include "algorithm"
#include "cmath"

class Solution {
private:
    int max_N(int k, int x) {
        if (k == 1) return x;
        int temp = x;
        for (int i = 1; i < x; i++) temp += max_N(k - 1, i);
        return temp;
    }

public:
    int superEggDrop(int K, int N) {
        int x = log(double(N)) / log(2);
        while (N > max_N(K, x)) x++;
        return x;
    }

    void test() {
        std::cout << "test start" << std::endl;
//        int K, x;
//        K = 3;
//        x = 3;
//        std::cout << "K:" << K << " x:" << x << " max_N:" << max_N(K, x) << std::endl;


        int K, N;
        K = 2;
        N = 6;
        std::cout << "K:" << K << " N:" << N << " X:" << superEggDrop(K, N) << std::endl;
        K = 3;
        N = 14;
        std::cout << "K:" << K << " N:" << N << " X:" << superEggDrop(K, N) << std::endl;
    }
};
