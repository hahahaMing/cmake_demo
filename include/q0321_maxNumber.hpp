//
// Created by ming on 2020/12/2.
//

#ifndef CMAKETEST_Q0321_MAXNUMBER_HPP
#define CMAKETEST_Q0321_MAXNUMBER_HPP

#endif //CMAKETEST_Q0321_MAXNUMBER_HPP

#include"tools.hpp"

class Solution {
    std::vector<int> final_rst;

    std::vector<int> delete_order(std::vector<int> &nums1) {
        int m = nums1.size();
        std::vector<int> rcd1(m, -1);
        for (int i = 0; i < m; ++i) {
            int last_index = -1;
            bool done = false;
            for (int j = 0; j < m; ++j) {
                if (rcd1[j] == -1) {
                    if (last_index == -1)last_index = j;
                    if (nums1[j] > nums1[last_index]) {
                        rcd1[last_index] = i;
                        done = true;
                        break;
                    } else {
                        last_index = j;
                    }
                }
            }
            if (!done)rcd1[last_index] = i;
        }
        return rcd1;
    }

    std::vector<int> extract_nums(std::vector<int> &nums, std::vector<int> &dnums, int m) {
        //从nums中提取最大的m位数，相对顺序不变
        std::vector<int> rst;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (dnums[i] >= n - m)rst.push_back(nums[i]);
        }
        return rst;
    }

    void combine_vecs(std::vector<int> &vec1, std::vector<int> &vec2) {
        int m = vec1.size(), n = vec2.size();
        int p1 = 0, p2 = 0;
        int wt;//等待被压入数字
        int count = 0;
        bool fresh = false;
        while (count < m + n) {
            int t1 = p1 < m ? vec1[p1] : -1;
            int t2 = p2 < n ? vec2[p2] : -1;
            if (t1 > t2) {
                wt = t1;
                p1++;
            } else if (t1 == t2) {
                wt = t1;
                //先用第一个多的，长的
                int tp1 = p1, tp2 = p2;
                while (++tp1 < m && ++tp2 < n && vec1[tp1] == vec2[tp2]);
//                while (tp1 < m && vec1[++tp1] == vec1[p1] && tp2 < n && vec2[++tp2] == vec2[p2]);

                if (tp1 < m && tp2 < n) {
                    if (vec1[tp1] > vec2[tp2])p1++;
                    else p2++;
                } else {
                    if (tp1 == m)p2++;
                    else p1++;
                }
            } else {
                wt = t2;
                p2++;
            }
            //放入wt
            if (fresh) {
                final_rst[count++] = wt;
            } else {
                if (wt > final_rst[count]) {
                    final_rst[count++] = wt;
                    fresh = true;
                } else if (wt < final_rst[count]) {
                    return;
                } else {
                    count++;
                }
            }

        }


    }

public:
    std::vector<int> maxNumber(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        final_rst = std::vector<int>(k, -1);
        std::vector<int> rcd1 = delete_order(nums1), rcd2 = delete_order(nums2);
        //nums1里出i个，nums2里出k-i个
        for (int i = 0; i <= m; ++i) {
            if (k - i > n || k - i < 0)continue;
            std::vector<int> vec1 = extract_nums(nums1, rcd1, i),
                    vec2 = extract_nums(nums2, rcd2, k - i);
            combine_vecs(vec1, vec2);
        }
        return final_rst;
    }


    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> nums1, nums2;
//        nums1 = {3, 4, 6, 5};
//        nums2 = {9, 1, 2, 5, 8, 3};
//        tools::printVectorInt(maxNumber(nums1, nums2, 5));
//        nums1 = {6, 7};
//        nums2 = {6, 0, 4};
//        tools::printVectorInt(maxNumber(nums1, nums2, 5));
//        nums1 = {3, 9};
//        nums2 = {8, 9};
//        tools::printVectorInt(maxNumber(nums1, nums2, 3));
//
        nums1 = {5, 1, 0};
        nums2 = {5, 2, 1};
        tools::printVectorInt(maxNumber(nums1, nums2, 3));
        nums1 = {2, 5, 6, 4, 4, 0};
        nums2 = {7, 3, 8, 0, 6, 5, 7, 6, 2};
        tools::printVectorInt(maxNumber(nums1, nums2, 15));
        nums1 = {1, 6, 5, 4, 7, 3, 9, 5, 3, 7, 8, 4, 1, 1, 4};
        nums2 = {4, 3, 1, 3, 5, 9};
        tools::printVectorInt(maxNumber(nums1, nums2, 21));
//        tools::printVectorInt({4, 3, 1, 6, 5, 4, 7, 3, 9, 5, 3, 7, 8, 4, 1, 3, 5, 9, 1, 1, 4});


    }
};