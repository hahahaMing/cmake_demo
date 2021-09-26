//
// Created by ming on 2021/2/21.
//

#ifndef CMAKETEST_Q1438_LONGESTSUBARRAY_HPP
#define CMAKETEST_Q1438_LONGESTSUBARRAY_HPP

#endif //CMAKETEST_Q1438_LONGESTSUBARRAY_HPP
#include"tools.hpp"
/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        //滑动窗口，最开始长度是1，然后长度变长向前走，直到达到limit
        //用顶堆记录一个排序后的窗口内数组
        //每次超出limit就更新顶堆
        //更新方法：
        //新值太小，则删除堆顶，


    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};