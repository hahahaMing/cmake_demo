#include"tools.hpp"

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
        std::vector<std::vector<int>> rst = {{}};
        std::vector<int> rcd(21, 0);
        for (int x:nums)rcd[x + 10]++;
        for (int i = 0; i < 21; ++i) {
            int m = rcd[i];
            int len = rst.size();
            for (int j = 0; j < len; ++j) {
                std::vector<int> tmp = rst[j];
                for (int k = 0; k < m; ++k) {
                    tmp.push_back(i - 10);
                    rst.push_back(tmp);
                }
            }
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums;
        nums = {1, 2, 2, 1, 2};
        tools::print2DVector(subsetsWithDup(nums));
//        nums = {1,2,2,1,2,1};
//        tools::print2DVector(subsetsWithDup(nums));
    }
};