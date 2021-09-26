//
// Created by ming on 2020/12/4.
//

#ifndef CMAKETEST_Q0659_ISPOSSIBLE_HPP
#define CMAKETEST_Q0659_ISPOSSIBLE_HPP

#endif //CMAKETEST_Q0659_ISPOSSIBLE_HPP

#include"tools.hpp"

class Solution {
public:
    bool isPossible(std::vector<int> &nums) {
        int n = nums.size();
        if (n < 3)return false;
        std::vector<int> rcd = {};
        int last = nums[0];
        int count = 0;
        while (count < n) {
            while (count < n && nums[count] == last) {
                rcd.emplace_back(1);
                count++;
            }
            int len = rcd.size();
            for (int i = len - 1; i >= 0; i--) {
                if (rcd[i] != -1 && nums[count] == last + 1) {
                    count++;
                    rcd[i]++;
                } else {
                    if (rcd[i] < 3 && rcd[i] != -1)return false;
                    rcd[i] = -1;
                }
            }
            if (rcd.back() == -1)last = nums[count];
            else last = nums[count - 1];
        }
        return rcd.back() >= 3 || rcd.back() == -1;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> vec;
        vec = {1, 2, 3, 3, 4, 5};
        std::cout << isPossible(vec) << std::endl;
        vec = {1, 2, 3, 3, 4, 4, 5, 5};
        std::cout << isPossible(vec) << std::endl;
        vec = {1, 2, 3, 4, 4, 5};
        std::cout << isPossible(vec) << std::endl;

    }
};