//
// Created by ming on 2020/12/1.
//

#ifndef CMAKETEST_Q0034_SEARCHRANGE_HPP
#define CMAKETEST_Q0034_SEARCHRANGE_HPP

#endif //CMAKETEST_Q0034_SEARCHRANGE_HPP

#include"tools.hpp"

class Solution {
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target) {
        if (nums.empty())return {-1, -1};
        int b = -1, e = -1;
        int l = 0, r = nums.size() - 1, m = (l + r) / 2;
        if (nums[l] > target || nums[r] < target)return {-1, -1};
        while (l <= r) {
            m = (l + r) / 2;
            if (nums[m] > target) {
                r = m - 1;
            } else if (nums[m] == target) {
                int t = m,tmp;
                while (l <= m) {
                    tmp = (l + m) / 2;
                    if (nums[tmp] >= target){
                        m = tmp - 1;
                        b = tmp;
                    }
                    else l = tmp + 1;
                }
                while (t <= r) {
                    tmp = (t + r) / 2;
                    if (nums[tmp] <= target){
                        t = tmp + 1;
                        e = tmp;
                    }
                    else{
                        r = tmp - 1;
                    }
                }
                return {b, e};
            } else {
                l = m + 1;
            }
        }
        return {-1, -1};
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> v;
        v = {5, 7, 7, 8, 8, 10};
        for (int i :v) {
            tools::printVectorInt(searchRange(v, i));
        }
        v = {2, 2};
        for (int i :v) {
            tools::printVectorInt(searchRange(v, i));
        }

//        std::mt19937 rng(std::random_device{}());
//        rng.seed(1);
//        std::vector<int> vec;
//        for (int i = 0; i < 10; ++i) {
//            vec = tools::random_vector(rng, 0, 9, -99, 99);
//            std::sort(vec.begin(),vec.end());
//            tools::printVectorInt(vec);
//            for (int i :vec) {
//                tools::printVectorInt(searchRange(vec,i));
//            }
//        }

    }

};