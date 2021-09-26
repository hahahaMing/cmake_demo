//
// Created by ming on 2021/3/24.
//

#ifndef CMAKETEST_Q0456_FIND132PATTERN_HPP
#define CMAKETEST_Q0456_FIND132PATTERN_HPP

#endif //CMAKETEST_Q0456_FIND132PATTERN_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    bool find132pattern(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> farthest_less(n, -1), nearest_more(n, -1);
        for (int i = 0; i < n; ++i) {
            int j = i - 1;
            //找最远的小于
            while (j >= 0) {
                if (nums[j] < nums[i] && farthest_less[j] == -1) {
                    farthest_less[i] = j;
                }
                if (farthest_less[j] != -1 && nums[farthest_less[j]] < nums[i])j = farthest_less[j];
                else j--;
            }
            //找最近的大于
            j = i - 1;
            while (j >= 0) {
                if (nums[j] > nums[i]) {
                    nearest_more[i] = j;
                    break;
                }
                //小于的情况
                if (nearest_more[j] == -1) {
                    nearest_more[i] = -1;
                    break;
                }
                j = nearest_more[j];
            }
            //找到了就停
            tools::printVectorInt(farthest_less);
            tools::printVectorInt(nearest_more);
            if (farthest_less[i] != -1 && farthest_less[i] < nearest_more[i])return true;
        }
        return false;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> v;
        v = {3,5,0,3,4};
        std::cout << find132pattern(v) << std::endl;

    }
};