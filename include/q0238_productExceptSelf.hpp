//
// Created by ming on 2020/6/4.
//

#ifndef CMAKETEST_Q0238_PRODUCTEXCEPTSELF_HPP
#define CMAKETEST_Q0238_PRODUCTEXCEPTSELF_HPP

#endif //CMAKETEST_Q0238_PRODUCTEXCEPTSELF_HPP
#include"tools.hpp"
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        //建立前缀积数组和后缀积数组
//        {
//            std::vector<int> front, back, rst;
//            int f = 1, b = 1, len = nums.size();
//            for (int i = 0; i < len; ++i) {
//                front.push_back(f);
//                back.push_back(b);
//                f *= nums[i];
//                b *= nums[len - 1 - i];
//            }
//            for (int j = 0; j < len; ++j) {
//                rst.push_back(front[j] * back[len - 1 - j]);
//            }
//            return rst;
//        }
        //常数空间复杂度
        std::vector<int> rst;
        int tmp = 1,len = nums.size();
        for (int i = 0; i < len; ++i) {
            rst.push_back(tmp);
            tmp*=nums[i];
        }
        tmp=1;
        for (int j = 0; j < len; ++j) {
            rst[len-1-j]*=tmp;
            tmp*=nums[len-1-j];
        }
        return rst;


    }
    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int> nums;
        nums = {1,2,3,4};
        tools::printVectorInt(productExceptSelf(nums));


    }
};