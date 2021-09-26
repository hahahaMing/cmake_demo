#include"tools.hpp"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rst = 0;
        for (int i = 0; i < 31; ++i) {
            rst = rst | (n & 1);
            rst = rst << 1;
            n = n >> 1;
        }
        return rst | (n & 1);;
    }

    void test() {
        std::cout << "test start" << std::endl;
        uint32_t n;
        n = 43261596;
        std::cout << std::bitset<32>(n) << std::endl;
        std::cout << std::bitset<32>(reverseBits(n)) << std::endl;
    }
};