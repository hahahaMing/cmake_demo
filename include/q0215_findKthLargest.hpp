//
// Created by ming on 2020/6/29.
//

#ifndef CMAKETEST_Q0215_FINDKTHLARGEST_HPP
#define CMAKETEST_Q0215_FINDKTHLARGEST_HPP

#endif //CMAKETEST_Q0215_FINDKTHLARGEST_HPP
#include"tools.hpp"
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
        int rst,i = nums.size()-1;
        while (k>0){
            rst = nums[i];
            while (nums[i]==rst)i--;
            k--;
        }
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int> nums;
        int k;

        nums = {3,2,1,5,6,4};
        k = 2;
        std::cout<<findKthLargest(nums,k)<<std::endl;

        nums = {3,2,3,1,2,4,5,5,6};
        k = 4;
        std::cout<<findKthLargest(nums,k)<<std::endl;


    }
};