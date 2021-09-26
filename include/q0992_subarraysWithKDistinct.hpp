//
// Created by ming on 2021/2/9.
//

#ifndef CMAKETEST_Q0992_SUBARRAYSWITHKDISTINCT_HPP
#define CMAKETEST_Q0992_SUBARRAYSWITHKDISTINCT_HPP

#endif //CMAKETEST_Q0992_SUBARRAYSWITHKDISTINCT_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
    void debug(std::vector<int> &A, int l, int r) {
        std::cout << '[';
        for (int i = l; i < r; ++i) {
            std::cout << A[i] << ',';
        }
        std::cout << A[r] << "],";
    }

    int at_most_K_distinct(std::vector<int> &A,int K){
        int n = A.size();
        std::vector<int> rcd(n + 1, 0);
        int diff = 0, rst = 0;
        int l = 0,r = 0;//[l,r)
        while (r<n){
            if (rcd[A[r]]==0)diff++;
            rcd[A[r]]++;
            r++;
            while (diff>K){
                rcd[A[l]]--;
                if (rcd[A[l]]==0)diff--;
                l++;
            }
            rst+=r-l;//以r结尾的开区间不同数小于等于K的区间个数。
        }
        return rst;
    }


public:
    int subarraysWithKDistinct(std::vector<int> &A, int K) {
        return at_most_K_distinct(A,K)-at_most_K_distinct(A,K-1);


        //滑动窗口从K开始
        int n = A.size();
        std::vector<int> rcd(n + 1, 0);
        int diff = 0, rst = 0;
        for (int i = 0; i < K - 1; ++i) {
            if (rcd[A[i]] == 0)diff++;
            rcd[A[i]]++;
        }
        int l = 0, r = K - 2;
        if (K == 1) {
            rst += n;
            r = 0;
            rcd[A[0]]++;
            diff++;
        }
        bool forward = false, turn = true;//开头时反向改为正向
        //每次l,r改变完成立即判断rst是否增加，所以出口为转向时
        while (r - l + 1 <= n) {
            if (turn) {
                if (forward) {//正向改为反向
                    forward = false;
                    l--;
                    if (rcd[A[l]] == 0)diff++;
                    if (diff == K) {
                        debug(A, l, r);
                        rst++;
                    }
                    if (l == 0)break;
                    rcd[A[l]]++;
                    turn = false;
                } else {
                    forward = true;
                    r++;
                    if (rcd[A[r]] == 0)diff++;
                    if (diff == K) {
                        debug(A, l, r);
                        rst++;
                    }
                    if (r == n - 1)break;
                    rcd[A[r]]++;
                    if (r != n - 1)turn = false;
                }
            } else {
                if (forward) {
                    rcd[A[l]]--;
                    if (rcd[A[l]] == 0)diff--;
                    l++;
                    r++;
                    if (rcd[A[r]] == 0)diff++;
                    rcd[A[r]]++;
                    if (r == n - 1)turn = true;
                } else {
                    rcd[A[r]]--;
                    if (rcd[A[r]] == 0)diff--;
                    r--;
                    l--;
                    if (rcd[A[l]] == 0)diff++;
                    rcd[A[l]]++;
                    if (l == 0)turn = true;
                }
                if (diff == K) {
                    debug(A, l, r);
                    rst++;
                }
            }

        }
        std::cout << std::endl;
        return rst;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> A;
        A = {1, 2};
        std::cout << subarraysWithKDistinct(A, 1) << std::endl;
        A = {1, 2, 1, 2, 3};
        std::cout << subarraysWithKDistinct(A, 2) << std::endl;
        A = {1, 2, 1, 3, 4};
        std::cout << subarraysWithKDistinct(A, 3) << std::endl;
    }
};