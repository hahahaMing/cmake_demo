//
// Created by ming on 2021/2/18.
//

#ifndef CMAKETEST_Q0995_MINKBITFLIPS_HPP
#define CMAKETEST_Q0995_MINKBITFLIPS_HPP

#endif //CMAKETEST_Q0995_MINKBITFLIPS_HPP

#include"tools.hpp"

/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int minKBitFlips(std::vector<int> &A, int K) {
        //窗口向后滑，看到0开头就翻转，直到翻转不了
        int l = 0, n = A.size();
        int rst = 0;
        std::queue<int> que;
        bool change = false;
        int tmp = 0;//记录当前状态已经进行了多少步，
        while (l < n) {
            if (change) {//改变状态
                if (A[l] == 1) {//看到1变为0
                    rst++;
                    change = false;//更改状态为不变状态
                    que.push(tmp);
                    tmp = 0;
                } else {
                    A[l] = 1;
                }
            } else {//不变状态
                if (A[l] == 0) {//看到0
                    rst++;
                    change = true;
                    A[l] = 1;
                    if (que.empty())que.push(K);//初始化que
                    else {//更新que
                        que.push(tmp);
                        tmp = 0;
                    }
                }
            }
            //走了一步
            if (!que.empty()) {
                que.front()--;
                tmp++;
                if (tmp == K)tmp = 0;
            }
            l++;
            //当前状态结束，改变状态
            if (!que.empty() && que.front() == 0) {
                que.pop();
                change = !change;
            }
        }
        if (que.empty()) return rst;
        return -1;
    }

    void test() {
        std::cout << "test start" << std::endl;
        std::vector<int> A;
        int K;
        A = {0, 1, 0};
        K = 1;
        std::cout << minKBitFlips(A, K) << std::endl;
        A = {1, 1, 0};
        K = 2;
        std::cout << minKBitFlips(A, K) << std::endl;
        A = {0, 0, 0, 1, 0, 1, 1, 0};
        K = 3;
        std::cout << minKBitFlips(A, K) << std::endl;

    }
};