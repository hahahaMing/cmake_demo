//
// Created by ming on 2020/5/24.
//

#ifndef CMAKETEST_Q0004_FINDMEDIANSORTEDARRAYS_HPP
#define CMAKETEST_Q0004_FINDMEDIANSORTEDARRAYS_HPP

#endif //CMAKETEST_Q0004_FINDMEDIANSORTEDARRAYS_HPP

#include"tools.hpp"

class Solution {
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
        //在两个数组中，各找一个数，使其将两个数组分割为等大的两半。
        //二分法
        int len1 = nums1.size(), len2 = nums2.size(), len = len1 + len2;
        int l = 0, r = len1, x1 = len1 / 2, x2 = len / 2 - x1 - 1;
        //在前一半中
        while (true) {
            if (nums1[x1] < nums2[x2]) {
                if (l==x1)x1=r;
                else{
                    l = x1;
                    x1 = (r + x1) / 2;
                }
                x2 = len / 2 - x1 - 1;
                if (x2<0){
                    x2=0;x1=len / 2  - 1;
                }

            } else if (x2 <= 0) {
                x2=0;

            } else if (nums1[x1] > nums2[x2 - 1]) {

            }

            if (x2 == 0 || x1 == 0 || x2 == len2 - 1 || x1 == len1 - 1)break;

        }


    }

    void test() {
        std::cout << "test start" << std::endl;

    }
};