//
// Created by ming on 2020/5/4.
//

#ifndef CMAKETEST_Q0045_JUMP_HPP
#define CMAKETEST_Q0045_JUMP_HPP

#endif //CMAKETEST_Q0045_JUMP_HPP
#include "tools.hpp"

class Solution {
public:
    int jump(std::vector<int>& nums) {
        //更新，i步能够到达的区间，比如1步能到[1,nums[0]],2步能到[nums[0]+1,?]...
        //当区间尾部超过数组边界，返回这个步数
//        if (nums.empty())return 0;
        int step = 0,end = 0,head = 0,temp = end,l = nums.size()-1;
        while (end<l){
            for (int i = head; i <=end ; ++i) {
                temp = std::max(temp,i+nums[i]);
            }
            step++;
            head = end+1;
            end = temp;
        }
        return step;
    }

    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int> nums;

//        nums = {2,3,1,1,4};
//        std::cout<<jump(nums)<<std::endl;
//
//        nums = {0};
//        std::cout<<jump(nums)<<std::endl;
//
//        nums = {1,2,3};
//        std::cout<<jump(nums)<<std::endl;

        nums = {1,2,1,1,1};
        std::cout<<jump(nums)<<std::endl;



    }
};