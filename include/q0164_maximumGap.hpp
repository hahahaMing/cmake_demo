//
// Created by ming on 2020/11/26.
//

#ifndef CMAKETEST_Q0164_MAXIMUMGAP_HPP
#define CMAKETEST_Q0164_MAXIMUMGAP_HPP

#endif //CMAKETEST_Q0164_MAXIMUMGAP_HPP

#include"tools.hpp"

class Solution {
public:
    int maximumGap(std::vector<int> &nums) {
        int rst = 0;
        std::sort(nums.begin(),nums.end());
        int n =nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i]-nums[i-1]>rst)
                rst = nums[i]-nums[i-1];
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;

        std::mt19937 rng(std::random_device{}());
        std::vector<int> vec;
        for (int i = 0; i < 10; ++i) {
            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
            std::cout << maximumGap(vec) << std::endl;
            std::sort(vec.begin(),vec.end());
            tools::printVectorInt(vec);
        }
        // single test
        std::vector<int> nums;
        nums = tools::string2vectorInt("[3,6,9,1]");
        std::cout << maximumGap(nums) << std::endl;
        nums = tools::string2vectorInt("[3]");
        std::cout << maximumGap(nums) << std::endl;
        nums = tools::string2vectorInt("[]");
        std::cout << maximumGap(nums) << std::endl;




    }
};