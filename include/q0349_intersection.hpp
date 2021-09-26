//
// Created by ming on 2020/11/2.
//

#ifndef CMAKETEST_Q0349_INTERSECTION_HPP
#define CMAKETEST_Q0349_INTERSECTION_HPP

#endif //CMAKETEST_Q0349_INTERSECTION_HPP

#include"tools.hpp"

class Solution {
public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
//        std::vector<int> sn, ln;
//        if (l1 < l2) {
//            sn = nums1;
//            ln = nums2;
//        } else {
//            sn = nums2;
//            ln = nums1;
//            std::swap(l1, l2);
//        }
        if (l1 > l2) {
            std::swap(nums1, nums2);
            std::swap(l1, l2);
        }


        std::vector<int> rst;
        std::unordered_set<int> rcd;
        for (int i = 0; i < l1; ++i) {
            if (rcd.find(nums1[i]) == rcd.end())rcd.emplace(nums1[i]);
        }
        for (int i = 0; i < l2; ++i) {
            if (rcd.find(nums2[i]) != rcd.end()){
                rst.push_back(nums2[i]);
                rcd.erase(rcd.find(nums2[i]));
            }
            if (rst.size() == rcd.size())break;
        }
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;

    }
};