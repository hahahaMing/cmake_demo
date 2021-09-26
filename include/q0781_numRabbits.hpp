#include"tools.hpp"

class Solution {
public:
    int numRabbits(std::vector<int> &answers) {
        std::vector<int> rcd(1000, 0);
        for (int i:answers)rcd[i]++;
        int rst = 0;
        for (int i = 0; i < 1000; ++i) {
            rst += rcd[i];
            if (rcd[i] % (i + 1))rst += i + 1 - rcd[i] % (i + 1);
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> ans;
        ans = {1, 0, 1, 0, 0};
        std::cout << numRabbits(ans) << std::endl;
    }
};