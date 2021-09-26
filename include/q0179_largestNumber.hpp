#include "tools.hpp"
class Solution
{
public:
    std::string largestNumber(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            return std::to_string(a) > std::to_string(b);
        });
        std::string rst;
        for (int a : nums)
        {
            rst += std::to_string(a);
        }
        return rst;
    }

    void test()
    {
        std::cout << "test start" << std::endl;
        std::vector<int> vec;
        vec = tools::string2vectorInt("[10,2]");
        std::cout << largestNumber(vec) << std::endl;
    }
};