//
// Created by ming on 2021/2/13.
//

#ifndef CMAKETEST_Q0448_FINDDISAPPEAREDNUMBERS_HPP
#define CMAKETEST_Q0448_FINDDISAPPEAREDNUMBERS_HPP

#endif //CMAKETEST_Q0448_FINDDISAPPEAREDNUMBERS_HPP

#include"tools.hpp"
/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        while (i<=n){
            int id = nums[i-1];
            if (id==i||nums[id-1]==id)i++;
            else{
                std::swap(nums[i-1],nums[id-1]);
            }
        }
        std::vector<int> rst;
        for (int j = 0; j < n; ++j) {
            if (nums[j]!=j+1)rst.push_back(j+1);
        }
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int> nums;
        nums = {4,3,2,7,8,2,3,1};
        tools::printVectorInt(findDisappearedNumbers(nums));
        tools::printVectorInt(nums);

    }
};
