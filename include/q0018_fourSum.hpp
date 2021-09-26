//
// Created by ming on 2020/10/5.
//

#ifndef CMAKETEST_Q0018_FOURSUM_HPP
#define CMAKETEST_Q0018_FOURSUM_HPP

#endif //CMAKETEST_Q0018_FOURSUM_HPP
#include"tools.hpp"
class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        /*
         * 排序
         * 存和为target-x的数组
         */
        std::sort(nums.begin(),nums.end());
        std::map<int,std::vector<std::vector<int>>> one,two,three;
        std::vector<std::vector<int>> rst;
        int count = 0,times = 1,last ;
        while (count<nums.size()){
            last = nums[count];
            //去重
            while (count<nums.size()&&nums[count]==last){
                times++;count++;
            }
            //单个
            if (one[target-last].empty())one[target-last]={{last}};
            else one[target-last].push_back({last});
            //两个
            if (!one.empty()){
                for(auto item=one.begin();item!=one.end();item++){
                    for (int i = 0; i < ; ++i) {
                        
                    }
                }
            }

            //三个


            //四个






            count++;
        }
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int> nums;
        int target;
        nums = {1, 0, -1, 0, -2, 2};
        target = 10;
        tools::print2DVector(fourSum(nums,target));

    }
};