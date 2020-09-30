//
// Created by ming on 2020/7/15.
//

#ifndef CMAKETEST_Q0096_NUMTREES_HPP
#define CMAKETEST_Q0096_NUMTREES_HPP

#endif //CMAKETEST_Q0096_NUMTREES_HPP
#include"tools.hpp"
class Solution {
public:
    int numTrees(int n) {
        /*
         * 递归：时间爆炸
         * 原因：重复很多简单操作
         * 更改：以空间换时间
         */
//        if (n==0||n==1)return 1;
//        int rst = 0;
//        for (int i = 0; i < n; ++i) {
//            rst+=numTrees(i)*numTrees(n-1-i);
//        }
//        return rst;
        std::vector<int> rcd = {1,1};
        for (int i = 2; i <= n; ++i) {
            int rst = 0;
            for (int j = 0; j < i; ++j) {
                rst+=rcd[j]*rcd[i-1-j];
            }
            rcd.push_back(rst);
        }
        return rcd.back();
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::cout<<numTrees(4)<<std::endl;
        std::cout<<numTrees(5)<<std::endl;
        std::cout<<numTrees(6)<<std::endl;
        std::cout<<numTrees(7)<<std::endl;
        std::cout<<numTrees(40)<<std::endl;
    }
};