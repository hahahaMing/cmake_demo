//
// Created by ming on 2020/10/3.
//

#ifndef CMAKETEST_Q0001_TWOSUM_HPP
#define CMAKETEST_Q0001_TWOSUM_HPP

#endif //CMAKETEST_Q0001_TWOSUM_HPP
#include"tools.hpp"
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int,int> hash;
        for(int i =0;i<nums.size();i++){
            if(hash.find(nums[i])!=hash.end())return{hash[nums[i]],i};
            hash[target-nums[i]]=i;
        }
        return {};
    }
    void test(){
        std::cout<<"test start"<<std::endl;

    }
};