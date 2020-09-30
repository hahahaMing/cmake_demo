//
// Created by ming on 2020/6/12.
//

#ifndef CMAKETEST_Q0015_THREESUM_HPP
#define CMAKETEST_Q0015_THREESUM_HPP

#endif //CMAKETEST_Q0015_THREESUM_HPP
#include"tools.hpp"
class Solution {
    std::vector<std::vector<int>> twoSum(std::vector<int>& nums,int target) {
        std::unordered_set<int> rcd;
        std::vector<std::vector<int>> rst;
        for(int i:nums){
            if(rcd.find(i)!=rcd.end())rst.push_back({target-i,i,-target});
            rcd.insert(target-i);
        }
        return rst;
    }
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int len = nums.size();
        std::vector<std::vector<int>> rst;
        if (len<3)return {};
        sort(nums.begin(),nums.end());
        for (int i = 0; i < len; ++i) {
            if (nums[i]>0)return rst;
            if (i>0&&nums[i]==nums[i-1])continue;
            int L = i+1,R = len-1;
            while (L<R){
                int tmp = nums[i] + nums[L] + nums[R];
                if (tmp== 0){
                    rst.push_back({nums[i], nums[L], nums[R]});
                    while (L<R&&nums[L]==nums[L+1])L++;
                    while (L<R&&nums[R]==nums[R-1])R--;
                    L++;R--;
                }else if(tmp>0){
                    R--;
                }else{
                    L++;
                }
            }
        }
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int> nums;
        nums = {-1, 0, 1, 2, -1, -4};
        tools::print2DVector(threeSum(nums));


    }
};