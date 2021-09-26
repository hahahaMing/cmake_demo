//
// Created by ming on 2021/3/6.
//

#ifndef CMAKETEST_Q0503_NEXTGREATERELEMENTS_HPP
#define CMAKETEST_Q0503_NEXTGREATERELEMENTS_HPP

#endif //CMAKETEST_Q0503_NEXTGREATERELEMENTS_HPP
#include"tools.hpp"
/*
 * ctrl+r replace
 * std::
 */
class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        if(nums.empty())return {};
        //有一个栈记录递减区间
        std::stack<int> decrease;
        int n = nums.size();
        if(n==1)return {-1};
        std::vector<int> rst(n,-1);
        decrease.push(0);
        int slow = 0,fast = 1;
        while(fast!=decrease.top()){
            if(nums[fast]<=nums[decrease.top()]){
                if (fast==slow)break;
                decrease.push(fast);
                fast++;
            }else{
                rst[decrease.top()] = nums[fast];
                decrease.pop();
                if(decrease.empty()){
                    slow = fast;
                    fast++;
                    decrease.push(slow);
                }
            }
            if (fast>=n)fast = 0;
        }
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int> nums;
        nums = {1,1,1,1,1,1};
        tools::printVectorInt(nextGreaterElements(nums));

        nums = {2,1,1,1,1,1};
        tools::printVectorInt(nextGreaterElements(nums));

        nums = {5,4,3,2,1};
        tools::printVectorInt(nextGreaterElements(nums));
        nums = {1,2,1};
        tools::printVectorInt(nextGreaterElements(nums));

    }
};