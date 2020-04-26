//
// Created by ming on 2020/4/24.
//

#ifndef CMAKETEST_M5100_REVERSEPAIRS_HPP
#define CMAKETEST_M5100_REVERSEPAIRS_HPP

#endif //CMAKETEST_M5100_REVERSEPAIRS_HPP

#include "tools.hpp"

class Solution {
private:
    int rst = 0;
public:

    int reversePairs_1(std::vector<int>& nums) {
        //相邻对换到不能调换时的调换数即为逆序数
        ////证明： 相邻对换只改变对换者的逆序数，不改变此对前后的逆序数
        int len = nums.size();
        int rst = 0;
        bool ordered = false;
        while (!ordered){
            ordered = true;
            for(int i =0;i<len-1;i++){
                if(nums[i]>nums[i+1]){
                    int temp = nums[i];
                    nums[i]=nums[i+1];
                    nums[i+1]=temp;
                    rst++;
                    ordered = false;
                }
            }
        }
        return rst;
    }//超时了
    int reversePairs(std::vector<int>& nums) {
        int len = nums.size();
        int rst = 0;
        for(int i =0;i<len-1;i++){
            if(nums[i]>nums[i+1]){
                int j = i;
                while (nums[j]>nums[j+1]&&j<len-1){
                    int temp = nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                    j++;
                    rst++;
                }
                i--;
            }
        }
        return rst;
    }

    void test(){
        std::cout<<"test start"<<std::endl;
        std::vector<int> arr;

        arr = {7,5,6,4};
        std::cout<<reversePairs(arr)<<std::endl;

        arr = {7};
        std::cout<<reversePairs(arr)<<std::endl;


    }
};