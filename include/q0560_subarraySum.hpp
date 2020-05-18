//
// Created by ming on 2020/5/15.
//

#ifndef CMAKETEST_Q0560_SUBARRAYSUM_HPP
#define CMAKETEST_Q0560_SUBARRAYSUM_HPP

#endif //CMAKETEST_Q0560_SUBARRAYSUM_HPP
#include "tools.hpp"
class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        //动态规划
        // 记录每次的和 如果等于k，rst++
        std::queue<int> rec;//存以当前位为末尾的连续子数组和
        int len;
        int rst=0;
        int temp;
        for (int i = 0; i <nums.size() ; ++i) {
            rec.push(nums[i]);
            if (nums[i]==k)rst++;
            for (int j = 0; j <i; ++j) {
                temp=rec.front()+nums[i];
                rec.push(temp);
                if (temp==k)rst++;
                rec.pop();
            }
        }
        return rst;
    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int> a;
        int k;

//        a = {1,1,-1,0,2,5};
//        k=2;
//        std::cout<<subarraySum(a,k)<<std::endl;
//
//        a = {};
//        k=2;
//        std::cout<<subarraySum(a,k)<<std::endl;

        a = {1,1,1};
        k=2;
        std::cout<<subarraySum(a,k)<<std::endl;


    }
};