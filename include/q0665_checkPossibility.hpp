//
// Created by ming on 2021/2/7.
//

#ifndef CMAKETEST_Q0665_CHECKPOSSIBILITY_HPP
#define CMAKETEST_Q0665_CHECKPOSSIBILITY_HPP

#endif //CMAKETEST_Q0665_CHECKPOSSIBILITY_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int rcd = 0, change = -1;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                rcd++;
                change = i;
            }
            if (rcd > 2)return false;
        }
        if (change == -1)return true;
        int a = change > 1 ? nums[change - 2] : -100000, b = nums[change - 1], c = nums[change], d =
                change < n - 1 ? nums[change + 1] : 100000;
        return (a <= c && c <= d) || (a <= b && b <= d);
    }

    void test() {
        std::cout << "test start" << std::endl;



//        std::mt19937 rng(std::random_device{}());
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            tools::printVectorInt(vec);
//        }
    }
};